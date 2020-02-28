#pragma once

class CMemoryMappedFile
{
public:

	enum errMMF {   errMMF_NoError, errMMF_FileOpen, errMMF_FileMapping, errMMF_MapView };

    CMemoryMappedFile( BSTR pszFileName );
    ~CMemoryMappedFile();
    
    PVOID GetBase() { return m_pMemoryMappedFileBase; }
    DWORD GetFileSize() const { return m_cbFile; }
    bool IsValid( ) const { return errMMF_NoError == m_errCode; } 
    errMMF  GetErrorType() const { return m_errCode; }

private:

    HANDLE m_hFile;
    HANDLE m_hFileMapping; // Handle of memory mapped file
    PVOID m_pMemoryMappedFileBase;
    DWORD m_cbFile;
    errMMF m_errCode;  
};

typedef CMemoryMappedFile *PCMemoryMappedFile;


