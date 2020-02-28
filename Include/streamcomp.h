#ifndef __STREAMCOMP_H
#define __STREAMCOMP_H

#if _MSC_VER < 1400
	// VC6
	#ifdef UNICODE
		#pragma comment( lib, "zlibvc6u" )
	#else
		#pragma comment( lib, "zlibvc6" )
	#endif
#elif _MSC_VER < 1500
	// VC8
	#ifdef UNICODE
		#ifdef _DLL
			#pragma comment( lib, "zlibvc8dllu" )
		#else
			#pragma comment( lib, "zlibvc8u" )
		#endif
	#else
		#pragma comment( lib, "zlibvc8" )
	#endif
#else
	// VC9
	#ifdef UNICODE
		#ifdef _DLL
			#pragma comment( lib, "zlibvc9dllu" )
		#else
			#pragma comment( lib, "zlibvc9u" )
		#endif
	#else
		#pragma comment( lib, "zlibvc9" )
	#endif
#endif // _MSC_VER < 1400\



#include "stringx.h"
#include "stream.h"

#define CHUNK 16384

#define COMP_LEVEL_NO_COMPRESSION         0
#define COMP_LEVEL_BEST_SPEED             1
#define COMP_LEVEL_BEST_COMPRESSION       9
#define COMP_LEVEL_DEFAULT_COMPRESSION  (-1)

typedef DWORD (__stdcall *PSTREAMCOMP_READ_CALLBACK)(LPBYTE lpBuffer, DWORD dwBufferSize, DWORD& dwBytesRead, PVOID pvContext);
typedef DWORD (__stdcall *PSTREAMCOMP_WRITE_CALLBACK)(LPBYTE lpBuffer, DWORD dwBufferSize, DWORD& dwBytesWritten, PVOID pvContext);

class CStreamCompression
{
public:
	CStreamCompression(int nCompressionLevel=COMP_LEVEL_DEFAULT_COMPRESSION)
		: m_nCompressionLevel(nCompressionLevel),
		m_pvCallbackContext(NULL)
	{}
	~CStreamCompression() {}

	void SetCallbackContext(PVOID pvContext) { m_pvCallbackContext = pvContext; }

	DWORD CompressIntoStream(const stringxi& sInputFile, PSTREAMCOMP_WRITE_CALLBACK pWriteCallback, DWORD& dwCompressedFileSize);
	DWORD DecompressFromStream(const stringxi& sOutputFile, PSTREAMCOMP_READ_CALLBACK pReadCallback);

	//
	// Deprecated, please use the other overloads or use CompressIntoStream/DecompressFromStream.
	//
	DWORD Compress(const stringxi& sInputFile, const stringxi& sOutputFile);
	DWORD Decompress(const stringxi& sInputFile, const stringxi& sOutputFile);

	DWORD Compress(LPBYTE rbIn, DWORD cbIn, LPBYTE rbOut, DWORD* cbOut);
	DWORD Decompress(LPBYTE rbIn, DWORD cbIn, LPBYTE rbOut, DWORD* cbOut);

private:
	static DWORD __stdcall DecompressReadCallback(LPBYTE lpBuffer, DWORD dwBufferSize, DWORD& dwBytesRead, PVOID pvContext);
	static DWORD __stdcall CompressWriteCallback(LPBYTE lpBuffer, DWORD dwBufferSize, DWORD& dwBytesWritten, PVOID pvContext);

	int m_nCompressionLevel;
	PVOID m_pvCallbackContext;
};

#endif