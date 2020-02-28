#ifndef _ISFONT_H_
#define _ISFONT_H_
#include <wingdi.h>


inline void GetSystemFontName(LPTSTR szFontName, long* plCharSet, long* plFontSize)
{
	HFONT hFont;
	LOGFONT lf;
	int iLogPixelsY;
	hFont = (HFONT) ::GetStockObject(DEFAULT_GUI_FONT);
	
	::GetObject (hFont, sizeof(lf), &lf);

	DWORD dwVersion = GetVersion();
	DWORD dwWindowsMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));

	*plCharSet = long(lf.lfCharSet) ;

	//calculate point size
	HDC dc = ::GetDC(NULL);
	iLogPixelsY = GetDeviceCaps(dc, LOGPIXELSY);
	::ReleaseDC(NULL, dc);
	if (iLogPixelsY > 0) 
	{
		*plFontSize = -72 * long(lf.lfHeight) / iLogPixelsY ;
	} 
	else 
	{
		*plFontSize = 8;
	}

	if (5 == dwWindowsMajorVersion)
	{
		_tcscpy(szFontName, _T(""));
	}
	else
	{
		_tcscpy(szFontName, lf.lfFaceName);


		if (0 == (lstrcmp(_T("MS Sans Serif"), szFontName)) || (0 == _tcscmp(_T("System"), szFontName)))
		{
			_tcscpy(szFontName, _T(""));
		}
	}
}

#endif 
