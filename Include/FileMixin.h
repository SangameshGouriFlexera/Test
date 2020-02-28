#ifndef __CFileMixin_H_
#define __CFileMixin_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace BuildEntity
{
	const int msidbFileISAttributesUseSystemSettings = 1;
	const int msidbFileISAttributesISDotNetFile = 2;
	const int msidbFileISAttributesOverrideAttributes = 4;
	const int msidbFileISAttributesOverrideSize = 8;
	const int msidbFileISAttributesOverrideVersion = 16;
	const int msidbFileISAttributesOverrideLanguage = 32;
	const int msidbFileISAttributesNoFileHash = 64;
};

class CFileMixin
{
public:
    CFileMixin();
    virtual void LoadSystemSettings(const stringx& bstrFullPathName,const int iFilter= BuildEntity::msidbFileISAttributesUseSystemSettings);
    virtual void LoadSystemSettingsFromFindData(const stringx& bstrFullPathName,
        const WIN32_FIND_DATA* pFindData,const int iFilter = BuildEntity::msidbFileISAttributesUseSystemSettings);
    virtual void LoadModified(const stringx& bstrFullPathName);

	virtual void LoadSystemFileSizeSettings(const stringx& bstrFullPathName, const int iFilter = BuildEntity::msidbFileISAttributesUseSystemSettings);
	virtual void LoadSystemVersionSettings(const stringx& bstrFullPathName, const int iFilter = BuildEntity::msidbFileISAttributesUseSystemSettings);
	virtual void LoadSystemLanguageSettings(const stringx& bstrFullPathName, const int iFilter = BuildEntity::msidbFileISAttributesUseSystemSettings);
	virtual void LoadSystemAttributesSettings(const stringx& bstrFullPathName, const int iFilter = BuildEntity::msidbFileISAttributesUseSystemSettings);

	virtual void LoadSystemFileSizeSettingsFromFindData(const stringx& bstrFullPathName,
        const WIN32_FIND_DATA* pFindData,const int iFilter = BuildEntity::msidbFileISAttributesUseSystemSettings);
	virtual void LoadSystemVersionSettingsFromFindData(const stringx& bstrFullPathName,
        const WIN32_FIND_DATA* pFindData,const int iFilter = BuildEntity::msidbFileISAttributesUseSystemSettings);
	virtual void LoadSystemLanguageSettingsFromFindData(const stringx& bstrFullPathName,
        const WIN32_FIND_DATA* pFindData,const int iFilter = BuildEntity::msidbFileISAttributesUseSystemSettings);
	virtual void LoadSystemAttributesSettingsFromFindData(const stringx& bstrFullPathName,
        const WIN32_FIND_DATA* pFindData,const int iFilter = BuildEntity::msidbFileISAttributesUseSystemSettings);
    // required overrides
    virtual void Win32Error(DWORD dwError) = 0;
    virtual stringx GetFileNotFoundString() = 0;

protected:
    // helpers
    void LoadModifiedFromData(const WIN32_FIND_DATA* pFindData);
    bool GetFileVersion( const stringx& pthFile, PULONG pulUpperVersion, PULONG pulLowerVersion );
    bool IsWinNT();
    bool Is9xDriverFile( const stringx& pthFile );
	void SetFileNotFoundAsError(bool bFileNotFoundAsError);

    // standard attributes
	long m_FileSize;
	stringx m_Version;
	stringx m_Language;
	short m_Attributes;

    // derived attributes
    stringx m_sModified;

    // states	
	bool m_bSystemFileSizeInitialized;
	bool m_bSystemVersionInitialized;
	bool m_bSystemLanguageInitialized;
	bool m_bSystemAttributesInitialized;
	bool m_bSystemModifiedInitialized;

	bool m_bFileNotFoundAsError;
};

#endif // #define __CFileMixin_H_
