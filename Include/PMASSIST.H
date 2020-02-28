// These make windows more compatible with PM


#ifndef PASCAL
#define PASCAL  pascal
#endif

#ifndef PASCAL
#define FAR     far
#endif

#ifndef PASCAL
#define NEAR    near
#endif

#define VOID    void

#define HAB     int


//typedef unsigned short SHANDLE;

typedef HANDLE         SHANDLE;
typedef void far      *LHANDLE;

#define EXPENTRY CALLBACK
#define APIENTRY WINAPI


#define CHAR    char            /* ch  */
#define SHORT   short           /* s   */
#define LONG    long            /* l   */
#define FLOAT   float           /* f   */
#ifndef INCL_SAADEFS
#define INT     int             /* i   */
#endif /* !INCL_SAADEFS */

typedef unsigned char UCHAR;    /* uch */
typedef unsigned short USHORT;  /* us  */
typedef unsigned long ULONG;    /* ul  */
typedef long MRESULT;           /* mres */
typedef unsigned int  UINT;     /* ui  */

#ifndef WIN32
typedef unsigned char far  *PSZ;
#endif

//typedef char far  *PSZ;
typedef unsigned char near *NPSZ;
//typedef char near *NPSZ;

typedef PSZ       *NPPSZ;
typedef PSZ  FAR  *PPSZ;

typedef char far  *PCH;
typedef char near *NPCH;


typedef long  (pascal far  *PFNL)();

typedef int   (pascal far  *PFN)();
typedef int   (pascal near *NPFN)();
typedef PFN FAR *PPFN;

//typedef BYTE   FAR  *PBYTE;
#define PBYTE LPBYTE  // fixes the win 3.0 conversion
typedef BYTE   near *NPBYTE;

typedef CHAR   FAR *PCHAR;
typedef SHORT  FAR *PSHORT;
//typedef LONG   FAR *PLONG;
#define PLONG LPLONG    // fixed the win 3.0 conversion
#ifndef INCL_SAADEFS
//typedef INT    FAR *PINT;
#define PINT LPINT      // FIXED the win 3.0 conversion
#endif /* !INCL_SAADEFS */

typedef UCHAR  FAR *PUCHAR;
typedef USHORT FAR *PUSHORT;
typedef ULONG  FAR *PULONG;
#ifndef INCL_SAADEFS
typedef UINT   FAR *PUINT;
#endif /* !INCL_SAADEFS */

typedef VOID   FAR *PVOID;

typedef BOOL FAR *PBOOL;

typedef UINT   MPARAM1;
typedef LONG   MPARAM2;

#define FALSE   0
#define TRUE    1

typedef LONG  (pascal far  *STDPFN) ( PVOID );
typedef LONG  (pascal far  *WINPFN) ( HWND, UINT, MPARAM1, MPARAM2 );

typedef HWND FAR *PHWND;

/* Combine l & h to form a 32 bit quantity. */
#define MAKEULONG(l, h)  ((ULONG)(((USHORT)(l)) | ((ULONG)((USHORT)(h))) << 16))

/* Combine l & h to form a 16 bit quantity. */
#define MAKEUSHORT(l, h) (((USHORT)(l)) | ((USHORT)(h)) << 8)
#define MAKESHORT(l, h)  ((SHORT)MAKEUSHORT(l, h))

/* Extract high and low order parts of 16 and 32 bit quantity */
#define LOUCHAR(w)      ((UCHAR)(w))
#define HIUCHAR(w)      ((UCHAR)(((USHORT)(w) >> 8) & 0xff))
#define LOUSHORT(l)     ((USHORT)(l))
#define HIUSHORT(l)     ((USHORT)(((ULONG)(l) >> 16) & 0xffff))
