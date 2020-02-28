#ifndef _SHELL_HELPER_H
#define _SHELL_HELPER_H


#include <SHLOBJ.H>
#include "hrx_new.h"

static const int MENU_ID_SHORTCUT = 17;
static const int MENU_ID_DELETE = 18;
static const int MENU_ID_PROPERTIES = 20;
static const int MENU_ID_CUT = 25;
static const int MENU_ID_COPY = 26;
static const int MENU_ID_PASTE = 27;
static const int MENU_ID_SENDTO = 28;

inline static void FreePidl(LPCITEMIDLIST pItem)
{
	CComPtr<IMalloc> spMalloc;
	::SHGetMalloc(&spMalloc);
	spMalloc->Free(const_cast<LPITEMIDLIST>(pItem));
	pItem = NULL;
}

static HRESULT GetDeskTopFolder(IShellFolder **pFolder)
{
	if (pFolder == NULL)
		return E_POINTER;

	CComPtr<IShellFolder> spShellFolder;
	HRESULT hr = ::SHGetDesktopFolder(&spShellFolder);
	if(FAILED(hr))
		return hr;

	*pFolder = spShellFolder.Detach();

	return S_OK;
}

static LPITEMIDLIST GetNextItemID(LPCITEMIDLIST pidl)
{
	if(pidl == NULL)
		return NULL;

	int cb = pidl->mkid.cb;
	if (cb == 0)
		return NULL;

	pidl = (LPITEMIDLIST)(((LPBYTE)pidl) + cb);
	return (pidl->mkid.cb == 0) ? NULL : (LPITEMIDLIST)pidl;
}

static UINT GetSize(LPCITEMIDLIST pidl)
{
	UINT cbTotal = 0;
	if (pidl)
	{
		cbTotal += sizeof(pidl->mkid.cb);
		while(pidl)
		{
			cbTotal += pidl->mkid.cb;
			pidl = GetNextItemID(pidl);
		}
	}
	return cbTotal;
}

static LPITEMIDLIST Append(LPCITEMIDLIST pidlBase, LPCITEMIDLIST pidlAdd)
{
	if(pidlBase == NULL || pidlAdd == NULL)
		return NULL;

	LPITEMIDLIST pidlNew;
	UINT cb1 = GetSize(pidlBase) - sizeof(pidlBase->mkid.cb);
	UINT cb2 = GetSize(pidlAdd);

	CComPtr<IMalloc> spMalloc;
	::SHGetMalloc(&spMalloc);
	pidlNew = reinterpret_cast<LPITEMIDLIST>(spMalloc->Alloc(cb1 + cb2));
	if (pidlNew)
	{
		CopyMemory(pidlNew, pidlBase, cb1);
		CopyMemory(reinterpret_cast<LPSTR>(pidlNew) + cb1, pidlAdd, cb2);
	}
	return pidlNew;
}

//If ppidl is a fully qualified then user can leave pFolder as NULL otherwise use pFolder as 
//a pointer to parent shell folder and then pass ppidl as the relative item pidl.
static HRESULT ConvertPathToPidl(LPCTSTR szPath, LPITEMIDLIST* ppidl, LPSHELLFOLDER pFolder = NULL)
{
	_ASSERT(ppidl);
	CComPtr<IShellFolder> spShellFolder;
	if (pFolder == NULL)
		hrx hr = GetDeskTopFolder(&spShellFolder);
	else
		spShellFolder = pFolder;

	//This is necessary becuase ParseDisplayName needs WideChar
	OLECHAR wszPath[_MAX_PATH] = {0};
	::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szPath, -1, wszPath, _MAX_PATH);

	ULONG nCharsParsed = 0;
	return spShellFolder->ParseDisplayName(NULL, NULL, wszPath, &nCharsParsed, ppidl, NULL);
};

//pidl must be a fully qualified pidl.
static bool CovertPidlToPath(LPCITEMIDLIST pidl, LPSTR pszPath)
{
	int nRetVal = ::SHGetPathFromIDList(pidl, pszPath);
	return (nRetVal == 0) ? false : true;
}


static void StrSetToString(LPITEMIDLIST pidl, LPSTRRET pStr, LPTSTR lpszBuf)
{
	if(!pStr || !pidl)
		return;

	lstrcpy(lpszBuf, _T(""));
	switch(pStr->uType)
	{
	case STRRET_WSTR:
		WideCharToMultiByte(CP_ACP, 0, pStr->pOleStr, -1, lpszBuf, _MAX_PATH, NULL, NULL);
		break;
	case STRRET_OFFSET:
		lstrcpy(lpszBuf, reinterpret_cast<LPTSTR>(pidl) + pStr->uOffset);
		break;
	case STRRET_CSTR:
		lstrcpy(lpszBuf, pStr->cStr);
		break;
	}
}

//Id the pidl which is passed as first argument is fully qualified then pFolder can be NULL
//otherwise pass pFolder as Parent Shell Folder and then pItem can be relative Pidl.
static void GetDisplayName(LPCITEMIDLIST pItem, LPTSTR lpszBuf, LPSHELLFOLDER pFolder = NULL)
{
	CComPtr<IShellFolder> spShellFolder;
	if (pFolder == NULL)
		hrx hr = GetDeskTopFolder(&spShellFolder);
	else
		spShellFolder = pFolder;

	STRRET sName;
	spShellFolder->GetDisplayNameOf(pItem, SHGDN_NORMAL, &sName);
	StrSetToString(const_cast<LPITEMIDLIST>(pItem), &sName, lpszBuf);
}

static HICON GetIconHandle(LPSHELLFOLDER pFolder, LPCITEMIDLIST pItem)
{
	if(!pItem || !pFolder)
		return NULL;

	HICON hIcon = NULL;
	CComPtr<IExtractIcon> spExtractIcon;
	if (SUCCEEDED(pFolder->GetUIObjectOf(NULL, 1, &pItem, IID_IExtractIcon, NULL, reinterpret_cast<void**>(&spExtractIcon))))
	{
		UINT nVal = 0;
		int nIconIndex = 0;
		TCHAR szIconFile[_MAX_PATH] = {0};
		spExtractIcon->GetIconLocation(0, szIconFile, _MAX_PATH, &nIconIndex, &nVal);
		//Once Icon has been recieved , don't forget to call ::DeleteObject(hIcon)
		::ExtractIconEx(szIconFile, nIconIndex, &hIcon, NULL, 1);
	}
	return hIcon;
}

static DWORD GetFolderObjectAttributes(LPCITEMIDLIST pItem, LPSHELLFOLDER pFolder = NULL)
{
	if(pItem == NULL)
		return 0;

	CComPtr<IShellFolder> spShellFolder;
	if(pFolder == NULL)
		hrx hr = GetDeskTopFolder(&spShellFolder);
	else
		spShellFolder = pFolder;

	ULONG nAttr = SFGAO_HASSUBFOLDER | SFGAO_FOLDER | SFGAO_FILESYSTEM | SFGAO_FILESYSANCESTOR;
	spShellFolder->GetAttributesOf(1, &pItem, &nAttr);
	return nAttr;
}

static HIMAGELIST GetSystemImageList()
{
	LPITEMIDLIST lpi = NULL;
	HIMAGELIST hImageList = NULL;
	if (NOERROR == ::SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOP, &lpi))
	{
		SHFILEINFO sfi;
		hImageList = reinterpret_cast<HIMAGELIST>(::SHGetFileInfo((LPCSTR)lpi, 0, &sfi, sizeof(SHFILEINFO),
			SHGFI_SYSICONINDEX | SHGFI_SMALLICON | SHGFI_PIDL));
		FreePidl(lpi);
	}
	return hImageList;
}

//Generally pass the Complete PIDL value to get the Icon Information, Relative PIDL may not return correct information
static int GetItemIconPos(LPCITEMIDLIST pItem)
{
   SHFILEINFO    sfi;
   ::SHGetFileInfo((LPCSTR)pItem, 
                 0,
                 &sfi, 
                 sizeof(SHFILEINFO), 
                 SHGFI_PIDL | SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
   return sfi.iIcon;
}


//Generally pass the Complete PIDL value to get the Icon Information, Relative PIDL may not return correct information
static int GetItemSelectedIconPos(LPCITEMIDLIST pItem)
{
   SHFILEINFO    sfi;
   ::SHGetFileInfo((LPCSTR)pItem, 
                 0,
                 &sfi, 
                 sizeof(SHFILEINFO), 
                 SHGFI_PIDL | SHGFI_SYSICONINDEX | SHGFI_SMALLICON | SHGFI_OPENICON);
   return sfi.iIcon;
}

static void GetFileItemType(LPCITEMIDLIST pItem, LPTSTR lpszTypeName)
{
   SHFILEINFO    sfi;
   ::SHGetFileInfo((LPCSTR)pItem, 
                 0,
                 &sfi, 
                 sizeof(SHFILEINFO), 
                 SHGFI_PIDL | SHGFI_TYPENAME );
   _tcscpy(lpszTypeName, sfi.szTypeName);
}

static bool IsValidFileSystemFolder(LPCITEMIDLIST pItem, LPSHELLFOLDER pFolder = NULL)
{

	DWORD dwAttr = GetFolderObjectAttributes(pItem, pFolder);
	if (dwAttr & (SFGAO_HASSUBFOLDER | SFGAO_FOLDER | SFGAO_FILESYSTEM | SFGAO_FILESYSANCESTOR ))
	{
		if ((dwAttr & SFGAO_FOLDER) && ((dwAttr & SFGAO_FILESYSANCESTOR ) || (dwAttr & SFGAO_FILESYSTEM )))
			  return true;
	}
	return false;
}

static bool IsValidFileSystemFile(LPCITEMIDLIST pItem, LPSHELLFOLDER pFolder = NULL)
{
	DWORD dwAttr = GetFolderObjectAttributes(pItem, pFolder);
    if ((dwAttr & (SFGAO_HASSUBFOLDER | SFGAO_FOLDER | SFGAO_FILESYSTEM | SFGAO_FILESYSANCESTOR )) &&
       (((dwAttr & SFGAO_FOLDER) && (dwAttr & SFGAO_FILESYSANCESTOR )) || (dwAttr & SFGAO_FILESYSTEM)))
	{
		if(!(dwAttr & SFGAO_FOLDER))
			return true;
	}
	return false;
}

static bool IsFolderHasChildren(LPCITEMIDLIST pItem, LPSHELLFOLDER pFolder = NULL)
{
	DWORD dwAttr = GetFolderObjectAttributes(pItem, pFolder);
	if (dwAttr & (SFGAO_HASSUBFOLDER | SFGAO_FOLDER | SFGAO_FILESYSTEM | SFGAO_FILESYSANCESTOR ))
	{
		if ((dwAttr & SFGAO_FOLDER) && ((dwAttr & SFGAO_FILESYSANCESTOR ) || (dwAttr & SFGAO_FILESYSTEM )))
		{
			if (dwAttr & SFGAO_HASSUBFOLDER)
			  return true;
		}
	}
	return false;
}

static LPITEMIDLIST MakeCopy(LPCITEMIDLIST pidl)
{
	UINT cb = GetSize(pidl);

	CComPtr<IMalloc> spMalloc;
	::SHGetMalloc(&spMalloc);

	LPITEMIDLIST pidlRet = reinterpret_cast<LPITEMIDLIST>(spMalloc->Alloc(cb));
	if(pidlRet)
		CopyMemory(pidlRet, pidl, cb);

	return pidlRet;
}

static LPSHELLFOLDER GetSubShellFolder(LPSHELLFOLDER pParentShellFolder, LPITEMIDLIST pRelativePidl)
{
	LPSHELLFOLDER pShellSubFolder = NULL;
	pParentShellFolder->BindToObject(pRelativePidl, 0, IID_IShellFolder, reinterpret_cast<LPVOID*>(&pShellSubFolder));
	return pShellSubFolder;
}

static bool ShowContextMenu(HWND hwnd, int nObjectAttrCount, LPSHELLFOLDER lpParentFolder, LPITEMIDLIST *pItem, LPPOINT lpPoint)
{
	ASSERT(lpParentFolder && pItem && lpPoint);
	try
	{
		CComPtr<IContextMenu> spContextMenu;
		hrx hr = lpParentFolder->GetUIObjectOf(hwnd, nObjectAttrCount, (const struct _ITEMIDLIST **)pItem, IID_IContextMenu, 0, reinterpret_cast<void**>(&spContextMenu));
		HMENU hMenu = CreatePopupMenu();
		if (hMenu)
		{
			hr = spContextMenu->QueryContextMenu(hMenu, 0, 1, 0x7fff, CMF_EXPLORE);
			UINT nCmd = ::TrackPopupMenu(hMenu, TPM_LEFTALIGN | TPM_RETURNCMD | TPM_RIGHTBUTTON, 
											lpPoint->x, lpPoint->y, 0, hwnd, NULL);
			if (nCmd)
			{
				CMINVOKECOMMANDINFO cmIvokedInfo;
				cmIvokedInfo.cbSize = sizeof(CMINVOKECOMMANDINFO);
				cmIvokedInfo.fMask  = 0;
				cmIvokedInfo.hwnd   = hwnd;
				cmIvokedInfo.lpVerb = MAKEINTRESOURCE(nCmd - 1);
				cmIvokedInfo.lpParameters = NULL;
				cmIvokedInfo.lpDirectory  = NULL;
				cmIvokedInfo.nShow        = SW_SHOWNORMAL;
				cmIvokedInfo.dwHotKey     = 0;
				cmIvokedInfo.hIcon        = NULL;

				hr = spContextMenu->InvokeCommand(&cmIvokedInfo);
				DestroyMenu(hMenu);
				return true;
			}
	    } 
	}
	catch(...)
	{
		return false;
	}
	return false;
}

static void RemoveDoubleLine(HMENU hMenu) 
{
	ASSERT(hMenu);

    CString strString1, strString2;
    long lSizeOfMenu = ::GetMenuItemCount(hMenu);

	TCHAR sMenuName[_MAX_PATH] = {0};

    for (long lCount = 1; lCount < lSizeOfMenu; lCount++)
    {
        ::GetMenuString( hMenu, lCount, sMenuName, MAX_PATH, MF_BYPOSITION);
        strString1 = sMenuName;

        ::GetMenuString( hMenu,(lCount-1), sMenuName,  MAX_PATH, MF_BYPOSITION);
        strString2 = sMenuName;

        if ((strString1.Compare(_T("")) == 0) && (strString2.Compare(_T("")) == 0)) 
        {
            ::RemoveMenu(hMenu, lCount, MF_BYPOSITION);
            return;
        }
    }
}

static void RemoveMenuItem(UINT iID, HMENU hMenu) 
{
	ASSERT(hMenu);

    ::RemoveMenu(hMenu, iID, MF_BYCOMMAND);
    RemoveDoubleLine(hMenu) ;
}

#endif //_SHELL_HELPER_H