#include "stdafx.h"
#include "ProjectSettings.h"
#include "SettingsConstants.h"
#include "iscomutils.h"

//using appservices to get the location of the settings file
#include "ISAppServices.h"
#include "ISAppServicesWrapper.h"


//////////////////////////////////////////////////////////////////////////////////////////////
//CSettingsItem Class
//////////////////////////////////////////////////////////////////////////////////////////////

CSettingsItem::CSettingsItem(XML::IXMLDOMNode* pNode):m_pNode(pNode)
{

}

CSettingsItem::~CSettingsItem()
{

}

stringx CSettingsItem::GetName()
{
	stringx sName;
	hrx hr = m_pNode->get_nodeName(&sName);
	return sName;
}

stringx CSettingsItem::GetContent()
{
	stringx sElementContent;

	CComPtr<XML::IXMLDOMNodeList> spXmlNodeList;
	hrx hr = m_pNode->get_childNodes(&spXmlNodeList);

	long lItems = 0;
	hr = spXmlNodeList->get_length(&lItems);

	CComPtr<XML::IXMLDOMText> spElementContent;
	bool bCreatedNode = false;

	if(lItems >= 1)
	{
		CComPtr<XML::IXMLDOMNode> spElementNode;
		hrx hr = spXmlNodeList->get_item(0, &spElementNode);

		if(SUCCEEDED(spElementNode.QueryInterface(&spElementContent)))
		{
			hr = spElementContent->get_text(&sElementContent);
		}
	}

	return sElementContent;
}

bool CSettingsItem::GetAttributeValueBool(const stringx& strAttribute, bool bDefaultValueIfNotExist)
{
	stringxi sAttributeValue = GetAttributeValue(strAttribute).c_str();

	if(sAttributeValue.empty())
	{
		// attribute doesn't exist, return the value the caller specified
		return bDefaultValueIfNotExist;
	}

	// Attribute does exist, check if equals true
	return (sAttributeValue == L"true");
}

stringx CSettingsItem::GetAttributeValue(const stringx& strAttribute)
{
	CComPtr<XML::IXMLDOMNamedNodeMap> spAttributes;
	hrx hr = m_pNode->get_attributes(&spAttributes);

	CComPtr<XML::IXMLDOMNode> spNode;
	hr = spAttributes->getNamedItem(strAttribute,&spNode);
    
	if(spNode)
	{
		CComVariant varValue;
		spNode->get_nodeValue(&varValue);
		return stringx(varValue);
	}
	return L"";
}

bool CSettingsItem::GetChildSettingItems(VEC_PROJECT_SETTINGS_ITEMS& vItems)
{
#ifdef DEBUG
	DOMNodeType type;
	m_pNode->get_nodeType(&type);
#endif
	CComPtr<XML::IXMLDOMNodeList> spNodeList;
	hrx hr = m_pNode->get_childNodes(&spNodeList);
	
	long lElements = 0;
	hr = spNodeList->get_length(&lElements);
	for (long nCount = 0; nCount < lElements; nCount++)
	{
		CComPtr<XML::IXMLDOMNode> spNode;
		hr = spNodeList->get_item(nCount, &spNode);

		CSettingsItem item(spNode);
		vItems.push_back(item);
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//CProjectSettings Class
//////////////////////////////////////////////////////////////////////////////////////////////

CProjectSettings::CProjectSettings()
{
	m_spDoc = OpenSettingsXml();
}

CProjectSettings::~CProjectSettings()
{

}

CComPtr<XML::IXMLDOMDocument2> CProjectSettings::OpenSettingsXml()
{
	stringx strSettingsFile;
	hrx hr = IsAppServicesWrapper::GetLocalSettings()->get_ISFilePath(Settings_XML, &strSettingsFile);

	CComPtr<XML::IXMLDOMDocument2> spDoc;
	hr = MSXMLWrapper::CreateXmlDocFromFile(strSettingsFile, &spDoc);

	return spDoc;
}

stringx CProjectSettings::GetSingleAttrbiuteValue(const stringx& sXPath, const stringx& sAttributeName)
{
	CComPtr<XML::IXMLDOMDocument2> spDoc = OpenSettingsXml();

	CComPtr<XML::IXMLDOMNode> spNode;
	hrx hr = spDoc->selectSingleNode(sXPath, &spNode);

	if(spNode)
	{
		return CSettingsItem(spNode).GetAttributeValue(sAttributeName);
	}

	return L"";
}

bool CProjectSettings::GetProjectSettingItemsUsingXPath(const stringx& sXPath, VEC_PROJECT_SETTINGS_ITEMS& vecItems)
{
	CComPtr<XML::IXMLDOMNodeList> spNodeList;
	hrx hr = m_spDoc->selectNodes(sXPath, &spNodeList);
	return LoadSettingNodes(spNodeList, vecItems);
}

bool CProjectSettings::LoadSettingNodes(XML::IXMLDOMNodeList* pNodeItemList, VEC_PROJECT_SETTINGS_ITEMS& vecItems)
{
	long lElements = 0;
	hrx hr = pNodeItemList->get_length(&lElements);
//	ATLASSERT((lElements != 0) && _T("Empty item list in settings.xml, is that what was intended??"));

	for (long nCount = 0; nCount < lElements; nCount++)
	{
		CComPtr<XML::IXMLDOMNode> spNode;
		hr = pNodeItemList->get_item(nCount, &spNode);
		vecItems.push_back(CSettingsItem(spNode));
	}

	return (!vecItems.empty());
}
