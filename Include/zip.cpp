#include "StdAfx.h"
#include <atlbase.h>
#import "shell32.dll" rename_namespace("Shell32") raw_interfaces_only
#include "zip.h"


CZip::CZip(const stringxi& sZipFile)
{
	m_sZipFile = sZipFile;
	m_sZipFile.path_remove_quote();
}

bool CZip::ExtractPSRReportFile(const stringxi& sDestFolderIn, const stringxi& sProductName)
{
	stringxi sDestFolder(sDestFolderIn);
	sDestFolder.path_remove_quote();
	
	HRESULT hrCoInitialize = S_OK;
	try
	{
		CComPtr<Shell32::IShellDispatch> spShell;

		hrCoInitialize = CoInitialize(NULL);
		HRESULT hr = CoCreateInstance(CLSID_Shell,NULL,CLSCTX_INPROC_SERVER,IID_IShellDispatch,(void**)&spShell);

		if (!spShell || FAILED(hr))
			return false;
		
		CComPtr<Shell32::Folder> spDestFolder;
		hr = spShell->NameSpace(sDestFolder, &spDestFolder);
		if (!spDestFolder || FAILED(hr))
			return false;
		
		CComPtr<Shell32::Folder> spZipFolder;
		hr = spShell->NameSpace(m_sZipFile, &spZipFolder);
		if (!spZipFolder || FAILED(hr))
			return false;

		CComPtr<Shell32::FolderItems> spFolderItems;
		hr = spZipFolder->Items(&spFolderItems);
		long itemCount = 0;
		spFolderItems->get_Count(&itemCount);
		
		if (itemCount > 0)
		{
			CComPtr<Shell32::FolderItem> spFolderItem;
			CComVariant index(0);
			hr = spFolderItems->Item(index, &spFolderItem);
			
 			stringxi sFileName;	
 			hr = spFolderItem->get_Name(&sFileName);

			hr = spDestFolder->CopyHere(CComVariant(spFolderItem));
			::MoveFile(sDestFolder ^ sFileName, sDestFolder ^ sProductName + L"_" + sFileName);
		}
	}
	catch (...)
	{
		return false;
	}

	if (hrCoInitialize == S_OK || hrCoInitialize == S_FALSE)
		CoUninitialize();
	return true;
}

bool CZip::ExtractAllFiles(const stringxi& sDestFolderIn)
{
	stringxi sDestFolder(sDestFolderIn);
	sDestFolder.path_remove_quote();
	
	HRESULT hrCoInitialize = S_OK;
	try
	{
		CComPtr<Shell32::IShellDispatch> spShell;

		hrCoInitialize = CoInitialize(NULL);
		HRESULT hr = CoCreateInstance(CLSID_Shell,NULL,CLSCTX_INPROC_SERVER,IID_IShellDispatch,(void**)&spShell);

		if (!spShell || FAILED(hr))
			return false;
		
		CComPtr<Shell32::Folder> spDestFolder;
		hr = spShell->NameSpace(sDestFolder, &spDestFolder);
		if (!spDestFolder || FAILED(hr))
			return false;
		
		
		CComPtr<Shell32::Folder> spZipFolder;
		hr = spShell->NameSpace(m_sZipFile, &spZipFolder);
		if (!spZipFolder || FAILED(hr))
			return false;

		CComPtr<Shell32::FolderItems> spFolderItems;
		hr = spZipFolder->Items(&spFolderItems);
		long itemCount = 0;
		spFolderItems->get_Count(&itemCount);

		
		for (long i = 0; i < itemCount; ++i)
		{
			CComPtr<Shell32::FolderItem> spFolderItem;
			CComVariant index(i);
			hr = spFolderItems->Item(index, &spFolderItem);
			
 			//stringxi sFileName;	
 			//hr = spFolderItem->get_Name(&sFileName);
			
			hr = spDestFolder->CopyHere(CComVariant(spFolderItem));
		}
	}
	catch (...)
	{
		return false;
	}

	if (hrCoInitialize == S_OK || hrCoInitialize == S_FALSE)
		CoUninitialize();
	return true;
}


