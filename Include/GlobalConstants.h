#ifndef GlobalConstants_H //Remove in .cs
#define GlobalConstants_H //Remove in .cs
//Option Explicit

#ifndef _VBOBJECTERROR_ //Remove in .cs
#define _VBOBJECTERROR_ //Remove in .cs
const long vbObjectError = -2147221504L;
#endif //Remove in .cs

#define MSI_VERSION_12 _T("1.20.1827.0")
#define MSI_VERSION_11 _T("1.10.1029.0")
#define MSI_VERSION_20 _T("2.0.2600.0")
#define MSI_VERSION_30 _T("3.0.3790.2149")

#define ISWI_WEBUPDATE_DAYS _T("30")
#define ISWI_PROP_ENABLE_UPDATE_SERVICE_FINISH_DIALOG _T("ISENABLEDWUSFINISHDIALOG")

//Update Service MM
#define ISUS_MM_ID _T("fnc1201_lite.9FC896E6_8DD6_4BFD_A02C_189B1B87F512")
#define ISUS_MM_LANG _T("0")

#define ISPROJECT_ISD_VERSION _T("735")
#define ISPROJECT_VERSION _T("777")
#define ISPROJECT_VERSION_RIPLEY _T("776")
#define ISPROJECT_VERSION_QI _T("775")
#define ISPROJECT_VERSION_PUNK _T("774")
#define ISPROJECT_VERSION_OPUS	_T("773")
#define ISPROJECT_VERSION_NEO _T("772")
#define ISPROJECT_VERSION_MAJESTY _T("771")
#define ISPROJECT_VERSION_LOYALTY_SP _T("770")
#define ISPROJECT_VERSION_LOYALTY _T("769")
#define ISPROJECT_VERSION_IRONWOOD _T("766")
#define ISPROJECT_VERSION_INDORE _T("765")
#define ISPROJECT_VERSION_IXTAPA _T("763")
#define ISPROJECT_VERSION_PLUTO _T("759")
#define ISPROJECT_VERSION_PROTEUS_SP _T("758")
#define ISPROJECT_VERSION_PROTEUS _T("757")
#define ISPROJECT_VERSION_NEPTUNE_PDC _T("756")
#define ISPROJECT_VERSION_NEPTUNE _T("755")
#define ISPROJECT_VERSION_JUPITER_MP _T("748")
#define ISPROJECT_VERSION_JUPITER _T("747")
#define ISPROJECT_VERSION_MARS_MP _T("744")
#define ISPROJECT_VERSION_PHOBOS_MP _T("744")
#define ISPROJECT_VERSION_THOR _T("734")
#define ISPROJECT_VERSION_PHOBOS _T("738")
#define ISPROJECT_VERSION_DEIMOS _T("739")
#define ISPROJECT_VERSION_MARS _T("742")
#define ISPROJECT_MINUPGRADE_VERSION _T("490")

// template project file names
#define ISMSI_PROJECT_SCHEMA  _T("IsProjSchema.ism")
#define ISMSI_PROJECT_TEMPLATE  _T("IsProjTpl.ism")
#define ISMSI_PROJECT_MSIDB  _T("Database.msi")
#define ISMSI_PROJECT_MSMDB  _T("Database.msm")
#define ISMSI_PROJECT_BLANKTEMPLATE  _T("IsProjBlankTpl.ism")
#define ISMSI_PROJECT_BLANKMERGEMODULE  _T("IsProjBlankMMTpl.ism")
#define ISMSI_PROJECT_CONVTEMPLATE  _T("IsProjConvTpl.ism")
#define ISMSI_PROJECT_CONVMSMTEMPLATE  _T("IsProjConvMMTpl.ism")
#define ISMSI_PROJECT_SCRIPT  _T("IsProjScriptTpl.ism")
#define ISMSI_PROJECT_SCRIPT_PROJ_WIZ  _T("IsProjWizScriptTpl.ism")
#define ISMSI_PROJECT_MM_UPGRADE  _T("IsProjUpgradeMMTpl.ism")
#define ISMSI_PROJECT_SCRIPT_UPGRADE  _T("IsProjUpgradeScriptTpl.ism")
#define ISMSI_PROJECT_SCRIPT_PRO_TEMPLATE  _T("ISProfessionalTpl.ism")
#define ISMSI_PROJECT_SCRIPT_PROOBJECT_TEMPLATE  _T("ISProfessionalObjTpl.ism")
#define ISMSI_PROJECT_SCRIPT_PRO_MIGRATE_TEMPLATE  _T("ISProMigrateTpl.ism")
#define ISMSI_PROJECT_SCRIPT_PROOBJECT_MIGRATE_TEMPLATE  _T("ISProMigrateObjTpl.ism")
#define ISMSI_PROJECT_CLICKONCE_TEMPLATE  _T("IsClickOnceTpl.ism")
#define ISMSI_PROJECT_THINAPP  _T("IsProjThinAppTpl.ism")
#define ISMSI_PROJECT_APPV  _T("IsProjAppVTpl.ism")
#define ISMSI_PROJECT_DIM_TEMPLATE	_T("ISProjDIMTpl.dim")
#define ISMSI_PROJECT_BOOTSTRAP_TEMPLATE	_T("ISProjSuiteTpl.issuite")
#define ISMSI_PROJECT_BOOTSTRAP_NTIERAPP_TEMPLATE	_T("ISProjSuiteNTierAppTpl.issuite")

#define ISMSI_BUILD_MM_TEMPLATE  _T("ISMsiMM.itp")
#define ISMSI_BUILD_MSI_TEMPLATE  _T("ISMsiPkg.itp")

#define ISMSI_PROJECT_EXPRESS_EXTENSION  _T("ise")
#define ISMSI_PROJECT_EXPRESS_EXTENSION_W  L"ise" //
#define ISMSI_PROJECT_EXPRESS_EXTENSION_DOT  _T(".ise")
#define ISMSI_PROJECT_EXPRESS_EXTENSION_SEARCH  _T("*.ise")
#define ISMSI_PROJECT_ISLE_EXTENSION_SEARCH  _T("*.isl")
#define ISMSI_PROJECT_ISLE_EXTENSION_DOT _T(".isl")
#define ISMSI_PROJECT_ISLE_EXTENSION _T("isl")
#define ISMSI_PROJECT_DIM_EXTENSION_SEARCH  _T("*.dim")
#define ISMSI_PROJECT_DIM_EXTENSION_DOT _T(".dim")
#define ISMSI_PROJECT_DIM_EXTENSION _T("dim")
#define ISMSI_PROJECT_SUITE_EXTENSION _T("issuite")
#define ISMSI_PROJECT_SUITE_EXTENSION_DOT _T(".issuite")

#define ISMSI_PROJECT_EXTENSION  _T("ism")
#define ISMSI_PROJECT_EXTENSION_W  L"ism" //
#define ISMSI_PROJECT_EXTENSION_DOT  _T(".ism")
#define ISMSI_PROJECT_EXTENSION_SEARCH  _T("*.ism")

#define ISMSI_PROJECT_EXPRESS_EXTENSION_2X  _T("iwz")
#define ISMSI_PROJECT_EXPRESS_EXTENSION_3X  _T("ism")
#define ISMSI_PROJECT_EXPRESS_EXTENSION_4X  _T("ise")
#define ISMSI_PROJECT_EXPRESS_EXTENSION_2X_DOT  _T(".iwz")
#define ISMSI_PROJECT_EXPRESS_EXTENSION_3X_DOT  _T(".ism")
#define ISMSI_PROJECT_EXPRESS_EXTENSION_4X_DOT  _T(".ise")
#define ISMSI_PROJECT_EXPRESS_EXTENSION_2X_SEARCH  _T("*.iwz")
#define ISMSI_PROJECT_EXPRESS_EXTENSION_3X_SEARCH  _T("*.ism")
#define ISMSI_PROJECT_EXPRESS_EXTENSION_4X_SEARCH  _T("*.ise")

#define ISMSI_PROJECT_DIRECTMSI_EXTENSION  _T("msi")
#define ISMSI_PROJECT_DIRECTMSI_EXTENSION_W  L"msi" //
#define ISMSI_PROJECT_DIRECTMSI_EXTENSION_DOT  _T(".msi")

#define ISMSI_PROJECT_DIRECTMSM_EXTENSION  _T("msm")
#define ISMSI_PROJECT_DIRECTMSM_EXTENSION_W  L"msm" //
#define ISMSI_PROJECT_DIRECTMSM_EXTENSION_DOT  _T(".msm")

#define ISMSI_PROJECT_TRANSFORM_EXTENSION  _T("mst")
#define ISMSI_PROJECT_TRANSFORM_EXTENSION_W  L"mst" //
#define ISMSI_PROJECT_TRANSFORM_EXTENSION_DOT  _T(".mst")

#define ISMSI_PROJECT_MSP_EXTENSION  _T("msp")
#define ISMSI_PROJECT_MSP_EXTENSION_W  L"msp" //
#define ISMSI_PROJECT_MSP_EXTENSION_DOT  _T(".msp")

#define ISMSI_WISE_PROJECT_EXTENSION  _T("wsi")
#define ISMSI_WISE_PROJECT_EXTENSION_W  L"wsi" //
#define ISMSI_WISE_PROJECT_EXTENSION_DOT  _T(".wsi")

#define ISMSI_PROJECT_VSIP_EXTENSION  _T("isproj")
#define ISMSI_PROJECT_VSIP_EXTENSION_W  L"isproj" //
#define ISMSI_PROJECT_VSIP_EXTENSION_DOT  _T(".isproj")

// File type descriptions
#define ISMSI_PCP_PATCHES  _T("Patch Creation Properties Files ")
#define ISMSI_INC_NETINSTALL  _T("Repackaged File ")
#define ISMSI_MSI_PACKAGES  _T("Windows Installer Packages ")
#define ISMSI_MSI_MODULES  _T("Windows Installer Modules ")
#define ISMSI_MSI_TRANSFORMS  _T("Windows Installer Transforms ")
#define ISMSI_IMM_INSTALLSCRIPT_OBJECTS  _T("InstallScript Objects ")
#define ISMSI_ISM_PROJECTS  _T("InstallScript Projects ")
#define ISMSI_MSP_PATCHES  _T("Windows Installer Patches ")
#define ISMSI_WISE_PROJECTS  _T("Wise for Windows Installer Projects")
#define ISMSI_FRAG_PROJECTS	_T("DIM Projects")
#define ISMSI_INSTALLSHIELD_PROJECTS _T("InstallShield Projects")

#define ISMSI_PROJECT_ISXTEMPLATE  _T("IsProjIsxConvTpl.ism")

#define ISMSI_PROJECT_EXPRESS_EXPRESS  _T("IsProjExpress.ise")
#define ISMSI_PROJECT_LITE_EXPRESS  _T("IsProjLite.ise")
#define ISMSI_PROJECT_ISLE_EXPRESS  _T("IsProjExpress.isl")

#define ISMSI_PROJECT_EXPRESS  _T("IsProjExpress.ism")
#define ISMSI_PROJECT_LITE  _T("IsProjLite.ism")

#define ISMSI_PROJECT_QUICKPATCH  _T("IsProjQuickPatch.ism")
#define ISMSI_PROJECT_QUICKPATCH_EXPRESS  _T("IsProjQuickPatch.ise")
#define ISMSI_PROJECT_REPACKTEMPLATE  _T("IsProjRepackTpl.ism")

#define ISMSI_PROJECT_UPGRADE_EXPRESS  _T("IsProjExpUpgradeTpl.ise")
#define ISMSI_PROJECT_UPGRADE  _T("IsProjUpgradeTpl.ism")

#define ISMSI_PROJECT_BLANKISOBJ  _T("IsProjISObjTpl.ism")
#define ISMSI_PROJECT_BLANKWEB  _T("IsProjWebTpl.ism")
#define ISMSI_PROJECT_TRANSFORM  _T("Transform.mst")

#define ISMSI_PROJECT_PRO  _T("ISProfessionalTpl.ism")
#define ISMSI_PROJECT_PRO_OBJ  _T("ISProfessionalObjTpl.ism")

// Standard error codes
#define ISMSI_ERR_BASE (vbObjectError + 512)
#define ISMSI_CANCELLED (ISMSI_ERR_BASE + 9999)

// Magic Null number
// Cannot end with # for compatibility with VBScript
#define ISMSI_NULL_NUMBER -2147483648L
#define ISMSI_NULL_STRING _T("###NULL###")

#define IS_APP_NAME _T("InstallShield")

#define ISMSI_FILE_ISFONT _T("***Default***")

//ProgIDs
#define IS_REGISTRY_OBJECT _T("InstallShield.Registry.1")
#define PROGID_FILEINFO _T("ISSystemObject.CFileInfo") // Low level file info

#define ISPROP_STD_NAME _T("0")

//================================================
//ActionText table fields
#define ISACTIONTEXT_LAYOUT _T("ACTIONTEXT_LAYOUT")
#define ISCLASST_ACTIONTEXT _T("ACTIONTEXT")
//Key = Action Name
#define ISFIELD_ACTIONTEXT_ACTION _T("Action")
#define ISFIELD_ACTIONTEXT_DESCRIPTION _T("Description")
#define ISFIELD_ACTIONTEXT_TEMPLATE _T("Template")

//================================================
//APPSEARCH class props
//Added 7/16/98 by Mark Pownell

#define ISFIELD_APPSEARCH_PROPERTY _T("Property")
#define ISFIELD_APPSEARCH_SIGNATUREKEY _T("Signature")

//================================================
// merge module authoring (ModuleSignature table in ism#)
#define ISPROP_AUTMERGEMODULE_DISPLAYNAME _T("ModuleID_ModuleID")
#define ISPROP_AUTMERGEMODULE_LANG _T("Language")
#define ISPROP_AUTMERGEMODULE_VERSION _T("Version")
#define ISPROP_AUTMERGEMODULE_MODULEIDGUID _T("ModuleID_ModuleIDGUID")

//================================================
//  MMCOMPONENTS -- New with ism#, ModuleComponents table
#define ISPROP_MMCOMPONENTS_COMPONENT _T("Component")
#define ISPROP_MMCOMPONENTS_MODULEID _T("ModuleID")
#define ISPROP_MMCOMPONENTS_LANGUAGE _T("Language")


//================================================
//BINARY class props
//Added 7/16/98 by Mark Pownell
#define ISFIELD_BINARY_NAME _T("Name")
#define ISFIELD_BINARY_FILE _T("Data")

//================================================
//CHECKBOX class props
//ISPROP_STD_NAME = Property
#define ISPROP_CHECKBOX_VALUE _T("Value")

//================================================
//COMBOBOX class props
//ISPROP_STD_NAME = Property
//Key = Order
#define ISPROP_COMBOBOX_VALUE _T("Value")
#define ISPROP_COMBOBOX_TEXT _T("Text")

//================================================
// Component properties
#define ISPROP_COMPONENT_NAME _T("0") // Same as ISPROP_STD_NAME
#define ISPROP_COMPONENT_GUID _T("ComponentId")
#define ISPROP_COMPONENT_KEYPATH _T("KeyPath_KeyPath")
#define ISPROP_COMPONENT_DESTINATION _T("Directory__Destination")
#define ISPROP_COMPONENT_RUNFROMSOURCE _T("Attributes_RunFromSource")
#define ISPROP_COMPONENT_CONDITION _T("Condition_DisplayCondition")
#define ISPROP_COMPONENT_TRANSITIVE _T("Attributes_Transitive")
#define ISPROP_COMPONENT_SELFREGISTER _T("ISAttributes_SelfRegister")
#define ISPROP_COMPONENT_CHECKVERSION _T("ISAttributes_CheckVersion")
#define ISPROP_COMPONENT_COMMENTS _T("ISComments")
#define ISPROP_COMPONENT_KEYPATHTYPE _T("Attributes_KeyPathType")
#define ISPROP_COMPONENT_NEVEROVERWRITE _T("Attributes_NeverOverwrite")
#define ISPROP_COMPONENT_PERMANENT _T("Attributes_Permanent")
#define ISPROP_COMPONENT_SHAREDDLLREFCOUNT _T("Attributes_SharedDLLRefCount")
#define ISPROP_COMPONENT_TYPE _T("Attributes_Type")
#define ISPROP_COMPONENT_SUPPLANG _T("Attributes_LangFilter")
#define ISPROP_COMPONENT_OSFILTER _T("Attributes_OSFilter")
#define ISPROP_COMPONENT_COMPRESSION_TYPE _T("CompressionType")
#define ISPROP_COMPONENT_SOURCELOCATION _T("Directory__SourceLocation")
#define ISPROP_COMPONENT_64BIT _T("Attributes_Attrib64Bit")
#define ISPROP_COMPONENT_REGISTRATION _T("ISAttributes_Registration")
#define ISPROP_COMPONENT_DISPLAYCONDITION _T("Condition_DisplayCondition")
#define ISPROP_COMPONENT_DNET_COMINTEROP _T("ISAttributes_DNetAssemblyCOMInteropAtBuild")
#define ISPROP_COMPONENT_DNET_JITCOMPILE _T("ISAttributes_JITCompileAtInstall")
#define ISPROP_COMPONENT_DNET_SCANATBUILD _T("ISAttributes_DNetAssemblyScanAtBuild")
#define ISPROP_COMPONENT_DNET_INSTALLCLASSATBUILD _T("ISAttributes_DNetAssemblyInstallerClassAtBuild")
#define ISPROP_COMPONENT_DNET_SCANATBUILDFILE _T("ISScanAtBuildFile")
#define ISPROP_COMPONENT_REGFILETOMERGEATBUILD _T("ISRegFileToMergeAtBuild")
#define ISPROP_COMPONENT_DNET_INSTALLERARGS_INSTALL _T("ISDotNetInstallerArgsInstall")
#define ISPROP_COMPONENT_DNET_INSTALLERARGS_COMMIT _T("ISDotNetInstallerArgsCommit")
#define ISPROP_COMPONENT_DNET_INSTALLERARGS_UNINSTALL _T("ISDotNetInstallerArgsUninstall")
#define ISPROP_COMPONENT_DNET_INSTALLERARGS_ROLLBACK _T("ISDotNetInstallerArgsRollback")
#define ISPROP_COMPONENT_COMPRESSED _T("ISAttributes_Compressed")
#define ISPROP_COMPONENT_POTENTIALLYLOCKED _T("ISAttributes_PotentiallyLocked")
#define ISPROP_COMPONENT_MISCELLANEOUS _T("Component_Miscellaneous")
#define ISPROP_COMPONENT_FTPLOCATION _T("Component_FTPLocation")
#define ISPROP_COMPONENT_HTTPLOCATION _T("Component_HTTPLocation")
#define ISPROP_COMPONENT_DOTNETASSEMBLY _T("ISAttributes_DotNetAssembly")
#define ISPROP_COMPONENT_OVERWRITEMAINOPTIONS _T("ISAttributes_OverwriteMainOptions")
#define ISPROP_COMPONENT_OVERWRITESUBOPTIONSVERSION _T("ISAttributes_OverwriteSubOptionsVersion")
#define ISPROP_COMPONENT_OVERWRITESUBOPTIONSDATE _T("ISAttributes_OverwriteSubOptionsDate")
#define ISPROP_COMPONENT_DIFFERENCE _T("ISAttributes_Difference")
#define ISPROP_COMPONENT_PLATFORMSUITECHECK _T("ISAttributes_PlatformSuiteCheck")
#define ISPROP_COMPONENT_PLATFORMSUITES _T("Component_PlatformSuites")
#define ISPROP_COMPONENT_STATICFILES _T("ISAttributes_StaticFiles")
#define ISPROP_COMPONENT_DISPLAYREGISTRYREFLECTION _T("Attributes_DisableRegistryReflection")
#define ISPROP_COMPONENT_DISPLAYCOMPSHARE _T("Attributes_ComponentAttributesShared")
#define ISPROP_COMPONENT_DISPLAYCOMPSUPERSEDE _T("Attributes_ComponentAttributesUninstallOnSupersedence")

//================================================
//CONDITION class props
//Added 7/16/98 by Mark Pownell

#define ISPROP_CONDITION_FEATUREKEY _T("10")
#define ISPROP_CONDITION_LEVEL _T("Level")
#define ISPROP_CONDITION_CONDITION _T("Condition")

//================================================
//DIALOG class props
#define ISDIALOG_LAYOUT _T("DIALOG_LAYOUT")
#define ISDIALOG_GROUP _T("DIALOG_GROUP")
#define ISCLASSN_DIALOG _T("DIALOG")
#define ISPROP_DIALOG_NAME _T("Name")
#define ISPROP_DIALOG_HCENTERING _T("HCentering")
#define ISPROP_DIALOG_VCENTERING _T("VCentering")
#define ISPROP_DIALOG_WIDTH _T("Width")
#define ISPROP_DIALOG_HEIGHT _T("Height")
#define ISPROP_DIALOG_ATTRIBUTES _T("Attributes_Attributes")
#define ISPROP_DIALOG_TITLE _T("Title")
#define ISPROP_DIALOG_CONTROL_FIRST _T("ControlFirst")
#define ISPROP_DIALOG_CONTROL_DEFAULT _T("ControlDefault")
#define ISPROP_DIALOG_CONTROL_CANCEL _T("ControlCancel")
#define ISPROP_DIALOG_SEQUENCE _T("Sequence")
#define ISPROP_DIALOG_TYPE _T("Type")
#define ISPROP_DIALOG_COMMENT _T("Comment")

// Global Dialog Settings Props

#define ISPROP_GLOBAL_IMAGE _T("1")
#define ISPROP_GLOBAL_BANNER _T("2")
#define ISPROP_GLOBAL_THEME _T("3")
#define ISPROP_GLOBAL_ALLUSERS _T("4")

//================================================

#define ISPROP_COMCLASS_GUID _T("CLSID")
#define ISPROP_COMCLASS_PROGID _T("ProgId_Default_ProgId")
#define ISPROP_COMCLASS_APPID _T("AppId__AppId")
#define ISPROP_COMCLASS_DISPLAYNAME _T("Description_Description") //was ISPROP_COMCLASS_DESCRIPTION
#define ISPROP_COMCLASS_FILETYPEMASK _T("FileTypeMask_FileTypeMask")
#define ISPROP_COMCLASS_STRICON _T("Icon__Icon")
#define ISPROP_COMCLASS_ICONINDEX _T("IconIndex_IconIndex")
#define ISPROP_COMCLASS_DESC _T("Description_Description") //was ISPROP_COMCLASS_FEATURE
#define ISPROP_COMCLASS_ATTRIBUTES _T("IconIndex_RelativePath")
#define ISPROP_COMCLASS_FEATURE _T("Feature_")

//================================================

#define ISPROP_COMCLASS_CONTEXT _T("Context")
#define ISPROP_COMCLASS_CONTEXT_DEFPROCHANDLER _T("DefInprocHandler")
#define ISPROP_COMCLASS_CONTEXT_ARGUMENT _T("Argument")

//================================================
//COMPLOCATOR class props
//Added 7/16/98 by Mark Pownell

#define ISFIELD_COMPLOCATOR_COMPONENTID _T("ComponentId")
#define ISFIELD_COMPLOCATOR_TYPE _T("Type")
#define ISFIELD_COMPLOCATOR_SIGNATUREKEY _T("Signature")

//================================================
//CONTROL class props
//Added 7/16/98 by Mark Pownell
#define ISPROP_CONTROL_TYPE _T("Type")
#define ISPROP_CONTROL_X _T("X_XPos")
#define ISPROP_CONTROL_Y _T("Y_YPos")
#define ISPROP_CONTROL_WIDTH _T("Width_Width")
#define ISPROP_CONTROL_HEIGHT _T("Height")
#define ISPROP_CONTROL_ATTRIBUTES _T("Attributes_Attribute")
#define ISPROP_CONTROL_PROPERTY _T("Property")
#define ISPROP_CONTROL_TEXT _T("Text")
#define ISPROP_CONTROL_CONTROL_NEXT _T("ControlNext")
#define ISPROP_CONTROL_HELP _T("Help")
#define ISPROP_CONTROL_STYLE _T("Style")
#define ISPROP_CONTROL_STYLE_BASE _T("StyleBase")

//================================================
//CONTROL CONDITION class props
#define ISFIELD_CONTROL_CONDITION_ACTION _T("Action")
#define ISFIELD_CONTROL_CONDITION_CONDITION _T("Conditon")

//================================================
//CONTROL EVENT class props
#define ISPROP_CONTROL_EVENT_ARGUMENT _T("Argument")
#define ISPROP_CONTROL_EVENT_CONDITION _T("Condition")
#define ISPROP_CONTROL_EVENT_ORDERING _T("Ordering")

//================================================
// Custom Action class props
#define ISPROP_CUSTOM_ACTION_TYPE _T("Type")
#define ISPROP_CUSTOM_ACTION_SOURCE _T("Source_Source")
#define ISPROP_CUSTOM_ACTION_TARGET _T("Target")
#define ISPROP_CUSTOM_ACTION_COMMENT _T("Comment")
#define ISPROP_CUSTOM_ACTION_ISCOMMENTS _T("ISComments")
#define ISPROP_CUSTOM_ACTION_PS64BIT _T("Type_PS64Bit")

//================================================
// New Props for ICustomAction2
#define ISPROP_CUSTOM_ACTION_SOURCETYPE _T("Type_SourceType")
#define ISPROP_CUSTOM_ACTION_RETURNPROCESSINGNOWAIT _T("Type_ReturnProcessingNoWait")
#define ISPROP_CUSTOM_ACTION_RETURNPROCESSINGRETURN _T("Type_ReturnProcessingIgnoreReturn")
#define ISPROP_CUSTOM_ACTION_SOURCELOCATION _T("Type_SourceLocation")
#define ISPROP_CUSTOM_ACTION_INSCRIPTEXECUTION _T("Type_InScriptExecution")
#define ISPROP_CUSTOM_ACTION_EXECUTIONSCHEDULING _T("Type_ExecutionScheduling")
#define ISPROP_CUSTOM_ACTION_RETURNPROCESSING _T("Type_ReturnProcessing")
#define ISPROP_CUSTOM_ACTION_TARGET_TARGET _T("Target_Target")
#define ISPROP_CUSTOM_ACTION_TYPE_TYPE _T("Type_Type")
#define ISPROP_CUSTOM_ACTION_ISCAREFFILEPATH _T("ExtendedType_ISCAReferenceFilePath")
#define ISPROP_CUSTOM_ACTION_PATCHUNINSTALL _T("ExtendedType_PatchUninstall")
#define ISPROP_CUSTOM_ACTION_64BIT _T("Type_Is64Bit")
#define ISPROP_CUSTOM_ACTION_DLLSILENT _T("Type_IsSilent")

//================================================
//DIRECTORY class props
//Added 7/16/98 by Mark Pownell

#define ISFIELD_DIRECTORY_NAME _T("0")
#define ISFIELD_DIRECTORY_DIRECTORY _T("Directory_Directory")
#define ISFIELD_DIRECTORY_PARENT _T("Directory_Parent_Parent")
#define ISFIELD_DIRECTORY_DEFAULTDIR _T("DefaultDir_DefaultDir")
#define ISFIELD_DIRECTORY_PREDEFINED _T("ISAttributes")

//================================================
//DRLOCATOR class props
//Added 7/16/98 by Mark Pownell

#define ISFIELD_DRLOCATOR_PARENT _T("Parent")
#define ISFIELD_DRLOCATOR_PATH _T("Path")
#define ISFIELD_DRLOCATOR_DEPTH _T("Depth")
#define ISFIELD_DRLOCATOR_SIGNATUREKEY _T("Signature")


//================================================
//ENVIRONMENT class props
//Added 7/16/98 by Mark Pownell

#define ISPROP_ENVIRONMENT_DISPLAYNAME _T("Name")
#define ISPROP_ENVIRONMENT_NAME _T("Name")
#define ISPROP_ENVIRONMENT_VALUE _T("Value")
#define ISPROP_ENVIRONMENT_COMPONENTKEY _T("Component")
#define ISPROP_ENVIRONMENT_TRUENODENAME _T("Environment")

#define ISPROXYPROP_ENV_COMPONENT _T("Component_")
#define ISPROXYPROP_ENV_NAME _T("Name_Name")
#define ISPROXYPROP_ENV_VALUE _T("Value_Value")
#define ISPROXYPROP_ENV_ONINSTALL _T("Name_OnInstall")
#define ISPROXYPROP_ENV_PLACEMENT _T("Value_Placement")
#define ISPROXYPROP_ENV_ONUNINSTALL _T("Name_OnUninstall")
#define ISPROXYPROP_ENV_TYPE _T("Name_EnvType")

#define ISPROXYPROP_ENV_LAST _T("6")

#define ISPROXYPROP_ENV_ONINSTALL_SET  _T("0")
#define ISPROXYPROP_ENV_ONINSTALL_CREATE  _T("1")
#define ISPROXYPROP_ENV_ONINSTALL_REMOVE  _T("2")

#define ISPROXYPROP_ENV_PLACEMENT_REPLACE  _T("0")
#define ISPROXYPROP_ENV_PLACEMENT_PREFIX  _T("1")
#define ISPROXYPROP_ENV_PLACEMENT_APPEND  _T("2")

#define ISPROXYPROP_ENV_ONUNINSTALL_REMOVE  _T("0")
#define ISPROXYPROP_ENV_ONUNINSTALL_LEAVE  _T("1")

#define ISPROXYPROP_ENV_TYPE_SYSTEM  _T("0")
#define ISPROXYPROP_ENV_TYPE_USER  _T("1")

//================================================
//Environment table prefixes

#define PREFIX_ENVIRONMENT_TYPE_SYSTEM _T("*")
#define PREFIX_ENVIRONMENT_ONINSTALL_SET _T("=")
#define PREFIX_ENVIRONMENT_ONINSTALL_CREATE _T("+")
#define PREFIX_ENVIRONMENT_ONINSTALL_REMOVE _T("!")
#define PREFIX_ENVIRONMENT_ONUNINSTALL_REMOVE _T("-")

#define MSI_NULL_SEQUENCE _T("[~]")

//================================================
//ERROR class props
//Key = Error Number
#define ISFIELD_ERROR_MESSAGE _T("Message")

//================================================
//   Extension
#define ISPROP_EXTENSION_EXT _T("Extension") // Same as ISPROP_STD_NAME
#define ISPROP_EXTENSION_PROGID _T("ProgId_")
#define ISPROP_EXTENSION_FEATURE _T("Feature_")

// New field identifiers
#define ISPROP_EXTENSION_COMPONENT _T("Component_")
#define ISPROP_EXTENSION_MIME _T("MIME_")

//================================================
// Verb
#define ISPROP_EXTENSION_VERB_NAME _T("Verb") // Same as ISPROP_STD_NAME
#define ISPROP_EXTENSION_VERB_SEQ _T("Sequence")
#define ISPROP_EXTENSION_VERB_COMMAND _T("Command")
#define ISPROP_EXTENSION_VERB_ARGUMENT _T("Argument")

// New field identifiers
#define ISPROP_EXTENSION_VERB_EXTENSION _T("Extension_")

//================================================
//Event Mapping class props
//ISPROP_STD_NAME = Event
#define ISFIELD_CONTROL_EVENTMAPPING_ATTRIBUTE _T("Attribute")

//================================================
// Feature properties
#define ISPROP_FEATURE_NAME _T("0") // Same as ISPROP_STD_NAME
#define ISPROP_FEATURE_CLASS _T("1") // Same as ISPROP_STD_CLASS
#define ISPROP_FEATURE_DISPLAYNAME _T("Title")
#define ISPROP_FEATURE_DESCRIPTION _T("Description")
#define ISPROP_FEATURE_CONFIGURABLE _T("ISAttributes_Configurable")
#define ISPROP_FEATURE_DIRLOCATION _T("Directory__Destination")
#define ISPROP_FEATURE_DISPLAY _T("Display")
#define ISPROP_FEATURE_ATTRIBUTE _T("Attributes_Attribute")
#define ISPROP_FEATURE_INSTALLLEVEL _T("Level")
#define ISPROP_FEATURE_EXPANDBYDEFAULT _T("17") //NOT USED (Cleanup)
#define ISPROP_FEATURE_ADVERTISE _T("Attributes_AdvertiseEx")
#define ISPROP_FEATURE_DISALLOWADVERTISE _T("19") //NOT USED (Cleanup)
#define ISPROP_FEATURE_UIDISALLOWABSENT _T("Attributes_Required")
#define ISPROP_FEATURE_COMMENTS _T("ISComments")
#define ISPROP_FEATURE_SEQUENCE _T("Display_Sequence")
#define ISPROP_FEATURE_RELEASEFLAGS _T("ISReleaseFlags")
#define ISPROP_FEATURE_VISIBLE _T("Display_Visible")
#define ISPROP_FEATURE_STATUSTEXT _T("Feature_StatusText")
#define ISPROP_FEATURE_NEED _T("Attributes_Need")
#define ISPROP_FEATURE_INCLUDEINBUILD _T("Attributes_IncludeInBuild")
#define ISPROP_FEATURE_PASSWORD _T("Feature_Password")
#define ISPROP_FEATURE_ENCRYPTION _T("Attributes_Encryption")
#define ISPROP_FEATURE_CDROMFOLDER _T("Feature_CDRomFolder")
#define ISPROP_FEATURE_GUID _T("Feature_GUID")
#define ISPROP_FEATURE_STRINGLIST _T("Feature_StringList")
#define ISPROP_FEATURE_FEATUREPATH _T("Feature_FeaturePath")

#define ISFIELD_FILELINKING_SOURCEFOLDER _T("SourceFolder")
#define ISFIELD_FILELINKING_INCLUDEFILES _T("IncludeFiles")
#define ISFIELD_FILELINKING_EXCLUDEFILES _T("ExcludeFiles")
#define ISFIELD_FILELINKING_INCLUDEFLAGS _T("IncludeFlags")

//================================================
//ICON class props
//Added 7/16/98 by Mark Pownell

#define ISPROP_ICON_DISPLAYNAME _T("Name")
#define ISPROP_ICON_FILE _T("Data")

//================================================
//Obsolete ICON class props
#define ISFIELD_ICON_DISPLAYNAME _T("Name")
#define ISFIELD_ICON_FILE _T("Data")

//================================================
//ISIISProperty properties
#define ISPROP_ISIISPROPERTY_METADATAVALUE	_T("MetaDataValue_MetaDataValue")

//================================================
//ISVRoot Class props
#define ISCLASS_ISVROOT _T("ISVRoot")

//================================================
//ISWebSite properties
#define ISPROP_ISWEBSITE_ROOTDIR _T("RootDir_RootDir")
#define ISPROP_ISWEBSITE_PORT _T("ISIISCommon_Port")
#define ISPROP_ISWEBSITE_IP _T("ISIISCommon_IP")
#define ISPROP_ISWEBSITE_SITENUMBER _T("ISIISCommon_SiteNumber")
#define ISPROP_ISWEBSITE_DELETEONUNINSTALL _T("ISIISCommon_DeleteOnUninstall")

//================================================
//ISVRoot properties
#define ISPROP_ISVROOT_ROOTDIR _T("RootDir_VRootDir")
#define ISPROP_ISVROOT_VROOTKEY _T("ISIISCommon_VRootKey")
#define ISPROP_ISVROOT_VROOTAPPNAME _T("AppName")
#define ISPROP_ISVROOT_EXECPERMISSION _T("Attributes_ExecPermission")
#define ISPROP_ISVROOT_APPPROTECTION _T("Attributes_AppProtection")
#define ISPROP_ISVROOT_COMPONENT _T("ISIISCommon_Component")
#define ISPROP_ISVROOT_WEBSITE _T("ISIISCommon_WebSite")
#define ISPROP_ISVROOT_SSLCERT _T("ISIISCommon_SSLCert")

//================================================
//ISIISMetaData Class props
#define ISCLASS_ISIISMETADATA _T("ISIISMetaData")

//================================================
//ISIISCommon Class props
#define ISCLASS_ISIISCOMMON _T("ISIISCommon")

//================================================
//ISIISCommon properties
#define ISPROP_ISIISCOMMON_READACCESS _T("Attributes_ReadAccess")
#define ISPROP_ISIISCOMMON_WRITEACCESS _T("Attributes_WriteAccess")
#define ISPROP_ISIISCOMMON_SCRIPTSRCACCESS _T("Attributes_ScriptSrcAccess")
#define ISPROP_ISIISCOMMON_DIRBROWSE _T("Attributes_DirBrowse")
#define ISPROP_ISIISCOMMON_INDEXING _T("Attributes_Indexing")
#define ISPROP_ISIISCOMMON_LOGVISIT _T("Attributes_LogVisit")
#define ISPROP_ISIISCOMMON_ANONYAUTHMODE _T("Attributes_AnonyAuthMode")
#define ISPROP_ISIISCOMMON_BASICAUTHMODE _T("Attributes_BasicAuthMode")
#define ISPROP_ISIISCOMMON_NTINTEGRATEDAUTHMODE _T("Attributes_NTIntegratedAuthMode")
#define ISPROP_ISIISCOMMON_ANONYSYNCPASS _T("Attributes_AnonySyncPass")
#define ISPROP_ISIISCOMMON_DISPLAYNAME _T("DisplayName")
#define ISPROP_ISIISCOMMON_DEFDOC _T("DefDoc")
#define ISPROP_ISIISCOMMON_SESSIONTIMEOUT _T("SessionTimeout")
#define ISPROP_ISIISCOMMON_SCRIPTTIMEOUT _T("ScriptTimeout")
#define ISPROP_ISIISCOMMON_ANONYUSERNAME _T("AnonyUserName")
#define ISPROP_ISIISCOMMON_ANONYPASSWRD _T("AnonyPasswrd")
#define ISPROP_ISIISCOMMON_CUSTOMERRORS _T("CustomErrors")
#define ISPROP_ISIISCOMMON_SSLPASSWORD _T("SslPassword")
#define ISPROP_ISIISCOMMON_HOSTHEADERNAME _T("HostHeaderName")

//================================================
//ISVRootAppMaps Class props
#define ISCLASS_ISVROOTAPPMAPS _T("ISVRootAppMaps")

//================================================
//ISWebSite Class props
#define ISCLASS_ISWEBSITE _T("ISWebSite")

//================================================
// IniFile properties
#define ISPROP_INIFILE_FILENAME _T("FileName")
#define ISPROP_INIFILE_DIRECTORY _T("DirProperty_Directory")
#define ISPROP_INIFILE_COMPONENT _T("Component_")
#define ISPROP_INIFILE_SECTION _T("Section_Name")
#define ISPROP_INIFILE_KEY _T("Key")
#define ISPROP_INIFILE_VALUE _T("Value")
#define ISPROP_INIFILE_ACTION _T("Action")

//================================================
//ISDRMFile Class props
#define ISCLASS_ISDRMFILE _T("ISDRMFile")

//================================================
//INILOCATOR class props
//Added 7/16/98 by Mark Pownell

#define ISFIELD_INILOCATOR_FILENAME _T("FileName")
#define ISFIELD_INILOCATOR_SECTION _T("Section")
#define ISFIELD_INILOCATOR_KEY _T("Key")
#define ISFIELD_INILOCATOR_FIELD _T("Field")
#define ISFIELD_INILOCATOR_TYPE _T("Type")
#define ISFIELD_INILOCATOR_SIGNATUREKEY _T("Signature")

//================================================
//ISSCRIPT_BILLBOARD

#define ISFIELD_ISSCRIPT_BILLBOARD_DISPLAYNAME _T("DisplayName")
#define ISFIELD_ISSCRIPT_BILLBOARD_BINARYKEY _T("Filename")
#define ISFIELD_ISSCRIPT_BILLBOARD_DURATION _T("Duration")
#define ISFIELD_ISSCRIPT_BILLBOARD_ORIGIN _T("Origin")
#define ISFIELD_ISSCRIPT_BILLBOARD_X _T("X")
#define ISFIELD_ISSCRIPT_BILLBOARD_Y _T("Y")
#define ISFIELD_ISSCRIPT_BILLBOARD_EFFECT _T("Effect")
#define ISFIELD_ISSCRIPT_BILLBOARD_SEQUENCE _T("Sequence")
#define ISFIELD_ISSCRIPT_BILLBOARD_TARGET _T("Target")
#define ISFIELD_ISSCRIPT_BILLBOARD_COLOR _T("Color")
#define ISFIELD_ISSCRIPT_BILLBOARD_STYLE _T("Style")
#define ISFIELD_ISSCRIPT_BILLBOARD_FONT _T("Font")
#define ISFIELD_ISSCRIPT_BILLBOARD_TITLE _T("Title")

//================================================
//LAUNCH_CONDITION class props
//Added 7/16/98 by Mark Pownell

#define ISPROP_LAUNCHCONDITION_CONDITION _T("Condition")
#define ISPROP_LAUNCHCONDITION_DESC _T("Description")

//================================================
// LINKER_OPTIONS class props
#define ISFIELD_LOPTIONS_FILENAME _T("Name")
#define ISFIELD_LOPTIONS_LIBRARIES _T("Library")

//ISPROP_STD_NAME = Property
//Key = Order
#define ISFIELD_LISTBOX_VALUE _T("Value")
#define ISFIELD_LISTBOX_TEXT _T("Text")

//================================================
//LISTVIEW class props
//ISPROP_STD_NAME = Property
//key = Order
#define ISFIELD_LISTVIEW_VALUE _T("Value")
#define ISFIELD_LISTVIEW_TEXT _T("Text")
#define ISFIELD_LISTVIEW_ICON _T("Binary")

//================================================
// Media table fields
//ISRelease table in ism#
#define ISPROP_MEDIA_NAME _T("ISRelease") // Same as ISPROP_STD_NAME
#define ISPROP_MEDIA_SIGNEXE _T("Attributes_SignExe")
#define ISPROP_MEDIA_BUILDLOC _T("BuildLocation")
#define ISPROP_MEDIA_PACKAGENAME _T("PackageName_PackageName")
#define ISPROP_MEDIA_TYPE _T("Type") //Network, CDROM, Custom, DVD, etc
#define ISPROP_MEDIA_CREATEREPORT _T("Attributes_CreateReport")
#define ISPROP_MEDIA_CREATELOGFILE _T("Attributes_CreateLogFile")
#define ISPROP_MEDIA_SUPPLANGUI _T("SupportedLanguagesUI") // Languages supported for UI
#define ISPROP_MEDIA_RELEASETYPE _T("ReleaseType_ReleaseType") //SINGLEPACK, UNCOMPRESS, COMBINATION
#define ISPROP_MEDIA_PLATFORMS _T("Platforms") //Intel, Alpha, Platform Independent
#define ISPROP_MEDIA_SUPPLANGDATA _T("SupportedLanguagesData") //What language files to add for component filtering
#define ISPROP_MEDIA_DEFAULTLANG _T("DefaultLanguage") //Default UI Language
#define ISPROP_MEDIA_ENABLELANGDLG _T("Attributes_EnableLanguageDialog")
#define ISPROP_MEDIA_BOOTSTRAP _T("Attributes_CreateSetupExe") // Include setup.exe
#define ISPROP_MEDIA_COPYMM _T("Attributes_CopyMM") // Copy MergeModule '## Need new prop for thor
#define ISPROP_MEDIA_OS _T("SupportedOSs") // 9x or NT
#define ISPROP_MEDIA_DISKSIZE _T("DiskSize")
#define ISPROP_MEDIA_DISKSIZE_UNIT _T("DiskSizeUnit")
#define ISPROP_MEDIA_DISK_CLUSTER_SIZE _T("DiskClusterSize")
#define ISPROP_MEDIA_RELEASEFLAGS _T("ReleaseFlags")
#define ISPROP_MEDIA_DISKSPANNING _T("DiskSpanning")
#define ISPROP_MEDIA_USETESTPATHVARS _T("Attributes_UseTestPathVariables")
#define ISPROP_MEDIA_KEEP_UNSUSED_DIRECTORIES _T("Attributes_KeepUnusedDirectories")
#define ISPROP_MEDIA_MINIMUM_INIT_DELAY _T("Attributes_MinimumInitTime")
#define ISPROP_MEDIA_MSISOURCETYPE _T("MsiSourceType_MsiSourceType") // MSI Source Type( To be used in summary stream)
#define ISPROP_MEDIA_CREATE_AUTORUN _T("Attributes_CreateAutorun") //
#define ISPROP_MEDIA_CREATE_PDF _T("Attributes_CreatePDF")
#define ISPROP_MEDIA_SYNCHMSI _T("SynchMsi")
#define ISPROP_MEDIA_MEDIA_LOCATION _T("MediaLocation")
#define ISPROP_MEDIA_URL_LOCATION _T("URLLocation")
#define ISPROP_MEDIA_DIGITAL_URL _T("DigitalURL")
#define ISPROP_MEDIA_DIGITAL_PVK _T("DigitalPVK")
#define ISPROP_MEDIA_DIGITAL_SPC _T("DigitalSPC")
#define ISPROP_MEDIA_PSWD _T("Password")
#define ISPROP_MEDIA_PSWD_PROTECT _T("Attributes_PasswordProtect")
#define ISPROP_MEDIA_USE_MY_VERINFO _T("Attributes_UseMyVersionInfo")
#define ISPROP_MEDIA_VER_COPYRIGHT _T("VersionCopyright")
#define ISPROP_MEDIA_SUPPRESSWIN2K _T("Attributes_SuppressWin2K")
#define ISPROP_MEDIA_LANG_FILTERING _T("Attributes_LanguageFiltering")
#define ISPROP_MEDIA_SIGN_MEDIA _T("Attributes_SignMedia")

//New field in ism#
#define ISPROP_MEDIA_CREATESETUPEXE _T("Attributes_CreateSetupExe")
#define ISPROP_MEDIA_PRODUCTCONFIGURATION _T("ISProductConfiguration_")
#define ISPROP_MEDIA_WRAP_MSI_INTO_CAB _T("Attributes_WrapMsiIntoCab")
#define ISPROP_MEDIA_GENERATE_ONE_CLICK _T("Attributes_GenerateOneClick")
#define ISPROP_MEDIA_CACHE_WEB_PKG_LOCALLY _T("Attributes_CacheWebPkgLocally")
#define ISPROP_MEDIA_DELAY_ENGINE_REBOOT _T("Attributes_DelayEngineReboot")
#define ISPROP_MEDIA_WEB_TYPE _T("MsiSourceType_WebType")
#define ISPROP_MEDIA_WEB_URL _T("PackageName_WebURL")
#define ISPROP_MEDIA_WEB_CAB_SIZE _T("MsiSourceType_WebCabSize")
#define ISPROP_MEDIA_ONELCICK_HTML_NAME _T("PackageName_OneClickHtmlName")
#define ISPROP_MEDIA_ONECLICK_CAB_NAME _T("PackageName_OneClickCabName")
#define ISPROP_MEDIA_WEB_LOCAL_CACHE_PATH _T("PackageName_WebLocalCachePath")
#define ISPROP_MEDIA_ENGINE_LOCATION _T("MsiSourceType_EngineLocation")
#define ISPROP_MEDIA_WIN9X_MSI_URL _T("PackageName_Win9xMsiUrl")
#define ISPROP_MEDIA_WINNT_MSI_URL _T("PackageName_WinNTMsiUrl")
#define ISPROP_MEDIA_WIN_MSI_30_URL _T("PackageName_WinMsi30Url")
#define ISPROP_MEDIA_ISENGINE_URL _T("PackageName_ISEngineURL")
#define ISPROP_MEDIA_ISENGINE_LOCATION _T("MsiSourceType_ISEngineLocation")
#define ISPROP_MEDIA_OPTIMIZESIZE _T("Attributes_OptimizeSize")
#define ISPROP_MEDIA_DIGITAL_CERT_ID_NETSCAPE _T("PackageName_DigitalCertificateIdNS")
#define ISPROP_MEDIA_DIGITAL_CERT_DBASE_NETSCAPE _T("PackageName_DigitalCertificateDBaseNS")
#define ISPROP_MEDIA_DIGITAL_CERT_PASSWORD_NETSCAPE _T("PackageName_DigitalCertificatePasswordNS")
#define ISPROP_MEDIA_ONECLICK_TARGET_BROWSWER _T("MsiSourceType_OneClickTargetBrowser")
#define ISPROP_MEDIA_CDBROWSER_PATH _T("CDBrowser")
#define ISPROP_MEDIA_DOTNETBUILDCONFIGURATION _T("DotNetBuildConfiguration")
#define ISPROP_MEDIA_DOTNET_URL _T("PackageName_DotNetRedistURL")
#define ISPROP_MEDIA_DOTNET_LOCATION _T("MsiSourceType_DotNetRedistLocation")
#define ISPROP_MEDIA_DOTNETUI _T("Attributes_DotNetUI")
#define ISPROP_MEDIA_DOTNET_VERSION _T("MsiSourceType_DotNetVersion")
#define ISPROP_MEDIA_DOTNET_BASELANG _T("PackageName_DotNetBaseLanguage")
#define ISPROP_MEDIA_DOTNET_LANGPACK _T("PackageName_DotNetLangaugePacks")
#define ISPROP_MEDIA_DOTNETFX_CMDLINE _T("PackageName_DotNetFxCmdLine")
#define ISPROP_MEDIA_DOTNET_LANGPACK_CMDLINE _T("PackageName_DotNetLangPackCmdLine")

#define ISPROP_MEDIA_JSHARP_LOCATION _T("MsiSourceType_JSharpRedistLocation")
#define ISPROP_MEDIA_JSHARP_CMDLINE _T("PackageName_JSharpCmdLine")
#define ISPROP_MEDIA_JSHARPOPTION _T("Attributes_JSharpOptionDlg")
#define ISPROP_MEDIA_JSHARPOPTIONSILENT _T("Attributes_JSharpOptionalIfSilent")

#define ISPROP_MEDIA_BUILD_MSIFILEHASH_TABLE _T("Attributes_GenerateFileHashValues")
#define ISPROP_MEDIA_MSIENGINE_VERSION _T("Attributes_MsiEngineVersion")
#define ISPROP_MEDIA_MSICOMMANDLINE _T("MsiCommandLine")
#define ISPROP_MEDIA_SUPPRESSARP _T("Attributes_SuppressARP")
#define ISPROP_MEDIA_LOGRUNTIMERESULTS _T("Attributes_LogRuntimeResults")
#define ISPROP_MEDIA_SHOWDNET_SETUPEXE_SELECTION _T("Attributes_ShowDotNetSetupExeSelection")
#define ISPROP_MEDIA_SHOWDNET_USER_INTERFACE _T("Attributes_DotNetUI")
#define ISPROP_MEDIA_DNET_DELAY_REBOOT _T("Attributes_DotNetDelayReboot")
#define ISPROP_MEDIA_SKINS _T("PackageName_Skin")
#define ISPROP_MEDIA_SMALL_INIT_DLG _T("Attributes_SmallInit")
#define ISPROP_MEDIA_SHALLOW_FOLDER _T("Attributes_ShallowFolder")
#define ISPROP_MEDIA_PREREQ_LOCATION _T("ISSetupPrerequisiteLocation")
#define ISPROP_MEDIA_CERTPASSWORD _T("ISRelease_CertPassword")
#define ISPROP_MEDIA_DRM _T("Attributes_IsDRMDisabled")
#define ISPROP_MEDIA_AS_PUBLISH_TO_REPO _T("PublishToSoftwareRepository")
#define ISPROP_MEDIA_AS_PUBLISH_GROUP _T("AdminStudioGroup")
#define ISPROP_MEDIA_AS_PUBLISH_UPDATE_OPTION _T("UpdateOption")
#define ISPROP_MEDIA_VALIDATE_DIM _T("Attributes_ValidateDIMs")
#define ISPROP_MEDIA_EXE_PRIVILEGES _T("Attributes_LauncherPrivileges")
#define ISPROP_MEDIA_ELEVATED_ADVERTISE _T("Attributes_ElevatedAdvertise")

#define ISPROP_SETUP_UNICODE_OPTION _T("Attributes_SetupLauncherType")

//ReleasePro constants
#define ISPROP_MEDIA_BUILDTYPE _T("Attributes_BuildType")
#define ISPROP_RELEASEPRO_MEDIATYPE _T("Type")
#define ISPROP_RELEASEPRO_GUID _T("ISRelease_GUID")
#define ISPROP_RELEASEPRO_SINGLEEXEFILENAME _T("ISRelease_SingleEXEFileName")
#define ISPROP_RELEASEPRO_SINGLEEXEICONNAME _T("ISRelease_SingleEXEIconName")
#define ISPROP_RELEASEPRO_PASSWORD _T("Password")
#define ISPROP_RELEASEPRO_SHOWPASSWORDDLG _T("Attributes_ShowPasswordDlg")
#define ISPROP_RELEASEPRO_SETUPCMDLINE _T("MsiCommandLine")
#define ISPROP_RELEASEPRO_PREPROCESSORDEFINES _T("ISRelease_PreProcessorDefines")
#define ISPROP_RELEASEPRO_COMPRESSSCRIPT _T("Attributes_CompressScript")
#define ISPROP_RELEASEPRO_OSFILTER _T("MsiSourceType_OSFilter")
#define ISPROP_RELEASEPRO_SUPPORTEDLANGUAGESUI _T("SupportedLanguagesUI")
#define ISPROP_RELEASEPRO_DEFAULTLANGUAGE _T("DefaultLanguage")
#define ISPROP_RELEASEPRO_ENABLELANGUAGESDIALOG _T("Attributes_EnableLanguageDialog")
#define ISPROP_RELEASEPRO_USEINCLUDEINBUILDFLAGS _T("Attributes_UseIncludeInBuildFlags")
#define ISPROP_RELEASEPRO_USEPROJECTSKIN _T("ISRelease_UseProjectSkin")
#define ISPROP_RELEASEPRO_SKINNAME _T("ISRelease_SkinName")
#define ISPROP_RELEASEPRO_SMALLINIT _T("Attributes_SmallInit")
#define ISPROP_RELEASEPRO_CDBROWSER _T("CDBrowser")
#define ISPROP_RELEASEPRO_WEBCREATEDEFAULTPAGE _T("Attributes_WebCreateDefaultPage")
#define ISPROP_RELEASEPRO_WEBSECURITYDLG _T("Attributes_WebSecurityDlg")
#define ISPROP_RELEASEPRO_WEBSAVEOPTIONSDLG _T("Attributes_WebSaveOptionsDlg")
#define ISPROP_RELEASEPRO_WEBSAVEOPTIONSRUNONLY _T("Attributes_WebSaveOptionsRunOnly")
#define ISPROP_RELEASEPRO_WEBSAVEOPTIONSSAVEANDRUN _T("Attributes_WebSaveOptionsSaveAndRun")
#define ISPROP_RELEASEPRO_WEBSAVEOPTIONSSAVEONLY _T("Attributes_WebSaveOptionsSaveOnly")
#define ISPROP_RELEASEPRO_WEBSAVEOPTIONSCREATESHORTCUT _T("Attributes_WebSaveOptionsCreateShortcut")
#define ISPROP_RELEASEPRO_WEBNETSCAPESUPPORT _T("Attributes_WebNetscapeSupport")
#define ISPROP_RELEASEPRO_WEBPAGEURL _T("ISRelease_WebPageUrl")
#define ISPROP_RELEASEPRO_SIGNMEDIA _T("Attributes_SignMedia")
#define ISPROP_RELEASEPRO_OBJDIFFOPTIONS _T("Attributes_ObjDiffOptions")
#define ISPROP_RELEASEPRO_SUPPORTEDVERSIONS _T("ISRelease_SupportedVersions")
#define ISPROP_RELEASEPRO_DISTRIBUTETOURLLOC _T("URLLocation")
#define ISPROP_RELEASEPRO_FTPFOLDER _T("ISRelease_FTPFolder")
#define ISPROP_RELEASEPRO_FTPUSERNAME _T("ISRelease_FTPUserName")
#define ISPROP_RELEASEPRO_FTPPASSWORD _T("ISRelease_FTPPassword")
#define ISPROP_RELEASEPRO_COPYTOFOLDER _T("ISRelease_CopyToFolder")
#define ISPROP_RELEASEPRO_BATCHFILENAME _T("ISRelease_BatchFileName")
#define ISPROP_RELEASEPRO_SETUPDLGAPPNAME _T("ISRelease_SetupDlgAppName")
#define ISPROP_RELEASEPRO_ENABLEDIFFERENCE _T("Attributes_EnableDifference")
#define ISPROP_RELEASEPRO_CHECKMD5 _T("Attributes_CheckMD5")
#define ISPROP_RELEASEPRO_DISPLAYBUILDLOCATION _T("ISRelease_DisplayBuildLocation")
#define ISPROP_RELEASEPRO_INITDLGPRODUCTNAME _T("ISRelease_InitDlgProductName")
#define ISPROP_RELEASEPRO_DISTRIBUTEAFTERBUILD _T("Attributes_DistributeAfterBuild")
#define ISPROP_RELEASEPRO_CERTPASSWORD _T("ISRelease_CertPassword")
#define ISPROP_RELEASE_VMSETTINGS_CONFIGNAME _T("ISRelease_VMConfiguration")
#define ISPROP_RELEASE_VMSETTINGS_MACHINENAME _T("ISRelease_VMMachineName")
#define ISPROP_RELEASE_VMSETTINGS_MACHINEUSERNAME _T("ISRelease_VMMachineUserName")
#define ISPROP_RELEASE_VMSETTINGS_MACHINEPASSWORD _T("ISRelease_VMMachinePassword")
#define ISPROP_RELEASE_VMSETTINGS_STAGE_AFTERBUILD _T("ISRelease_VMStagePostBuild")
#define ISPROP_RELEASE_VMSETTINGS_MACHINE_COPYPATH _T("ISRelease_VMDestinationPath")
#define ISPROP_RELEASE_VMSETTINGS_SNAPSHOT _T("ISRelease_VMSnapShot")

//OtherDiskFile constants
#define ISPROP_OTHERDISKFILE_NAME _T("ISDisk1File_Name")

//PreviousProMedia constants
#define ISPROP_PREVIOUSPROMEDIA_MEDIAFILE _T("MediaFile")
#define ISPROP_PREVIOUSPROMEDIA_VERSION _T("Version_Version")
#define ISPROP_PREVIOUSPROMEDIA_USEHEADERVERSION _T("Version_UseHeaderVersion")

//ReservedSpaces constants
#define ISPROP_RESERVEDSPACES_DISK _T("Disk")
#define ISPROP_RESERVEDSPACES_SIZE _T("KBsReserved")

//Release constants
#define RELEASE_WEB_INSTALL_HTM _T("install")
#define RELEASE_WEB_CAB_FILE_NAME _T("install")
#define RELEASE_HTTP_BLANK _T("http://")

//================================================
#define ISMSI_MEDIA_MB (0)
#define ISMSI_MEDIA_GB (1)

#define ISMSI_MEDIATYPE_CDROM (0)
#define ISMSI_MEDIATYPE_NETWORK (1)
#define ISMSI_MEDIATYPE_CUSTOM (2)
#define ISMSI_MEDIATYPE_DVD (3)

#define ISMSI_DISKSPAN_AUTOMATIC (0)
#define ISMSI_DISKSPAN_ENFORCESIZE (1)
#define ISMSI_DISKSPAN_NOENFORCE (2)

//Release Format Sizes
#define DVD5_SIZE _T("4.38") // 4.7 / 2^30
#define DVD9_SIZE _T("7.95") // 8.5
#define DVD10_SIZE _T("8.75") // 9.4
#define DVD18_SIZE _T("15.83") //17.0
#define CD_SIZE _T("650")
#define CD_CLUSTERSIZE _T("2048")
#define DVD_CLUSTERSIZE _T("2048")
#define RELEASE_CUSTOM_SIZE _T("100")
#define RELEASE_CUSTOM_CLUSTERSIZE (1024)
#define DISKETTE144_SIZE _T("1.44")

// special release name EXPRESS
#define RELEASE_SINGLEIMAGE _T("SingleImage")
#define RELEASE_WEBDEPLOYMENT _T("WebDeployment")
#define RELEASE_CUSTOM _T("Custom")
#define RELEASE_CDROM _T("CD_ROM")
#define RELEASE_DVD18 _T("DVD-18")
#define RELEASE_DVD10 _T("DVD-10")
#define RELEASE_DVD9 _T("DVD-9")
#define RELEASE_DVD5 _T("DVD-5")
#define PRODUCT_CONFIG_EXP _T("Express")

#define DISKNUMBER_TOKEN _T("?")

//================================================
// MERGEMODULE
#define ISPROP_MERGEMODULE_DESTINATION _T("Destination")

//new with ism#
#define ISPROP_MERGEMODULE_GUID _T("ISMergeModule")
#define ISPROP_MERGEMODULE_NAME _T("Name")

//================================================
// ISFEATUREMERGEMODULES - new with ism#
#define ISPROP_ISFEATUREMERGEMODULES_FEATURE _T("Feature_")
#define ISPROP_ISFEATUREMERGEMODULES_MODULE _T("ISMergeModule_")

//================================================
// MIME
#define ISPROP_MIME_CONTENTTYPE _T("ContentType") // Same as ISPROP_STD_NAME
#define ISPROP_MIME_EXTENSION _T("Extension_")
#define ISPROP_MIME_CLSID _T("CLSID")

//================================================
//   MMDEPENDENCY
#define ISPROP_MMDEPENDENCY_DISPLAYNAME _T("RequiredID_DisplayName")
#define ISPROP_MMDEPENDENCY_LANG _T("RequiredLanguage")
#define ISPROP_MMDEPENDENCY_VERSION _T("RequiredVersion")

//New with ism#
#define ISPROP_MMDEPENDENCY_MODULEID _T("ModuleID") //module requiring the the dependency
#define ISPROP_MMDEPENDENCY_MODULELANGUAGE _T("ModuleLanguage") //Language of module requiring the the dependency

//================================================
//  MMEXCLUSION
#define ISPROP_MMEXCLUSION_DISPLAYNAME _T("ExcludedID_DisplayName")
#define ISPROP_MMEXCLUSION_LANG _T("ExcludedLanguage")
#define ISPROP_MMEXCLUSION_MINVERSION _T("ExcludedMinVersion")
#define ISPROP_MMEXCLUSION_MAXVERSION _T("ExcludedMaxVersion")

//New with ism#
#define ISPROP_MMEXCLUSION_MODULEID _T("ModuleID") //module requiring the the exclusion
#define ISPROP_MMEXCLUSION_MODULELANGUAGE _T("ModuleLanguage") //Language of module requiring the the exclusion

//================================================
//ODBC_DATASOURCE class props
//Added 7/16/98 by Mark Pownell

#define ISPROP_ODBC_DATASOURCE_DESCRIPTION _T("Description")
#define ISPROP_ODBC_DATASOURCE_REGISTRATION _T("Registration")
#define ISPROP_ODBC_DATASOURCE_DRIVERDESCRIPTION _T("DriverDescription")

//================================================
//ODBC_SOURCEATTRIBUTE class props
//Added 7/16/98 by Mark Pownell

#define ISPROP_ODBC_SRCATTR_ATTRIBUTE _T("Attribute")
#define ISPROP_ODBC_SRCATTR_VALUE _T("Value")

//================================================
//ODBC_DRIVER class props
//Added 7/16/98 by Mark Pownell

#define ISPROP_ODBC_DRIVER_DESCRIPTION _T("Description")
#define ISPROP_ODBC_DRIVER_FILESETUP _T("File_Setup")
#define ISPROP_ODBC_DRIVER_FILEKEY _T("File_")

//================================================
//ODBC_ATTRIBUTE class props
//Added 7/16/98 by Mark Pownell

#define ISPROP_ODBC_ATTR_ATTRIBUTE _T("Attribute")
#define ISPROP_ODBC_ATTR_VALUE _T("Value")

//================================================
//ODBC_TRANSLATOR class props
//Added 7/16/98 by Mark Pownell

#define ISPROP_ODBC_TRANSLATOR_DESCRIPTION _T("Description")
#define ISPROP_ODBC_TRANSLATOR_FILESETUP _T("File_Setup")
#define ISPROP_ODBC_TRANSLATOR_FILEKEY _T("File_")

//================================================
//PATHVARIABLESET class props
#define ISPROP_PATHVARIABLESET_NAME _T("ISPathVariable") // Same as ISPROP_STD_NAME

//IMPORTANT: ISPROP_PATHVARIABLESET_NAME id's the key field in the
//           ISPathVariables table in new store, and other fields
//           in this table are accessed using ISFIELD_PATHVARIABLES_...
//           constants found below, under "PATHVARIABLES class props".

//================================================
//PATHVARIABLES class props
//See "PATHVARIABLESET class props" above for key field id.
// Key = Name of the path variable
#define ISFIELD_PATHVARIABLES_VALUE _T("Value")
#define ISFIELD_PATHVARIABLES_TESTVALUE _T("TestValue")
#define ISFIELD_PATHVARIABLES_TYPE _T("Type")


//================================================
// Product properties
//#define ISPROP_PRODUCT_NAME _T("0") // Same as ISPROP_STD_NAME
#define ISPROP_PRODUCT_SUBJECT _T("10")
#define ISPROP_PRODUCT_DEFDESTINATION _T("11")
//#define ISPROP_PRODUCT_VERSION _T("12")
//#define ISPROP_PRODUCT_HELPPHONE _T("13")
//#define ISPROP_PRODUCT_HELPURL _T("14")
//#define ISPROP_PRODUCT_TYPE _T("15")
//#define ISPROP_PRODUCT_DEVTOOL _T("16")
//#define ISPROP_PRODUCT_DISPLAYTREE _T("17") // The display tree layout to be used
//#define ISPROP_PRODUCT_CURRENT_MEDIA _T("18") // Current Media
#define ISPROP_PRODUCT_SISAUTHOR _T("19") // Used for SIS Author
#define ISPROP_PRODUCT_PACKAGECODE _T("20")
//#define ISPROP_PRODUCT_ABOUTURL _T("21") // Product 'About' URL (MSI Regentry)
//#define ISPROP_PRODUCT_UPDATEURL _T("22") // Update URL for a product
//#define ISPROP_PRODUCT_SHGCOUNT _T("23") // Global Shortcut Counter (Hidden)
//#define ISPROP_PRODUCT_REGCOUNT _T("24") // Global Registry Counter (Hidden)
#define ISPROP_PRODUCT_TEMPLATESUMMARY _T("25") //Template summary property
#define ISPROP_PRODUCT_DATABASEDIR _T("26")
#define ISPROP_PRODUCT_PAGECOUNT _T("27")
#define ISPROP_PRODUCT_APPTYPE _T("28")


//================================================
// ProgID
#define ISPROP_PROGID_ID _T("ProgId")
#define ISPROP_PROGID_PARENT _T("ProgId_Parent")
#define ISPROP_PROGID_CLASSID _T("Description")
#define ISPROP_PROGID_DESCRIPTION _T("Class_")
#define ISPROP_PROGID_STRICON _T("IconIndex_IconIndex")
#define ISPROP_PROGID_ICONINDEX _T("Icon__Icon")
#define ISPROP_PROGID_EXTRACTICON _T("ISAttributes_ExtractIcon")
#define ISPROP_PROGID_INSERTABLE _T("ISAttributes_Insertable") // Not implemented in IsmAutoProgId.h

//================================================
// Project root properties
#define ISPROP_PROJECT_NAME _T("0") // Same as ISPROP_STD_NAME
#define ISPROP_PROJECT_COMPANYNAME _T("10")
#define ISPROP_PROJECT_OWNER _T("11") // author, owner of project
#define ISPROP_PROJECT_COMMENTS _T("12") // project comments
#define ISPROP_PROJECT_COMPANYURL _T("13") // Company URL
#define ISPROP_PROJECT_COMPANYPHONE _T("14") // Company Phone Number
#define ISPROP_PROJECT_SSTREAMCOMMENT _T("15") // Comment for summary stream info.
#define ISPROP_PROJECT_LASTMODIFIED _T("16") // Last modification
#define ISPROP_PROJECT_CURRENT_PRODUCT _T("17") // Current selected product
#define ISPROP_PROJECT_VERSION _T("18") // Product version
#define ISPROP_PROJECT_CREATE_SETUPEXE _T("19")
#define ISPROP_PROJECT_PATHVARSET _T("20")
#define ISPROP_PROJECT_TYPE _T("21") // msi or msm project
#define ISPROP_PROJECT_ACTIVE_LANGUAGE _T("22")
#define ISPROP_PROJECT_TITLE _T("23")
#define ISPROP_PROJECT_KEYWORDS _T("24")
#define ISPROP_PROJECT_MSILOGFILE _T("MsiLogging")
#define ISPROP_PROJECT_MSIEXECCMDLINEOPTIONS _T("28")
#define ISPROP_PROJECT_DATECREATED _T("34")
#define ISPROP_PROJECT_LASTPRINTED _T("35")
#define ISPROP_PROJECT_DIM_SUBJECT _T("69") //subject is used as display name under a feature
// ISD project root properties
#define ISPROP_PROJECT_ISD_VERSION _T("10") // Product version

//================================================
// Publish Component
#define ISPROP_PUBCOMP_ID _T("ComponentId_ComponentId")
#define ISPROP_PUBCOMP_FEATURE _T("Feature_")
#define ISPROP_PUBCOMP_COMPONENT _T("Component_")
#define ISPROP_PUBCOMP_QUALIFIER_FEATURE _T("Feature_")
#define ISPROP_PUBCOMP_QUALIFIER_ID _T("Qualifier")
#define ISPROP_PUBCOMP_QUALIFIER_APPDATA _T("AppData")

//================================================
//RADIOBUTTON class props
#define ISPROP_RADIOBUTTON_NAME _T("Property")
#define ISPROP_RADIOBUTTON_ORDER _T("Order")
#define ISPROP_RADIOBUTTON_VALUE _T("Value")
#define ISPROP_RADIOBUTTON_X _T("XPos")
#define ISPROP_RADIOBUTTON_Y _T("YPos")
#define ISPROP_RADIOBUTTON_WIDTH _T("Width")
#define ISPROP_RADIOBUTTON_HEIGHT _T("Height")
#define ISPROP_RADIOBUTTON_TEXT _T("Text")
#define ISPROP_RADIOBUTTON_HELP _T("Help")


#define ISPROP_REGISTRYSET_COMMENTS _T("Comments")

//================================================
//REGLOCATOR class props
//Added 7/16/98 by Mark Pownell

#define ISFIELD_REGLOCATOR_ROOT _T("Root")
#define ISFIELD_REGLOCATOR_KEY _T("Key")
#define ISFIELD_REGLOCATOR_NAME _T("Name")
#define ISFIELD_REGLOCATOR_TYPE _T("Type")
#define ISFIELD_REGLOCATOR_SIGNATUREKEY _T("Signature")

//================================================
//SERVICE class props
//Added 7/16/98 by Mark Pownell

#define ISPROP_SERVICE_DISPLAYNAME _T("DisplayName")
#define ISPROP_SERVICE_TYPE _T("ServiceType_ServiceType")
#define ISPROP_SERVICE_INTERACTIVE_PROCESS _T("ServiceType_ServiceTypeInteractiveProcess")
#define ISPROP_SERVICE_STARTTYPE _T("StartType_StartType")
#define ISPROP_SERVICE_ERROR_CONTROL _T("ErrorControl_ErrorControlType")
#define ISPROP_SERVICE_LOAD_ORDER_GROUP _T("LoadOrderGroup")
#define ISPROP_SERVICE_DEPENDENCIES _T("Dependencies_Dependencies")
#define ISPROP_SERVICE_STARTNAME _T("StartName")
#define ISPROP_SERVICE_PASSWORD _T("Password")
#define ISPROP_SERVICE_ARGUMENTS _T("Arguments")
#define ISPROP_SERVICE_DESCRIPTION _T("Description")

//================================================
//SERVICE_CONTROL class props
//Added 7/16/98 by Mark Pownell
//Updated 9/17/98 by Marwan Tabet

#define ISPROP_SERVICE_CONTROL_DISPLAYNAME _T("Name")

//================================================
//SERVICE_CONTROL_EVENT class props

#define ISPROP_SERVICE_CONTROL_EVENT_INSTALL_START _T("Event_InstallStart")
#define ISPROP_SERVICE_CONTROL_EVENT_INSTALL_STOP _T("Event_InstallStop")
#define ISPROP_SERVICE_CONTROL_EVENT_INSTALL_DELETE _T("Event_InstallDelete")
#define ISPROP_SERVICE_CONTROL_EVENT_UNINSTALL_START _T("Event_UnInstallStart")
#define ISPROP_SERVICE_CONTROL_EVENT_UNINSTALL_STOP _T("Event_UnInstallStop")
#define ISPROP_SERVICE_CONTROL_EVENT_UNINSTALL_DELETE _T("Event_UnInstallDelete")
#define ISPROP_SERVICE_CONTROL_ARGUMENT _T("Arguments_Arguments")
#define ISPROP_SERVICE_CONTROL_WAIT _T("Wait_Wait")

//================================================
//SETUPTYPE class props

#define ISPROP_SETUPTYPE_NAME _T("ISSetupType")
#define ISPROP_SETUPTYPE_DISPLAYNAME _T("Display_Name")
#define ISPROP_SETUPTYPE_DESCRIPTION _T("Description")
#define ISPROP_SETUPTYPE_LEVEL _T("Display")
#define ISPROP_SETUPTYPE_COMMENTS _T("Comments")

//================================================
// Shortcut table properties
// #### note shared between TWO shortcut classes (folder & shortcut) ###
#define ISPROP_SHORTCUT_NAME _T("Shortcut")
#define ISPROP_SHORTCUT_FOLDER _T("Directory__Folder")
#define ISPROP_SHORTCUT_TARGET _T("Target_Target")
#define ISPROP_SHORTCUT_ICON _T("Icon__IconFile")
#define ISPROP_SHORTCUT_ICONINDEX _T("IconIndex_IconIndex")
#define ISPROP_SHORTCUT_DESCRIPTION _T("Description")
#define ISPROP_SHORTCUT_DISPLAYNAME _T("Name")
#define ISPROP_SHORTCUT_ARGUMENTS _T("Arguments")
#define ISPROP_SHORTCUT_HOTKEY _T("Hotkey")
#define ISPROP_SHORTCUT_WORKINGDIR _T("WkDir_WorkingDirectory")
#define ISPROP_SHORTCUT_DISPLAYRESOURCEDLL _T("DisplayResourceDLL")
#define ISPROP_SHORTCUT_DISPLAYRESOURCEID _T("DisplayResourceId")
#define ISPROP_SHORTCUT_DESCRIPTIONRESOURCEDLL _T("DescriptionResourceDLL")
#define ISPROP_SHORTCUT_DESCRIPTIONRESOURCEID _T("DescriptionResourceId")
#define ISPROP_SHORTCUT_COMMENTS _T("ISComments")
#define ISPROP_SHORTCUT_RUN _T("ShowCmd") //   normal, min, max, etc..
#define ISPROP_SHORTCUT_COMPONENTNAME _T("Component__ComponentName")
#define ISPROP_SHORTCUT_COMPONENTDISPLAYLIST _T("Component__ComponentDisplayList")
// Added for Pro Support
#define ISPROP_SHORTCUT_INTERNET _T("ISAttributes_InternetShortcut")
#define ISPROP_SHORTCUT_TYPE _T("ISAttributes_Type") //Personal, Common, or Automatic
#define ISPROP_SHORTCUT_UNINSTALL _T("ISAttributes_Uninstall")
#define ISPROP_SHORTCUT_REPLACE _T("ISAttributes_ReplaceExistingIfFound")
#define ISPROP_SHORTCUT_DOT_NET_PROJECT_OUTPUT _T("ISAttributes_DotNetProjectOutput")

#define ISPROP_SHORTCUTFOLDER_NAME _T("Directory_Name")
#define ISPROP_SHORTCUTFOLDER_DISPLAYNAME _T("DefaultDir_DisplayName")
#define ISPROP_SHORTCUTFOLDER_DESCRIPTION _T("ISDescription")
#define ISPROP_SHORTCUTFOLDER_SHARED _T("ISAttributes_Shared")

//================================================
//SIGNATURE class props
//Added 7/16/98 by Mark Pownell

#define ISFIELD_SIGNATURE_KEY _T("Signature")
#define ISFIELD_SIGNATURE_FILENAME _T("FileName")
#define ISFIELD_SIGNATURE_MINVERSION _T("MinVersion")
#define ISFIELD_SIGNATURE_MAXVERSION _T("MaxVersion")
#define ISFIELD_SIGNATURE_MINSIZE _T("MinSize")
#define ISFIELD_SIGNATURE_MAXSIZE _T("MaxSize")
#define ISFIELD_SIGNATURE_MINDATE _T("MinDate")
#define ISFIELD_SIGNATURE_MAXDATE _T("MaxDate")
#define ISFIELD_SIGNATURE_LANGUAGES _T("Languages")

//================================================
//TEXTSTYLE class props
#define ISTEXTSTYLE_LAYOUT _T("TEXTSTYLE_LAYOUT")
#define ISCLASST_TEXTSTYLE _T("TEXTSTYLE")
//Key = TextStyle
#define ISFIELD_TEXTSTYLE_DISPLAYNAME _T("FaceName")
#define ISFIELD_TEXTSTYLE_SIZE _T("Size")
#define ISFIELD_TEXTSTYLE_COLOR _T("Color")
#define ISFIELD_TEXTSTYLE_ATTRIBUTES _T("StyleBits")

//================================================

#define ISPROP_TYPELIB_GUID _T("LibID")
#define ISPROP_TYPELIB_VERSION _T("Version_Version")
#define ISPROP_TYPELIB_COST _T("Cost")
#define ISPROP_TYPELIB_DESC _T("p3") //not used in ism # 'was ISPROP_TYPELIB_FEATURE
#define ISPROP_TYPELIB_LANG _T("Language")
#define ISPROP_TYPELIB_HELPDIR _T("Directory__HelpPath")
#define ISPROP_TYPELIB_DISPLAYNAME _T("Description") //was ISPROP_TYPELIB_DESCRIPTION
#define ISPROP_TYPELIB_FEATURE _T("Feature")

//   ===========================================================================
//   Layouts & Groups
//   ===========================================================================
#define ISPROJECT_ROOT _T("PROJECTROOT") // used by Ism.exe

//   ===========================================================================
//   Misc constants
#define ISMSI_STR_NULL _T("NULL")

#define ISMSI_REGISTRATION_STATIC (0)
#define ISMSI_REGISTRATION_SELFREG (-1)
#define ISMSI_REGISTRATION_EXTRACT (-2)

#define ISMSI_NULL_GUID _T("{00000000-0000-0000-0000-000000000000}")

#define ISMSI_KEYPATH_REGISTRY (1) // Keypath is a registry key
#define ISMSI_KEYPATH_FILE (2) // Keypath is a file
#define ISMSI_KEYPATH_FOLDER (3) // Keypath is the installation folder
#define ISMSI_KEYPATH_ODBC (4) // Keypath is a ODBCDataSource


// predefined table and value for AppPath namedvalue table
#define ISMSI_APPPATH_DEFAULTKEY _T("YourApp")
#define ISMSI_APPPATH_DEFAULTNAME _T("(Default)")
#define ISMSI_APPPATH_DEFAULTPATH _T("Path")

// predefined table and value for registry namedvalue table
#define ISMSI_REGDEFAULT_NAME _T("(Default)")
#define ISMSI_REGDEFAULT_NONVALUE _T("%%%%NOVALUESET%%%%") // string used to represent non-value (highly unlikely string)

// predefined value for the dialog property fields
#define ISMSI_DIALOG_DEFAULTHCENTERING (50)
#define ISMSI_DIALOG_DEFAULTVCENTERING (50)
#define ISMSI_DIALOG_DEFAULTWIDTH (374)
#define ISMSI_DIALOG_DEFAULTHEIGHT (266)
#define ISMSI_DIALOG_DEFAULTATTRIBUTES (3) // Visible and Modal
#define ISMSI_DIALOG_DEFAULTSEQUENCE (-1) //

// predefined value for the control property fields
#define ISMSI_CONTROL_DEFAULTXPOS (0)
#define ISMSI_CONTROL_DEFAULTYPOS (0)
#define ISMSI_CONTROL_DEFAULTWIDTH (50)
#define ISMSI_CONTROL_DEFAULTHEIGHT (10)
#define ISMSI_CONTROL_DEFAULTATTRIBUTES (3) // Visible and enabled

// predefined value for the control condition table fields
#define ISMSI_CONTROL_DEFAULTCONDITION (1)

// predefined value for the control event table fields
#define ISMSI_CEVENT_DEFAULTARGUMENT _T("{}")

// Class Insertable
#define ISMSI_CLASSID_NOTINSERTABLE (0)
#define ISMSI_CLASSID_INSERTABLE (1)
#define ISMSI_CLASSID_NEITHER (2)

//   PROGID Insertable
#define ISMSI_PROGID_NOTINSERTABLE (0)
#define ISMSI_PROGID_INSERTABLE (1)
#define ISMSI_PROGID_NEITHER (2)

// predefined value for the Install Sequence table fields
#define ISMSI_SEQ_INSTALL_CONDITION _T("NOT UITEST AND NOT Installed")
#define ISMSI_SEQ_INSTALL_SEQUENCE (1100)
#define ISMSI_SEQ_MAINTAIN_CONDITION _T("NOT UITEST AND Installed AND NOT RESUME AND NOT Preselected")
#define ISMSI_SEQ_MAINTAIN_SEQUENCE (1200)

// predefined value for the Media table fields
#define ISMSI_MEDIA_DISK_PROMPT _T("Please enter your CD")
#define ISMSI_MEDIA_CAB_PREFIX _T("#")

// predefined value for the Summary Stream table fields
#define ISMSI_SSTREAM_COMMENT _T("The Installation database contains the logic and data required to install ")


//# samir
#define ISMSI_REGROOT_HKCR (0) // HKEY_CLASSES_ROOT
#define ISMSI_REGROOT_HKCU (1) // HKEY_CURRENT_USER
#define ISMSI_REGROOT_HKLM (2) // HKEY_LOCAL_MACHINE
#define ISMSI_REGROOT_HKU (3) // HKEY_USERS
#define ISMSI_REGROOT_HKUS (-1) // HKEY_USER_SELECTABLE

#define ISMSI_REG_INTEGER (0) // REG_NUMBER
#define ISMSI_REG_STRING (1) // REG_STRING
#define ISMSI_REG_BINARY (2) // REG_BINARY
#define ISMSI_REG_MULTISZ (3) // REG_MULTI_SZ
#define ISMSI_REG_EXPANDSZ (4) // REG_EXPAND_SZ

// numeric constants
#define ISMSI_RUNFROMSOURCE_FAVOR_LOCAL (0)
#define ISMSI_RUNFROMSOURCE_RUNFROM_SOURCE (1) //default
#define ISMSI_RUNFROMSOURCE_INSTALL_LOCALLY (2)

#define ISMSI_COMPONENT_RUNFRMSRC_LOCAL (0)
#define ISMSI_COMPONENT_RUNFRMSRC_FROM_SOURCE (1)
#define ISMSI_COMPONENT_RUNFRMSRC_FOLLOW_PARENT (2)

// Run/Show command styles of Shortcut
//Changed to 1 per WO 18652
//#define ISWI_SW_SHOWNORMAL (0)

#define ISWI_SW_SHOWNORMAL (1)
#define ISWI_SW_SHOWMAXIMIZED (3)
#define ISWI_SW_SHOWMINNOACTIVE (7)
#define ISWI_SW_SHOW (5)

//   ===========================================================================
//   ### Move to the MsiConst.h file

#define MSI_CONTEXT_LOCALSERVER _T("LocalServer")
#define MSI_CONTEXT_LOCALSERVER32 _T("LocalServer32")
#define MSI_CONTEXT_INPROCSERVER _T("InprocServer")
#define MSI_CONTEXT_INPROCSERVER32 _T("InprocServer32")

#define MSI_CONTEXT_DEFHANDLER16 _T("1")
#define MSI_CONTEXT_DEFHANDLER32 _T("2")
#define MSI_CONTEXT_DEFHANDLER1632 _T("3")

#define MSI_EXTVALUE_FILENAME _T("FileName")
#define MSI_EXTVALUE_COMMAND _T("Command")
#define MSI_EXTVALUE_DATA _T("Data")
#define MSI_EXTVALUE_NULLFILE _T("NullFile")

#define MSI_CONTROL_NEXT _T("Next")
#define MSI_CONTROL_BACK _T("Back")

//   ===========================================================================
//   Type of installation sequence this dialog is used for
//
#define ISMSI_DIALOG_INSTALLATION_SEQUENCE (1)
#define ISMSI_DIALOG_MAINTENANCE_SEQUENCE (2)

//   Control Types
#define ISMSI_CONTROL_BITMAP _T("Bitmap")
#define ISMSI_CONTROL_SCROLLABLETEXT _T("ScrollableText")

//   Control Condition
#define ISMSI_CCONDTION_TRUE _T("1")
#define ISMSI_CCONDTION_FALSE _T("0")

//   Sequence Types
#define ISMSI_SEQ_UI (1)
#define ISMSI_SEQ_EXEC (2)

//   Feature Advertise
#define ISMSI_FEATURE_ADVERTISE_NONE (0)
#define ISMSI_FEATURE_ADVERTISE_FAVOR (1)
#define ISMSI_FEATURE_ADVERTISE_DISALLOW (2)
#define ISMSI_FEATURE_ADVERTISE_DISABLE_NOTSUPPORTED (4)

//   Feature Display
#define ISMSI_FEATURE_DISPLAY_COLLAPSED (0)
#define ISMSI_FEATURE_DISPLAY_EXPANDED (1)
#define ISMSI_FEATURE_DISPLAY_NOTVISIBLE (2)

// ODBC Registration values
#define MSI_ODBC_SYSTEM_DSN _T("0")
#define MSI_ODBC_USER_DSN _T("1")

// Service Install table constants
#define ISMSI_SERVICE_NULLCHARACTER _T(",")

#define ISMSI_PLATFORM_INTEL _T("Intel")
#define ISMSI_PLATFORM_ALPHA _T("Alpha")

#define ISMSI_OS_NONE (0)
#define ISMSI_OS_WIN9x (1)
#define ISMSI_OS_WINNT (2)


// No more angle brackets in destinations in Express.
#define ISMSI_ADMINTOOLSFOLDER _T("[AdminToolsFolder]")
#define ISMSI_ALLUSERSPROFILE _T("[ALLUSERSPROFILE]")
#define ISMSI_APPDATAFOLDER _T("[AppDataFolder]")
#define ISMSI_COMMONAPPDATAFOLDER _T("[CommonAppDataFolder]")
#define ISMSI_COMMONFILESFOLDER _T("[CommonFilesFolder]")
#define ISMSI_COMMONFILES64FOLDER _T("[CommonFiles64Folder]")
#define ISMSI_DATABASEDIR _T("[DATABASEDIR]")
#define ISMSI_DESKTOPFOLDER _T("[DesktopFolder]")
#define ISMSI_FAVOURITESFOLDER _T("[FavoritesFolder]")
#define ISMSI_FONTSFOLDER _T("[FontsFolder]")
#define ISMSI_INSTALLDIR _T("[INSTALLDIR]")
#define ISMSI_LOCALAPPDATAFOLDER _T("[LocalAppDataFolder]")
#define ISMSI_MYPICTURESFOLDER _T("[MyPicturesFolder]")
#define ISMSI_PERSONALFOLDER _T("[PersonalFolder]")
#define ISMSI_PRIMARYVOLUMEPATH _T("[PrimaryVolumePath]")
#define ISMSI_PROGRAMFILESFOLDER _T("[ProgramFilesFolder]")
#define ISMSI_PROGRAMFILES64FOLDER _T("[ProgramFiles64Folder]")
#define ISMSI_PROGRAMMENUFOLDER _T("[ProgramMenuFolder]")
#define ISMSI_SENDTOFOLDER _T("[SendToFolder]")
#define ISMSI_STARTMENUFOLDER _T("[StartMenuFolder]")
#define ISMSI_STARTUPFOLDER _T("[StartupFolder]")
#define ISMSI_SYSTEM16FOLDER _T("[System16Folder]")
#define ISMSI_SYSTEMFOLDER _T("[SystemFolder]")
#define ISMSI_SYSTEM64FOLDER _T("[System64Folder]")
#define ISMSI_TEMPFOLDER _T("[TempFolder]")
#define ISMSI_TEMPLATEFOLDER _T("[TemplateFolder]")
#define ISMSI_USERPROFILE _T("[USERPROFILE]")
#define ISMSI_WINDOWSFOLDER _T("[WindowsFolder]")
#define ISMSI_TASKBARFOLDER _T("[TaskBarFolder]")
#define ISMSI_WINDOWSVOLUME _T("[WindowsVolume]")

#define PV_COMMONFILESFOLDER _T("<CommonFilesFolder>")
#define PV_PROGRAMFILESFOLDER _T("<ProgramFilesFolder>")
#define PV_SYSTEMFOLDER _T("<SystemFolder>")
#define PV_WINDOWSFOLDER _T("<WindowsFolder>")
#define PV_ISPROJECTFOLDER  _T("<ISProjectFolder>")
#define PV_ISPRODUCTFOLDER  _T("<ISProductFolder>")
#define PV_ISPROJECTDATAFOLDER  _T("<ISProjectDataFolder>")
#define PV_ISPROJECTDIR  _T("<ISPROJECTDIR>")
#define PV_ISREDISTPLATFORMDPTDIR  _T("<ISRedistPlatformDependentFolder>")

#define ISMSI_NEWPROJECT_SETUPWIZARD  _T("SetupWizard")
#define ISMSI_NEWPROJECT_SETUPWIZARD_CSHARP  _T("SetupWizardCSharp")
#define ISMSI_NEWPROJECT_SETUPWIZARD_VB7  _T("SetupWizardVB7")
#define ISMSI_NEWPROJECT_SETUPBLANK  _T("SetupBlank")
#define ISMSI_NEWPROJECT_MSIDATABASE  _T("MsiDB")
#define ISMSI_NEWPROJECT_MSMDATABASE  _T("MsmDB")
#define ISMSI_NEWPROJECT_MODULEWIZARD  _T("ModuleWizard") // unsupported
#define ISMSI_NEWPROJECT_MODULEBLANK  _T("ModuleBlank")
#define ISMSI_NEWPROJECT_QUICKPATCH  _T("QuickPatch")
#define ISMSI_NEWPROJECT_ISOBJ  _T("InstallScriptObjBlank")
#define ISMSI_NEWPROJECT_WEB  _T("WebBlank")
#define ISMSI_NEWPROJECT_VBWIZARD  _T("VBWizard") // unsupported
#define ISMSI_NEWPROJECT_VCWIZARD  _T("VCWizard") // unsupported
#define ISMSI_NEWPROJECT_SCRIPT  _T("Script")
#define ISMSI_NEWPROJECT_TRANSFORM  _T("Transform")
#define ISMSI_NEWPROJECT_PRO  _T("Professional")
#define ISMSI_NEWPROJECT_PRO_OBJ  _T("ProfessionalObj")
#define ISMSI_NEWPROJECT_CEWIZARD  _T("CEWizard")
#define ISMSI_NEWPROJECT_CLICKONCE  _T("ClickOnce")
#define ISMSI_NEWPROJECT_LITE  _T("Lite")
#define ISMSI_NEWPROJECT_UNV_INSTALLER  _T("UniversalInstaller")
#define ISMSI_NEWPROJECT_UNV_STATICSUITE  _T("StaticSuite")
#define ISMSI_NEWPROJECT_UNV_DYNAMICSUITE  _T("DynamicSuite")
#define ISMSI_NEWPROJECT_THINAPP  _T("ThinApp")
#define ISMSI_NEWPROJECT_APPV  _T("AppV")
#define ISMSI_NEWPROJECT_DIM _T("DIM")
#define ISMSI_NEWPROJECT_BOOTSTRAP _T("Bootstrap")

#define TEXT_TYPE (0)
#define FORMATTED_TYPE (1)

//String Identifier Delimiters used in store
#define STR_ID_DEL_LEFT _T("##")
#define STR_ID_DEL_RIGHT _T("##")

//String Identifier Delimiters used in UI
#define UI_STR_ID_DEL_LEFT _T("{")
#define UI_STR_ID_DEL_RIGHT _T("}")

//Registry Key for langs
#define ISREGKEY_LANGS _T("Languages")
#define ISREGKEY_TEMPLATES_PATH _T("Templates")

#define ISMSI_LANG_NEUTRAL _T("0")
#define ISMSI_LANG_FILTER_ON_SELECTED_LANGS (0)
#define ISMSI_LANG_DONOTFILTER (0)

#define ISMSI_PROJECTTYPE_MSI _T("MSI")
#define ISMSI_PROJECTTYPE_MSM _T("MSM")
#define ISMSI_PROJECTTYPE_MSIE _T("MSIE")
#define ISMSI_PROJECTTYPE_MSIDIRECT _T("MSIDirect")
#define ISMSI_PROJECTTYPE_MSMDIRECT _T("MSMDirect")
#define ISMSI_PROJECTTYPE_MST _T("MST")
#define ISMSI_PROJECTTYPE_QUICKPATCH _T("ISQP")
#define ISMSI_PROJECTTYPE_CE _T("CE")
#define ISMSI_PROJECTTYPE_PRO _T("PRO")
#define ISMSI_PROJECTTYPE_PROOBJECT _T("PROOBJECT")
#define ISMSI_PROJECTTYPE_MSP _T("MSP")
#define ISMSI_PROJECTTYPE_CLICKONCE _T("CLICKONCE")
#define ISMSI_PROJECTTYPE_LITE _T("LITE")
#define ISMSI_PROJECTTYPE_DIM _T("DIM")

// ==========================================================================
// Path variable types
#define ISMSI_PATHVARIABLES_PREDEFINED (1)
#define ISMSI_PATHVARIABLES_CUSTOM (2)
#define ISMSI_PATHVARIABLES_ENVIRONMENT (4)
#define ISMSI_PATHVARIABLES_REGISTRY (8)

//================================================
// Build Label class props
#define ISPROP_BUILDLABEL_NAME _T("ISProductConfiguration") // Same as ISPROP_STD_NAME

//================================================
// Additional Build Label (really SKU now) class props
//Under ism#, these are for ISProductConfiguration table...
#define ISPROP_SKU_SUBJECT _T("ISProductConfiguration_Subject") // SIS subject (can be localized)
#define ISPROP_SKU_VERSION _T("ISProductConfiguration_ProductVersion")
#define ISPROP_SKU_COMMENTS _T("ISProductConfiguration_Comments") // SIS comments
#define ISPROP_SKU_TITLE _T("ISProductConfiguration_Title") // SIS title
#define ISPROP_SKU_PRODUCTNAME _T("ISProductConfiguration_ProductName") // Non-localized ProductName
#define ISPROP_SKU_PACKAGECODE _T("ISProductConfiguration_PackageCode")
#define ISPROP_SKU_TEMPLATESUMMARY _T("ISProductConfiguration_TemplateSummary") //Template summary property
#define ISPROP_SKU_TEMPLATESUMMARYDIRECT _T("ISProductConfiguration_TemplateSummaryDirect") //Template summary property
#define ISPROP_SKU_SKUFLAGS _T("ProductConfigurationFlags")
#define ISPROP_SKU_GENPACKAGECODE _T("GeneratePackageCode")
#define ISPROP_SKU_PAGECOUNT _T("ISProductConfiguration_PageCount")
#define ISPROP_SKU_MSIFILENAME _T("ISProductConfiguration_MSIPackageFileName")
#define ISPROP_SKU_SETUPFILENAME _T("ISProductConfiguration_SetupFileName")
#define ISPROP_SKU_PLATFORMVALIDATION _T("ISProductConfiguration_PlatformValidation")

//New field codes in ism# for ISProductConfiguration table
#define ISPROP_SKU_UPGRADECODE _T("ISProductConfiguration_UpgradeCode")
#define ISPROP_SKU_PRODUCTCODE _T("ISProductConfiguration_ProductCode")
#define ISPROP_SKU_PREPROCESSOR_DEFINES _T("ISProductConfiguration_PreProcessorDefines")

#define SEQUENCENUMBER_INCREMENT 50L

#define INVALIDATE_POINTS -1L

// RDA: It would be best if we didn't change the following constants
#define ISSETUPTYPES_SELECTION_PROPERTY  _T("_IsSetupTypeMin")
#define ISSETUPTYPES_INSTALLLEVEL_PROPERTY  _T("INSTALLLEVEL")
#define ISSETUPTYPE_CONDITION_BASE  _T("_IsSetupTypeMin = ")
#define ISSETUPTYPE_CONTROL_NAME  _T("Next")
#define ISCONTROLEVENT_ADDLOCAL  _T("AddLocal")
#define ISCONTROLEVENT_ADDSOURCE  _T("AddSource")
#define ISCONTROLEVENT_SETINSTALLLEVEL  _T("SetInstallLevel")
#define ISPROP_SELECTEDSETUPTYPE  _T("[SelectedSetupType]")

#define SETUPTYPE_DISPLAYNAME_PROPERTY1 _T("DisplayNameTypical")
#define SETUPTYPE_DISPLAYNAME_PROPERTY2 _T("DisplayNameMinimal")
#define SETUPTYPE_DISPLAYNAME_PROPERTY3 _T("DisplayNameCustom")

#define ISSETUPTYPE_REFRESH_EVENT _T("REFRESH_ISSETUPTYPES_DIALOGS")
#define ISUPDATESERVICE_ENABLED_EVENT _T("REFRESH_COMPLETE_SUCCESS_DIALOG")

#define PROP_EXEFILE _T("ISAppExeFile")

// SQL related MSI properties
#define PROP_IS_SQLSERVER_SERVER _T("IS_SQLSERVER_SERVER")
#define PROP_IS_SQLSERVER_DATABASE _T("IS_SQLSERVER_DATABASE")
#define PROP_IS_SQLSERVER_USERNAME _T("IS_SQLSERVER_USERNAME")
#define PROP_IS_SQLSERVER_PASSWORD _T("IS_SQLSERVER_PASSWORD")
#define PROP_IS_SQLSERVER_AUTHENTICATION _T("IS_SQLSERVER_AUTHENTICATION")

//Used for TargetSystemRequirements
#define TARGETREQ_PROPERTY_KEYBASE  _T("IsTargetReq")
#define TARGETREQ_PROPERTIES_COUNT 5L
#define ISPROP_TARGETREQ_COLOR  _T("5")
#define ISPROP_TARGETREQ_OS  _T("1")
#define ISPROP_TARGETREQ_PROCESSOR  _T("2")
#define ISPROP_TARGETREQ_RAM  _T("3")
#define ISPROP_TARGETREQ_RESOLUTION  _T("4")

#define TARGETREQ_CONDITION_TRUE  _T("1")
#define TARGETREQ_CONDITIONBASE_COLOR  _T("ColorBits >= ")
#define TARGETREQ_CONDITIONBASE_PROCESSOR  _T("Intel >= ")
#define TARGETREQ_CONDITIONBASE_RAM  _T("PhysicalMemory >= ")
#define TARGETREQ_CONDITION_RES_640  _T("ScreenX >= 640 AND ScreenY >= 480")
#define TARGETREQ_CONDITION_RES_800  _T("ScreenX >= 800 AND ScreenY >= 600")
#define TARGETREQ_CONDITION_RES_1024  _T("ScreenX >= 1024 AND ScreenY >= 768")
#define TARGETREQ_CONDITION_RES_1280  _T("ScreenX >= 1280 AND ScreenY >= 1024")
#define TARGETREQ_CONDITIONBASE_OS_9X  _T("Version9X=")
#define TARGETREQ_CONDITIONBASE_OS_NT  _T("VersionNT=")
#define TARGETREQ_CONDITIONOFFSET_NT4  _T("400")
#define TARGETREQ_CONDITIONOFFSET_WIN2K  _T("500")
#define TARGETREQ_CONDITIONOFFSET_WINXP  _T("501")
#define TARGETREQ_CONDITIONOFFSET_WINNETSERVER  _T("502")
#define TARGETREQ_CONDITIONOFFSET_WINVISTA  _T("600")
#define TARGETREQ_CONDITIONOFFSET_WINLONGHORN  _T("600")
#define TARGETREQ_CONDITIONOFFSET_WIN7  _T("601")
#define TARGETREQ_CONDITIONOFFSET_WIN8  _T("602")
#define TARGETREQ_CONDITIONOFFSET_WIN81 _T("603")
#define TARGETREQ_CONDITIONOFFSET_WIN95  _T("400")
#define TARGETREQ_CONDITIONOFFSET_WIN98  _T("410")
#define TARGETREQ_CONDITIONOFFSET_WINME  _T("490")
#define TARGETREQ_CONDITION_WINDOWSBUILD  _T("WindowsBuild=")
#define TARGETREQ_CONDITION_BUILD_WIN98SE  _T("2222")
#define TARGETREQ_CONDITION_BUILD_XP  _T("2600")
#define TARGETREQ_CONDITION_WINDOWSBUILD_GREATER  _T("WindowsBuild>")

#define TARGETREQ_DESRIPTION_COLOR  _T("##IDS__TargetReq_DESC_COLOR##")
#define TARGETREQ_DESRIPTION_OS  _T("##IDS__TargetReq_DESC_OS##")
#define TARGETREQ_DESRIPTION_PROCESSOR  _T("##IDS__TargetReq_DESC_PROCESSOR##")
#define TARGETREQ_DESRIPTION_RAM  _T("##IDS__TargetReq_DESC_RAM##")
#define TARGETREQ_DESRIPTION_RESOLUTION  _T("##IDS__TargetReq_DESC_RESOLUTION##")

// Dialog Constants
#define ISPROP_SPLASH_BITMAP  _T("1")
#define ISPROP_SPLASH_SUNKEN  _T("2")

#define ISPROP_WELCOME_COPYRIGHT  _T("1")
#define ISPROP_WELCOME_TEXT  _T("2")
#define ISPROP_WELCOME_BITMAP  _T("3")

#define ISPROP_LICENSE_BITMAP  _T("1")
#define ISPROP_LICENSE_FILE  _T("2")

#define ISPROP_README_BITMAP  _T("1")
#define ISPROP_README_FILE  _T("2")

#define ISPROP_CUSTOMERINFO_BITMAP  _T("1")
#define ISPROP_CUSTOMERINFO_SHOWSN  _T("2")
#define ISPROP_CUSTOMERINFO_SNTEMP  _T("3")
#define ISPROP_CUSTOMERINFO_SNDLL  _T("4")
#define ISPROP_CUSTOMERINFO_VALIDATE  _T("5")
#define ISPROP_CUSTOMERINFO_SUCCESS  _T("6")
#define ISPROP_CUSTOMERINFO_RETRYLIMIT  _T("7")
//#define ISPROP_CUSTOMERINFO_ERRORMESSAGE  _T("8")
#define ISPROP_CUSTOMERINFO_ALLUSERS  _T("8")

#define ISPROP_CUSTOMSETUP_BITMAP  _T("1")
#define ISPROP_CUSTOMSETUP_DEST  _T("2")

#define ISPROP_SETUPTYPE_BITMAP  _T("1")
#define ISPROP_SETUPTYPE_SHOW  _T("2")

#define ISPROP_DATABASELOCATION_BITMAP  _T("1")
#define ISPROP_DATABASELOCATION_SHOW  _T("2")

#define ISPROP_DESTINATIONLOCATION_BITMAP  _T("1")
#define ISPROP_DESTINATIONLOCATION_SHOW  _T("2")

#define ISPROP_READYTOINSTALL_BITMAP  _T("1")
#define ISPROP_READYTOINSTALL_SHOW  _T("2")

#define ISPROP_PROGRESS_BITMAP  _T("1")
#define ISPROP_PROGRESS_SHOW  _T("2")

#define ISPROP_SUCCESS_BITMAP  _T("1")
#define ISPROP_SUCCESS_SHOWLAUNCH  _T("2")
#define ISPROP_SUCCESS_PROGRAMFILE  _T("3")
#define ISPROP_SUCCESS_SHOWREADME  _T("4")
#define ISPROP_SUCCESS_READMEFILE  _T("5")
#define ISPROP_SUCCESS_CMDLINEPARAMS  _T("6")

#define ISPROP_YAHOOTOOLBAR_BITMAP  _T("1")


#define ISX_CA_SIGNATURESTYLE_CLASSIC  0L
#define ISX_CA_SIGNATURESTYLE_NEW  1L

#define ISX_CA_EXECUTE_INSTALL  _T("0")
#define ISX_CA_EXECUTE_UNINSTALL  _T("1")

#define ISX_CA_SOURCE_LOCALFILE  0L
#define ISX_CA_SOURCE_FILEINSTALLED  1L
#define ISX_CA_SOURCE_TARGETSYSTEM  2L

// constant for SetupType properties
#define ISWI_SETUPTYPE_LEVEL  _T("1")
#define ISWI_SETUPTYPE_RADIOBTNCTRL  _T("2")
#define ISWI_SETUPTYPE_DESCIPTIONCTRL  _T("3")
#define ISWI_SETUPTYPE_ICONCTRL  _T("4")
#define ISWI_SETUPTYPE_DISPLAYNAME  _T("5")
#define ISWI_SETUPTYPE_DESCRIPTION  _T("6")

//predefined Express dialogs name
#define ISX_DLG_SPLASH  _T("SplashBitmap")
#define ISX_DLG_WELCOME  _T("InstallWelcome")
#define ISX_DLG_LICENSE  _T("LicenseAgreement")
#define ISX_DLG_README  _T("ReadmeInformation")
#define ISX_DLG_CUSTOMERINFO  _T("CustomerInformation")
#define ISX_DLG_DESTFOLDER  _T("DestinationFolder")
#define ISX_DLG_DATABASEFOLDER  _T("DatabaseFolder")
#define ISX_DLG_SETUPTYPE  _T("SetupType")
#define ISX_DLG_CUSTOMSETUP  _T("CustomSetup")
#define ISX_DLG_READYTOINSTALL  _T("ReadyToInstall")
#define ISX_DLG_PROGRESS  _T("SetupProgress")
#define ISX_DLG_COMPLETE  _T("SetupCompleteSuccess")
#define ISX_DLG_YAHOOTOOLBAR  _T("YahooToolbar")
#define ISX_DLG_YAHOOTOOLBAR_EULA  _T("YahooToolbarEula")
#define ISX_DLG_YAHOOTOOLBAR_AGREEMENTS  _T("YahooToolbarAgreements")

//predefined  Express dialog count
#define ISX_DLG_COUNT 15L

// Additional Express dlg only appeas in Uninstall
#define ISX_DLG_MAINTENANCE_WELCOME  _T("MaintenanceWelcome")
#define ISX_DLG_MAINTENANCE_TYPE  _T("MaintenanceType")
#define ISX_DLG_MAINTENANCE_READYTOREMOVE  _T("ReadyToRemove")

// Not actually a dialog name, just a value to be used by IsxCustomAction's
// InvokeBefore property and the Custom Action view.
#define ISX_PSEUDO_DLG_READYTOINSTALL_FROM_SETUPTYPE  _T("ReadyToInstall - From SetupType")

#define ISX_PSEUDO_DLG_PRE_UI_APPSEARCH  _T("UISeq_AppSearch")
#define ISX_PSEUDO_DLG_INIT  _T("Init")
#define ISX_PSEUDO_DLG_INSTALLFILES  _T("InstallFiles")
#define ISX_PSEUDO_DLG_REGISTERCLASSINFO  _T("RegisterClassInfo")
#define ISX_PSEUDO_DLG_INSTALLSERVICES  _T("InstallServices")
#define ISX_PSEUDO_DLG_PUBLISHPRODUCT  _T("PublishProduct")
#define ISX_PSEUDO_DLG_INSTALLINITIALIZE  _T("InstallInitialize")
#define ISX_PSEUDO_DLG_PRE_APPSEARCH  _T("AppSearch")
#define ISX_PSEUDO_DLG_REMOVEFOLDERS  _T("RemoveFolders")

#define ISX_ODBC_COMPONENT_NAME  _T("ISX_ODBC_COMPONENT")

#define ISX_INIFILE_FEATURE  _T("1")
#define ISX_INIFILE_COMPONENT  _T("1")
#define ISX_INIFILE_DIRECTORY  _T("2")
#define ISX_INIFILE_FILENAME  _T("3")

#define ISX_PROP_SERIALNUMVALDLL  _T("SERIALNUMVALDLL")
#define ISX_PROP_SERIALNUMVALFUNC  _T("SERIALNUMVALFUNC")
#define ISX_PROP_SERIALNUMVALSUCCESSRETVAL  _T("SERIALNUMVALSUCCESSRETVAL")
#define ISX_PROP_SERIALNUMVALRETRYLIMIT  _T("SERIALNUMVALRETRYLIMIT")
#define ISX_PROP_SERIALNUMVALRETURN  _T("SERIALNUMVALRETURN")
#define ISX_PROP_SHOWSERIAL  _T("SERIALNUMSHOW")


#define ISX_PROP_SERIALVERIFYCAISX  _T("serial@verifyCA@isx")
#define ISX_PROP_SERIALVERIFYCAISXHELPER  _T("serial@verifyCA@isx@helper")
#define ISX_PROP_SERIALNUMCAHELPERCLL  _T("SerialNumCAHelper.dll")
#define ISX_PROP_DECREASERETRYLIMITBYONE  _T("DecreaseRetryLimitByOne")

#define ISX_INTERNALCA_LAUNCHREADME  _T("LaunchReadmeFileFromSetupCompleteSuccess")
#define ISX_INTERNALCA_LAUNCHPROGRAM  _T("LaunchProgramFileFromSetupCompleteSuccess")

#define ISX_PROP_LAUNCHPROGRAM  _T("LAUNCHPROGRAM")
#define ISX_PROP_LAUNCHREADME  _T("LAUNCHREADME")

#define ISX_PROP_PROGRAMFILETOLAUNCHATEND  _T("PROGRAMFILETOLAUNCHATEND")
#define ISX_PROP_READMEFILETOLAUNCHATEND  _T("READMEFILETOLAUNCHATEND")
#define ISX_PROP_CMDLINEFORPROGRAMFILE  _T("CMDLINEFORPROGRAMFILE")

#define ISX_PROP_SHOWLAUNCHREADME  _T("SHOWLAUNCHREADME")
#define ISX_PROP_SHOWLAUNCHPROGRAM  _T("SHOWLAUNCHPROGRAM")

// property ID for ISX file extensin
#define ISX_FILEEXT_PROGID  _T("1")
#define ISX_FILEEXT_FEATURE  _T("2")
#define ISX_FILEEXT_CMD  _T("3")
#define ISX_FILEEXT_ARG  _T("4")
#define ISX_FILEEXT_ICONFILE  _T("5")
#define ISX_FILEEXT_ICONINDEX  _T("6")
#define ISX_FILEEXT_EXEFILE  _T("7")
#define ISX_FILEEXT_PROGIDDESCRIPTION  _T("8")

// app setting related constants
#define MODULES   _T("Modules")
#define REDIST  _T("redist")
#define LANGUAGE_INDEPENDENT_FOLDERNAME  _T("Language independent")
#define OS_INDEPENDENT  _T("OS Independent")
#define SUPPORT  _T("Support")
#define SYSTEMPATH  _T("System")
#define I386   _T("i386")
#define I386Exp   _T("i386 Express")
#define SCRIPT_PATH   _T("Script")
#define DIALOGS_PATH   _T("Dialogs")
#define SKINS_PATH   _T("Skins")


//properties for Billboard background style
#define IS_PROP_BILLBOARD_STYLE_SOLID  _T("0")
#define IS_PROP_BILLBOARD_STYLE_GRADIENT  _T("1")

#define BUILD_TAB 0L
#define VALIDATION_TAB 1L
#define RESULTS_TAB 2L

//Conflict Resolution
#define RENAME_CONFLICT _T("NON_UNIQUE_NAME")

//COM error codes
#define COMERR_E_INVALIDARG (&H80070057)

#define ISMSI_VERSIONDATABASE _T("VersionDatabase")

// SUPPORTFILES constants
#define IS_TF_LISTFILE_KEYINBINTBL  _T("SFHelper.ini")
#define IS_TF_LISTFILE_MAINSECTION  _T("Main")

// Base names for generated components. (ISX_ODBC_COMPONENT is listed above.)

#define ISX_DEFAULT_COMPNAME_BASE _T("ISX_DEFAULTCOMPONENT_")
#define ISWI_DEFAULT_COMPNAME_BASE _T("ISWI_DEFAULTCOMPONENT_")

#define ACC97_CREATESHORTCUT_ERROR (-100) // Usually because the Access97 merge module was not added.

// Missing string entry placeholder
#define UNDEFINED_STRING_REFERENCE _T("***IS_STRING_NOT_DEFINED***")

// Merge module (subject) names
#define VBSCRIPT_RUNTIME_MSM_NAME  _T("VBScriptRuntime")
#define DCOM95_MSM_NAME  _T("DCOM95")

//Script Props
#define ISPROP_SCR_FEATURE_FTPLOCATION  _T("FTPLocation")
#define ISPROP_SCR_FEATURE_HTTPLOCATION  _T("HTTPLocation")
#define ISPROP_SCR_FEATURE_MISCELLANEOUS  _T("Miscellaneous")
#define ISPROP_SCR_FEATURE_INSTALLING  _T("Installing")
#define ISPROP_SCR_FEATURE_INSTALLED  _T("Installed")
#define ISPROP_SCR_FEATURE_UNINSTALLING  _T("Uninstalling")
#define ISPROP_SCR_FEATURE_UNINSTALLED  _T("Uninstalled")

#define ISPROP_SCR_FEATUREREQUIRED_REQUIREDFEATURES  _T("RequiredFeature")

#define ISPROP_SCR_COMP_OS  _T("OS")
#define ISPROP_COMP_LANG  _T("Language")
#define ISPROP_SCR_DOMAINTENANCE  _T("DoMaintenance")

//Script OS constants
#define IS_OS_WIN2000  _T("Windows 2000")
#define IS_OS_WINNT4  _T("Windows NT 4.0")
#define IS_OS_WIN95  _T("Windows 95")
#define IS_OS_WIN98  _T("Windows 98")
#define IS_OS_WIN98SE  _T("Windows 98 Second Edition")
#define IS_OS_WINME  _T("Windows Me")
#define IS_OS_WINXP  _T("Windows XP")
#define IS_OS_WINSERVER2003  _T("Windows Server 2003")
#define IS_OS_WINVISTA  _T("Windows Vista")
#define IS_OS_WINSERVER2008  _T("Windows Server 2008")
#define IS_OS_WINVISTASERVER2008 _T("Windows Vista / Server 2008")
#define IS_OS_WIN7 _T("Windows 7")
#define IS_OS_WIN7SERVER2008R2 _T("Windows 7 / Server 2008 R2")
#define IS_OS_WINSERVER2008R2 _T("Windows Server 2008 R2")
#define IS_OS_WIN8 _T("Windows 8")
#define IS_OS_WIN8SERVER _T("Windows Server 2012")
#define IS_OS_WIN8ORSERVER _T("Windows 8 / Server 2012")
#define IS_OS_WIN81 _T("Windows 8.1")
#define IS_OS_WIN81_OR_LATER _T("Windows 8.1 or Windows 10")
#define IS_OS_WIN81SERVER _T("Windows Server 2012 R2")
#define IS_OS_WIN81ORSERVERR2 _T("Windows 8.1 / Server 2012 R2")
#define IS_OS_WIN10 _T("Windows 10")

// ISOSL Platform Constants
// Note: This list is also in ISRTDefs.h, the defintions must match. These
// constants are defined here since some projects don't have access to
// script header files.
#define ISOSL_ALL                               0x00000000
#define ISOSL_IGNORE                            0x40000000
#define ISOSL_WIN95                             0x00000010
#define ISOSL_WIN98                             0x00000040
#define ISOSL_WINME                             0x00000080
#define ISOSL_NT40                              0x00010000
#define ISOSL_NT40_ALPHA                        0x00020000
#define ISOSL_WIN2000                           0x00100000
#define ISOSL_WIN2000_ALPHA                     0x00200000
#define ISOSL_WINXP                             0x00400000
#define ISOSL_WINSERVER2003                     0x00800000
#define ISOSL_WINVISTA_SERVER2008               0x01000000
#define ISOSL_WINVISTA                          ISOSL_WINVISTA_SERVER2008
#define ISOSL_WIN7_SERVER2008R2                 0x02000000
#define ISOSL_WIN8                              0x04000000
#define ISOSL_WIN81								0x08000000
#define ISOSL_WIN10								0x10000000
#define ISOSL_SUPPORTED                         ( ISOSL_WIN95 | ISOSL_WIN98 | ISOSL_NT40 | ISOSL_WIN2000 | ISOSL_WINME | ISOSL_WINXP | ISOSL_WINSERVER2003 | ISOSL_WINVISTA | ISOSL_WIN7_SERVER2008R2 | ISOSL_WIN8 | ISOSL_WIN81 | ISOSL_WIN10 )

// UI Only (Not defined or used by script)
#define ISOSL_WINSERVER2008                     0x00000001
#define ISOSL_WINSERVER2008R2                   0x00000002
#define ISOSL_WIN8SERVER						0x00000004
#define ISOSL_WIN81SERVER						0x00000008

// Legacy UI platform constants, new code should use ISOSL_ constants directly.
#define IS_OS_WIN95_NUM                         ISOSL_WIN95
#define IS_OS_WIN98_NUM                         ISOSL_WIN98
#define IS_OS_WINME_NUM                         ISOSL_WINME
#define IS_OS_WINXP_NUM                         ISOSL_WINXP
#define IS_OS_WINNT4_NUM                        ISOSL_NT40
#define IS_OS_WIN2000_NUM                       ISOSL_WIN2000
#define IS_OS_WINSERVER2003_NUM                 ISOSL_WINSERVER2003
#define IS_OS_WINVISTA_NUM                      ISOSL_WINVISTA_SERVER2008
#define IS_OS_WIN7_NUM                          ISOSL_WIN7_SERVER2008R2
#define IS_OS_WIN8_NUM                          ISOSL_WIN8
#define IS_OS_WIN81_NUM							ISOSL_WIN81
#define IS_OS_WIN10_NUM							ISOSL_WIN10

// Note: IS_OS_ALL_SUPPORTED_NUM is all platforms considered "supported" in UI (i.e.) Win2K and later.
// Differs from ISOSL_SUPPORTED, which is all platforms not filtered by runtime. (i.e.) Win95/NT4 and later.
#define IS_OS_ALL_SUPPORTED_NUM                 ( ISOSL_WIN2000 | ISOSL_WINXP | ISOSL_WINSERVER2003 | ISOSL_WINVISTA_SERVER2008 | ISOSL_WIN7_SERVER2008R2  | ISOSL_WIN8 | ISOSL_WIN8SERVER | ISOSL_WIN81 | ISOSL_WIN81SERVER | ISOSL_WIN10 )

// UI Only (Not used by runtime)
#define IS_OS_WINSERVER2008_NUM                 ISOSL_WINSERVER2008
#define IS_OS_WINSERVER2008R2_NUM               ISOSL_WINSERVER2008R2
#define IS_OS_WIN8SERVER_NUM                    ISOSL_WIN8SERVER
#define IS_OS_WIN81SERVER_NUM					ISOSL_WIN81SERVER

//Web Local Path consts
#define WEBPATH_ADMINTOOLS  _T("[AdminToolsFolder]")
#define WEBPATH_APPDATAFOLDER  _T("[AppDataFolder]")
#define WEBPATH_COMMONAPPDATAFOLDER  _T("[CommonAppDataFolder]")
#define WEBPATH_COMMONDOCUMENTS  _T("[CommonDocuments]")
#define WEBPATH_LOCALAPPDATAFOLDER  _T("[LocalAppDataFolder]")
#define WEBPATH_PERSONALFOLDER  _T("[PersonalFolder]")
#define WEBPATH_PROGRAMFILESFOLDER  _T("[ProgramFilesFolder]")
#define WEBPATH_SYSTEMFOLDER  _T("[SystemFolder]")
#define WEBPATH_WINDOWSFOLDER  _T("[WindowsFolder]")
#define WEBPATH_DEFAULT  _T("[LocalAppDataFolder]Downloaded Installations")

//component GUIDs for MsiPackageDiff.exe - not sure what ISX and Admin component GUIDS will
//be so just use the ISWI one as placeholder.
#define ISWI_COMPONENT_GUID_MSIPACKAGEDIFF _T("{6734FE05-9840-440F-9915-850E582C2B90}")
#define ISWI_COMPONENT_GUID_MSIPACKAGEDIFF_ADMIN_STUDIO _T("{BE298F5B-F1F6-48F1-80C7-8962ECAF5508}")

// Always Install Feature Name For Express
#define EXPRESS_ALWAYSINSTALL  _T("AlwaysInstall")

// Directory Constants
#define ISMSI_DIR_INSTALLDIR  _T("INSTALLDIR")
#define ISMSI_DIR_DATABASEDIR  _T("DATABASEDIR")

// Quick Patch Build Constants
#define ISMSI_QPATCH_BUILD_FOLDER  _T("Patch")
#define ISMSI_QPATCH_BUILD_EXE  _T("Update.exe")
#define ISMSI_QPATCH_BUILD_MSP  _T("PatchPackage.msp")

// Registry Import
#define REG_IMPORT_INVALID_MASK  _T("**InvalidEntry**")

// Component .NET Installer Argument Constants
#define DNETINSTALLERARGS_DEFAULT  CComBSTR(L"/LogFile=")


#define OUTPUT_BUILDERROR_PREFIX_EXPRESS  _T("ISEXP : error ")
#define OUTPUT_BUILDFATALERROR_PREFIX_EXPRESS  _T("ISEXP : fatal error ")
#define OUTPUT_BUILDWARNING_PREFIX_EXPRESS  _T("ISEXP : warning ")
#define OUTPUT_DIRECT_MODE_SAVE_ERROR_PREFIX_EXPRESS _T("ISEXP : ")

#define OUTPUT_BUILDERROR_PREFIX  _T("ISDEV : error ")
#define OUTPUT_BUILDFATALERROR_PREFIX  _T("ISDEV : fatal error ")
#define OUTPUT_BUILDWARNING_PREFIX  _T("ISDEV : warning ")
#define OUTPUT_DIRECT_MODE_SAVE_ERROR_PREFIX _T("ISDEV : ")

#define OUTPUT_COMPILEERROR_PREFIX  _T(" : error ")
#define OUTPUT_COMPILEFATALERROR_PREFIX  _T(" : fatal error ")
#define OUTPUT_COMPILEWARNING_PREFIX  _T(" : warning ")
#define OUTPUT_COMPILE_FILE_PREFIX  _T(": File: ")

#define outScriptCompileError 1L
#define outScriptCompileFatalError 2L
#define outScriptCompileWarning 3L
#define outMediaBuildError 4L
#define outMediaBuildFatalError 5L
#define outMediaBuildWarning 6L
#define outMSIValidationError 7L
#define outMSIValidationWarning 8L
#define outMSIValidationFailure 9L
#define outMediaBuildMSIValidationError 10L
#define outMediaBuildMSIValidationWarning 11L
#define outMediaBuildMSIValidationFailure 12L
#define outMediaBuildUpgradeValidationError 13L
#define outMediaBuildUpgradeValidationWarning 14L
#define outMediaBuildUpgradeValidationFailure 15L


#define ISMSI_ADMINTOOLSFOLDER_RAW L"AdminToolsFolder" //
#define ISMSI_APPDATAFOLDER_RAW L"AppDataFolder" //
#define ISMSI_COMMONAPPDATAFOLDER_RAW L"CommonAppDataFolder" //
#define ISMSI_COMMONFILESFOLDER_RAW L"CommonFilesFolder" //
#define ISMSI_COMMONFILES64FOLDER_RAW L"CommonFiles64Folder" //
#define ISMSI_DATABASEDIR_RAW L"DATABASEDIR" //
#define ISMSI_DESKTOPFOLDER_RAW L"DesktopFolder" //
#define ISMSI_FAVOURITESFOLDER_RAW L"FavoritesFolder" //
#define ISMSI_FONTSFOLDER_RAW L"FontsFolder" //
#define ISMSI_INSTALLDIR_RAW L"INSTALLDIR" //
#define ISMSI_LOCALAPPDATAFOLDER_RAW L"LocalAppDataFolder" //
#define ISMSI_MYPICTURESFOLDER_RAW L"MyPicturesFolder" //
#define ISMSI_PERSONALFOLDER_RAW L"PersonalFolder" //
#define ISMSI_PRIMARYVOLUMEPATH_RAW L"PrimaryVolumePath" //
#define ISMSI_PROGRAMFILESFOLDER_RAW L"ProgramFilesFolder" //
#define ISMSI_PROGRAMFILES64FOLDER_RAW L"ProgramFiles64Folder" //
#define ISMSI_PROGRAMMENUFOLDER_RAW L"ProgramMenuFolder" //
#define ISMSI_SENDTOFOLDER_RAW L"SendToFolder" //
#define ISMSI_STARTMENUFOLDER_RAW L"StartMenuFolder" //
#define ISMSI_STARTUPFOLDER_RAW L"StartupFolder" //
#define ISMSI_SYSTEM16FOLDER_RAW L"System16Folder" //
#define ISMSI_SYSTEMFOLDER_RAW L"SystemFolder" //
#define ISMSI_SYSTEM64FOLDER_RAW L"System64Folder" //
#define ISMSI_TEMPFOLDER_RAW L"TempFolder" //
#define ISMSI_TEMPLATEFOLDER_RAW L"TemplateFolder" //
#define ISMSI_WINDOWSFOLDER_RAW L"WindowsFolder" //
#define ISMSI_TASKBARFOLDER_RAW L"TaskBarFolder" //
#define ISMSI_WINDOWSVOLUME_RAW L"WindowsVolume" //
#define ISMSI_GAC_RAW L"GlobalAssemblyCache" //
#define ISMSI_USERPROFILE_RAW L"USERPROFILE" //
#define ISMSI_ALLUSERSPROFILE_RAW L"ALLUSERSPROFILE"  //
#define ISMSI_RECENTFOLDER_RAW L"RecentFolder" //
#define ISMSI_PRINTHOODFOLDER_RAW L"PrintHoodFolder"  //
#define ISMSI_NETHOODFOLDER_RAW L"NetHoodFolder" //

#define ISMSI_ADMINTOOLSFOLDER_L L"[AdminToolsFolder]" //
#define ISMSI_APPDATAFOLDER_L L"[AppDataFolder]" //
#define ISMSI_COMMONAPPDATAFOLDER_L L"[CommonAppDataFolder]" //
#define ISMSI_COMMONFILESFOLDER_L L"[CommonFilesFolder]" //
#define ISMSI_COMMONFILES64FOLDER_L L"[CommonFiles64Folder]" //
#define ISMSI_DATABASEDIR_L L"[DATABASEDIR]" //
#define ISMSI_DESKTOPFOLDER_L L"[DesktopFolder]" //
#define ISMSI_FAVOURITESFOLDER_L L"[FavoritesFolder]" //
#define ISMSI_FONTSFOLDER_L L"[FontsFolder]" //
#define ISMSI_INSTALLDIR_L L"[INSTALLDIR]" //
#define ISMSI_LOCALAPPDATAFOLDER_L L"[LocalAppDataFolder]" //
#define ISMSI_MYPICTURESFOLDER_L L"[MyPicturesFolder]" //
#define ISMSI_PERSONALFOLDER_L L"[PersonalFolder]" //
#define ISMSI_PRIMARYVOLUMEPATH_L L"[PrimaryVolumePath]" //
#define ISMSI_PROGRAMFILESFOLDER_L L"[ProgramFilesFolder]" //
#define ISMSI_PROGRAMFILES64FOLDER_L L"[ProgramFiles64Folder]" //
#define ISMSI_PROGRAMMENUFOLDER_L L"[ProgramMenuFolder]" //
#define ISMSI_SENDTOFOLDER_L L"[SendToFolder]" //
#define ISMSI_STARTMENUFOLDER_L L"[StartMenuFolder]" //
#define ISMSI_STARTUPFOLDER_L L"[StartupFolder]" //
#define ISMSI_SYSTEM16FOLDER_L L"[System16Folder]" //
#define ISMSI_SYSTEMFOLDER_L L"[SystemFolder]" //
#define ISMSI_SYSTEM64FOLDER_L L"[System64Folder]" //
#define ISMSI_TEMPFOLDER_L L"[TempFolder]" //
#define ISMSI_TEMPLATEFOLDER_L L"[TemplateFolder]" //
#define ISMSI_WINDOWSFOLDER_L L"[WindowsFolder]" //
#define ISMSI_TASKBARFOLDER_L L"[TaskBarFolder]" //
#define ISMSI_WINDOWSVOLUME_L L"[WindowsVolume]" //
#define ISMSI_GAC_L L"[GlobalAssemblyCache]" //

#define ISMSI_SUMMARYINFORMATION  _T("Summary Information")
#define ISMSI_TOOLS_OPTIONS_REFERENTIAL_INTEGRITY_SETTING_CHANGED  _T("DirectEditRISettingChanged")
#define ISMSI_COMPLETED_MSI_DIFF  _T("DiffCompleted")
#define ISPRO_DEFAULT_PC  _T("Media")
#define ISPRO_PKG_DIR  _T("Package")
#define ISPRO_FILENAME_DEMOSHIELD_PLAYER  _T("Demo32.exe")
#define ISPRO_FILENAME_DEFAULT_WEBPAGE  _T("Setup.htm")
#define LANG_URL  _T("http://www.installshield.com/products/installshield/premier/default.asp")
#define ISMSI_PROJECTSETTINGS_PROJECT_CHANGED  _T("ProjectSettingsProjectChanged")
#define ISMSI_PROJECTSETTINGS_PRODUCT_CHANGED  _T("ProjectSettingsProductChanged")
#define ISMSI_PROJECTSETTINGS_LANGS_CHANGED  _T("ProjectSettingsLangsChanged")
#define ISMSI_PROJECTSETTINGS_PROOBJECT_CHANGED  _T("ProjectSettingsProObjectChanged")
#define ISMSI_PROJECTSETTINGS_PROOBJECT_LANGDEPENDENT_CHANGED  _T("ProjectSettingsProObjectLangDependentChanged")
#define ISMSI_PROJECTSETTINGS_MSI45EMBEDDEDUI_CHANGED  _T("ProjectSettingsUseMSI45EmbeddedUIChanged")
#define UPDATESERVICE_URL  _T("http://www.installshield.com/isus/")

#define ISMSI_RELEASESETTINGS_RELEASETYPE_CHANGED  _T("ReleaseSettingsReleaseTypeChanged")
#define ISMSI_RELEASESETTINGS_CREATESETUPEXE_CHANGED  _T("ReleaseSettingsCreateSetupExeChanged")
#define ISMSI_RELEASESETTINGS_WEBTYPE_CHANGED  _T("ReleaseSettingsWebTypeChanged")
#define ISMSI_RELEASESETTINGS_MEDIATYPE_CHANGED  _T("ReleaseSettingsMediaTypeChanged")
#define ISMSI_RELEASESETTINGS_DOTNETVERSION_CHANGED  _T("ReleaseSettingsDotNetVersionChanged")

#define ISMSI_SWIDTAG_SYSTEM_COMPONENT_CREATED  _T("SwidtagSystemComponentCreated")
#define ISMSI_SWIDTAG_LOCAL_COMPONENT_CREATED  _T("SwidtagLocalComponentCreated")

#define EXPORT_COMPONENT_LIST_SEPARATOR _T(";")
#define EXPORT_COMPONENT_LIST_SEPARATOR_W L";" //

#define INSTALLSHIELD_CURRENT_MEDIA  _T("CurrentMedia")
#define INSTALLSHIELD_CURRENT_MEDIA_L  L"CurrentMedia" //

#define NAVFILE_RELEASE_VIEW L"viewRelease" //
#define NAVFILE_SYSTEM_SEARCH_VIEW L"viewSystemSearch" //
#define NAVFILE_SETUP_DESIGN_VIEW L"viewSetupDesign" //
#define NAVFILE_USER_INTERFACE_VIEW L"viewUI" //

#define NAVFILE_UPDATESERVICE_VIEW L"viewUpdateService" //
#define NAVFILE_PRO_OBJECTS_VIEW L"viewObjectsPro" //
#define NAVFILE_REGISTRY_VIEW L"viewRegistry" //
#define NAVFILE_SHORTCUTS_VIEW L"viewShortcuts" //
#define NAVFILE_GENERAL_INFORMATION_VIEW L"viewProject" //
#define NAVFILE_APPLICATION_FILES_VIEW L"viewAppFiles" //
#define NAVFILE_FEATURE_FILES_VIEW L"viewFeatureFiles" //
#define NAVFILE_FILE_EXTENSION_VIEW L"viewFileExtensions" //
#define NAVFILE_USER_INTERFACE_VIEW_STD L"viewUIStd" //
#define NAVFILE_SMART_DEVICE L"viewSmartDevice" //
#define NAVFILE_ACTIVATION L"viewActivation" //

#define NAVFILE_FILTER_CLOSED L"closed" //
#define NAVFILE_FILTER_OPEN L"open" //
#define NAVFILE_FILTER_OPEN_STD L"openScript" //
#define NAVFILE_FILTER_OPEN_MSI L"openMSI" //
#define NAVFILE_FILTER_OPEN_MM L"openMM" //
#define NAVFILE_FILTER_NOCHECK L"nocheck" //
#define NAVFILE_FILTER_OPEN_QP L"openQP" //
#define NAVFILE_FILTER_OPEN_MM_DIRECT L"openMMDirect" //
#define NAVFILE_FILTER_OPEN_CE L"openCE" //
#define NAVFILE_FILTER_OPEN_PCP L"openPcp" //
#define NAVFILE_FILTER_OPEN_PRO L"openPro" //
#define NAVFILE_FILTER_OPEN_PRO_OBJ L"openProObj" //
#define NAVFILE_FILTER_OPEN_LITE L"openLite" //
#define NAVFILE_FILTER_OPEN_CLICKONCE L"openClickOnce" //
#define NAVFILE_FILTER_OPEN_MSP L"openMSP" //

#define DISTRIBUTE_VIEW_WORKSPACE_ID L"ISXDistribute" //
#define DISTRIBUTE_VIEW_FTP_USER_NAME L"FTPUserName" //
#define DISTRIBUTE_VIEW_FTP_USER_PASSWORD L"FTPUserPassword" //

#define DEFAULT_OBJPRJ_COMPILELINK_PREPROC  _T("IFX_OBJECTS")
#define DEFAULT_IFX_OBL  _T("ifx.obl")
#define DEFAULT_IFXOBJ_OBL  _T("ifxobject.obl")

//================================================
// strings used in pro projects (installscript) ISString table template
#define PRO_STRING1 _T("IDPROP_SETUPTYPE_CUSTOM")
#define PRO_STRING2 _T("IDPROP_SETUPTYPE_COMPLETE")
#define PRO_STRING3 _T("IDPROP_SETUPTYPE_COMPLETE_DESC")
#define PRO_STRING4 _T("IDPROP_SETUPTYPE_CUSTOM_DESC_PRO")
#define PRO_STRING5 _T("IDS_SQLSCRIPT_INSTALLING")
#define PRO_STRING6 _T("IDS_SQLSCRIPT_UNINSTALLING")

#define ISMSI_SCRIPTPROJECT_BLANKSCRIPT _T("BlankSetup.Rul")
#define ISMSI_SCRIPTPROJECT_BLANKMMSCRIPT _T("SetupTmplMM.rul")
#define ISMSI_SCRIPTPROJECT_SCRIPTNAME _T("Setup.Rul")
#define ISMSI_PRO_BLANKSCRIPT _T("BlankProSetup.rul")
#define ISMSI_PROOBJ_BLANKSCRIPT _T("BlankProObjSetup.rul")
#define ISMSI_SCRIPTFILES_DIR _T("Script Files")

//==================================================
// Quick Patch Constants
#define QUICKPATCH_BUILDUPGRADEDIMAGEFOLDER _T("BuildUpgradedImageFolder")
#define QUICKPATCH_LISTOFPATCHGUIDSTOREPLACE _T("ListOfPatchGUIDsToReplace")
#define QUICKPATCH_EXCLUDEDCUSTOMACTIONS _T("ExcludedCustomActions")

//==================================================
// CEIP
#define CEIP_CAT_PROJECT_TYPE  L"Type" //
#define CEIP_KEY_PROJECT_TYPE_CREATE  L"Create" //
#define CEIP_KEY_PROJECT_TYPE_OPEN  L"Open" //

#define CEIP_CAT_VIEW  L"View" //
#define CEIP_KEY_IDE_IS  L"IS" //
#define CEIP_KEY_IDE_VS  L"VS" //

#define CEIP_CAT_BUILD_COUNT  L"Count" //
#define CEIP_KEY_BUILD_COUNT_COMPONENTS  L"Components" //
#define CEIP_KEY_BUILD_COUNT_FILES  L"Files" //

#define CEIP_CAT_BUILD_MSM  L"MergeModule" //

#define CEIP_CAT_BUILD_HELP  L"Help" //

#define CEIP_CAT_BUILD_DOT_NET  L"DotNet" //
#define CEIP_CAT_BUILD_DOT_NET_INSTALLER (0)
#define CEIP_CAT_BUILD_DOT_NET_BUILD_DEP_SCAN (1)
#define CEIP_CAT_BUILD_DOT_NET_DEPLOY_FRAMEWORK (2)

#define CEIP_CAT_PROJECT_OPTIONS L"Project"
#define CEIP_KEY_PROJECT_THEME L"Theme"

#define SHORTCUT_DISPLAYNAME_TEMPLATE  L"IDS_SHORTCUT_DISPLAY_NAME" //
#define FEATURE_DISPLAYNAME_TEMPLATE  L"IDS_FEATURE_DISPLAY_NAME" //
#define PRODUCT_DISPLAYNAME_TEMPLATE  L"IDS_PRODUCT_DISPLAY_NAME" //
#define REQUIREMENT_MESSAGE_TEMPLATE  L"IDS_SOFTWARE_REQUIREMENT_MESSAGE" //

#define ISMSI_EXPORT_COMPS_DELETE_COMPLETED  _T("ExportComponents_DelCompsFinished")

#define SQL_DEFAULT_DATABASE_SERVER  _T("MSSQLServer")

#define TW_MSG_PATHNOTFOUND  _T("Path not found. Create Folder?")
#define TW_MSG_PATHNOTFOUND_DLG_TITLE  _T("Confirmation")

// Device driver support
#define DEVICE_DRIVER_CA_DLL  L"Difxapp.dll" //
#define DEVICE_DRIVER_CA_DLL_A  L"Difxappa.dll" //
#define DEVICE_DRIVER_CA_DLL_REDIST_LOCATION  L"<ISProductFolder>\\redist\\0409\\i386\\%s" //
#define DEVICE_DRIVER_CA_DLL_REDIST_LOCATION_LOCALIZED  L"<ISProductFolder>\\redist\\Language Independent\\i386\\%s" //
#define DEVICE_DRIVER_CA_DLL_REDIST_LOCATION_I64  L"<ISProductFolder>\\redist\\0409\\i64\\%s" //
#define DEVICE_DRIVER_CA_DLL_REDIST_LOCATION_I64_LOCALIZED  L"<ISProductFolder>\\redist\\Language Independent\\i64\\%s" //
#define DEVICE_DRIVER_CA_DLL_REDIST_LOCATION_X64  L"<ISProductFolder>\\redist\\0409\\x64\\%s" //
#define DEVICE_DRIVER_CA_DLL_REDIST_LOCATION_X64_LOCALIZED  L"<ISProductFolder>\\redist\\Language Independent\\x64\\%s" //
#define DEVICE_DRIVER_FORCE_INSTALLATION 1L
#define DEVICE_DRIVER_HIDE_NOT_CONNECTED_DLG 2L
#define DEVICE_DRIVER_NO_ARP_ENTRY 4L
#define DEVICE_DRIVER_ALLOW_UNSIGNED 8L
#define DEVICE_DRIVER_REMOVE_BINARY 16L

#define TOOLS_OPTIONS_DIR_SETTINGS  _T("ToolsOptionsDirectorySettings")

// DirectX9
#define DX9C_FOLDER _T("DirectX9c")

// custom RaiseItemChangeEvent
#define IS_EVENT_INSTALLSCRIPT_FUNCTION_CHANGED  _T("IS_EVENT_INSTALLSCRIPT_FUNCTION_CHANGED")

#define INSTANCEID L"InstanceId"

// General
#define IS_MAX_PATH                   1024
#define WM_CANCEL                     WM_APP + 50
#define BRANDING_SIZE 21

#ifdef UNICODE
#define _T_API(Api) (Api "W")
#else
#define _T_API(Api) (Api "A")
#endif

// Events/Dialog Source
#define SCRIPT_EVENT_FILE_PATH_ISP      L"script\\ifx\\src\\EventsSetup.rul"
#define SCRIPT_EVENT_FILE_PATH_ISMSI    L"script\\iswi\\src\\EventsConv.rul"
#define DIALOG_SOURCE_FILE_PATH         L"script\\ISRT\\src\\ISRTScriptDialogs.rul"

// Flags for the VSI converter
#define FLAG_VSICONVERT_PRODUCTNAME			0x00000001L
#define FLAG_VSICONVERT_PRODUCTVERSION		0x00000002L
#define FLAG_VSICONVERT_PRODUCTCODE			0x00000004L
#define FLAG_VSICONVERT_UPGRADECODE			0x00000008L
#define FLAG_VSICONVERT_DEFAULTLOCATION		0x00000010L
#define FLAG_VSICONVERT_ARP_PROPS			0x00000020L
#define FLAG_VSICONVERT_SIS_PROPS			0x00000040L
#define FLAG_VSICONVERT_ALLUSERS			0x00000080L
#define FLAG_VSICONVERT_SIGNATURE			0x00000100L
#define FLAG_VSICONVERT_LANGUAGE			0x00000200L

// Kill Process Custom Action
#define UPGRADE_SETALLUSERS_PATH L"<ISRedistPlatformDependentFolder>\\SetAllUsers.dll" //
#define UPGRADE_SETALLUSERS_FILE L"SetAllUsers.dll" //
#define FUNC_NAME_KILLPROCESS L"KillProcess" //
#define FUNC_NAME_KILLPROCESS_BY_ID L"KillProcessByID" //
#define FUNC_NAME_KILLPROCESS_DEFER L"KillProcessDeferred" //
#define FUNC_NAME_KILLPROCESS_BY_ID_DEFER L"KillProcessByIDDeferred" //

//================================================
// Predefined path variable names, without delimiters.
#define PD_COMMONFILESFOLDER L"CommonFilesFolder"
#define PD_PROGRAMFILESFOLDER L"ProgramFilesFolder"
#define PD_SYSTEMFOLDER L"SystemFolder"
#define PD_WINDOWSFOLDER L"WindowsFolder"
#define PD_VSSOLUTIONFOLDER L"VSSolutionFolder"
#define PD_ISPROJECTFOLDER L"ISProjectFolder"
#define PD_ISPRODUCTFOLDER L"ISProductFolder"
#define PD_ISPROJECTDATAFOLDER L"ISProjectDataFolder"
#define PD_ISPROJECTDIR L"ISPROJECTDIR"
#define PD_ISREDISTPLTFRMDEPFOLDER L"ISRedistPlatformDependentFolder"
#define PD_ISREDISTPLTFRMDEPEXPFOLDER L"ISRedistPlatformDependentExpressFolder"

//================================================
// Shortcut properties
#define PREDEF_SHORTCUT_PROP_PREVENTPINNING_KEY L"{9F4C2855-9F79-4B39-A8D0-E1D42DE1D5F3}, 9"
#define PREDEF_SHORTCUT_PROP_STARTPINOPTION_KEY L"{9F4C2855-9F79-4B39-A8D0-E1D42DE1D5F3}, 12"
#define PREDEF_SHORTCUT_PROP_STARTPINOPTION_FRIENDLY_KEY L"System.AppUserModel.StartPinOption"
#define PREDEF_SHORTCUT_PROP_EXCLUDEFROMNEWINSTALL_KEY L"{9F4C2855-9F79-4B39-A8D0-E1D42DE1D5F3}, 8"


// WiseScript Custom Action
#define WSEWRAP_BINARY_DLLKEY L"WiseScriptBridge.dll"
#define WSEWRAP_BINARY_DLLPATH L"<ISProductFolder>\\redist\\language independent\\i386\\WiseScriptBridge.dll"


#endif //Remove in .cs
