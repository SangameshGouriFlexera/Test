#ifndef _ODBC_UTILS_H_
#define _ODBC_UTILS_H_

namespace ODBCUtils
{
	static void ParseDatabaseString(CString& strConnection, const CString& strSubStr, CString& strActualName)
	{

		const TCHAR* lpszDelimiter = _T(";");
		
		LPTSTR lpszName;
		CString strDatabaseName(strConnection);
		lpszName = strDatabaseName.GetBuffer(2048);
		
		LPTSTR lpszToken = _tcstok(lpszName, lpszDelimiter);
		TCHAR* pCharPos;

		//parse and push the string in the vector
		while( lpszToken != NULL )
		{
			pCharPos = _tcsstr(lpszToken, strSubStr);
			if (pCharPos != NULL)
				break;
			lpszToken = _tcstok( NULL, lpszDelimiter );
		}

		lpszDelimiter = _T("=");
		lpszToken = _tcstok(lpszToken, lpszDelimiter);
		lpszToken = _tcstok( NULL, lpszDelimiter );
		if(lpszToken != NULL)
			strActualName = lpszToken;
		else
			strActualName = _T("");
	}

	static void CreateAccessFileDSN(CString& strConnectionStr, const CString& strpath, const CString& strDriver,
		CString& strUserName, CString& strPassword)
	{
		CString strToWrite;

		WritePrivateProfileString(_T("ODBC"), _T("DRIVER"), strDriver, strpath);
		
		strToWrite.Empty();
		ParseDatabaseString(strConnectionStr,_T("dbq="), strToWrite);
		WritePrivateProfileString(_T("ODBC"), _T("DBQ"), strToWrite, strpath);

		ParseDatabaseString(strConnectionStr,_T("user id="), strUserName);
		WritePrivateProfileString(_T("ODBC"), _T("UID"), strUserName, strpath);

		ParseDatabaseString(strConnectionStr,_T("password="), strPassword);
		WritePrivateProfileString(_T("ODBC"), _T("PWD"), strPassword, strpath);
	}


	static void CreateSQLServerFileDSN(CString& strConnectionStr, const CString& strpath, const CString& strDriver,
		CString& strUserName, CString& strPassword, CString& strDatabaseName)
	{
		CString strToWrite;

		WritePrivateProfileString(_T("ODBC"), _T("DRIVER"), strDriver, strpath);
		
		CString strNTSecurity;
		ParseDatabaseString(strConnectionStr, _T("integrated security="), strNTSecurity);
		if(strNTSecurity.GetLength() > 0 && (strNTSecurity.CompareNoCase(_T("sspi")) == 0))
			WritePrivateProfileString(_T("ODBC"), _T("Trusted_Connection"), _T("Yes"), strpath);

		ParseDatabaseString(strConnectionStr,_T("user id="), strUserName);
		WritePrivateProfileString(_T("ODBC"), _T("UID"), strUserName, strpath);

		ParseDatabaseString(strConnectionStr,_T("initial catalog="), strDatabaseName);
		WritePrivateProfileString(_T("ODBC"), _T("DATABASE"), strDatabaseName, strpath);

		ParseDatabaseString(strConnectionStr,_T("password="), strPassword);
		if (! strPassword.IsEmpty())
			WritePrivateProfileString(_T("ODBC"), _T("PWD"), strPassword, strpath);

		strToWrite.Empty();
		ParseDatabaseString(strConnectionStr,_T("data source="), strToWrite);


		strToWrite.MakeUpper();
		WritePrivateProfileString(_T("ODBC"), _T("SERVER"), strToWrite, strpath);
	}
	
	static void CreateOracleFileDSN(CString& strConnectionStr, const CString& strpath, const CString& strDriver,
		CString& strUserName, CString& strPassword, CString& strDatabaseName)
	{
		CString strToWrite;

		WritePrivateProfileString(_T("ODBC"), _T("DRIVER"), strDriver, strpath);
		
		CString strNTSecurity;
		ParseDatabaseString(strConnectionStr, _T("integrated security="), strNTSecurity);
		if(strNTSecurity.GetLength() > 0 && (strNTSecurity.CompareNoCase(_T("osauthent")) == 0))
			WritePrivateProfileString(_T("ODBC"), _T("UID"), _T("/"), strpath);
		else
			//as we need to proxy into the actual schema owner
			//which is identified by the catalog name
			//we pass that info in the UID & PWD,instead of the actual logged user.
			ParseDatabaseString(strConnectionStr,_T("initial catalog="), strUserName);
			WritePrivateProfileString(_T("ODBC"), _T("UID"), strUserName, strpath);

		ParseDatabaseString(strConnectionStr,_T("initial catalog="), strDatabaseName);
		//WritePrivateProfileString(_T("ODBC"), _T("DATABASE"), strDatabaseName, strpath);

		ParseDatabaseString(strConnectionStr,_T("initial catalog="), strPassword);
		if (! strPassword.IsEmpty())
			WritePrivateProfileString(_T("ODBC"), _T("PWD"), strPassword, strpath);

		strToWrite.Empty();
		ParseDatabaseString(strConnectionStr,_T("data source="), strToWrite);


		strToWrite.MakeUpper();
		WritePrivateProfileString(_T("ODBC"), _T("SRVR"), strToWrite, strpath);
	}

}
#endif // _ODBC_UTILS_H_