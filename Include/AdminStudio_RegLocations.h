#ifndef _REGLOCATIONS_H_
#define _REGLOCATIONS_H_

#ifndef VERSION_PRODUCTVERSTR
	#include "buildno.h"
#endif

namespace AdmRegLocations
{
	/////////////////////////////////////////////////////////////////////////////
	// HKLM Settings
	/////////////////////////////////////////////////////////////////////////////

	static const TCHAR* const g_lpszIDESettingsKey = _T("InstallShield\\AdminStudio");
	static const TCHAR* const g_lpszAdminStudioRoot = _T("Software\\InstallShield\\AdminStudio");
	#define AS_REG_ROOT	_T("Software\\InstallShield\\AdminStudio\\")

#ifndef AS_FROZEN_APP
	static const TCHAR* const g_szASProductVersion = _T(VERSION_PRODUCTVERSTR);
	static const TCHAR* const g_lpszHKLMProdVer95Key = AS_REG_ROOT _T("\\9.5");
	static const TCHAR* const g_lpszHKLMProdVer10Key  = AS_REG_ROOT _T("\\10.0");
	static const TCHAR* const g_lpszHKLMProdVer105Key  = AS_REG_ROOT _T("\\10.5");
	static const TCHAR* const g_lpszHKLMProdVer11Key  = AS_REG_ROOT _T("\\11.0");
	static const TCHAR* const g_lpszHKLMProdVer115Key  = AS_REG_ROOT _T("\\11.5");
	static const TCHAR* const g_lpszAESKey = _T("Software\\InstallShield\\AdminStudio Enterprise Server\\") _T(VERSION_PRODUCTVERSTR);
	static const TCHAR* const g_lpszPatchManagerSettingsKey = AS_REG_ROOT _T(VERSION_PRODUCTVERSTR) _T("\\Patch Impact Manager");
#endif

#ifdef WSE
	static const TCHAR* const g_lpszHKLMMainSettingsKey = _T("Software\\Wise Solutions\\WiseScript Package Editor\\") _T(VERSION_PRODUCTVERSTR);
#else
	static const TCHAR* const g_lpszHKLMMainSettingsKey = AS_REG_ROOT _T(VERSION_PRODUCTVERSTR);
#endif \\WSE

	static const TCHAR* const g_lpszHKCUMainSettingsKey =  _T("Software\\InstallShield\\AdminStudio");
	static const TCHAR* const g_lpszHKCUUserSettingsKey = _T("Software\\InstallShield\\AdminStudio\\UserSettings");
	static const TCHAR* const g_lpszDeveloperSettingsKey = _T("Software\\InstallShield\\20.0\\Professional");
	static const TCHAR* const g_szASRecentDatabaseKey = _T("Software\\InstallShield\\AdminStudio\\Recent List");
    static const TCHAR* const g_lpszRunKey = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");

    //	Last directory accessed by the FileDialogEx class
	static const TCHAR* const g_lpszLastDirectory = _T("LastDir");

	//	LocalSettings
	static const TCHAR* const g_lpszAllowUpdates = _T("AllowUpdates");
	static const TCHAR* const g_lpszCurrentVersion = _T("CurrentVersion");
	static const TCHAR* const g_lpszProductCode = _T("Product Code");
	static const TCHAR* const g_lpszUpdateFrequency = _T("Frequency");
	static const TCHAR* const g_lpszDataUpdated = _T("DateUpdated");
	static const TCHAR* const g_lpszLicenseBorrowed = _T("LicenseBorrowed");
	static const TCHAR* const g_lpszUpdateURL = _T("UpdateURL");
	static const TCHAR* const g_lpszProgramLocation = _T("Program Location");
	static const TCHAR* const g_lpszTempLocation = _T("Temp Location");
	static const TCHAR* const g_lpszLivePages = _T("LivePages");
	static const TCHAR* const g_lpszDebug = _T("Debug");
	static const TCHAR* const g_lpszPatchManager = _T("PIMKEY");
	static const TCHAR* const g_lpszHelpFile = _T("HelpFile");
	static const TCHAR* const g_lpszMsiHelpFile = _T("MsiHelpFile");
	static const TCHAR* const g_lpszGSG = _T("GSG");
    static const TCHAR* const g_lpszBuildNumber = _T("BuildNumber");
    static const TCHAR* const g_lpszCommonDir = _T("Common Location");
	static const TCHAR* const g_lpszEdition = _T("Edition");
	static const TCHAR* const g_lpszReadMeFile = _T("ReadMe");
	static const TCHAR* const g_lpszDebugLogLevel = _T("DebugLogLevel");
	static const TCHAR* const g_lpszSampleDatabaseName = _T("Sample.mdb");
    static const TCHAR* const g_lpszDbUpgradeLogLocation = _T("Upgrade Logs");
    static const TCHAR* const g_lpszEntEvalSerialReg = _T("EntEvalSN");

	static const TCHAR* const g_lpszEditorLocation = _T("EditorLocation");
	static const TCHAR* const g_lpszErrorCentral = _T("ErrorCentral");
	static const TCHAR* const g_lpszEnableCitrix = _T("EnableCitrix");
	static const TCHAR* const g_lpszEnableAltiris = _T("EnableAltiris");
	static const TCHAR* const g_lpszEnableSoftwareTagging = _T("EnableSoftwareTagging");
	static const TCHAR* const g_lpszEnableThinstall = _T("EnableThinstall");
	static const TCHAR* const g_lpszEnableAppV = _T("EnableAppV");
	static const TCHAR* const g_lpszEnableAppVLauncher = _T("EnableAppVLauncher");
	static const TCHAR* const g_lpszHideSerialNumber = _T("HideSerialNumber");
	static const TCHAR* const g_lpszSerialReg        =	_T("ProductID");
	static const TCHAR* const g_lpszLSProductID      = _T("LSProductID");
	static const TCHAR* const g_lpszNLProductID      = _T("NLProductID");
	static const TCHAR* const g_lpszFeedbackURL = _T("FeedbackURL");

	// Test center settings
	static const TCHAR* const g_lpszTestCenterBase = _T("Software\\InstallShield\\AdminStudio\\ConflictSolver\\TestCenter");
	static const TCHAR* const g_lpszShowTimeStamps = _T("ShowTimeStamps");

	// File names used.
	static const TCHAR* const g_lpszHelpFileName = _T("AdminStudio.chm");
	static const TCHAR* const g_lpszLogFileName = _T("AdminStudio.log");
    static const TCHAR* const g_lpszReleaseNotesFileName = _T("ReleaseNotes.htm");

	//	Externs required for Process Exception.
	#ifndef AS_FROZEN_APP
	extern "C" const __declspec(selectany) TCHAR *g_szLogFile = AS_REG_ROOT _T(VERSION_PRODUCTVERSTR);
	#endif
	extern "C" const __declspec(selectany) TCHAR *g_szWackLogFile = _T("Log File");

	/////////////////////////////////////////////////////////////////////////////
	// HKCU Settings
	/////////////////////////////////////////////////////////////////////////////
	static const TCHAR* const g_lpszSharedLocation = _T("Shared Location");
	static const TCHAR* const g_lpszHelpFileLocation = _T("Help Location");
	static const TCHAR* const g_lpszToolViewStyle = _T("ToolView Style");
	static const TCHAR* const g_lpszDefaultAccessDatabase = _T("Default Access Database");
	static const TCHAR* const g_lpszNewSQLDBScripts = _T("New SQL Database Scripts");
	static const TCHAR* const g_lpszUpgradeSQLScripts = _T("Upgrade Database Scripts");
	static const TCHAR* const g_lpszNewOracleScripts = _T("New Oracle Scripts");
	static const TCHAR* const g_lpszWorkflowDatabase = _T("Workflow Database");
	static const TCHAR* const g_lpszClientGuid = _T("Client GUID");

	static const TCHAR * const SOURCE_MRULIST_REGKEY = _T("SOFTWARE\\InstallShield\\AdminStudio\\MRUList\\SourcePackages");
	static const TCHAR * const SOURCE_MRUFILE_REGKEY_NAME = _T("Package");

	static const TCHAR * const TARGETDIR_MRULIST_REGKEY = _T("SOFTWARE\\InstallShield\\AdminStudio\\MRUList\\TargetDirs");
	static const TCHAR * const TARGETDIR_MRULIST_REGKEY_NAME = _T("TargetDir");

	// Values used for HKCU Settings
	static const TCHAR* const g_lpszDefaultHelpFilesLocation = _T("Help");

	static const TCHAR* const g_lpszAccessDatabaseName = _T("Schema.mdb");
	static const TCHAR* const g_lpszSQLSchemaFileName = _T("AS_System_Schema.SQL");
	static const TCHAR* const g_lpszAMSSQLSchemaFileName = _T("AMS_System_Schema.SQL");
	static const TCHAR* const g_lpszAMSDataSchemaFileName = _T("AMS_Data.SQL");
	static const TCHAR* const g_lpszAMSStoredProcsFileName = _T("AMS_StoreProcs.SQL");
	static const TCHAR* const g_lpszSchemaSMSFileName = _T("SMSSchema.SQL");
	static const TCHAR* const g_lpszAS50VP1UpgradeScript = _T("AS50VP1Upgrade.SQL");
	static const TCHAR* const g_lpszAS50VP1UpgradeScript_Access = _T("AS50VP1Upgrade_Access.SQL");
	static const TCHAR* const g_lpszAS50VP1To55UpgradeScript = _T("Upgrade50VP1To55.SQL");
	static const TCHAR* const g_lpszAS50VP1To55UpgradeScript_Access = _T("Upgrade50VP1To55_Access.SQL");
	static const TCHAR* const g_lpszAMSIndexScript = _T("AMSCreateIndex.sql");
	static const TCHAR* const g_lpszAMSSampleTmplScript = _T("AMS_SamplePackagingTemplate.sql");

	//Oracle scripts
	static const TCHAR* const g_lpszOracleSchemaFileName = _T("AS_Schema_Oracle.SQL");
	static const TCHAR* const g_lpszOracleAMSSchemaFileName = _T("AMS_Schema_Oracle.SQL");
	static const TCHAR* const g_lpszOracleAMSIndexesFileName = _T("AMS_Indexes.sql");
	static const TCHAR* const g_lpszOracleAMSSampleTmplFileName = _T("AMS_SamplePackagingTemplate_Oracle.sql");

	// Patch Impact Manager Settings
    static const TCHAR* const g_lpszLastProductSelection = _T("Product Selection");
    static const TCHAR* const g_lpszLastServicePackSelection = _T("ServicePack Selection");

	/////////////////////////////////////////////////////////////////////////////
	// Uninstall keys
	/////////////////////////////////////////////////////////////////////////////
	// Uninstall info.  Parent key is HKLM.
	static const TCHAR* const g_lpszUNINSTALL_REGKEY = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\");
	static const TCHAR* const g_lpszREGOWNER_VALUENAME = _T("RegOwner");
	static const TCHAR* const g_lpszREGCOMPANY_VALUENAME = _T("RegCompany");
	static const TCHAR* const g_lpszPRODUCTID_VALUENAME = _T("ProductID");
	static const TCHAR* const g_lpszVERSION_VALUENAME = _T("DisplayVersion");
	static const TCHAR* const g_lpszProductSKU = _T("ProductSKU");
	static const TCHAR* const g_lpszReadMeURL = _T("ReadMe");

	//	Product Folder Locations
	static const TCHAR* const g_lpszProductLocation = _T("Product Location");
	static const TCHAR* const g_lpszSupportLocation = _T("Support");
	static const TCHAR* const g_lpszHelpLocation = _T("Help");
	static const TCHAR* const g_lpszCommonLocation = _T("Common");
	static const TCHAR* const g_lpszEvalChecker = _T("ISCommonHelper.DLL");
    static const TCHAR* const g_lpszRepackager = _T("Repackager");
	static const TCHAR* const g_lpszDeveloperLocation = _T("Install Location");
	static const TCHAR* const g_lpszDeveloperSystemFolder = _T("System");
	static const TCHAR* const g_lpszQuickStartLocation = _T("QuickStart");
	static const TCHAR* const g_lpszSampleMsisLocation = _T("Sample Msis");
	static const TCHAR* const g_lpszSqlExpInstLocation = _T("SQL Express");

	//	URL Locations
	static const TCHAR* const g_lpszHomePage = _T("www.installshield.com");
	static const TCHAR* const g_lpszSupportPage = _T("http://support.installshield.com/support_central/adminstudio.asp");

	static const TCHAR* const g_lpszOptionsIni = _T("Options.ini");
    static const TCHAR* const g_lpszDefaultEA = _T("EA_Default.xml");

	//-------------------------------------------------------------------------
	//	Pre-Deployment - User settings
	//-------------------------------------------------------------------------
	static int PD_MAX_MRU_FILES = 5;
	static const TCHAR * const PD_ROOTKEY = _T("PreDeployment");
	static const TCHAR * const PD_MRU_ROOTKEY = _T("PreDeployment\\MRUList");
	static const TCHAR * const PD_SRC_MSI_KEY = _T("SrcMSI");
	static const TCHAR * const PD_DEST_MSI_KEY = _T("TargetMSI");
	static const TCHAR * const PD_WEB_SVC_KEY = _T("WebService");
	static const TCHAR * const PD_CATALOG_KEY = _T("Catalog");
	static const TCHAR * const PD_USE_CUSTOM_CAT = _T("UseCustomCatalog");
	static const TCHAR * const PD_CUSTOM_CAT_CXN = _T("CustomCatalogConenctionString");
	static const TCHAR * const g_lpszPDTDistributeNow = _T("PDTDistributeNow");

	//-------------------------------------------------------------------------
	//	Distribution - User settings
	//-------------------------------------------------------------------------
	static int DIST_MAX_MRU_FILES = 5;
	static const TCHAR * const DIST_MRU_ROOTKEY = _T("Distribution\\MRUList");
	static const TCHAR * const DIST_MSI_KEY = _T("MSIFile");
	static const TCHAR * const DIST_MSP_KEY = _T("MSPFile");

	static const TCHAR * const DIST_TYPE_LAST_SEL = _T("LastType");
	static const TCHAR * const DIST_NETWORK = _T("Network");
	static const TCHAR * const DIST_FTP     = _T("FTP");
	static const TCHAR * const DIST_ADMIN   = _T("Admin");
	static const TCHAR * const DIST_MARIMBA = _T("Marimba");
    	static const TCHAR * const DIST_TIVOLI  = _T("Tivoli");
	static const TCHAR * const DIST_MANAGESOFT  = _T("ManageSoft");

	static const TCHAR * const DIST_MARIMBA_XMLTEMPLATE = _T("MarimbaXMLTemplate");
	static const TCHAR * const DEFAULT_XMLTEMPLATE = _T("MarimbaMSIpackage.xml");
    static const TCHAR * const DIST_MARIMBA_PUBLISH_URL = _T("MarimbaPublishURL");
    static const TCHAR * const DIST_MARIMBA_LAST_SEL = _T("MarimbaLastSelections");

    static const TCHAR * const DIST_MARIMBA_LAST_SEL_CHANNEL_DIR = _T("ChannelDir");
    static const TCHAR * const DIST_MARIMBA_LAST_SEL_PUB_URL = _T("PublishingURL");
    static const TCHAR * const DIST_MARIMBA_LAST_SEL_INCLUDE_ALL_FILES = _T("IncludeAllFiles");
    static const TCHAR * const DIST_MARIMBA_LAST_SEL_APP_PACKAGE_URL = _T("AppPackageURL");
    static const TCHAR * const DIST_MARIMBA_LAST_SEL_XML_TEMPLATE = _T("XMLTemplate");
    static const TCHAR * const DIST_MARIMBA_LAST_SEL_COPIER_URL = _T("CopierURL");
    static const TCHAR * const DIST_MARIMBA_APPEND_PUB_URL = _T("AppendToPublishingURL");

    static const TCHAR * const DIST_LANDESK_NETWORK = _T("LANDeskNewtork");
    static const TCHAR * const DIST_LANDESK_SCRIPT_LOC = _T("LANDeskScript");
    static const TCHAR * const DIST_LANDESK_LAST_SEL = _T("LANDeskLastSelections");
    static const TCHAR * const DIST_LANDESK_LAST_SEL_NETWORK = _T("Network");
    static const TCHAR * const DIST_LANDESK_LAST_SEL_SCRIPT_LOC = _T("CustomScriptLocation");
    static const TCHAR * const DIST_LANDESK_LAST_SEL_WI_CMDLINE = _T("WICmdline");
    static const TCHAR * const DIST_LANDESK_LAST_SEL_MULTICAST = _T("Multicast");

    static const TCHAR * const DIST_ALTIRIS_NETWORK = _T("AltirisNetwork");
    static const TCHAR * const DIST_ALTIRIS_SERVER = _T("AltirisServer");
	static const TCHAR * const DIST_ALTIRIS_LAST_USERNAME = _T("LastAltirisUserName");

    static const TCHAR * const DIST_NOVELL_SERVER = _T("NovellServer");
    static const TCHAR * const DIST_NOVELL_CONTEXT = _T("NovelleDirContext");
    static const TCHAR * const DIST_NOVELL_SOURCE_PATHS = _T("NovellSourcePaths");
    static const TCHAR * const DIST_NOVELL_LAST_SEL = _T("NovellLastSelections");
    static const TCHAR * const DIST_NOVELL_LAST_SEL_USER = _T("NovellUser");
    static const TCHAR * const DIST_NOVELL_LAST_SEL_SERVER = _T("Server");
    static const TCHAR * const DIST_NOVELL_LAST_SEL_CONTEXT = _T("eDirContext");
    static const TCHAR * const DIST_NOVELL_LAST_SEL_DISTRIBUTOR = _T("Distributor");
    static const TCHAR * const DIST_NOVELL_LAST_SEL_SRV_PATH = _T("ServerPath");
    static const TCHAR * const DIST_NOVELL_LAST_SEL_CONTEXT_APP = _T("NovellAppObjContext");
    static const TCHAR * const DIST_NOVELL_LAST_SEL_CONTEXT_DIST = _T("NovellDistObjContext");
    static const TCHAR * const DIST_NOVELL_LAST_SEL_CONTEXT_DISTRIBUTOR = _T("NovellDistributorObjContext");
    static const TCHAR * const DIST_NOVELL_LAST_SEL_SRV_SOURCE = _T("ServerSource");


	//-------------------------------------------------------------------------
	//	QualityMonitor User Settings
	//-------------------------------------------------------------------------
	static const TCHAR * const QM_ROOTKEY		= _T("QualityMonitor");
 	static const TCHAR * const QM_EXCL_PATH		= _T("Exclusion List");
  	static const TCHAR * const QM_TEMPL_PATH	= _T("Template File");
  	static const TCHAR * const QM_RT_FILTERS	= _T("RTFilters");
	static const TCHAR * const QM_TEMPL_AUTO	= _T("Auto Load");


	//-------------------------------------------------------------------------
	//	ASFileOpen Settings
	//-------------------------------------------------------------------------
    static const TCHAR* const g_lpszIniFileName = _T("Developer.ini");
    static const TCHAR* const g_lpszIniFileSection = _T("developer");
    static const TCHAR* const g_lpszIniFileKey = _T("InstallLocation");

	//-------------------------------------------------------------------------
	//	ASShared INI File Settings
	//-------------------------------------------------------------------------
	static const TCHAR* const g_lpszDefaultASSharedFolder = _T("AdminStudio Shared");
	static const TCHAR* const g_lpszASSharedIniFile = _T("Shared AdminStudio.ini");

	static const TCHAR* const g_lpszASDatabaseSection = _T("Database Settings");
	static const TCHAR* const g_lpszASDefaultDatabaseKey = _T("DefaultDatabase");
    static const TCHAR* const g_lpszASEncryptedDatabaseKey = _T("SecuredDatabaseKey");
	
	static const TCHAR* const g_lpszASCompatSolverDatabaseSection = _T("Compatibility Solver Database Settings");

	static const TCHAR* const g_lpszSwIdTagSection = _T("Software ID Tag Settings");
	static const TCHAR* const g_lpszSwIdTag_CreateOnImport = _T("EnableTagCreation");
	static const TCHAR* const g_lpszSwIdTag_TagCreatorName = _T("TagCreatorName");
	static const TCHAR* const g_lpszSwIdTag_TagCreatorName_DefaultVal = _T("Flexera Software LLC");
	static const TCHAR* const g_lpszSwIdTag_TagCreatorRegId = _T("TagCreatorRegID");
	static const TCHAR* const g_lpszSwIdTag_TagCreatorRegId_DefaultVal = _T("regid.2009-06.com.flexerasoftware,AdminStudio");

    static const TCHAR* const g_lpszIntegrationSection = _T("Integration");
	static const TCHAR* const g_lpszEA_AMSFlagKey = _T("EA_IntegrateWithAMS");
    static const TCHAR* const g_lpszHttpResolveTimeout = _T("ResolveTimeout");
    static const TCHAR* const g_lpszHttpConnectTimeout = _T("ConnectTimeout");
    static const TCHAR* const g_lpszHttpSendTimeout    = _T("SendTimeout");
    static const TCHAR* const g_lpszHttpReceiveTimeout = _T("ReceiveTimeout");

	//Duplicate options section and keys
	static const TCHAR* g_lpszDupOption_Section   = _T("Duplicate Options");
	static const TCHAR* g_lpszPackageCode_Key     = _T("PackageCode");
	static const TCHAR* g_lpszProductCode_Key     = _T("ProductCode");
	static const TCHAR* g_lpszProductLanguage_Key = _T("ProductLanguage");
	static const TCHAR* g_lpszProductVersion_Key  = _T("ProductVersion");
	static const TCHAR* g_lpszTransformList_Key   = _T("TransformList");

	//AppV Duplicate options
	static const TCHAR* g_lpszAppVPackageGUID_Key   = _T("PackageGUID");
	static const TCHAR* g_lpszAppVVersionGUID_Key   = _T("VersionGUID");

	//Oracle section
	static const TCHAR* g_lpszOracleSection				= _T("Oracle");
	static const TCHAR* g_lpszOrcaleDataFileSize		= _T("FileSize");
	static const TCHAR* g_lpszOrcaleDataFileExtentSize	= _T("ExtentSize");
	static const TCHAR* g_lpszOracleDefUserQuota        = _T("UserQuota");

	//OSUpdate section
	static const TCHAR* g_lpszMSSecureXMLFile = _T("mssecure.xml");

	// Patch Section
	static const TCHAR* const g_lpszPatchSettings = _T("Patch File Settings");
	static const TCHAR* const g_lpszPatchDownloadURL = _T("DownloadURL");
	static const TCHAR* const g_lpszDownloadAtStartup = _T("DownloadAtStartup");
	static const TCHAR* const g_lpszPIMKey = _T("PIMKEY");

	static const TCHAR* const g_lpszDefaultPatchDownloadURL = _T("http://www.installshield.com/downloads/isas/mssecurecab.asp");

	//PreDeployTest Section
	static const TCHAR* const g_lpszPreDeployTestSec = _T("PreDeployTest");
	static const TCHAR* const g_lpszPreDeployTestReportsURL = _T("PreDeployTestReports");
	static const TCHAR* const g_lpszPreDeployTestServiceURL = _T("PreDeployTestService");

	//SMS Web Console Section
	static const TCHAR* const g_lpszSMSURL = _T("SMSURL");
	static const TCHAR* const g_lpszSMSSec = _T("SMS");

	//For SMS Edition
	static const TCHAR* const g_lpszSMSCheck = _T("DistVer");

	//ASES Section
	static const TCHAR* const g_lpszAsesSec = _T("AdminStudio Enterprise Server");
	static const TCHAR* const g_lpszAsesURL = _T("URL");
	static const TCHAR* const USE_AUTOMATIC_AUTHENTICATION = _T("Enable Automatic Authentication");
	static const TCHAR* const ASES_KEY  = _T("ASES");
	static const TCHAR* const ASES_MRU_ROOTKEY = _T("ASES\\MRUList");
	static const TCHAR* const g_lpszAskForAESInstall = _T("AskForAESInstall");

    //Job Manager specific keys.
	static const TCHAR* const JOB_CATALOGS_MRU_ROOTKEY = _T("JobEngine\\MRUList");
	static const TCHAR* const JOB_CATALOGS_ALERT_ROOTKEY = _T("JobEngine");
    static const TCHAR* const g_szJobManAlertServer = _T("AlertServer");
    static const TCHAR* const g_szJobManAlertAddress = _T("AlertAddress");
    static const TCHAR* const g_szJobManAlertPort = _T("AlertPort");
    static const TCHAR* const g_lpszJobDirectorRun = _T("JobManagerEngine");
    static const TCHAR* const g_lpszJobDirectorReminder = _T("JobManagerEngineReminder");

    //Enterprise Eval Serial
    static const TCHAR* const g_lpszEntEvalSerial = _T("45A48D1-D44-4BC1567D71");
    static const TCHAR* const ISHIDEGUIIFEVALTIMEREMAINING = _T("ISHIDEGUIIFEVALTIMEREMAINING");
	static const TCHAR* const g_lpszEntEvalWebDate = _T("Eewd");
	static const TCHAR* const g_lpszAESWebSite = _T("Website");
	static const TCHAR* const g_lpszWFMSerial = _T("WFMProductID");

	//CEIP Settings
	static const TCHAR* const MEMBER_CEIP = _T("MemberCEIP");
	static const TCHAR* const REMIND_CEIP = _T("RemindCEIP");
    static const TCHAR* const FIRSTRUN_CEIP = _T("1stRunCEIP");

	static const TCHAR* const AES_INSTALLED_VALUE = _T("Installed");

	static const TCHAR* const CATALOG_ERROR_SWITCH = _T("Catalog Errors");
}

#endif // _REGLOCATIONS_H_
