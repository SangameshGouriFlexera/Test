// CRC.h
//

#ifndef _CRC_H__INCLUDED_
#define _CRC_H__INCLUDED_


/////////////////////////////////////////////////////////////////////////////
// Definitions

#define CRC32_POLYNOMIAL	0xEDB88320L



/////////////////////////////////////////////////////////////////////////////
// Prototypes

void OpenCrcEngine();
void CloseCrcEngine();
DWORD CalculateBufferValue( LPBYTE buffer, DWORD count, DWORD crc );
DWORD CalculateFromFile( HANDLE hFile );
DWORD CalculateCRCFromFile( LPCTSTR szFileSpec );



/////////////////////////////////////////////////////////////////////////////

#endif//#ifndef _CRC_H__INCLUDED_
