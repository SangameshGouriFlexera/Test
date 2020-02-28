#ifndef _QUERY_MIXIN_H
#define _QUERY_MIXIN_H
/////////////////////////////////////////////////////////////////////////////
// QueryMixin.h
//		Implements a simple class wrapper around a MSI view. 
// 

#include <stdio.h>
#include <msi.h>
#include <msiquery.h>
#include "ismsi.h"

const int MAX_SQL_LENGTH = 2048;
const int MSIQUERYERROR_SQL_TOO_LONG = -4;

// user-defined namespace for MSI API
#ifndef MSI
#define MSI
#endif

// IPWI/Express expects these functions to throw by default.
// WACK expects them to not throw.
// The MSI API functions that are wrapped by ismsi throw exceptions.
// The MSI namespace is for raw, unwrappeds call to the MSI API, which does not throw.

#ifdef __ISWACK
#define ISMSI MSI
#else
#define ISMSI ismsi
#endif

///////////////////////////////////////////////////////////
class CQueryMixin
{
public:
	
	// constructor
	CQueryMixin()
	{
		// invalidate the handles
		m_hView = NULL;
	    
	}	// end of constructor

	///////////////////////////////////////////////////////////
	// destructor
	~CQueryMixin()
	{
		// if the view wasn't closed
		if (m_hView)
			MSI::MsiCloseHandle(m_hView);

	}	// end of destructor
	
	///////////////////////////////////////////////////////////
	// Open
	// Pre:	database handle is valid
	// Pos:	m_hView is open on databse
	UINT Open(MSIHANDLE hDatabase, LPCTSTR szSQLFormat)
	{
		if (m_hView)
			MSI::MsiCloseHandle(m_hView);

		// open the view
		UINT iResult = MSI::MsiDatabaseOpenView(hDatabase, szSQLFormat, &m_hView);

		return iResult;
	}	// end of Open

	///////////////////////////////////////////////////////////
	// Close
	// Pre:	none
	// Pos:	view handle is closed
	//			SQL string is blanked
	UINT Close()
	{
		UINT iResult = ERROR_SUCCESS;		// assume everything will be okay

		// close the handle and null the handle
		iResult = MSI::MsiViewClose(m_hView);
		
		return iResult;
	}	// end of Close

	///////////////////////////////////////////////////////////
	// Execute
	// Pre:	view handle is open
	// Pos:	view is executed
	//			result is returned
	UINT ExecuteThrow(MSIHANDLE hParams /*= NULL*/)
	{
		// execute the view and return the result
		return ismsi::MsiViewExecute(m_hView, hParams);
	}	// end of Execute

	///////////////////////////////////////////////////////////
	// Execute
	// Pre:	view handle is open
	// Pos:	view is executed
	//			result is returned
	UINT Execute(MSIHANDLE hParams /*= NULL*/)
	{
		// execute the view and return the result
		return ISMSI::MsiViewExecute(m_hView, hParams);
	}	// end of Execute

	///////////////////////////////////////////////////////////
	// OpenExecuteThrow
	// Pre:	database handle is valid
	// Pos:	m_hView is open and executed on databse
	UINT OpenExecuteThrow(MSIHANDLE hDatabase, LPCTSTR szSQLFormat)
	{
		// open the view
		if (m_hView)
			MSI::MsiCloseHandle(m_hView);

		UINT iResult;
		if (ERROR_SUCCESS != (iResult = ismsi::MsiDatabaseOpenView(hDatabase, szSQLFormat, &m_hView)))		
			return iResult;

		PMSIHANDLE hParam;

		// An exception will be thrown if there's a problem, so return value
		// does not need to be checked.
		return ismsi::MsiViewExecute(m_hView, hParam); 
	}	// end of OpenExecuteThrow

	///////////////////////////////////////////////////////////
	// OpenExecute
	// Pre:	database handle is valid
	// Pos:	m_hView is open and executed on databse
	UINT OpenExecute(MSIHANDLE hDatabase, LPCTSTR szSQLFormat)
	{
		// open the view
		if (m_hView)
			MSI::MsiCloseHandle(m_hView);

		UINT iResult;
		if (ERROR_SUCCESS != (iResult = ISMSI::MsiDatabaseOpenView(hDatabase, szSQLFormat, &m_hView)))		
			return iResult;

		PMSIHANDLE hParam;

		// An exception will be thrown if there's a problem, so return value
		// does not need to be checked.
		return ISMSI::MsiViewExecute(m_hView, hParam); 
	}	// end of OpenExecute
	
	///////////////////////////////////////////////////////////
	// OpenExecuteVA
	// Pre:	database handle is valid
	// Pos:	m_hView is open and executed on databse
    //
    // WARNING: Only call this function if you are sure that szSQLFormat
    //          is a valid printf format specification.  If szSQLFormat contiains
    //          any '%' characters not used for formatting, this function will fail.
    //
	UINT OpenExecuteVA(MSIHANDLE hDatabase, LPCTSTR szSQLFormat, ...)
	{
		// store the result SQL string
		va_list listSQL; 
		va_start(listSQL, szSQLFormat); 

		TCHAR szSQL[MAX_SQL_LENGTH];
		_vstprintf(szSQL, szSQLFormat, listSQL); 

		ATLASSERT(_tcslen(szSQL) < MAX_SQL_LENGTH); // If you get this assert increase MAX_SQL_LENGTH

		// open the view
		if (m_hView)
			MSI::MsiCloseHandle(m_hView);

		UINT iResult;
		if (ERROR_SUCCESS != (iResult = ISMSI::MsiDatabaseOpenView(hDatabase, szSQL, &m_hView)))		
			return iResult;

		PMSIHANDLE hParam;

		// An exception will be thrown if there's a problem, so return value
		// does not need to be checked.
		return ISMSI::MsiViewExecute(m_hView, hParam); 
	}	// end of OpenExecuteVA

	//OpenExecuteNoThrow
	// Pre:	database handle is valid
	// Pos:	m_hView is open and executed on databse
	UINT OpenExecuteNoThrow(MSIHANDLE hDatabase, LPCTSTR szSQLFormat)
	{		
		// open the view
		if (m_hView)
			MSI::MsiCloseHandle(m_hView);
		
		UINT iResult;
		if (ERROR_SUCCESS != (iResult = MSI::MsiDatabaseOpenView(hDatabase, szSQLFormat, &m_hView)))
			return iResult;
		
		PMSIHANDLE hParam;
		
		return MSI::MsiViewExecute(m_hView, hParam); 
	}	// end of OpenExecute
	///////////////////////////////////////////////////////////
	// Fetch
	// Pre:	view handle is open
	//			view is executed
	// Pos:	record is returned
	//			result is returned
	UINT FetchThrow(MSIHANDLE* phRecord)
	{
		// fetch from the view and return the result
		return ismsi::MsiViewFetch(m_hView, phRecord);
	}	// end of Fetch

	///////////////////////////////////////////////////////////
	// Fetch
	// Pre:	view handle is open
	//			view is executed
	// Pos:	record is returned
	//			result is returned
	UINT Fetch(MSIHANDLE* phRecord)
	{
		// fetch from the view and return the result
		return ISMSI::MsiViewFetch(m_hView, phRecord);
	}	// end of Fetch
	
	///////////////////////////////////////////////////////////
	// FetchOnce
	// Pre:	database handle is valid
	// Pos:	m_hView is open, executed, and one record is fetched
	UINT FetchOnce(MSIHANDLE hDatabase, MSIHANDLE* phRecord, LPCTSTR szSQLFormat)
	{
		if (m_hView != NULL)
			MSI::MsiCloseHandle(m_hView);

		// open the view
		UINT iResult;
		if (ERROR_SUCCESS != (iResult = ismsi::MsiDatabaseOpenView(hDatabase, szSQLFormat, &m_hView)))
			return iResult;
		if (ERROR_SUCCESS != (iResult = ismsi::MsiViewExecute(m_hView, NULL)))
			return iResult;

		return ISMSI::MsiViewFetch(m_hView, phRecord);
	}	// end of FetchOnce

	///////////////////////////////////////////////////////////
	// FetchOnce SingleMarker
	// Pre:	database handle is valid
	// Pos:	m_hView is open, executed, and one record is fetched
	// This is to be used with SQL queries that contian a single marker (?)
	// The value that the marker is to be replaced with is szMarker
	UINT FetchOnceSingleMarker(MSIHANDLE hDatabase, MSIHANDLE* phRecord, LPCTSTR szSQLFormat, LPCTSTR szMarker)
	{
		if (m_hView != NULL)
			MSI::MsiCloseHandle(m_hView);

		// open the view
		UINT iResult;
		if (ERROR_SUCCESS != (iResult = ismsi::MsiDatabaseOpenView(hDatabase, szSQLFormat, &m_hView)))
			return iResult;
		
		PMSIHANDLE hNewRec = ismsi::MsiCreateRecord(1);
		if (ERROR_SUCCESS != ismsi::MsiRecordSetString(hNewRec, 1, szMarker))
			return iResult;

		if (ERROR_SUCCESS != (iResult = ismsi::MsiViewExecute(m_hView, hNewRec)))
			return iResult;

		return ISMSI::MsiViewFetch(m_hView, phRecord);
	}	// end of FetchOnce
	
	///////////////////////////////////////////////////////////
	// FetchOnceVA
	// Pre:	database handle is valid
	// Pos:	m_hView is open, executed, and one record is fetched
    //
    // WARNING: Only call this function if you are sure that szSQLFormat
    //          is a valid printf format specification.  If szSQLFormat contiains
    //          any '%' characters not used for formatting, this function will fail.
    //
	UINT FetchOnceVA(MSIHANDLE hDatabase, MSIHANDLE* phRecord, LPCTSTR szSQLFormat, ...)
	{
		// store the result SQL string
		va_list listSQL; 
		va_start(listSQL, szSQLFormat); 
		
		TCHAR szSQL[MAX_SQL_LENGTH];
		_vstprintf(szSQL, szSQLFormat, listSQL);
			
		ATLASSERT(_tcslen(szSQL) < MAX_SQL_LENGTH); // If you get this assert increase MAX_SQL_LENGTH
		
		if (m_hView != NULL)
			MSI::MsiCloseHandle(m_hView);

		// open the view
		UINT iResult;
		if (ERROR_SUCCESS != (iResult = ismsi::MsiDatabaseOpenView(hDatabase, szSQL, &m_hView)))
			return iResult;
		if (ERROR_SUCCESS != (iResult = ismsi::MsiViewExecute(m_hView, NULL)))
			return iResult;

		return ISMSI::MsiViewFetch(m_hView, phRecord);
	}	// end of FetchOnceVA

	///////////////////////////////////////////////////////////
	// FetchOnceVA
	// Pre:	database handle is valid
	// Pos:	m_hView is open, executed, and one record is fetched
    //
    // WARNING: Only call this function if you are sure that szSQLFormat
    //          is a valid printf format specification.  If szSQLFormat contiains
    //          any '%' characters not used for formatting, this function will fail.
    //
	UINT FetchOnceVANoThrow(MSIHANDLE hDatabase, MSIHANDLE* phRecord, LPCTSTR szSQLFormat, ...)
	{
		// store the result SQL string
		va_list listSQL; 
		va_start(listSQL, szSQLFormat); 
		
		TCHAR szSQL[MAX_SQL_LENGTH];
		_vstprintf(szSQL, szSQLFormat, listSQL);
			
		ATLASSERT(_tcslen(szSQL) < MAX_SQL_LENGTH); // If you get this assert increase MAX_SQL_LENGTH
		
		if (m_hView != NULL)
			MSI::MsiCloseHandle(m_hView);

		// open the view
		UINT iResult;
		if (ERROR_SUCCESS != (iResult = MSI::MsiDatabaseOpenView(hDatabase, szSQL, &m_hView)))
			return iResult;
		if (ERROR_SUCCESS != (iResult = MSI::MsiViewExecute(m_hView, NULL)))
			return iResult;

		return MSI::MsiViewFetch(m_hView, phRecord);
	}	// end of FetchOnceVANoThrow


	///////////////////////////////////////////////////////////
	// ModifyThrow
	// Pre:	view handle is open
	//			view is executed
	// Pos:	modification is done
	//			result is returned
	UINT ModifyThrow(MSIMODIFY eInfo, MSIHANDLE hRec)
	{
		// execute the view and return the result
		return ismsi::MsiViewModify(m_hView, eInfo, hRec);
	}	// end of GetColumnInfo

	///////////////////////////////////////////////////////////
	// Modify
	// Pre:	view handle is open
	//			view is executed
	// Pos:	modification is done
	//			result is returned
	UINT Modify(MSIMODIFY eInfo, MSIHANDLE hRec)
	{
		// execute the view and return the result
		return ISMSI::MsiViewModify(m_hView, eInfo, hRec);
	}

	///////////////////////////////////////////////////////////
	// ModifyNoThrow
	// Pre:	view handle is open
	//			view is executed
	// Pos:	modification is done
	//			result is returned
	UINT ModifyNoThrow(MSIMODIFY eInfo, MSIHANDLE hRec)
	{
		// execute the view and return the result
		return MSI::MsiViewModify(m_hView, eInfo, hRec);
	}

	///////////////////////////////////////////////////////////
	// GetError
	// Pre:	view handle is open
	//			view is executed

	UINT CQueryMixin::GetError(LPTSTR szDummyBuf, unsigned long* cchDummyBuf)
	{
		// execute the view and return the result
		return MSI::MsiViewGetError(m_hView, szDummyBuf, cchDummyBuf);
	}	// end of GetColumnInfo

	///////////////////////////////////////////////////////////
	// GetColumnInfo
	// Pre:	view handle is open
	//			view is executed
	// Pos:	record is returned
	//			result is returned
	UINT GetColumnInfo(MSICOLINFO eInfo, MSIHANDLE* phRec)
	{
		// execute the view and return the result
		return ISMSI::MsiViewGetColumnInfo(m_hView, eInfo, phRec);
	}	// end of GetColumnInfo

	///////////////////////////////////////////////////////////
	// GetColumnInfo
	// Pre:	view handle is open
	//			view is executed
	// Pos:	record is returned
	//			result is returned
	UINT GetColumnInfoThrow(MSICOLINFO eInfo, MSIHANDLE* phRec)
	{
		// execute the view and return the result
		return ismsi::MsiViewGetColumnInfo(m_hView, eInfo, phRec);
	}	// end of GetColumnInfo

	///////////////////////////////////////////////////////////
	// AttachView
	void AttachView(MSIHANDLE hView)
	{
		ATLASSERT(m_hView == NULL);
		m_hView = hView;
	}

	///////////////////////////////////////////////////////////
	// DetachView
	MSIHANDLE DetachView()
	{
		MSIHANDLE hView = m_hView;
		m_hView = NULL;
		return hView;
	}

	bool TableExists(LPCTSTR szTable, MSIHANDLE hDatabase)
	{
		// check the table state
		UINT iResult = MSI::MsiDatabaseIsTablePersistent(hDatabase, szTable);

		// if the table exists (persistent or not, who cares)
		if (MSICONDITION_TRUE == iResult || MSICONDITION_FALSE == iResult)
			return true;

		return false;	// table does not exist
	}	// end of TableExists


protected:
	MSIHANDLE m_hView;
	
};

#endif //_QUERY_MIXIN_H