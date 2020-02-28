#ifndef _PROCESS_EXCEPTION_H
#define _PROCESS_EXCEPTION_H

#include <stdio.h>
#include "auto_handle.hxx"
#include "pathx.h"
#include <strstream>
#include <com_exception.h>
#include <stdexception.h>
#include <IsMsiError.h>
#include <atlbase.h>
#include <afxdisp.h>

#ifdef _UNICODE

#define WIDEN2(x) L ## x
#define WIDEN(x) WIDEN2(x)
#define IS_T__FILE__	WIDEN(__FILE__)

#else

#define IS_T__FILE__	__FILE__

#endif

//extern const TCHAR *g_szLogFile;
//extern const TCHAR *g_szWackLogFile;

#define PROCESS_EXCEPTION(e) \
    { \
        ProcessException(e, IS_T__FILE__, __LINE__); \
    }

#define PROCESS_UNKNOWN_EXCEPTION() \
    { \
        ProcessException(NULL, IS_T__FILE__, __LINE__); \
    }

#define THROW_EXCEPTION(e) \
    { \
        return ProcessAndReturnException(e, IS_T__FILE__, __LINE__); \
    }

#define THROW_UNKNOWN_EXCEPTION() \
    { \
        return ProcessAndReturnException(NULL, IS_T__FILE__, __LINE__); \
    }

class CLogException
{
public:
    void WriteToLogFile(LPCTSTR lpszErrorMessage)
    {
		try
		{
			OpenLogFile();
			if(m_file)
			{
			    _fputts(lpszErrorMessage, m_file);
			}
		}
		catch(...)
		{
		}
    }

    void WriteToLogFile(LPCTSTR lpszErrorMessage, LPTSTR lpszFileName, long nLineNo)
    {
		try
		{
			OpenLogFile();
			if(m_file)
			{
				std::ostrstream strFormattedData;
				strFormattedData << lpszErrorMessage << '\n';
				strFormattedData << _T("File: ") << lpszFileName << '\n';
				strFormattedData << _T("Line: ") << nLineNo << '\n';
				strFormattedData << std::ends;

				USES_CONVERSION;
			    _fputts(A2T(strFormattedData.str()), m_file);
				strFormattedData.rdbuf()->freeze(0);
			}
		}
		catch(...)
		{
		}
    }

private:

	//	-----------------------------------------------------------------------------
	void WriteDateTime()
	{
		COleDateTime timeNow = COleDateTime::GetCurrentTime();
		CString strTime = timeNow.Format(_T("%d-%b-%Y, %H:%M:%S"));

		CString strFormattedData = _T("\n----------------");
		strFormattedData += strTime;
		strFormattedData += _T("------------------");
		_fputts(strFormattedData, m_file);
	}



	//	-----------------------------------------------------------------------------
	void OpenLogFile()
	{
		try
		{
/*			CRegKey regKey;
			if(regKey.Open(HKEY_LOCAL_MACHINE, g_szLogFile, KEY_READ) == ERROR_SUCCESS)
			{
				TCHAR strValue[1024] = {0};
				DWORD dwCount = 1024;
				if (regKey.QueryValue(strValue, g_szWackLogFile, &dwCount) == ERROR_SUCCESS)
				{
					try
					{
						is::pathw pthFile = strValue;
						is::pathw pthDir = pthFile.dir();
						is::stringwi strFile = pthFile.file();

						if(pthDir.exists(is::pathw::eptDir) && strFile.length())
						{
							m_file = _tfopen(strValue, "a+");
							return;
						}
					}
					catch(...)
					{
					}
				}
			}
*/
			TCHAR strValue[1024] = {0};
			::GetModuleFileName(NULL, strValue, 1024);

			// Replace the extension with the '.'
			LPTSTR lpszDot = _tcsrchr(strValue, _T('.'));
			if(lpszDot)
			{
				lpszDot++;
				if(_tcslen(lpszDot) >= 3)
				{
					_tcscpy(lpszDot, _T("log"));
				}
			}
			else
			{
				_tcsncat(strValue, _T(".log"), 4);
			}
			m_file = _tfopen(strValue, _T("a+"));

			WriteDateTime();
		}
		catch(...)
		{
		}
	}
private:
	is::auto_stream m_file;
};


static void ProcessException(CException *pException, 
	LPTSTR lpszFileName, long nLineNo)
{
	CLogException logException;
	if (pException != NULL)
	{
		try
		{
			TCHAR szErrorMessage[2048];
			if (pException->GetErrorMessage(szErrorMessage, 2048))
			{
				std::ostrstream strFormattedData;
				strFormattedData << "\n";

				//	Add the error number of the message to the log file.
				CComException *pComException = dynamic_cast<CComException*>(pException);
				if (pComException)
				{
					HRESULT hr = pComException->m_e.hresult();
					
					//	Convert to MSI error, if necessary
					hr = HRESULT_TO_MSI(hr);
					strFormattedData << _T("Error: ") << hr << '\t';
				}

				strFormattedData << szErrorMessage << std::ends;
				USES_CONVERSION;
				logException.WriteToLogFile(A2T(strFormattedData.str()));
				strFormattedData.rdbuf()->freeze(0);

//	Remove the File and Line number for non-debug builds.
#ifndef _DEBUG
				LPTSTR lpszMessage = _tcsstr(szErrorMessage, _T("File:"));
				if (lpszMessage)
					*lpszMessage = '\0';
#endif
				AfxMessageBox(szErrorMessage);
			}
			else
			{
				logException.WriteToLogFile(_T("Exception encountered, Error Message Not Available"), lpszFileName, nLineNo);
				AfxMessageBox(_T("Exception encountered, Error Message Not Available"));
			}
			pException->Delete();
		}
		catch(...)
		{
			AfxMessageBox(_T("Unknown exception encountered"));
			pException->Delete();
		}
	}
	else
	{
		logException.WriteToLogFile(_T("Unknown exception encountered"), lpszFileName, nLineNo);
		AfxMessageBox(_T("Unknown exception encountered"));
	}
}

static HRESULT ProcessAndReturnException(CException *pException, LPTSTR lpszFileName, long nLineNo)
{
	if (pException != NULL)
	{
		try
		{
			CComException *pComException = dynamic_cast<CComException*>(pException);

			if (pComException)
			{
				com_exception *pe = &(pComException->m_e);
				return AtlSetErrorInfo(pe->clsid(), CComBSTR(pe->what()), 
					0, NULL, pe->iid(), pe->hresult(), NULL);
			}
		}
		catch(...)
		{
		}

		pException->Delete();
	}
	return E_UNEXPECTED;
}

#endif