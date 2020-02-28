#pragma once
#include "fontutil.h"

#define DEFAULT_FONT_NAME	_T("Calibri")

const int MAX_FONT_NAME = 50;


class CLanguageFontSettings
{
public:
	CLanguageFontSettings() {};
	~CLanguageFontSettings() {};
	
	void GetLanguageFontProps(LPTSTR szFontName, long* plCharSet, long* plFontSize)
	{
	    ::GetSystemFontName(szFontName, plCharSet, plFontSize);
		if ((*plCharSet) == ANSI_CHARSET) // English and German
		{
			_tcscpy(szFontName, DEFAULT_FONT_NAME);
			*plFontSize = 8;
		}
		else	// Japanese
		{
			if (!_tcscmp(szFontName, _T("")))
				_tcscpy(szFontName, DEFAULT_FONT_NAME);
		}
	}
};


class CFontMixin : public CLanguageFontSettings
{
public:
    CFontMixin()
	{
		m_WrkSpcFont = NULL;
		m_WrkSpcFontBig = NULL;
		m_WrkSpcFontBold = NULL;
	}

    virtual ~CFontMixin()
	{
		if (m_WrkSpcFontBig)
	    {
			DeleteObject(m_WrkSpcFontBig);
		}
		if (m_WrkSpcFontBold)
	    {
			DeleteObject(m_WrkSpcFontBold);
		}
	}	

	void SetFontInfo()
	{
		CreateFont();
		CreateFontBig();
		CreateFontBold();
	}
			
    void SetDlgBigFont (UINT nIDTemplate)
	{
	    CreateFontBig();
	    HWND hWnd = GetHWND();
	    ::SendMessage(::GetDlgItem(hWnd, nIDTemplate), WM_SETFONT, (WPARAM)(HFONT)m_WrkSpcFontBig, LPARAM(0));
	}	

	void SetDlgBoldFont (UINT nIDTemplate)
	{
	    CreateFontBold();
	    HWND hWnd = GetHWND();
	    ::SendMessage(::GetDlgItem(hWnd, nIDTemplate), WM_SETFONT, (WPARAM)(HFONT)m_WrkSpcFontBold, LPARAM(0));
	}	

	void CreateFont()
	{
		if (m_WrkSpcFont != NULL)
			return;

	    HWND hWnd = GetHWND();
		ASSERT(hWnd != NULL);

		m_WrkSpcFont = reinterpret_cast<HFONT>(::SendMessage(GetHWND(), WM_GETFONT, 0, 0L));
		if (m_WrkSpcFont == NULL)
			m_WrkSpcFont = reinterpret_cast<HFONT>(::GetStockObject(SYSTEM_FONT));
	}
			
    void CreateFontBig()
	{
	    if (!m_WrkSpcFontBig)
	    {
			CreateFont();
			ASSERT(m_WrkSpcFont != NULL);
						
			if (m_WrkSpcFont)
			{
				LOGFONT lf;
				::GetObject(m_WrkSpcFont, sizeof(LOGFONT), &lf);
				lf.lfWeight = FW_BOLD;
				lf.lfHeight = (lf.lfHeight * 5)/4;
				m_WrkSpcFontBig = ::CreateFontIndirect(&lf);
			}
		}
	}		
	
	void CreateFontBold()
	{
		if (!m_WrkSpcFontBold)
		{
			CreateFont();
			ASSERT(m_WrkSpcFont != NULL);
						
			if (m_WrkSpcFont)
			{
				LOGFONT lf;
				::GetObject(m_WrkSpcFont, sizeof(LOGFONT), &lf);
				lf.lfWeight = FW_BOLD;
				m_WrkSpcFontBold = ::CreateFontIndirect(&lf);
			}
		}
	}		

	virtual HWND GetHWND() = 0;

protected:
	HFONT m_WrkSpcFont;   
	HFONT m_WrkSpcFontBig;
	HFONT m_WrkSpcFontBold;
};
