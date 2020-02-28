#ifndef _DATABASE_ACCESS_H_
#define _DATABASE_ACCESS_H_

#include <vector>

typedef std::vector<tstring> VEC_RECORDS;
typedef VEC_RECORDS::iterator VEC_RECORDS_ITERATOR;

typedef std::vector<tstring> VEC_ONERECORD;
typedef VEC_ONERECORD::iterator VEC_ONERECORD_ITERATOR;

class CISDatabaseAccess
{
public:

	//----------------------------------------------------------------------
	CISDatabaseAccess(CComQIPtr<_Connection> spConnection)
	{
		m_spConnection = spConnection;
	}

	//----------------------------------------------------------------------
	virtual ~CISDatabaseAccess(){}

	//----------------------------------------------------------------------
	void get_Records(const tstring& sQuery, VEC_RECORDS& vecRecords)
	{
		RetrieveRecords(sQuery, vecRecords);
	}

	//----------------------------------------------------------------------
	bool get_OneRecord(bool bFirstRec, VEC_RECORDS& vecRecords, VEC_ONERECORD& vecRecord)
	{
		try
		{
			static VEC_RECORDS_ITERATOR it;

			//	Clear the vector always
			vecRecord.erase(vecRecord.begin(), vecRecord.end());

			//	get the iterator 
			if (bFirstRec)
				it = vecRecords.begin();
			else	
				it++;

			VEC_RECORDS_ITERATOR itEnd = vecRecords.end();
			
			LPTSTR lpszDelimiter = _T("\t");
			if (it != itEnd)
			{
				stringx sRecord = (*it).c_str();
				LPTSTR lpszBuffer = sRecord.get_buffer(sRecord.length());
				LPTSTR lpszToken = _tcstok(lpszBuffer, lpszDelimiter);
				char* pCharPos;

				//	parse the fields and push the strings in the vector
				while( lpszToken != NULL )
				{
					pCharPos = strstr(lpszToken, _T("NULL"));
					if (pCharPos != NULL)
						lpszToken = _T("");

					vecRecord.push_back(lpszToken);		
					lpszToken = _tcstok( NULL, lpszDelimiter );
				}

			}

			return (it == itEnd) ? false : true;
		}
		catch(...)
		{
		}

		return false;
	}

	//----------------------------------------------------------------------
	bool IsRecordsFound(const tstring& sQuery)
	{
		CComPtr<_Recordset> spRecordset;
		return ExecuteQuery(sQuery, spRecordset);
	}
	//----------------------------------------------------------------------

protected:

	//----------------------------------------------------------------------
	void RetrieveRecords(const tstring& sQuery, VEC_RECORDS& vecRecords)
	{
		try
		{
			CComPtr<_Recordset> spRecordset;
			bool bRecordsFound = ExecuteQuery(sQuery, spRecordset);
			
			if (bRecordsFound)
			{
				// Set the separators for columns and rows
				CComBSTR bstrTab;
				CComBSTR bstrRet;
				CComBSTR bstrNull(_T("NULL"));			
				CComBSTR bstrValue;			

				// Get the rows and columns in a single string
				HRESULT hr = spRecordset->GetString(adClipString, -1, bstrTab, bstrRet, bstrNull, &bstrValue);			
				CHECK_HRX(hr);

				USES_CONVERSION;

				// Verify that no illegal character present
				// Since lpa was allocated based on the size of lpw
				// Don't worry about the number of chars

				int nLen = bstrValue.Length();

				LPTSTR lpBuf = (LPTSTR)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, nLen + 1 );
				if (lpBuf)
				{
					lpBuf[0] = '\0';
					WideCharToMultiByte(CP_ACP, 0, bstrValue, -1, lpBuf, nLen, NULL, NULL);
				}

				const TCHAR* lpszDelimiter = _T("\r");
				LPTSTR lpszToken = _tcstok(lpBuf, lpszDelimiter);

				//parse and push the string in the vector
				while( lpszToken != NULL )
				{
					vecRecords.push_back(lpszToken);			
					lpszToken = _tcstok( NULL, lpszDelimiter );
				}

				HeapFree( GetProcessHeap(), 0, lpBuf);
			}

			if(spRecordset)
				spRecordset->Close();
		}
		catch(...)
		{
		}
	}

	//----------------------------------------------------------------------
	bool ExecuteQuery(const tstring& sQuery, CComPtr<_Recordset> &spRecordset)
	{
		bool bRecordsFound = false;
		try
		{		
			CComPtr<_Command> spCommand;
			HRESULT hr = spCommand.CoCreateInstance(__uuidof(Command));
			CHECK_HRX(hr);

			hr = spCommand->put_ActiveConnection(CComVariant(m_spConnection));
			CHECK_HRX(hr);

			hr = spCommand->put_CommandText(CComBSTR(sQuery.c_str()));
			CHECK_HRX(hr);

			hr = spCommand->put_CommandType(adCmdText);
			CHECK_HRX(hr);

			CComVariant vtRecordAffected;
			hr = spCommand->Execute(&vtRecordAffected, NULL, NULL, &spRecordset);
			CHECK_HRX(hr);

			CComBool cbEndOfFile;
			hr = spRecordset->get_EndOfFile(&cbEndOfFile);
			CHECK_HRX(hr);

			CComBool cbBeginOfFile;
			hr = spRecordset->get_BOF(&cbBeginOfFile);
			CHECK_HRX(hr);
			
			if (!cbEndOfFile && !cbBeginOfFile)
				bRecordsFound = true;
		}
		catch(...)
		{
		}

		return bRecordsFound;
	}
	//----------------------------------------------------------------------

private:
	CComPtr<_Connection> m_spConnection;
};

#endif // _DATABASE_ACCESS_H_