#ifndef _MSI_HELPER_H
#define _MSI_HELPER_H

#include "is.h"
#include "msi.h"
#include "pathx.h"
#include <locale>
	
_IS_BEGIN
//------------------------------------------------------------------------------
//
//	Description: GetRecordCollection
//
//	Parameters: 
//		 IMsiDatabase *pMsiDatabase
//		 BSTR bstrTableName
//		 BSTR bstrRecordQuery
//		 IRecordSet **pRecordSet
//
//	Returns: 
//		 HRESULT
//------------------------------------------------------------------------------
static HRESULT GetRecordCollection(IMsiDatabase *pMsiDatabase, BSTR bstrTableName, BSTR bstrRecordQuery, 
	IRecordSet **pRecordSet)
{
	CHECK_POINTER(pMsiDatabase);
	CHECK_OUT_POINTER(pRecordSet);
	_ASSERTE(VALID_BSTR(bstrTableName));
	_ASSERTE(VALID_BSTR(bstrRecordQuery));

	//Create the Tables Collection
	CComPtr<ITableSet> spTableSet;
	hrx hr = pMsiDatabase->get_Tables(&spTableSet);
	ATLASSERT(spTableSet);

	//Get the ITable Object
	USES_CONVERSION;
	LPCTSTR lpszTableName = OLE2T(bstrTableName);
	TCHAR szQuery[_MAX_PATH] = {0};
	wsprintf(szQuery, _T("Name = \'%s\'"), lpszTableName);

	CComBSTR bstrTableQuery(szQuery);

	CComPtr<ITable> spTable;
	spTableSet->get_Item(bstrTableQuery, &spTable);
	if(spTable != NULL)
	{
		//Get the collection of Records
		hr = spTable->get_Records(CComVariant(bstrRecordQuery), pRecordSet);
	}
	return S_OK;
}

//------------------------------------------------------------------------------
//
//	Description: GetFieldValue
//
//	Parameters: 
//		 IRecord *pRecord
//		 CComVariant varField
//		 CComVariant *varFieldValue
//
//	Returns: 
//		 HRESULT
//------------------------------------------------------------------------------
static HRESULT GetFieldValue(IRecord *pRecord, CComVariant varField, CComVariant *varFieldValue)
{
	CHECK_POINTER(pRecord);
	CHECK_POINTER(varFieldValue);

	//Get the Field Collection
	CComPtr<IFieldSet> spFieldSet;
	hrx hr = pRecord->get_Fields(&spFieldSet);
	ATLASSERT(spFieldSet);

	CComPtr<IField> spField;
	hr = spFieldSet->get_Item(varField, &spField);
	ATLASSERT(spField);

	CComVariant varValue;
	hr = spField->get_Value(&varValue);
	*varFieldValue = varValue;

	return S_OK;
}

//------------------------------------------------------------------------------
//
//	Description: GetRecordSet
//
//	Parameters: 
//		 IMsiDatabase *pMsiDatabase
//		 CComBSTR bstrTable
//		 CComBSTR bstrQuery
//		 IRecordSet *pRecordSet
//
//	Returns: 
//		 HRESULT
//------------------------------------------------------------------------------
static HRESULT GetRecordSet(IMsiDatabase *pDatabase, BSTR bstrTableName, BSTR bstrQuery, IRecordSet **pRecordSet)
{
	CHECK_POINTER(pDatabase);
	_ASSERT(VALID_BSTR(bstrTableName));
	_ASSERT(VALID_BSTR(bstrQuery));
	CHECK_OUT_POINTER(pRecordSet);

	VARIANT_BOOL vbIsDbOpen;
	pDatabase->get_IsOpen(&vbIsDbOpen);

	if(vbIsDbOpen == VARIANT_TRUE)
	{
		return is::GetRecordCollection(pDatabase, bstrTableName, bstrQuery, pRecordSet);
	}
	return S_OK;
}

//------------------------------------------------------------------------------
//
//	Description: GetRecordSet
//
//	Parameters: 
//		 IMsiDatabase *pMsiDatabase
//		 CComBSTR bstrTableName
//		 std::vector<CComBSTR>& vecDataNames
//
//	Returns: 
//		 HRESULT
//------------------------------------------------------------------------------
static HRESULT GetTransformDataNames(IMsiDatabase *pDatabase, BSTR bstrTableName, std::vector<CComBSTR>& vecDataNames)
{
	CHECK_POINTER(pDatabase);
	_ASSERT(VALID_BSTR(bstrTableName));

	//Get RecordSet prepares a collection of all the entries in the _TransformView table.
	CComBSTR bstrQuery("SELECT * FROM _TransformView WHERE Column = \'INSERT\'");
	CComBSTR bstrTranformTableName("_TransformView");

	CComPtr<IRecordSet> spRecordSet;
	HRESULT hr = is::GetRecordSet(pDatabase, bstrTranformTableName, bstrQuery, &spRecordSet);

	if (spRecordSet && SUCCEEDED(hr))
	{
		CComVariant varResult;
		unsigned int uArgErr;
		DISPPARAMS disparams = {0};

		CHECK_HRX(spRecordSet->Invoke(DISPID_NEWENUM, IID_NULL, 0, DISPATCH_PROPERTYGET, &disparams, &varResult, NULL, &uArgErr));
		CComQIPtr<IEnumVARIANT> pEnum = varResult.punkVal;
		ATLASSERT(pEnum);

		CComVariant var[1];
		ULONG celtFetched;

		while(pEnum->Next(sizeof(var)/sizeof(var[0]), var, &celtFetched), celtFetched)
		{
			for(ULONG i = 0; i < celtFetched; ++i)
			{
				// let's make sure it's VT_UNKNOWN
				CHECK_HRX(VariantChangeType(&var[i], &var[i], 0, VT_UNKNOWN));

				CComQIPtr<IRecord> spRecord = var[i].punkVal;

				//With the Index 0 I am getting the TableName, so that I get the rest of the information
				//from the record only if TableName matches Component.
				CComVariant varTableName;
				HRESULT hr = is::GetFieldValue(spRecord, CComVariant(0), &varTableName);

				if(CComBSTR(varTableName.bstrVal) == bstrTableName)
				{
					//Now get the Component Name, we are getting the component name from the _TransformView Table
					//In TransformView table data lies at column 3
					CComVariant varDataName;
					HRESULT hr = is::GetFieldValue(spRecord, CComVariant(3), &varDataName);
					if (SUCCEEDED(hr))
					{
						vecDataNames.push_back(varDataName.bstrVal);
					}
				}
				// clear the variant
				var[i].Clear();
			}
		}
	}
	return S_OK;
}

//------------------------------------------------------------------------------
//	Convert to uppercase
static void WINAPI ToUpper(stringxi& sSource)
{
	stringxi::iterator it = sSource.begin();
	std::ctype<TCHAR> charType;

	while (it != sSource.end())
	{
		*it = charType.toupper(*it);
		it++;
	}
}

//------------------------------------------------------------------------------
static void GetShortName(const stringxi& sName, stringxi& sShortName)
{
	const stringxi sVALIDCHAR = _T("$%`-_@{}~`!#()");

	long nLen = sName.length();
	if (nLen <= 8)
	{
		sShortName = sName;
		return;
	}

	long nCurPos = 0;
	long nSourceLen = 0;

	stringxi sShortFolderName = "";
	stringxi sCurrentChar;

	while (nCurPos <= nLen && nSourceLen < 6)
	{
		sCurrentChar = sName.substr(nCurPos, 1);
		if (sCurrentChar == _T(" "))
		{
			++nCurPos;
			continue;
		}

		//   Convert to upper case
		ToUpper(sCurrentChar);

		//   Replace all invalid characters to '_'
		std::ctype<TCHAR> charType;
		if (! charType.is(std::ctype<TCHAR>::alnum, (*sCurrentChar.begin())))
			if (sVALIDCHAR.find(sCurrentChar) == stringxi::npos)
				sCurrentChar = _T("_");
    
		//   Collect the characters
		sShortFolderName += sCurrentChar;
		++nSourceLen;
		++nCurPos;
	}

	//   add the ~1
	sShortName = sShortFolderName;
	sShortName += L"~1";
	return;
}

//------------------------------------------------------------------------------
static void GetShortFileName(const stringxi& sName, stringxi& sShortFileName)
{
	//	Get the short file name
	pathx pthFileName = sName;
	stringxi strFileName = pthFileName.filename();

	if (strFileName.length() <= 8)
		sShortFileName = sName;
	else
	{
		GetShortName(strFileName, sShortFileName);
		stringxi strExtension = pthFileName.ext();

		if (strExtension.length())
			sShortFileName += pthFileName.ext();
	}

}



//------------------------------------------------------------------------------
//
//	Description: GetMsiStyleFileName
//
//	Parameters: 
//		 BSTR bstrFileName
//		 BSTR *pbstrFileName
//
//	Returns: 
//		 HRESULT
//------------------------------------------------------------------------------
static HRESULT GetMsiStyleFileName(BSTR bstrFileName, BSTR *pbstrFileName)
{
	try
	{
		is::pathx pthFilePath(bstrFileName);

		//Get the filename from the path
		stringxi strFileName = pthFilePath.file();

		//Get the filename from the path
		stringxi strDir = pthFilePath.dir();

		//If the directory is empty this means we cannot validate the file short name, so just use what we have
		stringxi strShortFileName;
		if (!strDir.empty())
		{
			//Get the Short File Path
			is::pathx pthShortFilePath = pthFilePath.short_path();

			//Get the short file name
			strShortFileName = pthShortFilePath.file();
		}
		else
		{
			GetShortFileName(strFileName, strShortFileName);
		}

		//If ShortFileName is not same as Initial FileName 
		//convatenate them by putting a |
		if (strShortFileName != strFileName)
		{
			stringxi strTempFileName = strFileName;
			strFileName = strShortFileName;
			strFileName += L"|";
			strFileName += strTempFileName;
		}
		*pbstrFileName = strFileName.copy();
	}
	catch(is::win32_exception& error)
	{
		return error.hresult();
	}
	//catch(...)
	//{
	//	return E_UNEXPECTED;
	//}
	return S_OK;
}


//------------------------------------------------------------------------------
static void GetLongName(BSTR bstrName, BSTR* pbstrLongName)
{
	_ASSERTE(VALID_BSTR(bstrName));

	stringxi strName(bstrName);
	int pos = strName.find(L"|");
	
	if(pos == stringxi::npos)
		*pbstrLongName = strName.copy();
	else
		*pbstrLongName = (strName.substr(pos+1)).copy();
}

static HRESULT PutRecordData(int nIndex, IRecord *pRecord, VARIANT vVal)
{
	ATLASSERT(pRecord);
	ATLASSERT(nIndex > 0);

	CComPtr<IFieldSet> spFields;
	CHECK_HRX(pRecord->get_Fields(&spFields));
	ATLASSERT(spFields);

	CComPtr<IField> spField;
	CHECK_HRX(spFields->get_Item(CComVariant(nIndex), &spField));

	if(spField)
	{
		CHECK_HRX(spField->put_Value(vVal));
	}
	return S_OK;
}

static HRESULT GetRecordData(int nFieldIndex, IRecord *pRecord, VARIANT *pVal)
{
	ATLASSERT(pRecord);
	ATLASSERT(nFieldIndex > 0);
	CHECK_POINTER(pVal);

	CComPtr<IFieldSet> spFields;
	CHECK_HRX(pRecord->get_Fields(&spFields));
	ATLASSERT(spFields);

	CComPtr<IField> spField;
	CHECK_HRX(spFields->get_Item(CComVariant(nFieldIndex), &spField));
	ATLASSERT(spField);

	CHECK_HRX(spField->get_Value(pVal));
	return S_OK;
}

static HRESULT GetTable(LPCTSTR strTableName, IMsiDatabase *pDatabase, ITable **pTable)
{
	CHECK_OUT_POINTER(pTable);
	ATLASSERT(pDatabase);

	CComPtr<ITableSet> spTables;
	CHECK_HRX(pDatabase->get_Tables(&spTables));

	TCHAR szQuery[1024] = {0};
	wsprintf(szQuery, _T("Name = \'%s\'"), strTableName);
	CComBSTR bstrQuery = szQuery;

	CComPtr<ITable> spTable;
	CHECK_HRX(spTables->get_Item(bstrQuery, &spTable));

	*pTable = spTable.Detach();
	return S_OK;
}

// --------------------------------------------------------------------------
#ifdef __ISWACK
static void GetPropertyValue(IMsiDatabase* pDatabase, LPCTSTR lpszPropertyName, 
	LPTSTR lpszValue, DWORD dwSize)
{
	ATLASSERT(pDatabase != NULL);
	ATLASSERT(lpszPropertyName != NULL);
	ATLASSERT(lpszValue != NULL);

	TCHAR szFormat[1024] = {0};
	wsprintf(szFormat, _T("`Property`='%s'"), lpszPropertyName);
	
	CComPtr<IPropertySet> spPropertySet;
	HRESULT hr = pDatabase->get_Properties(&spPropertySet);
	CHECK_HRX(hr);

	CComPtr<IProperty> spProperty;
	hr = spPropertySet->get_Item(CComBSTR(szFormat), &spProperty);
	CHECK_HRX(hr);

	if (spProperty)
	{
		USES_CONVERSION;

		CComBSTR bstrValue;
		hr = spProperty->get_Value(&bstrValue);
		CHECK_HRX(hr);

		//	Sanity check to avoid buffer overruns.
		if (bstrValue.Length() < dwSize)
			_tcscpy(lpszValue, OLE2T(bstrValue));
	}
}
#endif // __ISWACK

//------------------------------------------------------------------------------
_IS_END

#endif //_MSI_HELPER_H
