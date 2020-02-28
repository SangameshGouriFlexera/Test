//////////////////////////////////////////////////////////////////////

// SwIdTagMstWriter.cpp
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "iscomutils.h"
#include "SwIdTag.h"
#include "SwIdTagUtils.h"
#include "SwIdTagMstWriter.h"
#include "CurrentFolderHelper.h"
#include "..\repackager\islc\LocalInforepack.h"
//#include "MsiVariableConverter.h"

//Using 0xFFFFFFFF since winbase.h of VC6 does not have INVALID_FILE_ATTRIBUTES defined
#ifndef INVALID_FILE_ATTRIBUTES
#define INVALID_FILE_ATTRIBUTES 0xFFFFFFFF 
#endif

#include "AdminStudio_RegLocations.h"
#include "AppRegKey.h"

using namespace AdmRegLocations;

bool CSwIdTagMstWriter::GetRegKeyValue(LPCTSTR lpszKeyName, LPCTSTR lpszValueName, LPCTSTR lpszDefaultValue, CString& strValue, HKEY key)
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

bool CSwIdTagMstWriter::GetRepackagerFolder(CString& strLocation)
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

bool CSwIdTagMstWriter::GetProductFolder(CString& strProductLocation)
{
	bool bRc = true;
	static CString _strProductLocation;
	if( _strProductLocation.IsEmpty() )
		bRc = GetRegKeyValue(AdmRegLocations::g_lpszHKLMMainSettingsKey, AdmRegLocations::g_lpszProductLocation, _T(""), _strProductLocation, HKEY_LOCAL_MACHINE);
	strProductLocation = _strProductLocation;
	return bRc;
}




// #import "..\..\..\DeveloperBinaries\ISWIBuild.tlb" \
// 	named_guids no_implementation raw_interfaces_only \
// 	rename_namespace("IsmBuild")

//had to redefine bool because otherwise the generated TLH for ismsientity.dll would not compile
#define bool boolean
#import "..\..\..\DeveloperBinaries\ISMsiEntity.dll" \
	named_guids no_implementation raw_interfaces_only no_auto_exclude\
  	rename_namespace("ISMsiEntity")\
 	rename("tag_inner_PROPVARIANT", "tag_inner_PROPVARIANT_2")
#undef bool

// #import "..\..\..\DeveloperBinaries\isupgrade.dll" \
// 	named_guids no_implementation raw_interfaces_only 

//#import "..\..\..\DeveloperBinaries\IsAppServices.dll" named_guids no_implementation raw_interfaces_only

#define STANDALONE
#include "AsCoCreateInProc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


CSwIdTagMstWriter::CSwIdTagMstWriter(const stringxi& sTagFilesFolder, const stringxi& sMsiFile)
{
	m_eTagConsumer = eRepackager;
	m_sMsiFile = sMsiFile;
	m_sOutputFolder = sMsiFile.path_dir();
	m_vecTagFiles = SwIdTagUtils::GetExistingSwIdTagFiles(sTagFilesFolder);
	
}

CSwIdTagMstWriter::CSwIdTagMstWriter(const stringxi& sTagFilesFolder, const stringxi& sMsiFile, const std::vector<stringxi>& vecMstFiles, const stringxi& sOutputFolder, TagConsumer eConsumer, std::vector<stringx>& vecExistingTagFileKeys)
{
	m_vecExistingTagFileKeys = vecExistingTagFileKeys;
	m_eTagConsumer = eConsumer;
	m_sMsiFile = sMsiFile;
	m_sOutputFolder = sOutputFolder;
	m_vecMstFiles = vecMstFiles;
	m_vecTagFiles = SwIdTagUtils::GetExistingSwIdTagFiles(sTagFilesFolder);
}

bool CSwIdTagMstWriter::Create()
{
	if (!::PathFileExists(m_sMsiFile))
		return true;

	if (m_vecTagFiles.size() == 0)
	{
	#ifdef INCLIB
 		CString msg;
 		msg.Format(IDS_MSG_SWIDTAG_NOTAGSPRESENT);
 		ApiHandler::RaiseEvent(EventMessage(EventMessage::Type::info, msg));
	#endif

		return true;
	}

	//in the Application Manager case we know all tag files will be included
	if (eRepackager == m_eTagConsumer)
	{
		bool bGenerateAtLeastOneTag = false;
		std::vector<stringxi>::iterator tagFileIter = m_vecTagFiles.begin();
		for (; tagFileIter != m_vecTagFiles.end(); ++ tagFileIter)
		{
			CSwIdTag tag(*tagFileIter);
			bGenerateAtLeastOneTag |= tag.GetGenerateTag();
			if (bGenerateAtLeastOneTag)
				break;
		}

		if (!bGenerateAtLeastOneTag)
		{
		#ifdef INCLIB
	 		CString msg;
	 		msg.Format(IDS_MSG_SWIDTAG_NOTAGSSELECTED);
	 		ApiHandler::RaiseEvent(EventMessage(EventMessage::Type::info, msg));
		#endif

			return true;
		}
	}

	stringxi sModuleFile;
	GetModuleFileName(NULL, sModuleFile.get_buffer(MAX_PATH), MAX_PATH);
	
	//This location is valid in debug builds or if Repackager is running
	stringxi sCandidate1 = sModuleFile.path_dir() ^ L"System";
	//This location is valid if Application Manager is running
	stringxi sCandidate2 = sModuleFile.path_dir().path_dir() ^ L"Repackager\\System";
	//This location is valid if AdminStudio.exe is running (only possible if new catalog is created with AdminStudio.exe with the option
	//to import sample packages - fringe case
	stringxi sCandidate3 = sModuleFile.path_dir() ^ L"Repackager\\System";
	
	//This location can be valid if an external executable invokes this such as powershell
	CString strCandidate4;
	GetRepackagerFolder(strCandidate4);
	stringxi sCandidate4 = stringxi(strCandidate4) ^ L"System";
	//This location can be valid if an external executable invokes this such as powershell in debug mode
	CString strCandidate5;
	GetProductFolder(strCandidate5);
	stringxi sCandidate5 = stringxi(strCandidate5) ^ L"System";

	if (::PathFileExists(sCandidate1 ^ L"ismsientity.dll"))
		m_sIsSysFolder = sCandidate1;
	else if (::PathFileExists(sCandidate2 ^ L"ismsientity.dll"))
		m_sIsSysFolder = sCandidate2;
	else if (::PathFileExists(sCandidate3 ^ L"ismsientity.dll"))
		m_sIsSysFolder = sCandidate3;
	else if (::PathFileExists(sCandidate4 ^ L"ismsientity.dll"))
		m_sIsSysFolder = sCandidate4;
	else if (::PathFileExists(sCandidate5 ^ L"ismsientity.dll"))
		m_sIsSysFolder = sCandidate5;
	else if (::PathFileExists(sCandidate5 ^ L"System\\ismsientity.dll"))
		m_sIsSysFolder = sCandidate5 ^ L"System";
	else
		//this is a fall back for some debug environments
		m_sIsSysFolder = sModuleFile.path_dir();

	CDllDirectoryHelper dllDriectory;
	dllDriectory.SetDllDirectory(m_sIsSysFolder);
	
	bool bRet = OpenMst() && AddTagFiles() && AddProperties() && RemoveExistingTags() && SaveMst();
	
	m_spProject = NULL;
	m_spProjectRoot = NULL;
	m_spProduct = NULL;
	
	CleanupTempFolders();

	return bRet;
}

//---------------------------------------------------------------------------------------
//	GetSwIdMstTemplate
//		The template file is located in the Repackager System folder.
//		Since this code is shared between Application Manager and Repackager, we need
//		to check the running binary name and use the appropriate relative path to get to
//		the transform file.
//		Note
//---------------------------------------------------------------------------------------
stringxi CSwIdTagMstWriter::GetSwIdMstTemplate()
{
	stringxi sModuleFile;
	GetModuleFileName(NULL, sModuleFile.get_buffer(MAX_PATH), MAX_PATH);

	//This location is valid in debug builds or if Repackager is running
	stringxi sCandidate1 = sModuleFile.path_dir() ^ L"SwIdTagTemplate.Mst";
	//This location is valid if Application Manager is running
	stringxi sCandidate2 = sModuleFile.path_dir().path_dir() ^ L"Repackager\\SwIdTagTemplate.Mst";
	//This location is valid if AdminStudio.exe is running (only possible if new catalog is created with AdminStudio.exe with the option
	//to import sample packages - fringe case
	stringxi sCandidate3 = sModuleFile.path_dir() ^ L"Repackager\\SwIdTagTemplate.Mst";
	//This location may be valid in some debug builds
	stringxi sCandidate4 = sModuleFile.path_dir().path_dir() ^ L"Source\\Repackager\\Wizard\\System\\SwIdTagTemplate.Mst";
	
	//This location can be valid if an external executable invokes this such as powershell
	CString strCandidate5;
	GetRepackagerFolder(strCandidate5);
	stringxi sCandidate5 = stringxi(strCandidate5) ^ L"SwIdTagTemplate.Mst";
	//This location can be valid if an external executable invokes this such as powershell in debug mode
	CString strCandidate6;
	GetProductFolder(strCandidate6);
	stringxi sCandidate6 = stringxi(strCandidate6) ^ L"System\\SwIdTagTemplate.Mst";

	if (::PathFileExists(sCandidate1))
		return sCandidate1;
	else if (::PathFileExists(sCandidate2))
		return sCandidate2;
	else if (::PathFileExists(sCandidate3))
		return sCandidate3;
	else if (::PathFileExists(sCandidate4))
		return sCandidate4;
	else if (::PathFileExists(sCandidate5))
		return sCandidate5;
	else if (::PathFileExists(sCandidate6))
		return sCandidate6;
	else
		return stringxi(L"");
}

bool CSwIdTagMstWriter::OpenMst()
{
#ifdef INCLIB
 	CString msg;
 	msg.Format(IDS_MSG_SWIDTAG_OPENINGTRANSFORM);
 	ApiHandler::RaiseEvent(EventMessage(EventMessage::Type::info, msg));
#endif

	stringxi sMstTemplate = GetSwIdMstTemplate();
	if (sMstTemplate.empty())
		return false;

	stringxi sMst = m_sOutputFolder ^ m_sMsiFile.path_find_file_name_no_ext() + L"_SoftwareId.mst";
	::DeleteFile(sMst);
	if (::PathFileExists(sMst))
	{
	#ifdef INCLIB
 		CString msg;
 		msg.Format(IDS_MSG_ERR_SWIDTAG_CANTDELETEOLDMST, static_cast<LPCTSTR>(sMst));
 		ApiHandler::RaiseEvent(EventMessage(EventMessage::Type::error, msg));
	#endif

		return false;
	}

	::CopyFile(sMstTemplate, sMst, false);

	// getting rid of read-only status (only applies to some debug environments)
	DWORD dwAttrs = ::GetFileAttributes(sMst);
	if (dwAttrs != INVALID_FILE_ATTRIBUTES && dwAttrs & FILE_ATTRIBUTE_READONLY)
		::SetFileAttributes(sMst, dwAttrs & !FILE_ATTRIBUTE_READONLY);

	HRESULT hr = ASCoCreateInstance(m_sIsSysFolder.as_stringx() ^ L"IsMsiEntity.dll", ISMsiEntity::CLSID_IsmAutoProject, &m_spProject, false);
	if (FAILED(hr))
	{
	#ifdef INCLIB
 		CString msg;
 		msg.Format(IDS_MSG_ERR_SWIDTAG_UNABLETOLOADISMSIENTITY, hr);
 		ApiHandler::RaiseEvent(EventMessage(EventMessage::Type::error, msg));
	#endif

		return false;
	}

 	/*
	We will not open the existing transforms into the overall MSI transformed view because then the changes
	in the existing transforms will also get saved into the software id tag transform
	stringx sExistingTransforms;
	std::vector<stringxi>::iterator existingMstIter = m_vecMstFiles.begin();
	for (; existingMstIter != m_vecMstFiles.end(); ++existingMstIter)
	{
		if (!existingMstIter->endswith(L"_SoftwareId.mst"))
			sExistingTransforms += existingMstIter->as_stringx() + L"|";
	}
	sExistingTransforms.trim(L"|");
	*/

	CComPtr<IsmAuto::IProject2> spProject2;
	spProject2 = com_cast<IsmAuto::IProject2>(m_spProject);

	if (FAILED(spProject2->OpenNoVal(sMst, VARIANT_FALSE, m_sMsiFile, L"", &m_spProjectRoot)))
	{
	#ifdef INCLIB
 		CString msg;
 		msg.Format(IDS_MSG_ERR_SWIDTAG_FAILEDTOOPENMST, static_cast<LPCTSTR>(sMst));
 		ApiHandler::RaiseEvent(EventMessage(EventMessage::Type::error, msg));
	#endif

		return false;
	}

	m_spProjectRoot->get_ActiveProduct(&m_spProduct);

	return true;
}

CComPtr<IsmAuto::IDirectory2> CSwIdTagMstWriter::AddChildDir(const stringx& sRequestedDirId, const stringx& sDefaultDir, CComPtr<IsmAuto::IDirectory2> spParentDir2)
{
	CComPtr<IsmAuto::IBusinessObject> spBusDir;
	hrx hr = spParentDir2->AddChild(IsmAuto::edcDirectory, sRequestedDirId, CDefaultVariant(), &spBusDir);
	CComQIPtr<IsmAuto::IDirectory2> spChildDir2(spBusDir);
	hr = spChildDir2->put_DefaultDir(sDefaultDir);
	return spChildDir2;
}

CComPtr<IsmAuto::IDirectory2> CSwIdTagMstWriter::AddCommonAppDataFolderDir()
{
	CComPtr<IsmAuto::IDirectory2> spCommonAppDataFolder2 = GetDirByDirId(L"CommonAppDataFolder");
	if (spCommonAppDataFolder2)
		return spCommonAppDataFolder2;
	
	CComQIPtr<IsmAuto::IProjectRoot2> spProjectRoot2(m_spProjectRoot);
	CComPtr<IsmAuto::IDirectory> spTargetDir;
	hrx hr = spProjectRoot2->get_TARGETDIR(&spTargetDir);
	CComQIPtr<IsmAuto::IDirectory2> spTargetDir2(spTargetDir);
	ASSERT(spTargetDir2);
	
	CComPtr<IsmAuto::IBusinessObject> spBusDir;
	hr = spTargetDir2->AddChild(IsmAuto::edcDirectory, CComBSTR(L"CommonAppDataFolder"), CDefaultVariant(), &spBusDir);
	
	CComQIPtr<IsmAuto::IDirectory2> spDir2(spBusDir);
	hr = spDir2->put_DefaultDir(CComBSTR(L".:Common~1|CommonAppData"));
	hr = spDir2->put_RealName(CComBSTR(L"CommonAppDataFolder"));
	
	return spDir2;
}

CComPtr<IsmAuto::IComponent2> CSwIdTagMstWriter::AddComponent(const stringx& sName, CComPtr<IsmAuto::IDirectory2> spDir2, const stringx& sCondition, const stringx& sFeature)
{
	if (!spDir2)
		return NULL;

	CComPtr<IsmAuto::IFeatures> spFeatures;
	hrx hr = m_spProduct->get_Features(&spFeatures);

	//Get existing parent feature from MST template that will hold software tags
	CComPtr<IsmAuto::IFeature> spFeature;
	hr = spFeatures->get_Item(sFeature, &spFeature);
	if (!spFeature)
		return NULL;

	//Create component
	CComPtr<IsmAuto::IBusinessObject> spBus;
	hr = spFeature->AddChild(IsmAuto::efcComponent, sName, CComVariant(), &spBus);
	CComQIPtr<IsmAuto::IComponent2> spComp2(spBus);
	hr = spComp2->put_Condition(sCondition);
	hr = spComp2->put_Directory(spDir2);

	return spComp2;
}

void CSwIdTagMstWriter::AddFileToComponent(CComPtr<IsmAuto::IComponent2> spComp, const stringxi& sFile)
{
	if (!spComp)
		return;

	CComPtr <IsmAuto::IFileHeader> spFileHeader;
	hrx hr = spComp->get_FileHeader(&spFileHeader);

	CComPtr<IsmAuto::IBusinessObject> spBus;
	spFileHeader->AddFile(sFile, CComVariant(sFile.path_file().c_str()), &spBus);

	CComQIPtr<IsmAuto::IFile2> spFile2(spBus);
	spFile2->put_CompressionType(IsmAuto::efctCompressed);
}

CComPtr<IsmAuto::IDirectory2> CSwIdTagMstWriter::GetDirByDirId(stringx sDirId)
{
	//If INSTALLDIR exists, then assume it is main install folder and return its directory object
	CComPtr<IsmAuto::IDirectories> spDirectories;
	hrx hr = m_spProjectRoot->get_Directories(&spDirectories);
	CComPtr<IsmAuto::IDirectory> spDir;
	spDirectories->get_Item(sDirId, &spDir);
	if (spDir)
	{
		CComQIPtr<IsmAuto::IDirectory2> spDir2(spDir);
		return spDir2;
	}
	else
		return NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	GetMainInstallDir
//		In InstallShield created MSI packages the INSTALLDIR folder is the main installation directory.
//		However, in vendor MSI packages INSTALLDIR may not even exist. When INSTALLDIR does not exist,
//		we will try to guess the main install folder by examining shortcuts in the package.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

CComPtr<IsmAuto::IDirectory2> CSwIdTagMstWriter::GetMainInstallDir()
{
	CComQIPtr<IsmAuto::IProjectRootLoyalty> spProjectRootLoyalty(m_spProjectRoot);
	if (!spProjectRootLoyalty)
		return NULL;

	CComPtr<IsmAuto::IDirectory2> spDir2 = GetDirByDirId(L"INSTALLDIR");
	if (spDir2)
		return spDir2;
	
	//Check shortcut targets
	//std::vector<stringxi> vecShortcutTargets;
	

	//CMsiVariableConverter oMsiVariableConverter(spProjectRootLoyalty);

	CComPtr<IsmAuto::IShortcuts> spShortcuts;
	hrx hr = spProjectRootLoyalty->get_Shortcuts(&spShortcuts);
	enumerator<IsmAuto::IShortcuts, IsmAuto::IShortcutL> ShortcutEnum(spShortcuts);
	CComPtr<IsmAuto::IShortcutL> spShortcut;
	while (ShortcutEnum.next(spShortcut))
	{
		stringx sCompDirId;
		CComPtr<IsmAuto::IComponent> spComponent;
		hr = spShortcut->get_ComponentObj(&spComponent);

		CComQIPtr<IsmAuto::IComponent2> spComponent2(spComponent);
		CComPtr<IsmAuto::IDirectory2> spDirectory;
		hr = spComponent2->get_Directory(&spDirectory);
		return spDirectory;
		//spDirectory->get_Name(&sCompDirId);
/*
		stringx sTarget;
		VARIANT_BOOL vbIsAdvertised;
		hr = spShortcut->get_IsAdvertised(&vbIsAdvertised);
		if (vbIsAdvertised)
		{
			//For advertised shortcuts, get the component key and resolve that path
			//this is going to be the shortcut target
			CComPtr<IsmAuto::IComponent> spComponent;
			hr = spShortcut->get_ComponentObj(&spComponent);

			stringx sKeyPath;
			hr = spComponent->get_KeyPath(&sKeyPath);

			hr = spProjectRootLoyalty->UtilGetPathFromFileKey(sKeyPath, (IsmAuto::EnumPathType)2, &sTarget);			
		}
		else
		{
			hr = spShortcut->get_Target(&sTarget);
		}

		stringx sResolvedTarget;
		long retVal = oMsiVariableConverter.Convert(sTarget, sResolvedTarget);
		vecShortcutTargets.push_back(sTarget.as_stringxi());
		*/
	}
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	AddTagFiles
//		Creates two components in the MST:
//			-SwIdTagInstalldir - installs to INSTALLDIR or to best guess INSTALLDIR
//			-SwIdTagGlobal_<sw creator regid> 
//				- installs to %AllUsersProfile%\Application Data\<software creator regid>\ on pre-Vista
//				- installs to %Program Data%\<software creator regid>\ on Vista and newer
////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool CSwIdTagMstWriter::AddTagFiles()
{
#ifdef INCLIB
 	CString msg;
 	msg.Format(IDS_MSG_SWIDTAG_ADDINGFILES);
 	ApiHandler::RaiseEvent(EventMessage(EventMessage::Type::info, msg));
#endif
	CComPtr<IsmAuto::IDirectory2> spInstallDir = GetMainInstallDir();
	CComPtr<IsmAuto::IComponent2> spCompInstalldir;
	//There is a possibility that we can't figure out the main installdir
	//in this case don't install the tag to the installdir
	if (spInstallDir)
		spCompInstalldir = AddComponent(L"SwIdTagInstalldir", spInstallDir, L"", L"SoftwareIdTag");

	//this map has component entity objects for the global swidtag install location corresponding to each tag
	std::map<stringxi, CComPtr<IsmAuto::IComponent2> > mapSwCreatorToGlobalComp2;
	
	std::vector<stringxi>::iterator tagFileIter = m_vecTagFiles.begin();
	for (; tagFileIter != m_vecTagFiles.end(); ++tagFileIter)
	{
		CSwIdTag tag(*tagFileIter);
		stringxi swCreatorRegId = tag.GetSwCreatorRegId().as_stringxi();
		if (tag.GetGenerateTag() && mapSwCreatorToGlobalComp2.find(swCreatorRegId) == mapSwCreatorToGlobalComp2.end())
		{
			stringxi sSwCreatorRegIdDefaultDir = swCreatorRegId;
			if (sSwCreatorRegIdDefaultDir.length() > 8)
			{
				stringxi sShort(sSwCreatorRegIdDefaultDir);
				sShort.replace_all(L" ", L"");
				sShort.replace_all(L",", L"");
				sShort.replace_all(L".", L"");
				sShort.to_upper();
				sSwCreatorRegIdDefaultDir = sShort.substr(0, 6) + L"~1|" + sSwCreatorRegIdDefaultDir;
			}
		
			CComPtr<IsmAuto::IDirectory2> spGlobalDir2 = AddChildDir(swCreatorRegId.as_stringx(), sSwCreatorRegIdDefaultDir.as_stringx(), AddCommonAppDataFolderDir());
			stringx sCompName = L"SwIdTagGlobal_" + swCreatorRegId.as_stringx();
			sCompName.replace_all(L"-", L"");
			mapSwCreatorToGlobalComp2[swCreatorRegId] = AddComponent(sCompName, spGlobalDir2, L"", L"SoftwareIdTag");
			if (!mapSwCreatorToGlobalComp2[swCreatorRegId])
				return false;
		}
	}

	stringx sBinTableEntries = L"";
	int i = 0;
	//For each tag that should be included in the install, add it to the three associated components	
	for (tagFileIter = m_vecTagFiles.begin(); tagFileIter != m_vecTagFiles.end(); ++tagFileIter)
	{
		CSwIdTag tag(*tagFileIter);
		stringxi swCreatorRegId = tag.GetSwCreatorRegId().as_stringxi();
		
		if (eApplicationManager == m_eTagConsumer || tag.GetGenerateTag())
		{
		#ifdef INCLIB
 			CString msg;
 			msg.Format(IDS_MSG_SWIDTAG_ADDINGFILE, static_cast<LPCTSTR>(*tagFileIter));
 			ApiHandler::RaiseEvent(EventMessage(EventMessage::Type::info, msg));
		#endif

			//no need to update/put ARP info in the tag in Application Manager case because
			//tag already contains the correct ARP info
			if (eRepackager == m_eTagConsumer)
			{
				//put current ARP information in tag files
				tag.PutCurArpInfo(GetMsiProperty(L"ProductCode").remove_braces(), GetMsiProperty(L"Manufacturer"), GetMsiProperty(L"ProductName"), GetMsiProperty(L"ProductVersion"));
				tag.Save();
			}
			
			AddFileToComponent(spCompInstalldir, *tagFileIter);
 			AddFileToComponent(mapSwCreatorToGlobalComp2[swCreatorRegId], *tagFileIter);
			sBinTableEntries += AddFileToBinaryTable(*tagFileIter, L"SoftwareIdTag_" + stringx(++i) + L".swidtag") + L";";
		}
	}
	if (!sBinTableEntries.empty())
		SetMSIProperty(L"AS_SWIDTAG_BIN_TBL_ENTRIES", sBinTableEntries);

	return true;	
}

bool CSwIdTagMstWriter::AddProperties()
{
	//SetMSIProperty(_T("AJAYTEST"), _T("INMST"));
	return true;
}

bool CSwIdTagMstWriter::SaveMst()
{
	stringxi sMst = m_sOutputFolder ^ m_sMsiFile.path_find_file_name_no_ext() + L"_SoftwareId.mst";
	
	m_spProject->Save(sMst, VARIANT_FALSE);
	m_spProject->Close();
	return true;
}

void CSwIdTagMstWriter::SetMSIProperty(const stringx& sPropName, const stringx& sPropValue)
{
	CComQIPtr<IsmAuto::IProjectRoot2> spRoot2(m_spProjectRoot);
	
	CComPtr<IsmAuto::IProperties> spProps;
	spRoot2->get_Properties(&spProps);
	
	CComPtr<IsmAuto::IProperty> spProp;
	spProps->get_Item(sPropName, &spProp);
	if (!spProp)
	{
		CComPtr<IsmAuto::IBusinessObject> spObj;
		spRoot2->AddChild(IsmAuto::eprcProperty, sPropName, CDefaultVariant(), &spObj);
		spProp = com_cast<IsmAuto::IProperty>(spObj);
	}
	
	ASSERT(spProp);
	spProp->put_Value(sPropValue);
}

stringx CSwIdTagMstWriter::GetMsiProperty(const stringx& sPropName)
{
	CComQIPtr<IsmAuto::IProjectRoot2> spRoot2(m_spProjectRoot);
	
	CComPtr<IsmAuto::IProperties> spProps;
	spRoot2->get_Properties(&spProps);
	
	CComPtr<IsmAuto::IProperty> spProp;
	spProps->get_Item(sPropName, &spProp);
	if (!spProp)
		return L"";
	
	stringx sPropVal;
	spProp->get_Value(&sPropVal);
	return sPropVal;
}

//inputs - sFile = full file path of file to be streamed into Binary table (expecting a tag file)
//		 - sRequestedKey = requested key name for the record to be inserted into the Binary table
//outputs - Actual key name of the newly inserted record
stringx CSwIdTagMstWriter::AddFileToBinaryTable(const stringxi& sFile, const stringx& sRequestedKey)
{
	CComPtr<IsmAuto::IBusinessObject> spBusObj;

	//TODO - there is a possibility that a Binary table record with this name already exists!
	m_spProjectRoot->AddChild(IsmAuto::eprcBinary, sRequestedKey, CDefaultVariant(), &spBusObj);

	if (!spBusObj)
		return L"";

	CComQIPtr<IsmAuto::IBinary> spBinary(spBusObj);
	ASSERT(spBinary);

	if (!spBinary)
		return L"";
	
	spBinary->put_Value(sFile);

	return sRequestedKey;
}

bool CSwIdTagMstWriter::RemoveExistingTags()
{
	CComQIPtr<IsmAuto::IProjectRootLoyalty> spProjectRootLoyalty(m_spProjectRoot);

	std::vector<stringx>::iterator tagFileKeyIter = m_vecExistingTagFileKeys.begin();
	for (; tagFileKeyIter != m_vecExistingTagFileKeys.end(); ++tagFileKeyIter)
	{
		CComPtr<IsmAuto::IFile> spFile;
		hrx hr = spProjectRootLoyalty->UtilGetIFileUsingFileKey(*tagFileKeyIter, &spFile);

		ASSERT(spFile);
		if(!spFile)
			continue;

		CComQIPtr<IsmAuto::IFileNeptune> spFileNeptune(spFile);
		ASSERT(spFileNeptune);
		if (!spFileNeptune)
			continue;

		CComPtr<IsmAuto::IComponent2> spComp2;
		spFileNeptune->get_Component(&spComp2);
		ASSERT(spComp2);

		stringx sKeyPath;
		spComp2->get_KeyPath(&sKeyPath);
		if (sKeyPath == *tagFileKeyIter)
			spComp2->put_KeyPath(L"");

		//this does a deep delete - basically file key references in other tables are removed
		is_com_cast<IsmAuto::IBusinessObject>(spFile)->Delete();
	}
	
	return true;
}

//These folders are created when InstallShield opens the software tag template transform
//against the MSI package.
void CSwIdTagMstWriter::CleanupTempFolders()
{
	stringx sTempFolder;
	if (0 == ::GetTempPath(MAX_PATH, sTempFolder.get_buffer(MAX_PATH)))
		return;

	stringx sFolderMask = L"isi*";
	WIN32_FIND_DATAW FindFileData;
	HANDLE hSearch = ::FindFirstFileW(sTempFolder ^ sFolderMask, &FindFileData);
	if (hSearch != INVALID_HANDLE_VALUE)
	{
		do
		{
			if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				&& stringx(FindFileData.cFileName).length() == 7)
			{
				//will only remove empty directories, which is what we need
				::RemoveDirectory(sTempFolder ^ FindFileData.cFileName);
			}
		} while (::FindNextFileW(hSearch, &FindFileData));
	}
	::FindClose(hSearch);
}