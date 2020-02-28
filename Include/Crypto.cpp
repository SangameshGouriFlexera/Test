#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "Crypto.h"
#include "stringx.h"

/////////////////////////////////////////////////////////////////////////////
// Definitions

#define LONIBBLE(X)			(X & 0x0f)
#define HINIBBLE(X)			(X & 0xf0)

#define PRIVATE_KEY			0x13,0x35,0x86,0x07		//0x07863513

/////////////////////////////////////////////////////////////////////////////

BYTE EncryptByte(BYTE bText, BYTE bKey/*=0*/)
{
	bText = (BYTE)(~bText);
	bText ^= bKey;
	bText = (BYTE)( ((LONIBBLE(bText)) << 4 ) | ( (HINIBBLE(bText)) >> 4) );
	return bText;
}

BOOL EncryptBuffer(LPBYTE lpBuff, DWORD dwBuff, LPCSTR lpszKey, int nKeyOffset)
{
	LPBYTE lpbKey=GetDecryptionKey(lpszKey);

	if(NULL==lpbKey)
		return FALSE;

	for(DWORD i=0, len=lstrlenA(lpszKey); i<dwBuff; i++ )
		lpBuff[i]=EncryptByte(lpBuff[i], lpbKey[(i + nKeyOffset) % len]);

	delete [] lpbKey;

	return TRUE;
}

BOOL EncryptBuffer(LPBYTE lpBuff, DWORD dwBuff, LPCSTR lpszKey)
{
	return EncryptBuffer(lpBuff, dwBuff, lpszKey, 0);
}

BOOL EncryptFile(LPCTSTR lpszFile, LPCSTR lpszKey)
{
	BOOL bSuccess=FALSE;
	HANDLE hFile=CreateFile(lpszFile, GENERIC_READ|GENERIC_WRITE,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if(INVALID_HANDLE_VALUE != hFile)
	{
		DWORD dwSize=GetFileSize(hFile, NULL);
		HANDLE hMap=CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0,
			NULL);

		if(hMap)
		{
			LPBYTE lpBuff=(LPBYTE)MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0,
				0);

			if(lpBuff)
			{
				CHAR szKey[MAX_PATH];
				strcpy_s(szKey, MAX_PATH, stringx(lpszKey));
				bSuccess=EncryptBuffer(lpBuff, dwSize, szKey);
				UnmapViewOfFile(lpBuff);
			}

			CloseHandle(hMap);
		}

		CloseHandle(hFile);
	}

	return bSuccess;
}		

BYTE DecryptByte(BYTE bText, BYTE bKey/*=0*/)
{
	bText = (BYTE)( ((LONIBBLE(bText)) << 4 ) | ( (HINIBBLE(bText)) >> 4) );
	bText ^= bKey;
	bText = (BYTE)(~bText);
	return bText;
}

BOOL DecryptBuffer(LPBYTE lpBuff, DWORD dwBuff, LPCSTR lpszKey, int nKeyOffset)
{
	LPBYTE lpbKey=GetDecryptionKey(lpszKey);

	if(NULL==lpbKey)
		return FALSE;

	for(DWORD i=0, len=lstrlenA(lpszKey); i<dwBuff; i++ )
		lpBuff[i]=DecryptByte(lpBuff[i], lpbKey[(i + nKeyOffset) % len]);

	delete [] lpbKey;

	return TRUE;
}

BOOL DecryptBuffer(LPBYTE lpBuff, DWORD dwBuff, LPCSTR lpszKey)
{
	return DecryptBuffer(lpBuff, dwBuff, lpszKey, 0);
}

BOOL DecryptFile(LPCTSTR lpszFile, LPCSTR lpszKey)
{
	BOOL bSuccess=FALSE;
	HANDLE hFile=CreateFile(lpszFile, GENERIC_READ|GENERIC_WRITE,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if(INVALID_HANDLE_VALUE != hFile)
	{
		bSuccess = DecryptFile( hFile, lpszKey);

		CloseHandle(hFile);
	}

	return bSuccess;
}

BOOL DecryptFile(HANDLE hFile, LPCSTR lpszKey)
{
	BOOL bSuccess=FALSE;
	
	DWORD dwSize=GetFileSize(hFile, NULL);
	HANDLE hMap=CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0,
		NULL);

	if(hMap)
	{
		LPBYTE lpBuff=(LPBYTE)MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0,
			0);

		if(lpBuff)
		{
			bSuccess=DecryptBuffer(lpBuff, dwSize, lpszKey);
			UnmapViewOfFile(lpBuff);
		}

		CloseHandle(hMap);
	}

	return bSuccess;
}

LPBYTE GetDecryptionKey(LPCSTR lpszKey)
{
	BYTE arPrivateKey[]={ PRIVATE_KEY };
	DWORD len=lstrlenA(lpszKey), mod=sizeof(arPrivateKey);
	LPBYTE pbKey=new BYTE[len];

	if(pbKey)
	{
		// Combine the user key with the private key
		for(DWORD i=0; i<len; i++)
			pbKey[i]=(BYTE)(lpszKey[i] ^ arPrivateKey[i % mod]);
	}

	return pbKey;
}

BOOL DecryptBufferFromRegistry(LPCSTR szInput, LPCSTR lpszKey, LPSTR lpszOutput, DWORD dwOutputSize)
{
	unsigned int nCount = 0;
	unsigned int nLength = strlen(szInput);
	int nPos = 0;\

	BYTE* pByte = (BYTE*)lpszOutput;

	if ((2 * dwOutputSize) > (nLength + 1))
	{
		while(nCount < nLength)
		{
			CHAR szConvert[4];
			strncpy_s(szConvert, 4, &szInput[nCount], 2);
			pByte[nPos] = (BYTE)(strtol(szConvert, 0,16) & 0xFF);
			nPos ++;
			nCount++;
			nCount++;
		}
		lpszOutput[nPos] = '\0';
		DecryptBuffer(pByte, nPos, lpszKey);
		return true;
	}
	else
	{
		return false;
	}
}

BOOL EncryptBufferForRegistry(LPCSTR szInput, LPCSTR lpszKey, LPSTR lpszOutput, DWORD dwOutputSize)
{
	BYTE* pByte = (BYTE*) szInput;

	// Figure out the Size in Bytes
	unsigned int nCount = 0;
	while(pByte[nCount] != '\0' && (nCount < ((strlen(szInput)) +1 )))
	{
		nCount++;
	}

	BYTE* pEncryptedByte = new BYTE[nCount+1];
	strcpy_s((LPSTR)pEncryptedByte, nCount + 1, szInput);
	EncryptBuffer(pEncryptedByte, nCount, lpszKey);

	bool bReturn = false;
	
	strcpy_s(lpszOutput, dwOutputSize, "");

	if (dwOutputSize > (nCount*2 +1))
	{
		unsigned int nCounter = 0;
		while (nCounter < nCount)
		{
			CHAR szOneChar[4];
			sprintf(szOneChar, "%02X", pEncryptedByte[nCounter]);
			strcat_s(lpszOutput, dwOutputSize, szOneChar);
			nCounter++;
		}
		bReturn = true;
	}

	delete pEncryptedByte;
	return bReturn;
}