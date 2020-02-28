#ifndef __PESIZE_H__
#define __PESIZE_H__

#include "is.h"
#include "auto_handle.hxx"

#define MakePtr(cast, ptr, addValue) (cast)((DWORD)(ptr) + (addValue))

_IS_BEGIN

static DWORD GetInternalExeSize(LPCTSTR pszSrc, bool bIgnoreSignature = false );
static DWORD GetSignatureOffset(LPCTSTR pszSrc);
static DWORD GetInternalMSCabSize(LPCTSTR pszCab);

// GetSectionHeader
//
// Given a section name, look it up in the section table and return a
// pointer to its IMAGE_SECTION_HEADER
//
static PIMAGE_SECTION_HEADER GetSectionHeader(LPSTR pszSection, PIMAGE_NT_HEADERS pNTHeader)
{
	PIMAGE_SECTION_HEADER pSection;
	
	pSection = reinterpret_cast<PIMAGE_SECTION_HEADER>(pNTHeader+1);
	
	for(unsigned i = 0; i < pNTHeader->FileHeader.NumberOfSections; i++, pSection++)
	{
        if(CSTR_EQUAL == ::CompareStringA(LOCALE_USER_DEFAULT, NORM_IGNORECASE, reinterpret_cast<LPCSTR>(pSection->Name), IMAGE_SIZEOF_SHORT_NAME, pszSection, -1))
			return pSection;
	}
	
	return NULL;
}


// GetDebugSize
static DWORD GetDebugSize(HANDLE hFileMapping, DWORD base, PIMAGE_NT_HEADERS pNTHeader, DWORD nImageSizeWithoutDebugSection)
{
	PIMAGE_DEBUG_DIRECTORY  debugDir;
	PIMAGE_SECTION_HEADER   header;
	unsigned                cDebugFormats, i;
	DWORD                   offsetInto_rdata;
	DWORD                   va_debug_dir;
	DWORD	                nSize=0;
	DWORD					dwBaseViewSize = 0;
	MEMORY_BASIC_INFORMATION MappedExeViewSizeInfo;
	is::auto_handle_t<PIMAGE_DEBUG_DIRECTORY, BOOL (__stdcall *)(LPCVOID), UnmapViewOfFile> lpDebugViewBase;
	DWORD					dwRawFileOffset, dwDebugDirSize;

	va_debug_dir = pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_DEBUG].VirtualAddress;

	if (va_debug_dir == 0)
		return 0;

	//
	// Get the size of the mapped view that was passed to us in base.
	//
	if(::VirtualQuery((LPCVOID)base, &MappedExeViewSizeInfo, sizeof(MEMORY_BASIC_INFORMATION)))
		dwBaseViewSize = MappedExeViewSizeInfo.RegionSize;


	// If we found a .debug section, and the debug directory is at the
	// beginning of this section, it looks like a Borland file
	header = GetSectionHeader(".debug", pNTHeader);
	
    if (header && (header->VirtualAddress == va_debug_dir))
	{
		debugDir = (PIMAGE_DEBUG_DIRECTORY)(header->PointerToRawData+base);
		cDebugFormats = pNTHeader->OptionalHeader.
							DataDirectory[IMAGE_DIRECTORY_ENTRY_DEBUG].Size;

		dwRawFileOffset = header->PointerToRawData;
		dwDebugDirSize = (DWORD)cDebugFormats;
	}
	else	// Look for microsoft debug directory in the .rdata or .text section
	{
		header = GetSectionHeader(".rdata", pNTHeader);
		if (!header)
		{
			header = GetSectionHeader(".text", pNTHeader);
			if (!header)
				return 0;
		}

		// See if there's even any debug directories to speak of...
		cDebugFormats = pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_DEBUG].Size / sizeof(IMAGE_DEBUG_DIRECTORY);
		
        if (cDebugFormats == 0)
			return 0;
	
		//
		// Determine if this virtual address extends past the raw data available for this
		// section. If so, the VA for the debug info is invalid.
		//
		if(va_debug_dir > (header->VirtualAddress + header->SizeOfRawData))
			return 0;

		offsetInto_rdata = va_debug_dir - header->VirtualAddress;
		
        debugDir = MakePtr(PIMAGE_DEBUG_DIRECTORY, base, header->PointerToRawData + offsetInto_rdata);

		dwRawFileOffset = header->PointerToRawData + offsetInto_rdata;
		dwDebugDirSize = pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_DEBUG].Size;
	}
    
	//
	// Map another view of the file if the debug directory is past
	// the current view.
	//
	if((((DWORD)debugDir - base) > dwBaseViewSize) && hFileMapping)
	{
		DWORD dwTotalViewSize;
		DWORD dwActualFileOffsetStart;
		DWORD dwAllocationGranularity;
		SYSTEM_INFO SystemInfo;
		PVOID lpNewMapAddress;

		GetSystemInfo(&SystemInfo);
		dwAllocationGranularity = SystemInfo.dwAllocationGranularity;

		//
		// We need to get an offset in the file that is a multiple of the system allocation 
		// granularity. Since there's no guarantee dwRawFileOffset is a multiple, round down
		// to the next lowest multiple of dwAllocationGranularity to get a valid file offset
		// to map. The view size is our desired file offset mod the allocation granularity,
		// plus the size of the actual data we care about.
		//
		dwActualFileOffsetStart = (dwRawFileOffset / dwAllocationGranularity) * dwAllocationGranularity;
		dwTotalViewSize = (dwRawFileOffset % dwAllocationGranularity) + dwDebugDirSize;
		
		lpNewMapAddress = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, dwActualFileOffsetStart, dwTotalViewSize);
		if(!lpNewMapAddress)
			return 0;

		lpDebugViewBase = reinterpret_cast<PIMAGE_DEBUG_DIRECTORY>(lpNewMapAddress);
		debugDir = (PIMAGE_DEBUG_DIRECTORY)((LPBYTE)lpNewMapAddress + (dwRawFileOffset - dwActualFileOffsetStart));
	}

	for (i=0; i < cDebugFormats; i++)
	{
		if (debugDir->PointerToRawData + debugDir->SizeOfData> nImageSizeWithoutDebugSection)
			nSize += debugDir->SizeOfData;
		
        debugDir++;
	}

	return nSize;
}


// GetExeImageSize
static DWORD GetExeImageSize(HANDLE hFileMapping, DWORD base, PIMAGE_NT_HEADERS pNTHeader, bool bIgnoreSignature )
{
	PIMAGE_SECTION_HEADER   section = (PIMAGE_SECTION_HEADER)(pNTHeader+1);
	unsigned                cSections = pNTHeader->FileHeader.NumberOfSections;
	BOOL                    IsEXE = TRUE;
	unsigned                i;
	DWORD	                nSize=0;

	nSize += pNTHeader->OptionalHeader.SizeOfHeaders;

	for (i=1; i <= cSections; i++, section++)
	{
		nSize+=section->SizeOfRawData;
	}

	nSize += GetDebugSize(hFileMapping, base, pNTHeader,nSize);

    if( !bIgnoreSignature )
	    nSize += pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_SECURITY].Size;
						
	return nSize;
}

static UINT MapImageFile(LPCTSTR pszFile, LPVOID *lpBaseMapping, HANDLE *phFile, HANDLE *phFileMapping, PIMAGE_NT_HEADERS *ppNtHeaders)
{
	is::auto_handle hFile, hFileMapping;
	is::auto_handle_t<LPVOID, BOOL (__stdcall *)(LPCVOID), UnmapViewOfFile> pMapBase;
	PIMAGE_DOS_HEADER   dosHeader;
    DWORD dwSizeToMap = 0;
	SYSTEM_INFO SystemInfo;
	
	hFile = ::CreateFile(pszFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
		return ::GetLastError();

	hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
	if (hFileMapping == NULL)
		return ::GetLastError();
	
	//
	// Get the page size for the machine we're running on and map
	// that size for our exe (basically just the PE headers).
	//
	GetSystemInfo(&SystemInfo);
	dwSizeToMap = SystemInfo.dwPageSize;
	pMapBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, dwSizeToMap);
	
	if (pMapBase == 0)
		return ::GetLastError();
	
	dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>((LPVOID)pMapBase);
	
	PIMAGE_NT_HEADERS pNTHeader;

	if (dosHeader->e_magic == IMAGE_DOS_SIGNATURE)
	{
		DWORD base = (DWORD)dosHeader;
		
		pNTHeader = MakePtr(PIMAGE_NT_HEADERS, dosHeader, dosHeader->e_lfanew);
		
		// First, verify that the e_lfanew field gave us a reasonable
		// pointer, then verify the PE signature.
		if (IsBadReadPtr(pNTHeader, sizeof(IMAGE_NT_HEADERS)) ||
			pNTHeader->Signature != IMAGE_NT_SIGNATURE)
			return ERROR_BAD_EXE_FORMAT;
		
		//
		// Verify we have enough of the file mapped for the PE headers. Remap the
		// headers if needed and verify again.
		//
		if(dwSizeToMap < pNTHeader->OptionalHeader.SizeOfHeaders)
		{
			dwSizeToMap = pNTHeader->OptionalHeader.SizeOfHeaders;
			UnmapViewOfFile(pMapBase);
			pMapBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, dwSizeToMap);
			
			dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>((LPVOID)pMapBase);
			base = (DWORD)dosHeader;
			
			if(dosHeader->e_magic != IMAGE_DOS_SIGNATURE)
			{
				return ERROR_BAD_EXE_FORMAT;
			}
			
			pNTHeader = MakePtr(PIMAGE_NT_HEADERS, dosHeader, dosHeader->e_lfanew);
			if(IsBadReadPtr(pNTHeader, sizeof(IMAGE_NT_HEADERS)) ||
				pNTHeader->Signature != IMAGE_NT_SIGNATURE)
			{
				return ERROR_BAD_EXE_FORMAT;
			}

			//
			// Image is valid, fall through...	
			//
		}
	}

	if(lpBaseMapping)
	{
		*lpBaseMapping = pMapBase;
		pMapBase.release();
	}

	if(phFile)
	{
		*phFile = hFile;
		hFile.release();
	}

	if(phFileMapping)
	{
		*phFileMapping = hFileMapping;
		hFileMapping.release();
	}

	if(ppNtHeaders)
		*ppNtHeaders = pNTHeader;

	return ERROR_SUCCESS;
}

// GetInternalExeSize
static DWORD GetInternalExeSize(LPCTSTR	pthSrc, bool bIgnoreSignature)
{
    is::auto_handle     hFileMapping, hFile;
    is::auto_handle_t<PIMAGE_DOS_HEADER, BOOL (__stdcall *)(LPCVOID), UnmapViewOfFile> lpFileBase;
	PIMAGE_NT_HEADERS pNTHeader;

	if(ERROR_SUCCESS != MapImageFile(pthSrc, (LPVOID *)&lpFileBase, &hFile, &hFileMapping, &pNTHeader))
		return 0;
	
	return GetExeImageSize(hFileMapping, (DWORD)(LPVOID)lpFileBase, pNTHeader, bIgnoreSignature );
}

static DWORD GetSignatureOffset(LPCTSTR pszSrc)
{
    is::auto_handle     hFileMapping, hFile;
    is::auto_handle_t<PIMAGE_DOS_HEADER, BOOL (__stdcall *)(LPCVOID), UnmapViewOfFile> lpFileBase;
	PIMAGE_NT_HEADERS pNTHeader;

	if(ERROR_SUCCESS != MapImageFile(pszSrc, (LPVOID *)&lpFileBase, &hFile, &hFileMapping, &pNTHeader))
		return 0;

	return pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_SECURITY].VirtualAddress;
}

#pragma pack(push, 1)
struct mscab_cfheader //part of the mscab header we care about
{
	BYTE	signature[4];
	ULONG	ulReserved;
	ULONG	ulCabSize;
};
#pragma pack(pop)

static DWORD GetInternalMSCabSize(LPCTSTR pszCab)
{
	DWORD				dwSize(INVALID_FILE_SIZE);
    is::auto_hfile      hFile;

	hFile = ::CreateFile(pszCab, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile.valid())
	{
		mscab_cfheader	hdr;
		DWORD			dwBytesRead(0);

		ReadFile(hFile, &hdr, sizeof(hdr), &dwBytesRead, 0);
		if (sizeof(hdr) == dwBytesRead)
			dwSize = hdr.ulCabSize;
	}

	return dwSize;
}

_IS_END

#endif // __PESIZE_H__
