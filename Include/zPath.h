#ifndef _ZPATH_H_
#define _ZPATH_H_

#include "zString.h"
#include "shlobj.h"

#pragma comment( lib, "version" )

#define MAJOR_VERSION(x)        ((x)/0x10000)
#define MINOR_VERSION(x)        ((x)&0xffff)

class zpath : public zstringi
{
protected:
    class _substr_ref;
    typedef zstringi _Base;

public:

	/// the assigned values for these enum constants are important (do not change them)
	/// as the values represent the size of the URL prefix (eg http:// is 7 characters in length)
	enum URL_TYPE
	{
		HTTP=7,
		HTTPS=8,
		FTP=6,
		FILEURL=7,
		FILE=0,
		INVALID=-1,
	};

	typedef _Base::element_type	element_type;

    class _zpath_ptr;
    friend class _zpath_ptr;

    // ctor
	zpath() : _Base() {}

    zpath(const zpath& _X)
        : _Base(_X){}
	zpath(size_type _N, const element_type *_S)
        : _Base(_N, _S){}
	zpath(const element_type *_S)
        : _Base(_S){}
	zpath(const char *_S)
        : _Base(_S){}
    zpath(const _Base& _X)
        : _Base(_X){}
	zpath(const zpath& _X, size_type nStartPos, size_type nCount )
		: _Base(_X, nStartPos, nCount){}

    // operator=
    zpath& operator=(const _Base& _X)
        {_Base::operator=(_X); return *this; }
    zpath& operator=(const zpath& _X)
        {_Base::operator=(_X); return *this; }
    zpath& operator=(const element_type *_S)
        {_Base::operator=(_S); return *this; }
	zpath& operator=(const char *_S)
        {_Base::operator=(zpath(_S)); return *this; }

    // can be used to get zpath* or BSTR*
    _zpath_ptr operator&()
        {return _zpath_ptr(this); }

    // get temporary char* or WCHAR* buffer of size at least n characters
    _Base::_zstring_buffer get_buffer(size_type n = MAX_PATH)
        {return _Base::_zstring_buffer(this, n); }

    // special_folder
    enum special_folders
    {
        desktop =           CSIDL_DESKTOP,
        internet =          CSIDL_INTERNET,
        programs =          CSIDL_PROGRAMS,
        controls =          CSIDL_CONTROLS,
        printers =          CSIDL_PRINTERS,
        personal =          CSIDL_PERSONAL,
        favorites =         CSIDL_FAVORITES,
        startup =           CSIDL_STARTUP,
        recent =            CSIDL_RECENT,
        sendto =            CSIDL_SENDTO,
        bitbucket =         CSIDL_BITBUCKET,
        startmenu =         CSIDL_STARTMENU,
        desktopdirectory =  CSIDL_DESKTOPDIRECTORY,
        drives =            CSIDL_DRIVES,
        network =           CSIDL_NETWORK,
        nethood =           CSIDL_NETHOOD,
        fonts =             CSIDL_FONTS,
        templates =         CSIDL_TEMPLATES,
        common_startmenu =  CSIDL_COMMON_STARTMENU,
        common_programs =   CSIDL_COMMON_PROGRAMS,
        common_startup =    CSIDL_COMMON_STARTUP,
        common_desktop =    CSIDL_COMMON_DESKTOPDIRECTORY,
        appdata =           CSIDL_APPDATA,
        printhood =         CSIDL_PRINTHOOD,
        altstartup =        CSIDL_ALTSTARTUP,
        common_altstartup = CSIDL_COMMON_ALTSTARTUP,
        common_favorites =  CSIDL_COMMON_FAVORITES,
        internet_cache =    CSIDL_INTERNET_CACHE,
        cookies =           CSIDL_COOKIES,
        history =           CSIDL_HISTORY,
		common_files =		CSIDL_PROGRAM_FILES_COMMON,
		program_files =		CSIDL_PROGRAM_FILES,
    };

    enum registry_folders
    {
        programfiles,
        commonfiles
    };
        
    enum temp_folder
    {
        temporary
    };

    enum windows_folder
    {
        windows
    };

    enum system_folder
    {
        system
    };

    // no definition for this template, only specializations are defined
    // some specialization are very small so can be inlined
    template <typename T>
    static zpath special_folder(T enumFolder);

    // special_folder<special_folders>
    template <>
    static zpath special_folder<special_folders>(special_folders enumFolder)
    {
		if (GetVersion() > 0x80000000)
		{	//SHGetSpecialFolderLocation will fail on 9x for certain cases.
			switch(enumFolder)
			{
			case personal:
			case appdata:
				enumFolder = programs; //just set it to program folder.
				break;
			//You can add more here
			}
		}

        TCHAR           psz[MAX_PATH] = {0};
        LPITEMIDLIST    pidl;
        LPMALLOC        pMalloc;
        bool            bAPIFailed = true;
        
        if(SUCCEEDED(::SHGetSpecialFolderLocation(NULL, enumFolder, &pidl)))
		{
            bAPIFailed = false;
	        if(::SHGetPathFromIDList(pidl, psz))
			{
		        if(SUCCEEDED(::SHGetMalloc(&pMalloc)))
				{
					pMalloc->Free(pidl);
					pMalloc->Release();
				}
			}
		}

        bool bPathNotExist = false; // so far we only care about the existance of program_files and common_files
		if( (enumFolder == program_files) || (enumFolder == common_files) )
        {
            zpath pthTemp = zpath(psz) += L"\\"; //??? why do we need backslash before calling exists?
            bPathNotExist = !(pthTemp.exists() && (pthTemp.drive().Length() != 0));
        }

        if( bAPIFailed || bPathNotExist )
		{
			// special handling for certain cases.
			switch(enumFolder)
			{
			case appdata: // then peer to personal folder named "Application Data"
				{				
					zpath pthAppData = zpath::special_folder(zpath::personal).remove_slash().dir();
					pthAppData += L"Application Data\\";
					return pthAppData;
				}
				break;
				//next two cases: must have failed due to presence of invalid character in the registry value
				//so lets read directly from the registry and clean up the value. See WO 1-9PEQD for details.
			case common_files:
                {
                    zpath pthCommonFiles = read_from_reg(commonfiles);
				    if( !pthCommonFiles.exists() || (pthCommonFiles.drive().Length() == 0) )
                    {
                        pthCommonFiles = zpath::special_folder(program_files).remove_slash();
                        pthCommonFiles += L"Common Files\\";
                    }
                    return pthCommonFiles;
                }
                break;

			case program_files:
                {
                    zpath pthProgramFiles = read_from_reg(programfiles);
                    if( !pthProgramFiles.exists() || (pthProgramFiles.drive().Length() == 0) )
                    {
                        pthProgramFiles = zpath::special_folder(windows).drive();
                        pthProgramFiles += "Program Files\\";
                    }
                    return pthProgramFiles;
                }
                break;

			//You can add more here
			}
		}

        return *psz? zpath(psz) += L"\\": zpath(psz);
    }

    // special_folder<registry_folders>
    template <>
    static zpath special_folder<registry_folders>(registry_folders enumFolder)
    {
        TCHAR			psz[_MAX_PATH] = {0};
		bool			bRedirectToApi(false);
		OSVERSIONINFO	osvi;

		// Starting WinXP, redirecting call to SH api -- based on Microsoft's recommendation
		// is just simpler to check for W2K than XP...
		osvi.dwOSVersionInfoSize = sizeof(osvi);
		bRedirectToApi = (GetVersionEx(&osvi) && osvi.dwPlatformId == VER_PLATFORM_WIN32_NT && osvi.dwMajorVersion >= 5);

		if (bRedirectToApi)
		{
			if (enumFolder == commonfiles)
				return special_folder(common_files);
			else if (enumFolder == programfiles)
				return special_folder(program_files);
		}
		else
		{
            zpath pth = read_from_reg(enumFolder);
            if( !pth.exists() || (pth.drive().Length() == 0) )
            {
                switch( enumFolder )
                {
                    case commonfiles:
                        pth = zpath::special_folder(programfiles).remove_slash();
                        pth += L"Common Files\\";
                        break;

                    case programfiles:
                        pth = zpath::special_folder(windows).drive();
                        pth += "Program Files\\";
                        break;
                }
            }

			return pth;
		}
		return *psz? zpath(psz) += L"\\": zpath(psz);
    }
    
    // special_folder<temp_folder>
    template <>
    static zpath special_folder<temp_folder>(temp_folder)
    {
        TCHAR psz[MAX_PATH] = {0};

        GetTempPath(MAX_PATH, psz);

        // if 9x and temp directory is read-only, then use <WINDOWSSYSTEMDRIVE>\temp
        OSVERSIONINFO osVer = {0};
        osVer.dwOSVersionInfoSize = sizeof(osVer);
        if (GetVersionEx(&osVer))
        {
	        if (osVer.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)//9x family
            {
                zpath pth(psz);
                pth += L"123.tmp";
                HANDLE h = CreateFile(pth, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
                if (h == INVALID_HANDLE_VALUE)
                {
                    pth = (zpath::special_folder(zpath::windows)).drive();
                    pth += L"temp";
                    return pth;
                }
                else
                {
                    CloseHandle(h);
                    DeleteFile(pth);
                }
            }
        }                
        
        return *psz? zpath(psz) += L"\\": zpath(psz);
    }

    // special_folder<windows_folder>
    template <>
    static zpath special_folder<windows_folder>(windows_folder)
    {
        TCHAR psz[MAX_PATH] = {0};

        GetWindowsDirectory(psz, MAX_PATH);
        
        return *psz? zpath(psz) += L"\\": zpath(psz);
    }

    // special_folder<system_folder>
    template <>
    static zpath special_folder<system_folder>(system_folder)
    {
        TCHAR psz[MAX_PATH] = {0};

        GetSystemDirectory(psz, MAX_PATH);
        
        return *psz? zpath(psz) += L"\\": zpath(psz);
    }

    zpath& beautify_case()
    {
		if (m_str)
		{
			USES_CONVERSION;
			LPTSTR  lpzStr = W2T(m_str);
			LPTSTR  lpzCurrent, lpzPrevious;

			CharLowerBuff(lpzStr,lstrlen(lpzStr));

			lpzPrevious = lpzStr;
			lpzCurrent  = CharNext(lpzPrevious);
			while (*lpzPrevious) 
			{
				   if (!IsDBCSLeadByte((BYTE)*lpzPrevious))
				   {
					   if (((*lpzCurrent!='\\')&&(*lpzPrevious=='\\')) ||
							(*lpzPrevious==' '))
							CharUpperBuff(lpzCurrent, 1);

					   if ((*lpzCurrent==':')&&(lpzPrevious==lpzStr))
						   CharUpperBuff(lpzPrevious, 1);
				   }

				   lpzPrevious = lpzCurrent;
				   lpzCurrent  = CharNext(lpzCurrent);
			}
        
			::SysFreeString(m_str);
			m_str = T2BSTR(lpzStr);
		}
        return (*this);
    }

	// exists
    bool exists() const
	{
		return (GetFileAttributes( *this ) != 0xffffffff);
	}

	// file_size
	DWORD file_size( DWORD *pdwSizeLow, DWORD* pdwSizeHigh=0 ) const
	{
		ATLASSERT( pdwSizeLow != 0 );

		WIN32_FIND_DATA	fd;
		HANDLE	hFind = FindFirstFile( *this, &fd );
		if( hFind != INVALID_HANDLE_VALUE )
		{
			*pdwSizeLow = fd.nFileSizeLow;
			if( pdwSizeHigh )
				*pdwSizeHigh = fd.nFileSizeHigh;
			FindClose(hFind);
			return 0;
		}

		return GetLastError();
	}

	// get_version
	bool get_version( _Base& rversion ) const
	{
		UINT	uPMajor(0), uPMinor(0), uBMajor(0), uBMinor(0);

		if( get_version( &uPMajor, &uPMinor, &uBMajor, &uBMinor ) )
		{
			wsprintf( rversion.get_buffer(30), _T("%u.%u.%u.%u"), 
					  uPMajor, uPMinor, uBMajor, uBMinor );
			return true;
		}

		return false;
	}

	// get_version
	bool get_version( UINT* puPMajor, UINT *puPMinor=0, UINT *puBMajor=0, UINT *puBMinor=0 ) const
	{
		bool	bDone(false);
		DWORD	dwHandle(0), dwSize(0);

		UINT	versionHi(0),versionLo(0);

		if( exists() )
		{
			dwSize = GetFileVersionInfoSize( const_cast<LPTSTR>(static_cast<LPCTSTR>(*this)), &dwHandle );
			if ( dwSize > 0 )
			{
				char *pVerInfo = new char[dwSize];
				if( GetFileVersionInfo( const_cast<LPTSTR>(static_cast<LPCTSTR>(*this)), dwHandle, dwSize, pVerInfo ) )
				{
					UINT				dwInfoSize(0);
					VS_FIXEDFILEINFO	*pFileInfo =0;
					if( VerQueryValue( pVerInfo, _T("\\"), (void**)&pFileInfo, &dwInfoSize ) )
					{
						if ( 0 < dwInfoSize )
						{
							bDone = true;
							*puPMajor = MAJOR_VERSION( pFileInfo->dwFileVersionMS );

							if( puPMinor )
								*puPMinor = MINOR_VERSION( pFileInfo->dwFileVersionMS );

							if( puBMajor )
								*puBMajor = MAJOR_VERSION( pFileInfo->dwFileVersionLS );

							if( puBMinor )
								*puBMinor = MINOR_VERSION( pFileInfo->dwFileVersionLS );
						}
					}
				}
				delete [] pVerInfo;
			}
		}
		return bDone;
	}

    // remove_slash
    zpath& remove_slash()
    {
        if( Length() > 0 && ((last_char() == L'\\') || (last_char() == L'/')))
            *this = substr( 0, Length() - 1 );
        
        return *this;
    }

    // dir
    _substr_ref dir()
    {
        size_type   slash = find_last_of(L"/\\");
        _substr_ref refDrive = drive();

        if(slash != npos && slash >= refDrive.Length())
            return _substr_ref(this, 0, slash + 1);
        else
            return refDrive;
    }
    
    const _Base dir() const
    {
        size_type   slash = find_last_of(L"/\\");
        _Base       strDrive = drive();

        if(slash != npos && slash >= strDrive.Length())
            return substr(0, slash + 1);
        else
            return strDrive;
    }

    // file
    _substr_ref file()
    {
        return _substr_ref(this, dir().Length());
    }

    const _Base file() const
    {
        return substr(dir().Length());
    }

    // filename
    _substr_ref filename()
    {
        size_type   nDir = dir().Length();
        size_type   nDot = rfind(L'.');

        if(nDot != npos && nDot >= nDir)
            return _substr_ref(this, nDir, nDot - nDir);
        else
            return _substr_ref(this, nDir);
    }

    const _Base filename() const
    {
        size_type   nLen = Length();
        size_type   nDir = dir().Length();
        size_type   nDot = rfind(L'.');

        if ((nLen == nDir)&&(nDot != npos)) //no directory; just a file
        {
            return substr(0,nDot);   
        }
        else
        {
            if(nDot != npos && nDot >= nDir)   //we have a '.' and a normal full path
                return substr(nDir, nDot - nDir);
            else
                return substr(0,nDir);           
        }
    }

    // ext
    _substr_ref ext(bool bDontIncludeDot = false)
    {
        size_type   nDir = dir().Length();
        size_type   nDot = rfind(L'.');

        if (nDot != npos && nDot >= nDir)
        {
           if (bDontIncludeDot) nDot++;
           return _substr_ref(this, nDot);
        } else
			return _substr_ref(this, Length());
    }

    const _Base ext(bool bDontIncludeDot = false) const
    {
        size_type   nDir = dir().Length();
        size_type   nDot = rfind(L'.');

        if(nDot != npos && nDot >= nDir)
        {
            if (bDontIncludeDot) nDot++;
            return substr(nDot);
        } else
            return substr(Length());
    }


    // drive
    _substr_ref drive(bool bProtocolPrefix=false)
    {
        if(is_unc())
        {
            ATLASSERT(Length() >= 3);

            size_type slash = find_first_of(L"/\\", 2);
            
            if(slash != npos)
                slash = find_first_of(L"/\\", slash + 1);

            return _substr_ref(this, 0, slash);
        }    
        else 
		{
			URL_TYPE	ut = url_type();

			if( ut == INVALID )
				return _substr_ref(this, 0, 0);

			if( ut == FILE )
				return _substr_ref(this, 0, c_str()[1] == L':' ? 2 : 0);

			ATLASSERT( Length() > UINT(ut) );

			size_type slash = find_first_of(L"/\\", ut );

			return _substr_ref(this, bProtocolPrefix? 0:ut, bProtocolPrefix? slash:slash-ut );
		}
    }

    const _Base drive(bool bProtocolPrefix=false) const
    {
        if(is_unc())
        {
            ATLASSERT(Length() >= 3);

            size_type slash = find_first_of(L"/\\", 2);
            
            if(slash != npos)
                slash = find_first_of(L"/\\", slash + 1);

            return substr(0, slash);
        }
        else 
		{
			URL_TYPE	ut = url_type();

			if( ut == INVALID )
				return L"";

			if( ut == FILE )
				return substr(0, c_str()[1] == L':' ? 2 : 0);

			ATLASSERT( Length() > UINT(ut) );

			size_type slash = find_first_of(L"/\\", ut );

			return substr(bProtocolPrefix? 0:ut, bProtocolPrefix? slash:slash-ut );
		}
    }

	const _Base root_path() const
	{
		return substr( drive(true).Length() );
	}

    // is_unc
    bool is_unc() const
        {return Length() >= 3 && c_str()[0] == L'\\' && c_str()[1] == L'\\'; }

    
    bool is_http() const
		{return 0 == compare( 0,  7, L"http://" ); }

	bool is_https() const
		{return 0 == compare( 0, 8, L"https://" ); }

	bool is_ftp() const
		{return 0 == compare( 0, 6, L"ftp://" ); }

	bool is_fileurl() const
		{return 0 == compare( 0, 7, L"file://" ); }

	bool is_url() const
		{return (is_http() || is_ftp() || is_https()); }

	URL_TYPE url_type() const
	{
		if( is_http() )
			return HTTP;
		else if( is_ftp() )
			return FTP;
		else if( is_https() )
			return HTTPS;
		else if( is_fileurl() )
			return FILEURL;
		else if( m_str == 0 )
			return INVALID;

		return FILE;
	}

	zpath& url_decode()
	{
        size_type nLength = Length(), nOutputPos(0);
        BSTR  bsLocalString = SysAllocString(m_str);

		for (size_type nPos=0; nPos < nLength && m_str[nPos]; nPos++)
		{
			if ( (m_str[nPos] == L'%') &&  //check base character
                 ((nPos+2)<nLength)    &&  //make sure we don't go over the end
				 IS_HEX_DIGIT(m_str[nPos+1]) &&
				 IS_HEX_DIGIT(m_str[nPos+2]) )
			{
				char szBuffer[3] = {0};

				szBuffer[0] = char(m_str[nPos+1] & 0xFF);
				szBuffer[1] = char(m_str[nPos+2] & 0xFF);

				bsLocalString[nOutputPos++] = WCHAR(atoi(szBuffer,16));
                nPos += 2;  //extra nPos will come through in the for loop
			}
             else
            {            
                bsLocalString[nOutputPos++] = m_str[nPos];
            }
        }
        
        bsLocalString[nOutputPos] = L'\0';  //finish the string with terminating null
        if (m_str) SysFreeString(m_str);

		m_str = SysAllocString(bsLocalString);
		SysFreeString(bsLocalString);

		return *this;
	}

	// use this when pathw contains just a name (file or folder name) 
	// and you want to purge it of invalid chars
	zpath& remove_invalid_chars_from_name()
	{
		WCHAR			invalid_chars[] = {L"\\/:*?\"<>|"};

		return remove_invalid_chars(invalid_chars, sizeof(invalid_chars)/sizeof(WCHAR));
	}

	// use this when pathw contains a full path (anything that has more than one path part) 
	// and you want to purge it of invalid chars. Note I did not include:
	//  \ - as this is valid path separator
	//  / - as this is also a valid path separator
	zpath& remove_invalid_chars_from_path()
	{
		WCHAR	invalid_chars[] = {L":*?\"<>|"};
		zpath&	rPath = remove_invalid_chars(invalid_chars, sizeof(invalid_chars)/sizeof(WCHAR), true);

		// remove invalid sequences (/// or \\\ or combinations of /\)
		size_type	nLeft = 2, // start after first 2 positions to make it work for UNC paths
					nRight = 0;

		if (rPath.first_char() == L'"' && rPath.last_char() == L'"')
		{
			++nLeft; 
			++nRight;
		}

		size_type	n1=0;

		for (size_type n=nLeft, nSize=rPath.Length(); n < nSize-nRight; ++n)
		{
			if (rPath[n] == L'\\' || rPath[n] == L'/')
			{
				for (n1=n; rPath[n1] == L'\\' || rPath[n1] == L'/'; ++n1);

				if (n1 - n > 1)
				{
					rPath.erase(n+1, n1-n-1);
					nSize=rPath.Length();
				}
			}
		}

		return rPath;
	}

    // canonicalize
    zpath& canonicalize()
    {
        size_type n, n1;

        for(n = find(L"\\."); n != npos; n = find(L"\\.", n))
            if(c_str()[n+2] != L'.')
                erase(n, 2);
            else
                n++;

        for(n = find(L"\\.."); n != npos; n = find(L"\\..", n1))
        {
            n1 = rfind(L'\\', n - 1);
            
            if(npos == n1)
                n1 = n;
            erase(n1 + 1, n - n1 + 3);
        }

        return *this;
    }
    
    // short
    zpath short_path() const
    {
        zpath pth;
        
        if( !GetShortPathName(*this, pth.get_buffer(), MAX_PATH) )
			pth = L"";

        return pth;
    }

    // long path from short path
    zpath long_path() const
    {
        bool    bFirst = true;
        zpath   pthLongDir;

        for(int n = 0, nSize = Length(); n < nSize; ++n)
            if(operator[](n) == L'\\')
            {
                const zpath     pthDir(*this, 0, n);
                HANDLE		    hSearch;
                WIN32_FIND_DATA find;
                
                if(!bFirst)
                {
                    hSearch = FindFirstFile(pthDir, &find);
                    if(INVALID_HANDLE_VALUE == hSearch)
						break;

					pthLongDir += find.cFileName;
					FindClose(hSearch);
                }
                else
                {
                    bFirst = false;
                    pthLongDir = pthDir;
                }
            }

        return pthLongDir;
    }

    // make_temp
    bool make_temp(const zpath& pth)
    {
		short	nRetries(0);
retry:
        if(!GetTempFileName(pth.dir(), pth.file(), 0, get_buffer()))
		{
custom_method:
            DWORD	dwTick = GetTickCount();
			TCHAR	szUniqueName[MAX_PATH] = {0};

			do 
			{
				wsprintf(szUniqueName, _T("%s%d.tmp"), (LPCTSTR)pth, dwTick);
			} while (0xFFFFFFFF != GetFileAttributes(szUniqueName));
			*this = szUniqueName;
		}
		else
		{
			if (FILE_ATTRIBUTE_DIRECTORY & GetFileAttributes(*this))
			{
				if (nRetries < 3)
				{
					++nRetries;
					goto retry;
				}
				else
					goto custom_method;
			}
			DeleteFile(*this);
		}

		return true;
    }

    
    // char_compact
    _Base char_compact(size_type cchMax)
    {
        zpath		pth(*this);
        size_type	nLen(0);
    
        while((nLen = pth.Length()) > cchMax && pth.compact());
    
        return pth;
    }

    
    // pixel_compact
    _Base pixel_compact(HDC hDC, int cchMax)
    {
        zpath pth(*this);
        SIZE size;
        long nLen = pth.Length();

        while((GetTextExtentPoint32(hDC, pth, nLen = pth.Length(), &size) ? size.cx : 0) > cchMax && pth.compact());

        return pth;
    }

    
    // operator+=
    zpath& operator+=(const _Base& pth)
    {
		element_type fc = pth.first_char();

        if(Length() > 0 && (last_char() == L'\\' || last_char() == L'/'))
            append(pth, ( fc == L'\\' || fc == L'/') ? 1 : 0, npos);
        else
        {
            if(pth.first_char() != L'\\' && !is_empty())
                append(L'\\', 1);
            append(pth);
        }

        return *this;
    }

    zpath& operator+=(const element_type *_S)
    {
        if(Length() > 0 && (last_char() == L'\\' || last_char() == L'/'))
            append(_S + ((_S[0] == L'\\' || _S[0] == L'/') ? 1 : 0));
        else
        {
            if(_S[0] != L'\\' && !is_empty())
                append(L'\\', 1);
            append(_S);
        }

        return *this;
    }

	zpath& operator+=(const char *pstr)
	{
        if(Length() > 0 && (last_char() == L'\\' || last_char() == L'/'))
            append(pstr + ((pstr[0] == L'\\'||pstr[0] == L'/') ? 1 : 0));
        else
        {
            if(pstr[0] != L'\\' && !is_empty())
                append(L'\\',1);
            append(pstr);
        }

        return *this;
	}

public:
    class _zpath_ptr : public _Base::_zstring_ptr
    {
    public:
        _zpath_ptr(zpath* ppth)
            : _zstring_ptr(ppth), m_ppth(ppth){}

        operator zpath*()
            {return m_ppth; }

    protected:
        zpath*  m_ppth;
    };

protected:

	zpath& remove_invalid_chars(WCHAR *pszInvalidChars, unsigned int nSize, bool bProcessPath=false)
	{
		size_type		nLength = Length(), nOutputPos(0);
		BSTR			strLocal = SysAllocString(*this);
		bool			bSkip, bUnqouted(false);
		zpath			*pTHIS = this;

		// prepare path for char validation - remove quotes, trim spaces - it eases the logic
		if (bProcessPath)
		{
			pTHIS = new zpath(*this);
			if (bUnqouted = (pTHIS->first_char() == L'"' && pTHIS->last_char() == L'"'))
				pTHIS->unquote_spaces();
			pTHIS->trim();
		}

		for (size_type nPos=0; nPos < nLength && (*pTHIS)[nPos]; ++nPos)
		{
			bSkip = false;
			for (size_type n=0; n < nSize && !bSkip; ++n)
			{
				if (bProcessPath)
				{
					//if a ':' is present after <Drive Char>: and before eos, its an invalid char
					if (pszInvalidChars[n] == L':' && (*pTHIS)[nPos] == L':')
					{
						bSkip = ((nPos > 1 && nPos < nLength));
						continue;
					}
				}
				bSkip = ((*pTHIS)[nPos] == pszInvalidChars[n]);
			}

			if (!bSkip)
				strLocal[nOutputPos++] = (*pTHIS)[nPos];
		}

		strLocal[nOutputPos] = L'\0';

		*this = strLocal;
		if (bUnqouted) //restore qoutes for the path
			quote_spaces();

		SysFreeString(strLocal);

		if (bProcessPath)
			delete pTHIS;

		return *this;
	}

	static zpath read_from_reg(registry_folders enumFolder)
	{
		TCHAR	psz[_MAX_PATH] = {0};
		HKEY	hkey;

		if(!RegOpenKey(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion"), &hkey))
		{
			unsigned long cb = sizeof(psz);

			RegQueryValueEx(hkey, (enumFolder == commonfiles) ? _T("CommonFilesDir") : _T("ProgramFilesDir"), NULL, NULL, reinterpret_cast<LPBYTE>(psz), &cb);

			zpath	p(psz);

			p += L"\\";
			p.remove_invalid_chars_from_path(); //see WO 1-9PEQD for details.

			RegCloseKey(hkey);
			return p;
		}

		return *psz? zpath(psz) += L"\\": zpath(psz);;
	}

    bool compact()
    {
        size_type n1 = find_first_of(L"/\\", drive().Length());
        size_type n0 = n1+1;

        while((n1 != npos) && (c_str()[n1+1] == L'.'))
            n1 = find_first_of(L"/\\", n1+1);

        if(n1 != npos)
        {
            size_type n2 = find_first_of(L"/\\", n1+1);
            if(n2 != npos)
            {
                replace(n0, n2-n0, L"...");
                return true;
            }
        }

        return false;
    }

	//// all refrences to zstringi should actually be _Base. But VC gets confused with
	// _Base (it picks up CComBSTR -- zstringi's base class)
    class _substr_ref : public zstringi
    {
    public:
        _substr_ref(zstringi* pstr, size_type pos = 0, size_type n = npos)
            : m_pos(pos), m_n(n), m_ReferenceStr(*pstr)
            {assign(m_ReferenceStr.substr(pos, n)); }

        // operator=
        _substr_ref& operator=(const zstringi& _X)
            {slash_safe_assign(_X); m_ReferenceStr.replace(m_pos, m_n, *this); return *this; }
        
        _substr_ref& operator=(const element_type *_S)
            {slash_safe_assign(_S); m_ReferenceStr.replace(m_pos, m_n, *this); return *this; }

        _substr_ref& operator=(const char *_S)
		{
			USES_CONVERSION;
			slash_safe_assign( _ZA2W(_S) );
			m_ReferenceStr.replace(m_pos, m_n, *this); 
			return *this; 
		}

    private:
        void slash_safe_assign(zstringi _X)  // should be _Base not zstringi but VC can't compile it
        {
            if(first_char() == L'\\' && _X.first_char() != L'\\')
                _X.insert((size_type)0, 1, L'\\');

            if(last_char() == L'\\' && _X.last_char() != L'\\')
                _X.append( L'\\', 1 );

			if(first_char() == L'/' && _X.first_char() != L'/' )
				_X.insert(0, 1, L'/');

            if(last_char() == L'/' && _X.last_char() != L'/')
                _X.append( L'/', 1 );

            assign(_X);
        }

        size_type m_pos, m_n;
        zstringi&  m_ReferenceStr;
    };    

};

// operator+
inline zpath operator+(const zpath& pth1, const zpath& pth2)
    {return zpath(pth1) += pth2; }

template<class _Tr>
inline zpath operator+(const zpath& pth, const _zstring<_Tr>& str)
    {return zpath(pth) += str; }

template<class _Tr>
inline zpath operator+(const _zstring<_Tr>& str, const zpath& pth)
    {return zpath(str) += pth; }

inline zpath operator+(const zpath& pth1, const WCHAR *_S)
    {return zpath(pth1) += _S; }

inline zpath operator+(const WCHAR *_S, const zpath& pth1)
    {return zpath(_S) += pth1; }


// operator==
inline bool operator==(const zpath& pth1, const zpath& pth2)
    {return 0 == zpath(pth1).canonicalize().compare(zpath(pth2).canonicalize()); }

#endif //_ZPATH_H_
