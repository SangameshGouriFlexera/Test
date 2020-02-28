THIS FILE SHOULD NOT BE USED - Use INCConverter\INCConverterApi.h

//#pragma once

// This is the implementation of the C interface
// exposed by this DLL.
//
// If you want to use this DLL from your app,
// you must #define USING_INCCONVERTER.
//
// The interface functions are enclosed inside the
// INCConverter namespace.

//#ifdef USING_INCCONVERTER
//#define APISPEC __declspec( dllimport )
//#else
//#define APISPEC __declspec( dllexport )
//#endif

//#include "INCConverterEvent.h"

//namespace INCConverter
//{
//	void APISPEC Convert(LPCTSTR szIncFile, LPCTSTR szOptionsFile, LPCTSTR szIsmFile, bool bBuild);
//	void APISPEC Cancel();
//	void APISPEC SetEventCallback(EventCallback pfn);
//	void APISPEC GetTargetDirectories(LPCTSTR szIncFile, LPTSTR szDirectories, LPTSTR szRecommendedDir, long nDirListBuffLen = MAX_PATH*100, long nRecBuffLen = MAX_PATH);
//	void APISPEC SetInstallDir(LPCTSTR szInstallDir);

	// Deprecated - do not use
//	void APISPEC SetOtherFilesNewComponents(bool bNewComponents = true);
//}

//void CALLBACK UnitTest(HWND hwnd, HINSTANCE hinst, LPTSTR lpCmdLine, int nCmdShow);

//typedef void (*pfnINCConvert)(LPCTSTR szIncFile, LPCTSTR szOptionsFile, LPCTSTR szIsmFile, bool bBuild);
//typedef void (*pfnINCCancel)();
//typedef void (*pfnINCSetEventCallback)(EventCallback pfn);
//typedef void (*pfnINCGetTargetDirectories)(LPCTSTR szIncFile, LPTSTR szDirectories, LPTSTR szRecommendedDir, long nDirListBuffLen, long nRecBuffLen);
//typedef void (*pfnINCSetInstallDir)(LPCTSTR szInstallDir);
