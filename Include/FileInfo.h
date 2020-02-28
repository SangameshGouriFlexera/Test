// FileInfo.h: interface for the FileInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEINFO_H__7030270C_DF09_11D3_A8D5_00105A996B60__INCLUDED_)
#define AFX_FILEINFO_H__7030270C_DF09_11D3_A8D5_00105A996B60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma comment(lib, "version")

#include <vector>
#include <string.h>
#include "auto_handle.hxx"
#include "IconStruct.h"

// MakePtr is a macro that allows you to easily add to values (including
// pointers) together without dealing with C's pointer arithmetic.  It
// essentially treats the last two parameters as DWORDs.  The first
// parameter is used to typecast the result to the appropriate pointer type.
#define MakePtr( cast, ptr, addValue ) (cast)( (DWORD)(ptr) + (DWORD)(addValue))

/* PE Header information */
#define SIZE_OF_NT_SIGNATURE	sizeof (DWORD)
#define PEFHDROFFSET(a)			((LPVOID)((BYTE *)a +  \
								((PIMAGE_DOS_HEADER)a)->e_lfanew + SIZE_OF_NT_SIGNATURE))

#define ISSYS_NON_EXECUTABLE			-1
#define ISSYS_NT_EXECUTABLE				0
#define ISSYS_EXECUTABLE_LIB			1
#define ISSYS_DOS_EXECUTABLE			2
#define ISSYS_OS2_EXECUTABLE			3
#define ISSYS_VXD_EXECUTABLE			4
#define ISSYS_LX_EXECUTABLE				5

typedef is::auto_handle_t<LPVOID, int (__stdcall *)(const void*), &::UnmapViewOfFile>    auto_hMapFile;


typedef enum EnumFileType
{
	eftUnknown	= 0,
	eftEXE	= 1,
	eftDLL	= 2,
}EnumFileType;

class CFileInfo
{
public:
	CFileInfo::CFileInfo():m_pVersion(NULL),
				m_bInitSucceeded(false)
	{
	}

	CFileInfo::~CFileInfo()
	{
		Release();
	}

	bool GetFileVersion(LPTSTR lpVersion)
	{
		if (!GetVersionInfoBlock())
			return false;

		_ASSERT(lpVersion != NULL);

		VS_FIXEDFILEINFO *pVersionInfo = NULL;
		UINT nSize = 0;
		if (!VerQueryValue(m_pVersion, _T("\\"), reinterpret_cast<void**>(&pVersionInfo), &nSize))
			return false;

		//This can fail if the size of the buffer is smaller than needed.
		wsprintf(lpVersion, _T("%d.%d.%d.%d"),
				HIWORD(pVersionInfo->dwFileVersionMS), LOWORD(pVersionInfo->dwFileVersionMS),
				HIWORD(pVersionInfo->dwFileVersionLS), LOWORD(pVersionInfo->dwFileVersionLS));

		return true;
	}

	DWORD GetFileVersionBlock()
	{
		if (!m_pVersion)
			if (!GetVersionInfoBlock())
				return 0;

		_ASSERT(m_pVersion != NULL);

		VS_FIXEDFILEINFO *pVersionInfo = NULL;
		UINT nSize = 0;
		if (!VerQueryValue(m_pVersion, _T("\\"), reinterpret_cast<void**>(&pVersionInfo), &nSize))
			return 0;

		return pVersionInfo->dwFileVersionMS;
	}

	int GetMajorVersion()
	{
		return HIWORD(GetFileVersionBlock());
	}

	int GetMinorVersion()
	{
		return LOWORD(GetFileVersionBlock());
	}

	int GetBuildNumber()
	{
		return HIWORD(GetFileVersionBlock());
	}

	bool GetFileSize(DWORD *pdwSize)
	{
		if (!m_bInitSucceeded)
			return false;

		is::auto_hfile hFile(CreateFile(m_strFileName.c_str(), GENERIC_READ,
							   FILE_SHARE_READ,
							   NULL,
							   OPEN_EXISTING,
							   FILE_ATTRIBUTE_NORMAL,
							   NULL));
		
		DWORD dwSize = ::GetFileSize(hFile, NULL);
		if (dwSize <= 0)
			return false;

		*pdwSize = dwSize;
		return true;
	}

	bool GetFileDateTime(LPTSTR lpszCreationDateTime, LPTSTR lpszModifiedDateTime, LPTSTR lpszAccessDateTime)
	{
		if (!m_bInitSucceeded)
			return false;

		is::auto_hfile hFile(CreateFile(m_strFileName.c_str(), 0/*GENERIC_READ*/,
							   FILE_SHARE_READ,
							   NULL,
							   OPEN_EXISTING,
							   FILE_ATTRIBUTE_NORMAL,
							   NULL)); // 0 for dwDesiredAccess allows it to check files in use.

		FILETIME fCreationTime;
		FILETIME fAccessTime;
		FILETIME fModifiedTime;

		if (hFile != NULL && ::GetFileTime(hFile, &fCreationTime, &fAccessTime, &fModifiedTime ))
		{
	        FILETIME fLocalCreationTime;
			::FileTimeToLocalFileTime(&fCreationTime, &fLocalCreationTime);

			SYSTEMTIME SysCreationTime;
			::FileTimeToSystemTime(&fLocalCreationTime, &SysCreationTime);

			TCHAR szDate[1024] = {0};
			TCHAR szTime[1024] = {0};

			GetDateFormat(LOCALE_USER_DEFAULT, DATE_SHORTDATE, &SysCreationTime, NULL, szDate, 1024);
			GetTimeFormat(LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, &SysCreationTime, NULL, szTime, 1024);

			wsprintf(lpszCreationDateTime, _T("%s %s"), szDate, szTime);

	        FILETIME fLocalModifiedTime;
			::FileTimeToLocalFileTime(&fModifiedTime, &fLocalModifiedTime);

			SYSTEMTIME SysModifiedTime;
			::FileTimeToSystemTime(&fLocalModifiedTime, &SysModifiedTime);

			GetDateFormat(LOCALE_USER_DEFAULT, DATE_SHORTDATE, &SysModifiedTime, NULL, szDate, 1024);
			GetTimeFormat(LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, &SysModifiedTime, NULL, szTime, 1024);

			wsprintf(lpszModifiedDateTime, _T("%s %s"), szDate, szTime);
			
			FILETIME fLocalAccessTime;
			::FileTimeToLocalFileTime(&fAccessTime, &fLocalAccessTime);

			SYSTEMTIME SysAccessTime;
			::FileTimeToSystemTime(&fLocalAccessTime, &SysAccessTime);

			GetDateFormat(LOCALE_USER_DEFAULT, DATE_SHORTDATE, &SysAccessTime, NULL, szDate, 1024);
			GetTimeFormat(LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, &SysAccessTime, NULL, szTime, 1024);

			wsprintf(lpszAccessDateTime, _T("%s %s"), szDate, szTime);

			return true;
		}
		return false;
	}

	bool GetFileDateTime(LPTSTR lpszDateTime)
	{
		if (!m_bInitSucceeded)
			return false;

		is::auto_hfile hFile(CreateFile(m_strFileName.c_str(), 0/*GENERIC_READ*/,
							   FILE_SHARE_READ,
							   NULL,
							   OPEN_EXISTING,
							   FILE_ATTRIBUTE_NORMAL,
							   NULL)); // 0 for dwDesiredAccess allows it to check files in use.

		FILETIME fTimeWrite;
		if (hFile && ::GetFileTime(hFile, NULL, NULL, &fTimeWrite ))
		{
	        FILETIME fLocalTime;
			SYSTEMTIME SysTime;

			::FileTimeToLocalFileTime(&fTimeWrite, &fLocalTime);
			::FileTimeToSystemTime(&fLocalTime, &SysTime);

			wsprintf(lpszDateTime, _T("%02d-%02d-%d  %02d:%02d:%02d"),
				SysTime.wMonth, SysTime.wDay, SysTime.wYear, 
				SysTime.wHour, SysTime.wMinute, SysTime.wSecond);

			return true;
		}
		return false;
	}

	bool GetFileDateTime(SYSTEMTIME& SysTime)
	{
		if (!m_bInitSucceeded)
			return false;

		is::auto_hfile hFile(CreateFile(m_strFileName.c_str(), 0/*GENERIC_READ*/,
							   FILE_SHARE_READ,
							   NULL,
							   OPEN_EXISTING,
							   FILE_ATTRIBUTE_NORMAL,
							   NULL)); // 0 for dwDesiredAccess allows it to check files in use.

		FILETIME fTimeWrite;
		if (hFile && ::GetFileTime(hFile, NULL, NULL, &fTimeWrite ))
		{
	        FILETIME fLocalTime;

			::FileTimeToLocalFileTime(&fTimeWrite, &fLocalTime);
			::FileTimeToSystemTime(&fLocalTime, &SysTime);

			return true;
		}
		return false;
	}

	bool GetFileLanguages(std::vector<WORD>& veclanguages)
	{
		return GetTranslationData(veclanguages, true);
	}

	bool GetCodePage(std::vector<WORD>& vecCodePage)
	{
		return GetTranslationData(vecCodePage, false);
	}

	bool GetProperty(LPCTSTR lpszValueName, WORD dwLang, WORD dwCodePage, LPTSTR lpstrValue)
	{
		if (!GetVersionInfoBlock())
			return false;

		_ASSERT(lpstrValue);

		TCHAR szName[_MAX_PATH] = {0};
		wsprintf(szName, _T("\\StringFileInfo\\%04x%04x\\%s"),
				dwCodePage, dwLang, lpszValueName);

		LPVOID lpBuffer;
		UINT nSize = 0;
		if (!VerQueryValue(m_pVersion, szName, reinterpret_cast<void**>(&lpBuffer), &nSize))
			return false;

		lstrcpy(lpstrValue, reinterpret_cast<TCHAR*>(lpBuffer));

		return true;
	}

	bool Init(LPCTSTR lpszFileName)
	{
		Release();

		m_strFileName = lpszFileName;

		m_bInitSucceeded = IsFileExist();
		return m_bInitSucceeded;
	}

	bool IsArchive() const
	{
		if(this->GetFileAttributes() & FILE_ATTRIBUTE_ARCHIVE)
			return true;
		return false;
	}

	bool IsSystem() const
	{
		if(this->GetFileAttributes() & FILE_ATTRIBUTE_SYSTEM)
			return true;
		return false;
	}

	bool IsHidden() const
	{
		if(this->GetFileAttributes() & FILE_ATTRIBUTE_HIDDEN)
			return true;
		return false;
	}

	bool IsReadOnly() const
	{
		if(this->GetFileAttributes() & FILE_ATTRIBUTE_READONLY)
			return true;
		return false;
	}

	bool IsCheckSum() const
	{
		_ASSERT(m_bInitSucceeded);

		is::auto_hfile hFile(CreateFile( m_strFileName.c_str(),
							GENERIC_READ,
							FILE_SHARE_READ,
							NULL,
							OPEN_EXISTING,
							0,
							NULL
						  ));

		// seek to the beginning of the file
		if (::SetFilePointer( hFile, 0, 0, FILE_BEGIN ) == -1L)
			return false;

		// read in the dos header
		DWORD cb;
		IMAGE_DOS_HEADER dosHdr;
		if ((::ReadFile(hFile, &dosHdr, sizeof(dosHdr), &cb, 0) == FALSE) || (cb != sizeof(dosHdr)))
			return false;

		// read in the pe header
		if ((dosHdr.e_magic != IMAGE_DOS_SIGNATURE) ||
			(::SetFilePointer(hFile, dosHdr.e_lfanew, 0, FILE_BEGIN) == -1L))
			return false;

		// read in the nt header
		IMAGE_NT_HEADERS   ntHdr;
		if ((!::ReadFile(hFile, &ntHdr, sizeof(ntHdr), &cb, 0)) || (cb != sizeof(ntHdr)))
			return false;

		if (::SetFilePointer(hFile, dosHdr.e_lfanew, 0, FILE_BEGIN) == -1L)
			return false;

		return (ntHdr.OptionalHeader.CheckSum > 0) ? true : false;
	}
	
	bool IsFilePE()
	{
		if(GetFilePEType() != -1)
			return true;
		return false;
	}

	void GetFileType(EnumFileType *enumFileType)
	{
		int nRetVal = GetFilePEType();
		switch(nRetVal)
		{
		case ISSYS_NON_EXECUTABLE:
			*enumFileType = eftUnknown;
			break;
		case ISSYS_EXECUTABLE_LIB:
			*enumFileType = eftDLL;
			break;
		case ISSYS_NT_EXECUTABLE:
		case ISSYS_DOS_EXECUTABLE:
		case ISSYS_OS2_EXECUTABLE:
		case ISSYS_VXD_EXECUTABLE:
		case ISSYS_LX_EXECUTABLE:
			*enumFileType = eftEXE;
			break;
		}
	}

	bool IsIconFile()
	{
		HANDLE hFile;
		bool bIconFile = false;

		hFile = CreateFile(m_strFileName.c_str(), GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (hFile == INVALID_HANDLE_VALUE)
			return bIconFile;

		ICONDIR icondir;
		ZeroMemory(&icondir, sizeof(ICONDIR));

		DWORD dwBytesRead = 0;

		// Read the Reserved word
		ReadFile( hFile, &(icondir.idReserved), sizeof( WORD ), &dwBytesRead, NULL );
		if (icondir.idReserved)
		{
			CloseHandle(hFile);
			return bIconFile;
		}

		// Read the Type word - make sure it is 1 for icons
		ReadFile( hFile, &(icondir.idType), sizeof( WORD ), &dwBytesRead, NULL );
		if (icondir.idType != 1)
		{
			CloseHandle(hFile);
			return bIconFile;
		}
		
		bIconFile = true;
		CloseHandle(hFile);
		return bIconFile;
	}

	bool IsFileUnicode()
	{
		bool bUnicode = false;

		DWORD dwSize = 0;
		if (GetFileSize(&dwSize))
		{
			// For performance reasons we will give up after the first 1024 bytes.
			const int maxSize = 1024;
			if (dwSize > maxSize) dwSize = maxSize;
	
			USES_CONVERSION;
			FILE* f = fopen(T2A((LPTSTR)m_strFileName.c_str()), "r");
			if (f)
			{
				// allocate new buffer and read from file
				char* pszBuff = new char[dwSize];
				strcpy(pszBuff, "");
				dwSize = fread(pszBuff, sizeof(char), dwSize, f);
			
				// Check for Unicode byte-order mark at start of file
				if (dwSize >= 2 && pszBuff[0] == '\xFF' && pszBuff[1] == '\xFE')
				{
					bUnicode = true;
				}
				else 
				{
					// could be a unicode file without marks, i.e. PerfStringBackup.ini
					// search the file for zero-value bytes.
					for (DWORD dw = 0; (dw < dwSize) && (!bUnicode); ++dw)
							bUnicode = (pszBuff[dw] == NULL);
				}
										
				// destroy buffer
				delete [] pszBuff;

				// close file
				fclose(f);
			}
		}

		return bUnicode;
	}

private:
	DWORD GetFileAttributes() const
	{
		_ASSERT(m_bInitSucceeded);

		DWORD dwAttr = ::GetFileAttributes(m_strFileName.c_str());
		if (0xFFFFFFFF == dwAttr)
			return 0;
		return dwAttr;
	}

	CFileInfo(const CFileInfo&);
	CFileInfo& operator=(const CFileInfo&);


	bool GetTranslationData(std::vector<WORD>& vecData, bool bLang)
	{
		if (!GetVersionInfoBlock())
			return false;

		LPDWORD lpBuffer;
		UINT nSize = 0;
		if (!VerQueryValue(m_pVersion, _T("\\VarFileInfo\\Translation"), reinterpret_cast<void**>(&lpBuffer), &nSize))
			return false;

		if (bLang)
		{
			for(UINT nCount = 0; nCount < nSize/sizeof(DWORD); nCount++)
				vecData.push_back(LOWORD(lpBuffer[nCount]));
		}
		else
		{
			for(UINT nCount = 0; nCount < nSize/sizeof(DWORD); nCount++)
				vecData.push_back(HIWORD(lpBuffer[nCount]));
		}

		return true;

	}

	bool GetVersionInfoBlock()
	{
		if (!m_bInitSucceeded)
			return false;

		Release();

		LPCTSTR lpszFileName = m_strFileName.c_str();

		_ASSERT(lpszFileName);

		UINT nSize = GetFileVersionInfoSize(const_cast<LPTSTR>(lpszFileName), 0);
		if (nSize <= 0)
			return false;

		//try
		//{
			m_pVersion = new BYTE[nSize];
		//}
		//catch(...)
		//{
		//}
		if (!GetFileVersionInfo(const_cast<LPTSTR>(lpszFileName), 0, nSize, m_pVersion))
			return false;

		return true;
	}



	void Release()
	{
		if (m_pVersion)
			delete [] m_pVersion;
		m_pVersion = NULL;
	}

	bool IsFileExist() const
	{
		if (0xFFFFFFFF == ::GetFileAttributes(m_strFileName.c_str()))
			return false;
		return true;
	}

	//	Get the pe image type
	int ImageType (LPVOID lpFileBase, DWORD dwFileSize)
	{
		int iFileType = ISSYS_NON_EXECUTABLE;

		// If we get here, the file exists, and was mapped.  We're still not
		// sure that it's a valid EXE though
		if ( dwFileSize < sizeof(IMAGE_DOS_HEADER) )
			return iFileType;

		PIMAGE_DOS_HEADER pDosHdr = (PIMAGE_DOS_HEADER)lpFileBase;
		if ( IMAGE_DOS_SIGNATURE != pDosHdr->e_magic )
			return iFileType;
		
		// If we get here, it's at least a DOS 'MZ' file
		if ( pDosHdr->e_lfarlc < 0x40 ) // Theoretically, this field must be >=
		{                               // 0x40 for it to be a non-DOS executable
			iFileType = ISSYS_DOS_EXECUTABLE;
			return iFileType;
		}


		// Sanity check.  Make sure the "new header" offset isn't past the end
		// of the file
		if ( pDosHdr->e_lfanew > (LONG)dwFileSize )
			return iFileType;

		// Make a pointer to the secondary header   
		PWORD pSecondHdr = MakePtr( PWORD, lpFileBase, pDosHdr->e_lfanew );

		// Decide what type of EXE, based on the start of the secondary header
		switch ( *pSecondHdr )
		{
			case IMAGE_OS2_SIGNATURE: iFileType = ISSYS_OS2_EXECUTABLE; return iFileType;
			case IMAGE_VXD_SIGNATURE: iFileType = ISSYS_VXD_EXECUTABLE; return iFileType;
			case 0x4558: iFileType = ISSYS_LX_EXECUTABLE; return iFileType;     // OS/2 2.X
		}
    
		if ( *(PDWORD)pSecondHdr != IMAGE_NT_SIGNATURE )
			return iFileType;

		//	Copy the PE header
		IMAGE_FILE_HEADER image_file_header;
		CopyMemory ((LPVOID)&image_file_header, PEFHDROFFSET (lpFileBase), sizeof (IMAGE_FILE_HEADER));

		// Check the characteristics field to determine whether the file is a DLL
		if (image_file_header.Characteristics & IMAGE_FILE_DLL)
			iFileType = ISSYS_EXECUTABLE_LIB;

		else if (image_file_header.Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE)
			iFileType = ISSYS_NT_EXECUTABLE;

		return iFileType;
	}

	// Checks whether a file is a DLL.
	int GetFilePEType()
	{
		int iFileType = ISSYS_NON_EXECUTABLE;

		_ASSERTE(m_strFileName.c_str() != NULL);

		//	Open the reference file.
		is::auto_hfile hImage;
		hImage = CreateFile(m_strFileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL,
					OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (! hImage.valid())
			return iFileType;

		DWORD dwFileSize = ::GetFileSize( hImage, 0 );

		/* map view of file */
		is::auto_hfile hMMFile;
		hMMFile = CreateFileMapping (hImage, NULL, PAGE_READONLY, 0, 0, NULL);
		if (hMMFile.valid())
		{
			auto_hMapFile lpMem;
			lpMem = MapViewOfFile (hMMFile, FILE_MAP_READ, 0, 0, 0);
			if (lpMem != NULL)
				return ImageType(lpMem, dwFileSize);
		
		}	/* end of if(hMMFile) */

		return iFileType;
	}

private:
	BYTE *m_pVersion;
	std::basic_string<TCHAR> m_strFileName;
	bool m_bInitSucceeded;

};

#endif // !defined(AFX_FILEINFO_H__7030270C_DF09_11D3_A8D5_00105A996B60__INCLUDED_)
