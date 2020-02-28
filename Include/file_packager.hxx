#ifndef _FILE_PACKAGER_H_
#define _FILE_PACKAGER_H_

#include <winver.h>
#include <vector>
#include "is.h"
#include "auto_handle.hxx"
#include "zpath.h"
#include "fileLt.h"
#include "stringx.h"
#include "pesize.h"

#define BUFFER_SIZE 16384
////////////////////////////////////////////////////////////////////////////////////////////////////
//	Purpose:
//		This class was created out of a need to package files in a way that they can be extracted
//      without the overhead of the cab api, or the installshield kernel.  Can be used in conjuction
//      with Compress.exe and the LZ API.
//
//	Usage:
/**/
/**/#if 0
/**/
/**/	file_packager	pack; 
/**/
/**/    if (bCreate == true)
/**/        pack.create_package_from_folder( "C:\\test\\Files.pck", "C:\\SourceFolder" );
/**/    else
/**/	    pack.unpack_all( "C:\\test\\Files.pck", "C:\\Destination" );
/**/
/**/
/**/#endif
//
////////////////////////////////////////////////////////////////////////////////////////////////////

_IS_BEGIN

class file_packager
{

public:
    file_packager():m_bSilent(false), m_dwFileCount(0) {};
    ~file_packager() {};

    long create_package_from_folder( TCHAR *pszPackage, TCHAR *pszSource );
    long unpack_all( TCHAR *pszPackage, TCHAR *pszDestination );
    long append_file( TCHAR *pszPackage, TCHAR *pszSourceFile, TCHAR *pszCompressEXE = NULL, TCHAR *pszStoreName = NULL, TCHAR *pszParent = NULL );
    long append_folder( TCHAR *pszPackage, TCHAR *pszSourceFolder, TCHAR *pszParent = NULL, TCHAR *pszFirst = NULL );
    bool unpack_by_name( TCHAR *pszPackage, TCHAR *pszDestination, TCHAR *pszSourceFile, bool bDestIncludesName = false );
    long unpack_all_from_exe( TCHAR *pszPackage, TCHAR *pszDestination, std::vector<stringxi>* pvFiles = NULL, std::vector<stringxi>* pvFolders = NULL, bool bUnpackDataCab = false );
    long unpack_file_from_exe( TCHAR *pszPackage, TCHAR *pszDestination, TCHAR *pszFile );
    long find_file_info( TCHAR *pszPackage, TCHAR *pszFile, DWORD &dwOffset, DWORD &dwSize );
    bool file_exists( TCHAR *pszPackage, TCHAR *pszFile );
    void set_silent( bool bSilent ) { m_bSilent = bSilent; }
	long create_package(TCHAR *pszPackage, TCHAR *pszSourceFolder);

protected:

    // Note (Devin): Unpack_by_index was previously public, however since we don't provide a way to query the index from the name
    // this method requires that hard coded indexes be used which cannot be determined programmatically therefore this
    // method is only useful if the file indexes/names are hard-coded, so hide this method to prevent this kind of bad code.
    bool unpack_by_index( TCHAR *pszPackage, TCHAR *pszDestination, int iIndex, bool bDestIncludesName = false );
    bool unpack_by_index_or_name( TCHAR *pszPackage, TCHAR *pszDestination, TCHAR *pszSourceFile, int iIndex, bool bIndexOrName, bool bDestIncludesName = false );

private:
    DWORD get_PE_size( TCHAR *pszPEFile );
	DWORD GetEndOfStream(TCHAR *pszPackage, DWORD dwPackageSize);
    void MakeSureDirectoryExists(const zpath& pth);

    bool m_bSilent;
	DWORD m_dwFileCount;
};

inline long file_packager::create_package(TCHAR *pszPackage, TCHAR *pszSourceFolder)
{
	//
	// This is here to write out a count of files at the beginning
	// of the file stream before any files are written. Then we write
	// all the files to be streamed onto the compressed setup, and
	// then we seek back to the beginning of the stream where the file
	// count is written and write it again with the number of files
	// we counted while streaming.
	//
	file_lite fl;
	if(!fl.open_write(pszPackage, OPEN_ALWAYS))
		return -805;

	DWORD dwFileEnd = fl.seek(0, FILE_END);
	m_dwFileCount = 0;
	fl.write(&m_dwFileCount, sizeof(DWORD));
	fl.close();

	long lReturnVal = append_folder(pszPackage, pszSourceFolder);
	if(lReturnVal < 0)
		return lReturnVal;

	if(!fl.open_write(pszPackage, OPEN_ALWAYS))
		return -806;

	fl.seek(dwFileEnd, FILE_BEGIN);
	fl.write(&m_dwFileCount, sizeof(DWORD));
	fl.close();

	return 0;
}

inline long file_packager::append_folder( TCHAR *pszPackage, TCHAR *pszSourceFolder, TCHAR *pszParent/*=NULL*/, TCHAR *pszFirst/*=NULL*/ )
{


    TCHAR buff[MAX_PATH] = {0};
    ::lstrcpy( buff, pszSourceFolder );
    ::lstrcat(buff, _T("\\*.*"));
    ::WIN32_FIND_DATA finddata;
    auto_hfind hFind(::FindFirstFile(buff, &finddata));
    if(hFind == INVALID_HANDLE_VALUE)
    {
        //printf("Could not find files.\n\n");
        return -801;
    }

    TCHAR pszFile[MAX_PATH] = {0};
    BOOL b;
    do
    {
		long lAppend;
        ::lstrcpy( pszFile, pszSourceFolder );
        ::lstrcat( pszFile, _T("\\") );
        ::lstrcat( pszFile, finddata.cFileName );
        if( !(finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
		{
            lAppend = append_file( pszPackage, pszFile, NULL, NULL, pszParent );
			if ( lAppend < 0 )
				return lAppend;
		}
        else
        {
            if( (::lstrcmp(finddata.cFileName, _T(".")) != 0) && (::lstrcmp(finddata.cFileName, _T("..")) != 0) )
            {
                TCHAR pszNewParent[MAX_PATH] = {0};
                if( pszParent )
                {
                    ::lstrcpy( pszNewParent, pszParent );
                    ::lstrcat( pszNewParent, _T("\\") );
                    ::lstrcat( pszNewParent, finddata.cFileName );
                }
                else
                    ::lstrcpy( pszNewParent, finddata.cFileName );
                
                lAppend = append_folder( pszPackage, pszFile, pszNewParent, pszFirst );
				if ( lAppend < 0 )
					return lAppend;
            }
        }
        b = ::FindNextFile(hFind, &finddata);
    } while(b);

    return 0;
}

inline long file_packager::append_file( TCHAR *pszPackage, TCHAR *pszSourceFile, TCHAR *pszCompressEXE, TCHAR *pszStoreName, TCHAR *pszParent)
{
    bool bCompress = ( pszCompressEXE != NULL );
    bool bNewName = ( pszStoreName != NULL );
    TCHAR pszStoredFile[MAX_PATH];
    TCHAR pszSourceName[MAX_PATH];
    ::lstrcpy( pszStoredFile, pszSourceFile );

    file_lite fPkg;

    if(!fPkg.open_write(pszPackage, OPEN_ALWAYS))
    {
        //printf("Could not open output file");
        return -800;
    }

    TCHAR buff[MAX_PATH];
    ::WIN32_FIND_DATA finddata;
    auto_hfind hFind(::FindFirstFile( pszSourceFile, &finddata ));
    if((hFind == INVALID_HANDLE_VALUE) || (finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
    {
        //printf( "Could not find source file: %s", pszSourceFile );
        return -801;
    }

    DWORD   dwBlockSize, dwInfoHandle;
    TCHAR    pszVersion[25];
    lstrcpy( pszVersion, _T("0.0.0.0") );
    dwBlockSize = ::GetFileVersionInfoSize( pszSourceFile, (DWORD FAR *) &dwInfoHandle );
    if( dwBlockSize > 0 )
    {
        TCHAR* pInfo;
        pInfo = new TCHAR[ dwBlockSize + 1 ];
        if( ::GetFileVersionInfo( pszSourceFile, 0, dwBlockSize, pInfo ))
        {
            ::VS_FIXEDFILEINFO* vInfo;
            UINT uiLen;
            LPVOID pBuff;

            //Get the fixed file info structure
            if (::VerQueryValue( pInfo, _T("\\"), &pBuff, &uiLen ))
            {
                vInfo=(VS_FIXEDFILEINFO*)pBuff;
                ::wsprintf(pszVersion,_T("%d.%d.%d.%d"),HIWORD(vInfo->dwFileVersionMS),LOWORD(vInfo->dwFileVersionMS),
                           HIWORD(vInfo->dwFileVersionLS),LOWORD(vInfo->dwFileVersionLS));
            }
        }
        delete [] pInfo;
    }


    if( pszParent )
    {
        ::lstrcpy( pszSourceName, pszParent );
        ::lstrcat( pszSourceName, _T("\\") );
    }
    else
        ::lstrcpy( pszSourceName, _T("") );

    if( bNewName )
        ::lstrcat( pszSourceName, pszStoreName );
    else
        ::lstrcat( pszSourceName, finddata.cFileName );

    if( bCompress )
    {
        // pszStoredFile = TempPath + file(pszSourceFile) -> .xx_
		int iPos;
		::GetTempPath( MAX_PATH, pszStoredFile );
        for (iPos = ::lstrlen( pszSourceFile ) - 1; pszSourceFile[iPos]!='\\'; --iPos);
        ::lstrcat( pszStoredFile, pszSourceFile + iPos + 1 );
        iPos = ::lstrlen( pszStoredFile );
        pszStoredFile[iPos-1] = '_';

        TCHAR pszCommand[MAX_PATH];
		::wsprintf( pszCommand, _T("\"%s\" \"%s\" \"%s\""), pszCompressEXE, pszSourceFile, pszStoredFile );
        ::PROCESS_INFORMATION pi = {0};
        ::STARTUPINFO si = {sizeof(::STARTUPINFO)};
        si.dwFlags = STARTF_USESHOWWINDOW;
        si.wShowWindow = SW_HIDE;
        
        // Set the creation flags, use CREATE_NEW_CONSOLE if running in silent mode
        // this will hide the output from the compressor EXE.
        DWORD dwCreationFlags = 0;
        if( m_bSilent )
            dwCreationFlags = CREATE_NEW_CONSOLE;

        ::CreateProcess( NULL, pszCommand, NULL, NULL, FALSE, dwCreationFlags, NULL, NULL, &si, &pi );
        ::WaitForSingleObject(pi.hProcess, INFINITE);
        hFind.close();
        hFind = ::FindFirstFile( pszStoredFile, &finddata );
        if( hFind == INVALID_HANDLE_VALUE )
        {
            //printf("Compression failed\n" );
            return -802;
        }
    }
        
    file_lite fStoredFile;
    if(fStoredFile.open_read(pszStoredFile))
    {
        DWORD   dwFileSize = finddata.nFileSizeLow + 2;
        DWORD   dwRead = 0;

        fPkg.seek(0, FILE_END);
		// format the file size as an unsigned int
        ::wsprintf(buff, _T("%u"), finddata.nFileSizeLow);
        if((-1 == fPkg.write(finddata.cFileName, ((lstrlen(finddata.cFileName)+1) * sizeof(TCHAR)))) ||
           (-1 == fPkg.write(pszSourceName, ((lstrlen(pszSourceName)+1) * sizeof(TCHAR)))) ||
           (-1 == fPkg.write(pszVersion, ((lstrlen(pszVersion)+1) * sizeof(TCHAR)))) ||
           (-1 == fPkg.write(buff, ((lstrlen(buff)+1) * sizeof(TCHAR)))))
        {
            //could not append file info
            return -803;
        }
        while( dwFileSize > BUFFER_SIZE )
        {
            CHAR* pszBuffer = new CHAR[BUFFER_SIZE];
            if(-1 != (dwRead = fStoredFile.read(pszBuffer, BUFFER_SIZE) ))
            {
                fPkg.seek(0, FILE_END);
				// format the file size as an unsigned int
                ::wsprintf(buff, _T("%u"), finddata.nFileSizeLow);
                if(-1 == fPkg.write(pszBuffer, dwRead))
                {
                    //printf("Could not append %s.", pszSourceFile );
                    delete [] pszBuffer;
                    return -803;
                }
                dwFileSize -= dwRead;
            }
            else
            {
                delete [] pszBuffer;
                return -804;
            }
            delete [] pszBuffer;
        }
        if( dwFileSize )
        {
            CHAR* pszBuffer = new CHAR[dwFileSize];
            DWORD dwRead = 0;
            if(-1 != (dwRead = fStoredFile.read(pszBuffer, dwFileSize)))
            {
                fPkg.seek(0, FILE_END);
				// format the file size as an unsigned int
                ::wsprintf(buff, _T("%u"), finddata.nFileSizeLow);
                if( -1 == fPkg.write(pszBuffer, dwRead))
                {
                    //printf("Could not append %s.", pszSourceFile );
                    delete [] pszBuffer;
                    return -803;
                }
            }
            else
            {
                //printf( "Could not read file %s", pszStoredFile );
                delete [] pszBuffer;
                return -804;
            }
            delete [] pszBuffer;
        }

        if( bCompress )
        {
            fStoredFile.close();
            //if we used compression, we have a temp file to get rid of
            ::DeleteFile( pszStoredFile );
        }

		m_dwFileCount++;
    }


    return 0;
}

// Creates a new packaged from all files found in pszSource
inline long file_packager::create_package_from_folder( TCHAR *pszPackage, TCHAR *pszSource )
{
    file_lite fPkg;
    if(!fPkg.open_write(pszPackage)) 
    {
        //printf("Could not open output file.\n\n");
        return -800;
    }

    TCHAR buff[MAX_PATH] = {0};
    ::lstrcpy( buff, pszSource );
    ::lstrcat(buff, _T("\\*.*"));
    ::WIN32_FIND_DATA finddata;
    auto_hfind hFind(::FindFirstFile(buff, &finddata));
    if(hFind == INVALID_HANDLE_VALUE)
    {
        //printf("Could not find files.\n\n");
        return -801;
    }

    TCHAR file[MAX_PATH] = {0};
    BOOL b;
    do
    {
        if( !(finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
        {
            ::lstrcpy(file, pszSource);
            ::lstrcat(file, _T("\\"));
            ::lstrcat(file, finddata.cFileName);

            file_lite fFile;
            if(fFile.open_read(file))
            {
                TCHAR* pszBuff = new TCHAR[finddata.nFileSizeLow+2];
                DWORD dwRead = 0;
                if(-1 != (dwRead = fFile.read(pszBuff, finddata.nFileSizeLow+2))) 
                {
					// format the file size as an unsigned int
                    wsprintf(buff, _T("%u"), finddata.nFileSizeLow);
                    if((-1 == fPkg.write(finddata.cFileName, (lstrlen(finddata.cFileName)+1)) * sizeof(TCHAR)) ||
                       (-1 == fPkg.write(buff, (lstrlen(buff)+1)) * sizeof(TCHAR)) ||
                       (-1 == fPkg.write(pszBuff, dwRead)))
                    {
                        //printf("Could not append %s.", file);
                        delete [] pszBuff;
                        return -803;
                    }
                }
                //else
                //    printf("Could not read %s.\n\n", file);
                delete [] pszBuff;
            }
        }
        b = ::FindNextFile(hFind, &finddata);
    } while(b);

    return 0;
}

// unpack_by_name -----------------------------------------------------------
inline bool file_packager::unpack_by_name( TCHAR *pszPackage, TCHAR *pszDestination, TCHAR *pszSourceFile, bool bDestIncludesName )
{
    return unpack_by_index_or_name( pszPackage, pszDestination, pszSourceFile, 0, false, bDestIncludesName );
}

// unpack_by_index ----------------------------------------------------------
inline bool file_packager::unpack_by_index( TCHAR *pszPackage, TCHAR *pszDestination, int iIndex, bool bDestIncludesName )
{
    return unpack_by_index_or_name( pszPackage, pszDestination, NULL, iIndex, true, bDestIncludesName );
}

// unpack_by_index_or_name --------------------------------------------------
inline bool file_packager::unpack_by_index_or_name( TCHAR *pszPackage, TCHAR *pszDestination, TCHAR *pszSourceFile, int iIndex, bool bIndexOrName, bool bDestIncludesName )
{
    // Return failure if no file name was specified.
    if( !bIndexOrName && pszSourceFile == NULL )
        return false;

    file_lite fPkg;
    if(fPkg.open_read(pszPackage))
    {
        DWORD dwPackageSize = fPkg.size();

        zpath pthCompressedName;
        zpath pthOriginalName;
        zpath pthTarget;

        TCHAR    buff[256] = {0};
        int     iFileIndex = 0;
        DWORD   nSize;
        for( DWORD nFileOffset = 0; nFileOffset < dwPackageSize; )
        {
            fPkg.seek(nFileOffset);
            if(-1 == fPkg.read(buff, sizeof(buff)))
                return false;

            pthCompressedName = buff;
            fPkg.seek(nFileOffset += (lstrlen(buff) + 1));
            if(-1 == fPkg.read(buff, sizeof(buff)))
                return false;

            pthOriginalName = buff;
            fPkg.seek(nFileOffset += (lstrlen(buff) + 1));
            if(-1 == fPkg.read(buff, sizeof(buff)))
                return false;

            fPkg.seek(nFileOffset += (lstrlen(buff) + 1));
            if(-1 == fPkg.read(buff, sizeof(buff)))
                return false;

            nSize = _ttoi(buff);
            nFileOffset += (::lstrlen(buff) + 1);

            if( ( bIndexOrName ? iFileIndex == iIndex : lstrcmpi( pszSourceFile, pthOriginalName ) == 0 ) )
            {
                TCHAR* pFile = new TCHAR[nSize];
                fPkg.seek(nFileOffset);
                if(-1 == fPkg.read(pFile, nSize))
                {
                    delete [] pFile;
                    return false;
                }

                zpath pthCompressedFile;
                pthCompressedFile = zpath::special_folder( zpath::temporary );   
                pthCompressedFile += pthCompressedName;
                pthCompressedFile.make_temp(pthCompressedFile);
                file_lite fNewFile;
                if( !fNewFile.open_write(pthCompressedFile) )
                {
                    delete [] pFile;
                    return false;
                }
                if(-1 == fNewFile.write( pFile, nSize ) )
                {
                    delete[] pFile;
                    return false;
                }

                delete[] pFile;
                fNewFile.close();

                pthTarget = pszDestination;

                if( !bDestIncludesName )
                    pthTarget += pthOriginalName;

                MakeSureDirectoryExists( pthTarget.dir() );

                //Install File
                TCHAR pszTempFile[MAX_PATH] = {0};
                DWORD cb;
                DWORD dwVIFError = ::VerInstallFile(0, 
                                        const_cast<LPTSTR>(static_cast<LPCTSTR>(pthCompressedFile.file())),
                                        const_cast<LPTSTR>(static_cast<LPCTSTR>(pthTarget.file())), 
                                        const_cast<LPTSTR>(static_cast<LPCTSTR>(pthCompressedFile.dir())), 
                                        const_cast<LPTSTR>(static_cast<LPCTSTR>(pthTarget.dir())), 
                                        const_cast<LPTSTR>(static_cast<LPCTSTR>(pthTarget.dir())), 
                                        pszTempFile, 
                                        reinterpret_cast<unsigned int*>(&(cb = sizeof(pszTempFile))));
                if(dwVIFError & VIF_TEMPFILE)
	                ::DeleteFile(stringxi(pthTarget.dir().c_str()) + pszTempFile);

                if(dwVIFError && !(dwVIFError & VIF_SRCOLD))
                {
	                DWORD dw = dwVIFError;
	                
	                if((dwVIFError & VIF_FILEINUSE) || (dwVIFError & VIF_SHARINGVIOLATION))
		                dw = ERROR_SHARING_VIOLATION;
	                
	                if(dwVIFError & VIF_ACCESSVIOLATION)
		                dw = ERROR_ACCESS_DENIED;
	                
	                if(dwVIFError & VIF_OUTOFSPACE)
		                dw = ERROR_DISK_FULL;
                    return false;
                }
                else
                {
                    ::DeleteFile( pthCompressedFile );
                    return true;  //compressed file installed file properly!!
                }

                return false;  //right index, but failed
            }
            iFileIndex++;
            nFileOffset += nSize;
        }
    }
    return false;
}

inline DWORD file_packager::get_PE_size( TCHAR *pszPEFile )
{
    // Note: Ignore signature
    return is::GetInternalExeSize( pszPEFile, true );
}

inline DWORD file_packager::GetEndOfStream(TCHAR *pszPackage, DWORD dwPackageSize)
{
	DWORD dwSigOffset = is::GetSignatureOffset(pszPackage);

	if(dwSigOffset && dwSigOffset < dwPackageSize)
		return dwSigOffset;
	else
		return dwPackageSize;
}

// this function extracts just the file specified from the executable package.
// this function does not prevent extraction of data#.cab file or does not support extraction from sub-folders
// use unpack_all_from_exe if required
inline long file_packager::unpack_file_from_exe( TCHAR *pszPackage, TCHAR *pszDestination, TCHAR *pszFile )
{
    DWORD dwSizeOfPE = get_PE_size( pszPackage );
    if( dwSizeOfPE < 0 )
        return dwSizeOfPE;

    file_lite fPkg;
    if(fPkg.open_read(pszPackage))
    {    
        fPkg.seek( dwSizeOfPE );

        //do the same as below, starting at beginning of package
        TCHAR* pszBuffer = new TCHAR[BUFFER_SIZE];
        TCHAR* p = pszBuffer;
        TCHAR pszNewFile[MAX_PATH];
        TCHAR pszOriginalFile[MAX_PATH];
        TCHAR pszVersion[25];
        TCHAR pszFileName[MAX_PATH];

        // we add this to i below, so make sure this is also unsigned.
		// also use an unsigned int for the file size
		unsigned int x;
        unsigned int iFileSize;        
        int iFileCount = 0;
        int iFolderCount = 0;

		//
		// Read the count of files from the beginning of the stream,
		// then start reading the files.
		//
		DWORD dwFileCount = 0;
		fPkg.seek(dwSizeOfPE, FILE_BEGIN);
		fPkg.read(&dwFileCount, sizeof(DWORD));

        for(UINT i = dwSizeOfPE + sizeof(DWORD), j = 0; j < dwFileCount; ++j)
        {
            fPkg.seek( i );
            DWORD dwRead = fPkg.read( pszBuffer, MAX_PATH * sizeof(TCHAR) );
            ::lstrcpy(pszFileName, pszBuffer);
			x = (::lstrlen(pszFileName) + 1) * sizeof(TCHAR); 
			i += x;
            fPkg.seek( i );
            fPkg.read( pszBuffer, MAX_PATH * sizeof(TCHAR) );
            ::lstrcpy(pszOriginalFile, pszBuffer);
            x = (::lstrlen(pszOriginalFile) + 1) * sizeof(TCHAR);
            i += x;
            fPkg.seek( i );
            fPkg.read( pszBuffer, MAX_PATH * sizeof(TCHAR) );
            ::lstrcpy(pszVersion, pszBuffer);
            x = (::lstrlen( pszVersion ) + 1) * sizeof(TCHAR);
            i += x;
            fPkg.seek( i );
            fPkg.read( pszBuffer, 15 * sizeof(TCHAR) );
			iFileSize = _ttoi(p);
			x = (::lstrlen(p) + 1) * sizeof(TCHAR);
			i += x;

            if (lstrcmpi(pszFileName, pszFile) == 0)
            {
                ::lstrcpy( pszNewFile, pszDestination );
                ::lstrcat( pszNewFile, _T("\\") );
                ::lstrcat( pszNewFile, pszFileName ); 
            
                file_lite fNewFile;
                if(!fNewFile.open_write(pszNewFile)) 
                {
                    //printf("Could not open output file.\n\n");
                    delete [] pszBuffer;
                    return -800;
                }
                while( iFileSize >= BUFFER_SIZE )
                {
    			    fPkg.seek( i );
                    fPkg.read( pszBuffer, BUFFER_SIZE );
			        i += BUFFER_SIZE;
                    if(-1 == fNewFile.write(pszBuffer, BUFFER_SIZE))
                    {
                        //printf("Could not write to output file\n\n");
                        delete [] pszBuffer;
                        return -806;
                    }
                    iFileSize = iFileSize - BUFFER_SIZE;
                }
                if( iFileSize > 0 )
                {
                    fPkg.seek( i );
                    fPkg.read( pszBuffer, iFileSize );
                    i += iFileSize;
                    if(-1 == fNewFile.write(pszBuffer, iFileSize))
                    {
                        //printf("Could not write to output file\n\n");
                        delete [] pszBuffer;
                        return -806;
                    }
                }

                fNewFile.close();
                if (::lstrcmpi(pszFileName, pszOriginalFile) != 0 )
                {
                    //file was compressed, and should be uncompressed
                    ::lstrcpy( pszFileName, pszDestination );
                    ::lstrcat( pszFileName, _T("\\") );
                    ::lstrcat( pszFileName, pszOriginalFile );
                    ::OFSTRUCT  ofCompressedFile;
                    ::OFSTRUCT  ofFinalFile;
                    int         iCompressedFile;
                    int         iFinalFile;
                    iCompressedFile = ::LZOpenFile( pszNewFile, &ofCompressedFile, OF_READ );
                    iFinalFile = ::LZOpenFile( pszFileName, &ofFinalFile, OF_CREATE | OF_WRITE );
                    long lResult = ::LZCopy( iCompressedFile, iFinalFile );
                    ::LZClose( iCompressedFile );
                    ::LZClose( iFinalFile );
                    if( lResult > 0 )
                    {
                        ::DeleteFile( pszNewFile );
                        lstrcpy( pszNewFile, pszFileName );
                    }
                }

                break; // file found, exit loop
            }
            else
            {
                i += iFileSize;
            }

        }

        delete [] pszBuffer;
        return 0;
    }
    return -1;
}

//
inline long file_packager::unpack_all_from_exe( TCHAR *pszPackage, TCHAR *pszDestination, std::vector<stringxi>* pvFiles, std::vector<stringxi>* pvFolders, bool bUnpackDataCab )
{
    DWORD dwSizeOfPE = get_PE_size( pszPackage );
    if( dwSizeOfPE < 0 )
        return dwSizeOfPE;

    file_lite fPkg;
    if(fPkg.open_read(pszPackage))
    {    
        fPkg.seek( dwSizeOfPE );

        ::WIN32_FIND_DATA finddata;
        TCHAR pszFileName[MAX_PATH];
        auto_hfind hFind(::FindFirstFile(pszPackage, &finddata));
        if(hFind == INVALID_HANDLE_VALUE)
        {
            //printf("Could not find package file.\n\n");
            return -805;
        }

        hFind.close();

        //do the same as below, starting at beginning of package
        TCHAR* pszBuffer = new TCHAR[BUFFER_SIZE];
        TCHAR* p = pszBuffer;
        TCHAR pszNewFile[MAX_PATH];
        TCHAR pszOriginalFile[MAX_PATH];
        TCHAR pszVersion[25];
        bool bDataCab;

        // we add this to i below, so make sure this is also unsigned.
		// also use an unsigned int for the file size
		unsigned int x;
        unsigned int iFileSize;        
        int iFileCount = 0;
        int iFolderCount = 0;

        //record the main folder for deletion upon cleanup
        if( pvFiles )
            pvFiles->push_back( pszDestination );

		//
		// Read the count of files from the beginning of the stream,
		// then start reading the files.
		//
		DWORD dwFileCount = 0;
		fPkg.seek(dwSizeOfPE, FILE_BEGIN);
		fPkg.read(&dwFileCount, sizeof(DWORD));

        for(UINT i = dwSizeOfPE + sizeof(DWORD), j = 0; j < dwFileCount; ++j)
        {
            bDataCab = false;
            fPkg.seek( i );
            DWORD dwRead = fPkg.read( pszBuffer, MAX_PATH * sizeof(TCHAR) );
            ::lstrcpy(pszFileName, pszBuffer);
			x = (::lstrlen(pszFileName) + 1) * sizeof(TCHAR); 
			i += x;
            fPkg.seek( i );
            fPkg.read( pszBuffer, MAX_PATH * sizeof(TCHAR) );
            ::lstrcpy(pszOriginalFile, pszBuffer);
            x = (::lstrlen(pszOriginalFile) + 1) * sizeof(TCHAR);
            i += x;
            fPkg.seek( i );
            fPkg.read( pszBuffer, MAX_PATH * sizeof(TCHAR) );
            ::lstrcpy(pszVersion, pszBuffer);
            x = (::lstrlen( pszVersion ) + 1) * sizeof(TCHAR);
            i += x;
            fPkg.seek( i );
            fPkg.read( pszBuffer, 15 * sizeof(TCHAR) );
			iFileSize = _ttoi(p);
			x = (::lstrlen(p) + 1) * sizeof(TCHAR);
			i += x;

            zpath pthOriginalFile(pszOriginalFile);
            zpath pthFolder = pthOriginalFile.dir();

            ::lstrcpy( pszNewFile, pszDestination );
            ::lstrcat( pszNewFile, _T("\\") );
            if( pthFolder.Length() > 0 )
            {
                ::lstrcat( pszNewFile, pthFolder );
                zpath pthSub( pszNewFile );
                if( !pthSub.exists() )
                {
                    MakeSureDirectoryExists( pthSub );
                    //record the sub folder for deletion upon cleanup
                    if( pvFolders )
                        pvFolders->push_back( pszNewFile );
                }
            }
            ::lstrcat( pszNewFile, pszFileName );
            
            //check to see if it is Data#.cab
            zpath pthFileName( pszFileName );
            if( ::lstrcmpi( pthFileName.ext(), _T(".cab") ) == 0 )
            {
                TCHAR pszTemp[5];
                ::lstrcpyn( pszTemp, pszFileName, 5 );
				// Updated 06/06/05 - Related to 1-CW3Y5
				// Only supress the extraction of data#.cab in the disk# 
				// folders, data.cab's in sub-folders should be extracted.
				zpath pthParent = pthFolder.remove_slash().dir();
                if( ::lstrcmpi( pszTemp, _T("data")) == 0 && (::lstrcmpi( pszFileName, _T("data1.cab")) != 0) && !pthParent.Length() )
                    bDataCab = true;
            }

            if( !bDataCab || bUnpackDataCab )
            {
                file_lite fNewFile;
                if(!fNewFile.open_write(pszNewFile)) 
                {
                    //printf("Could not open output file.\n\n");
                    delete [] pszBuffer;
                    return -800;
                }
                while( iFileSize >= BUFFER_SIZE )
                {
    			    fPkg.seek( i );
                    fPkg.read( pszBuffer, BUFFER_SIZE );
			        i += BUFFER_SIZE;
                    if(-1 == fNewFile.write(pszBuffer, BUFFER_SIZE))
                    {
                        //printf("Could not write to output file\n\n");
                        delete [] pszBuffer;
                        return -806;
                    }
                    iFileSize = iFileSize - BUFFER_SIZE;
                }
                if( iFileSize > 0 )
                {
                    fPkg.seek( i );
                    fPkg.read( pszBuffer, iFileSize );
                    i += iFileSize;
                    if(-1 == fNewFile.write(pszBuffer, iFileSize))
                    {
                        //printf("Could not write to output file\n\n");
                        delete [] pszBuffer;
                        return -806;
                    }
                }

                fNewFile.close();
                if (::lstrcmpi(pthFileName.file(), pthOriginalFile.file()) != 0 )
                {
                    //file was compressed, and should be uncompressed
                    ::lstrcpy( pszFileName, pszDestination );
                    ::lstrcat( pszFileName, _T("\\") );
                    ::lstrcat( pszFileName, pszOriginalFile );
                    ::OFSTRUCT  ofCompressedFile;
                    ::OFSTRUCT  ofFinalFile;
                    int         iCompressedFile;
                    int         iFinalFile;
                    iCompressedFile = ::LZOpenFile( pszNewFile, &ofCompressedFile, OF_READ );
                    iFinalFile = ::LZOpenFile( pszFileName, &ofFinalFile, OF_CREATE | OF_WRITE );
                    long lResult = ::LZCopy( iCompressedFile, iFinalFile );
                    ::LZClose( iCompressedFile );
                    ::LZClose( iFinalFile );
                    if( lResult > 0 )
                    {
                        ::DeleteFile( pszNewFile );
                        lstrcpy( pszNewFile, pszFileName );
                    }
                }
                if( pvFiles )
                    pvFiles->push_back( pszNewFile );
            }
            else
            {
                //we skip over the data#.cab files
                i += iFileSize;
            }

        }
        //record the file for deletion upon cleanup
        if( pvFiles )
            pvFiles->push_back( pszDestination );

        delete [] pszBuffer;
        return 0;
    }
    return -1;
}

//Extracts all files from the package to the folder in pszDestination
inline long file_packager::unpack_all( TCHAR *pszPackage, TCHAR *pszDestination )
{
    ::WIN32_FIND_DATA finddata;
    DWORD dwPackageSize;
    TCHAR pszFileName[MAX_PATH];

    auto_hfind hFind(::FindFirstFile(pszPackage, &finddata));
    if(hFind == INVALID_HANDLE_VALUE)
    {
        //printf("Could not find package file.\n\n");
        return -805;
    }
    dwPackageSize = finddata.nFileSizeLow;
    hFind.close();
    
    file_lite fPkg;
    if( fPkg.open_read(pszPackage) )
    {
        TCHAR* pszBuffer = new TCHAR[dwPackageSize + 2];
        TCHAR* p = pszBuffer;
        TCHAR pszNewFile[MAX_PATH];
        TCHAR pszOriginalFile[MAX_PATH];
        TCHAR pszVersion[25];

		// use unsigned values for these since we want to address
		// more than 2GB of data
        unsigned int x;
        unsigned int iFileSize;
        DWORD dwRead = fPkg.read( pszBuffer, dwPackageSize + 2 );
        if( dwRead > 0 )
        {
            for(UINT i = 0; i < dwRead; )
            {
                ::lstrcpy(pszFileName, p);
			    x = (::lstrlen(pszFileName) + 1) * sizeof(TCHAR); 
			    i += x;
			    p += x;
                ::lstrcpy(pszOriginalFile, p);
                x = (::lstrlen(pszOriginalFile) + 1) * sizeof(TCHAR);
                i += x;
                p += x;
                ::lstrcpy(pszVersion, p);
                x = (::lstrlen( pszVersion ) + 1) * sizeof(TCHAR);
                i += x;
                p += x;
                iFileSize = _ttoi(p);
			    x = (::lstrlen(p) + 1) * sizeof(TCHAR);
			    i += x;
			    p += x;
			    TCHAR* pszFile = new TCHAR[iFileSize];
                ::CopyMemory(pszFile, p, iFileSize);
			    i += iFileSize;
			    p += iFileSize;
                ::lstrcpy( pszNewFile, pszDestination );
                ::lstrcat( pszNewFile, _T("\\") );
                ::lstrcat( pszNewFile, pszFileName );
                file_lite fNewFile;
                if(!fNewFile.open_write(pszNewFile)) 
                {
                    //printf("Could not open output file.\n\n");
                    delete [] pszFile;
                    delete [] pszBuffer;
                    return -800;
                }
                if(-1 == fNewFile.write(pszFile, iFileSize))
                {
                    //printf("Could not write to output file\n\n");
                    delete [] pszFile;
                    delete [] pszBuffer;
                    return -806;
                }
                delete [] pszFile;
                fNewFile.close();
                if (::lstrcmpi(pszFileName, pszOriginalFile) != 0 )
                {
                    //file was compressed, and should be uncompressed
                    ::lstrcpy( pszFileName, pszDestination );
                    ::lstrcat( pszFileName, _T("\\") );
                    ::lstrcat( pszFileName, pszOriginalFile );
                    ::OFSTRUCT  ofCompressedFile;
                    ::OFSTRUCT  ofFinalFile;
                    int         iCompressedFile;
                    int         iFinalFile;
                    iCompressedFile = ::LZOpenFile( pszNewFile, &ofCompressedFile, OF_READ );
                    iFinalFile = ::LZOpenFile( pszFileName, &ofFinalFile, OF_CREATE | OF_WRITE );
                    long lResult = ::LZCopy( iCompressedFile, iFinalFile );
                    ::LZClose( iCompressedFile );
                    ::LZClose( iFinalFile );
                    if( lResult > 0 )
                        ::DeleteFile( pszNewFile );
                }

            }
        }
        delete [] pszBuffer;
    }		    

    return 0;

}

inline long file_packager::find_file_info( TCHAR *pszPackage, TCHAR *pszFile, DWORD &dwOffset, DWORD &dwSize )
{
    bool bEXE = false;
    DWORD dwPESize = 0;
    zpath pthPackage( pszPackage );
    if( lstrcmpi(pthPackage.ext(), _T(".exe")) == 0 )
        dwPESize = get_PE_size( pszPackage );

    ::WIN32_FIND_DATA finddata;
    TCHAR pszFileName[MAX_PATH];

    auto_hfind hFind(::FindFirstFile(pszPackage, &finddata));
    if(hFind == INVALID_HANDLE_VALUE)
    {
        //printf("Could not find package file.\n\n");
        return -805;
    }

    hFind.close();
    
    file_lite fPkg;
    if( fPkg.open_read(pszPackage) )
    {
        TCHAR* pszBuffer = new TCHAR[MAX_PATH];
        TCHAR* p = pszBuffer;
        TCHAR pszOriginalFile[MAX_PATH];
        TCHAR pszVersion[25];

        unsigned int x;
        unsigned int iFileSize;        
        int iFileCount = 0;

		//
		// Read the count of files from the beginning of the stream,
		// then start reading the files.
		//
		DWORD dwFileCountInStream = 0;
		fPkg.seek(dwPESize, FILE_BEGIN);
		fPkg.read(&dwFileCountInStream, sizeof(DWORD));

        for(UINT i = dwPESize + sizeof(DWORD), j = 0; j < dwFileCountInStream; ++j, iFileCount++)
        {
            fPkg.seek( i );
            DWORD dwRead = fPkg.read( pszBuffer, MAX_PATH * sizeof(TCHAR) );
            ::lstrcpy(pszFileName, pszBuffer);
			x = (::lstrlen(pszFileName) + 1) * sizeof(TCHAR); 
			i += x;
            fPkg.seek( i );
            fPkg.read( pszBuffer, MAX_PATH * sizeof(TCHAR) );
            ::lstrcpy(pszOriginalFile, pszBuffer);
            x = (::lstrlen(pszOriginalFile) + 1) * sizeof(TCHAR);
            i += x;
            fPkg.seek( i );
            fPkg.read( pszBuffer, MAX_PATH * sizeof(TCHAR) );
            ::lstrcpy(pszVersion, pszBuffer);
            x = (::lstrlen( pszVersion ) + 1) * sizeof(TCHAR);
            i += x;
            fPkg.seek( i );
            fPkg.read( pszBuffer, 15 * sizeof(TCHAR) );
            iFileSize = _ttoi(p);
			x = (::lstrlen(p) + 1) * sizeof(TCHAR);
			i += x;

            zpath pthOriginalFileName(pszOriginalFile);
            zpath pthFile(pszFile);

            // Updated 08/04/05 - Devin - Related to IOC-000035234
            // For Backwards compatibility, if just the file name was specified
            // compare to the filename as before, note that if the archive
            // contains multiple versions of a file with the same name 
            // under different paths the function will find the first file.
            if( pthFile.find( '\\' ) == -1 )
                pthOriginalFileName = pthOriginalFileName.file();
            
            // Otherwise compare to the entire file path in the archive, this will always
            // find the appropriate file if multiple files with the same name are
            // in the archive and will find data-as-files files with parent paths.
            if( lstrcmpi( pszFile, pthOriginalFileName ) == 0 )
            {
                dwOffset = i;
                dwSize = iFileSize;
                delete[] pszBuffer;
                return iFileCount;
            }
            i += iFileSize;
        }
        delete pszBuffer;
        return -1; //file not found in package
    }

    return -2; //file could not be opened
}

inline void file_packager::MakeSureDirectoryExists(const zpath& pth)
{
    zstring     strErrorFormat;

    for (UINT uPos = pth.drive().Length(); zpath::npos != (uPos = pth.find(L'\\', uPos + 1)) ;)
	{
		zpath pthFolder(pth, 0, uPos + 1);
		
		::CreateDirectory(pthFolder, NULL);
    }
}

inline bool file_packager::file_exists( TCHAR *pszPackage, TCHAR *pszFile )
{
    file_lite fPkg;
    if(fPkg.open_read(pszPackage))
    {
        DWORD dwPackageSize = fPkg.size();

        zpath pthCompressedName;
        zpath pthOriginalName;

        TCHAR    buff[256] = {0};
        DWORD   nSize;
        for( DWORD nFileOffset = 0; nFileOffset < dwPackageSize; )
        {
            fPkg.seek(nFileOffset);
            if(-1 == fPkg.read(buff, sizeof(buff)))
                return false;

            pthCompressedName = buff;
            fPkg.seek(nFileOffset += ((lstrlen(buff) + 1)) * sizeof(TCHAR));
            if(-1 == fPkg.read(buff, sizeof(buff)))
                return false;

            pthOriginalName = buff;
            fPkg.seek(nFileOffset += ((lstrlen(buff) + 1)) * sizeof(TCHAR));
            if(-1 == fPkg.read(buff, sizeof(buff)))
                return false;

            if(lstrcmpi(pszFile, pthOriginalName) == 0)
                return true;

            fPkg.seek(nFileOffset += ((lstrlen(buff) + 1)) * sizeof(TCHAR));
            if(-1 == fPkg.read(buff, sizeof(buff)))
                return false;

            nFileOffset += ((::lstrlen(buff) + 1)) * sizeof(TCHAR);
            nSize = _ttoi(buff);
            nFileOffset += nSize;
        }
    }
    return false;
}


_IS_END

#endif //_FILE_PACKAGER_H_