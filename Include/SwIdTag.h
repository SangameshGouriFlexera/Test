#pragma once
#include "MSXMLWrapper.h"
#include "stringx.h"

class CSwIdTag
{
public:
	CSwIdTag();
	CSwIdTag(const stringxi& sSwIdTagFile);
	virtual ~CSwIdTag();
	
	void Save();
	void SaveToFolder(const stringxi& sFolder);
	stringxi SaveToFolderWithDefaultName(const stringxi& sFolder);
	stringxi SaveWithDefaultName();
	bool IsModified();

	stringx GetProductName() {return m_sProductName; };
	stringx GetProductVersion() {return m_sProductVersion; };
	stringx GetProductCode() {return m_sOrigArpGuid; };
	stringx GetSwCreatorName() {return m_sSwCreatorName; };
	stringx GetSwCreatorRegId() {return m_sSwCreatorRegId; };
	stringx GetSwLicensorName() {return m_sSwLicensorName; };
	stringx GetSwLicensorRegId() {return m_sSwLicensorRegId; };
	stringx GetSwId() {return m_sSwUniqueId; };
	stringx GetSwPublisher() {return m_sOrigArpPublisher; };
	stringx GetTagCreator() {return m_sTagCreatorName; };
	stringx GetTagCreatorRegId() {return m_sTagCreatorRegId; };

	bool GetGenerateTag() {return m_bGenerateTag; };
	bool GetRequireSwEntitlement() { return (m_sEntitlementRequired == L"1"); };
	
	long GetAppCatalogPkgId() {return m_nAppCatalogPkgId; };
	stringx GetAppCatalogServerName() {return m_sAppCatalogServerName; };
	stringx GetAppCatalogDbName() {return m_sAppCatalogDbName; };
	stringx GetAppCatalogDbGuid() {return m_sAppCatalogDbGuid; };
	
	stringx GetOrigArpGuid() {return m_sOrigArpGuid; };
	stringx GetOrigArpPublisher() {return m_sOrigArpPublisher; };
	stringx GetOrigArpDispName() {return m_sOrigArpDisplayName; };
	stringx GetOrigArpDispVersion() {return m_sOrigArpDisplayVersion; };

	stringx GetCurArpGuid() {return m_sCurArpGuid; };
	stringx GetCurArpPublisher() {return m_sCurArpPublisher; };
	stringx GetCurArpDispName() {return m_sCurArpDisplayName; };
	stringx GetCurArpDispVersion() {return m_sCurArpDisplayVersion; };

	void PutProductName(const stringx& sIn) 
	{
		m_sProductName = sIn; 
		m_sProductName.replace_all(L"®", L"");
		m_sProductName.replace_all(L"™", L"");
	};
	void PutProductVersion(const stringx& sIn) {m_sProductVersion = sIn; };
	void PutOrigArpGuid(const stringx& sIn) {if(m_sOrigArpGuid.empty()) m_sOrigArpGuid = sIn; };
	void PutCurArpGuid(const stringx& sIn) {m_sCurArpGuid = sIn; };
	void PutSwCreatorName(const stringx& sIn) {m_sSwCreatorName = sIn; };
	void PutSwCreatorRegId(const stringx& sIn) {m_sSwCreatorRegId = sIn; };
	void PutSwLicensorName(const stringx& sIn) {m_sSwLicensorName = sIn; };
	void PutSwLicensorRegId(const stringx& sIn) {m_sSwLicensorRegId = sIn; };
	void PutSwId(const stringx& sIn) {m_sSwUniqueId = sIn; };
	void PutSwPublisher(const stringx& sIn) {m_sOrigArpPublisher = sIn; };
	void PutTagCreator(const stringx& sIn) {m_sTagCreatorName = sIn; };
	void PutTagCreatorRegId(const stringx& sIn) {m_sTagCreatorRegId = sIn; };
	void PutGenerateTag(bool bIn) {m_bGenerateTag = bIn; };
	void PutRequireSwEntitlement(bool bIn) { m_sEntitlementRequired = bIn ? L"1" : L"0"; };
	void PutOrigArpInfo(const stringx& sGuid, const stringx& sDispName, const stringx& sDispVersion, const stringx& sPublisher);
	void PutCurArpInfo(const stringx& sGuid, const stringx& sDispName, const stringx& sDispVersion, const stringx& sPublisher);
	void PutAppCatalogInfo(long nPkgId, const stringx& sDbName, const stringx& sDbGuid, const stringx& sDbServer);
	bool GetSuccessfullyLoadedExistingTagFile() {return m_bSuccessfullyReadExistingTag; };
	void EscapeSingleQuotes();

protected:
	void Load(const stringxi& tagFile);
	void ReadTag();
	bool SaveTagFile();
	stringx CreateHash();
	bool OpenTagFile(const stringxi& tagFile);
	bool OpenSwIdTagXmlTemplate();
	void DetermineUniqueId();

	void WriteSwIdTagSettings();
	void WriteProductVersion(XML::IXMLDOMNode* pSwidtagNode);
	void WriteProductName(XML::IXMLDOMNode* pSwidtagNode);
	void WriteSwId(XML::IXMLDOMNode* pSwidtagNode);
	void WriteSwCreator(XML::IXMLDOMNode* pSwidtagNode);
	void WriteSwLicensor(XML::IXMLDOMNode* pSwidtagNode);
	void WriteTagCreator(XML::IXMLDOMNode* pSwidtagNode);
	void WriteEntitlementRequiredIndicator(XML::IXMLDOMNode* pSwidtagNode);
	void WriteExtendedInformation(XML::IXMLDOMNode* pSwidtagNode);

 	void GetVersionFromString(const stringx& sNumber, long* lMajor, long* lMinor, long* lBuild, long* lReview);
// 	bool ValidatePropertyValue(int nPropName, const stringx& sPropValue, bool bNotNullable, bool bFilename);
	stringxi GetDefaultTagFileName();
	bool GetRegKeyValue(LPCTSTR lpszKeyName, LPCTSTR lpszValueName, LPCTSTR lpszDefaultValue, CString& strValue, HKEY key);
	bool GetRepackagerFolder(CString& strLocation);
	bool GetProductFolder(CString& strProductLocation);


private:
	CComPtr<XML::IXMLDOMDocument2> m_spXmlDoc;
	stringxi m_sTagFile;
	stringx m_sHash;
	bool m_bGenerateTag;
	bool m_bSuccessfullyReadExistingTag;
	//these are the 11 software id tag fields from the tag specification
	stringx m_sSwUniqueId;
	stringx m_sSwRegId;
	stringx m_sTagCreatorName;
	stringx m_sTagCreatorRegId;
	stringx m_sSwCreatorName;
	stringx m_sSwCreatorRegId;
	stringx m_sSwLicensorName;
	stringx m_sSwLicensorRegId;
	stringx m_sEntitlementRequired;
	stringx m_sProductName;
	stringx m_sProductVersion;
	
	//these are nine extended AdminStudio attributes (extension to tag specfication)
	stringx m_sOrigArpGuid;
	stringx m_sOrigArpPublisher;
	stringx m_sOrigArpDisplayName;
	stringx m_sOrigArpDisplayVersion;
	stringx m_sCurArpGuid;
	stringx m_sCurArpPublisher;
	stringx m_sCurArpDisplayName;
	stringx m_sCurArpDisplayVersion;
	
	//These fields are populated during import into application catalog
	long m_nAppCatalogPkgId;
	stringx m_sAppCatalogServerName;
	stringx m_sAppCatalogDbName;
	stringx m_sAppCatalogDbGuid;
};

