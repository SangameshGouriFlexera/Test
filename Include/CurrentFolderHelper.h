/**************************************************************************************************
* NOTICE OF COPYRIGHT AND OWNERSHIP OF SOFTWARE:
*
* Copyright (c) 1993-2005, Macrovision Corporation.  All Rights Reserved.
*
* This computer program is the property of Macrovision Europe Ltd. of Maidenhead, Berkshire,
* England and Macrovision Corporation of Santa Clara, California, U.S.A.
* Any use, copy, publication, distribution, display, modification, or transmission of this
* computer program in whole or in part in any form or by any means without the prior express
* written permission of Macrovision Europe Ltd. or Macrovision Corporation is strictly prohibited.
*
* Except when expressly provided by Macrovision Europe Ltd. or Macrovision Corporation in writing,
* possession of this computer program shall not be construed to confer any license or rights under
* any of Macrovision Europe Ltd.'s or Macrovision Corporation's intellectual property rights,
* whether by estoppel, implication, or otherwise.
*
* ALL COPIES OF THIS PROGRAM MUST DISPLAY THIS NOTICE OF COPYRIGHT AND OWNERSHIP IN FULL.
**************************************************************************************************/

#pragma once

#include "stringx.h"
#define ERROR_FUNCTION_NOT_CALLED        1626L

// Helper class which temporarily sets the module folder to the current one
class CCurrentFolderHelper
{
public:
	CCurrentFolderHelper(){};
	CCurrentFolderHelper(const stringxi& sDir)
	{
		SetDirectory(sDir);
	};

	void SetDirectory(const stringxi& sDir)
	{
		stringxi sOriginalCurrentFolder;
		::GetCurrentDirectory(MAX_PATH, sOriginalCurrentFolder.get_buffer(MAX_PATH));
		if(sOriginalCurrentFolder != sDir)
		{
			m_sOriginalCurrentFolder = sOriginalCurrentFolder;
			::SetCurrentDirectory(sDir);
		}
	}

	void UseModuleFolder(HMODULE hMod = NULL)
	{
		stringxi sModuleName;
#ifdef _CLRHOST_USE_COM_MODULE_INSTANCE
	#ifdef _ISDEV_USE_GLOBAL_MODULE_INSTANCE
			::GetModuleFileName(g_hInst, sModuleName.get_buffer(MAX_PATH), MAX_PATH);
	#else
			::GetModuleFileName(_Module.GetModuleInstance(), sModuleName.get_buffer(MAX_PATH), MAX_PATH);
	#endif
#else
		::GetModuleFileName(hMod, sModuleName.get_buffer(MAX_PATH), MAX_PATH);
#endif
		SetDirectory(sModuleName.path_dir());
	}

	virtual ~CCurrentFolderHelper()
	{
		if(!m_sOriginalCurrentFolder.empty())
		{
			::SetCurrentDirectory(m_sOriginalCurrentFolder);
		}
	}

private:
	stringxi m_sOriginalCurrentFolder;

};


// Helper class to temporarily set the DLL Loading directory to a given directory, module directory, or current directory
class CDllDirectoryHelper
{
	typedef BOOL (WINAPI *PfnSetDllDirectoryW)(LPCWSTR lpPathName);
	typedef BOOL (WINAPI *PfnSetDllDirectoryA)(LPCSTR lpPathName);

	typedef DWORD (WINAPI *PfnGetDllDirectoryW)(DWORD nBufferLength, LPWSTR lpBuffer);
	typedef DWORD (WINAPI *PfnGetDllDirectoryA)(DWORD nBufferLength, LPSTR lpBuffer);

#ifdef UNICODE
#define PfnSetDllDirectory PfnSetDllDirectoryW
#define SETDLLDIRECTORY "SetDllDirectoryW"
#define PfnGetDllDirectory PfnGetDllDirectoryW
#define GETDLLDIRECTORY "GetDllDirectoryW"
#else
#define PfnSetDllDirectory PfnSetDllDirectoryA
#define SETDLLDIRECTORY "SetDllDirectoryA"
#define PfnGetDllDirectory PfnGetDllDirectoryA
#define GETDLLDIRECTORY "GetDllDirectoryA"
#endif

public:
	CDllDirectoryHelper()
	{
		Load();
		UseCurrentDirectory();
	}
	CDllDirectoryHelper(const stringxi& sDir)
	{
		Load();
		SetDllDirectory(sDir);
	};
	CDllDirectoryHelper(HMODULE hMod)
	{
		Load();
		UseModuleFolder(hMod);
	}

	void SetDllDirectory(const stringxi& sDir)
	{
		stringxi sOriginalCurrentFolder;
		GetDllDirectory_(sOriginalCurrentFolder);
		if(sOriginalCurrentFolder != sDir)
		{
			if (m_sOriginalDllFolder.empty())
			{
				m_sOriginalDllFolder = sOriginalCurrentFolder;
			}
			SetDllDirectory_(sDir);
		}
	}

	void UseModuleFolder(HMODULE hMod = NULL)
	{
		stringxi sModuleName;
#ifdef _CLRHOST_USE_COM_MODULE_INSTANCE
#ifdef _ISDEV_USE_GLOBAL_MODULE_INSTANCE
		::GetModuleFileName(g_hInst, sModuleName.get_buffer(MAX_PATH), MAX_PATH);
#else
		::GetModuleFileName(_Module.GetModuleInstance(), sModuleName.get_buffer(MAX_PATH), MAX_PATH);
#endif
#else
		::GetModuleFileName(hMod, sModuleName.get_buffer(MAX_PATH), MAX_PATH);
#endif
		SetDllDirectory(sModuleName.path_dir());
	}

	void UseCurrentDirectory()
	{
		stringxi sCurrentDirectory;
		::GetCurrentDirectory(MAX_PATH, sCurrentDirectory.get_buffer(MAX_PATH + 1));
		SetDllDirectory_(sCurrentDirectory);
	}

	virtual ~CDllDirectoryHelper()
	{
		if(!m_sOriginalDllFolder.empty())
		{
			SetDllDirectory_(m_sOriginalDllFolder);
		}
	}

private:
	void Load()
	{
		HMODULE hK32 = ::GetModuleHandle(TEXT("KERNEL32"));
		m_GetDllDirectory = reinterpret_cast<PfnGetDllDirectory>(hK32 ? ::GetProcAddress(hK32, GETDLLDIRECTORY) : NULL);
		m_SetDllDirectory = reinterpret_cast<PfnSetDllDirectory>(hK32 ? ::GetProcAddress(hK32, SETDLLDIRECTORY) : NULL);
	}
	DWORD GetDllDirectory_(stringxi& sDirectory)
	{
		if (!m_GetDllDirectory)
		{
			SetLastError(ERROR_FUNCTION_NOT_CALLED);
			return 0;
		}

		DWORD dwSize = m_GetDllDirectory(MAX_PATH, sDirectory.get_buffer(MAX_PATH));
		if (!dwSize || dwSize < MAX_PATH)
			return dwSize;
		++dwSize;
		return m_GetDllDirectory(MAX_PATH, sDirectory.get_buffer(MAX_PATH));
	}
	BOOL SetDllDirectory_(const stringxi& sDirectory)
	{
		if (!m_SetDllDirectory)
		{
			SetLastError(ERROR_FUNCTION_NOT_CALLED);
			return FALSE;
		}
		return m_SetDllDirectory(sDirectory);
	}

	stringxi m_sOriginalDllFolder;
	PfnGetDllDirectory m_GetDllDirectory;
	PfnSetDllDirectory m_SetDllDirectory;
};