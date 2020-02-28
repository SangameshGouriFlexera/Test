#pragma once

namespace ASRegistry
{
	static inline bool GetEnableAppVLauncher()
	{
		bool bEnable = true;

		CRegKey key;
		if (ERROR_SUCCESS == key.Open(HKEY_LOCAL_MACHINE, _T("Software\\InstallShield\\AdminStudio"), KEY_READ))
		{
			TCHAR szCurrentVersion[16];
			DWORD dwCount = sizeof(szCurrentVersion)/sizeof(TCHAR);
			if (ERROR_SUCCESS == key.QueryValue(szCurrentVersion, _T("CurrentVersion"), &dwCount))
			{
				CRegKey versionKey;
				if (ERROR_SUCCESS == versionKey.Open(key, szCurrentVersion, KEY_READ))
				{
					TCHAR szEnable[8];
					if (ERROR_SUCCESS == versionKey.QueryValue(szEnable, _T("EnableAppVLauncher"), &dwCount))
					{
						bEnable = !_tcscmp(szEnable, _T("1"));
					}
				}
			}
		}

		return bEnable;
	}
}