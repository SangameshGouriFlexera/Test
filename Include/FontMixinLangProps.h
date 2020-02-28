const int OFFSET_FOR_BIG_FONT = 4;

#define GET_LANGUAGE_FONT_PROPS(szName, lnSize, lnCharSet)\
	_tcscpy(szName, _T("Tahoma"));\
	lnSize = 8;\
	lnCharSet = ANSI_CHARSET;

