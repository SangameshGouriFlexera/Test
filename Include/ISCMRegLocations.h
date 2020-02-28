#ifndef _ISCMREGLOCATIONS_H_
#define _ISCMREGLOCATIONS_H_

#ifndef VERSION_PRODUCTVERSTR
	#include "..\Include\buildno.h"
#endif

/////////////////////////////////////////////////////////////////////////////
// HKLM Settings
/////////////////////////////////////////////////////////////////////////////

#if _MSC_VER < 1400
static const TCHAR* const g_lpszMainSettings = _T("Software\\InstallShield\\AdminStudio\\ConflictSolver\\12.0\\Main");
#else
static const TCHAR* const g_lpszMainSettings = _T("Software\\InstallShield\\AdminStudio\\ConflictSolver\\") _T(VERSION_PRODUCTVERSTR) _T("\\Main");
#endif

//special purpose conflict solver configuration information
static const TCHAR* const g_lpszBrokenFileLinks = _T("DisplayBrokenFileLinks");
static const TCHAR* const g_lpszModeSetting = _T("LastModeSetting");
static const TCHAR* const g_lpszViewDisplay = _T("ViewDisplay");

//IISCMLocalSettings
static const TCHAR* const g_lpszProductCode = _T("Product Code");
static const TCHAR* const g_lpszProgramFolder = _T("Program Folder");
static const TCHAR* const g_lpszSQLInitScript = _T("Default SQL Database");
static const TCHAR* const g_szProductSKU = _T("ProductSKU");
static const TCHAR* const g_szDebugAceQueries = _T("AceDebug");
static const TCHAR* const g_szShowEANodes = _T("ShowExtendedAttributeNodes");
static const TCHAR* const g_lpszAutoImportInterval = _T("AutoImportInterval");

//	Product Folder Locations
static const TCHAR* const g_lpszProductLocation = _T("Product Location");
static const TCHAR* const g_lpszSystemLocation = _T("System");
static const TCHAR* const g_lpszSupportLocation = _T("Support");
static const TCHAR* const g_lpszSampleLocation = _T("Samples");
static const TCHAR* const g_lpszRedistFolder = _T("Redist");

//IISCMLocalSettings Default Values
static const TCHAR* const g_lpszLogFileName = _T("ISCM.log");

/////////////////////////////////////////////////////////////////////////////
// HKCU Settings
/////////////////////////////////////////////////////////////////////////////

//	IISCMUserSettings: Keys
static const TCHAR* g_lpszDatabaseSettings = _T("Software\\InstallShield\\AdminStudio\\ConflictSolver\\Database");
static const TCHAR* g_lpszValidationKey = _T("Software\\InstallShield\\AdminStudio\\ConflictSolver\\Validation");
static const TCHAR* g_lpszConflictKey = _T("Software\\InstallShield\\AdminStudio\\ConflictSolver\\Conflict");
static const TCHAR* g_lpszImportKey = _T("Software\\InstallShield\\AdminStudio\\ConflictSolver\\Import");
static const TCHAR* g_lpszMainKey = _T("Software\\InstallShield\\AdminStudio\\ConflictSolver\\Main");
static const TCHAR* g_lpszSearchKey = _T("Software\\InstallShield\\AdminStudio\\ConflictSolver\\Search");

//	IISCMUserSettings: ValueData
static const TCHAR* const g_szDbConnectionString = _T("ConnectionString");
static const TCHAR* const g_szValidationFile = _T("CubFile");
static const TCHAR* const g_szMsiRules = _T("MsiRules");
static const TCHAR* const g_szMsmValidationFile = _T("MsmCubFile");
static const TCHAR* const g_szMsmRules = _T("MsmRules");
static const TCHAR* const g_szSuppressInfo = _T("SuppressInfo");
static const TCHAR* const g_szSuppressError = _T("SuppressError");
static const TCHAR* const g_szSuppressWarning = _T("SuppressWarning");
static const TCHAR* const g_lpszStandardMicrosoftReports = _T("StandardMicrosoftReports");
static const TCHAR* const g_lpszStandardOracleReports = _T("StandardOracleReports");
static const TCHAR* const g_lpszDupNameSyntax = _T("Duplicate Name Syntax");
static const TCHAR* const g_lpszCreateTransforms = _T("CreateTransforms");
static const TCHAR* const g_lpszWelcomeDialog = _T("WelcomeDialog");
static const TCHAR* const g_lpszTransformsLocation = _T("TransformLocation");
static const TCHAR* const g_szConflictTypes = _T("ConflictTypes");
static const TCHAR* const g_szConflictFile = _T("ACEFile");
static const TCHAR* const g_szMsmConflictFile = _T("MsmACEFile");
static const TCHAR* const g_szAccessOdbcDriver = _T("AccessOdbcDriver"); 
static const TCHAR* const g_szSqlOdbcDriver = _T("SQLOdbcDriver");
static const TCHAR* const g_szOracleOdbcDriver = _T("OracleOdbcDriver");
static const TCHAR* const g_lpszDragPrompt = _T("DragPrompt");
static const TCHAR* const g_lpszCrystalReports = _T("CrystalReports");
static const TCHAR* const g_lpszDisplayMaxRecords = _T("DisplayMaxRecords");
static const TCHAR* const g_szCustomConflictFile = _T("CustomACEFile");

static const TCHAR* const g_lpszLoggingOptions = _T("LogOptions");
static const TCHAR* const g_lpszLoggingDisplayOptions = _T("LogDisplayOptions");
static const TCHAR* const g_lpszLoggingDisplayRecords = _T("LogRecordLimit");

static const TCHAR* const g_lpszResolutionPreview = _T("ResolutionPreview");
static const TCHAR* const g_lpszResolutionMaxUserFlex = _T("ResolutionMaxUserFlex");
static const TCHAR* const g_lpszDisplayAll = _T("DisplayAll");
static const TCHAR* const g_lpszResolutionFavorIsolation = _T("ResolutionFavorIsolation");
static const TCHAR* const g_lpcsRebuildAssessment = _T("RebuildAssessment");

//	Import specific entries
static const TCHAR* const g_lpszValidate = _T("Validate");
static const TCHAR* const g_lpszConflict = _T("DetectConflict");
static const TCHAR* const g_lpszTestAutomatically = _T("AutoTest");
static const TCHAR* const g_lpszImportCustomTables = _T("CustomTables");
static const TCHAR* const g_lpszImportBinaryData = _T("BinaryData");
static const TCHAR* const g_lpszImportPEData = _T("PEData");
static const TCHAR* const g_lpszProcessIScriptHeaders = _T("IScriptHeaders");
static const TCHAR* const g_lpszImportAbortOnFatalError = _T("AbortOnFatalError");

//	IISCMUserSettings Default Values
static const TCHAR* const g_szDupNameSyntaxDefault = _T("[Manufacturer]_[ProductName]");
static const TCHAR* const g_szDbConnStrValue = _T("");
static const TCHAR* const g_lpszDefaultValidationFile = _T("darice.cub");
static const TCHAR* const g_lpszDefaultMsiRules = _T("");
static const TCHAR* const g_lpszDefaultMsmRules = _T("");
static const TCHAR* const g_lpszDefaultMsmValidationFile = _T("MergeMod.cub");
static const TCHAR* const g_lpszStandardReportLocation = _T("Reports\\Standard");
static const TCHAR* const g_lpszConflictReportLocation = _T("Reports\\Standard");
static const TCHAR* const g_lpszDefaultConflictFile = _T("isconflict.ace");
static const TCHAR* const g_lpszDefaultMsmConflictFile = _T("ismmconflict.ace");
static const TCHAR* const g_lpszDefaultCustomConflictFile = _T("CustomConflictFile.ace");
static const TCHAR* const g_szDefaultAccessOdbcDriver_Obsolete = _T("Microsoft Access Driver (*.mdb)"); 
static const TCHAR* const g_szDefaultSqlOdbcDriver = _T("SQL Server");
static const TCHAR* const g_szDefaultOracleDriver = _T("CR Oracle8 v3.6");
static const TCHAR* const g_szUserFileLocation = _T("My Resolutions");

static const TCHAR* const g_szSelectedACEList = _T("SelectedACEList");
static const TCHAR* const g_szSelectedBestACEList = _T("SelectedBestACEList");
static const TCHAR* const g_szBestACEList = _T("BestACEList");

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
// 
/////////////////////////////////////////////////////////////////////////////
static const TCHAR* const RELEASENOTES_FILE = _T("ReleaseNotes.htm");
static const TCHAR* const AS_SUPPORT_CENTRAL= _T("http://support.installshield.com/support_central/adminstudio.asp");
static const TCHAR* const INSTALLSHIELD_HOMEPAGE = _T("http://www.installshield.com");

#endif // _ISCMREGLOCATIONS_H_
