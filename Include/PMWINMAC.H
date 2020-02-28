#ifndef _PMWINMACRO
#define _PMWINMACRO

 /*=======================================================================*/
 /*                 The Stirling Group  (c) 1990                          */
 /*                 Roselle, Illinois 60172  USA                          */
 /*                 All rights Reserved.                                  */
 /*                 SHIELD (tm)                                           */
 /*                 Macro definitions for Windows<==>PM                   */
 /*=======================================================================*/

 //
 //
 //   File :     pmwinmac.h
 //
 //   Purpose :  To provide macros for pm-window similarities.
 //              This should reduce the code necessary for
 //              convertable code.
 //

#ifdef _PMPROG

        // Functions
#define _WinSendMsg         WinSendMsg
#define _WinPostMsg         WinPostMsg
#define _WinSetWindowText   WinSetWindowText
#define _WinDefWindowProc   WinDefWindowProc
#define _WinDestroyWindow   WinDestroyWindow
#define _WinSetWindowPtr( x, y, z )    WinSetWindowPtr( (HWND) x, y, (PVOID) z )
#define _WinQueryWindowPtr  WinQueryWindowPtr
#define _WinEnableWindow    WinEnableWindow
#define _WinIsWindowEnabled WinIsWindowEnabled
#define _WinSetFocus( x )   WinSetFocus( HWND_DESKTOP, x )
#define _WinQueryFocus( x ) WinQueryFocus( HWND_DESKTOP )
#define _WinIsWindowVisible WinIsWindowVisible
#define _sprintf            sprintf
#define _DosFreeModule( x ) DosFreeModule( (HMODULE) x )
#define _WinInvalidateRect  WinInvalidateRect
#define _WinUpdateWindow    WinUpdateWindow
#define _FreeProcInstance( x )     x = x
#define _MakeProcInstance( x, y )  x

#define DISABLE_OS_ERROR() DosError( FERR_DISABLEHARDERR );
#define ENABLE_OS_ERROR()  DosError( FERR_ENABLEHARDERR );


        // Constants
#define TSG_CAPTION_DY   WinQuerySysValue( HWND_DESKTOP, SV_CYTITLEBAR )
#define TSG_SCREEN_MAX_X WinQuerySysValue( HWND_DESKTOP, SV_CXSCREEN )
#define TSG_SCREEN_MAX_Y WinQuerySysValue( HWND_DESKTOP, SV_CYSCREEN )

#define HOURGLASSON( x ) WinSetCapture( HWND_DESKTOP, x ); WinSetPointer( HWND_DESKTOP, WinQuerySysPointer( HWND_DESKTOP, SPTR_WAIT, FALSE ))
#define HOURGLASSOFF()   WinSetCapture( HWND_DESKTOP, (HWND) NULL )

#define HINSTANCE( x )   WinQueryAnchorBlock( x )
#define PARENT( x )      WinQueryWindow( x, QW_PARENT )
#define OWNER( x )       WinQueryWindow( x, QW_OWNER )
#define HWNDFROMID( x, y ) WinWindowFromID( x, y )
#define CLIENT( x )      WinWindowFromID( x, FID_CLIENT )

#define _COMMAND_NOTIFY( x, y )    SHORT2FROMMP( x )
#define _COMMAND_ID( x )           SHORT1FROMMP( x )

        // International
#define _ASSIGN( x, y )    *x = *y; *((PSZ) ((ULONG) x + 1L )) = *((PSZ) ((ULONG) y + 1L ))

        // typedefs
#define _POINT          POINTL
#define _RECT           RECTL
#define _PPOINT         PPOINTL
#define _PRECT          PRECTL
#define _HAB            HAB
#define _HANDLE         ULONG
#define _HFONT          LONG
#define _HCURSOR        HPOINTER
#define _HICON          HPOINTER
#define _HMODULE        HMODULE
#define _HDC            HPS
#define _HBRUSH         ULONG
#define DRESULT         MRESULT

#else

#define HOURGLASSON( x ) SetCapture( x ); SetCursor( LoadCursor( NULL, MAKEINTRESOURCE( IDC_WAIT )))
#define HOURGLASSOFF()   ReleaseCapture()

        // Functions
#define _WinSendMsg   SendMessage
#define _WinPostMsg   PostMessage
#define _WinDefWindowProc  DefWindowProc
#define _WinSetWindowText  SetWindowText
#define _WinDestroyWindow  DestroyWindow
#define _WinSetWindowPtr( x, y, z )    SetWindowLong( (HWND) x, y, (LONG) z )
#define _WinQueryWindowPtr GetWindowLong
#define _WinEnableWindow   EnableWindow
#define _WinIsWindowEnabled IsWindowEnabled
#define _WinSetFocus( x )  SetFocus( x )
#define _WinQueryFocus( x ) GetFocus()
#define _WinIsWindowVisible IsWindowVisible
#define _sprintf           wsprintf
#define _DosFreeModule( x ) FreeLibrary( (HANDLE) x )
#define _WinInvalidateRect  InvalidateRect
#define _WinUpdateWindow    UpdateWindow
#define _FreeProcInstance( x )     FreeProcInstance( x )
#define _MakeProcInstance( x, y )  MakeProcInstance( x, y )
#define DISABLE_OS_ERROR() SetErrorMode( 0x8001 );
#define ENABLE_OS_ERROR()  SetErrorMode( 0x0 );

#define HINSTANCE( x )     GetWindowWord( x, GWW_HINSTANCE )
#define PARENT( x )        GetParent( x )
#define OWNER( x )         GetParent( x )
#define HWNDFROMID( x, y ) GetDlgItem( x, y )
#define CLIENT( x )      (HWND) x

        // International
#define _ASSIGN( x, y )    *x = *y; *((PSZ) ((ULONG) x + 1L )) = *((PSZ) ((ULONG) y + 1L ))

        // Constants
#define TSG_CAPTION_DY   GetSystemMetrics( SM_CYCAPTION )
#define TSG_SCREEN_MAX_X GetSystemMetrics( SM_CXSCREEN )
#define TSG_SCREEN_MAX_Y GetSystemMetrics( SM_CYSCREEN )

        // typedefs
#define _POINT          POINT
#define _RECT           RECT
#define _PPOINT         LPPOINT
#define _PRECT          LPRECT
#define _HAB            ULONG
#define _HANDLE         HANDLE
#define _HFONT          HFONT
#define _HCURSOR        HCURSOR
#define _HICON          HICON
#define _HMODULE        ULONG
#define _HDC            HDC
#define _HBRUSH         HBRUSH
#define DRESULT         BOOL

#ifdef NT
#define _COMMAND_HWND( y )         (HWND) y
#define _COMMAND_NOTIFY( x, y )    HIWORD( x )
#define _COMMAND_ID( x )           LOWORD( x )
#define HUGE
#define huge
#define PHUGE                      LPSTR
#else
#define _COMMAND_HWND( y )         (HWND) LOWORD( y )
#define _COMMAND_NOTIFY( x, y )    HIWORD( y )
#define _COMMAND_ID( x )           x
#define HUGE                       huge
#define PHUGE                      CHAR HUGE *
#define DEF_PHUGE
#endif

#endif

#endif
