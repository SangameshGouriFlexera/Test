#ifndef _STREAM_H_
#define _STREAM_H_
/*=======================================================================*/
/*              Installshield Software Corp. (c) 1996-2000               */
/*                  Schaumburg, Illinois 60173  USA                      */
/*                       All Rights Reserved.                            */
/*=======================================================================*/
//
//
//   File    : Stream.h
//
//   Purpose : This file contains the information to add files to EXE files
//

#include <map>

#define IS_STREAM_VERSION_LEGACY	1
#define IS_STREAM_VERSION_EXTENDED	2

#define ERROR_RES_EXISTS -100
#define FILEINFO_ATTRIB_ENCRYPTED 2
#define FILEINFO_ATTRIB_ENCRYPTED_FAST 4

#define ERROR_ADD_RESOURCE_SUCCESS 1
#define ERROR_EXTRACT_RESOURCE_SUCCESS ERROR_ADD_RESOURCE_SUCCESS

typedef enum EnumProgressMessage {
	epmExtracting,
	epmDecompressing	
};

class IStreamProgress
{
public:
	virtual bool SetProgress(unsigned long lCurrent, unsigned long lTotal) = 0;
	virtual void SetProgressMessage(EnumProgressMessage epmProgressMessage, LPCWSTR lpszFile) { /* do nothing by default */ }
};

//------------------------------------------------------------------------
// Constants

//------------------------------------------------------------------------
// Internal File header information 
typedef struct _Fileinfo
{
    CHAR   szFileName[MAX_PATH];
    DWORD   dwAttributes;
    USHORT  uLanguage;
    DWORD   dwSize;
    DWORD   dwDateTime;
    DWORD   dwVersionInfo;
    USHORT  uCompression;
    CHAR   szMisc[30];
} FILEINFO;

//------------------------------------------------------------------------
// Internal header to hold information about the files.
#pragma pack(push, 1)

typedef struct _IsHeader
{
	CHAR   szSignature[14];
	USHORT  uNumFiles;
	CHAR   szMisc[30];
} ISHEADER;

typedef struct _IsHeaderEx
{
	CHAR szSignature[14];
	USHORT uNumFiles;
	DWORD dwStreamVersion;
	BYTE reserved[26];
} ISHEADEREX;

typedef struct _FileInfoEx
{
	DWORD cbFileNameSize;
	DWORD dwAttributes;
	USHORT uLanguage;
	DWORD dwSize;
	DWORD dwDateTime;
	DWORD dwVersionInfo;
	USHORT uCompression;
} FILEINFOEX;

#pragma pack(pop)

enum EnumStreamFileEncryption
{
	esfeNone,
	esfeEncrypted,
	esfeEncryptedFast
};

class CStreamedFileInfo
{
public:
	CStreamedFileInfo(DWORD nStreamVersion);

	ULONG Initialize(HANDLE hStream, DWORD dwFileInfoOffset);

	void SetFileName(const stringxi& sFileName) { m_sFileName = sFileName; }
	void SetAttributes(DWORD dwAttributes) { m_dwAttributes = dwAttributes; }
	void SetEncrypted(EnumStreamFileEncryption eType)
	{
		if(eType == esfeNone)
			m_dwAttributes &= ~(FILEINFO_ATTRIB_ENCRYPTED_FAST | FILEINFO_ATTRIB_ENCRYPTED);
		else if(eType == esfeEncrypted)
			m_dwAttributes |= FILEINFO_ATTRIB_ENCRYPTED;
		else if(eType == esfeEncryptedFast)
			m_dwAttributes |= FILEINFO_ATTRIB_ENCRYPTED | FILEINFO_ATTRIB_ENCRYPTED_FAST;
	}
	void SetLanguage(USHORT usLanguage) { m_usLanguage = usLanguage; }
	void SetSize(DWORD dwSize) { m_dwSize = dwSize; }
	void SetDateTime(DWORD dwDateTime) { m_dwDateTime = dwDateTime; }
	void SetVersion(DWORD dwVersion) { m_dwVersionInfo = dwVersion; }
	void SetCompression(USHORT usCompression) { m_usCompression = usCompression; }
	void SetFileDataOffset(DWORD dwOffset) { m_dwFileDataOffset = dwOffset; }

	stringxi GetFolderName() { return m_sFileName.path_dir(); }
	stringxi GetFileName() { return m_sFileName.path_file(); }
	stringxi GetFullFileName() { return m_sFileName; }
	DWORD GetAttributes() { return m_dwAttributes; }
	bool GetEncrypted() { return (m_dwAttributes & FILEINFO_ATTRIB_ENCRYPTED) || (m_dwAttributes & FILEINFO_ATTRIB_ENCRYPTED_FAST); }
	bool GetEncryptedFast() { return (m_dwAttributes & FILEINFO_ATTRIB_ENCRYPTED_FAST) != 0; }
	USHORT GetLanguage() { return m_usLanguage; }
	DWORD GetSize() { return m_dwSize; }
	DWORD GetDateTime() { return m_dwDateTime; }
	DWORD GetVersion() { return m_dwVersionInfo; }
	USHORT GetCompression() { return m_usCompression; }
	DWORD GetFileDataOffset() { return m_dwFileDataOffset; }

	DWORD WriteFileInfoToStream(HANDLE hStream);
	DWORD GetFileInfoSize();

private:
	stringxi m_sFileName;
	DWORD m_dwAttributes;
	USHORT m_usLanguage;
	DWORD m_dwSize;
	DWORD m_dwDateTime;
	DWORD m_dwVersionInfo;
	USHORT m_usCompression;
	DWORD m_dwFileDataOffset;

	HANDLE m_hStream;
	DWORD m_dwStreamVersion;
};

typedef enum EnumCompressionType {
	ectNone = 0,
	ectZlib
};

//------------------------------------------------------------------------
// Callback functions
typedef int (__stdcall *PFNENUMXFILES)(CStreamedFileInfo *pFileInfo, LPARAM lData, stringxi& sOutput);
typedef int (__stdcall *PFNENUMFILES)(CStreamedFileInfo *pFileInfo);

class STREAM
{
public:

    // = FOUNDATION

    STREAM(LPCTSTR lpszStub);
    virtual ~STREAM();

	void UseEncryption(bool bEncrypt, bool bEncryptFast = false)
	{
		m_bEncrypt = bEncrypt;
		m_bEncryptFast = bEncryptFast;
	}

	void UseCompression(bool bCompress)
	{
		m_bCompress = bCompress;
	}

	void SetCompressionLevel(int nCompressionLevel)
	{
		m_nCompressionLevel = nCompressionLevel;
	}

	void SetEncrypted(CStreamedFileInfo* pFileInfo, bool bEncrypted, bool bUseFast = false)
	{
		if(bEncrypted)
			pFileInfo->SetEncrypted(bUseFast ? esfeEncrypted : esfeEncryptedFast);
		else
			pFileInfo->SetEncrypted(esfeNone);
	}

    // = MODIFIERS

    int AddResource(const stringxi& sInput, const stringxi& sFileName, IStreamProgress* pProgress = NULL);
    int ReplaceResource(const stringxi& sInput, const stringxi& sFileName, IStreamProgress* pProgress = NULL);

    // = ACCESS

	bool IsInstallShield() const;
	DWORD GetError() const;
    const DWORD GetTotalFileSize();

	bool FileExistsInStream(const stringxi& sResourceName);
	bool QueryResource(const stringxi& sResourceName, CStreamedFileInfo **pFileInfo, DWORD& dwPosition);

	int RemoveFile(const stringxi& sFileName);
	int ExtractResource(const stringxi& sResourceName, const stringxi& sOutputPath, IStreamProgress* pProgress = NULL);

	BOOL EnumExtractFiles(PFNENUMXFILES pfnEnumFilesCallback, LPARAM lData, IStreamProgress* pProgress = NULL);
    BOOL EnumFiles(PFNENUMFILES pfnEnumFilesCallback);

private:
	DWORD CheckStreamHeader(ISHEADER *pHeader);
	void PopulateStreamHeader(PVOID pHeader, USHORT uFileCount);

    void InitFileList(int nNumFiles);

    int ExtractResourceEx(CStreamedFileInfo *pFileInfo, DWORD dwPosition, const stringxi& sOutput, IStreamProgress* pProgress = NULL);

    DWORD StreamSetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
	DWORD StreamGetFilePointer(HANDLE hFile) const;

    int RemoveFileFromList(CStreamedFileInfo *pFileInfo);

	DWORD AddFileDataToStream(const stringxi& sInputFile, CStreamedFileInfo *pFileInfo, HANDLE hOutput, IStreamProgress *pProgress);
	DWORD AddFileDataCompressToStream(const stringxi& sInputFile, CStreamedFileInfo *pFileInfo, HANDLE hOutput, DWORD& dwCompressedSize, IStreamProgress *pProgress);
	static DWORD __stdcall StreamCompressWriteCallback(LPBYTE lpBuffer, DWORD dwBufferSize, DWORD& dwBytesWritten, PVOID pvContext);

	DWORD ExtractFileDataFromStream(const stringxi &sOutputFile, CStreamedFileInfo *pFileInfo, HANDLE hInput, IStreamProgress *pProgress);
	DWORD ExtractFileDataDecompressFromStream(const stringxi &sOutputFile, CStreamedFileInfo *pFileInfo, HANDLE hInput, IStreamProgress *pProgress);
	static DWORD __stdcall StreamDecompressReadCallback(LPBYTE lpBuffer, DWORD dwBufferSize, DWORD& dwBytesWritten, PVOID pvContext);

private:

    stringxi	m_sStub;
    HANDLE      m_hStub;    
    BOOL        m_bInit;    

	bool		m_bEncrypt;
	bool		m_bEncryptFast;

	bool		m_bCompress;

    DWORD       m_dwStubSize;    
    DWORD       m_dwLastError;

	int			m_nCompressionLevel;

	DWORD		m_dwHeaderSize;
	DWORD		m_dwFileInfoSize;

	typedef std::map<stringxi, CStreamedFileInfo *> MAP_STREAM_FILES;
	MAP_STREAM_FILES m_mapFileList;

	mutable DWORD m_nStreamVersion;

	bool		m_bIsValidStream;

};

//------------------------------------------------------------------------
#endif // _STREAM_H_
