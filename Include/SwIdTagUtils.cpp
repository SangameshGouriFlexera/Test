#include "stdafx.h"
#include "resource.h"
#include "SwIdTagUtils.h"
#include "SwIdTag.h"
#include "AdminStudio_RegLocations.h"
#include "..\repackager\islc\LocalInfoRepack.h"

namespace SwIdTagUtils
{
	std::vector<stringxi> GetExistingSwIdTagFiles(const stringxi& sDir)
	{
		std::vector<stringxi> vec_TagFiles;
		
		WIN32_FIND_DATAW findData;
		HANDLE hSearch = FindFirstFileW(sDir ^ L"*.swidtag", &findData);
		
		do 
		{
			if (hSearch != INVALID_HANDLE_VALUE && !(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
				vec_TagFiles.push_back(sDir ^ findData.cFileName);
		} 
		while (FindNextFileW(hSearch, &findData));
		
		FindClose(hSearch);
		
		return vec_TagFiles;
	}
	
	//Will at least one tag file be included
	bool AtLeastOneTagSelected(const stringxi& sDir)
	{
		bool bGenerateAtLeastOneTag = false;
		std::vector<stringxi> vec_TagFiles = GetExistingSwIdTagFiles(sDir);
		std::vector<stringxi>::iterator tagFileIter = vec_TagFiles.begin();
		for (; tagFileIter != vec_TagFiles.end(); ++ tagFileIter)
		{
			CSwIdTag tag(*tagFileIter);
			bGenerateAtLeastOneTag |= tag.GetGenerateTag();
		}

		return bGenerateAtLeastOneTag;
	}

	//This function is only called from Repackager and not Application Manager. This is important due to the GetModuleFileName call.
	void CreateOrUpdateSwIdTag(const stringx& sName, const stringx& sVersion, const stringx& sProductGuid, const stringx& sPublisher, const stringxi& sDir)
	{
		std::vector<stringxi> vec_TagFiles = SwIdTagUtils::GetExistingSwIdTagFiles(sDir);
		std::vector<stringxi>::iterator iter = vec_TagFiles.begin();
		
		for (; iter != vec_TagFiles.end(); ++iter)
		{
			CSwIdTag tag(*iter);
			if (sName == tag.GetProductName())
			{
				//tag.PutOrigArpGuid(sProductGuid);
				tag.PutOrigArpInfo(sProductGuid, sName, sVersion, sPublisher);
				tag.Save();
				return;
			}
		}
		
		
		//could not find match
		using namespace AdmRegLocations;
				
		stringxi sPreferencesFile;
		GetModuleFileName(NULL, sPreferencesFile.get_buffer(MAX_PATH), MAX_PATH);
		sPreferencesFile = sPreferencesFile.path_dir() ^ L"islc.ini";
		
		bool bDefaultGenerateTagOption = true;
		stringx sDefaultTagCreatorName, sDefaultTagCreatorRegId;
		if(::PathFileExists(sPreferencesFile))
		{
			stringx sDefaultGenerateTagOptVal;
			GetPrivateProfileString(_T("Build"), g_lpszSwIdTag_CreateOnImport, _T("1"), sDefaultGenerateTagOptVal.get_buffer(10), 10, sPreferencesFile);
			bDefaultGenerateTagOption = (sDefaultGenerateTagOptVal == L"0") ? false : true;

			GetPrivateProfileString(_T("Build"), g_lpszSwIdTag_TagCreatorName, _T(""), sDefaultTagCreatorName.get_buffer(256), 256, sPreferencesFile);
			GetPrivateProfileString(_T("Build"), g_lpszSwIdTag_TagCreatorRegId, _T(""), sDefaultTagCreatorRegId.get_buffer(256), 256, sPreferencesFile);
		}

		CString sAsSharedFolder;
		CLocalInfo::GetSharedLocation(sAsSharedFolder);
		stringx sAsSharedIniFile = stringx(sAsSharedFolder) ^ g_lpszASSharedIniFile;
		if (::PathFileExists(sAsSharedIniFile))
		{
			stringx sDefaultGenerateTagOptVal;
			GetPrivateProfileString(g_lpszSwIdTagSection, g_lpszSwIdTag_CreateOnImport, _T("1"), sDefaultGenerateTagOptVal.get_buffer(10), 10, sAsSharedIniFile);
			bDefaultGenerateTagOption = (sDefaultGenerateTagOptVal == L"0") ? false : true;
			
			GetPrivateProfileString(g_lpszSwIdTagSection, g_lpszSwIdTag_TagCreatorName, _T(""), sDefaultTagCreatorName.get_buffer(256), 256, sAsSharedIniFile);
			GetPrivateProfileString(g_lpszSwIdTagSection, g_lpszSwIdTag_TagCreatorRegId, _T(""), sDefaultTagCreatorRegId.get_buffer(256), 256, sAsSharedIniFile);
		}

		// ADMIN-14672 - No longer creating tag files in Repackager if option is set to No as per Bank of America request
		if (!bDefaultGenerateTagOption)
			return;

		CSwIdTag idTag;
		idTag.PutProductName(sName);
		idTag.PutProductVersion(sVersion);
		idTag.PutOrigArpGuid(sProductGuid);
		idTag.PutSwPublisher(sPublisher);
		idTag.PutSwCreatorName(sPublisher);
		idTag.PutGenerateTag(bDefaultGenerateTagOption);

		if (!sDefaultTagCreatorName.empty())
			idTag.PutTagCreator(sDefaultTagCreatorName);
		else
			idTag.PutTagCreator(g_lpszSwIdTag_TagCreatorName_DefaultVal);
		
		if (!sDefaultTagCreatorRegId.empty())
			idTag.PutTagCreatorRegId(sDefaultTagCreatorRegId);
		else
			idTag.PutTagCreatorRegId(g_lpszSwIdTag_TagCreatorRegId_DefaultVal);

		idTag.SaveToFolder(sDir);
	}

	bool HaveWritePermissions(const stringxi& sFolder)
	{
		HANDLE hFile = ::CreateFile(sFolder ^ L"ASWritePermissionsTest.txt", GENERIC_READ|GENERIC_WRITE,
			FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		if(INVALID_HANDLE_VALUE == hFile || !::PathFileExists(sFolder ^ L"ASWritePermissionsTest.txt"))
		{
			return false;
		}
		else
		{
			::CloseHandle(hFile);
			::DeleteFile(sFolder ^ L"ASWritePermissionsTest.txt");
			return true;
		}
	}
}
