#ifndef IS_PROJECTSETTINGS_H
#define IS_PROJECTSETTINGS_H

#include "MSXMLWrapper.h"
#include "stringx.h"
#include "settingsconstants.h"
#include <vector>
#include <map>

class CSettingsItem;

typedef std::vector<CSettingsItem> VEC_PROJECT_SETTINGS_ITEMS;

//////////////////////////////////////////////////////////////////////////////////////////////
//CSettingsItem Class
//////////////////////////////////////////////////////////////////////////////////////////////
class CSettingsItem
{
public:
	CSettingsItem(XML::IXMLDOMNode* pNode);
	~CSettingsItem();

	stringx GetName();
	stringx GetContent();
	stringx GetAttributeValue(const stringx& strAttribute);
	bool GetAttributeValueBool(const stringx& strAttribute, bool bDefaultValueIfNotExist = false);
	bool GetChildSettingItems(VEC_PROJECT_SETTINGS_ITEMS& vItems);

private:
	CComPtr<XML::IXMLDOMNode> m_pNode;
};

//////////////////////////////////////////////////////////////////////////////////////////////
//CProjectSettings Class
//////////////////////////////////////////////////////////////////////////////////////////////
class CProjectSettings
{
public:
	CProjectSettings();
	~CProjectSettings();

	bool GetProjectSettingItemsUsingXPath(const stringx& sXPath,VEC_PROJECT_SETTINGS_ITEMS& vecItems);
	static stringx GetSingleAttrbiuteValue(const stringx& sXPath, const stringx& sAttributeName);

protected:
	bool LoadSettingNodes(XML::IXMLDOMNodeList* pNodeItemList, VEC_PROJECT_SETTINGS_ITEMS& vItems);
	static CComPtr<XML::IXMLDOMDocument2> OpenSettingsXml();


private:
	CComPtr<XML::IXMLDOMDocument2> m_spDoc;
	
};

#endif //IS_PROJECTSETTINGS_H
