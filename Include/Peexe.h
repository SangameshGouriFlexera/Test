//==========================================
// Matt Pietrek
// Microsoft Systems Journal, Feb 1997
// FILE: PEEXE.H
//==========================================
#ifndef __PEEXE_H__
#define __PEEXE_H__

#ifndef __EXEFILE_H__
#include "exefile.h"
#endif

//
// Retrieve field value from 32-bit or 64-bit optional header.
//
#define GET_OPTIONAL_HEADER_FIELD(field) ((GetExeType() == exeType_PE) ? ((PIMAGE_NT_HEADERS32)m_pNtHdr)->OptionalHeader.field : ((PIMAGE_NT_HEADERS64)m_pNtHdr)->OptionalHeader.field)

class CPeExe : public CExeFile
{
    public:

    CPeExe( BSTR bstrFileName );
    ~CPeExe( ){ }

    bool IsValid() { return m_pNtHdr ? true: false; }

    // For those who want at the data directly
    PIMAGE_NT_HEADERS GetIMAGE_NT_HEADERS() { return m_pNtHdr; }

    // IMAGE_FILE_HEADER fields
    WORD    GetMachine()
                { return m_pNtHdr->FileHeader.Machine; }
    WORD    GetNumberOfSections()
                { return m_pNtHdr->FileHeader.NumberOfSections; }
    DWORD   GetTimeDateStamp()
                { return m_pNtHdr->FileHeader.TimeDateStamp; }
    DWORD   GetCharacteristics()
                { return m_pNtHdr->FileHeader.Characteristics; }

    // IMAGE_OPTIONAL_HEADER fields
	DWORD   GetSizeOfCode()
            { return GET_OPTIONAL_HEADER_FIELD(SizeOfCode); }
    DWORD   GetSizeOfInitializedData()
			{ return GET_OPTIONAL_HEADER_FIELD(SizeOfInitializedData); }
    DWORD   GetSizeOfUninitializedData( )
            { return GET_OPTIONAL_HEADER_FIELD(SizeOfUninitializedData); }
    DWORD   GetAddressOfEntryPoint( )
            { return GET_OPTIONAL_HEADER_FIELD(AddressOfEntryPoint); }
    DWORD   GetBaseOfCode( )
            { return GET_OPTIONAL_HEADER_FIELD(BaseOfCode); }
#ifndef _WIN64
	DWORD   GetBaseOfData( )
			{ return ((GetExeType() == exeType_PE) ? m_pNtHdr->OptionalHeader.BaseOfData : 0); }
#endif
	ULONGLONG   GetImageBase( )
            { return GET_OPTIONAL_HEADER_FIELD(ImageBase); }
    DWORD   GetSectionAlignment( )
            { return GET_OPTIONAL_HEADER_FIELD(SectionAlignment); }
    DWORD   GetFileAlignment( )
            { return GET_OPTIONAL_HEADER_FIELD(FileAlignment); }
    WORD    GetMajorOperatingSystemVersion( )
            { return GET_OPTIONAL_HEADER_FIELD(MajorOperatingSystemVersion); }
    WORD    GetMinorOperatingSystemVersion( )
            { return GET_OPTIONAL_HEADER_FIELD(MinorOperatingSystemVersion); }
    WORD    GetMajorImageVersion( )
            { return GET_OPTIONAL_HEADER_FIELD(MajorImageVersion); }
    WORD    GetMinorImageVersion( )
            { return GET_OPTIONAL_HEADER_FIELD(MinorImageVersion); }
    WORD    GetMajorSubsystemVersion( )
            { return GET_OPTIONAL_HEADER_FIELD(MajorSubsystemVersion); }
    WORD    GetMinorSubsystemVersion( )
            { return GET_OPTIONAL_HEADER_FIELD(MinorSubsystemVersion); }
//    DWORD   GetWin32VersionValue( )
//          { return m_pNtHdr->OptionalHeader.Win32VersionValue; }
    DWORD   GetSizeOfImage( )
            { return GET_OPTIONAL_HEADER_FIELD(SizeOfImage); }
    DWORD   GetSizeOfHeaders( )
            { return GET_OPTIONAL_HEADER_FIELD(SizeOfHeaders); }
    WORD    GetSubsystem( )
            { return GET_OPTIONAL_HEADER_FIELD(Subsystem); }
    ULONGLONG   GetSizeOfStackReserve( )
            { return GET_OPTIONAL_HEADER_FIELD(SizeOfStackReserve); }
    ULONGLONG   GetSizeOfStackCommit( )
            { return GET_OPTIONAL_HEADER_FIELD(SizeOfStackCommit); }
    ULONGLONG   GetSizeOfHeapReserve( )
            { return GET_OPTIONAL_HEADER_FIELD(SizeOfHeapReserve); }
    ULONGLONG   GetSizeOfHeapCommit( )
            { return GET_OPTIONAL_HEADER_FIELD(SizeOfHeapCommit); }
	WORD		GetOptionalHeaderCharacteristics( )
			{ return GET_OPTIONAL_HEADER_FIELD(DllCharacteristics); }

    DWORD   GetDataDirectoryEntryRVA( DWORD id );
    PVOID   GetDataDirectoryEntryPointer( DWORD id );
    DWORD   GetDataDirectoryEntrySize( DWORD id );

    PVOID   GetReadablePointerFromRVA( DWORD rva );

	bool IsSelfRegistering();
	
	bool LoadFailed()
	{
		return m_bLoadFailed;
	}

	stringx GetErrorDescription()
	{
		return m_sErrorDescription;
	}
	
	long GetError()
	{
		return m_lError;
	}

	bool IsDotNetPE();
	bool IsCppCli();

	eType GetNetAssemblyType();
	stringxi GetAssemblyCLRMetadataVersion();

    protected:

    DWORD   RVAToFileOffset( DWORD rva );

	PIMAGE_DATA_DIRECTORY GetDataDirectoryEntry(DWORD id);

    PIMAGE_NT_HEADERS m_pNtHdr;

private:
	PIMAGE_COR20_HEADER GetDotNetHeader();

	bool    m_bLoadFailed;
	long    m_lError;
	stringx m_sErrorDescription;	
};

#endif
