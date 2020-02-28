#ifndef _IS_FOLDER_H_
#define _IS_FOLDER_H_

class CISFolder
{

public:
	CISFolder(){m_bShowNewUI=false;};           
	virtual ~CISFolder(){};

public:
	bool	m_bShowNewUI;//Shows the New UI dlg. (sets BIF_NEWDIALOGSTYLE)
public:
	//	----------------------------------------------------------------------------
	bool Browse(HWND hwndOwner, LPCTSTR lpszTitle, LPTSTR szReturnDir)
	{
		 LPMALLOC pMalloc;

		 if (SUCCEEDED(SHGetMalloc(&pMalloc))) 
		 {
			ZeroMemory(&m_bi,sizeof(m_bi));
			m_bi.hwndOwner = hwndOwner;
			m_bi.pszDisplayName = 0;
			m_bi.lpszTitle = lpszTitle; 
			m_bi.pidlRoot = 0;
			if(m_bShowNewUI)
				m_bi.ulFlags = 0x0040;// value for BIF_NEWDIALOGSTYLE
			else
				m_bi.ulFlags = NULL;
			m_bi.lpfn = BrowseCallbackProc;
			m_bi.lParam = reinterpret_cast<LPARAM>(szReturnDir);

			LPITEMIDLIST pidl = ::SHBrowseForFolder(&m_bi);

			if (pidl) 
			{
				::SHGetPathFromIDList(pidl,szReturnDir);

			   pMalloc->Free(pidl);
			   pMalloc->Release();

			   return true;
			}
		 }
		 return false;         
	}

private:
	static int CALLBACK BrowseCallbackProc(HWND hwnd,UINT uMsg,LPARAM lp, LPARAM pData) 
	{
		 switch(uMsg) 
		 {
			case BFFM_INITIALIZED: 
			{
				  // WParam is TRUE since you are passing a path.
				  // It would be FALSE if you were passing a pidl.
				if(pData)
					SendMessage(hwnd,BFFM_SETSELECTION,TRUE,pData);
			   break;
			}
			default:
			   break;
		 }
		 return 0;
	}

private:
	BROWSEINFO m_bi;
};

/////////////////////////////////////////////////////////////////////////////


#endif // _IS_FOLDER_H_
