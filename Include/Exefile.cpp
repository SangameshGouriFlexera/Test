//==========================================
// Matt Pietrek
// Microsoft Systems Journal, Feb 1997
// FILE: EXEFILE.CPP
//==========================================
#include "stdafx.h"
#include "exefile.h"

// Thanks to compiling XP support for runtime projects...
#ifndef IMAGE_FILE_MACHINE_ARMNT
#define IMAGE_FILE_MACHINE_ARMNT             0x01c4  // ARM Thumb-2 Little-Endian
#endif

CExeFile::CExeFile( BSTR bstrFileName ) : CMemoryMappedFile( bstrFileName )
{
    m_errorType = errEXE_FILE_FILE_NOT_FOUND;
    m_secondaryHeaderOffset = -1;   // A bogus value to catch bugs
    m_exeType = exeType_Invalid;

    if ( ! CMemoryMappedFile::IsValid() )
        return;     // m_errorType already set to errEXE_FILE_FILE_NOT_FOUND

    // If we get here, the file exists, and was mapped.  We're still not
    // sure that it's a valid EXE though
    m_errorType = errEXE_FILE_INVALID_FORMAT;

    if ( GetFileSize() < sizeof(IMAGE_DOS_HEADER) )
        return;
    
    PIMAGE_DOS_HEADER pDosHdr = (PIMAGE_DOS_HEADER)GetBase();
    if ( IMAGE_DOS_SIGNATURE != pDosHdr->e_magic )
        return;

    // If we get here, it's at least a DOS 'MZ' file
    m_errorType = errEXE_FILE_NO_ERROR;

    if ( pDosHdr->e_lfarlc < 0x40 ) // Theoretically, this field must be >=
    {                               // 0x40 for it to be a non-DOS executable
        m_exeType = exeType_DOS;
        return;
    }

    // Sanity check.  Make sure the "new header" offset isn't past the end
    // of the file
    if ( pDosHdr->e_lfanew > (LONG)GetFileSize() )
        return;

    // Make a pointer to the secondary header   
    m_secondaryHeaderOffset = pDosHdr->e_lfanew;
    PWORD pSecondHdr = MakePtr( PWORD, GetBase(), m_secondaryHeaderOffset );

    // Decide what type of EXE, based on the start of the secondary header
    switch ( *pSecondHdr )
    {
        case IMAGE_OS2_SIGNATURE: m_exeType = exeType_NE; break;
        case IMAGE_VXD_SIGNATURE: m_exeType = exeType_VXD; break;
        case 0x4558: m_exeType = exeType_LX; break;     // OS/2 2.X
    }
    
    if ( *(PDWORD)pSecondHdr == IMAGE_NT_SIGNATURE )
	{
		if(((PIMAGE_NT_HEADERS)pSecondHdr)->FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64 && ((PIMAGE_NT_HEADERS)pSecondHdr)->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC)
			m_exeType = exeType_PE64;
		else if(((PIMAGE_NT_HEADERS)pSecondHdr)->FileHeader.Machine == IMAGE_FILE_MACHINE_IA64 && ((PIMAGE_NT_HEADERS)pSecondHdr)->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC)
			m_exeType = exeType_PEIA64;
		else if(((PIMAGE_NT_HEADERS)pSecondHdr)->FileHeader.Machine == IMAGE_FILE_MACHINE_ARMNT)
			m_exeType = exeType_PEARM;
		else
			m_exeType = exeType_PE;
	}
}

PSTR CExeFile::GetFileTypeDescription( void )
{
    // Returns a static string that describes what type this file is
    switch ( m_exeType )
    {
        case exeType_DOS:     return "DOS";
        case exeType_NE:      return "NE";
        case exeType_VXD:     return "VXD";
        case exeType_LX:      return "LX";
        case exeType_PE:      return "PE";
		case exeType_PE64:	  return "PE64";
		case exeType_PEIA64:  return "PEIA64";
		case exeType_PEARM:   return "PEARM";
        default:              return "Invalid";
    }
}
