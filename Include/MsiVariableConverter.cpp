#include "stdafx.h"
#include "MsiVariableConverter.h"

const char LBRACKET = L'[';
const char RBRACKET = L']';
const char NULL_TOKEN = L'~';
const stringx ESCAPE_TOKEN = L"[\\";

CMsiVariableConverter::CMsiVariableConverter(IsmAuto::IProjectRootLoyalty* pProjectRoot)
	: m_spProjectRoot(pProjectRoot)
{
	LoadDirectories();
	LoadProperties();
}

CMsiVariableConverter::~CMsiVariableConverter()
{

}

stringx CMsiVariableConverter::Convert(const stringx& s)
{
	stringx sResult;
	Convert(s,sResult);
	return sResult;
}

long CMsiVariableConverter::Convert(const stringx& s, stringx& sConverted)
{
	sConverted = s;

	std::vector<stringx> vecTokens;
	ExtractVariables(s, vecTokens);

	if (vecTokens.size() <=0)
	{
		return 0;
	}

	bool bHasUnresolvedToken = false;
	for(unsigned int i=0;i<vecTokens.size();i++)
	{
		stringx sConvertedVar = ConvertVariable(vecTokens[i]);
		if (sConvertedVar.empty())
		{
			bHasUnresolvedToken = true;
			continue;
		}
		
		stringx sToken;
		sToken.format(L"[%s]", vecTokens[i].c_str());
		sConverted.replace(sToken, sConvertedVar);
	}

	return (bHasUnresolvedToken)?-1:1;
}

// Search for a variable of form [xxx] starting from the nPos character
// The return value is a vector containing all of the variables
void CMsiVariableConverter::ExtractVariables(const stringx& s, std::vector<stringx>& vecTokens)
{
    if (s.length() < 3)
        return;

	int nEnd = -1;
	//find the first begin bracket
	int nStart = s.find(LBRACKET, 0);
	while(nStart != stringx::npos)
	{
		//ignore escaped begin brackets
		if(nStart < 2 || s.find(ESCAPE_TOKEN, nStart - 2) != nStart - 2)
		{				
			//don't pack bracketed items that are nulls
			if(s.find(NULL_TOKEN, nStart + 1) != nStart + 1)
			{
				nEnd = s.find(RBRACKET, nStart + 1);
				if (nEnd != stringx::npos)
				{
					//if escaped end bracket go to next end bracket
					if(s.find(ESCAPE_TOKEN, nEnd - 2) == nEnd - 2)
					{				
						nEnd = s.find(RBRACKET, nEnd + 1);
					}

					stringx sVar = s.substr(nStart+1, nEnd-nStart-1);
					vecTokens.push_back(sVar);			
					nStart = nEnd;					
				}
			}
		}
		//find the next begin bracket
		nStart = s.find(LBRACKET, nStart+1);
	}	
}


stringx CMsiVariableConverter::ConvertVariable(const stringx& sVar)
{
	stringx sReturn = L"";

	if(m_mapDirectories.find(sVar) != m_mapDirectories.end())
	{
		VARMAP::iterator it = m_mapDirectories.find(sVar);
		sReturn = it->second;		
		
		if (!sReturn.empty() && !sReturn.endswith(L"]"))
			sReturn.path_add_last_slash();
	}
	else if(m_mapProperties.find(sVar) != m_mapProperties.end())
	{
		VARMAP::iterator it = m_mapProperties.find(sVar);
		sReturn = it->second;		
	}
	else
	{
		sReturn = ConvertInstallerKey(sVar);
		sReturn = Convert(sReturn);
	}

	return sReturn;
}

stringx	CMsiVariableConverter::ConvertInstallerKey(const stringx& sValue)
{
//	BEGIN_METHOD(L"CMsiVariableConverter::ConvertInstallerKey");

	if(sValue.length()==0) return L"";

	if(sValue[0]=='#')
	{
		//long file key
		return GetFilePath(sValue.substr(1));		
	}
	else if(sValue[0]=='!')
	{
		//short file key
		stringx sShortName = GetFilePath(sValue.substr(1)).c_str();
		if(!sShortName.empty())
		{
			stringx sTemp = sShortName;
			sShortName.format(L"_Short(%s)", sTemp.c_str());
		}		
		return sShortName;		
	}
	else if(sValue[0]=='$')
	{
		//Component key
		return GetComponentPath(sValue.substr(1));		
	}
	else if(sValue[0]=='\\')
	{
		//Component key
		return sValue.substr(1,1);		
	}
	else if(sValue[0]=='%')
	{
		//Environment
		return GetEnvironmentValue(sValue.substr(1).c_str());
	}

//	END;

	return L"";
}

stringx CMsiVariableConverter::GetEnvironmentValue(const stringxi& sEnvKey)
{
	stringx sResult;

//	BEGIN_METHOD(L"CMsiVariableConverter::GetEnvironmentValue");

	//We can't do static resolution of environment variables
	//however, we can map some of them to folder variables that we can resolve

	if(sEnvKey == L"SystemRoot" || sEnvKey == L"WinDir")
		sResult = L"[WindowsFolder]";
	else if(sEnvKey == L"SystemDrive")
		sResult = L"[WindowsVolume]";
	else if(sEnvKey == L"SystemDirectory")
		sResult = L"[SystemFolder]";
	else if(sEnvKey == L"ComSpec")
		sResult = L"[SystemFolder]cmd.exe";
	else if(sEnvKey == L"ProgramFiles")
		sResult = L"[ProgramFilesFolder]";
	else if(sEnvKey == L"Temp" || sEnvKey == L"Tmp")
		sResult = L"[TempFolder]";
	else if(sEnvKey == L"allusersprofile")
		sResult = L"[ALLUSERSPROFILE]";
	else if(sEnvKey == L"CommonProgramFiles")
		sResult = L"[CommonFilesFolder]";
	else if(sEnvKey == L"APPDATA")
		sResult = L"[AppDataFolder]";
	
	//END;
	
	return sResult;
}

stringx CMsiVariableConverter::GetComponentPath(const stringx& sCompKey)
{
	stringx sResult = L"";

	//BEGIN_METHOD(L"CMsiVariableConverter::GetComponentPath");

	if (sCompKey.find(L'\'') != stringx::npos)
		return sResult;

	CComPtr<IsmAuto::IComponent> spComponent;
	hrx hr = m_spProjectRoot->GetComponentFromKey(NULL,sCompKey,&spComponent);

	if(spComponent)
	{
		CComPtr<IsmAuto::IComponent2> spComponent2 = is_com_cast<IsmAuto::IComponent2>(spComponent);
		CComPtr<IsmAuto::IDirectory2> spDirectory;
		hr = spComponent2->get_Directory(&spDirectory);
	
		hr = spDirectory->get_DisplayPathNoDirId(&sResult);

		if (!sResult.empty() && !sResult.is_last_char(L']'))
			 sResult.path_add_last_slash();
	}

	//END;
	
	return sResult;
}

stringx CMsiVariableConverter::GetFilePath(const stringx& sFileKey)
{
	stringx sResult = L"";

	//BEGIN_METHOD(L"CMsiVariableConverter::GetFilePath");

	if (sFileKey.find(L'\'') != stringx::npos)
		return sResult;

	CComPtr<IsmAuto::IFile> spFile;
	hrx hr = m_spProjectRoot->UtilGetIFileUsingFileKey(sFileKey,&spFile);

	if(spFile)
	{
		CComPtr<IsmAuto::IFileIndoreSP1> spFile2 = is_com_cast<IsmAuto::IFileIndoreSP1>(spFile);
		hrx hr = spFile2->get_DestinationPath(&sResult);

		stringx sLongFileName;
		hr = spFile2->get_LongName(&sLongFileName);

		if(sResult[sResult.length()-1] != L']' && sResult[sResult.length()-1] != L'\\')
		{
			sResult.append(L"\\");
		}
		
		sResult.append(sLongFileName);		
	}

	//END;

	return sResult;
}

stringx CMsiVariableConverter::GetDefaultDestination(bool bEndWithSlash)
{
	//BEGIN_METHOD(L"CMsiVariableConverter::GetDefaultDestination")

	if(m_sDefaultDestination.empty())
	{
		CComPtr<IsmAuto::IProduct> spProduct;
		hrx hr = m_spProjectRoot->get_ActiveProduct(&spProduct);
		if (SUCCEEDED(spProduct->get_DefaultDestination(&m_sDefaultDestination)))
		{
			// remove directory id...
			if(m_sDefaultDestination.is_first_char(L'{'))
			{
				stringx::size_type pos;
				if((pos = m_sDefaultDestination.find(L"}", 0)) != stringx::npos)
				{
					m_sDefaultDestination = m_sDefaultDestination.substr(pos+1);
					m_sDefaultDestination.trim();
				}
			}

			m_sDefaultDestinationWithSlash = m_sDefaultDestination;
			if (!m_sDefaultDestinationWithSlash.is_last_char(L'\\'))
				m_sDefaultDestinationWithSlash += L'\\';
		}
	}

	//END

	return bEndWithSlash ? m_sDefaultDestinationWithSlash : m_sDefaultDestination;
}


void CMsiVariableConverter::LoadDirectories()
{
	//BEGIN_METHOD(L"CMsiVariableConverter::LoadDirectories");

	CComPtr<IsmAuto::IDirectories> spDirectories;
	hrx hr = m_spProjectRoot->get_Directories(&spDirectories);

	enumerator<IsmAuto::IDirectories,IsmAuto::IDirectory> enumDirs(spDirectories);

	::OutputDebugString(_T("CMsiVariableConverter: Loading directories...\n"));

	CComPtr<IsmAuto::IDirectory> spDirectory;
	while(enumDirs.next(spDirectory))
	{
		CComPtr<IsmAuto::IDirectory2> spDirectory2 = is_com_cast<IsmAuto::IDirectory2>(spDirectory);
		stringx sId;
		hr = spDirectory2->get_Directory(&sId);
		stringx sParentId;
		hr = spDirectory2->get_Parent(&sParentId);

		if (sParentId.length() > 0)
			::OutputDebugString(sId + L"\n");
		else
		{
			::OutputDebugString(sId + L" - Ignored because its parent is null\n");
			continue;
		}

		sId.replace(L"[",L"");
		sId.replace(L"]",L"");

		stringx sPath;
		hr = spDirectory2->get_DisplayPathNoDirId(&sPath);
		if (sPath == L"[INSTALLDIR]")
			sPath = GetDefaultDestination();
		else if (sPath.find(L"[INSTALLDIR]") != stringx::npos)
			sPath.replace(L"[INSTALLDIR]", GetDefaultDestination(true));

		m_mapDirectories[sId] = sPath;
	}

	AddSpecialDirectories();

	//END;
}

void CMsiVariableConverter::AddSpecialDirectories()
{
	AddSpecialDirectory(L"AdminToolsFolder");
	AddSpecialDirectory(L"AppDataFolder");
	AddSpecialDirectory(L"CommonAppDataFolder");
	AddSpecialDirectory(L"CommonFilesFolder");
	AddSpecialDirectory(L"CommonFiles64Folder");
	AddSpecialDirectory(L"DesktopFolder");
	AddSpecialDirectory(L"FavoritesFolder");
	AddSpecialDirectory(L"FontsFolder");
	AddSpecialDirectory(L"LocalAppDataFolder");
	AddSpecialDirectory(L"MyPicturesFolder");
	AddSpecialDirectory(L"PersonalFolder");
	AddSpecialDirectory(L"PrimaryVolumePath");
	AddSpecialDirectory(L"ProgramFilesFolder");
	AddSpecialDirectory(L"ProgramFiles64Folder");
	AddSpecialDirectory(L"ProgramMenuFolder");
	AddSpecialDirectory(L"SendToFolder");
	AddSpecialDirectory(L"StartMenuFolder");
	AddSpecialDirectory(L"StartupFolder");
	AddSpecialDirectory(L"System16Folder");
	AddSpecialDirectory(L"SystemFolder");
	AddSpecialDirectory(L"System64Folder");
	AddSpecialDirectory(L"TempFolder");
	AddSpecialDirectory(L"TemplateFolder");
	AddSpecialDirectory(L"WindowsFolder");
	AddSpecialDirectory(L"WindowsVolume");
}

void CMsiVariableConverter::AddSpecialDirectory(const stringx& sDir)
{
	if (m_mapDirectories.find(sDir) == m_mapDirectories.end())
	{
		stringx sFormattedDir;
		sFormattedDir.format(L"[%s]", sDir.c_str());
		m_mapDirectories[sDir] = sFormattedDir;
	}
}

void CMsiVariableConverter::LoadProperties()
{
	//BEGIN_METHOD(L"CMsiVariableConverter::LoadProperties");

	CComPtr<IsmAuto::IProperties> spProperties;
	hrx hr = m_spProjectRoot->get_Properties(&spProperties);

	enumerator<IsmAuto::IProperties,IsmAuto::IProperty> enumProps(spProperties);

	CComPtr<IsmAuto::IProperty> spProperty;
	while(enumProps.next(spProperty))
	{
		stringx sName;
		hr = spProperty->get_Name(&sName);

		stringx sValue;
		hr = spProperty->get_Value(&sValue);

		m_mapProperties[sName.c_str()] = sValue;
	}	
	
	//LoadDefaultProperties();

	//END;
}
/*
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	LoadDefaultProperties
//		Makes sure that there is at least a default value for certain properties that are specified in Msi.xml
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CMsiVariableConverter::LoadDefaultProperties()
{
	stringx configXml;
	GetModuleFileName(_AtlBaseModule.GetModuleInstance(), configXml.get_buffer(MAX_PATH), MAX_PATH);
	configXml = configXml.path_dir() ^ L"Msi.xml";
	
	CComPtr<XML::IXMLDOMDocument2> spDoc;
	if (!SUCCEEDED(MSXMLWrapper::CreateXmlDocFromFile(configXml.c_str(), &spDoc)))
		return;
	
	CComPtr<XML::IXMLDOMNode> spDefaultPropertyValuesNode;
	spDoc->selectSingleNode(L"//VirtualSettings/Converter/PropertyDefaults", &spDefaultPropertyValuesNode);
	if (!spDefaultPropertyValuesNode)
		return;
	
	CComPtr<XML::IXMLDOMNodeList> spPropNodeList;
	spDefaultPropertyValuesNode->get_childNodes(&spPropNodeList);
	if (!spPropNodeList)
		return;

	long propNodeCount;
	spPropNodeList->get_length(&propNodeCount);
	
	for (long i = 0; i < propNodeCount; i++)
	{
		CComPtr<XML::IXMLDOMNode> spPropNode;
		spPropNodeList->get_item(i, &spPropNode);
		if (!spPropNode)
			return;
		
		CComPtr<XML::IXMLDOMNamedNodeMap> spAttributes;
		spPropNode->get_attributes(&spAttributes);
		if (!spAttributes)
			return;
		
		stringx propName = GetAssemblyIdentityAttribute(spAttributes, L"name");
		stringx propValue = GetAssemblyIdentityAttribute(spAttributes, L"value");
		
		if(!propName.empty() && m_mapProperties.find(propName) == m_mapProperties.end())
			m_mapProperties[propName.c_str()] = propValue;
	}
}
*/