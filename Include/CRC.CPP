// CRC.cpp
//

#include "afx.h"
#include "CRC.h"


/////////////////////////////////////////////////////////////////////////////
// Definitions

#define BUFFSIZE 32768



/////////////////////////////////////////////////////////////////////////////
// Globals

LPDWORD g_pCrcTable=NULL;



/////////////////////////////////////////////////////////////////////////////

DWORD CalculateCRCFromFile( LPCTSTR szFileSpec )
{
	DWORD dwCRC=0;
	HANDLE hFile=NULL;

	OpenCrcEngine();

	hFile=CreateFile( szFileSpec, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );

	if(INVALID_HANDLE_VALUE != hFile)
	{
		dwCRC = CalculateFromFile( hFile );

		CloseHandle( hFile );
	}

	CloseCrcEngine();

	return dwCRC;
}

void OpenCrcEngine()
{
	if(NULL==g_pCrcTable)
	{
		DWORD crc=0;
		int i=0, j=0;

		g_pCrcTable = new DWORD[256];

		for(i=0; i <= 255; i++)
		{
			crc=i;

			for(j=8; j > 0; j--)
			{
				if(crc & 1)
					crc = (crc >> 1) ^ CRC32_POLYNOMIAL;
				else
					crc >>= 1;
			}

			g_pCrcTable[i] = crc;
		}
	}
}

void CloseCrcEngine()
{
	if(g_pCrcTable)
		delete [] g_pCrcTable;

	g_pCrcTable=NULL;
}

DWORD CalculateBufferValue( LPBYTE buffer, DWORD count, DWORD crc )
{
	while( count-- )
	{
		DWORD temp1 = (crc >> 8) & 0x00FFFFFFL;
		DWORD temp2 = g_pCrcTable[((int)crc ^ *buffer++) & 0xFF];

		crc = temp1 ^ temp2;
	}

	return crc;
}

DWORD CalculateFromFile( HANDLE hFile )
{
	DWORD crc = 0xFFFFFFFFL;

	if( hFile != INVALID_HANDLE_VALUE )
	{
		DWORD dwSize=0;
		LPBYTE pBuffer=new BYTE[BUFFSIZE];

		SetFilePointer( hFile, 0, NULL, FILE_BEGIN );

		while( ReadFile( hFile, (LPVOID)pBuffer, BUFFSIZE, &dwSize, NULL )
			&& dwSize )
		{
			crc = CalculateBufferValue( pBuffer, dwSize, crc );
		}

		delete [] pBuffer;
	}

	crc ^= 0xFFFFFFFFL;

	return crc;
}
