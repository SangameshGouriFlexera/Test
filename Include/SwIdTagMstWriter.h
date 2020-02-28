#pragma once

#include "stringx.h"
#include "IsmAutoWrapper.h"

enum TagConsumer
{
	eApplicationManager,
	eRepackager
};


class CSwIdTagMstWriter 
{
public:
 	CSwIdTagMstWriter(const stringxi& sTagFilesFolder, const stringxi& sMsiFile); 
	CSwIdTagMstWriter(const stringxi& sTagFilesFolder, const stringxi& sMsiFile, const std::vector<stringxi>& vecMstFiles, const stringxi& sOutputFolder, TagConsumer eTagConsumer, std::vector<stringx>& vecExistingTagFileKeys);
	bool Create();
		
protected:
	stringxi GetSwIdMstTemplate();
	bool OpenMst();
	bool AddTagFiles();
	bool AddProperties();
	bool SaveMst();
	void SetMSIProperty(const stringx& sPropName, const stringx& sPropValue);
	stringx GetMsiProperty(const stringx& sName);
	CComPtr<IsmAuto::IComponent2> AddComponent(const stringx& sName, CComPtr<IsmAuto::IDirectory2> spDir2, const stringx& sCondition, const stringx& sFeature);
	void AddFileToComponent(CComPtr<IsmAuto::IComponent2> spComp, const stringxi& sFile);
	stringx AddFileToBinaryTable(const stringxi& sFile, const stringx& sRequestedKey);
	CComPtr<IsmAuto::IDirectory2> GetMainInstallDir();
	CComPtr<IsmAuto::IDirectory2> GetDirByDirId(stringx sDirId);
	CComPtr<IsmAuto::IDirectory2> AddCommonAppDataFolderDir();
	CComPtr<IsmAuto::IDirectory2> AddChildDir(const stringx& sRequestedDirId, const stringx& sDefaultDir, CComPtr<IsmAuto::IDirectory2> spParentDir2);
	bool RemoveExistingTags();
	bool GetRegKeyValue(LPCTSTR lpszKeyName, LPCTSTR lpszValueName, LPCTSTR lpszDefaultValue, CString& strValue, HKEY key);
	bool GetProductFolder(CString& strProductLocation);
	bool GetRepackagerFolder(CString& strLocation);
	void CleanupTempFolders();
	stringxi m_sMsiFile;
	stringxi m_sOutputFolder;
	stringxi m_sIsSysFolder;
	std::vector<stringxi> m_vecTagFiles;
	std::vector<stringxi> m_vecMstFiles;
	TagConsumer m_eTagConsumer;
	std::vector<stringx> m_vecExistingTagFileKeys;

	CComPtr<IsmAuto::IProject> m_spProject;
	CComPtr<IsmAuto::IProjectRoot> m_spProjectRoot;
	CComPtr<IsmAuto::IProduct> m_spProduct;
};
