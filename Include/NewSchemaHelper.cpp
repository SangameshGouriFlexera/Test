#include "stdafx.h"
#include "NewSchemaHelper.h"

static const TCHAR* const szGetPkgIDQuery	=		_T("SELECT RowID FROM cstblPackage WHERE PackageCode = '%s' ");
static const TCHAR* const szGetPkgCodeQuery	=		_T("SELECT PackageCode FROM cstblPackage WHERE RowID = %ld ");

HRESULT PkgRowIDFromGUID(const CComPtr<_Connection> &spDBConnUnknown, const CString& strPackageCode, long * plPkgRowID)
{
	HRESULT hr;

	CComPtr<_Recordset> spRecordset;
	CString strQuery;
	strQuery.Format(szGetPkgIDQuery, strPackageCode);

	hr = spDBConnUnknown->Execute(_bstr_t(strQuery), NULL, 1, &spRecordset);

	CComBool bEOF;
	hr = spRecordset->get_EndOfFile(&bEOF);

	if(!bEOF)
	{
		CComPtr <Fields> spFields;
		CComPtr <Field> spGroupCodeField;
		VARIANT vaGroupCode;
		CComVariant vaFieldIndex = 0;
		
		hr = spRecordset->get_Fields(&spFields);
		hr = spFields->get_Item(vaFieldIndex, &spGroupCodeField);
		hr = spGroupCodeField->get_Value(&vaGroupCode);

		*plPkgRowID = V_I4(&vaGroupCode);
	}
	else
	{
		return E_FAIL;
	}
		
	hr = spRecordset->Close();

	return hr;
}
