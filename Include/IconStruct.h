#ifndef __ICONSTRUCT_H__INCLUDED_
#define __ICONSTRUCT_H__INCLUDED_

//	-------------------------------------------------------------------------------

#pragma pack(push, 2)

//	Icon structure
// These next two structs represent how the icon information is stored
// in an ICO file.
typedef struct
{
	BYTE	bWidth;               // Width of the image
	BYTE	bHeight;              // Height of the image (times 2)
	BYTE	bColorCount;          // Number of colors in image (0 if >=8bpp)
	BYTE	bReserved;            // Reserved
	WORD	wPlanes;              // Color Planes
	WORD	wBitCount;            // Bits per pixel
	DWORD	dwBytesInRes;         // how many bytes in this resource?
	DWORD	dwImageOffset;        // where in the file is this image
} ICONDIRENTRY, *LPICONDIRENTRY;

typedef struct
{
	WORD           idReserved;   // Reserved (must be 0)
	WORD           idType;       // Resource Type (1 for icons)
	WORD           idCount;      // How many images?
	ICONDIRENTRY   idEntries[1]; // An entry for each image (idCount of 'em)
} ICONDIR, *LPICONDIR;

#pragma pack( pop )

#endif//#ifndef __ICONSTRUCT_H__INCLUDED_
