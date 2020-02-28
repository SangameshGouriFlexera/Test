#ifndef __APPREGKEY_H__
#define __APPREGKEY_H__

#include <vector>
#include <atlbase.h>
#include "Win32x.h"
#include "ErrorDesign.h"
#include "iscomacros.h"

class CAppRegKey
{
public:
	// --------------------------------------------------------------------------
	//	Description: This function gets a value from the registry key.
	//  The registry key is given by lpszKeyName and the the value name is given by lpszValueName
	//
	//	Returns: Returns the Success or Error Code and pbstrValue returns the value.
	// --------------------------------------------------------------------------
	static long GetRegKeyValue(HKEY hRootKey, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, BSTR *pbstrValue)
	{
		TRY_WIN32
		{
			ATL::CRegKey regKey;
			is::Win32x retVal = regKey.Open(hRootKey, lpszKeyName, KEY_READ);

			TCHAR strValue[1024] = {0};
			DWORD dwCount = 1024;
#if _MSC_VER > 1200 
			retVal = regKey.QueryStringValue(lpszValueName,strValue, &dwCount);
#else
			retVal = regKey.QueryValue(strValue, lpszValueName, &dwCount);
#endif
			CComBSTR bstrVal = strValue;
			*pbstrValue = bstrVal.Detach();
		}
		CATCH_WIN32

		return ERROR_SUCCESS;
	}

	// --------------------------------------------------------------------------
	//	Description: This function gets a value from the registry key.
	//  The registry key is given by lpszKeyName and the the value name is given by lpszValueName.
	//  If value does not exist then default value is returned
	//
	//	Returns: Returns the Succes or Error Code and pbstrValue returns the value.
	// --------------------------------------------------------------------------
	static long GetRegKeyValue(HKEY hRootKey, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, LPCTSTR lpszDefaultValue, BSTR *pbstrValue)
	{		
		long nRetVal = GetRegKeyValue(hRootKey, lpszKeyName, lpszValueName, pbstrValue);

		if (nRetVal != ERROR_SUCCESS || ! ::SysStringLen(*pbstrValue))
		{
			CComBSTR bstrValue = lpszDefaultValue;

			*pbstrValue = bstrValue.Detach();
		}
		return nRetVal;
	}

	// --------------------------------------------------------------------------
	//	Description: This function gets a value from the registry key. The registry
	//	key is given by lpszKeyName and the the value name is given by lpszValueName
	//
	//	Returns: Returns the Succes Code and pdwValue returns the value.
	// --------------------------------------------------------------------------
	static long GetRegKeyValue(HKEY hRootKey, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, DWORD *pdwValue)
	{
		CHECK_POINTER(pdwValue);

		TRY_WIN32
		{
			ATL::CRegKey regKey;
			is::Win32x retVal = regKey.Open(hRootKey, lpszKeyName, KEY_READ);
#if _MSC_VER > 1200
			retVal = regKey.QueryDWORDValue(lpszValueName, *pdwValue);
#else
			retVal = regKey.QueryValue( *pdwValue, lpszValueName);
#endif
		}
		CATCH_WIN32

		return ERROR_SUCCESS;
	}

	// --------------------------------------------------------------------------
	//	Description: This function gets a value from the registry key. The registry
	//	key is given by lpszKeyName and the the value name is given by lpszValueName
	//  If the ValueName does not exist, then default value is returned
	//
	//	Returns: Returns the Succes Code and pdwValue returns the value.
	// --------------------------------------------------------------------------
	static long GetRegKeyValue(HKEY hRootKey, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, DWORD dwDefault, DWORD *pdwValue)
	{
		CHECK_POINTER(pdwValue);

		long nRetVal = GetRegKeyValue(hRootKey, lpszKeyName, lpszValueName, pdwValue);

		if (nRetVal != ERROR_SUCCESS)
		{
			*pdwValue = dwDefault;
		}
		return nRetVal;
	}

	// --------------------------------------------------------------------------
	//	Description: This function sets a value in a registry key.
	//  The registry key is given by lpszKeyName and the the value name is given by lpszValueName
	//	The value to be set is given by bstrValue.
	//
	//	Returns: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long SetRegKeyValue(HKEY hRootKey, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, BSTR bstrValue)
	{
		ATLASSERT(VALID_BSTR(bstrValue));

		TRY_WIN32
		{
			is::Win32x retVal = ERROR_SUCCESS;

			ATL::CRegKey regKey;
			DWORD dwErrCode = regKey.Open(hRootKey, lpszKeyName, KEY_WRITE);

			if (dwErrCode != retVal)
				retVal = regKey.Create(hRootKey, lpszKeyName, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE);

			USES_CONVERSION;
#if _MSC_VER > 1200
			retVal = regKey.SetStringValue(lpszValueName, OLE2T(bstrValue));
#else
			retVal = regKey.SetValue( OLE2T(bstrValue), lpszValueName);
#endif
		}
		CATCH_WIN32

		return ERROR_SUCCESS;
	}

	// --------------------------------------------------------------------------
	//	Description: This function sets a value in a registry key.
	//	The registry key is given by lpszKeyName and the the value name is given by lpszValueName
	//	The value to be set is given by dwValue.
	//
	//	Returns: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long SetRegKeyValue(HKEY hRootKey, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, DWORD dwValue)
	{
		TRY_WIN32
		{
			is::Win32x retVal = ERROR_SUCCESS;

			ATL::CRegKey regKey;
			DWORD dwErrorCode = regKey.Open(hRootKey, lpszKeyName, KEY_WRITE);

			if (dwErrorCode != retVal)
				retVal = regKey.Create(hRootKey, lpszKeyName, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE);
#if _MSC_VER > 1200
			retVal = regKey.SetDWORDValue(lpszValueName,dwValue);
#else
			retVal = regKey.SetValue(dwValue,lpszValueName);
#endif
		}
		CATCH_WIN32

		return ERROR_SUCCESS;
	}

	// --------------------------------------------------------------------------
	//	Description: This function sets a value in a registry key.
	//	The registry key is given by lpszKeyName and the the value name is given by lpszValueName
	//	The value to be set is given by vbValue.
	//
	//	Returns: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long SetRegKeyValue(HKEY hRootKey, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, VARIANT_BOOL vbValue)
	{
		
		DWORD dwValue = vbValue == VARIANT_TRUE ? 1 : 0;
		return SetRegKeyValue(hRootKey, lpszKeyName, lpszValueName, dwValue);
	}

	// --------------------------------------------------------------------------
	//	Description: This function gives the number if values under a given key.
	//
	//	Return Value: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long GetRegKeyValueCount(HKEY hRootKey, LPCTSTR lpszKeyName, DWORD *pdwValueCount)
	{
		CHECK_POINTER(pdwValueCount);

		TRY_WIN32
		{
			ATL::CRegKey regKey;
			is::Win32x retVal = regKey.Open(hRootKey, lpszKeyName, KEY_READ);

			retVal = RegQueryInfoKey(regKey, NULL, NULL, NULL, NULL, NULL, NULL, pdwValueCount, NULL, NULL, NULL, NULL); 
		}
		CATCH_WIN32
				
		return ERROR_SUCCESS;	
	}

	// --------------------------------------------------------------------------
	//	Description: This function gives the number if SubKeys under a given key.
	//
	//	Return Value: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long GetRegKeySubKeysCount(HKEY hRootKey, LPCTSTR lpszKeyName, DWORD *pdwSubKeysCount)
	{
		CHECK_POINTER(pdwSubKeysCount);

		TRY_WIN32
		{
			ATL::CRegKey regKey;
			is::Win32x retVal = regKey.Open(hRootKey, lpszKeyName, KEY_READ);

			retVal = RegQueryInfoKey(regKey, NULL, NULL, NULL, pdwSubKeysCount, NULL, NULL, NULL, NULL, NULL, NULL, NULL); 
		}
		CATCH_WIN32
				
		return ERROR_SUCCESS;	
	}

	// --------------------------------------------------------------------------
	static long GetRegKeyValue(HKEY hRootKey, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, 
		VARIANT_BOOL vbDefault, VARIANT_BOOL* pVal)
	{
		CHECK_POINTER(pVal);

		DWORD dwValue = 1;
		long nRetVal = GetRegKeyValue(hRootKey, lpszKeyName, lpszValueName, &dwValue);
		if (nRetVal != ERROR_SUCCESS)
			*pVal = vbDefault;
		else
			*pVal = (dwValue == 1) ?  VARIANT_TRUE : VARIANT_FALSE;

		return nRetVal;
	}

	// --------------------------------------------------------------------------
	//	Description: This function gives a vector filled with all the SubKeys under a given registry key.
	//
	//	Return Value: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long EnumSubKeys(HKEY hRootKey, LPCTSTR lpszKeyName, std::vector<CAdapt<CComBSTR> >& regSubKeys)
	{
		regSubKeys.clear();

		TRY_WIN32
		{
			DWORD dwValue = 0;
			is::Win32x retVal = GetRegKeySubKeysCount(hRootKey, lpszKeyName, &dwValue);

			DWORD dwCount = 0;
			TCHAR szSubKeyName[1024] = {0};
			DWORD dwSize = 1024;

			ATL::CRegKey regKey;
			retVal = regKey.Open(hRootKey, lpszKeyName, KEY_READ);

			while (dwCount != dwValue)
			{
				retVal = RegEnumKeyEx(regKey, dwCount, szSubKeyName, &dwSize, 0, NULL, NULL, NULL);

				CComBSTR bstrValue(szSubKeyName);

				regSubKeys.push_back(bstrValue);

				dwSize = 1024;
				dwCount++;
			}
		}
		CATCH_WIN32

		return ERROR_SUCCESS;
	}

	// --------------------------------------------------------------------------
	//	Description: This function gives a vector filled with all the values under a given registry key.
	//
	//	Return Value: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long EnumValues(HKEY hRootKey, LPCTSTR lpszKeyName, std::vector<CAdapt<CComBSTR> >& regValues)
	{
		regValues.clear();

		TRY_WIN32
		{
			DWORD dwValue = 0;
			is::Win32x retVal = GetRegKeyValueCount(hRootKey, lpszKeyName, &dwValue);

			DWORD dwCount = 0;
			//Buffer for storing Value Name
			TCHAR szValueName[1024] = {0};
			//Buffer for storing Value
			TCHAR szValue[1024] = {0};

			LPBYTE lpData = reinterpret_cast<LPBYTE>(&szValue);
			DWORD dwValueNameSize = 1024;
			DWORD dwValueSize = 1024;

			ATL::CRegKey regKey;
			retVal = regKey.Open(hRootKey, lpszKeyName, KEY_READ);

			while (dwCount != dwValue)
			{
				retVal = RegEnumValue(regKey, dwCount, szValueName, &dwValueNameSize, 0, NULL, lpData, &dwValueSize);

				CComBSTR bstrValue(reinterpret_cast<TCHAR*>(lpData));

				regValues.push_back(bstrValue);

				dwValueNameSize = 1024;
				dwValueSize = 1024;
				dwCount++;
			}

		}
		CATCH_WIN32

		return ERROR_SUCCESS;
	}

	// --------------------------------------------------------------------------
	//	Description: This function gives a vector filled with all the value names under a given registry key.
	//
	//	Return Value: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long EnumValueNames(HKEY hRootKey, LPCTSTR lpszKeyName, std::vector<CAdapt<CComBSTR> >& regValueNames)
	{
		regValueNames.clear();

		TRY_WIN32
		{
			DWORD dwValue = 0;
			is::Win32x retVal = GetRegKeyValueCount(hRootKey, lpszKeyName, &dwValue);

			DWORD dwCount = 0;
			//Buffer for storing ValueName
			TCHAR szValueName[1024] = {0};
			DWORD dwSize = 1024;

			ATL::CRegKey regKey;
			retVal = regKey.Open(hRootKey, lpszKeyName, KEY_READ);

			while (dwCount != dwValue)
			{
				retVal = RegEnumValue(regKey, dwCount, szValueName, &dwSize, 0, NULL, NULL, NULL);

				CComBSTR bstrValue(szValueName);
				regValueNames.insert(regValueNames.begin(), bstrValue);

				dwSize = 1024;
				dwCount++;
			}

		}
		CATCH_WIN32

		return ERROR_SUCCESS;
	}

	// --------------------------------------------------------------------------
	//	Description: This function creates a key under the hRootKey parameter. The key name is specified by lpszKeyName
	//
	//	Returns: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long CreateRegKey(HKEY hRootKey, LPCTSTR lpszKeyName, REGSAM samDesired = KEY_ALL_ACCESS)
	{
		TRY_WIN32
		{
			ATL::CRegKey regKey;
			is::Win32x retVal = regKey.Create(hRootKey, lpszKeyName, REG_NONE, REG_OPTION_NON_VOLATILE, samDesired);
		}
		CATCH_WIN32

		return ERROR_SUCCESS;
	}

	// --------------------------------------------------------------------------
	//	Description: This function deletes all the values under a given key.
	//
	//	Returns: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long DeleteAllValues(HKEY hRootKey, LPCTSTR lpszKeyName)
	{
		TRY_WIN32
		{
			ATL::CRegKey regKey;
			is::Win32x retVal = regKey.Open(hRootKey, lpszKeyName, KEY_WRITE);

			std::vector< CAdapt<CComBSTR> > regValueNames;
			retVal = EnumValueNames(hRootKey, lpszKeyName, regValueNames);

			int nSize = regValueNames.size();

			USES_CONVERSION;
			while (nSize-- != 0)
			{
				CComBSTR bstrValue = regValueNames.at(nSize);

				regKey.DeleteValue(OLE2T(bstrValue));
			}
		}
		CATCH_WIN32
		
		return ERROR_SUCCESS;
	}

	// --------------------------------------------------------------------------
	//	Description: This function delete a given value under a given key.
	//
	//	Returns: Returns the Succes or Error Code
	// --------------------------------------------------------------------------
	static long DeleteValue(HKEY hRootKey, LPCTSTR lpszKeyName, LPCTSTR lpszValueName)
	{
		TRY_WIN32
		{
			ATL::CRegKey regKey;
			is::Win32x retVal = regKey.Open(hRootKey, lpszKeyName, KEY_WRITE);

			regKey.DeleteValue(lpszValueName);
		}
		CATCH_WIN32
		
		return ERROR_SUCCESS;
	}

};

#endif //__APPREGKEY_H__
