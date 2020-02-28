// IconFile.cpp : implementation file
//
// Adapted from the IconPro sample found in the article titled "Icons in
// Win32" by John Hornick of Microsoft Corporation.
//

#include "stdafx.h"
#include "IconFile.h"
#include "auto_handle.hxx"

/////////////////////////////////////////////////////////////////////////////
// CIconFile

CIconFile::CIconFile()
{
	m_lpID=_T(""); 
	m_nIdxCurr=0;
	m_nIdxFind=0;
	m_lpIconResource=NULL;
}

CIconFile::~CIconFile()
{
	DestroyIcon();
}

BOOL CIconFile::LoadIcon(LPCTSTR szFileName, int nIndex, bool b16ColorsOnly/*=false*/)
{
	DestroyIcon();

	// First we'll try loading the file as a EXE / DLL
	HINSTANCE hLib=LoadLibraryEx(szFileName, NULL, LOAD_LIBRARY_AS_DATAFILE);

	if(hLib)
	{
		// It's a EXE / DLL
		m_lpIconResource=ReadIconFromEXEFile(hLib, nIndex, b16ColorsOnly);
		FreeLibrary(hLib);
	}
	else
	{
		// See if it's an ICO file
		m_lpIconResource=ReadIconFromICOFile(szFileName, b16ColorsOnly);
	}

	return (NULL != m_lpIconResource);
}

BOOL CIconFile::SaveIcon(LPCTSTR szFileName)
{
	if(NULL==m_lpIconResource)
		return FALSE;

	return WriteIconToICOFile(m_lpIconResource, szFileName);
}

BOOL CIconFile::IsResourceFile(LPCTSTR szFileName)
{
	HINSTANCE hLib=LoadLibraryEx(szFileName, NULL, LOAD_LIBRARY_AS_DATAFILE);
	BOOL bIsExeFile=(hLib != NULL);

	if(hLib)
		FreeLibrary(hLib);

	return bIsExeFile;
}

BOOL CIconFile::ExtractIcon(LPCTSTR szSource, int nIndex, LPCTSTR szDest)
{
	CIconFile iFile;
	return ( iFile.LoadIcon(szSource, nIndex) && iFile.SaveIcon(szDest) );
}

BOOL CIconFile::ExtractIcon16(LPCTSTR szSource, int nIndex, LPCTSTR szDest)
{
	CIconFile iFile;
    if ( iFile.LoadIcon(szSource, nIndex, true))
    {
        return iFile.SaveIcon(szDest);
    }

	return FALSE;
}

BOOL CIconFile::ExtractIcon(LPCTSTR szSource, LPCTSTR szIconName, LPCTSTR szDest)
{
	BOOL bSuccess=FALSE;
	HINSTANCE hLib=LoadLibraryEx(szSource, NULL, LOAD_LIBRARY_AS_DATAFILE);

	if(hLib)
	{
		CIconFile iFile;

		iFile.m_lpIconResource=iFile.ReadIconFromEXEFile(hLib, (LPTSTR)szIconName);

		if(iFile.m_lpIconResource)
			bSuccess=iFile.SaveIcon(szDest);

		FreeLibrary(hLib);
	}

	return bSuccess;
}

void CIconFile::DestroyIcon()
{
	if(m_lpIconResource)
	{
		for(unsigned int i=0; i<m_lpIconResource->nNumImages; i++)
			free(m_lpIconResource->IconImages[i].lpBits);

		free(m_lpIconResource);
	}

	if(m_lpID != _T("") && HIWORD(m_lpID))
		free(m_lpID);

	m_lpID=NULL;
	m_lpIconResource=NULL;
}

LPICONRESOURCE CIconFile::ReadIconFromEXEFile(HINSTANCE hLibrary, LPTSTR lpID, bool b16ColorsOnly/*=false*/)
{
	LPICONRESOURCE lpIR=NULL;

	if(lpID != _T(""))
	{
		// Find the group icon resource
		HRSRC hRsrc=FindResource(hLibrary, lpID, RT_GROUP_ICON);
		HGLOBAL hGlobal=LoadResource(hLibrary, hRsrc);
		LPMEMICONDIR lpIcon=(LPMEMICONDIR)LockResource(hGlobal);

		if(lpIcon)
		{
			// Allocate enough memory for the images
			lpIR=(LPICONRESOURCE)malloc( sizeof(ICONRESOURCE) +
				((lpIcon->idCount-1) * sizeof(ICONIMAGE)) );
		}

		if(lpIR)
		{
			// Fill in local struct members
            UINT nNumImages = lpIcon->idCount;
            lpIR->nNumImages = nNumImages;
            UINT nIndex = -1;
			
			// Loop through the images
			for(UINT i = 0; i < nNumImages; i++)
			{                
				// Get the individual image
				hRsrc=FindResource(hLibrary,
					MAKEINTRESOURCE(lpIcon->idEntries[i].nID), RT_ICON);

				hGlobal=LoadResource(hLibrary, hRsrc);

				if(NULL==hGlobal)
				{
					free(lpIR);
					return NULL;
				}

                if (b16ColorsOnly)
                {
                    LPICONRESOURCE lpMyIR=NULL;
	                // Allocate enough memory for the images
			        lpMyIR=(LPICONRESOURCE)malloc( sizeof(ICONRESOURCE) +
				                ((lpIcon->idCount-1) * sizeof(ICONIMAGE)) );

                    lpMyIR->nNumImages = nNumImages;
				    // Store a copy of the resource locally
				    lpMyIR->IconImages[i].dwNumBytes=SizeofResource(hLibrary,
					    hRsrc);

				    lpMyIR->IconImages[i].lpBits=
					    (LPBYTE)malloc(lpMyIR->IconImages[i].dwNumBytes);

				    memcpy(lpMyIR->IconImages[i].lpBits, LockResource(hGlobal),
					    lpMyIR->IconImages[i].dwNumBytes);

				    if(!AdjustIconImagePointers( &(lpMyIR->IconImages[i]) ))
				    {
					    // Error converting to internal format
					    free(lpMyIR);
					    return NULL;
				    }


                    UINT uColors = lpMyIR->IconImages[i].Colors;
                    free(lpMyIR);

                    if ((uColors != 0) && (uColors <= 4)) //Allow only 16 Colors and to be safe don't allow 0
                        nIndex++;
                    else
                    {
                        lpIR->nNumImages = lpIR->nNumImages - 1;                                       
                        continue;
                    }
                }
                else
                    nIndex = i;
                
				// Store a copy of the resource locally
				lpIR->IconImages[nIndex].dwNumBytes = SizeofResource(hLibrary, hRsrc);
				lpIR->IconImages[nIndex].lpBits = (LPBYTE)malloc(lpIR->IconImages[nIndex].dwNumBytes);

				memcpy(lpIR->IconImages[nIndex].lpBits, LockResource(hGlobal),
					lpIR->IconImages[nIndex].dwNumBytes);

				// Adjust internal pointers
				if(!AdjustIconImagePointers( &(lpIR->IconImages[nIndex]) ))
				{
					// Error converting to internal format
					free(lpIR);
					return NULL;
				}
			}
		}
    }

    return lpIR;
}

LPICONRESOURCE CIconFile::ReadIconFromEXEFile(HINSTANCE hLibrary, int nIndex, bool b16ColorsOnly/*= false*/)
{
	return ReadIconFromEXEFile(hLibrary, FindIconByIndex(hLibrary, nIndex), b16ColorsOnly);
}

LPTSTR CIconFile::FindIconByIndex(HINSTANCE hLibrary, int nIndex)
{
	m_lpID=_T("");
	m_nIdxCurr=0;
	m_nIdxFind=nIndex;

	EnumResourceNames(hLibrary, RT_GROUP_ICON, (ENUMRESNAMEPROC)EnumProc, (LPARAM)this);

	return m_lpID;
}

BOOL CALLBACK CIconFile::EnumProc(HMODULE hModule, LPCTSTR lpszType,
								  LPTSTR lpszName, CIconFile* pThis)
{
	// Wait until we find the index we're searching for
	if(pThis->m_nIdxFind==pThis->m_nIdxCurr++)
	{
		// See if the ID is a number or a string
		if(HIWORD(lpszName))
	        pThis->m_lpID=_tcsdup(lpszName);//string
	    else
			pThis->m_lpID=lpszName;//number

		return FALSE;// End enumeration
	}

	return TRUE;// Continue enumeration
}

LPICONRESOURCE CIconFile::ReadIconFromICOFile( LPCTSTR szFileName, bool b16ColorsOnly/*=false*/)
{
    LPICONRESOURCE    	lpIR = NULL, lpNew = NULL;
    HANDLE            	hFile = NULL;
    UINT                i;
    DWORD            	dwBytesRead;
    LPICONDIRENTRY    	lpIDE = NULL;


    // Open the file
    if( (hFile = CreateFile( szFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL )) == INVALID_HANDLE_VALUE )
    {
//        MessageBox( hWndMain, "Error Opening File for Reading", szFileName, MB_OK );
        return NULL;
    }
    // Allocate memory for the resource structure
    if( (lpIR = (LPICONRESOURCE)malloc( sizeof(ICONRESOURCE) )) == NULL )
    {
//        MessageBox( hWndMain, "Error Allocating Memory", szFileName, MB_OK );
        CloseHandle( hFile );
        return NULL;
    }
    // Read in the header
    if( (lpIR->nNumImages = ReadICOHeader( hFile )) == (UINT)-1 )
    {
//        MessageBox( hWndMain, "Error Reading File Header", szFileName, MB_OK );
        CloseHandle( hFile );
        free( lpIR );
        return NULL;
    }
    // Adjust the size of the struct to account for the images
    if( (lpNew = (LPICONRESOURCE)realloc( lpIR, sizeof(ICONRESOURCE) + ((lpIR->nNumImages-1) * sizeof(ICONIMAGE)) )) == NULL )
    {
//        MessageBox( hWndMain, "Error Allocating Memory", szFileName, MB_OK );
        CloseHandle( hFile );
        free( lpIR );
        return NULL;
    }
    lpIR = lpNew;
    // Allocate enough memory for the icon directory entries
    if( (lpIDE = (LPICONDIRENTRY)malloc( lpIR->nNumImages * sizeof( ICONDIRENTRY ) ) ) == NULL )
    {
//        MessageBox( hWndMain, "Error Allocating Memory", szFileName, MB_OK );
        CloseHandle( hFile );
        free( lpIR );
        return NULL;
    }
    // Read in the icon directory entries
    if( ! ReadFile( hFile, lpIDE, lpIR->nNumImages * sizeof( ICONDIRENTRY ), &dwBytesRead, NULL ) )
    {
//        MessageBox( hWndMain, "Error Reading File", szFileName, MB_OK );
        CloseHandle( hFile );
        free( lpIR );
        return NULL;
    }
    if( dwBytesRead != lpIR->nNumImages * sizeof( ICONDIRENTRY ) )
    {
//        MessageBox( hWndMain, "Error Reading File", szFileName, MB_OK );
        CloseHandle( hFile );
        free( lpIR );
        return NULL;
    }

    UINT nNumImages = lpIR->nNumImages;
    UINT nIndex = -1;

    // Loop through and read in each image
    for( i = 0; i < nNumImages; i++ )
    {
        if (b16ColorsOnly)
        {
            WORD wCount = lpIDE[i].wBitCount;  //4 = 16 colors
            if ((wCount != 0) && (wCount <= 4))
                nIndex++;
            else
            {
                lpIR->nNumImages = lpIR->nNumImages - 1;                                       
                continue;
            }
        }
        else
            nIndex = i;

        // Allocate memory for the resource
        if( (lpIR->IconImages[nIndex].lpBits = (LPBYTE)malloc(lpIDE[nIndex].dwBytesInRes)) == NULL )
        {
//            MessageBox( hWndMain, "Error Allocating Memory", szFileName, MB_OK );
            CloseHandle( hFile );
            free( lpIR );
            free( lpIDE );
            return NULL;
        }
        lpIR->IconImages[nIndex].dwNumBytes = lpIDE[nIndex].dwBytesInRes;
        // Seek to beginning of this image
        if( SetFilePointer( hFile, lpIDE[nIndex].dwImageOffset, NULL, FILE_BEGIN ) == 0xFFFFFFFF )
        {
//            MessageBox( hWndMain, "Error Seeking in File", szFileName, MB_OK );
            CloseHandle( hFile );
            free( lpIR );
            free( lpIDE );
            return NULL;
        }
        // Read it in
        if( ! ReadFile( hFile, lpIR->IconImages[nIndex].lpBits, lpIDE[nIndex].dwBytesInRes, &dwBytesRead, NULL ) )
        {
//            MessageBox( hWndMain, "Error Reading File", szFileName, MB_OK );
            CloseHandle( hFile );
            free( lpIR );
            free( lpIDE );
            return NULL;
        }
        if( dwBytesRead != lpIDE[nIndex].dwBytesInRes )
        {
//            MessageBox( hWndMain, "Error Reading File", szFileName, MB_OK );
            CloseHandle( hFile );
            free( lpIDE );
            free( lpIR );
            return NULL;
        }
        // Set the internal pointers appropriately
        if( ! AdjustIconImagePointers( &(lpIR->IconImages[nIndex]) ) )
        {
//            MessageBox( hWndMain, "Error Converting to Internal Format", szFileName, MB_OK );
            CloseHandle( hFile );
            free( lpIDE );
            free( lpIR );
            return NULL;
        }
    }
    // Clean up	
    free( lpIDE );
    CloseHandle( hFile );

    // Adjust the size of the struct to account for the 16 color images only
    if (b16ColorsOnly)
    {
        if (lpIR->nNumImages == 0)
        {
            free( lpIR );
            return NULL;
        }

        LPICONRESOURCE  lp16 = NULL;
        if( (lp16 = (LPICONRESOURCE)realloc( lpIR, sizeof(ICONRESOURCE) + ((lpIR->nNumImages-1) * sizeof(ICONIMAGE)) )) == NULL )
        {
 //           MessageBox( hWndMain, "Error Allocating Memory", szFileName, MB_OK );
            free( lpIR );
            return NULL;
        }

		m_lpIconResource = lp16;
        return lp16;
    }
    else
	{
		m_lpIconResource = lpIR;
        return lpIR;
	}
}

UINT CIconFile::ReadICOHeader( HANDLE hFile )
{
    WORD    Input;
    DWORD	dwBytesRead;

    // Read the 'reserved' WORD
    if( ! ReadFile( hFile, &Input, sizeof( WORD ), &dwBytesRead, NULL ) )
        return (UINT)-1;
    // Did we get a WORD?
    if( dwBytesRead != sizeof( WORD ) )
        return (UINT)-1;
    // Was it 'reserved' ?   (ie 0)
    if( Input != 0 )
        return (UINT)-1;
    // Read the type WORD
    if( ! ReadFile( hFile, &Input, sizeof( WORD ), &dwBytesRead, NULL ) )
        return (UINT)-1;
    // Did we get a WORD?
    if( dwBytesRead != sizeof( WORD ) )
        return (UINT)-1;
    // Was it type 1?
    if( Input != 1 )
        return (UINT)-1;
    // Get the count of images
    if( ! ReadFile( hFile, &Input, sizeof( WORD ), &dwBytesRead, NULL ) )
        return (UINT)-1;
    // Did we get a WORD?
    if( dwBytesRead != sizeof( WORD ) )
        return (UINT)-1;
    // Return the count
    return Input;
}

BOOL CIconFile::AdjustIconImagePointers( LPICONIMAGE lpImage )
{
    // Sanity check
    if( lpImage==NULL )
        return FALSE;
    // BITMAPINFO is at beginning of bits
    lpImage->lpbi = (LPBITMAPINFO)lpImage->lpBits;
    // Width - simple enough
    lpImage->Width = lpImage->lpbi->bmiHeader.biWidth;
    // Icons are stored in funky format where height is doubled - account for it
    lpImage->Height = (lpImage->lpbi->bmiHeader.biHeight)/2;
    // How many colors?
    lpImage->Colors = lpImage->lpbi->bmiHeader.biPlanes * lpImage->lpbi->bmiHeader.biBitCount;
    // XOR bits follow the header and color table
    lpImage->lpXOR = (LPBYTE)FindDIBBits((LPSTR)lpImage->lpbi);
    // AND bits follow the XOR bits
    lpImage->lpAND = lpImage->lpXOR + (lpImage->Height*BytesPerLine((LPBITMAPINFOHEADER)(lpImage->lpbi)));
    return TRUE;
}

WORD CIconFile::DIBNumColors( LPSTR lpbi )
{
    WORD wBitCount;
    DWORD dwClrUsed;

    dwClrUsed = ((LPBITMAPINFOHEADER) lpbi)->biClrUsed;

    if (dwClrUsed)
        return (WORD) dwClrUsed;

    wBitCount = ((LPBITMAPINFOHEADER) lpbi)->biBitCount;

    switch (wBitCount)
    {
        case 1: return 2;
        case 4: return 16;
        case 8:	return 256;
        default:return 0;
    }
    return 0;
}

BOOL CIconFile::WriteIconToICOFile( LPICONRESOURCE lpIR, LPCTSTR szFileName)
{
    HANDLE    	hFile;
    UINT        i;
    DWORD    	dwBytesWritten;
 
    // open the file
    if( (hFile = CreateFile( szFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL )) == INVALID_HANDLE_VALUE )
    {
//        MessageBox( hWndMain, "Error Opening File for Writing", szFileName, MB_OK );
        return FALSE;
    }
    // Write the header
    if( ! WriteICOHeader( hFile, lpIR->nNumImages ) )
    {
//        MessageBox( hWndMain, "Error Writing ICO File", szFileName, MB_OK );
        CloseHandle( hFile );
        return FALSE;
    }

    // Write the ICONDIRENTRY's
    for( i=0; i<lpIR->nNumImages; i++ )
    {
        ICONDIRENTRY    ide;

        // Convert internal format to ICONDIRENTRY
        ide.bWidth = lpIR->IconImages[i].Width;
        ide.bHeight = lpIR->IconImages[i].Height;
        ide.bReserved = 0;
        ide.wPlanes = lpIR->IconImages[i].lpbi->bmiHeader.biPlanes;
        ide.wBitCount = lpIR->IconImages[i].lpbi->bmiHeader.biBitCount;
        if( (ide.wPlanes * ide.wBitCount) >= 8 )
            ide.bColorCount = 0;
        else
            ide.bColorCount = 1 << (ide.wPlanes * ide.wBitCount);

        ide.dwBytesInRes = lpIR->IconImages[i].dwNumBytes;
        ide.dwImageOffset = CalculateImageOffset( lpIR, i );
        // Write the ICONDIRENTRY out to disk
        if( ! WriteFile( hFile, &ide, sizeof( ICONDIRENTRY ), &dwBytesWritten, NULL ) )
		{
			CloseHandle( hFile );
            return FALSE;
		}
        // Did we write a full ICONDIRENTRY ?
        if( dwBytesWritten != sizeof( ICONDIRENTRY ) )
		{
			CloseHandle( hFile );
            return FALSE;
		}
    }
    // Write the image bits for each image
    for( i=0; i<lpIR->nNumImages; i++ )
    {
        DWORD dwTemp = lpIR->IconImages[i].lpbi->bmiHeader.biSizeImage;

        // Set the sizeimage member to zero
        lpIR->IconImages[i].lpbi->bmiHeader.biSizeImage = 0;
        // Write the image bits to file
        if( ! WriteFile( hFile, lpIR->IconImages[i].lpBits, lpIR->IconImages[i].dwNumBytes, &dwBytesWritten, NULL ) )
		{
			CloseHandle( hFile );
            return FALSE;
		}
        if( dwBytesWritten != lpIR->IconImages[i].dwNumBytes )
		{
			CloseHandle( hFile );
            return FALSE;
		}
        // set it back
        lpIR->IconImages[i].lpbi->bmiHeader.biSizeImage = dwTemp;
    }
    CloseHandle( hFile );
    return TRUE;
}

BOOL CIconFile::WriteICOHeader( HANDLE hFile, UINT nNumEntries )
{
    WORD    Output;
    DWORD	dwBytesWritten;

    // Write 'reserved' WORD
    Output = 0;
    if( ! WriteFile( hFile, &Output, sizeof( WORD ), &dwBytesWritten, NULL ) )
        return FALSE;
    // Did we write a WORD?
    if( dwBytesWritten != sizeof( WORD ) )
        return FALSE;
    // Write 'type' WORD (1)
    Output = 1;
    if( ! WriteFile( hFile, &Output, sizeof( WORD ), &dwBytesWritten, NULL ) )
        return FALSE;
    // Did we write a WORD?
    if( dwBytesWritten != sizeof( WORD ) )
        return FALSE;
    // Write Number of Entries
    Output = (WORD)nNumEntries;
    if( ! WriteFile( hFile, &Output, sizeof( WORD ), &dwBytesWritten, NULL ) )
        return FALSE;
    // Did we write a WORD?
    if( dwBytesWritten != sizeof( WORD ) )
        return FALSE;
    return TRUE;
}

DWORD CIconFile::CalculateImageOffset( LPICONRESOURCE lpIR, UINT nIndex )
{
    DWORD	dwSize;
    UINT    i;

    // Calculate the ICO header size
    dwSize = 3 * sizeof(WORD);
    // Add the ICONDIRENTRY's
    dwSize += lpIR->nNumImages * sizeof(ICONDIRENTRY);
    // Add the sizes of the previous images
    for(i=0;i<nIndex;i++)
        dwSize += lpIR->IconImages[i].dwNumBytes;
    // we're there - return the number
    return dwSize;
}

LPICONRESOURCE CIconFile::CreateIconFromBitmap(const stringx& sBitmapImage)
{
	LPBYTE lpDib = ReadBmpFromFile(sBitmapImage);
	if(!lpDib)
		return NULL;

	LPICONRESOURCE lpIR = NULL;

	//
	// There can only be one image from the provided bitmap, so always
	// allocate space for the icon header and one image.
	//
	lpIR = (LPICONRESOURCE)malloc(sizeof(ICONRESOURCE) + sizeof(ICONIMAGE));
	if(!lpIR)
		return NULL;

	ZeroMemory(lpIR, sizeof(ICONRESOURCE) + sizeof(ICONIMAGE));

	lpIR->nNumImages = 1;

	//
	// Get color depth, width, and height info from the bitmap we're
	// going to be streaming in.
	//
	LPBITMAPINFO lpBI = (LPBITMAPINFO)lpDib;
	LPICONIMAGE lpIconImage = &lpIR->IconImages[0];
	lpIconImage->Colors = lpBI->bmiHeader.biBitCount;
	lpIconImage->Height = lpBI->bmiHeader.biHeight;
	lpIconImage->Width = lpBI->bmiHeader.biWidth;

	if(!BmpToIconImage(lpDib, lpIconImage))
	{
		free(lpDib);
		free(lpIR);
		return NULL;
	}

	//
	// This could probably be an autopointer, but I'm too lazy
	// to include the right header.
	//
	free(lpDib);

	m_lpIconResource = lpIR;
	return lpIR;
}

LPBYTE CIconFile::ReadBmpFromFile(const stringx& sBitmapFile)
{
	is::auto_handle hBitmapFile(CreateFile(sBitmapFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL));

	if(!hBitmapFile.valid())
		return NULL;

	//
	// Read the file header and validate bfType is 'BM' and the reserved
	// values are 0.
	//
	DWORD dwBytes = sizeof(BITMAPFILEHEADER);
	BITMAPFILEHEADER bfHeader;
	if(!ReadFile(hBitmapFile, &bfHeader, dwBytes, &dwBytes, NULL))
		return NULL;

	ATLASSERT(dwBytes == sizeof(BITMAPFILEHEADER));

	if(bfHeader.bfType != 0x4d42 || bfHeader.bfReserved1 != 0 || bfHeader.bfReserved2 != 0)
		return NULL;

	//
	// Read the info header and validate it is a valid
	// header.
	//
	LPBYTE lpDib = (LPBYTE)malloc(sizeof(BITMAPINFO));
	if(!lpDib)
		return NULL;

	dwBytes = sizeof(BITMAPINFOHEADER);
	if(!ReadFile(hBitmapFile, lpDib, dwBytes, &dwBytes, NULL))
	{
		free(lpDib);
		return NULL;
	}

	if(((LPBITMAPINFOHEADER)lpDib)->biSize != sizeof(BITMAPINFOHEADER))
	{
		free(lpDib);
		return NULL;
	}

	WORD wPaletteSize = PaletteSize((LPSTR)lpDib);
	DWORD dwBitsSize = ((LPBITMAPINFOHEADER)lpDib)->biHeight * BytesPerLine((LPBITMAPINFOHEADER)lpDib);
	LPBYTE lpTempBits = (LPBYTE)realloc(lpDib, sizeof(BITMAPINFOHEADER) + wPaletteSize + dwBitsSize);
	if(!lpTempBits)
		return NULL;

	lpDib = lpTempBits;

	//
	// Read color palette if present.
	//
	if(wPaletteSize)
	{
		if(!ReadFile(hBitmapFile, ((LPBITMAPINFO)lpDib)->bmiColors, wPaletteSize, &dwBytes, NULL))
		{
			free(lpDib);
			return NULL;
		}

		ATLASSERT(dwBytes == (DWORD)wPaletteSize);
	}

	//
	// Seek to the bits for the bitmap and read them in.
	//
	if(bfHeader.bfOffBits != 0)
	{
		if(SetFilePointer(hBitmapFile, bfHeader.bfOffBits, NULL, FILE_BEGIN) == 0xffffffff)
		{
			free(lpDib);
			return NULL;
		}
	}

	if(!ReadFile(hBitmapFile, FindDIBBits((LPSTR)lpDib), dwBitsSize, &dwBytes, NULL))
	{
		free(lpDib);
		return NULL;
	}

	return lpDib;
}

bool CIconFile::BmpToIconImage(LPBYTE lpDib, LPICONIMAGE lpIcon)
{
	//
	// This is modified from the original code sample. The original sample
	// allowed for converting/stretching from the original bitmap into the 
	// format the icon would be in. There is no need for us to be able to
	// do this, so I modified this code a bit. The CreateIconFromBitmap
	// function that calls this function already has the icon image information
	// set to the size and color depth of the source bitmap.
	//
	if(!lpDib || !lpIcon)
		return false;

	lpIcon->dwNumBytes = sizeof(BITMAPINFOHEADER) + PaletteSize((LPSTR)lpDib) +
		lpIcon->Height * BytesPerLine((LPBITMAPINFOHEADER)lpDib) +
		lpIcon->Height * WIDTHBYTES(lpIcon->Width);

	if(lpIcon->lpBits)
		free(lpIcon->lpBits);

	lpIcon->lpBits = (LPBYTE)malloc(lpIcon->dwNumBytes);
	if(!lpIcon->lpBits)
		return false;

	//
	// Copy the color table bits.
	//
	memcpy(lpIcon->lpBits, lpDib, sizeof(BITMAPINFOHEADER) + PaletteSize((LPSTR)lpDib));

	//
	// Copy the bitmaps and readjust the image pointers for the bitmap copied.
	//
	lpIcon->lpbi = (LPBITMAPINFO)lpIcon->lpBits;
	lpIcon->lpbi->bmiHeader.biHeight *= 2;
	lpIcon->lpXOR = (LPBYTE)FindDIBBits((LPSTR)lpIcon->lpBits);
	memcpy(lpIcon->lpXOR, FindDIBBits((LPSTR)lpDib), lpIcon->Height * BytesPerLine((LPBITMAPINFOHEADER)lpDib));
	lpIcon->lpAND = lpIcon->lpXOR + lpIcon->Height * BytesPerLine((LPBITMAPINFOHEADER)lpDib);
	memset(lpIcon->lpAND, 0, lpIcon->Height * WIDTHBYTES(lpIcon->Width));

	return true;
}