#if !defined(AFX_GENGRID_H__BFC88A8B_CDD6_11D3_92C7_00104BD34E29__INCLUDED_)
#define AFX_GENGRID_H__BFC88A8B_CDD6_11D3_92C7_00104BD34E29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

#ifndef __ISWACK
#define ISGRID_DLL _T("ISGrid2.dll")
#else
#define ISGRID_DLL _T("ISGrid.dll")
#endif

// Dispatch interfaces referenced by this interface
#include "ISOleControlSite.h"

class CGenRowCursor;

/////////////////////////////////////////////////////////////////////////////
// CGenGrid wrapper class

class AFX_EXT_CLASS CGenGrid : public CWnd
{
protected:
	DECLARE_DYNCREATE(CGenGrid)
public:
	CLSID const& GetClsid()
	{
#ifndef __ISWACK
		static CLSID const clsid
			= {  0xC03AAB45, 0x221B, 0x11D4, { 0xAB, 0x3A, 0x00, 0xC0, 0x4F, 0x09, 0x71, 0x9C }  };

#elif ITWI_OEMVERSION
		static CLSID const clsid
			= {  0x8699892E, 0x7DEA, 0x41AC, { 0x99, 0x29, 0xc4, 0xa5, 0x49, 0x50, 0x5b, 0x74 } };

#else
		static CLSID const clsid
			= {  0x1FDAAB76, 0x810C, 0x11D5, { 0xAB, 0x7C, 0x00, 0xC0, 0x4F, 0x09, 0x71, 0x9A }  };
#endif

		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateEx(lpszWindowName, dwStyle, rect, pParentWnd, nID); }
//	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
//	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
//		pPersist, bStorage, bstrLicKey); }
	{ return CreateEx(lpszWindowName, dwStyle, rect, pParentWnd, nID,
			pPersist, bStorage, bstrLicKey); }

	BOOL CreateEx(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{
		CRect rect2( rect );
		CPoint pt;
		CSize size;

		pt = rect2.TopLeft();
		size = rect2.Size();

		CISWnd* pISParentWnd = (CISWnd*) pParentWnd;

		if ((pParentWnd == NULL) || !pISParentWnd->InitControlContainerEx())
			return FALSE;
		
		CISOleControlContainer* pISOleCtrlCont = pISParentWnd->GetCtrlCont();

		return pISOleCtrlCont->CreateControlEx(this, ISGRID_DLL, GetClsid(), lpszWindowName, dwStyle, &pt, &size, nID, 
			pPersist, bStorage, bstrLicKey); 
	}


// Attributes
public:

// Operations
public:
	long GetRows();
	void SetRows(long nNewValue);
	long GetCols();
	void SetCols(long nNewValue);
	long GetFixedRows();
	void SetFixedRows(long nNewValue);
	long GetFixedCols();
	void SetFixedCols(long nNewValue);
	short GetVersion();
	CString GetFormatString();
	void SetFormatString(LPCTSTR lpszNewValue);
	long GetTopRow();
	void SetTopRow(long nNewValue);
	long GetLeftCol();
	void SetLeftCol(long nNewValue);
	long GetRow();
	void SetRow(long nNewValue);
	long GetCol();
	void SetCol(long nNewValue);
	long GetRowSel();
	void SetRowSel(long nNewValue);
	long GetColSel();
	void SetColSel(long nNewValue);
	CString GetText();
	void SetText(LPCTSTR lpszNewValue);
	unsigned long GetBackColor();
	void SetBackColor(unsigned long newValue);
	unsigned long GetForeColor();
	void SetForeColor(unsigned long newValue);
	unsigned long GetBackColorFixed();
	void SetBackColorFixed(unsigned long newValue);
	unsigned long GetForeColorFixed();
	void SetForeColorFixed(unsigned long newValue);
	unsigned long GetBackColorSel();
	void SetBackColorSel(unsigned long newValue);
	unsigned long GetForeColorSel();
	void SetForeColorSel(unsigned long newValue);
	unsigned long GetBackColorBkg();
	void SetBackColorBkg(unsigned long newValue);
	BOOL GetWordWrap();
	void SetWordWrap(BOOL bNewValue);
	CString GetCellFontName();
	void SetCellFontName(LPCTSTR lpszNewValue);
	float GetCellFontSize();
	void SetCellFontSize(float newValue);
	BOOL GetCellFontBold();
	void SetCellFontBold(BOOL bNewValue);
	BOOL GetCellFontItalic();
	void SetCellFontItalic(BOOL bNewValue);
	BOOL GetCellFontUnderline();
	void SetCellFontUnderline(BOOL bNewValue);
	BOOL GetCellFontStrikeThrough();
	void SetCellFontStrikeThrough(BOOL bNewValue);
	float GetCellFontWidth();
	void SetCellFontWidth(float newValue);
	long GetTextStyle();
	void SetTextStyle(long nNewValue);
	long GetTextStyleFixed();
	void SetTextStyleFixed(long nNewValue);
	BOOL GetScrollTrack();
	void SetScrollTrack(BOOL bNewValue);
	long GetFocusRect();
	void SetFocusRect(long nNewValue);
	long GetHighLight();
	void SetHighLight(long nNewValue);
	BOOL GetRedraw();
	void SetRedraw(BOOL bNewValue);
	long GetScrollBars();
	void SetScrollBars(long nNewValue);
	long GetMouseRow();
	long GetMouseCol();
	long GetCellLeft();
	long GetCellTop();
	long GetCellWidth();
	long GetCellHeight();
	long GetRowHeightMin();
	void SetRowHeightMin(long nNewValue);
	long GetFillStyle();
	void SetFillStyle(long nNewValue);
	long GetGridLines();
	void SetGridLines(long nNewValue);
	long GetGridLinesFixed();
	void SetGridLinesFixed(long nNewValue);
	unsigned long GetGridColor();
	void SetGridColor(unsigned long newValue);
	unsigned long GetGridColorFixed();
	void SetGridColorFixed(unsigned long newValue);
	unsigned long GetCellBackColor();
	void SetCellBackColor(unsigned long newValue);
	unsigned long GetCellForeColor();
	void SetCellForeColor(unsigned long newValue);
	long GetCellAlignment();
	void SetCellAlignment(long nNewValue);
	long GetCellTextStyle();
	void SetCellTextStyle(long nNewValue);
	long GetCellPictureAlignment();
	void SetCellPictureAlignment(long nNewValue);
	CString GetClip();
	void SetClip(LPCTSTR lpszNewValue);
	void SetSort(long nNewValue);
	long GetSelectionMode();
	void SetSelectionMode(long nNewValue);
	long GetMergeCells();
	void SetMergeCells(long nNewValue);
	BOOL GetAllowBigSelection();
	void SetAllowBigSelection(BOOL bNewValue);
	long GetAllowUserResizing();
	void SetAllowUserResizing(long nNewValue);
	long GetBorderStyle();
	void SetBorderStyle(long nNewValue);
	long GetHWnd();
	BOOL GetEnabled();
	void SetEnabled(BOOL bNewValue);
	long GetAppearance();
	void SetAppearance(long nNewValue);
	long GetMousePointer();
	void SetMousePointer(long nNewValue);
	LPDISPATCH GetMouseIcon();
	void SetRefMouseIcon(LPDISPATCH newValue);
	long GetPictureType();
	void SetPictureType(long nNewValue);
	LPDISPATCH GetPicture();
	LPDISPATCH GetCellPicture();
	void SetRefCellPicture(LPDISPATCH newValue);
	CString GetTextArray(long index);
	void SetTextArray(long index, LPCTSTR lpszNewValue);
	long GetColAlignment(long index);
	void SetColAlignment(long index, long nNewValue);
	long GetColWidth(long index);
	void SetColWidth(long index, long nNewValue);
	long GetRowHeight(long index);
	void SetRowHeight(long index, long nNewValue);
	BOOL GetMergeRow(long index);
	void SetMergeRow(long index, BOOL bNewValue);
	BOOL GetMergeCol(long index);
	void SetMergeCol(long index, BOOL bNewValue);
	void SetRowPosition(long index, long nNewValue);
	void SetColPosition(long index, long nNewValue);
	VARIANT GetRowData(long index);
	void SetRowData(long index, const VARIANT& newValue);
	long GetColData(long index);
	void SetColData(long index, long nNewValue);
	CString GetTextMatrix(long Row, long Col);
	void SetTextMatrix(long Row, long Col, LPCTSTR lpszNewValue);
	void AddItem(LPCTSTR Item, long Row);
	void RemoveItem(long index);
	void Clear();
	void Refresh();
	CGenRowCursor GetDataSource();
	void SetDataSource(LPDISPATCH newValue);
	BOOL GetRowIsVisible(long index);
	BOOL GetColIsVisible(long index);
	long GetRowPos(long index);
	long GetColPos(long index);
	short GetGridLineWidth();
	void SetGridLineWidth(short nNewValue);
	long GetFixedAlignment(long index);
	void SetFixedAlignment(long index, long nNewValue);
	CString GetFontName();
	void SetFontName(LPCTSTR lpszNewValue);
	float GetFontSize();
	void SetFontSize(float newValue);
	BOOL GetFontBold();
	void SetFontBold(BOOL bNewValue);
	BOOL GetFontItalic();
	void SetFontItalic(BOOL bNewValue);
	BOOL GetFontStrikethru();
	void SetFontStrikethru(BOOL bNewValue);
	BOOL GetFontUnderline();
	void SetFontUnderline(BOOL bNewValue);
	BOOL GetRightToLeft();
	void SetRightToLeft(BOOL bNewValue);
	long GetOLEDropMode();
	void SetOLEDropMode(long nNewValue);
	void OLEDrag();
	void SetCellType(long Row, long Col, long Style);
	EEditStyle GetCellType(long Row, long Col);
	void ComboBoxAddItem(VARIANT* pvargItem, VARIANT* pvargIndex);
	void ComboBoxClear();
	void SetComboBoxStyle(long nNewValue);
	long GetComboBoxStyle();
	long GetEditMode();
	void SetLastRowEditInserts(BOOL bNewValue);
	BOOL GetLastRowEditInserts();
	void SetDisplayArrowOnSortedCol(BOOL bNewValue);
	BOOL GetDisplayArrowOnSortedCol();
	void EndEdit(BOOL Cancel);
	void AppendRow();
	void SetValue(long Row, long Col, LPCTSTR Value);
	CString GetValue(long Row, long Col);
	void SetComboBoxDropButtonStyle(long nNewValue);
	long GetComboBoxDropButtonStyle();
	void SetFillEntireWidth(BOOL bNewValue);
	BOOL GetFillEntireWidth();
	void BeginEdit();
	void TakeFocus();
	void SetScrollingEndsEdit(BOOL bNewValue);
	BOOL GetScrollingEndsEdit();
	void SetSingleClickEdit(BOOL bNewValue);
	BOOL GetSingleClickEdit();
	short GetFontCharset();
	void SetFontCharset(short nNewValue);
	void FindString();
	void ReplaceString();
	void SetMainMsgLoopWindow(long hWnd);
	void SetFindWindowCaption(LPCTSTR szCaption);
	void SetReplaceWindowCaption(LPCTSTR szCaption);
	void InitFindReplace(DWORD dwOptions);
	void DoFindReplace(LPCTSTR szSearchText, LPCTSTR szReplaceText, unsigned long dwOptions, BOOL* vbFound);
	void SetRowSelEx(long lRow);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENGRID_H__BFC88A8B_CDD6_11D3_92C7_00104BD34E29__INCLUDED_)
