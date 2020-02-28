
#ifndef __IRECENTFILESBASE_H_
#define __IRECENTFILESBASE_H_

#include <vector>
typedef std::vector< CAdapt<CComBSTR> > COMBSTRVECTOR;

/////////////////////////////////////////////////////////////////////////////
// CRecentFilesBase
class CRecentFilesBase :
	public is::CErrorHandler<&GUID_NULL>
{
public:
	CRecentFilesBase(COMBSTRVECTOR& vecRecentFiles) : 
		m_vecRecentFiles(vecRecentFiles), m_bInitFileList(false){}
		virtual ~CRecentFilesBase() {};

	void Init(LPCTSTR bstrRecentFileLocation, bool bEncryptMRUList);

public:
	STDMETHOD(Add)(/*[in]*/ BSTR bstrFileName, /*[out, retval]*/ BSTR *pbstrFileName);
	STDMETHOD(Remove)(/*[in]*/ VARIANT vItem);

protected:
	HRESULT IndexInRange(long nItem);
	HRESULT GetRecentFilesList();
	HRESULT SaveRecentFiles();
	HRESULT RemoveIfFileExist(CComBSTR bstrFileName);
	HRESULT RemoveEmptyValues();
	HRESULT Clear();
	void EncryptString(CComBSTR& bstrName, bool bEncrypt);

private:

	typedef COMBSTRVECTOR::iterator VECITERATOR;
	bool m_bInitFileList;
	CComBSTR m_bstrRecentFileKey;
	COMBSTRVECTOR& m_vecRecentFiles;
	bool m_bEncryptMRUList;
};

#endif //__IRECENTFILESBASE_H_
