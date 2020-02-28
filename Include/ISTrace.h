#ifndef ISTRACE_H
#define ISTRACE_H

#include <stdio.h>
#include <crtdbg.h>

#ifdef TRACE_SRV
#include "TraceSrv.h"
#endif

#ifdef TRACE_SRV
inline void Trace(const TCHAR* pszMsg)
{
    ITrace* pTrace;

    HRESULT hRet = CoCreateInstance(CLSID_Trace, NULL, CLSCTX_SERVER, IID_ITrace, (void**)&pTrace);
    if (SUCCEEDED(hRet))
    {
        wchar_t* bstr = 0;

        #ifdef UNICODE
        bstr = ::SysAllocString(pszMsg));
        #else
        wchar_t buf[1024];
        size_t cb = mbstowcs(buf, pszMsg, sizeof(buf));
        if (cb == sizeof(buf))
        {
            buf[sizeof(buf) - 1] = 0;
        }
        else if (cb == (size_t) - 1)
        {
            buf[0] = 0;
        }
        bstr = ::SysAllocString(buf);
        #endif

        pTrace->Trace(bstr);
        pTrace->Release();
        ::SysFreeString(bstr);
    }
}
#endif // #ifdef TRACE_SRV

#ifdef _DEBUG
inline void _cdecl ISTrace(LPCTSTR lpszFormat, ...)
{
    va_list args;
    va_start(args, lpszFormat);

    int nBuf;
    TCHAR szBuffer[512];

    nBuf = _vsntprintf(szBuffer, sizeof(szBuffer), lpszFormat, args);
    _ASSERTE(nBuf < sizeof(szBuffer)); //Output truncated as it was > sizeof(szBuffer)

#ifdef TRACE_SRV
    Trace(szBuffer);
#else
    OutputDebugString(szBuffer);
#endif
    va_end(args);
}

inline void _cdecl ISTrace2(DWORD category, UINT level, LPCTSTR lpszFormat, ...)
{
    va_list args;
    va_start(args, lpszFormat);

    int nBuf;
    TCHAR szBuffer[512];

    nBuf = _vsntprintf(szBuffer, sizeof(szBuffer), lpszFormat, args);
    _ASSERTE(nBuf < sizeof(szBuffer)); //Output truncated as it was > sizeof(szBuffer)

#ifdef TRACE_SRV
    Trace(szBuffer);
#else
    OutputDebugString(szBuffer);
#endif
    va_end(args);
}
#endif // #ifdef _DEBUG

#ifdef _DEBUG
#define ISTRACE            ISTrace
#undef ATLTRACE
#undef ATLTRACE2
#define ATLTRACE           ISTrace
#define ATLTRACE2          ISTrace2
#else
#define ISTRACE            1 ? (void)0 : AtlTrace
#endif

#endif
