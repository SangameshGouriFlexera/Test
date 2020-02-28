#if !defined(_PXLIB_INCLUDED_)
#define _PXLIB_INCLUDED_

class CSize : public tagSIZE
{
public:
    CSize::CSize()
    {
        // random filled
    }
    CSize(int initCX, int initCY)
    {
        cx = initCX;
        cy = initCY;
    }
    CSize operator+(SIZE size) const
    {
        return CSize(cx + size.cx, cy + size.cy);
    }
    CSize operator-(SIZE size) const
    {
        return CSize(cx - size.cx, cy - size.cy);
    }
    BOOL operator==(SIZE size) const
    {
        return (cx == size.cx && cy == size.cy);
    }
    BOOL operator!=(SIZE size) const
    {
        return (cx != size.cx || cy != size.cy);
    }
};

class CRect : public tagRECT
{
public:
    CRect()
    {
        // random filled
    }
    CRect(int l, int t, int r, int b)
    {
        left = l;
        top = t;
        right = r;
        bottom = b;
    }
    CRect(const RECT& srcRect)
    {
        ::CopyRect(this, &srcRect);
    }
    operator LPRECT()
    {
        return this;
    }
    int Height() const
    {
        return bottom - top;
    }
    int Width() const
    {
        return right - left;
    }
    CSize CRect::Size() const
    {
        return CSize(right - left, bottom - top);
    }
};

namespace PxLib
{
    extern void FillRect(HDC& dc, const CRect& rc, COLORREF color);
    extern void DrawEmbossed(HDC& dc, HIMAGELIST& il, int i,
        POINT p, BOOL bColor=FALSE);

    extern HBITMAP LoadSysColorBitmap(LPCTSTR lpResName, BOOL bMono=FALSE);
    inline HBITMAP LoadSysColorBitmap(UINT nResID, BOOL bMono=FALSE)
    {
        return LoadSysColorBitmap(MAKEINTRESOURCE(nResID), bMono);
    }
    extern HBITMAP AfxLoadSysColorBitmap(HINSTANCE hInst, HRSRC hRsrc, BOOL bMono);
} // end namespace

#endif // !defined(AFX_STDAFX_H__E2E825E9_5EC8_11D2_8045_00104BD1A600__INCLUDED)
