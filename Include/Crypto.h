#ifndef _CRYPTO_H_
#define _CRYPTO_H_

BYTE EncryptByte(BYTE bText, BYTE bKey/*=0*/);
BOOL EncryptBuffer(LPBYTE lpBuff, DWORD dwBuff, LPCSTR lpszKey, int nKeyOffset);
BOOL EncryptBuffer(LPBYTE lpBuff, DWORD dwBuff, LPCSTR lpszKey);
BOOL EncryptFile(LPCTSTR lpszFile, LPCSTR lpszKey);

BYTE DecryptByte(BYTE bText, BYTE bKey=0);
BOOL DecryptFile(LPCTSTR lpszFile, LPCSTR lpszKey);
BOOL DecryptBuffer(LPBYTE lpBuff, DWORD dwBuff, LPCSTR lpszKey, int nKeyOffset);
BOOL DecryptBuffer(LPBYTE lpBuff, DWORD dwBuff, LPCSTR lpszKey);
BOOL DecryptFile(HANDLE hFile, LPCSTR lpszKey);

BOOL DecryptBufferFromRegistry(LPCSTR szInput, LPCSTR lpszKey, LPSTR lpszOutput, DWORD dwOutputSize);
BOOL EncryptBufferForRegistry(LPCSTR szInput, LPCSTR lpszKey, LPSTR lpszOutput, DWORD dwOutputSize);

LPBYTE GetDecryptionKey(LPCSTR lpszKey);

#endif // _CRYPTO_H_
