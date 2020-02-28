// switch for windwo/pm compiling
#ifndef _WIN_PM_H
//#define _WIN_PM_H 1
#define DBX_WIN 1
//#define DBX_PM 1

#ifdef _DBX_WIN // flavor of windows
#include <wintype.h>
#endif
        // Include mappings for function renames
#ifndef _NORENAME

#ifndef _NOMEMHOOK

#include <memhook.h>

#endif

#endif

#endif
