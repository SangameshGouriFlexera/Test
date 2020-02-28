#ifndef modConstPErrors_H //Remove in .cs
#define modConstPErrors_H //Remove in .cs
//Option Explicit

#ifndef _VBOBJECTERROR_ //Remove in .cs
#define _VBOBJECTERROR_ //Remove in .cs
const long vbObjectError = -2147221504L;
#endif //Remove in .cs

#define ISMSI_ERR_SUCCESS (0) // Successful operation
#define ISMSI_ERR_GENERAL (-1) // General/Undefined error
#define ISMSI_ERR_BUILDABORTED (-32000) // Build was prematurely abored by end-user

#define ISMSI_ERR_PKG_GENERAL (-3001)
#define ISMSI_ERR_PKG_INVALIDFIELD (-3003) // Field number is invalid
#define ISMSI_ERR_PKG_KEYEXISTS (-3004) // Key Exists
#define ISMSI_ERR_PKG_INVALIDOP (-3005) // Invalid Operation
#define ISMSI_ERR_PKG_INITREQUIRED (-3006) // Initialization Required
#define ISMSI_ERR_PKG_REINIT (-3007) // Cannot reinitialize
#define ISMSI_ERR_PKG_NOTPRESENT (-3008) // Key/Item not present
#define ISMSI_ERR_PKG_NOTEXIST (-3008) // Key/Item does not exist
#define ISMSI_ERR_PKG_INVALIDROOT (-3009) // Invalid Root object

#define ISMSI_ERR_PKG_INVALIDOBJ (-3010) // Invalid Object

#define ISMSI_ERR_PKG_CREATERECORD (-3011) // Failed to Create new record
#define ISMSI_ERR_PKG_ADDBINARYDATA (-3012) // Failed to Add Binary Data
#define ISMSI_ERR_PKG_ADDSTRINGDATA (-3013) // Failed to Add String Data
#define ISMSI_ERR_PKG_ADDINTEGERDATA (-3014) // Failed to add Integer Data
#define ISMSI_ERR_PKG_RUNQUERY (-3015) // Failed to execute a Query
#define ISMSI_ERR_PKG_MODIFYRECORD (-3016) // Failed to Update/modify a record

#define ISMSI_ERR_PKG_INVALIDFEATURE (-3017) // Invalid Feature Name
#define ISMSI_ERR_PKG_INVALIDKEYPATH (-3018) // Invalid Key Path
#define ISMSI_ERR_PKG_INITICONEXTRACTOR (-3019) // Failed to initialize Icon Extractor

#define ISMSI_ERR_PKG_FETCHRECORD (-3020) // Failed to fetch a record based on the query
#define ISMSI_ERR_PKG_CANCELUPDATE (-3021) // Failed to cancel an update operation

#define ISMSI_ERR_PKG_GETBINARYDATA (-3022) // Failed to get Binary Data
#define ISMSI_ERR_PKG_GETSTRINGDATA (-3023) // Failed to get String Data
#define ISMSI_ERR_PKG_GETINTEGERDATA (-3024) // Failed to get Integer Data
#define ISMSI_ERR_PKG_TABLEDOESNOTEXIST (-3025) // Table does not exist
#define ISMSI_ERR_PKG_WRITE_BINARYDATA (-3031) // Failed to stream out binary data

#define ISMSI_ERR_PKG_FULLPATH (-3026) // Absolute path used instead of Relative path
#define ISMSI_ERR_PKG_INSTALLDIR (-3027) // INSTALLDIR is not a valid entry for the Product Default Destination
#define ISMSI_ERR_STRID (-3028) //Cannot find strID in string table
#define ISMSI_ERR_DLG_NOT_IN_ISS (-3029) //Cannot find dialog in .iss file
#define ISMSI_ERR_TEXTSTYLE_MISSING (-3030) //TextStyle not found in ism or isd
#define ISMSI_ERR_PKG_DATABASEDIR = -3031                   // DATABASEDIR is not a valid entry for the Product #define ISMSI_ERR_PKG_INSTALLDIR (-3027                   ' INSTALLDIR is not a valid entry for the Product Public Const ISMSI_ERR_PKG_INSTALLDIR (-3027) ) ' INSTALLDIR is not a valid entry for the Product DATABASEDIR

//   Table Specific Error Codes - 25 error values per table


//   AppPath table Error Codes
#define ISMSI_ERR_PKG_APPPATH_INIT (-3100) // Failed to initialize App Path Class
#define ISMSI_ERR_PKG_APPPATH_COLLECTINFO (-3101) // Failed to read APP Path Data
#define ISMSI_ERR_PKG_APPPATH_UPDATE_FILEKEY (-3102) // Failed to create Primary Key for file name
#define ISMSI_ERR_PKG_APPPATH_COMPNAME (-3103) // Failed to add component alias
#define ISMSI_ERR_PKG_APPPATH_ALIAS (-3104) // Failed to determine Key Aliases
#define ISMSI_ERR_PKG_APPPATH_REGKEY (-3105) // Failed to add registry key
#define ISMSI_ERR_PKG_APPPATH_REGROOT (-3106) // Failed to add registry root
#define ISMSI_ERR_PKG_APPPATH_DEFAULT (-3107) // Failed to add file name (value name in reg key)
#define ISMSI_ERR_PKG_APPPATH_FILENAME (-3108) // Failed to update file name
#define ISMSI_ERR_PKG_APPPATH_FILERECORD (-3109) // Failed to update file record
#define ISMSI_ERR_PKG_APPPATH_UPDATE_PATHKEY (-3110) // Failed to update primary key for path
#define ISMSI_ERR_PKG_APPPATH_UPDATE_PATHNAME (-3111) // Failed to update path name (value name in reg key)
#define ISMSI_ERR_PKG_APPPATH_UPDATE_PATHVALUE (-3112) // Failed to update path value
#define ISMSI_ERR_PKG_APPPATH_PATHRECORD (-3113) // Failed to modify record for path
#define ISMSI_ERR_PKG_APPPATH_PATH_NOT_FOUND (-3114) //component destination not in app path

//   Class table Error Codes
#define ISMSI_ERR_PKG_CLASS_INIT (-3125) // Failed to initialize class
#define ISMSI_ERR_PKG_CLASS_REINIT (-3126) // Cannot reinitialize a class!
#define ISMSI_ERR_PKG_CLASS_UNINIT (-3127) // Failed to uninitialize a class
#define ISMSI_ERR_PKG_CLASS_INVALIDCLASS (-3128) // Invalid Class Name
#define ISMSI_ERR_PKG_CLASS_INVALIDOBJ (-3129) // Failed to determine object handle for context/Class
#define ISMSI_ERR_PKG_CLASS_NOOFCONTEXTS (-3130) // Invalid number of Context Items
#define ISMSI_ERR_PKG_CLASS_COLLECTCLASSINFO (-3131) // Failed to collect COMClass Info
#define ISMSI_ERR_PKG_CLASS_EXTRACTICON (-3132) // Failed to Extract Icon from the Icon file
#define ISMSI_ERR_PKG_CLASS_COLLECTCONTEXTINFO (-3133) // Failed to collect Context information
#define ISMSI_ERR_PKG_CLASS_ADDCLSID (-3134) // Failed to add CLSID Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDCONTEXT (-3135) // Failed to add Context Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDPROGID (-3136) // Failed to add ProgID Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDDESC (-3137) // Failed to add Description  Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDINSERT (-3138) // Failed to add Insertable Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDAPPID (-3139) // Failed to add APPID Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDFTMASK (-3140) // Failed to add FileType Mask Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDICONNAME (-3141) // Failed to add Icon Name Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDICONINDEX (-3142) // Failed to add Icon Index Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDPROCHANDLER (-3143) // Failed to add DefProcHandler Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDARG (-3144) // Failed to add Arguments Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDFEATURE (-3145) // Failed to add Feature Field Entry
#define ISMSI_ERR_PKG_CLASS_ADDCOMP (-3146) // Failed to add Components Field Entry
#define ISMSI_ERR_PKG_ICON_KEYPATH (-3147) // Failed to get Key path to extract Icon from
#define ISMSI_ERR_PKG_CLASS_ADDATTR (-3148) // Failed to add attributes Field Entry

//   Typelib  (Adding/Extracting Icons) table
#define ISMSI_ERR_PKG_TYPELIB_INIT (-3175)
#define ISMSI_ERR_PKG_TYPELIB_REINIT (-3176)
#define ISMSI_ERR_PKG_TYPELIB_UNINIT (-3178)
#define ISMSI_ERR_PKG_TYPELIB_INVALIDOBJ (-3179)
#define ISMSI_ERR_PKG_TYPELIB_COLLECTTYPELIBINFO (-3180)
#define ISMSI_ERR_PKG_TYPELIB_COLLECTLANGINFO (-3181)
#define ISMSI_ERR_PKG_TYPELIB_ADDCOMP (-3182)
#define ISMSI_ERR_PKG_TYPELIB_ADDDESC (-3183)
#define ISMSI_ERR_PKG_TYPELIB_ADDDIR (-3184)
#define ISMSI_ERR_PKG_TYPELIB_ADDFEAT (-3185)
#define ISMSI_ERR_PKG_TYPELIB_ADDLIBID (-3186)
#define ISMSI_ERR_PKG_TYPELIB_ADDCOST (-3187)
#define ISMSI_ERR_PKG_TYPELIB_ADDLANG (-3188)
#define ISMSI_ERR_PKG_TYPELIB_ADDVER (-3189)
#define ISMSI_ERR_PKG_TYPELIB_HELPDIR (-3190) // Failed to get Directory Alias for Help Directory
#define ISMSI_ERR_PKG_TYPELIB_INVALIDVERSION (-3191) // Invalid version number.

//   Icon (Adding/Extracting Icons) table
#define ISMSI_ERR_PKG_ICON_REINIT (-3200) // Cannot reinitialize IsIcon Module
#define ISMSI_ERR_PKG_ICON_WIN95EXTRACT (-3201) // Icon Extraction not allowed on Windows 95
#define ISMSI_ERR_PKG_ICON_ADDICON (-3202) // Failed to add Icon File (file with extension .ICO)
#define ISMSI_ERR_PKG_ICON_ADDDLL (-3203) // Cannot use resource ONLY DLL for icons
#define ISMSI_ERR_PKG_ICON_INVALID (-3204) // This is not a valid icon or EXE file
                                                            // (MSI does not allow it.  Only .ICO or .EXE files supported)
#define ISMSI_ERR_PKG_ICON_WIN9X (-3205) // On Win 9x platforms, if there is no icon file specified, it
                                                            //uses the default icon in the resource only exe file

//   ProgID Table Error Codes
#define ISMSI_ERR_PKG_PROGID_INIT (-3225)
#define ISMSI_ERR_PKG_PROGID_REINIT (-3226)
#define ISMSI_ERR_PKG_PROGID_UNINIT (-3227)
#define ISMSI_ERR_PKG_PROGID_INVALIDOBJ (-3228)
#define ISMSI_ERR_PKG_PROGID_INVALIDCLASS (-3229)
#define ISMSI_ERR_PKG_PROGID_COLLECTINFO (-3230)
#define ISMSI_ERR_PKG_PROGID_ADDPROGID (-3231)
#define ISMSI_ERR_PKG_PROGID_ADDPARENT (-3232)
#define ISMSI_ERR_PKG_PROGID_ADDCLASS (-3233)
#define ISMSI_ERR_PKG_PROGID_ADDDESC (-3234)
#define ISMSI_ERR_PKG_PROGID_ADDDICON (-3235)
#define ISMSI_ERR_PKG_PROGID_ADDDICONINDEX (-3236)
#define ISMSI_ERR_PKG_PROGID_ADDDINSERTABLE (-3237)

//   Extension and Verb Table Error Codes
#define ISMSI_ERR_PKG_EXTVERB_INIT (-3250)
#define ISMSI_ERR_PKG_EXTVERB_REINIT (-3251)
#define ISMSI_ERR_PKG_EXTVERB_UNINIT (-3252)
#define ISMSI_ERR_PKG_EXTVERB_INVALIDOBJ (-3253)
#define ISMSI_ERR_PKG_EXTVERB_GETEXT (-3256)
#define ISMSI_ERR_PKG_EXTVERB_COLLECTEXTINFO (-3257)
#define ISMSI_ERR_PKG_EXTVERB_COLLECTVERBINFO (-3258)
#define ISMSI_ERR_PKG_EXTVERB_ADDCOMP (-3259)
#define ISMSI_ERR_PKG_EXTVERB_ADDEXT (-3260)
#define ISMSI_ERR_PKG_EXTVERB_ADDFEAT (-3261)
#define ISMSI_ERR_PKG_EXTVERB_ADDPROGID (-3263)
#define ISMSI_ERR_PKG_EXTVERB_ADDSHELLNEW (-3264)
#define ISMSI_ERR_PKG_EXTVERB_ADDSHELLNEWVAL (-3265)
#define ISMSI_ERR_PKG_EXTVERB_ADDVERB (-3266)
#define ISMSI_ERR_PKG_EXTVERB_ADDARG (-3267)
#define ISMSI_ERR_PKG_EXTVERB_ADDCMD (-3268)
#define ISMSI_ERR_PKG_EXTVERB_ADDSEQ (-3269)
#define ISMSI_ERR_PKG_EXTVERB_ADDMIME (-3270)

//   MIME Table Error Codes
#define ISMSI_ERR_PKG_MIME_INIT (-3275)
#define ISMSI_ERR_PKG_MIME_REINIT (-3276)
#define ISMSI_ERR_PKG_MIME_UNINIT (-3277)
#define ISMSI_ERR_PKG_MIME_INVALIDOBJ (-3278)
#define ISMSI_ERR_PKG_MIME_COLLECTINFO (-3279)
#define ISMSI_ERR_PKG_MIME_ADDCONTENT (-3280)
#define ISMSI_ERR_PKG_MIME_ADDCLASS (-3281)
#define ISMSI_ERR_PKG_MIME_ADDCLSID (-3282)

//   Publish Component Table Error Codes
#define ISMSI_ERR_PKG_PUBCOMP_INIT (-3300)
#define ISMSI_ERR_PKG_PUBCOMP_REINIT (-3301)
#define ISMSI_ERR_PKG_PUBCOMP_UNINIT (-3302)
#define ISMSI_ERR_PKG_PUBCOMP_INVALIDOBJ (-3303)
#define ISMSI_ERR_PKG_PUBCOMP_COLLECTINFO (-3304)
#define ISMSI_ERR_PKG_PUBCOMP_APPDATA (-3305)
#define ISMSI_ERR_PKG_PUBCOMP_ADDCOMP (-3306)
#define ISMSI_ERR_PKG_PUBCOMP_FEATURE (-3307)
#define ISMSI_ERR_PKG_PUBCOMP_LIBID (-3308)
#define ISMSI_ERR_PKG_PUBCOMP_QUALIFIER (-3309)

// -------------------------------------------------------------------------------------
//   Component Table Error Codes
#define ISMSI_ERR_PKG_COMP_INVALIDDIRFORMAT (-3400)
#define ISMSI_ERR_PKG_COMP_NOGUID (-3401) // Failed to find GUID for a component
#define ISMSI_ERR_PKG_COMP_SKIP (-3402)

// -------------------------------------------------------------------------------------
//   Dialog table error codes
#define ISMSI_ERR_PKG_DIALOG_INIT (-3500) // Failed to initialize Dialog Class
#define ISMSI_ERR_PKG_DIALOG_REINIT (-3501) // Failed to reinitialize Dialog Class
#define ISMSI_ERR_PKG_DIALOG_UPDATE (-3502) // Failed to build Dialog table
#define ISMSI_ERR_PKG_DIALOG_READING_LICENSE (-3503) // Failed to read the License file
#define ISMSI_ERR_PKG_DIALOG_GETDIALOGARRAY (-3504) // Failed to get the dialog layout from the ism file
#define ISMSI_ERR_PKG_DIALOG_COLLECTDLGINFO (-3505) // Failed to collect dialog data
#define ISMSI_ERR_PKG_DIALOG_INSTALLSEQUENCE (-3606) // Failed to update install sequence
#define ISMSI_ERR_PKG_DIALOG_CONTROLARRAY (-3607) // Failed to get the control list for the dialog
#define ISMSI_ERR_PKG_DIALOG_COLLECTCTRLINFO (-3608) // Failed to control information
#define ISMSI_ERR_PKG_DIALOG_UPDATECONTROL (-3609) // Failed to update control table
#define ISMSI_ERR_PKG_DIALOG_PROCESSCTRLEVENTS (-3610) // Failed to process the control events table
#define ISMSI_ERR_PKG_DIALOG_READING_BITMAP (-3611) // Failed to read the Welcome Bitmap

// -------------------------------------------------------------------------------------
//   CustomAction table error codes
#define ISMSI_ERR_PKG_CUSTOM_ACTION_INIT (-3700) // Failed to initialize CustomAction Class
#define ISMSI_ERR_PKG_CUSTOM_ACTION_REINIT (-3701) // Failed to reinitialize CustomAction Class
#define ISMSI_ERR_PKG_CUSTOM_ACTION_UPDATE (-3702) // Failed to build CustomAction table
#define ISMSI_ERR_PKG_CUSTOM_ACTION_FILE_NOTIN_FILETABLE (-3703) // Custom action file is not among files to be installed
#define ISMSI_ERR_PKG_CUSTOM_ACTION_GETCUSTOMACTIONARRAY (-3704) // Failed to get the CustomAction layout from the ism file
#define ISMSI_ERR_PKG_CUSTOM_ACTION_COLLECTCUSTOMACTIONINFO (-3705) // Failed to collect CustomAction data
#define ISMSI_ERR_PKG_CUSTOM_ACTION_READING_FILE (-3706) // Failed to read the file
#define ISMSI_ERR_PKG_CUSTOM_ACTION_UPDATE_PATH (-3707) // Failed parse path (for local files)
#define ISMSI_ERR_PKG_CUSTOM_ACTION_STREAM_WRAPPER_INI (-3708) // Failed to stream in the dll wrapper ini file
#define ISMSI_ERR_PKG_CUSTOM_ACTION_STREAM_WRAPPER_DLL (-3709) // Failed to stream in the dll wrapper dll
#define ISMSI_ERR_PKG_CUSTOM_ACTION_PARAMETER_INVALID (-3710) // Parameter for the dllwrapper is invalid
#define ISMSI_ERR_PKG_CUSTOM_ACTION_NOMODIFIER (-3711) // in/out/inout modifier missing from parameter
#define ISMSI_ERR_PKG_CUSTOM_ACTION_TYPE_INVALID (-3712) //invalid type in DLL Prototype
#define ISMSI_ERR_PKG_CUSTOM_ACTION_FUNCTIONBLOCK_INVALID (-3713) //function block not in a vlaid format
#define ISMSI_ERR_PKG_CUSTOM_ACTION_NOVOID (-3714) //no return value must have a return value of void
#define ISMSI_ERR_PKG_CUSTOM_ACTION_NOFILENAME (-3715) //no file name (source) specified
#define ISMSI_ERR_PKG_CUSTOM_ACTION_NOTARGET (-3716) //no target (DLL function name) specified
#define ISMSI_WRN_PKG_CUSTOM_ACTION_NOVBSMSM (-3717) // ISX VBScript CA included, but no VBScript Runtime merge module.
#define ISMSI_WRN_PKG_CUSTOM_ACTION_VBSMSM_BUT_NO_DCOM95 (-3718) // VBScript Runtime merge module included, but no DCOM95.

// -------------------------------------------------------------------------------------
//   Control table error codes
#define ISMSI_ERR_PKG_CONTROL_INIT (-3525) // Failed to initialize control Class
#define ISMSI_ERR_PKG_CONTROL_REINIT (-3526) // Failed to reinitialize control Class
#define ISMSI_ERR_PKG_CONTROL_READING_LICENSE (-3527) // Failed to read the License file
#define ISMSI_ERR_PKG_CONTROL_GETCONTROLOBJ (-3528) // Failed to get the control objects from the ism file
#define ISMSI_ERR_PKG_CONTROL_COLLECTINFO (-3529) // Failed to control information
#define ISMSI_ERR_PKG_CONTROL_UPDATECONTROL (-3530) // Failed to update control table
#define ISMSI_ERR_PKG_CONTROL_READING_BITMAP (-3531) // Failed to read the Welcome Bitmap
#define ISMSI_ERR_PKG_CONTROL_READING_FILE (-3532) //Cannot find or read file (especially for scrollable text)

// -------------------------------------------------------------------------------------
//   Installsequence table error codes
#define ISMSI_ERR_PKG_SEQ_INIT (-3550) // Failed to initialize sequence Class
#define ISMSI_ERR_PKG_SEQ_REINIT (-3551) // Failed to reinitialize sequence Class
#define ISMSI_ERR_PKG_SEQ_GETSEQUENCEARRAY (-3552) // Failed to populate array of sequence records
#define ISMSI_ERR_PKG_SEQ_COLLECTSEQUENCEINFO (-3553) // Failed to collect info for a record
#define ISMSI_ERR_PKG_SEQ_UPDATESEQUENCETABLE (-3554) // Failed to update MSI sequence table


// -------------------------------------------------------------------------------------
// Property table Error Codes
#define ISMSI_ERR_PKG_PROPERTY_INIT (-3800) // Failed to initialize Property Table
#define ISMSI_ERR_PKG_PROPERTY_REINIT (-3801) // Cannot reinit
#define ISMSI_ERR_PKG_PROPERTY_EMPTY (-3802) // Empty Property name or Property Value
#define ISMSI_ERR_PROPERTY_DEFAULT (-3803)
#define ISMSI_ERR_PKG_PROPERTY_UPDATE_NAME (-3804) // Failed to Add property name
#define ISMSI_ERR_PKG_PROPERTY_UPDATE_VALUE (-3805) // Failed to add Property Value
#define ISMSI_ERR_PKG_PROPERTY_UPDATE_RECORD (-3806) // Failed to update/assign property record

// -------------------------------------------------------------------------------------
// Shortcut Table error codes
#define ISMSI_ERR_PKG_SHORTCUT_MULTIPLEZAWTARGET (-3825) // Tried to create more than one ZAW
                                                                // complient shortcuts under one component
#define ISMSI_ERR_PKG_SHORTCUT_DETERMINETARGET (-3826) // Failed to determine shortcut target
#define ISMSI_ERR_PKG_SHORTCUT_DETERMINEICONPATH (-3827) // Failed to determine Icon Path
#define ISMSI_ERR_PKG_SHORTCUT_COLLECTINFO (-3828) // Failed to collect shortcut information

// -------------------------------------------------------------------------------------
//   Media table error codes
#define ISMSI_ERR_PKG_MEDIA_INIT (-3850) // Failed to initialize the Media table
#define ISMSI_ERR_PKG_MEDIA_BUILDTABLE (-3851) // Failed to build the media information
#define ISMSI_ERR_PKG_MEDIA_ENUMINFO (-3852) // Failed to enumerate the meida information
#define ISMSI_ERR_PKG_MEDIA_UPDATETABLE (-3853) // Failed to update the media table

// -------------------------------------------------------------------------------------
//   Summary stream error codes
#define ISMSI_ERR_PKG_INVALIDSUMMARYSTREAM (-3875) // Error accessing the summary stream information
#define ISMSI_ERR_PKG_SSTREAM_INVALIDTEMPLATE (-3876) // Invalid template string
#define ISMSI_ERR_PKG_SSTREAM_INVALIDPLATFORM (-3877) // Invalid platform in the template string
#define ISMSI_ERR_PKG_SSTREAM_INVALIDLANGUAGE (-3878) // Invalid language in the template string

// -------------------------------------------------------------------------------------
//   APPID table error codes
#define ISMSI_ERR_PKG_APPID_ACTIVATE (-3900) //Failed to update Activate
#define ISMSI_ERR_PKG_APPID_APPID (-3901) //Failed to update APPID
#define ISMSI_ERR_PKG_APPID_DLLSURROGATE (-3902) //Failed to update DLLSurrogate
#define ISMSI_ERR_PKG_APPID_LOCALSERVICE (-3903) //Failed to update LocalService
#define ISMSI_ERR_PKG_APPID_REMOTESERVERNAME (-3904) //Failed to update RemoteServerName
#define ISMSI_ERR_PKG_APPID_RUNASINTERACTIVESERVER (-3905) //Failed to update RunAsInterActiveServer
#define ISMSI_ERR_PKG_APPID_SERVICEPARAMETERS (-3906) //Failed to update ServiceParameters

// -------------------------------------------------------------------------------------
//   LaunchCondition table error codes
#define ISMSI_ERR_PKG_LAUNCHCOND_CONDITION (-3920) //Failed to update the Condition field
#define ISMSI_ERR_PKG_LAUNCHCOND_DESC (-3921) //Failed to update the Description field

// -------------------------------------------------------------------------------------
//   ServiceInstall table error codes
#define ISMSI_ERR_PKG_SERVICEINSTALL_SERVICEINSTALL (-3930) //Failed to update the ServiceInstall field
#define ISMSI_ERR_PKG_SERVICEINSTALL_NAME (-3931) //Failed to update the Name field
#define ISMSI_ERR_PKG_SERVICEINSTALL_DISPLAYNAME (-3932) //Failed to update the Displayname field
#define ISMSI_ERR_PKG_SERVICEINSTALL_SERVICETYPE (-3933) //Failed to update the ServiceType field
#define ISMSI_ERR_PKG_SERVICEINSTALL_STARTTYPE (-3934) //Failed to update the StartType field
#define ISMSI_ERR_PKG_SERVICEINSTALL_ERRORCONTROL (-3935) //Failed to update the Error Control field
#define ISMSI_ERR_PKG_SERVICEINSTALL_LOADORDER (-3936) //Failed to update the Load Order field
#define ISMSI_ERR_PKG_SERVICEINSTALL_DEPENDENCIES (-3937) //Failed to update the Dependencies field
#define ISMSI_ERR_PKG_SERVICEINSTALL_STARTNAME (-3938) //Failed to update the Startname field
#define ISMSI_ERR_PKG_SERVICEINSTALL_PASSWORD (-3939) //Failed to update the Password field
#define ISMSI_ERR_PKG_SERVICEINSTALL_ARGUMENTS (-3940) //Failed to update the Arguments field
#define ISMSI_ERR_PKG_SERVICEINSTALL_COMPONENT (-3941) //Failed to update the Component field

// -------------------------------------------------------------------------------------
//   ServiceControl table error codes
#define ISMSI_ERR_PKG_SERVICECONTROL_SERVICECONTROL (-3960) //Failed to update the ServiceControl field
#define ISMSI_ERR_PKG_SERVICECONTROL_NAME (-3961) //Failed to update the Name field
#define ISMSI_ERR_PKG_SERVICECONTROL_EVENT (-3962) //Failed to update the Event field
#define ISMSI_ERR_PKG_SERVICECONTROL_ARGUMENTS (-3963) //Failed to update the Arguments field
#define ISMSI_ERR_PKG_SERVICECONTROL_WAIT (-3964) //Failed to update the Wait field
#define ISMSI_ERR_PKG_SERVICECONTROL_COMPONENT (-3965) //Failed to update the Component field

// -------------------------------------------------------------------------------------
//   ODBCDriver table error codes
#define ISMSI_ERR_PKG_ODBCDRIVER_DRIVER (-3980) //Failed to update the Driver field
#define ISMSI_ERR_PKG_ODBCDRIVER_COMPONENT (-3981) //Failed to update the Component field
#define ISMSI_ERR_PKG_ODBCDRIVER_DESCRIPTION (-3982) //Failed to update the Description field
#define ISMSI_ERR_PKG_ODBCDRIVER_FILE (-3983) //Failed to update the File field
#define ISMSI_ERR_PKG_ODBCDRIVER_FILESETUP (-3984) //Failed to update the FileSetup field
    
// -------------------------------------------------------------------------------------
//   ODBCAttribute table error codes
#define ISMSI_ERR_PKG_ODBCATTRIBUTE_DRIVER (-3990) //Failed to update the Driver field
#define ISMSI_ERR_PKG_ODBCATTRIBUTE_ATTRIBUTE (-3991) //Failed to update the Attribute field
#define ISMSI_ERR_PKG_ODBCATTRIBUTE_VALUE (-3992) //Failed to update the Value field

    
// -------------------------------------------------------------------------------------
//   Build Error Codes
#define ISMSI_ERR_BUILD_CREATEDIR (-1000) // Unable to create directory
#define ISMSI_ERR_BUILD_OPENMSIDATABASE (-1001) // Unable to open the MSI package
#define ISMSI_ERR_BUILD_CREATEMSITABLE (-1002) // Unabel to create MSI table
#define ISMSI_ERR_BUILD_BUILDCAB (-1003) // Unable to build the cab file
#define ISMSI_ERR_BUILD_GETFILEALIAS (-1004) // Unable to get file alias from the collection
#define ISMSI_ERR_BUILD_LOOKUPKEY (-1005) // Unable to lookup key from the file alias from the collection
#define ISMSI_ERR_BUILD_ENUMFILEINFO (-1006) // Unable to enumerate file info from the collection
#define ISMSI_ERR_BUILD_COPYFILE (-1007) // Unable to copy a file from source to target
#define ISMSI_ERR_BUILD_DISKSPACE (-1008) // Insufficient disk space
#define ISMSI_ERR_BUILD_BKDISKSPACE (-1009) // Insufficient disk space for backup operation
#define ISMSI_ERR_BUILD_INITIALIZATION (-1010) // Initialization error
#define ISMSI_ERR_BUILD_COPYRESONLY (-1011) // Failed to copy Resource Only template (Could be in use?)
#define ISMSI_ERR_BUILD_COPYMSITEMPLATE (-1012) // Failed to copy MSI template package
#define ISMSI_ERR_BUILD_COPY_FILEINUSE (-1013) // Failed to copy since file is in use
#define ISMSI_ERR_BUILD_RENBACKUPDIR (-1014) // Failed to backup the directory.  May be in use.
#define ISMSI_ERR_BUILD_SETUPEXE (-1015) // Could not copy/modify setup.exe
#define ISMSI_ERR_BUILD_NOPRODUCTEXISTS (-1016)
#define ISMSI_ERR_BUILD_PROJECTPARAMSMISSING (-1017) // From cmdline build - project parameter missing
#define ISMSI_ERR_BUILD_PRODUCTPARAMSMISSING (-1018) // From cmdline build - product parameter missing
#define ISMSI_ERR_BUILD_RELEASEPARAMSMISSING (-1019) // From cmdline build - release parameter missing
#define ISMSI_ERR_BUILD_BUILDLABELPARAMSMISSING (-1020) // From cmdline build - build label parameter missing
#define ISMSI_ERR_BUILD_FILE_PERMISSION (-1021) // Target is locked
#define ISMSI_ERR_BUILD_FILE_DISKSPACE (-1022) // not enough disk space
#define ISMSI_ERR_BUILD_FILE_MISSING (-1023) // cannot find source file
#define ISMSI_ERR_BUILD_FILE_NOTFOUND (-1024) // cannot find the given file
#define ISMSI_ERR_BUILD_INVALIDPRODUCTNAME (-1025)
#define ISMSI_ERR_BUILD_AUTORUN (-1026) //cannot create autorun.inf
#define ISMSI_ERR_SIGN_SETUPEXE (-1027) // Could not sign setup.exe
#define ISMSI_ERR_BUILD_OLD_VERSION (-1028) // old project, need to upgrade - from command line build only
#define ISMSI_WRN_SHARESOURCELOCATION_SAMEFILENAME (-1029) // mulitple files with the same name and source location in separate components

// -------------------------------------------------------------------------------------
//   Build Error Codes for CAB files
#define ISMSI_ERR_BUILD_FCI_CREATE (-1500) // Unable to create the FCI cab object
#define ISMSI_ERR_BUILD_FCI_ADDFILE (-1501) // Unable to add a file to the FCI object
#define ISMSI_ERR_BUILD_FCI_FLUSHCABINET (-1502) // Unable to flush the buffer in the FCI object
#define ISMSI_ERR_BUILD_FCI_FLUSHFOLDER (-1503) // Unable to flush the folder in the FCI cab object
#define ISMSI_ERR_BUILD_FCI_DESTROY (-1504) // Unable to destroy the FCI cab object
#define ISMSI_ERR_BUILD_CAB_SINGLEPACKAGE (-1505) // Unable to stream the cab files into the package
// -------------------------------------------------------------------------------------
//   Build Error Codes for standard files
#define ISMSI_ERR_BUILD_FILE_ADDFILE (-1526) // Unable to add a file to the target directory
#define ISMSI_ERR_BUILD_FILE_NOFILES (-1527) // No files added to the package

#define ISMSI_ERR_BUILD_DISK_TOO_SMALL_FOR_FILE (-1530)
#define ISMSI_ERR_BUILD_DISK_TOO_SMALL_FOR_FEATURE (-1531)
#define ISMSI_ERR_BUILD_SINGLEPACK_TOO_SMALL (-1532)

// -------------------------------------------------------------------------------------
//   Build Error Codes for fonts
#define ISMSIBUILD_ERR_PKG_FON (-4500)

// -------------------------------------------------------------------------------------
//   Utility error codes
#define ISMSI_ERR_UTIL_ROOTDIR (-4000) // Cannot delete root directory
#define ISMSI_ERR_UTIL_INVALIDDIR (-4001) // Invalid directory
#define ISMSI_ERR_UTIL_DIRACCESS (-4002) // Failed to access directory.  May be security right problem
#define ISMSI_ERR_UTIL_DELDIR (-4003) // Failed to delete dir
#define ISMSI_ERR_UTIL_ATTRIBCHG (-4004) // Failed to change attributes
#define ISMSI_ERR_UTIL_DIRENUMFAILED (-4005) // Failed to enumerate directory
#define ISMSI_ERR_UTIL_DELETEFILE (-4006) // Failed to delete file
#define ISMSI_ERR_UTIL_COPYFILE (-4007)
#define ISMSI_ERR_UTIL_RENAMEFILE (-4008)
#define ISMSI_ERR_PATH_BUILDPATH (-4009)
#define ISMSI_ERR_UTIL_CREATEDIR (-4010) // Failed to create directory.

// -------------------------------------------------------------------------------------
//   ODBC DataSource table error codes
#define ISMSI_ERR_PKG_ODBCDATASOURCE_DATASOURCE (-4020) //Failed to update the DataSource field
#define ISMSI_ERR_PKG_ODBCDATASOURCE_COMPONENT (-4021) //Failed to update the DataSource field
#define ISMSI_ERR_PKG_ODBCDATASOURCE_DESCRIPTION (-4022) //Failed to update the DataSource field
#define ISMSI_ERR_PKG_ODBCDATASOURCE_DRIVERDESCRIPTION (-4023) //Failed to update the DataSource field
#define ISMSI_ERR_PKG_ODBCDATASOURCE_REGISTRATION (-4024) //Failed to update the DataSource field
#define ISMSI_WRN_PKG_ODBCDATASOURCE_DESCRIPTION_LENGTH (-4025) //Description cannot exceed 32 chars

// -------------------------------------------------------------------------------------
//   ODBC SourceAttribute table error codes
#define ISMSI_ERR_PKG_ODBCSOURCEATTRIBUTE_DRIVER (-4030) //Failed to update the Driver field
#define ISMSI_ERR_PKG_ODBCSOURCEATTRIBUTE_ATTRIBUTE (-4031) //Failed to update the Attribute field
#define ISMSI_ERR_PKG_ODBCSOURCEATTRIBUTE_VALUE (-4032) //Failed to update the Value field

// -------------------------------------------------------------------------------------
//   ODBC Translator table error codes
#define ISMSI_ERR_PKG_ODBCTRANSLATOR_TRANSLATOR (-4040) //Failed to update the Translator field
#define ISMSI_ERR_PKG_ODBCTRANSLATOR_COMPONENT (-4041) //Failed to update the Component field
#define ISMSI_ERR_PKG_ODBCTRANSLATOR_DESCRIPTION (-4042) //Failed to update the Description field
#define ISMSI_ERR_PKG_ODBCTRANSLATOR_FILE (-4043) //Failed to update the File field
#define ISMSI_ERR_PKG_ODBCTRANSLATOR_FILESETUP (-4044) //Failed to update the FileSetup field

// -------------------------------------------------------------------------------------
//   VC Edition Limitations
#define ISMSI_ERR_VCEDITION_MAXFEATURES (-4060) //VC Edition, can't create more than 5 features
#define ISMSI_ERR_VCEDITION_NOSUBFEATURES (-4061) //VC Edition, can't create subfeatures
#define ISMSI_ERR_VCEDITION_MAXCOMPONENTS (-4062) //VC Edition, can't create more than 30 components
#define ISMSI_ERR_VCEDITION_MAXFILES (-4063) //VC Edition, can't create more than 100 files

// -------------------------------------------------------------------------------------
//   MergeModule table error codes
#define ISMSI_ERR_PKG_MM_INIT (-4070)
#define ISMSI_ERR_PKG_MM_REINIT (-4071)
#define ISMSI_ERR_PKG_MM_DEPENDENCY (-4072) //Dependency MM does not exist in catalog. Therefore cannot be merged into msi
#define ISMSI_ERR_PKG_MM_MERGE (-4073) //One of the merge apis failed
#define ISMSI_ERR_PKG_MM_EXCLUSION (-4074) //One of the included MMs is listed as an exclusion of another included MM
#define ISMSI_ERR_PKG_MM_NOTFOUND (-4075) //MM included in the ISM is not found in the system
#define ISMSI_WRN_PKG_MM_DESTINATION (-4076) //Could not find MM in the ism - so could not find destination
#define ISMSI_WRN_PKG_MM_SHARESOURCELOCATION_SAMEFILENAME (-4077) //multiple files with the same name and source location exist in MM

// -------------------------------------------------------------------------------------
//   TextStyle table error codes
#define ISMSI_ERR_PKG_TEXTSTYLE_INIT (-4080)
#define ISMSI_ERR_PKG_TEXTSTYLE_REINIT (-4081)
#define ISMI_ERR_PKG_TEXTSTYLE_ADD (-4082)

// -------------------------------------------------------------------------------------
//  INIFile & RemoveINIFile table error codes
#define ISMSI_ERR_PKG_INI_INIT (-4400)
#define ISMSI_ERR_PKG_INI_REINIT (-4401)
#define ISMSI_ERR_PKG_INI_ADDID (-4402)
#define ISMSI_ERR_PKG_INI_ADDFILENAME (-4403)
#define ISMSI_ERR_PKG_INI_ADDDIRPROP (-4404)
#define ISMSI_ERR_PKG_INI_ADDSECTION (-4405)
#define ISMSI_ERR_PKG_INI_ADDKEY (-4406)
#define ISMSI_ERR_PKG_INI_ADDVALUE (-4407)
#define ISMSI_ERR_PKG_INI_ADDACTION (-4408)
#define ISMSI_ERR_PKG_INI_ADDCOMPID (-4409)

// -------------------------------------------------------------------------------------
//   ActionText table error codes
#define ISMSI_ERR_PKG_ACTIONTEXT_INIT (-4085)
#define ISMSI_ERR_PKG_ACTIONTEXT_REINIT (-4086)
#define ISMSI_ERR_PKG_ACTIONTEXT_ADD (-4087)

// -------------------------------------------------------------------------------------
//   Language related error codes
#define ISMSI_ERR_LANG_INIT (-4090)
#define ISMSI_ERR_LANG_REINIT (-4091)
#define ISMSI_ERR_LANG_OPEN_DATABASE (-4092)
#define ISMSI_ERR_LANG_COPY_DATABASE (-4093)
#define ISMSI_ERR_LANG_CONTROL_EVENT (-4094)
#define ISMSI_ERR_LANG_CONTROL_EVENT_CA (-4095)
#define ISMSI_ERR_LANG_DLGSEQ_EVENTS (-4096)
#define ISMSI_ERR_LANG_DIALOGS (-4097)
#define ISMSI_ERR_LANG_ADDDIALOG (-4098)
#define ISMSI_ERR_LANG_ADDCHECKBOX (-4099)
#define ISMSI_ERR_LANG_ADDCOMBOBOX (-4100)
#define ISMSI_ERR_LANG_ADDLISTBOX (-4101)
#define ISMSI_ERR_LANG_ADDLISTVIEW (-4102)
#define ISMSI_ERR_LANG_ADDRADIOBUTTON (-4103)
#define ISMSI_ERR_LANG_STRID_MISSING (-4104)
#define ISMSI_ERR_LANG_ADDCONTROL (-4105)
#define ISMSI_ERR_LANG_ADDCONTROLCONDITION (-4106)
#define ISMSI_ERR_LANG_ADDCONTROL_EVENT_MAPPING (-4107)
#define ISMSI_ERR_LANG_STR_OPENTABLE (-4108)
#define ISMSI_ERR_PKG_FEATURE_SKIP (-4109)
#define ISMSI_WRN_LANG_MISSING (-4110)

// -------------------------------------------------------------------------------------
//   Error table error codes
#define ISMSI_ERR_PKG_ERROR_INIT (-4120)
#define ISMSI_ERR_PKG_ERROR_REINIT (-4121)
#define ISMSI_ERR_PKG_ERROR_ADD (-4122)

// -------------------------------------------------------------------------------------
//   UIText table error codes
#define ISMSI_ERR_PKG_UITEXT_INIT (-4130)
#define ISMSI_ERR_PKG_UITEXT_REINIT (-4131)
#define ISMSI_ERR_PKG_UITEXT_ADD (-4132)

// -------------------------------------------------------------------------------------
//   ModuleSequence table error codes
#define ISMSI_ERR_MSMSEQUENCE_INIT (-4200)
#define ISMSI_ERR_PKG_MMSEQ_ENUMSEQTABLES (-4201)
#define ISMSI_ERR_PKG_MMSEQ_ENUMRECORDS (-4202)
#define ISMSI_ERR_PKG_MMSEQ_MSITABLEINIT (-4203)
#define ISMSI_ERR_PKG_MMSEQ_COLLECTSEQUENCEINFO (-4204)
#define ISMSI_ERR_PKG_MMSEQ_WRITESEQUENCERECORD (-4205)

//--------------------------------------------------------------------------------------
//   CIsMsmModule error codes
#define ISMSI_ERR_MSMMODULE_INIT (-4210)
#define ISMSI_ERR_MSMMODULE_REINIT (-4211)
#define ISMSI_ERR_MSMMODULE_INITREQUIRED (-4212)
#define ISMSI_ERR_PKG_MSMMODULE_MSITABLEINIT (-4213)
#define ISMSI_ERR_PKG_MSMMODULE_BUILDTABLES (-4214)
#define ISMSI_ERR_PKG_MSMMODULE_NOTEXIST (-4215)
#define ISMSI_ERR_PKG_MSMMODULE_COLLECTMODULEINFO (-4216)
#define ISMSI_ERR_PKG_MSMMODULE_UPDATESIGTABLE (-4217)
#define ISMSI_ERR_PKG_MSMMODULE_GETLAYOUT (-4218)
#define ISMSI_ERR_PKG_MSMMODULE_NULLVERSION (-4219)

//--------------------------------------------------------------------------------------
//   ModuleDependency error codes
#define ISMSI_ERR_MSMDEPENDENCY_INIT (-4230)
#define ISMSI_ERR_MSMDEPENDENCY_REINIT (-4231)
#define ISMSI_ERR_MSMDEPENDENCY_INITREQUIRED (-4232)
#define ISMSI_ERR_PKG_MSMDEPENDENCY_NOTEXIST (-4233)
#define ISMSI_ERR_PKG_MSMDEPENDENCY_ENUMRECORDS (-4234)
#define ISMSI_ERR_PKG_MSMDEPENDENCY_WRITERECORD (-4235)

//--------------------------------------------------------------------------------------
//   ModuleExclusion error codes
#define ISMSI_ERR_MSMEXCLUSION_INIT (-4240)
#define ISMSI_ERR_MSMEXCLUSION_REINIT (-4241)
#define ISMSI_ERR_MSMEXCLUSION_INITREQUIRED (-4242)
#define ISMSI_ERR_PKG_MSMEXCLUSION_NOTEXIST (-4243)
#define ISMSI_ERR_PKG_MSMEXCLUSION_ENUMRECORDS (-4244)
#define ISMSI_ERR_PKG_MSMEXCLUSION_WRITERECORD (-4245)
#define ISMSI_ERR_PKG_MSMEXCLUSION_NULLEXCLUDEID (-4246)

//--------------------------------------------------------------------------------------
//   Pathvariables error code
#define ISMSI_ERR_PATHVARIABLE_DOESNOTEXIST (-4250)

//--------------------------------------------------------------------------------------
//   File error code
#define ISMSI_ERR_FILE_GETFILEINFO (-4300)
#define ISMSI_ERR_SYNCH_KEY_OPEN (-4301)
#define ISMSI_ERR_SYNCH_KEY_CONFLICT (-4302)
#define ISMSI_ERR_SYNCH_KEY_UNEXPECTED (-4303)

//--------------------------------------------------------------------------------------
//   Installscript error codes
#define ISMSIBUILD_ERR_WRITING_ISCONFIGFILE (-4325)
#define ISMSIBUILD_ERR_FUNCCOUNT_EXCEEDED (-4326)
#define ISMSIBUILD_ERR_CREATING_STRINGTABLE (-4327)
#define ISMSIBUILD_ERR_SETUPRUL_NOTFOUND (-4328)

//--------------------------------------------------------------------------------------
//   CCOMExtract error code
#define ISMSI_ERR_COMEXTRACT_INIT (-4340) //failed to initialize object
#define ISMSI_ERR_COMEXTRACT_ENUMCOMPONENTS (-4341) //failed to find components
#define ISMSI_ERR_COMEXTRACT_EXTRACT (-4342) //Failed to extract COM inofrmation for components
#define ISMSI_ERR_COMEXTRACT_BUILDCLASS (-4343) // Failed to build extracted class data
#define ISMSI_ERR_COMEXTRACT_BUILDPROGID (-4344) // Failed to build extracted progid data
#define ISMSI_ERR_COMEXTRACT_BUILDTYPELIB (-4345) // Failed to build extracted typelib data
#define ISMSI_ERR_COMEXTRACT_BUILDAPPID (-4346) // Failed to build extracted appid data
#define ISMSI_ERR_COMEXTRACT_BUILDMIME (-4347) // Failed to build extracted mime data
#define ISMSI_ERR_COMEXTRACT_BUILDEXTENSION (-4348) // Failed to build extracted EXTENSION data
#define ISMSI_ERR_COMEXTRACT_BUILDMISCREG (-4349) // Failed to build extracted registry data
#define ISMSI_ERR_COMEXTRACT_OVERWRITECOM (-4350) //Overwrote static com data
#define ISMSI_ERR_COMEXTRACT_BUILTNEWCOM (-4351) //built new com data
#define ISMSI_ERR_COMEXTRACT_NOKEYFILE (-4352) // Need key file to extract
#define ISMSI_ERR_COMEXTRACT_REGISTRYCLEANUP (-4353) //Unable to cleanup the registry after COM Extraction
#define ISMSI_ERR_COMEXTRACT_NOREGINFO (-4354) //No Registry Info found
#define ISMSI_ERR_COMEXTRACT_SELFREGFAILED (-4355) //SelfRegistration failed in the COM Extraction engine
//--------------------------------------------------------------------------------------
//   Registry Error Codes

#define ISMSI_ERR_REGISTRY_RESOLVEKEY (-4360) //Unable to resolve registry key
#define ISMSI_ERR_REGISTRY_NONUNIQUEKEY (-4361) //Non-unique MSI key specified

//--------------------------------------------------------------------------------------
//   Compile + Link Error Codes

#define ISMSI_ERR_ISSCRIPT_COMPILE_ERROR (-4370)
#define ISMSI_ERR_ISSCRIPT_COMPILE_WRN (-4371)
#define ISMSI_ERR_ISSCRIPT_LINK_ERROR (-4372)
#define ISMSI_ERR_ISSCRIPT_LINK_WRN (-4373)

//--------------------------------------------------------------------------------------
//   Object Error Codes

#define ISMSI_ERROR_OBJECTS (-4400)
#define ISMSI_ERROR_OBJECTS_ACCESS2K (-4401) // error building Access2000 object

//--------------------------------------------------------------------------------------
//   Support Files Error Codes
#define ISMSI_ERR_SUPPORTFILES_ADD_TO_BINARY (-4500) // Could not add a support file to the Binary table.
#define ISMSI_ERR_SUPPORTFILES_ADD_TO_INI (-4501) // Could not list the support file in the ini file
#define ISMSI_ERR_SUPPORTFILES_ADD_INI_TO_BINARY (-4502) // Could not add the ini file to the Binary table.
#define ISMSI_ERR_SUPPORTFILES_ADD_SFHELPER_TO_BINARY (-4503) // Could not add SFHelper.dll to the Binary table.

//--------------------------------------------------------------------------------------
//   Environment Table Error Codes
#define ISMSI_ERR_ENVIRONMENT_NO_NAME (-4600) // Environment variable must have a name
#define ISMSI_ERR_ENVIRONMENT_KILLING_PATH (-4601) // You are going to delete the PATH env variable at runtime
#define ISMSI_ERR_ENVIRONMENT_INVALID_PREFIX_COMBO (-4602) // See MSI Help topic "Environment table" for illegal combos
#define ISMSI_ERR_ENVIRONMENT_REPLACE_PATH (-4603) // Illegal to replace PATH env variable at runtime
#define ISMSI_WRN_ENVIRONMENT_CREATESET_EMPTY (-4604) // Creating or setting an empty env variable

//--------------------------------------------------------------------------------------
//   Directory error code
#define ISMSI_ERR_SOURCE_DIR (-33002)
#define ISMSI_ERR_BRACKET (-33003)

// -------------------------------------------------------------------------------------
//   Build Error Code for compressing the package (.msi) into a cabinet file
#define ISMSI_ERR_BUILD_CAB4MSI (-4700) // Unable to compress the package into a cabinet file

// -------------------------------------------------------------------------------------
// Web deployment
#define ISMSI_ERR_BUILD_WEBDEPLOY (-4701) // General build Error Code for WebDeployment release
#define ISMSI_ERR_BUILD_WEB_JAR (-4702) // Problem creating the jar file.
#define ISMSI_WRN_CURDIR_DETERMINE (-4703) // Couldn't determine the current directory
#define ISMSI_WRN_CURDIR_RESTORE (-4704) // Couldn't restore the previous current directory
#define ISMSI_ERR_CURDIR_SET (-4705) // Couldn't set the current directory for zip.exe
#define ISMSI_ERR_ZIPFAILED (-4706)
#define ISMSI_ERR_NETSCAPE_SIGNINFONEEDED (-4707) // Netscape certificate file info is needed for signing

// -------------------------------------------------------------------------------------
// Access2000
#define ISMSI_WRN_BUILD_ACCESS2000COMPRESSED (-4801) // Access97 won't work with a compressed setup.


#endif //Remove in .cs
