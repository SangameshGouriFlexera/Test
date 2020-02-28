// IconFile.h : header file
//
// Adapted from the IconPro sample found in the article titled "Icons in
// Win32" by John Hornick of Microsoft Corporation.
//

#ifndef __ICONFILE_H__INCLUDED_
#define __ICONFILE_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "iconstruct.h"


// How wide, in bytes, would this many bits be, DWORD aligned?
#define WIDTHBYTES(bits)      ((((bits) + 31)>>5)<<2)

/////////////////////////////////////////////////////////////////////////////
// Types

#pragma pack(push, 2)

// These first two structs represent how the icon information is stored
// when it is bound into a EXE or DLL file. Structure members are WORD
// aligned and the last member of the structure is the ID instead of
// the imageoffset.
typedef struct
{
	BYTE	bWidth;			// Width of the image
	BYTE	bHeight;		// Height of the image (times 2)
	BYTE	bColorCount;	// Number of colors in image (0 if >=8bpp)
	BYTE	bReserved;		// Reserved
	WORD	wPlanes;		// Color Planes
	WORD	wBitCount;		// Bits per pixel
	DWORD	dwBytesInRes;	// How many bytes in this resource?
	WORD	nID;			// The ID

} MEMICONDIRENTRY, *LPMEMICONDIRENTRY;

typedef struct 
{
	WORD			idReserved;   // Reserved
	WORD			idType;	   // resource type (1 for icons)
	WORD			idCount;	  // how many images?
	MEMICONDIRENTRY	idEntries[1]; // the entries for each image

} MEMICONDIR, *LPMEMICONDIR;

#pragma pack( pop )


// The following two structs are for the use of this program in
// manipulating icons. They are more closely tied to the operation
// of this program than the structures listed above. One of the
// main differences is that they provide a pointer to the DIB
// information of the masks.
typedef struct
{
	UINT			Width, Height, Colors; // Width, Height and bpp
	LPBYTE			lpBits;				// ptr to DIB bits
	DWORD			dwNumBytes;			// how many bytes?
	LPBITMAPINFO	lpbi;				  // ptr to header
	LPBYTE			lpXOR;				 // ptr to XOR image bits
	LPBYTE			lpAND;				 // ptr to AND image bits

} ICONIMAGE, *LPICONIMAGE;

typedef struct
{
	UINT		nNumImages;						  // How many images?
	ICONIMAGE	IconImages[1];				   // Image entries

} ICONRESOURCE, *LPICONRESOURCE;


/////////////////////////////////////////////////////////////////////////////
// CIconFile

class CIconFile
{
public:
	CIconFile();
	virtual ~CIconFile();

// Operations
public:
	BOOL LoadIcon(LPCTSTR szFileName, int nIndex, bool b16ColorsOnly = false);
	BOOL SaveIcon(LPCTSTR szFileName);
	void DestroyIcon();

	static BOOL IsResourceFile(LPCTSTR szFileName);
	static BOOL ExtractIcon(LPCTSTR szSource, int nIndex, LPCTSTR szDest);
	static BOOL ExtractIcon(LPCTSTR szSource, LPCTSTR szIconName, LPCTSTR szDest);
    static BOOL ExtractIcon16(LPCTSTR szSource, int nIndex, LPCTSTR szDest);

// Implementation
protected:
	LPTSTR m_lpID;
	int m_nIdxFind, m_nIdxCurr;
	LPICONRESOURCE m_lpIconResource;

protected:
	LPICONRESOURCE ReadIconFromEXEFile(HINSTANCE hLibrary, LPTSTR lpID, bool b16ColorsOnly = false);
	LPICONRESOURCE ReadIconFromEXEFile(HINSTANCE hLibrary, int nIndex, bool b16ColorsOnly = false);
	LPTSTR FindIconByIndex(HINSTANCE hLibrary, int nIndex);
	LPICONRESOURCE ReadIconFromICOFile( LPCTSTR szFileName, bool b16ColorsOnly = false);
	BOOL WriteIconToICOFile( LPICONRESOURCE lpIR, LPCTSTR szFileName );
	UINT ReadICOHeader( HANDLE hFile );
	BOOL AdjustIconImagePointers( LPICONIMAGE lpImage );
	BOOL WriteICOHeader( HANDLE hFile, UINT nNumEntries );
	DWORD CalculateImageOffset( LPICONRESOURCE lpIR, UINT nIndex );

	LPICONRESOURCE CreateIconFromBitmap(const stringx& sBitmapImage);

	static BOOL CALLBACK EnumProc(HMODULE hModule, LPCTSTR lpszType,
		LPTSTR lpszName, CIconFile* pThis);

	WORD DIBNumColors( LPSTR lpbi );

	inline WORD PaletteSize( LPSTR lpbi ) {
		return ( DIBNumColors( lpbi ) * sizeof( RGBQUAD ) );
	}

	inline LPSTR FindDIBBits( LPSTR lpbi ) {
		return ( lpbi + *(LPDWORD)lpbi + PaletteSize( lpbi ) ); }

	inline DWORD BytesPerLine( LPBITMAPINFOHEADER lpBMIH ) {
		return WIDTHBYTES(lpBMIH->biWidth * lpBMIH->biPlanes * lpBMIH->biBitCount); }

	LPBYTE ReadBmpFromFile(const stringx& sBitmapFile);
	bool BmpToIconImage(LPBYTE lpDib, LPICONIMAGE lpIcon);
};



/////////////////////////////////////////////////////////////////////////////

#endif//#ifndef __ICONFILE_H__INCLUDED_
