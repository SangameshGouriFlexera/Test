#pragma once

#include "localinfo.h"

class CCurrentDirectoryChanger
{
public:
	enum EInitialDirectory
	{
		eidAdminStudioCommon
	};

	CCurrentDirectoryChanger(EInitialDirectory eid)
	{
		//DEBUG3(_T("CCurrentDirectoryChanger(EInitialDirectory eid) - Called"));

		CString sDirectory;

		CLocalInfo localInfo;

		switch(eid)
		{
			case eidAdminStudioCommon:
				localInfo.GetCommonFolder(sDirectory);
				break;
			default:
				ATLASSERT(_T("Unrecognized Initial Directory")==0);
				break;
		}

		ChangeDirectory(sDirectory);
	}

	CCurrentDirectoryChanger(CString sDirectory)
	{
		//DEBUG3(_T("CCurrentDirectoryChanger(CString sDirectory) - Called"));
		ChangeDirectory(sDirectory);		
	}

	void ChangeDirectory(CString sDirectory)
	{
		//DEBUG3(_T("void ChangeDirectory(CString sDirectory) - Called"));
		::GetCurrentDirectory(MAX_PATH*4,m_strOriginalDirectory.GetBuffer(MAX_PATH*4));
		SetCurrentDirectory(sDirectory);
	}

	~CCurrentDirectoryChanger()
	{
		//DEBUG3(_T("~CCurrentDirectoryChanger() - Called"));
		SetCurrentDirectory(m_strOriginalDirectory);
	}

private:
	CString m_strOriginalDirectory;
};