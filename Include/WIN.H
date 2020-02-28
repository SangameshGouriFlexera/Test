#include <win_pm.h>
#undef _MEM_NOHOOK
#define _WINPROG
#ifdef DBX_WIN
        // Windows includes
#include <windows.h>
#include <pmassist.h>

//if _WINNT_ is defined, NT's windows.h is used. Force NT to be defined.
#ifdef _WINNT_
#ifndef NT
#define NT
#endif
#endif

#ifdef NT
#define TSG_MAX_PATH    261
#else
#define TSG_MAX_PATH    145
#endif

#else
        // OS/2 Presentation Manager includes
#define  INCL_WIN
//#define  INCL_GPI
#define  INCL_DOS
#include <os2.h>

#include <pmextra.h>    // alias defines for our system

#define TSG_MAX_PATH    261

#endif

#include <pmwinmac.h>
