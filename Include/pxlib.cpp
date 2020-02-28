#include "stdafx.h"
#include "pxlib.h"

#define RGB_TO_RGBQUAD(r,g,b)   (RGB(b,g,r))
#define CLR_TO_RGBQUAD(clr)     (RGB(GetBValue(clr), GetGValue(clr), GetRValue(clr)))

HBITMAP PxLib::AfxLoadSysColorBitmap(HINSTANCE hInst, HRSRC hRsrc, BOOL bMono)
{
    struct COLORMAP
    {
        // use DWORD instead of RGBQUAD so we can compare two RGBQUADs easily
        DWORD rgbqFrom;
        int iSysColorTo;
    };
    static const COLORMAP sysColorMap[] =
    {
        // mapping from color in DIB to system color
        { RGB_TO_RGBQUAD(0x00, 0x00, 0x00),  COLOR_BTNTEXT },       // black
        { RGB_TO_RGBQUAD(0x80, 0x80, 0x80),  COLOR_BTNSHADOW },     // dark grey
        { RGB_TO_RGBQUAD(0xC0, 0xC0, 0xC0),  COLOR_BTNFACE },       // bright grey
        { RGB_TO_RGBQUAD(0xFF, 0xFF, 0xFF),  COLOR_BTNHIGHLIGHT }   // white
    };
    const int nMaps = 4;

    HGLOBAL hglb;
    if ((hglb = LoadResource(hInst, hRsrc)) == NULL)
        return NULL;

    LPBITMAPINFOHEADER lpBitmap = (LPBITMAPINFOHEADER)LockResource(hglb);
    if (lpBitmap == NULL)
        return NULL;

    // make copy of BITMAPINFOHEADER so we can modify the color table
    const int nColorTableSize = 16;
    UINT nSize = lpBitmap->biSize + nColorTableSize * sizeof(RGBQUAD);
    LPBITMAPINFOHEADER lpBitmapInfo = (LPBITMAPINFOHEADER)::malloc(nSize);
    if (lpBitmapInfo == NULL)
        return NULL;
    memcpy(lpBitmapInfo, lpBitmap, nSize);

    // color table is in RGBQUAD DIB format
    DWORD* pColorTable =
        (DWORD*)(((LPBYTE)lpBitmapInfo) + (UINT)lpBitmapInfo->biSize);

    for (int iColor = 0; iColor < nColorTableSize; iColor++)
    {
        // look for matching RGBQUAD color in original
        for (int i = 0; i < nMaps; i++)
        {
            if (pColorTable[iColor] == sysColorMap[i].rgbqFrom)
            {
                if (bMono)
                {
                    // all colors except text become white
                    if (sysColorMap[i].iSysColorTo != COLOR_BTNTEXT)
                        pColorTable[iColor] = RGB_TO_RGBQUAD(255, 255, 255);
                }
                else
                    pColorTable[iColor] =
                        CLR_TO_RGBQUAD(::GetSysColor(sysColorMap[i].iSysColorTo));
                break;
            }
        }
    }

    int nWidth = (int)lpBitmapInfo->biWidth;
    int nHeight = (int)lpBitmapInfo->biHeight;
    HDC hDCScreen = ::GetDC(NULL);
    HBITMAP hbm = ::CreateCompatibleBitmap(hDCScreen, nWidth, nHeight);

    if (hbm != NULL)
    {
        HDC hDCGlyphs = ::CreateCompatibleDC(hDCScreen);
        HBITMAP hbmOld = (HBITMAP)::SelectObject(hDCGlyphs, hbm);

        LPBYTE lpBits;
        lpBits = (LPBYTE)(lpBitmap + 1);
        lpBits += (1 << (lpBitmapInfo->biBitCount)) * sizeof(RGBQUAD);

        StretchDIBits(hDCGlyphs, 0, 0, nWidth, nHeight, 0, 0, nWidth, nHeight,
            lpBits, (LPBITMAPINFO)lpBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
        SelectObject(hDCGlyphs, hbmOld);

#ifdef _MAC
        // We don't change this bitmap any more, so get rid of the big,
        // wasteful Macintosh port
        ::SetBitmapReadOnly(hbm, BRO_READONLY);
#endif

        ::DeleteDC(hDCGlyphs);
    }
    ::ReleaseDC(NULL, hDCScreen);

    // free copy of bitmap info struct and resource itself
    ::free(lpBitmapInfo);
    ::FreeResource(hglb);

    return hbm;
}

//////////////////
// Load a bitmap, converting the standard colors.
// Calls AfxLoadSysColorBitmap to do the work.
//
// RGB(0x00, 0x00, 0x00) (black)      --> COLOR_BTNTEXT
// RGB(0x80, 0x80, 0x80) (dark gray)  --> COLOR_3DSHADOW
// RGB(0xC0, 0xC0, 0xC0) (gray)       --> COLOR_3DFACE
// RGB(0xFF, 0xFF, 0xFF) (white)      --> COLOR_3DHILIGHT
// 
HBITMAP PxLib::LoadSysColorBitmap(LPCTSTR lpResName, BOOL bMono)
{
    HINSTANCE hInst = _Module.m_hInst;
    HRSRC hRsrc = ::FindResource(hInst, lpResName, RT_BITMAP);
    if (hRsrc == NULL)
        return NULL;
    return AfxLoadSysColorBitmap(hInst, hRsrc, bMono);
}

//////////////////
// Shorthand to fill a rectangle with a solid color.
//
void PxLib::FillRect(HDC& dc, const CRect& rc, COLORREF color)
{
    HBRUSH brush = ::CreateSolidBrush(color);
    HBRUSH pOldBrush = static_cast<HBRUSH>(::SelectObject(dc, brush));
    ::PatBlt(dc, rc.left, rc.top, rc.Width(), rc.Height(), PATCOPY);
    ::SelectObject(dc, pOldBrush);
    ::DeleteObject(brush);
}

const COLORREF CWHITE  = RGB(255,255,255);

// This is the "magic" ROP code used to generate the embossed look for
// a disabled button. It's listed in Appendix F of the Win32 Programmer's
// Reference as PSDPxax (!) which is a cryptic reverse-polish notation for
//
// ((Destination XOR Pattern) AND Source) XOR Pattern
//
// which I leave to you to figure out. In the case where I apply it,
// Source is a monochrome bitmap which I want to draw in such a way that
// the black pixels get transformed to the brush color and the white pixels
// draw transparently i.e. leave the Destination alone.
//
// black ==> Pattern
// white ==> Destintation (ie, transparent)
//
// 0xb8074a is the ROP code that does this. For more info, see Charles
// Petzold, Programming Windows, 2nd Edition, p 622-624.
//
const DWORD MAGICROP = 0xb8074a;

//////////////////
// Draw an image with the embossed (disabled) look.
//
// dc device context to draw in
// il image list containing image
// i index of image to draw
// p point in dc to draw image at
//    bColor do color embossing. Default is B/W.
//
void PxLib::DrawEmbossed(HDC& dc, HIMAGELIST& il, int i,
    POINT p, BOOL bColor)
{
    IMAGEINFO info;
    ImageList_GetImageInfo(il, 0, &info);
    CRect rc = info.rcImage;
    int cx = rc.Width();
    int cy = rc.Height();

    // create memory dc
    HDC memdc = ::CreateCompatibleDC(dc);

    // create mono or color bitmap
    HBITMAP bm;
    if (bColor)
    {
        bm = ::CreateCompatibleBitmap(dc, cx, cy);
    }
    else
    {
        bm = ::CreateBitmap(cx, cy, 1, 1, NULL);
    }

    // draw image into memory DC--fill BG white first
    HBITMAP pOldBitmap = static_cast<HBITMAP>(SelectObject(memdc, bm));
    PatBlt(memdc, 0, 0, cx, cy, WHITENESS);
    ImageList_Draw(il, i, memdc, 0, 0, ILD_TRANSPARENT);

    // This seems to be required. Why, I don't know. ???
    COLORREF colorOldBG = SetBkColor(dc, CWHITE);

    // Draw using hilite offset by (1,1), then shadow
    HBRUSH brShadow = ::CreateSolidBrush(GetSysColor(COLOR_3DSHADOW));
    HBRUSH brHilite = ::CreateSolidBrush(GetSysColor(COLOR_3DHIGHLIGHT));
    HBRUSH pOldBrush = static_cast<HBRUSH>(::SelectObject(dc, brHilite));
    ::BitBlt(dc, p.x+1, p.y+1, cx, cy, memdc, 0, 0, MAGICROP);
    ::SelectObject(dc, brShadow);
    ::BitBlt(dc, p.x, p.y, cx, cy, memdc, 0, 0, MAGICROP);
    ::SelectObject(dc, pOldBrush);
    ::SetBkColor(dc, colorOldBG); // restore
    ::SelectObject(memdc, pOldBitmap); // ...
    ::DeleteObject(brShadow);
	::DeleteObject(brHilite);
    ::DeleteDC(memdc);
	::DeleteObject(bm);
}
