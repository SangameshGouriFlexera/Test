/*************************************************************************************************/
/*!@file ISAppServicesWrapper.h
* @brief Wrapper class for ISAppServices
*
*/
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

#include "IsCoCreateInProc.h"
#include "hrx_new.h"
#include "ComBool.h"

// src\inc
#include "IsAppServices.h"

#ifdef ISAPPSERVICES
	#include "AppSettings.h"
#endif

class IsAppServicesWrapper
{
	#define IAppServicesL IAppServicesQi
	#define IUserSettingsL IUserSettingsRipley
	#define ILocalSettingsL ILocalSettingsMajesty

public:

// User settings
//-----------------------------------------------------------------------------

	static CComPtr<IUserSettingsL> GetUserSettings()
	{
		CComPtr<IUserSettingsL> spUserSettings;
#ifdef ISAPPSERVICES
		// We can directly instantiate CAppSettings if this code is
		// called from inside of ISAppServices, which is faster than going
		// through ISCoCreateInstance
		CComObject<CAppSettings>* pAppSettings = NULL;
		hrx hr = CComObject<CAppSettings>::CreateInstance(&pAppSettings);
		spUserSettings = pAppSettings;
#else
		hrx hr = ISCoCreateInstance(ISAPPSERVICES_DLL, __uuidof(AppSettings), &spUserSettings);
#endif

		return spUserSettings;
	}

// Local Settings
//-----------------------------------------------------------------------------

	static CComPtr<ILocalSettingsL> GetLocalSettings()
	{
		CComPtr<ILocalSettingsL> spLocalSettings;
#ifdef ISAPPSERVICES
		// We can directly instantiate CAppSettings if this code is
		// called from inside of ISAppServices, which is faster than going
		// through ISCoCreateInstance
		CComObject<CAppSettings>* pAppSettings = NULL;
		hrx hr = CComObject<CAppSettings>::CreateInstance(&pAppSettings);
		spLocalSettings = pAppSettings;
#else
		hrx hr = ISCoCreateInstance(ISAPPSERVICES_DLL, __uuidof(AppSettings), &spLocalSettings);
#endif
		return spLocalSettings;
	}

// Wrapper for ILocalSetting->get_ISFilePath()
//-----------------------------------------------------------------------------
	static stringx GetISFilePath(EnumISFileId eFileId)
	{
		stringx sFilePath;
		hrx hr = GetLocalSettings()->get_ISFilePath(eFileId, &sFilePath);
		return sFilePath;
	}

// Wrapper for ILocalSetting->get_ISFolderPath()
//-----------------------------------------------------------------------------
	static stringx GetISFolderPath(ILocalSettingsL* pLocalSettings, EnumISFolderId eISFolderId)
	{
		stringx sFolderPath;
		hrx hr = pLocalSettings->get_ISFolderPath(eISFolderId, &sFolderPath);
		return sFolderPath;
	}

	static stringx GetISFolderPath(EnumISFolderId eISFolderId)
	{
		return GetISFolderPath(GetLocalSettings(), eISFolderId);
	}

	static stringx GetISRedistFilePath(EnumISFileId eISFileId, const stringx& sLangId, EnumProcessorArchitecture eOSArchitecture)
	{
		stringx sFilePath;
		hrx hr = GetLocalSettings()->get_ISRedistFilePath(eISFileId, sLangId, eOSArchitecture, &sFilePath);
		return sFilePath;
	}

// Wrapper for IUserSetting->get\put_UserSetting()
//-----------------------------------------------------------------------------
	static stringx GetUserSettingString(IUserSettingsL* pUserSettings, EnumUserSettingId eUserSettingId)
	{
		CComVariant vVal;
		hrx hr = pUserSettings->get_UserSetting(eUserSettingId, &vVal);
		ATLASSERT(V_VT(&vVal) == VT_BSTR);
		return V_BSTR(&vVal);
	}

	static stringx GetUserSettingString(EnumUserSettingId eUserSettingId)
	{
		return GetUserSettingString(GetUserSettings(), eUserSettingId);
	}

	static HRESULT PutUserSettingString(EnumUserSettingId eUserSettingId, const stringx& sValue)
	{
		return GetUserSettings()->put_UserSetting(eUserSettingId, CComVariant(sValue.c_str()));
	}

// Wrapper for IUserSetting->get_UserSetting()
//-----------------------------------------------------------------------------
	static bool GetUserSettingBool(IUserSettingsL* pUserSettings, EnumUserSettingId eUserSettingId)
	{
		CComVariant vVal;
		hrx hr = pUserSettings->get_UserSetting(eUserSettingId, &vVal);
		ATLASSERT(V_VT(&vVal) == VT_BOOL);
		return CComBool(V_BOOL(&vVal));
	}

	static bool GetUserSettingBool(EnumUserSettingId eUserSettingId)
	{
		return GetUserSettingBool(GetUserSettings(), eUserSettingId);
	}

	static HRESULT PutUserSettingBool(EnumUserSettingId eUserSettingId, bool bVal)
	{
		return GetUserSettings()->put_UserSetting(eUserSettingId, CComVariant(bVal));
	}


// Wrapper for IUserSetting->get_UserSetting()
//-----------------------------------------------------------------------------
	static DWORD GetUserSettingDWORD(EnumUserSettingId eUserSettingId)
	{
		CComVariant vVal;
		hrx hr = GetUserSettings()->get_UserSetting(eUserSettingId, &vVal);
		ATLASSERT(V_VT(&vVal) == VT_UI4);
		return V_UI4(&vVal);
	}

	static HRESULT PutUserSettingDWORD(EnumUserSettingId eUserSettingId, DWORD dwValue)
	{
#if _MSC_VER < 1400
		// VC6
		return GetUserSettings()->put_UserSetting(eUserSettingId, CComVariant(dwValue, VT_UI4));
#else
		// VC8
		return GetUserSettings()->put_UserSetting(eUserSettingId, CComVariant(dwValue));
#endif
	}

};



