#include "stdafx.h"
#include "resource.h"
#include "SwIdTag.h"
#include "MSXMLWrapper.h"
#include "hrx_new.h"
#include "AdminStudio_RegLocations.h"
#include "AppRegKey.h"
#include "pathx.h"

using namespace AdmRegLocations;

bool CSwIdTag::GetRegKeyValue(LPCTSTR lpszKeyName, LPCTSTR lpszValueName, LPCTSTR lpszDefaultValue, CString& strValue, HKEY key)
{
	try
	{
		CComBSTR bstrValue;
		HRESULT hr = HRESULT_FROM_WIN32(CAppRegKey::GetRegKeyValue(key, lpszKeyName, lpszValueName, &bstrValue));

		strValue = bstrValue;
		if(FAILED(hr))
		{
			CString sRoot(_T("HKEY_LOCAL_MACHINE"));

			if(key == HKEY_CURRENT_USER) sRoot = _T("HKEY_CURRENT_USER");

			CString sMessage;
			sMessage.Format(_T("Can't find registry value %s in %s\\%s"), lpszValueName, sRoot, lpszKeyName);
			TRACE(_T("InstallShield Exception: %s\n"), sMessage);

			strValue = lpszDefaultValue;
		}

		return true;
	}
	catch(...)
	{
	}
	return false;
}

bool CSwIdTag::GetRepackagerFolder(CString& strLocation)
{
	bool bSuccess = false;

	GetRegKeyValue(g_lpszHKLMMainSettingsKey, g_lpszRepackager, _T(""), strLocation, HKEY_LOCAL_MACHINE);
	if (strLocation.IsEmpty())
	{
		// Assume subfolder of main installdir
		GetRegKeyValue(AdmRegLocations::g_lpszHKLMMainSettingsKey, AdmRegLocations::g_lpszProductLocation, _T(""), strLocation, HKEY_LOCAL_MACHINE);
		if (!strLocation.IsEmpty())
		{
			is::pathx pthRepackager((LPCTSTR)strLocation);
			pthRepackager += _T("Repackager");
			strLocation = (LPCTSTR)pthRepackager;
			bSuccess = true;
		}
	}

	return bSuccess;
}

bool CSwIdTag::GetProductFolder(CString& strProductLocation)
{
	bool bRc = true;
	static CString _strProductLocation;
	if( _strProductLocation.IsEmpty() )
		bRc = GetRegKeyValue(AdmRegLocations::g_lpszHKLMMainSettingsKey, AdmRegLocations::g_lpszProductLocation, _T(""), _strProductLocation, HKEY_LOCAL_MACHINE);
	strProductLocation = _strProductLocation;
	return bRc;
}


#define SWIDTAG_NAMESPACE_2008 L"xmlns:ds='http://www.w3.org/2000/09/xmldsig#' xmlns:swid='http://standards.iso.org/iso/19770/-2/2008/schema.xsd' xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xmlns:fs='http://www.flexerasoftware.com/swid/2011/arp'"
#define SWIDTAG_NAMESPACE_2009 L"xmlns:ds='http://www.w3.org/2000/09/xmldsig#' xmlns:swid='http://standards.iso.org/iso/19770/-2/2009/schema.xsd' xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xmlns:fs='http://www.flexerasoftware.com/swid/2011/arp'"
#define SELECTION_NAMESPACES L"SelectionNamespaces"
#define SELECTION_LANGUAGE L"SelectionLanguage"

#define SWIDTAG_XPATH_SOFTWARE_ID_TAG L"//swid:software_identification_tag"

#define SWIDTAG_NODENAME_ENTITLMENT_REQUIRED_INDICATOR L"swid:entitlement_required_indicator"
#define SWIDTAG_NODENAME_PRODUCT_TITLE L"swid:product_title"
#define SWIDTAG_NODENAME_PRODUCT_VERSION L"swid:product_version"
#define SWIDTAG_NODENAME_SOFTWARE_CREATOR L"swid:software_creator"
#define SWIDTAG_NODENAME_SOFTWARE_LICENSOR L"swid:software_licensor"
#define SWIDTAG_NODENAME_SOFTWARE_ID L"swid:software_id"
#define SWIDTAG_NODENAME_UNIQUE_ID L"swid:unique_id"
#define SWIDTAG_NODENAME_TAG_CREATOR_REGID L"swid:tag_creator_regid"
#define SWIDTAG_NODENAME_TAG_CREATOR L"swid:tag_creator"
#define SWIDTAG_NODENAME_NAME L"swid:name"
#define SWIDTAG_NODENAME_REGID L"swid:regid"
#define SWIDTAG_NODENAME_NUMERIC L"swid:numeric"
#define SWIDTAG_NODENAME_MAJOR L"swid:major"
#define SWIDTAG_NODENAME_MINOR L"swid:minor"
#define SWIDTAG_NODENAME_BUILD L"swid:build"
#define SWIDTAG_NODENAME_REVIEW L"swid:review"
#define SWIDTAG_NODENAME_EXTENDED_INFO L"swid:extended_information"
#define SWIDTAG_NODENAME_FS_ORG_ARP_GUID L"fs:original_arp_guid"
#define SWIDTAG_NODENAME_FS_ORG_ARP_PUBLISHER L"fs:original_arp_publisher"
#define SWIDTAG_NODENAME_FS_ORG_ARP_DISP_NAME L"fs:original_arp_display_name"
#define SWIDTAG_NODENAME_FS_ORG_ARP_DISP_VERSION L"fs:original_arp_display_version"
#define SWIDTAG_NODENAME_FS_CUR_ARP_GUID L"fs:current_arp_guid"
#define SWIDTAG_NODENAME_FS_CUR_ARP_PUBLISHER L"fs:current_arp_publisher"
#define SWIDTAG_NODENAME_FS_CUR_ARP_DISP_NAME L"fs:current_arp_display_name"
#define SWIDTAG_NODENAME_FS_CUR_ARP_DISP_VERSION L"fs:current_arp_display_version"
#define SWIDTAG_NODENAME_FS_AS_APPCATALOG_PACKAGEID L"fs:adminstudio_app_catalog_package_id"
#define SWIDTAG_NODENAME_FS_AS_APPCATALOG_MACHINENAME L"fs:adminstudio_app_catalog_machine_name"
#define SWIDTAG_NODENAME_FS_AS_APPCATALOG_DBNAME L"fs:adminstudio_app_catalog_db_name"
#define SWIDTAG_NODENAME_FS_AS_APPCATALOG_GUID L"fs:adminstudio_app_catalog_guid"

#define SWIDTAG_NODENAME_FS_GENERATETAG L"fs:generate_tag"

#define SWIDTAG_NODEVALE_TRUE L"true"
#define SWIDTAG_NODEVALE_FALSE L"false"


#define SWIDTAG_NAMESPACE_FS L"http://www.flexerasoftware.com/swid/2011/arp"
// #define SWIDTAG_FLEXERANAME L"Flexera Software LLC"
// #define SWIDTAG_FLEXERAREGID_ADMINSTUDIO L"regid.2009-06.com.flexerasoftware,AdminStudio"
#define SWIDTAG_UNKNOWN L"Unknown"

namespace XmlHelper
{
	stringx GetNodeValue(XML::IXMLDOMDocument2* pDoc, const stringx& query)
	{
		CComPtr<XML::IXMLDOMNode> spNode;
		pDoc->selectSingleNode(query, &spNode);
		if (spNode)
		{
			CComBSTR bs;
			spNode->get_text(&bs);
			return stringx(bs);
		}
		
		return L"";
	}

	void DeleteNode(XML::IXMLDOMDocument2* pDoc, const stringx& query)
	{
		CComPtr<XML::IXMLDOMNode> spNode;
		pDoc->selectSingleNode(query, &spNode);
		if (!spNode)
			return;
		
		CComPtr<XML::IXMLDOMNode> spParentNode;
		spNode->get_parentNode(&spParentNode);
		if (!spParentNode)
			return;

		CComPtr<XML::IXMLDOMNode> spRemovedNode;
		spParentNode->removeChild(spNode, &spRemovedNode);
	}

	void DeleteNode(XML::IXMLDOMNode* pStartNode, const stringx& query)
	{
		CComPtr<XML::IXMLDOMNode> spNode;
		pStartNode->selectSingleNode(query, &spNode);
		if (!spNode)
			return;
		
		CComPtr<XML::IXMLDOMNode> spParentNode;
		spNode->get_parentNode(&spParentNode);
		if (!spParentNode)
			return;
		
		CComPtr<XML::IXMLDOMNode> spRemovedNode;
		spParentNode->removeChild(spNode, &spRemovedNode);
	}
	
	CComPtr<XML::IXMLDOMNode> CreateNode(XML::IXMLDOMDocument2* pDoc, XML::IXMLDOMNode* pParentNode, const stringx& sNodeName, const stringx& sNamespace = L"")
	{
		CComPtr<XML::IXMLDOMNode> spNode;
		hrx hr = pParentNode->selectSingleNode(sNodeName, &spNode);
		if(!spNode)
		{
			stringx sNamespaceTmp = sNamespace;
			if(sNamespaceTmp.empty())
			{
				hr = pParentNode->get_namespaceURI(&sNamespaceTmp);
			}
			
			CComPtr<XML::IXMLDOMNode> spTmpNewNode;
			//constant 1 == NODE_ELEMENT
			hr = pDoc->createNode(CComVariant(1), sNodeName, sNamespaceTmp, &spTmpNewNode);
			hr = pParentNode->appendChild(spTmpNewNode, &spNode);
		}

		return spNode;
	}
}

//Set defaults for the various software id tag attributes
CSwIdTag::CSwIdTag()
{
	m_bSuccessfullyReadExistingTag = false;
	OpenSwIdTagXmlTemplate();
}

CSwIdTag::CSwIdTag(const stringxi& sSwIdTagFile)
{
	m_sTagFile = sSwIdTagFile;
	m_bSuccessfullyReadExistingTag = false;
	Load(m_sTagFile);
}

CSwIdTag::~CSwIdTag()
{
}

bool CSwIdTag::OpenTagFile(const stringxi& tagFile)
{
	m_bSuccessfullyReadExistingTag = false;
	try
	{
		HRESULT hr = MSXMLWrapper::CreateXmlDocObj(&m_spXmlDoc);
		if (FAILED(hr) || m_spXmlDoc.p == NULL)
			return false;
		
		m_spXmlDoc->put_async(VARIANT_FALSE);
		m_spXmlDoc->put_validateOnParse(VARIANT_FALSE);
		m_spXmlDoc->put_resolveExternals(VARIANT_FALSE);
		m_spXmlDoc->put_preserveWhiteSpace(VARIANT_TRUE);
		
		CComVariant  vtFile((LPCTSTR)tagFile);
		VARIANT_BOOL vbResults;
		hr = m_spXmlDoc->load(vtFile, &vbResults);   
		if (vbResults != VARIANT_TRUE)
			return false;
		
		//it is possible for the tag file to have one of two different namespaces (2008 or 2009)
		//first try one namespace and check to see if the root element can be queried.
		//if not, then try second namespace
		m_spXmlDoc->setProperty(SELECTION_NAMESPACES, CComVariant(SWIDTAG_NAMESPACE_2008));
		m_spXmlDoc->setProperty(SELECTION_LANGUAGE, CComVariant(CComBSTR(L"XPath")));

		CComPtr<XML::IXMLDOMNode> spNode;
		m_spXmlDoc->selectSingleNode(SWIDTAG_XPATH_SOFTWARE_ID_TAG, &spNode);
		if (!spNode)
		{
			m_spXmlDoc->setProperty(SELECTION_NAMESPACES, CComVariant(SWIDTAG_NAMESPACE_2009));
			m_spXmlDoc->selectSingleNode(SWIDTAG_XPATH_SOFTWARE_ID_TAG, &spNode);
			if (!spNode)
			{
				return false;
			}
		}
	} 
	catch (...)
	{
	}

	m_bSuccessfullyReadExistingTag = true;
	return true;
}

//Read from swIdTag and populate member variables
void CSwIdTag::Load(const stringxi& tagFile)
{
	m_sTagFile = tagFile;
	if (OpenTagFile(tagFile))
		ReadTag();
}

void CSwIdTag::ReadTag()
{
	m_sEntitlementRequired = (XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_ENTITLMENT_REQUIRED_INDICATOR).as_stringxi() == SWIDTAG_NODEVALE_TRUE) ? L"1" : L"0";

	m_sProductName = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_PRODUCT_TITLE);
	m_sProductVersion += XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_PRODUCT_VERSION L"/" SWIDTAG_NODENAME_NUMERIC L"/" SWIDTAG_NODENAME_MAJOR);
	m_sProductVersion += L"." + XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_PRODUCT_VERSION L"/" SWIDTAG_NODENAME_NUMERIC L"/" SWIDTAG_NODENAME_MINOR);
	m_sProductVersion += L"." + XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_PRODUCT_VERSION L"/" SWIDTAG_NODENAME_NUMERIC L"/" SWIDTAG_NODENAME_BUILD);
	m_sProductVersion += L"." + XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_PRODUCT_VERSION L"/" SWIDTAG_NODENAME_NUMERIC L"/" SWIDTAG_NODENAME_REVIEW);

	m_sSwCreatorName = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_SOFTWARE_CREATOR L"/" SWIDTAG_NODENAME_NAME);
	m_sSwCreatorRegId = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_SOFTWARE_CREATOR L"/" SWIDTAG_NODENAME_REGID);
	if (m_sSwCreatorRegId.empty())
		m_sSwCreatorRegId = SWIDTAG_UNKNOWN;

	m_sSwLicensorName = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_SOFTWARE_LICENSOR L"/" SWIDTAG_NODENAME_NAME);
	if (m_sSwLicensorName.empty())
		m_sSwLicensorName = SWIDTAG_UNKNOWN;
	m_sSwLicensorRegId = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_SOFTWARE_LICENSOR L"/" SWIDTAG_NODENAME_REGID);
	if (m_sSwLicensorRegId.empty())
		m_sSwLicensorRegId = SWIDTAG_UNKNOWN;

	using namespace AdmRegLocations;
	m_sTagCreatorName = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_TAG_CREATOR L"/" SWIDTAG_NODENAME_NAME);
	if (m_sTagCreatorName.empty())
		m_sTagCreatorName = g_lpszSwIdTag_TagCreatorName_DefaultVal;

	m_sTagCreatorRegId = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_TAG_CREATOR L"/" SWIDTAG_NODENAME_REGID);
	if (m_sTagCreatorRegId.empty())
		m_sTagCreatorRegId = g_lpszSwIdTag_TagCreatorRegId_DefaultVal;

	m_sSwUniqueId = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_SOFTWARE_ID L"/" SWIDTAG_NODENAME_UNIQUE_ID);
	m_sSwRegId = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_SOFTWARE_ID L"/" SWIDTAG_NODENAME_TAG_CREATOR_REGID);
	if (m_sSwRegId.empty())
		m_sSwRegId = g_lpszSwIdTag_TagCreatorRegId_DefaultVal;
	
	//extended information
	m_sOrigArpGuid = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_ORG_ARP_GUID);
	m_sOrigArpDisplayName = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_ORG_ARP_DISP_NAME);
	m_sOrigArpDisplayVersion = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_ORG_ARP_DISP_VERSION);
	m_sOrigArpPublisher = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_ORG_ARP_PUBLISHER);

	m_sCurArpGuid = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_CUR_ARP_GUID);
	m_sCurArpDisplayName = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_CUR_ARP_DISP_NAME);
	m_sCurArpDisplayVersion = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_CUR_ARP_DISP_VERSION);
	m_sCurArpPublisher = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_CUR_ARP_PUBLISHER);
	
	m_nAppCatalogPkgId = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_AS_APPCATALOG_PACKAGEID).as_int();
	m_sAppCatalogServerName = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_AS_APPCATALOG_MACHINENAME);
	m_sAppCatalogDbName = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_AS_APPCATALOG_DBNAME);
	m_sAppCatalogDbGuid = XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_AS_APPCATALOG_GUID);

	//We are going to overload the tag file by also storing the option that indicates whether 
	//to include the tag in a MST during the Repackager build phase.  If the option is not present,
	//then default it to true (include tag).
	m_bGenerateTag = (XmlHelper::GetNodeValue(m_spXmlDoc, SWIDTAG_XPATH_SOFTWARE_ID_TAG L"/" SWIDTAG_NODENAME_EXTENDED_INFO L"/" SWIDTAG_NODENAME_FS_GENERATETAG) != L"No");
		
	m_sHash = CreateHash();
}

stringxi CSwIdTag::GetDefaultTagFileName()
{
	return m_sTagCreatorRegId.as_stringxi() + L"_" + m_sSwUniqueId.as_stringxi() + L".swidtag";
}

stringxi CSwIdTag::SaveWithDefaultName()
{
	stringxi sDefaultTagFileName = GetDefaultTagFileName();
	stringxi sOrigTagFile = m_sTagFile;
	bool bTagFileNameChange = false;
	if (sDefaultTagFileName != m_sTagFile.path_file())
	{
		bTagFileNameChange = true;
		m_sTagFile = sOrigTagFile.path_dir() ^ sDefaultTagFileName;
	}
		
	Save();

	if (bTagFileNameChange)
		::DeleteFile(sOrigTagFile);
		
	return m_sTagFile;
}

stringxi CSwIdTag::SaveToFolderWithDefaultName(const stringxi& sFolder)
{
	m_sTagFile = L"";
	SaveToFolder(sFolder);
	return m_sTagFile;
}

void CSwIdTag::SaveToFolder(const stringxi& sFolder)
{
	//Generate the tag file name if one already does not exist, otherwise use the existing name.
	DetermineUniqueId();

	if (m_sTagFile.empty())
		m_sTagFile = sFolder ^ GetDefaultTagFileName();
	else
		m_sTagFile = sFolder ^ m_sTagFile.path_file();
	Save();
}

void CSwIdTag::Save()
{
	if (m_sTagFile.empty())
		return;

	m_sHash = CreateHash();
	WriteSwIdTagSettings();
	SaveTagFile();
}

bool CSwIdTag::SaveTagFile()
{
	try
	{
 		if (::PathFileExists(m_sTagFile))
 			::DeleteFile(m_sTagFile);
		
		//Have to use this if define because the version of shlwapi.h that Repackager links to does
		//not have access to SHCreateStreamOnFile API
#if _MSC_VER > 1400
		if(m_spXmlDoc)
		{
			CComPtr<IStream> spStream;
			if (FAILED(SHCreateStreamOnFile(m_sTagFile, STGM_WRITE|STGM_CREATE, &spStream))
				|| FAILED(MSXMLWrapper::IndentXml(m_spXmlDoc, CComVariant(spStream))))
			{
				spStream.Release();
				hrx hr = m_spXmlDoc->save(CComVariant((LPCTSTR)m_sTagFile));
				return SUCCEEDED(hr);
			}
			else
			{
				return true;
			}
		}
#else
		hrx hr = m_spXmlDoc->save(CComVariant((LPCTSTR)m_sTagFile));
		return SUCCEEDED(hr);
#endif
	}
	catch (...)
	{
		return false;
	}

	return false;
}

//store original values of member variable strings in one string to compare later to determine if any values have been modified
//this will help to set the modified status of the overall Repackager doc appropriately
stringx CSwIdTag::CreateHash()
{
	return m_sSwUniqueId + L"<|>" + m_sSwRegId + L"<|>" + m_sTagCreatorName + L"<|>" + m_sTagCreatorRegId + 
		L"<|>" + m_sSwCreatorName + L"<|>" + m_sSwCreatorRegId + L"<|>" + m_sSwLicensorName + 
		L"<|>" + m_sSwLicensorRegId + L"<|>" + m_sEntitlementRequired + L"<|>" + m_sProductName + 
		L"<|>" + m_sProductVersion + L"<|>" + m_sOrigArpGuid + L"<|>" + m_sOrigArpPublisher + L"<|>" + (m_bGenerateTag ? L"Yes" : L"No") +
		L"<|>" + m_sCurArpGuid + L"<|>" + m_sCurArpDisplayName + L"<|>" + m_sCurArpDisplayVersion + L"<|>" + m_sCurArpPublisher;
}

bool CSwIdTag::IsModified()
{
	return CreateHash() != m_sHash;
}

bool CSwIdTag::OpenSwIdTagXmlTemplate()
{
	stringxi sModuleFile;
	GetModuleFileName(NULL, sModuleFile.get_buffer(MAX_PATH), MAX_PATH);

	//This location is valid in debug builds or if Repackager is running
	stringxi sCandidate1 = sModuleFile.path_dir() ^ L"Swidtag.xml";
	//This location is valid if Application Manager is running
	stringxi sCandidate2 = sModuleFile.path_dir().path_dir() ^ L"Repackager\\Swidtag.xml";
	//This location can be valid if an external executable invokes this such as powershell
	CString strCandidate3;
	GetRepackagerFolder(strCandidate3);
	stringxi sCandidate3 = stringxi(strCandidate3) ^ L"Swidtag.xml";
	//This location can be valid if an external executable invokes this such as powershell in debug mode
	CString strCandidate4;
	GetProductFolder(strCandidate4);
	stringxi sCandidate4 = stringxi(strCandidate4) ^ L"system\\Swidtag.xml";
	
	stringxi sSwidtagFile;
	if (::PathFileExists(sCandidate1))
		sSwidtagFile = sCandidate1;
	else if (::PathFileExists(sCandidate2))
		sSwidtagFile = sCandidate2;
	else if (::PathFileExists(sCandidate3))
		sSwidtagFile = sCandidate3;
	else if (::PathFileExists(sCandidate4))
		sSwidtagFile = sCandidate4;
	else
		return false;

	if (OpenTagFile(sSwidtagFile))
	{
		ReadTag();
		return true;
	}
	else
		return false;
}

void CSwIdTag::DetermineUniqueId()
{
	if (m_sSwUniqueId.empty())
		m_sSwUniqueId = m_sOrigArpGuid;
}

void CSwIdTag::WriteSwIdTagSettings()
{
	if(m_spXmlDoc)
	{
		CComPtr<XML::IXMLDOMNode> spSwidtagNode;
		hrx hr = m_spXmlDoc->selectSingleNode(SWIDTAG_XPATH_SOFTWARE_ID_TAG, &spSwidtagNode);\
		WriteProductName(spSwidtagNode);
		WriteProductVersion(spSwidtagNode);
		WriteSwId(spSwidtagNode);
		WriteSwCreator(spSwidtagNode);
		WriteSwLicensor(spSwidtagNode);
		WriteTagCreator(spSwidtagNode);
		WriteEntitlementRequiredIndicator(spSwidtagNode);
		WriteExtendedInformation(spSwidtagNode);
	}
}

void CSwIdTag::WriteProductName(XML::IXMLDOMNode* pSwidtagNode)
{
	CComPtr<XML::IXMLDOMNode> spProductTitleNode = XmlHelper::CreateNode(m_spXmlDoc, pSwidtagNode, SWIDTAG_NODENAME_PRODUCT_TITLE);
	hrx hr = spProductTitleNode->put_text(m_sProductName);
}

void CSwIdTag::WriteProductVersion(XML::IXMLDOMNode* pSwidtagNode)
{
	CComPtr<XML::IXMLDOMNode> spVersionNode = XmlHelper::CreateNode(m_spXmlDoc, pSwidtagNode, SWIDTAG_NODENAME_PRODUCT_VERSION);
	CComPtr<XML::IXMLDOMNode> spNameNode = XmlHelper::CreateNode(m_spXmlDoc, spVersionNode, SWIDTAG_NODENAME_NAME);
	hrx hr = spNameNode->put_text(m_sProductVersion);

	long lMajor = 0;
	long lMinor = 0;
	long lBuild = 0;
	long lReview = 0;
	GetVersionFromString(m_sProductVersion, &lMajor, &lMinor, &lBuild, &lReview );

	CComPtr<XML::IXMLDOMNode> spNumericNode = XmlHelper::CreateNode(m_spXmlDoc, spVersionNode, SWIDTAG_NODENAME_NUMERIC);
	CComPtr<XML::IXMLDOMNode> spMajorNode = XmlHelper::CreateNode(m_spXmlDoc, spNumericNode, SWIDTAG_NODENAME_MAJOR);
	hr = spMajorNode->put_text(stringx(lMajor));
	
	CComPtr<XML::IXMLDOMNode> spMinorNode = XmlHelper::CreateNode(m_spXmlDoc, spNumericNode, SWIDTAG_NODENAME_MINOR);
	hr = spMinorNode->put_text(stringx(lMinor));

	CComPtr<XML::IXMLDOMNode> spBuildNode = XmlHelper::CreateNode(m_spXmlDoc, spNumericNode, SWIDTAG_NODENAME_BUILD);
	hr = spBuildNode->put_text(stringx(lBuild));

	CComPtr<XML::IXMLDOMNode> spReviewNode = XmlHelper::CreateNode(m_spXmlDoc, spNumericNode, SWIDTAG_NODENAME_REVIEW);
	hr = spReviewNode->put_text(stringx(lReview));
}

void CSwIdTag::WriteSwId(XML::IXMLDOMNode* pSwidtagNode)
{
	CComPtr<XML::IXMLDOMNode> spSwIdNode = XmlHelper::CreateNode(m_spXmlDoc, pSwidtagNode, SWIDTAG_NODENAME_SOFTWARE_ID);
	CComPtr<XML::IXMLDOMNode> spUniqueIdNode = XmlHelper::CreateNode(m_spXmlDoc, spSwIdNode, SWIDTAG_NODENAME_UNIQUE_ID);
	hrx hr = spUniqueIdNode->put_text(m_sSwUniqueId);

	CComPtr<XML::IXMLDOMNode> spRegIdNode = XmlHelper::CreateNode(m_spXmlDoc, spSwIdNode, SWIDTAG_NODENAME_TAG_CREATOR_REGID);
	hr = spRegIdNode->put_text(m_sTagCreatorRegId);
}

void CSwIdTag::WriteSwCreator(XML::IXMLDOMNode* pSwidtagNode)
{
	CComPtr<XML::IXMLDOMNode> spSwCreatorNode = XmlHelper::CreateNode(m_spXmlDoc, pSwidtagNode, SWIDTAG_NODENAME_SOFTWARE_CREATOR);
	CComPtr<XML::IXMLDOMNode> spNameNode = XmlHelper::CreateNode(m_spXmlDoc, spSwCreatorNode, SWIDTAG_NODENAME_NAME);
	hrx hr = spNameNode->put_text(m_sSwCreatorName.empty() ? (m_sTagCreatorName.empty() ? m_sOrigArpPublisher : m_sTagCreatorName) : m_sSwCreatorName);

	CComPtr<XML::IXMLDOMNode> spRegIdNode = XmlHelper::CreateNode(m_spXmlDoc, spSwCreatorNode, SWIDTAG_NODENAME_REGID);
	hr = spRegIdNode->put_text(m_sSwCreatorRegId.empty() ? m_sTagCreatorRegId : m_sSwCreatorRegId);
}

void CSwIdTag::WriteSwLicensor(XML::IXMLDOMNode* pSwidtagNode)
{
	CComPtr<XML::IXMLDOMNode> spSwLicensorNode = XmlHelper::CreateNode(m_spXmlDoc, pSwidtagNode, SWIDTAG_NODENAME_SOFTWARE_LICENSOR);
	CComPtr<XML::IXMLDOMNode> spNameNode = XmlHelper::CreateNode(m_spXmlDoc, spSwLicensorNode, SWIDTAG_NODENAME_NAME);
	hrx hr = spNameNode->put_text(m_sSwLicensorName.empty() ? (m_sTagCreatorName.empty() ? m_sOrigArpPublisher : m_sTagCreatorName) : m_sSwLicensorName);

	CComPtr<XML::IXMLDOMNode> spRegIdNode = XmlHelper::CreateNode(m_spXmlDoc, spSwLicensorNode, SWIDTAG_NODENAME_REGID);
	hr = spRegIdNode->put_text(m_sSwLicensorRegId.empty() ? m_sTagCreatorRegId : m_sSwLicensorRegId);
}

void CSwIdTag::WriteTagCreator(XML::IXMLDOMNode* pSwidtagNode)
{
	CComPtr<XML::IXMLDOMNode> spTagCreatorNode = XmlHelper::CreateNode(m_spXmlDoc, pSwidtagNode, SWIDTAG_NODENAME_TAG_CREATOR);
	CComPtr<XML::IXMLDOMNode> spNameNode = XmlHelper::CreateNode(m_spXmlDoc, spTagCreatorNode, SWIDTAG_NODENAME_NAME);
	hrx hr = spNameNode->put_text(m_sTagCreatorName.empty() ? m_sOrigArpPublisher : m_sTagCreatorName);

	CComPtr<XML::IXMLDOMNode> spRegIdNode = XmlHelper::CreateNode(m_spXmlDoc, spTagCreatorNode, SWIDTAG_NODENAME_REGID);
	hr = spRegIdNode->put_text(m_sTagCreatorRegId);
}

void CSwIdTag::WriteEntitlementRequiredIndicator(XML::IXMLDOMNode* pSwidtagNode)
{
	CComPtr<XML::IXMLDOMNode> spRequireIndicatorNode = XmlHelper::CreateNode(m_spXmlDoc, pSwidtagNode, SWIDTAG_NODENAME_ENTITLMENT_REQUIRED_INDICATOR);
	hrx hr = spRequireIndicatorNode->put_text(stringx(m_sEntitlementRequired==L"1" ? SWIDTAG_NODEVALE_TRUE : SWIDTAG_NODEVALE_FALSE));
}

void CSwIdTag::WriteExtendedInformation(XML::IXMLDOMNode* pSwidtagNode)
{
	hrx hr;
	CComPtr<XML::IXMLDOMNode> spExtendedInfoNode = XmlHelper::CreateNode(m_spXmlDoc, pSwidtagNode, SWIDTAG_NODENAME_EXTENDED_INFO);
	
	CComPtr<XML::IXMLDOMNode> spGuidNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_ORG_ARP_GUID);
	hr = spGuidNode->put_text(m_sOrigArpGuid);

	CComPtr<XML::IXMLDOMNode> spPublisherNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_ORG_ARP_PUBLISHER, SWIDTAG_NAMESPACE_FS);
	hr = spPublisherNode->put_text(m_sOrigArpPublisher.empty() ? m_sOrigArpPublisher : m_sOrigArpPublisher);

	CComPtr<XML::IXMLDOMNode> spNameNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_ORG_ARP_DISP_NAME, SWIDTAG_NAMESPACE_FS);
	hr = spNameNode->put_text(m_sOrigArpDisplayName.empty() ? m_sProductName : m_sOrigArpDisplayName);

	CComPtr<XML::IXMLDOMNode> spVersionNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_ORG_ARP_DISP_VERSION, SWIDTAG_NAMESPACE_FS);
	hr = spVersionNode->put_text(m_sOrigArpDisplayVersion.empty() ? m_sProductVersion : m_sOrigArpDisplayVersion);

	if (!m_sCurArpGuid.empty())
	{
		CComPtr<XML::IXMLDOMNode> spCurGuidNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_CUR_ARP_GUID);
		hr = spCurGuidNode->put_text(m_sCurArpGuid);
		
		CComPtr<XML::IXMLDOMNode> spCurPublisherNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_CUR_ARP_PUBLISHER, SWIDTAG_NAMESPACE_FS);
		hr = spCurPublisherNode->put_text(m_sCurArpPublisher);
		
		CComPtr<XML::IXMLDOMNode> spCurNameNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_CUR_ARP_DISP_NAME, SWIDTAG_NAMESPACE_FS);
		hr = spCurNameNode->put_text(m_sCurArpDisplayName);
		
		CComPtr<XML::IXMLDOMNode> spCurVersionNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_CUR_ARP_DISP_VERSION, SWIDTAG_NAMESPACE_FS);
		hr = spCurVersionNode->put_text(m_sCurArpDisplayVersion);
	}
	
	CComPtr<XML::IXMLDOMNode> spAppCatalogPkgRowIdNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_AS_APPCATALOG_PACKAGEID, SWIDTAG_NAMESPACE_FS);
	hr = spAppCatalogPkgRowIdNode->put_text(stringx(m_nAppCatalogPkgId));

	CComPtr<XML::IXMLDOMNode> spAppCatalogServerNameNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_AS_APPCATALOG_MACHINENAME, SWIDTAG_NAMESPACE_FS);
	hr = spAppCatalogServerNameNode->put_text(m_sAppCatalogServerName);

	CComPtr<XML::IXMLDOMNode> spAppCatalogDbNameNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_AS_APPCATALOG_DBNAME, SWIDTAG_NAMESPACE_FS);
	hr = spAppCatalogDbNameNode->put_text(m_sAppCatalogDbName);

	CComPtr<XML::IXMLDOMNode> spAppCatalogDbGuidNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_AS_APPCATALOG_GUID, SWIDTAG_NAMESPACE_FS);
	hr = spAppCatalogDbGuidNode->put_text(m_sAppCatalogDbGuid);

	if (!m_bGenerateTag)
	{
		// write out the generate tag option if it is no
		CComPtr<XML::IXMLDOMNode> spGenerateTagNode = XmlHelper::CreateNode(m_spXmlDoc, spExtendedInfoNode, SWIDTAG_NODENAME_FS_GENERATETAG, SWIDTAG_NAMESPACE_FS);
		hr = spGenerateTagNode->put_text(L"No");
	}
	else
	{
		//delete generate tag option if it exists in tag file
		XmlHelper::DeleteNode(spExtendedInfoNode, SWIDTAG_NODENAME_FS_GENERATETAG);
	}
}


void CSwIdTag::GetVersionFromString(const stringx& sNumber, long* lMajor, long* lMinor, long* lBuild, long* lReview)
{
	std::vector<stringx> vItems;
	sNumber.split(L'.', vItems);
	long lSize = vItems.size();

	if (lSize > 0)
	{
		stringx strMajor = vItems[0];
		*lMajor = strMajor.as_int();
		if (lSize > 1)
		{
			stringx strMinor = vItems[1];
			*lMinor = strMinor.as_int();
			if (lSize > 2)
			{
				stringx strBuild = vItems[2];
				*lBuild = strBuild.as_int();
				if (lSize > 3)
				{
					stringx strReview = vItems[3];
					*lReview = strReview.as_int();
				}
			}
		}	
	}
}

void CSwIdTag::PutOrigArpInfo(const stringx& sGuid, const stringx& sDispName, const stringx& sDispVersion, const stringx& sPublisher)
{
	m_sOrigArpGuid = sGuid;
	m_sOrigArpPublisher = sPublisher;
	m_sOrigArpDisplayName = sDispName;
	m_sOrigArpDisplayVersion = sDispVersion;
}

void CSwIdTag::PutCurArpInfo(const stringx& sGuid, const stringx& sDispName, const stringx& sDispVersion, const stringx& sPublisher)
{
	m_sCurArpGuid = sGuid;
	m_sCurArpPublisher = sPublisher;
	m_sCurArpDisplayName = sDispName;
	m_sCurArpDisplayVersion = sDispVersion;
}

void CSwIdTag::PutAppCatalogInfo(long nPkgId, const stringx& sDbName, const stringx& sDbGuid, const stringx& sDbServer)
{
	m_nAppCatalogPkgId = nPkgId;
	m_sAppCatalogDbName = sDbName;
	m_sAppCatalogDbGuid = sDbGuid;
	m_sAppCatalogServerName = sDbServer;
}

void CSwIdTag::EscapeSingleQuotes()
{
	m_sTagFile.escape_chars("'","'","");

	//these are the 11 software id tag fields from the tag specification
	m_sSwUniqueId.escape_chars("'","'","");
	m_sSwRegId.escape_chars("'","'","");
	m_sTagCreatorName.escape_chars("'","'","");
	m_sTagCreatorRegId.escape_chars("'","'","");
	m_sSwCreatorName.escape_chars("'","'","");
	m_sSwCreatorRegId.escape_chars("'","'","");
	m_sSwLicensorName.escape_chars("'","'","");
	m_sSwLicensorRegId.escape_chars("'","'","");
	m_sEntitlementRequired.escape_chars("'","'","");
	m_sProductName.escape_chars("'","'","");
	m_sProductVersion.escape_chars("'","'","");

	//these are nine extended AdminStudio attributes (extension to tag specfication)
	m_sOrigArpGuid.escape_chars("'","'","");
	m_sOrigArpPublisher.escape_chars("'","'","");
	m_sOrigArpDisplayName.escape_chars("'","'","");
	m_sOrigArpDisplayVersion.escape_chars("'","'","");
	m_sCurArpGuid.escape_chars("'","'","");
	m_sCurArpPublisher.escape_chars("'","'","");
	m_sCurArpDisplayName.escape_chars("'","'","");
	m_sCurArpDisplayVersion.escape_chars("'","'","");
}

/*
bool CSwIdTag::ValidatePropertyValue(int nPropName, const stringx& sPropValue, bool bNotNullable, bool bFilename)
{
	if(bNotNullable && sPropValue.empty())
	{
		stringx sPropName;
		sPropName.load_string(_Module.GetResourceInstance(), nPropName);
		build_exception be_error;
		be_error.prepare_error(BE_BUILD_SWIDTAG_EMPTY_DATA, ISWIBUILD_SWIDTAG_EMPTY_DATA, sPropName);
		Status().LogWarning(be_error);
		return false;
	}

	if(bFilename && (sPropValue.find_first_of(L"\\/:*?<>\"|") != stringx::npos))
	{
		stringx sPropName;
		sPropName.load_string(_Module.GetResourceInstance(), nPropName);
		build_exception be_error;
		be_error.prepare_error(BE_BUILD_SWIDTAG_INVALID_DATA, ISWIBUILD_SWIDTAG_INVALID_DATA, sPropName);
		Status().LogError(be_error);
		return false;
	}

	return true;
}
*/