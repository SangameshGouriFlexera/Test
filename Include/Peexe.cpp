//==========================================
// Matt Pietrek
// Microsoft Systems Journal, Feb 1997
// FILE: PEEXE.CPP
//==========================================
#include "stdafx.h"
#include "peexe.h"

#include "CorError.h"

CPeExe::CPeExe( BSTR bstrFileName ) : 
	CExeFile( bstrFileName ), 
	m_bLoadFailed(false),
    m_pNtHdr(0)
{
    if ( ! CExeFile::IsValid() )
	{
        return;
	}
    // It's an EXE, but is it a *PE* file???  If not, set code and bail
    if ( GetExeType() != exeType_PE && GetExeType() != exeType_PE64)
    {
        m_errorType = errEXE_FILE_INVALID_FORMAT;
        return;
    }

    m_pNtHdr = MakePtr(PIMAGE_NT_HEADERS,GetBase(),GetSecondaryHeaderOffset());
}

PIMAGE_DATA_DIRECTORY CPeExe::GetDataDirectoryEntry(DWORD id)
{
	return &GET_OPTIONAL_HEADER_FIELD(DataDirectory)[id];
}

DWORD CPeExe::GetDataDirectoryEntryRVA( DWORD id )
{
    // Given a IMAGE_DIRECTORY_ENTRY_XXX value (see WINNT.H), retrive the
    // RVA stored in the corresponding slot

    if ( id >= IMAGE_NUMBEROF_DIRECTORY_ENTRIES )
        return (DWORD)-1;

    return GetDataDirectoryEntry(id)->VirtualAddress;
}

PVOID CPeExe::GetDataDirectoryEntryPointer( DWORD id )
{
    // Given a IMAGE_DIRECTORY_ENTRY_XXX value (see WINNT.H), return a pointer
    // to memory that corresponds to the RVA in the specified slot.

    if ( id >= IMAGE_NUMBEROF_DIRECTORY_ENTRIES )
        return (PVOID)-1;
    
    DWORD va = GetDataDirectoryEntry(id)->VirtualAddress;

    if ( !va )      // Return 0 if the RVA is 0
        return 0;

    return GetReadablePointerFromRVA( va );
}

DWORD CPeExe::GetDataDirectoryEntrySize( DWORD id )
{
    // Given a IMAGE_DIRECTORY_ENTRY_XXX value (see WINNT.H), retrive the
    // size value stored in the corresponding slot

    if ( id >= IMAGE_NUMBEROF_DIRECTORY_ENTRIES )
        return (DWORD)-1;

    return GetDataDirectoryEntry(id)->Size;
}

PVOID CPeExe::GetReadablePointerFromRVA( DWORD rva )
{
    // Given an RVA, translate it into a pointer within our linear memory
    // mapping for the executable.

    DWORD fileOffset = RVAToFileOffset( rva );
    if ( (DWORD)-1 == fileOffset )
        return 0;
    
    return MakePtr( PVOID, GetBase(), fileOffset );
}

DWORD CPeExe::RVAToFileOffset( DWORD rva )
{
    // Given an RVA, figure out which section encompasses it.  Next, using
    // the PointerToRawData field for the found section, return an actual
    // file offset that corresponds to the RVA

    PIMAGE_SECTION_HEADER pSectHdr = IMAGE_FIRST_SECTION( m_pNtHdr );
    
    for ( unsigned i = 0; i < GetNumberOfSections(); i++, pSectHdr++ )
    {
        DWORD cbMaxOnDisk
            = min( pSectHdr->Misc.VirtualSize, pSectHdr->SizeOfRawData );

        DWORD startSectRVA = pSectHdr->VirtualAddress;
        DWORD endSectRVA = startSectRVA + cbMaxOnDisk;
        
        if ( (rva >= startSectRVA) && (rva < endSectRVA) )
            return pSectHdr->PointerToRawData + (rva - startSectRVA);
    }
    
    return (DWORD)-1;   // RVA not found in the section table... Ooops!
}

bool CPeExe::IsSelfRegistering()
{
	bool bSelfRegistering = false;
	//
	// JLC 5/11/00
	// Find out if this module exports the DllRegisterServer function
	//
	if (GetDataDirectoryEntrySize(IMAGE_DIRECTORY_ENTRY_EXPORT) > 0)
	{
		// Get pointer to exports table
		PIMAGE_EXPORT_DIRECTORY pExportDir;
		pExportDir = (PIMAGE_EXPORT_DIRECTORY) GetDataDirectoryEntryPointer(IMAGE_DIRECTORY_ENTRY_EXPORT);
		if (pExportDir != NULL)
		{
			int nNames = pExportDir->NumberOfNames;

			// Get pointer to name table
			PSTR *names = (PSTR *) GetReadablePointerFromRVA(((DWORD)pExportDir->AddressOfNames));
			if(!names)  // crash fix IOC-000046705 				
				return false;

			// Look for "DllSelfRegister" function
			for ( int j=0; !bSelfRegistering && j < nNames; ++j)
			{
				PSTR n = (PSTR) GetReadablePointerFromRVA((DWORD)(names[j]));
				ATLTRACE(" - %s\n", n);
				if (lstrcmp(_T("DllRegisterServer"), stringx(n)) == 0)
				{
					bSelfRegistering = true;
				}
			}
		}
	}

	return bSelfRegistering;
}

bool CPeExe::IsDotNetPE()
{
	return GetDotNetHeader() != NULL;
}

bool CPeExe::IsCppCli()
{
	if(m_bLoadFailed)	return false;

	// Make a pointer to the .NET table
	PIMAGE_COR20_HEADER pDotNetDir = GetDotNetHeader();

	if (!pDotNetDir)	return false;

	return (pDotNetDir->Flags & COMIMAGE_FLAGS_NATIVE_ENTRYPOINT) == COMIMAGE_FLAGS_NATIVE_ENTRYPOINT;
}

CExeFile::eType CPeExe::GetNetAssemblyType()
{
	if(m_bLoadFailed)
		return exeType_Invalid;

	PIMAGE_COR20_HEADER pDotNetHeader = GetDotNetHeader();
	if(!pDotNetHeader)
		return GetExeType();

	if(pDotNetHeader->Flags & COMIMAGE_FLAGS_ILONLY)
		return exeType_PE_NET_MSIL;

	eType peType = GetExeType();
	switch(peType)
	{
		case exeType_PE:
			return exeType_PE_NET_X86;
		
		case exeType_PE64:
			return exeType_PE_NET_X64;

		case exeType_PEIA64:
			return exeType_PE_NET_IA64;

		case exeType_PEARM:
			return exeType_PE_NET_ARM;

		default:
			return peType;
	}
}

//
// Note this is just a partial structure as it has what we need.
// The Version field is variable length anyway so defining any members
// after that point is a bit tricky.
//
struct DotNetMetadataHeader
{
	DWORD Signature;
	WORD MajorVersion;
	WORD MinorVersion;
	DWORD Reserved;
	DWORD Length;
	UCHAR Version[1];
};

stringxi CPeExe::GetAssemblyCLRMetadataVersion()
{
	PIMAGE_COR20_HEADER pDotNetHeader = GetDotNetHeader();
	if (pDotNetHeader == nullptr)
		return L"";

	PIMAGE_DATA_DIRECTORY pMetaDir = &pDotNetHeader->MetaData;

	if (pMetaDir->Size == 0 || pMetaDir->VirtualAddress == 0)
		return L"";

	DotNetMetadataHeader *pMetadata = (DotNetMetadataHeader *)GetReadablePointerFromRVA(pDotNetHeader->MetaData.VirtualAddress);

	if (pMetadata == nullptr)
		return L"";

	return stringxi((char *)&pMetadata->Version, pMetadata->Length);
}

PIMAGE_COR20_HEADER CPeExe::GetDotNetHeader()
{
	if(m_bLoadFailed)
		return NULL;

	return (PIMAGE_COR20_HEADER)GetDataDirectoryEntryPointer(IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR);
}