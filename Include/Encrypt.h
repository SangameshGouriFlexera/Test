#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_

#include "auto_handle.hxx"

class CEncrypt
{
public:
	CEncrypt::CEncrypt()
	{
	}

	CEncrypt::~CEncrypt()
	{
	}

	bool EncryptString(LPCTSTR lpszInput, LPTSTR lpszOutput)
	{
		DWORD dwSize = _tcslen(lpszInput);

		if(dwSize > 0)
		{
			BYTE *pBuffer = new BYTE[dwSize + 1];

			if(pBuffer == NULL)
				return false;

			_tcscpy(reinterpret_cast<TCHAR*>(pBuffer), lpszInput);

			BYTE *pTempBuffer = pBuffer;
			for (DWORD nCount = 0 ; nCount < dwSize ; nCount++ )
			{
				*pTempBuffer ^= 0xFF;
				pTempBuffer++;
			}

			_tcscpy(lpszOutput, reinterpret_cast<TCHAR*>(pBuffer));

			delete [] pBuffer;
		}
		return true;
	}

	bool DecryptString(LPCTSTR lpszInput, LPTSTR lpszOutput)
	{
		return EncryptString(lpszInput, lpszOutput);
	}

	bool EncryptFile(LPCTSTR lpszFileName)
	{
		is::auto_hfile hFile;
		if(OpenExistingFile(lpszFileName, hFile))
		{
			DWORD dwSize = ::GetFileSize(hFile, NULL);
			if(dwSize == INVALID_FILE_SIZE)
				return false;

			BYTE *pBuffer = new BYTE[dwSize];
			if(pBuffer == NULL)
				return false;

			::ZeroMemory(pBuffer, dwSize);

			if(this->Read(hFile, reinterpret_cast<void*>(pBuffer), dwSize))
			{
				BYTE *pTempBuffer = pBuffer;
				for (DWORD nCount = 0 ; nCount < dwSize ; nCount++ )
				{
					*pTempBuffer ^= 0xFF;
					pTempBuffer++;
				}

				hFile.close();

				if(OpenNewFile(lpszFileName, hFile))
					this->Write(hFile, reinterpret_cast<void*>(pBuffer), dwSize);
			}
			delete [] pBuffer;
		} 
		return true;
	}

	bool DecryptFile(LPCTSTR lpszFileName)
	{
		return EncryptFile(lpszFileName);
	}

private:
	
	bool OpenExistingFile(LPCTSTR lpszFileName, is::auto_hfile& hFileHandle)
	{
		hFileHandle = ::CreateFile(lpszFileName, GENERIC_READ | GENERIC_WRITE,
							   FILE_SHARE_READ,
							   NULL,
							   OPEN_EXISTING,
							   FILE_ATTRIBUTE_NORMAL,
							   NULL);

		return (hFileHandle == INVALID_HANDLE_VALUE) ? false : true;
	}

	bool OpenNewFile(LPCTSTR lpszFileName, is::auto_hfile& hFileHandle)
	{
		hFileHandle = ::CreateFile(lpszFileName, GENERIC_READ | GENERIC_WRITE,
							   FILE_SHARE_READ,
							   NULL,
							   CREATE_ALWAYS,
							   FILE_ATTRIBUTE_NORMAL,
							   NULL);

		return (hFileHandle == INVALID_HANDLE_VALUE) ? false : true;
	}

	bool Read(is::auto_hfile& hFile, void* lpBuf, UINT nBufSize)
	{
		_ASSERT(hFile);
		_ASSERT(lpBuf);

		if(0 == nBufSize)
			return false;

		DWORD dwRead = 0;
		if(!::ReadFile(hFile, lpBuf, nBufSize, &dwRead, NULL))
			return false;

		return true;
	}

	bool Write(is::auto_hfile& hFile, const void* lpBuf, UINT nBufSize)
	{
		_ASSERT(hFile);

		if(0 == nBufSize)
			return false;

		DWORD nWritten = 0;
		if (!::WriteFile(hFile, lpBuf, nBufSize, &nWritten, NULL))
			return false;

		_ASSERT(nWritten == nBufSize);

		return true;
	}
};

#endif // _ENCRYPT_H_
