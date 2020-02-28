// ismsi.h
// wrapper of MSI API that handles error codes

#ifndef _ISMSI_H
#define _ISMSI_H

#include <hrx_new.h> // Includes atlbase.h
#include <MsiRecordString.h> // Includes msi.h and msiquery.h

#ifndef __ISWACK
#include <hresults.h>
#endif

#include <stringx.h>

const int _MAX_COL_NAME_SIZE = 127; // No column name is even close to this long.

// user-defined namespace for MSI API
#ifndef MSI
#define MSI
#endif

#pragma comment( lib, "shlwapi" ) // The Path* APIs require this.

class ismsi
{
public:
    static void MsiOpenDatabase(
        LPCTSTR szDatabasePath,  // path to database
        LPCTSTR szPersist,       // output database or predefined persist mode
        MSIHANDLE *phDatabase    // location to return database handle
        )
    {
        CheckError(MSI::MsiOpenDatabase(szDatabasePath, szPersist, phDatabase),
            _T("MsiOpenDatabase"), szDatabasePath);
    }

    static void MsiGetProperty(
        MSIHANDLE hInstall,    // installer handle
        LPCTSTR szName,        // property identifier, case-sensitive
        LPTSTR szValueBuf,     // buffer for returned property value
        DWORD *pchValueBuf     // in/out buffer character count
        )
    {
        CheckError(MSI::MsiGetProperty(hInstall, szName, szValueBuf, pchValueBuf),
            _T("MsiGetProperty"), szName);
    }

    static void MsiDatabaseGenerateTransform(
      MSIHANDLE hDatabase,          // database handle
      MSIHANDLE hDatabaseReference, // base database to reference changes
      LPCTSTR szTransformFile,      // name of generated transform file
      int iReserved1,               // this must be set to 0
      int iReserved2                // this must be set to 0
    )
    {
        CheckError(MSI::MsiDatabaseGenerateTransform(hDatabase, hDatabaseReference,
            szTransformFile, iReserved1, iReserved2),
            _T("MsiDatabaseGenerateTransform"), szTransformFile);
    }
	
    static void MsiCreateTransformSummaryInfo(
		MSIHANDLE hDatabase,          // database handle
		MSIHANDLE hDatabaseReference, // base database to reference changes
		LPCTSTR   szTransformFile,    // name of generated transform file
		int       iErrorConditions,    // errors to suppress when applied, from MSITRANSFORM_ERROR
		int       iValidation        // properties validated when applied, MSITRANSFORM_VALIDATE
	)
    {
        CheckError(MSI::MsiCreateTransformSummaryInfo(hDatabase, hDatabaseReference,
            szTransformFile, iErrorConditions, iValidation),
            _T("MsiDatabaseGenerateTransform"), szTransformFile);
    }
	static void MsiDatabaseApplyTransform(MSIHANDLE hDatabase,
		LPCTSTR szTransformFile, int iErrorConditions)
	{
        CheckError(MSI::MsiDatabaseApplyTransform(hDatabase, szTransformFile,
            iErrorConditions),_T("MsiDatabaseApplyTransform"), szTransformFile);
	}

	static void MsiDatabaseMerge(MSIHANDLE hDatabase,
		MSIHANDLE hDatabaseMerge,    // database to be merged into hDatabase
		LPCTSTR   szTableName)      // name of non-persistent table to receive errors
	{
        CheckError(MSI::MsiDatabaseMerge(hDatabase, hDatabaseMerge, szTableName),
            _T("MsiDatabaseMerge"));
	}

	static void MsiOpenPackage(LPCTSTR szPackagePath,     // path to package, or database handle: #nnnn
		MSIHANDLE  *hProduct)         // returned product handle, must be closed
	{
        CheckError(MSI::MsiOpenPackage(szPackagePath, hProduct), 
			_T("MsiOpenPackage"), szPackagePath);
	}

    static void MsiCloseHandle(
        MSIHANDLE hAny    // Installer handle
    )
    {
        CheckError(MSI::MsiCloseHandle(hAny), _T("MsiCloseHandle"));
    }
 
	// Handles buffer resizing.
    static std::basic_string<TCHAR> MsiRecordGetStringEx(MSIHANDLE hRecord, UINT iField)
	{
		CMsiRecordString recstr(hRecord, iField); // Object handles ERROR_MORE_DATA.
		CheckError(recstr.Result(), _T("MsiRecordGetString"));
		return LPCTSTR(recstr);
	}

	static void MsiRecordReadStream(MSIHANDLE hRecord,
		UINT iField, char *szDataBuf,     // buffer to receive bytes from stream
		DWORD   *pcbDataBuf)			  // in/out buffer byte count
	{
		CheckError(MSI::MsiRecordReadStream(hRecord, iField, szDataBuf, 
			pcbDataBuf), _T("MsiRecordReadStream"));
	}


	static UINT MsiDatabaseOpenView(MSIHANDLE hDatabase, LPCTSTR szQuery, 
		MSIHANDLE *phView)	
	{
		UINT uiResult = MSI::MsiDatabaseOpenView(hDatabase, szQuery, phView);
		CheckError(uiResult, _T("MsiOpenDatabaseView"));
		return uiResult;
	}

	static UINT MsiViewExecute(MSIHANDLE hView, MSIHANDLE hRecord)
	{
		UINT uiResult = MSI::MsiViewExecute(hView, hRecord);
		CheckError(uiResult, _T("MsiViewExecute"));
		return uiResult;
	}

	static UINT MsiViewFetch(MSIHANDLE hView, MSIHANDLE *phRecord, 
		bool bThrowIfNoItems = false)
	{
		UINT uiResult = MSI::MsiViewFetch(hView, phRecord);
		if ((uiResult != ERROR_SUCCESS) &&
			((bThrowIfNoItems) || (uiResult != ERROR_NO_MORE_ITEMS)))
			CheckError(uiResult, _T("MsiViewFetch"));

		return uiResult;
	}
	
	static UINT MsiViewGetColumnInfo(MSIHANDLE hView, MSICOLINFO eColumnInfo, 
		MSIHANDLE *phRecord)
	{
		UINT uiResult = MSI::MsiViewGetColumnInfo(hView, eColumnInfo, phRecord);
		CheckError(uiResult, _T("MsiViewGetColumnInfo"));
		return uiResult;
	}

	static UINT MsiRecordSetString(MSIHANDLE hRecord, UINT iField, LPCTSTR szValue)
	{
		UINT uiResult = MSI::MsiRecordSetString(hRecord, iField, szValue);
		CheckError(uiResult, _T("MsiRecordSetString"));
		return uiResult;
	}

    static void MsiRecordSetInteger(MSIHANDLE hRecord, UINT iField, int iValue)
	{
		UINT uiResult = MSI::MsiRecordSetInteger(hRecord, iField, iValue);
		CheckError(uiResult, _T("MsiRecordSetInteger"));
	}

    static UINT MsiRecordSetStream(MSIHANDLE hRecord, UINT iField, LPCTSTR szValue)
	{
		UINT uiResult = MSI::MsiRecordSetStream(hRecord, iField, szValue);
		CheckError(uiResult, _T("MsiRecordSetStream"));
		return uiResult;
	}

	static UINT MsiViewModify(MSIHANDLE hView, MSIMODIFY eModifyMode, MSIHANDLE hRecord)
	{
		UINT uiResult = MSI::MsiViewModify(hView, eModifyMode, hRecord);
		MSIDBERROR msiError;
		if (uiResult == ERROR_INVALID_DATA)
		{
			DWORD dwSize = _MAX_COL_NAME_SIZE; // Most column names aren't longer than 20.
			TCHAR szBadColumn[_MAX_COL_NAME_SIZE];
			msiError = MSI::MsiViewGetError(hView, szBadColumn, &dwSize);
		}
		CheckError(uiResult, _T("MsiViewModify"), _T(""), _T(""), msiError);
		return uiResult;
	}

	static UINT MsiDatabaseCommit(MSIHANDLE hDatabase)
	{
		UINT uiResult = MSI::MsiDatabaseCommit(hDatabase);
		CheckError(uiResult, _T("MsiDatabaseCommit"));
		return uiResult;
	}

	static void MsiSequence(MSIHANDLE hInstall, LPCTSTR szTable, INT iSequenceMode)
	{
        CheckError(MSI::MsiSequence(hInstall, szTable, iSequenceMode),
            _T("MsiSequence"), szTable);
	}

	static void MsiDoAction(MSIHANDLE hInstall, LPCTSTR szTable)
	{
        CheckError(MSI::MsiDoAction(hInstall, szTable), _T("MsiDoAction"), szTable);
	}

    static MSIHANDLE MsiCreateRecord(UINT cParams)
    {
        MSIHANDLE hRec = MSI::MsiCreateRecord(cParams);
        if (!hRec)
        {
            CheckError(ERROR_CREATE_FAILED, _T("MsiCreateRecord"));            
        }
        return hRec;
    }    

    static BOOL MsiRecordIsNull(MSIHANDLE hRecord, UINT iField)
    {
        return MSI::MsiRecordIsNull(hRecord, iField);
    }

    static int MsiRecordGetInteger(MSIHANDLE hRecord, UINT iField)
    {
        return MSI::MsiRecordGetInteger(hRecord, iField);
    }

    static UINT MsiSetProperty(MSIHANDLE hInstall, LPCTSTR szName, LPCTSTR szValue)
    {
		UINT uiResult = MSI::MsiSetProperty(hInstall, szName, szValue);
        CheckError(uiResult, _T("MsiSetProperty"), szName);
		return uiResult;
    }

	static UINT MsiGetFeatureState(MSIHANDLE hInstall, LPCTSTR szName, INSTALLSTATE *piInstalled, INSTALLSTATE *piAction)
    {
		UINT uiResult = MSI::MsiGetFeatureState(hInstall, szName, piInstalled, piAction);
        CheckError(uiResult, _T("MsiGetFeatureState"), szName);
		return uiResult;
    }

    static UINT MsiRecordGetFieldCount(MSIHANDLE hRecord)
    {
        return MSI::MsiRecordGetFieldCount(hRecord);
    }

	// This makes exports it to a file that does not already exist, based on your file name 
	// suggestion. It returns the filename to which the file was actually exported.
    static stringx MsiDatabaseExportEx(MSIHANDLE hDatabase, 
		LPCTSTR szTableName, LPCTSTR szFolderPath, LPCTSTR szSuggestedFileName)
    {
		stringx bstrExportFile = szFolderPath;
		bstrExportFile.path_append(szSuggestedFileName);

		// Make sure bstrExportFile doesn't already exist.
		int i = 0;
		while (::PathFileExists(bstrExportFile))
		{
			stringx bstrNew = bstrExportFile.path_dir();
			bstrNew.path_append(bstrExportFile.path_find_file_name_no_ext());
			bstrNew += stringx(i);
			bstrNew += bstrExportFile.path_ext();
			bstrExportFile = bstrNew;
			i++;
		}

		UINT iRes = MSI::MsiDatabaseExport(hDatabase, szTableName, 
			bstrExportFile.path_dir(), bstrExportFile.path_find_file_name());
		CheckError(iRes, _T("MsiDatabaseExport"));

		return bstrExportFile.path_find_file_name();
    }

	static void MsiDatabaseImport(MSIHANDLE hDatabase, LPCTSTR szFolderPath, 
		LPCTSTR szFileName)
	{
        CheckError(MSI::MsiDatabaseImport(hDatabase, szFolderPath, szFileName),
            _T("MsiDatabaseImport"), szFolderPath, szFileName);
	}

	static UINT MsiRecordClearData(MSIHANDLE hRecord)
	{
        UINT uiResult = MSI::MsiRecordClearData(hRecord);
		CheckError(uiResult, _T("MsiRecordClearData"));
		return uiResult;
	}
	
	static UINT MsiGetFileVersion(
		LPCTSTR szFilePath,      // path to the file
		LPTSTR lpVersionBuf,    // returned version string
		DWORD *pcchVersionBuf,   // buffer byte count
		LPTSTR lpLangBuf,       // returned language string
		DWORD *pcchLangBuf       // buffer byte count
		)
	{
		UINT uiResult = MSI::MsiGetFileVersion(szFilePath, lpVersionBuf, pcchVersionBuf,lpLangBuf,pcchLangBuf);
		//file invalid should not throw...this is a good error message...kind of like no more items.
		if(uiResult!=ERROR_FILE_INVALID)
		    CheckError(uiResult,_T("MsiGetFileVersion"));
		return uiResult;
    }

	static UINT MsiSummaryInfoSetProperty(
		MSIHANDLE hSummaryInfo, // summary information handle
		UINT uiProperty,        // property ID, one of allowed values
								//  for summary information
		UINT uiDataType,        // VT_I4, VT_LPSTR, VT_FILETIME,
				                  //  or VT_EMPTY
		INT iValue,             // integer value, used only if integer
				                  //  property
		FILETIME *pftValue,     // pointer to file-time value, used only
				                  //  if date/time property
		LPTSTR szValue          // text value, used only if string property
		)
	{
		UINT uiResult = MSI::MsiSummaryInfoSetProperty(hSummaryInfo, uiProperty, uiDataType,iValue,pftValue,szValue);
        CheckError(uiResult,
            _T("MsiSummaryInfoSetProperty"));
		return uiResult;
    }
	static UINT MsiSummaryInfoPersist(
		MSIHANDLE hSummaryInfo // summary information handle
		)
	{
		UINT uiResult = MSI::MsiSummaryInfoPersist(hSummaryInfo);
        CheckError(uiResult,
            _T("MsiSummaryInfoSetProperty"));
		return uiResult;
    }

	static UINT MsiGetSummaryInformation(
		MSIHANDLE hDatabase,   
		LPCTSTR szDatabasePath,
		UINT uiUpdateCount,  
        MSIHANDLE *phSummaryInfo
		)

	{
		UINT uiResult = MSI::MsiGetSummaryInformation(hDatabase, szDatabasePath, uiUpdateCount,phSummaryInfo);
        CheckError(uiResult,
            _T("MsiGetSummaryInformation"));
		return uiResult;
    }

	static INSTALLSTATE MsiLocateComponent(LPCTSTR szComponent,  LPTSTR lpPathBuf, DWORD *pcchBuf)
	{
        return MSI::MsiLocateComponent(szComponent, lpPathBuf, pcchBuf);
	}

	static UINT MsiSummaryInfoGetProperty(
		MSIHANDLE hDatabase,  
		UINT     uiProperty,     
		UINT     *puiDataType,   
		INT      *piValue,       
		FILETIME *pftValue,
		LPTSTR  szValueBuf, 
		DWORD    *pcchValueBuf)
	{
		UINT uiResult = MSI::MsiSummaryInfoGetProperty(hDatabase, uiProperty, puiDataType, piValue,pftValue, szValueBuf, pcchValueBuf);
        CheckError(uiResult,
            _T("MsiSummaryInfoGetProperty"));
		return uiResult;
    }
	
    static void CheckError(UINT iError, LPCTSTR str1 = _T(""),
        LPCTSTR str2 = _T(""), LPCTSTR str3 = _T(""), 
		MSIDBERROR msiError = MSIDBERROR_NOERROR)
    {
        if (iError != ERROR_SUCCESS)
        {
            // Determine the HRESULT we are going to raise with hrx
            HRESULT hres = HRESULT_FROM_WIN32(iError);
            if (SUCCEEDED(hres))
            {
                // Force an error
                hres = E_UNEXPECTED;
            }

            hrx hr;
            TCHAR* szMsg = 0;
            LPVOID lpMsgBuf = 0;
            //try
            //{
                USES_CONVERSION;
                TCHAR rgchBuf[1024];
                LPCTSTR str0 = _T("");
                PMSIHANDLE hError = MsiGetLastErrorRecord();
                if (hError)
                { 
                    if (MsiRecordIsNull(hError, 0))
                    {
                        MsiRecordSetString(hError, 0, _T("Windows Installer Error [1]: [2]{, [3]}{, [4]}{, [5]}\n"));
                    }
                    DWORD cchBuf = sizeof(rgchBuf)/sizeof(TCHAR);
                    //TODO: handle more-data
                    MsiFormatRecord(0, hError, rgchBuf, &cchBuf);
                    str0 = rgchBuf;
                }
                else
                {
                    if (::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER  |
                        FORMAT_MESSAGE_FROM_SYSTEM |
                        FORMAT_MESSAGE_IGNORE_INSERTS,
                        NULL, hres, 0, (LPTSTR)&lpMsgBuf, 0, NULL))
                    {
                        str0 = (LPCTSTR)lpMsgBuf;
                    }
                }

                int nLen = _tcsclen(str0) + _tcsclen(str1) + _tcsclen(str2) + _tcsclen(str3);

                szMsg = new TCHAR[nLen + 4];
                szMsg[0] = '\0';
                if (*str2 && *str3)
                {
                    ::wsprintf(szMsg, _T("%s%s(%s, %s)"), str0, str1, str2, str3);
                }
                else if (*str2)
                {
                    ::wsprintf(szMsg, _T("%s%s(%s)"), str0, str1, str2, str3);
                }
                else
                {
                    ::wsprintf(szMsg, _T("%s%s()"), str0, str1, str2, str3);
                }
        
                CComPtr<ICreateErrorInfo> spCreateErrorInfo;
                hr = ::CreateErrorInfo(&spCreateErrorInfo);
                hr = spCreateErrorInfo->SetDescription(T2W(szMsg));
                ATLTRACE(_T("Setting IErrorInfo to: \"%s\"\n"), szMsg);
                CComPtr<IErrorInfo> spErrorInfo;
                hr = spCreateErrorInfo->QueryInterface(&spErrorInfo);
                hr = ::SetErrorInfo(0, spErrorInfo);
            //}
			//catch (...)
			//{
			//    // If an exception occurred trying to set the error info,
			//    // what can we do?
			//    ATLASSERT(false);
			//}

            // Clean-up after catching exceptions
            delete[] szMsg;
            if (lpMsgBuf)
            {
                LocalFree(lpMsgBuf);
            }

            // Throw!
#ifndef __ISWACK
			if (msiError == MSIDBERROR_DUPLICATEKEY)
				hr = E_IS_DUP_PRIMARY;
			// Feel free to add any other MSIDBERRORs.
#endif
            hr = hres;
        }
    }
};

#endif // #define _ISMSI_H
