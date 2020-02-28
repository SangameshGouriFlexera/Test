#pragma once

#include "pathx.h"
using namespace is;
#include "GlobalConstants.h"
#include "Peexe.h"

enum AppvFileAttribute
{
	UserData,
	ApplicationData,
	UnspecifiedData
};

namespace AppVFileSettings
{	
	//used internally by the AppV writer.
	//the pthFile is expected to start with a CSIDL-prefix.
	//static bool IsUserData(const pathx& pthFile)
	static AppvFileAttribute GetAppvFileUserDataAttr(const pathx& pthFile)
	{
		pathx pthDest = pthFile;

		stringwi sExt = pthDest.ext();
		if ((sExt == L".cp") ||
			(sExt == L".exe") ||
			(sExt == L".dll") ||
			(sExt == L".com") ||
			(sExt == L".config") ||
			(sExt == L".manifest"))
		{
			return ApplicationData;
		}

		if ((pthDest.find(L"CSIDL_PERSONAL") != -1) || (pthDest.find(L"CSIDL_FAVORITES") != -1) ||
			(pthDest.find(L"CSIDL_PICTURES") != -1) || (pthDest.find(L"USERPROFILE") != -1) ||
			(pthDest.find(L"CSIDL_SENDTO") != -1)  ||
			(pthDest.find(L"CSIDL_APPDATA") != -1) || (pthDest.find(L"CSIDL_LOCAL_APPDATA") != -1))
			return UserData;

		if ((pthDest.find(L"CSIDL_PROGRAM_FILES_COMMON\\Microsoft Shared") != -1) ||
			(pthDest.find(L"%ProgramFilesDir%\\Common Files\\Microsoft Shared") != -1))
			return ApplicationData;

		if ((sExt == L".dat") ||
			(sExt == L".ini") ||
			(sExt == L".dot") ||
			(sExt == L".mdw"))
		{
			return UserData;
		}

		return UnspecifiedData;
	}
	
	//This version of this function is only called from the InstallShield IDE 
	//static bool IsUserData(const pathx& pthDestination, const pathx& pthFile)
	static AppvFileAttribute GetAppvFileUserDataAttr2(const pathx& pthDestination, const pathx& pthFile)
	{
		pathx pthDest = pthDestination;
		
		// Strip off {Var} if any
		if (pthDestination[0] == L'{')
		{
			int nPos = pthDestination.find(L'}');
			if (nPos != pathx::npos)
				pthDest = pthDestination.substr(nPos + 2);
		}

		stringwi sExt = pthFile.ext();
		if ((sExt == L".cp") ||
			(sExt == L".exe") ||
			(sExt == L".dll") ||
			(sExt == L".com") ||
			(sExt == L".config") ||
			(sExt == L".manifest"))
		{
			return ApplicationData;
		}

		if (pthDest[0] == L'[')
		{
			int nPos = pthDest.find(L']');
			stringw sVar = pthDest.substr(0, nPos+1).c_str();
			
			if ((sVar == ISMSI_USERPROFILE) || (sVar == ISMSI_FAVOURITESFOLDER) ||
				(sVar == ISMSI_MYPICTURESFOLDER) || (sVar == ISMSI_PERSONALFOLDER) ||
				(sVar == ISMSI_SENDTOFOLDER) || 
				(sVar == ISMSI_APPDATAFOLDER) || (sVar == ISMSI_LOCALAPPDATAFOLDER))
				return UserData;

			if (((sVar == ISMSI_COMMONFILESFOLDER) || (sVar == ISMSI_COMMONFILES64FOLDER)) &&
				(pthDest.find(L"Microsoft Shared") == (nPos+1)))
			{
				return ApplicationData;
			}

			if ((sExt == L".dat") ||
				(sExt == L".ini") ||
				(sExt == L".dot") ||
				(sExt == L".mdw"))
			{
				return UserData;
			}

			//Based on feedback this function should default to user data
			return UnspecifiedData;
		}
		else
		{
			ATLASSERT(FALSE);
			return UnspecifiedData;
		}
	}
	
	static stringx GenerateRootFolderName(stringx rootFolder, stringx productName, stringx productVersion)
	{
		if(rootFolder.empty())
		{

			productName.replace_all(L" ",L"");
			
			//make sure no invalid characters /:*?\"<>|
			productName.replace_all(L"/",L"");
			productName.replace_all(L":",L"");
			productName.replace_all(L"*",L"");
			productName.replace_all(L"?",L"");
			productName.replace_all(L"\\",L"");
			productName.replace_all(L"\"",L"");
			productName.replace_all(L"<",L"");
			productName.replace_all(L">",L"");
			productName.replace_all(L"|",L"");
			
			
			//root folder must be 8.3 naming, so get only the first 8 characters of the name
			if(productName.length() > 8)
			{
				productName = productName.substr(0,8);
			}
			
			//root folder must be 8.3 naming, use product version to generate 3 character extension
			productVersion.replace_all(L" ",L"");
			
			//make sure no invalid characters /:*?\"<>|
			productVersion.replace_all(L"/",L"");
			productVersion.replace_all(L":",L"");
			productVersion.replace_all(L"*",L"");
			productVersion.replace_all(L"?",L"");
			productVersion.replace_all(L"\\",L"");
			productVersion.replace_all(L"\"",L"");
			productVersion.replace_all(L"<",L"");
			productVersion.replace_all(L">",L"");
			productVersion.replace_all(L"|",L"");
			
			productVersion.replace_all(L".",L"");
			
			if(productVersion.length() > 3)
			{
				productVersion = productVersion.substr(0,3);
			}
			
			rootFolder = productName + L"." + productVersion;
		}
		else
		{
			//make sure no invalid characters /:*?\"<>|
			rootFolder.replace_all(L"/",L"");
			rootFolder.replace_all(L":",L"");
			rootFolder.replace_all(L"*",L"");
			rootFolder.replace_all(L"?",L"");
			rootFolder.replace_all(L"\\",L"");
			rootFolder.replace_all(L"\"",L"");
			rootFolder.replace_all(L"<",L"");
			rootFolder.replace_all(L">",L"");
			rootFolder.replace_all(L"|",L"");
		}
		
		return rootFolder;
	}

	static bool Is16BitFile(const stringx& absoluteFilePath)
	{
		CExeFile oExeFile(absoluteFilePath);
		
		if (oExeFile.IsValid())
		{
			// DOS and NE files are 16-bit and before PE; 32bit files and up are PE
			CExeFile::eType exeType = oExeFile.GetExeType();
			if (CExeFile::exeType_DOS == exeType || CExeFile::exeType_NE == exeType)
				return true;
		}
		
		return false;
	}

	static bool Is64BitFile(const stringx& absoluteFilePath)
	{
		CExeFile oExeFile(absoluteFilePath);
		
		if (oExeFile.IsValid())
			return (CExeFile::exeType_PE64 == oExeFile.GetExeType());
		
		return false;
	}

	static bool IsConsoleExe(const stringx& absoluteFilePath)
	{
		SHFILEINFO fileInfo = {0};
		DWORD result = SHGetFileInfo(absoluteFilePath,NULL,&fileInfo,sizeof(fileInfo),SHGFI_EXETYPE);
		
		if((LOWORD(result)==MAKEWORD('P','E') || LOWORD(result)==MAKEWORD('N','E')) && HIWORD(result)==0)
		{
			return true;
		}
		
		return false;
	}

}