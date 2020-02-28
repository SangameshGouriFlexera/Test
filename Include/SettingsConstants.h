#ifndef IS_SETTINGS_CONSTANTS_H
#define IS_SETTINGS_CONSTANTS_H

//Update Service project setting constants
static const stringx UPDATE_SERVICE_VERSION_ITEMS = L"DevStudio/IDE/Workspaces/UpdateService/ISUS_Version";
static const stringx UPDATE_SERVICE_VERSION_NAME = L"Name";
static const stringx UPDATE_SERVICE_VERSION_VALUE = L"Value";
static const stringx UPDATE_SERVICE_VERSION_HIDDEN = L"Hidden";
static const stringx UPDATE_SERVICE_GRID_ITEMS = L"DevStudio/IDE/Workspaces/UpdateService/ISUS_GridAttribute";
static const stringx UPDATE_SERVICE_GRID_ITEM_NAME = L"Name";
static const stringx UPDATE_SERVICE_GRID_ITEM_HELPLINK = L"HelpLink";
static const stringx UPDATE_SERVICE_GRID_ITEM_PROPERTY = L"Property";
static const stringx UPDATE_SERVICE_GRID_ITEM_DEFAULT = L"Default";
static const stringx UPDATE_SERVICE_GRID_COMBO_ITEM_VALUE = "Value";
static const stringx UPDATE_SERVICE_GRID_ITEM_IGNORE = "Ignore";
static const stringx UPDATE_SERVICE_GRID_ITEM_MSIONLY = "MsiOnly";
static const stringx UPDATE_SERVICE_GRID_ITEM_HIDDEN = "Hidden";
static const stringx UPDATE_SERVICE_GRID_VALUE_IGNORE = "Y";
static const stringx UPDATE_SERVICE_GRID_VALUE_YES = "Y";

//Exclusion List
static const stringx MM_ExclusionFiles   =	L"DevStudio/IDE/Workspaces/MM_FilesExlusion/FilesExlusion";
static const stringx MM_Guid             =	L"MM_GUID";
static const stringx ExclusionFile_Name  = L"InclusionFileNames";

//Custom Action View constants
static const stringx CUSTOM_ACTION_ELEMENT = L"DevStudio/IDE/Workspaces/CustomAction/*";
static const stringx CUSTOM_ACTION_ACTIONS = L"IS_Action";
static const stringx CUSTOM_ACTION_ACTION_NAME = L"Name";
static const stringx CUSTOM_ACTION_ACTION_HIDDEN = L"Hidden";
static const stringx CUSTOM_ACTION_ACTION_HIDDEN_YES = L"Y";
static const stringx CUSTOM_ACTION_ACTION_TYPE = L"Type";
static const stringx CUSTOM_ACTION_ACTION_DESCRIPTION = L"Description";
static const stringx CUSTOM_ACTION_DOTNETINSTALLER_TEMPLATE = L"DevStudio/IDE/Workspaces/CustomAction/IS_Action[@Name=\"{GUID}.%s\"]";

static const stringx UPDATE_SERVICE_CMDLINE_ITEMS = L"DevStudio/IDE/Workspaces/UpdateService/ISUS_CmdLine";
static const stringx UPDATE_SERVICE_CMDLINE_ITEM_NAME = UPDATE_SERVICE_GRID_ITEM_NAME;
static const stringx UPDATE_SERVICE_CMDLINE_ITEM_VALUE = UPDATE_SERVICE_GRID_COMBO_ITEM_VALUE;

// Msi Dialog View constants
static const stringx PROJECT_SETTINGS_MSI_DIALOGS = L"DevStudio/IDE/Workspaces/MsiDialog/Dialog";
static const stringx PROJECT_SETTINGS_MSI_DIALOGS_NAME = L"Name";
static const stringx PROJECT_SETTINGS_MSI_DIALOGS_LOCK = L"Lock";

// InstallScript Dialog View constants
static const stringx SCRIPT_DIALOG_DIALOGS = L"DevStudio/IDE/Workspaces/ScriptDialog/IS_ScriptDialog";
static const stringx SCRIPT_DIALOG_NAME = L"Name";
static const stringx SCRIPT_DIALOG_DISPLAYNAME = L"DisplayName";
static const stringx SCRIPT_DIALOG_SCRIPTMSIONLY = L"ScriptMSIOnly";
static const stringx SCRIPT_DIALOG_SCRIPTMSIONLY_YES = L"Y";
static const stringx SCRIPT_DIALOG_HIDDEN = L"Hidden";
static const stringx SCRIPT_DIALOG_HIDDEN_YES = L"Y";

static const stringx SCRIPT_DIALOG_TEXTSTYLES = L"DevStudio/IDE/Workspaces/ScriptDialog/IS_ScriptTextStyle";
static const stringx SCRIPT_DIALOG_LANG = L"Lang";
static const stringx SCRIPT_DIALOG_FACENAME = L"FaceName";
static const stringx SCRIPT_DIALOG_SIZE = L"Size";
static const stringx SCRIPT_DIALOG_STYLEBITS = L"StyleBits";
static const stringx SCRIPT_DIALOG_COLOR = L"Color";

// Scanners constants
static const stringx SCANNER_DOTNET_EXCLUSION_ITEMS = L"DevStudio/Scanners/DotNetExclusionList";
static const stringx SCANNER_DOTNET_EXCLUSION_ITEM_PATH = L"Path";

// New Project Dialog constants
static const stringx NEWPRJ_DIALOG_HIDE = L"DevStudio/IDE/NewProjectDlg/IS_HidePrjType";
static const stringx NEWPRJ_DIALOG_NAME = L"Name";
static const stringx NEWPRJ_DIALOG_TYPE = L"EPrjType";

// SQL scripts support constants
static const stringx SQL_SCRIPTS_METADATA = L"DevStudio/IDE/Workspaces/SQLScripts/IS_MetaData";
static const stringx SQL_SCRIPTS_METADATA_NAME = L"Name";
static const stringx SQL_SCRIPTS_METADATA_DISPLAYNAME = L"DisplayName";
static const stringx SQL_SCRIPTS_METADATA_DEFAULT = L"Default";
static const stringx SQL_SCRIPTS_METADATA_ADODRIVERNAME = L"AdoDriverName";
static const stringx SQL_SCRIPTS_METADATA_ADOCXNDRIVER = L"AdoCxnDriver";
static const stringx SQL_SCRIPTS_METADATA_ADOCXNSERVER = L"AdoCxnServer";
static const stringx SQL_SCRIPTS_METADATA_ADOCXNDB = L"AdoCxnDatabase";
static const stringx SQL_SCRIPTS_METADATA_ADOCXNUID = L"AdoCxnUserID";
static const stringx SQL_SCRIPTS_METADATA_ADOCXNPWD = L"AdoCxnPassword";
static const stringx SQL_SCRIPTS_METADATA_ADOCXNWINSECURITY = L"AdoCxnWindowsSecurity";
static const stringx SQL_SCRIPTS_METADATA_ADOCXNNETLIB = L"AdoCxnNetLibrary";
static const stringx SQL_SCRIPTS_METADATA_VERSIONBEGINTOKEN = L"VersionBeginToken";
static const stringx SQL_SCRIPTS_METADATA_VERSIONENDTOKEN = L"VersionEndToken";
static const stringx SQL_SCRIPTS_METADATA_VERSIONINFOCMD = L"VersionInfoCmd";
static const stringx SQL_SCRIPTS_METADATA_TESTDATABASECMD = L"TestDatabaseCmd";
static const stringx SQL_SCRIPTS_METADATA_TESTTABLECMD = L"TestTableCmd";
static const stringx SQL_SCRIPTS_METADATA_LOCALINSTANCENAMES = L"LocalInstanceNames";
static const stringx SQL_SCRIPTS_METADATA_CREATEDBCMD = L"CreateDbCmd";
static const stringx SQL_SCRIPTS_METADATA_SWITCHDBCMD = L"SwitchDbCmd";
static const stringx SQL_SCRIPTS_METADATA_ISATTRIBUTES = L"ISAttributes";
static const stringx SQL_SCRIPTS_METADATA_TESTTABLECMD2 = L"TestTableCmd2";
static const stringx SQL_SCRIPTS_METADATA_WINAUTHENTUSERID = L"WinAuthentUserId";
static const stringx SQL_SCRIPTS_METADATA_DSNODBCNAME = L"DsnODBCName";
static const stringx SQL_SCRIPTS_METADATA_ADOCXNPORT = L"AdoCxnPort";
static const stringx SQL_SCRIPTS_METADATA_ADOCXNADDITIONAL = L"AdoCxnAdditional";
static const stringx SQL_SCRIPTS_METADATA_QUERYDATABASESCMD = L"QueryDatabasesCmd";
static const stringx SQL_SCRIPTS_METADATA_CREATETABLECMD = L"CreateTableCmd";
static const stringx SQL_SCRIPTS_METADATA_INSERTRECORDCMD = L"InsertRecordCmd";
static const stringx SQL_SCRIPTS_METADATA_SELECTTABLECMD = L"SelectTableCmd";
static const stringx SQL_SCRIPTS_METADATA_SCRIPTVERSIONTABLECMD = L"ScriptVersion_Table";
static const stringx SQL_SCRIPTS_METADATA_SCRIPTVERSIONCOLUMNCMD = L"ScriptVersion_Column";
static const stringx SQL_SCRIPTS_METADATA_SCRIPTVERSIONCOLUMNTYPECMD = L"ScriptVersion_ColumnType";

static const stringx SQL_SCRIPTS_METADATA_PROP = L"DevStudio/IDE/Workspaces/SQLScripts/IS_MetaData[@Name=\"%s\"]/Properties/Property";
static const stringx SQL_SCRIPTS_METADATA_PROP_NAME = L"Name";
static const stringx SQL_SCRIPTS_METADATA_PROP_VALUE = L"Value";


static const stringx SQL_SCRIPTS_REQ = L"DevStudio/IDE/Workspaces/SQLScripts/IS_MetaData[@Name=\"%s\"]/ProductVersions/ProductVersion";
static const stringx SQL_SCRIPTS_REQ_NAME = L"Name";
static const stringx SQL_SCRIPTS_REQ_MAJORVERSION = L"MajorVersion";
static const stringx SQL_SCRIPTS_REQ_SERVICEPACKLEVEL = L"ServicePackLevel";
static const stringx SQL_SCRIPTS_REQ_VALUE = L"Value";
static const stringx SQL_SCRIPTS_REQ_DEFAULT = L"Default";

static const stringx SQL_SCRIPTS_DBIMPORT_COLUMNTYPE = L"DevStudio/IDE/Workspaces/SQLScripts/DBImport_ColumnType";
static const stringx SQL_SCRIPTS_DBIMPORT_COLUMNTYPE_NAME = L"Name";
static const stringx SQL_SCRIPTS_DBIMPORT_COLUMNTYPE_TYPE = L"Type";
static const stringx SQL_SCRIPTS_DBIMPORT_COLUMNTYPE_NULLABLE = L"Nullable";
static const stringx SQL_SCRIPTS_DBIMPORT_COLUMNTYPE_DEFAULT = L"DefaultValue";

static const stringx SQL_SCRIPTS_DBIMPORT_BCPPROP = L"DevStudio/IDE/Workspaces/SQLScripts/DBImport_BulkCopyProp";
static const stringx SQL_SCRIPTS_DBIMPORT_BCPPROP_ROWDEL = L"RowDelimiter";
static const stringx SQL_SCRIPTS_DBIMPORT_BCPPROP_COLUMNDEL = L"ColumnDelimiter";


//OBSOLETE: Digital Rights Management project setting constants
// static const stringx DRM_GRID_ITEMS = L"DevStudio/IDE/Workspaces/DigitalRightsManagement/DRM_GridAttribute";
// static const stringx DRM_GRID_ITEM_NAME = L"Name";
// static const stringx DRM_GRID_ITEM_HELPLINK = L"HelpLink";
// static const stringx DRM_GRID_ITEM_PROPERTY = L"Property";
// static const stringx DRM_GRID_ITEM_DEFAULT = L"Default";
// static const stringx DRM_GRID_COMBO_ITEM_VALUE = "Value";
// static const stringx DRM_GRID_ITEM_IGNORE = "Ignore";
// static const stringx DRM_GRID_ITEM_HIDDEN = "Hidden";
// static const stringx DRM_GRID_ITEM_YESNO ="YesNo";
// static const stringx DRM_GRID_ITEM_NUMERIC = "Numeric";
// static const stringx DRM_GRID_ITEM_MAXIMUM = "Maximum";
// static const stringx DRM_GRID_VALUE_YES = "Y";
// static const stringx DRM_GRID_PROP_PRODUCTNAME = "ProductName";
// static const stringx DRM_GRID_PROP_PRODUCTPURCHASEURL = "ProductPurchaseURL";
// static const stringx DRM_GRID_PROP_TRIALDAYS = "TrialDays";
// static const stringx DRM_GRID_PROP_SERIALNUMBERMASK = "SerialNumberMask";
// static const stringx DRM_GRID_PROP_ALLOWTRIALEXTENSION = "AllowTrialExtension";
// static const stringx DRM_GRID_VAL_ALLOWTRIALEXTENSION_YES = L"1";
// static const stringx DRM_GRID_VAL_ALLOWTRIALEXTENSION_NO = L"0";
// static const stringx DRM_GRID_PROP_TRIALEXTENSIONDAYS = "TrialExtensionDays";
// static const stringx DRM_GRID_PROP_TRIALEXTENSIONPASSWORD = "TrialExtensionPassword";
// static const stringx DRM_GRID_PROP_FEEDBACKURL = "FeedbackURL";
// static const stringx DRM_GRID_PROP_WHEREISMYSERIALNUMBERURL = "WhereIsMySerialNumberURL";
// static const stringx DRM_GRID_PROP_HELPURL = "HelpURL";
// static const stringx DRM_GRID_PROP_PRIVACYPOLICY = "PrivacyPolicy";
// static const stringx DRM_GRID_PROP_EMAILADDRESSTOACTIVATE = "EmailAddressToActivate";
// static const stringx DRM_GRID_PROP_PHONETOACTIVATE = "PhoneToActivate";
// static const stringx DRM_GRID_PROP_SNKEY = "SNKey";
// static const stringx DRM_GRID_PROP_SNVALUE = "SNValue";
// static const stringx DRM_GRID_PROP_GRACEPERIODTYPE = "GracePeriodType";
// static const stringx DRM_GRID_VAL_GRACEPERIODTYPE_DAYS = "Days";
// static const stringx DRM_GRID_VAL_GRACEPERIODTYPE_USES = "Uses";
// static const stringx DRM_GRID_PROP_DROPDEADDATE = "ExpirationDate";

//Build engine constants
static const stringx MSI_30_SETTINGS_ITEM = L"DevStudio/Build/Settings/MSI30";
static const stringx MSI_31_SETTINGS_ITEM = L"DevStudio/Build/Settings/MSI31";
static const stringx MSI_30_SETTINGS_VERSION = L"version";

//DotNet constants
static const stringx DOTNET_VERSION_10 = L"DevStudio/Build/DotNetRedistributables/NetFx[@key=\"0\"]";
static const stringx DOTNET_VERSION_11 = L"DevStudio/Build/DotNetRedistributables/NetFx[@key=\"1\"]";
static const stringx DOTNET_VERSION_20 = L"DevStudio/Build/DotNetRedistributables/NetFx[@key=\"2\"]";
static const stringx DOTNET_VERSION = L"Version";
static const stringx DOTNET_CORELANG = L"CoreLang";
static const stringx DOTNET_LANGPACK = L"LangPack";

//Clickonce constants
static const stringx CLICKONCE_PERMISSIONS = L"DevStudio/IDE/Workspaces/ClickOnce/Permissions/*";
static const stringx CLICKONCE_PERMISSIONS_ZONE = L"Zones";
static const stringx CLICKONCE_PERMISSIONS_SOURCE = L"Source";
static const stringx CLICKONCE_PERMISSIONS_METADATA = L"MetaData";

// DIM constants - Predefined vars
static const stringx DIM_PREDIFINED_TARGET_DIRS = L"DevStudio/DIM/PredefinedTargetFolders/PredefinedTargetFolder";
static const stringx DIM_PREDIFINED_TARGET_DIR_NAME = L"VarName";
static const stringx DIM_PREDIFINED_TARGET_DIR_VALUE = L"VarValue";

// DIM constants - Languages
static const stringx DIM_LANGUAGES = L"DevStudio/DIM/Languages/Language";
static const stringx DIM_LANGUAGES_NAME = L"Name";
static const stringx DIM_LANGUAGES_LANGID = L"MsiLangId";
static const stringx DIM_LANGUAGES_SUBLANGUAGE_COUNTRY = L"Country";
static const stringx DIM_LANGUAGES_SUBLANGUAGE_VARIANT = L"Variant";
static const stringx DIM_LANGUAGES_LANGID_COUNTRY = L"Id";
static const stringx DIM_LANGUAGES_LANGID_VARIANT = L"Id";


// String Import/Export
static const stringx STRING_IMPORT = L"DevStudio/IDE/StringImportExport/StringImport";
static const stringx STRING_IMPORT_ESC_AS_LITERAL = L"EscCharsAsLiteral";

// XML view settings
static const stringx XML_ENCODING = L"DevStudio/ISXML/Encodings/Encoding";
static const stringx XML_DEFAULT_ENCODING_ATTRIB_NAME = L"Default";

// Build
const stringx SETTINGS_EMPTY_TABLE_DISPOSITION = L"DevStudio/Build/EmptyTableDisposition";
const stringx SETTINGS_EMPTY_TABLE_DISPOSITION_TABLES = L"DevStudio/Build/EmptyTableDisposition/*";
const stringx SETTINGS_EMPTY_TABLE_DISPOSITION_KEEP = L"Keep";
const stringx SETTINGS_EMPTY_TABLE_DISPOSITION_DROP = L"Drop";
const stringx SETTINGS_EMPTY_TABLE_DISPOSITION_REFER = L"Ref:";

const stringx SETTINGS_BUILD_WARNINGS = L"DevStudio/Build/Warnings";
const stringx SETTINGS_BUILD_WARNINGS_DISABLE = L"Disable";
const WCHAR SETTINGS_BUILD_WARNINGS_SEP = L',';

const stringx SETTINGS_DIRECTORY_REFERENCE = L"DevStudio/Build/DirectoryReferences/Reference";
const stringx SETTINGS_DIRECTORY_REFERENCE_TABLE = L"Table";
const stringx SETTINGS_DIRECTORY_REFERENCE_DIRECTORY = L"Column";

const stringx PROJECT_SETTINGS_SIGNING = L"DevStudio/Build/DigitalSignature";
const stringx PROJECT_SETTINGS_SIGNING_RFC3161 = L"DevStudio/Build/DigitalSignature[@TimestampRFC3161]";
const stringx PROJECT_SETTINGS_SIGNING_TIMESTAMP = L"Timestamp";
const stringx PROJECT_SETTINGS_SIGNING_TIMESTAMP_RFC3161 = L"TimestampRFC3161";

//Mobile
static const stringx SETTINGS_MOBILE_DEVICES = L"DevStudio/ISMobile/MobileDevices/MobileDevice";
static const stringx SETTINGS_MOBILE_ATTRIB_DISPLAYNAME = L"DisplayName";
static const stringx SETTINGS_MOBILE_ATTRIB_MASK = L"Mask";
static const stringx PLATFORM_VERSION = L"DevStudio/ISMobile/MobileDevices/MobileDevice[@Mask=\"%d\"]";
static const stringx XPATH_UNSUPPORTED_PLATFORMS = L"DevStudio/ISMobile/MobileDevices/MobileDevice[@Mask=\"%d\"]/UnsupportedPlatforms/Platform";
static const stringx PLATFORM_MIN = L"PlatformMin";
static const stringx PLATFORM_MAX = L"PlatformMax";
static const stringx ATTRIBUTE_DEVICE_NAME = L"DeviceName";
static const stringx ATTRIBUTE_PLATFORM_NAME = L"PlatformName";
static const stringx ATTRIBUTE_PLATFORM_STRING = L"PlatformString";
static const stringx ATTRIBUTE_BUILDMAXSCREENSUPPORT = L"BuildMaxScreenSupport";

static const stringx SETTINGS_MOBILE_REDISTS = L"DevStudio/ISMobile/MobileRedists/MobileRedist";
static const stringx SETTINGS_MOBILE_SHORTCABFILEEXTS = L"DevStudio/ISMobile/MobileRedists/MobileRedist[@Name=\"%s\"]/ShortCabFileNames/ShortCabFileExt";
static const stringx SETTINGS_MOBILE_REDISTPATHS = L"DevStudio/ISMobile/MobileRedistPaths/MobileRedistPath";
static const stringx SETTINGS_MOBILE_ATTRIB_NAME = L"Name";
static const stringx SETTINGS_MOBILE_ATTRIB_INIFILE = L"IniFile";
static const stringx SETTINGS_MOBILE_ATTRIB_INISECTION = L"IniSection";
static const stringx SETTINGS_MOBILE_ATTRIB_INIVALUE = L"IniValue";
static const stringx SETTINGS_MOBILE_ATTRIB_CABSUBFOLDER = L"CabFileSubFolder";
static const stringx SETTINGS_MOBILE_ATTRIB_SOURCEFOLDER = L"SourceFolder";
static const stringx SETTINGS_MOBILE_ATTRIB_PRODUCTCODE = L"ProductCode";
static const stringx SETTINGS_MOBILE_ATTRIB_FINDWHAT = L"FindWhat";
static const stringx SETTINGS_MOBILE_ATTRIB_REPLACEWITH = L"ReplaceWith";
static const stringx SETTINGS_MOBILE_ATTRIB_PATHVAR= L"PathVar";
static const stringx SETTINGS_MOBILE_ATTRIB_REGKEY= L"RegKey";
static const stringx SETTINGS_MOBILE_ATTRIB_REGNAME= L"RegName";

// VSI Converter support constants
static const stringx VSI_CONVERTER_PREREQS = L"DevStudio/VSIConverter/Prereqs/Prereq";
static const stringx VSI_CONVERTER_ISPREREQS = L"DevStudio/VSIConverter/Prereqs/Prereq[@Name=\"%s\"]/ISPrereqs/ISPrereq";
static const stringx VSI_CONVERTER_PREREQS_NAME = L"Name";

#endif //IS_SETTINGS_CONSTANTS_H
