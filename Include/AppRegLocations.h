#ifndef _APPREGLOCATIONS_H_
#define _APPREGLOCATIONS_H_

#ifndef VERSION_PRODUCTVERSTR
	#include "..\..\Include\buildno.h"
#endif

// Name of the Msi Help FileName
// Note: This is not stored in Registry. I am putting here becuase we
// store other help file info here
static const TCHAR* const szMsiHelpFileName = _T("Msi.chm");
/////////////////////////////////////////////////////////////////////////////
// HKLM Settings
/////////////////////////////////////////////////////////////////////////////

// Root location for all settings in both HKCU and HKLM
#ifdef ITWI_OEMVERSION
	#define TUNER_OEM_REG	_T("Software\\InstallShield\\TunerOEM\\")

	static const TCHAR* g_lpszWackRoot = TUNER_OEM_REG;
	static const TCHAR const *szRecentFileKey = TUNER_OEM_REG _T("Recent File List");
	static const TCHAR const *szValidationRecentFileKey = TUNER_OEM_REG _T("Validation\\Recent File List");

	extern "C" const __declspec(selectany) TCHAR *g_szLogFile = TUNER_OEM_REG _T(VERSION_PRODUCTVERSTR) _T("\\Main");;

	static const TCHAR* const szProjectSettings = TUNER_OEM_REG _T("Project Settings");
	static const TCHAR* const szIdeSettings = TUNER_OEM_REG _T("IDE Settings");
	static const TCHAR* const szMainSettings = TUNER_OEM_REG _T(VERSION_PRODUCTVERSTR) _T("\\Main");
	static const TCHAR* const szURLInfo = TUNER_OEM_REG _T(VERSION_PRODUCTVERSTR) _T("\\URL Info");
	static const TCHAR* const szNavFileName = _T("ISTunerOEM.nav");

#else
	#define IS_IST_REG	_T("Software\\InstallShield\\IST\\")

	static const TCHAR* g_lpszWackRoot = IS_IST_REG _T(VERSION_PRODUCTVERSTR) ;
	static const TCHAR const *szRecentFileKey = IS_IST_REG _T("Recent File List");
	static const TCHAR const *szValidationRecentFileKey = IS_IST_REG _T("Validation\\Recent File List");

	extern "C" const __declspec(selectany) TCHAR *g_szLogFile = IS_IST_REG _T(VERSION_PRODUCTVERSTR) _T("\\Main");;

	static const TCHAR* const szProjectSettings = IS_IST_REG _T("Project Settings");
	static const TCHAR* const szIdeSettings = IS_IST_REG _T("IDE Settings");
	static const TCHAR* const szMainSettings = IS_IST_REG _T(VERSION_PRODUCTVERSTR) _T("\\Main");
	static const TCHAR* const szURLInfo = IS_IST_REG _T(VERSION_PRODUCTVERSTR) _T("\\URL Info");
	static const TCHAR* const szNavFileName = _T("ISTuner.nav");

#endif

extern "C" const __declspec(selectany) TCHAR *g_szWackLogFile = _T("Log File");


//Default Registry Values for IST
//ILocalSettings
static const TCHAR* const szEmailAddress = _T("www.installshield.com");
static const TCHAR* const szLogFileName = _T("ISTuner.log");
static const TCHAR* const szHelpFileName = _T("Tuner.chm");
static const TCHAR* const szOEMConfigToolHelpFileName = _T("TunerOEMConfig.chm");


//IST Values to be created 
//ILocalSettings
static const TCHAR* const szMsiVersion = _T("Msi Version");
static const TCHAR* const szProductCode = _T("Product Code");
static const TCHAR* const szProgramFolder = _T("Program Folder");
static const TCHAR* const szWackLogFile = _T("Log File");
static const TCHAR* const szEmail = _T("Email");
static const TCHAR* const szFeedback = _T("Feedback");
static const TCHAR* const szHome = _T("Home");
static const TCHAR* const szNavFile = _T("NavFile");
static const TCHAR* const szHelpFile = _T("HelpFile");
static const TCHAR* const g_szProductSKU = _T("ProductSKU");
static const TCHAR* const g_lpszDateUpdated = _T("DateUpdated");
static const TCHAR* const g_lpszFrequency = _T("Frequency");
static const TCHAR* const g_lpszSupportCentralUrl = _T("SupportCentralUrl");
static const TCHAR* const g_lpszIsOnWebUrl = _T("IsOnWebUrl");
static const TCHAR* const g_lpszOemHelpRedirectionUrl = _T("HelpRedirectionUrl");

//	Product Folder Locations
static const TCHAR* const szProductLocation = _T("Product Location");
static const TCHAR* const g_lpszSystemLocation = _T("System");
static const TCHAR* const g_lpszSupportLocation = _T("Support");
static const TCHAR* const g_lpszRedistFolder = _T("Redist");

/////////////////////////////////////////////////////////////////////////////
// HKCU Settings
/////////////////////////////////////////////////////////////////////////////

//IUserSettings
static const TCHAR* const szUserISTodayLocation = _T("www.installshield.com");
static const TCHAR* const szUserFileLocation = _T("My Customization");
static const DWORD nHeight = 200;
static const DWORD nWidth = 200;
static const DWORD nLeft = 200;
static const DWORD nTop = 200;

// IDE Settings.  Parent key is the Root.
static const TCHAR* g_lpszIDERegKey = _T("IDE");
static const TCHAR* g_lpszIDEWorkspaces = _T("IDE\\Workspaces");


//IUserSettings
static const TCHAR* const szMstFileFolder = _T("Mst File Location");
static const TCHAR* const szMsiFileFolder = _T("Msi File Location");
static const TCHAR* const szHeight = _T("Height");
static const TCHAR* const szWidth = _T("Width");
static const TCHAR* const szLeft = _T("Left");
static const TCHAR* const szTop = _T("Top");
static const TCHAR* const szISToday = _T("ISToday");
static const TCHAR* const szISTodayLoc = _T("ISToday Location");
static const TCHAR* const g_lpszDisplayMsiFiles = _T("Display Msi Files");
static const TCHAR* const g_lpszAdditionalTransforms = _T("Additional Transforms");

/////////////////////////////////////////////////////////////////////////////
// Uninstall keys
/////////////////////////////////////////////////////////////////////////////
// Uninstall info.  Parent key is HKLM.
static const TCHAR* const g_lpszUNINSTALL_REGKEY = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\");
static const TCHAR* const g_lpszREGOWNER_VALUENAME = _T("RegOwner");
static const TCHAR* const g_lpszREGCOMPANY_VALUENAME = _T("RegCompany");
static const TCHAR* const g_lpszPRODUCTID_VALUENAME = _T("ProductID");
static const TCHAR* const g_lpszVERSION_VALUENAME = _T("DisplayVersion");

/////////////////////////////////////////////////////////////////////////////
//IST Installation related keys
/////////////////////////////////////////////////////////////////////////////
static const TCHAR* const g_lpszCubeComponentGUID = _T("{A8431EAB-3E20-11D4-8A43-006008AED607}");

/////////////////////////////////////////////////////////////////////////////
// 
/////////////////////////////////////////////////////////////////////////////
static const TCHAR* const AS_SUPPORT_CENTRAL= _T("http://support.installshield.com/support_central/adminstudio.asp");
static const TCHAR* const RELEASENOTES_FILE = _T("ReleaseNotes.htm");
static const TCHAR* const INSTALLSHIELD_HOMEPAGE = _T("http://www.installshield.com");
static const TCHAR* const OEMHELP_REDIRECTIONURL = _T("_redirect.htm#ms-its:ISTuner.chm::/");

#endif // _APPREGLOCATIONS_H_
