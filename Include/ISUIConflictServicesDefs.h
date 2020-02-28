#ifndef _ISUICONFLICTSERVICES_DEFS_H_
#define _ISUICONFLICTSERVICES_DEFS_H_

//--------------------------------------------------------------------------
// Validation Messages
#define WM_VALIDATIONCANCEL		(WM_USER + 200)
#define WM_VALIDATIONERROR		(WM_VALIDATIONCANCEL + 1)
#define WM_CUBFILE_NOTFOUND		(WM_VALIDATIONCANCEL + 2)
#define WM_VALIDATIONDONE		(WM_VALIDATIONCANCEL + 3)
#define WM_VALIDATIONBEGIN		(WM_VALIDATIONCANCEL + 4)

//--------------------------------------------------------------------------
// Conflict Messages
#define WM_CONFLICTCANCEL		(WM_USER + 207)
#define WM_CONFLICTERROR		(WM_CONFLICTCANCEL + 1)
#define WM_ACEFILE_NOTFOUND		(WM_CONFLICTCANCEL + 2)
//#define WM_NOPACKAGE_IN_DB		(WM_CONFLICTCANCEL + 3)
#define WM_CONFLICTDONE			(WM_CONFLICTCANCEL + 4)
#define WM_CONFLICTBEGIN		(WM_CONFLICTCANCEL + 5)
#define WM_CONFLICT_UPDATE		(WM_CONFLICTCANCEL + 6)

//--------------------------------------------------------------------------
// Patch Impact Messages
#define WM_PATCHIMPACT_START    (WM_USER + 360)
#define WM_PATCHIMPACT_PROGRESS (WM_PATCHIMPACT_START + 1)
#define WM_PATCHIMPACT_FINISH   (WM_PATCHIMPACT_PROGRESS + 1)
#define WM_PATCHIMPACT_PRODUCT_FINISH   (WM_PATCHIMPACT_FINISH + 1)

// Dependency Checking Messages
#define WM_DEPENDCHECK_START    (WM_USER + 365)
#define WM_DEPENDCHECK_PROGRESS (WM_DEPENDCHECK_START + 1)
#define WM_DEPENDCHECK_FINISH   (WM_DEPENDCHECK_PROGRESS + 1)
#define WM_DEPENDCHECK_PRODUCT_FINISH   (WM_DEPENDCHECK_FINISH + 1)

//--------------------------------------------------------------------------
// Import Messages
#define WM_IMPORT_STATE			(WM_USER + 350)
#define WM_IMPORT_PROGRESS		(WM_IMPORT_STATE + 1)
#define IMPORT_BEGIN			0
#define IMPORT_END				1
#define IMPORT_COUNT			2
#define IMPORT_NEXT				3
#define IMPORT_BEGIN_SELECT		4
#define IMPORT_END_SELECT		5

#define WM_SOFTREP_PROGRESS		(WM_USER + 355)
#define SOFTREP_OPERATION_BEGIN	1
#define SOFTREP_OPERATION_END	2
#define WM_PACKAGE_DELETE_REFRESH	(WM_USER + 356)
#define WM_SOFTREP_OUTPUTWND_CLEARONADD	(WM_USER + 357)

//--------------------------------------------------------------------------
// Subscription Messages
#define WM_SUBSCRIPTION_BEGIN			(WM_USER + 400)
#define WM_SUBSCRIPTION_PROGRESS		(WM_SUBSCRIPTION_BEGIN + 1)
#define WM_SUBSCRIPTION_END				(WM_SUBSCRIPTION_BEGIN + 2)

#define WM_DB_UPGRADE_PROGRESS		(WM_USER + 215)

#define WM_DB_REFRESH				(WM_USER + 299)
#define WM_SNAPSHOT_IMPORTCANCEL	(WM_USER + 300)
#define WM_SNAPSHOT_IMPORTERROR		(WM_SNAPSHOT_IMPORTCANCEL + 1)
#define WM_SNAPSHOT_IMPORTDONE		(WM_SNAPSHOT_IMPORTCANCEL + 2)
#define WM_SNAPSHOT_IMPORTBEGIN		(WM_SNAPSHOT_IMPORTCANCEL + 3)
#define WM_SNAPSHOT_IMPORTSTATUS	(WM_SNAPSHOT_IMPORTCANCEL + 4)
 
#define WM_TESTBED_DONE				(WM_USER + 735)
#define WM_TESTBED_BEGIN			(WM_USER + 736)
#define WM_TESTBED_STATUS			(WM_USER + 737)

#define WM_RUNALLTESTS_DONE			(WM_USER + 738)
#define WM_RUNALLTESTS_BEGIN		(WM_USER + 739)
#define WM_RUNALLTESTS_STATUS		(WM_USER + 740)
#define WM_RUNALLTESTS_PROGRESS		(WM_USER + 741)
#define WM_RUNALLTESTS_INVOKE		(WM_USER + 742)
#define WM_RUNALLTESTS_QUEUE		(WM_USER + 743)
#define WM_RUNSELECTEDTESTS			(WM_USER + 744)
#define WM_SOFTREP_OPS_DONE			(WM_USER + 745)

//--------------------------------------------------------------------------
// Resolution Message
// Format:	WPARAM - pointer to a string;
//			LPARAM - LOWORD - boolean flag indicating start message
//			LPARAM - HIWORD - count of number of additional lines			
//#define   WM_RESOLUTION_MESSAGE		(WM_USER +220)
//#define WM_RESOLUTIONCANCEL		(WM_USER + 220)
//#define WM_RESOLUTIONDONE		    (WM_RESOLUTIONCANCEL + 1)
//#define WM_RESOLUTIONBEGIN		(WM_RESOLUTION_MESSAGE + 2)
//#define WM_RESOLUTIONERROR		(WM_RESOLUTIONCANCEL + 3)

//--------------------------------------------------------------------------
// General Purpose Messages
#define WM_OUTPUT_WND_CLEAR		(WM_USER + 230)
#define WM_INSERT_MSI_PACKAGE	(WM_USER + 231)
#define WM_INSERT_MSM_PACKAGE	(WM_USER + 232)
#define WM_SELECT_MSI_PACKAGE	(WM_USER + 233)
#define WM_SELECT_MSM_PACKAGE	(WM_USER + 234)

#define WM_REFRESH_TABLE_VIEW   (WM_USER + 235)
#define WM_HANDLE_THREAD_SAFE_OUTPUT	(WM_USER + 236)
#define WM_POST_THREAD_SAFE_OUTPUT	(WM_USER + 237)
	#define ERROR_TEXT			RGB(255,0,0)
	#define INFO_TEXT			RGB(65,105,225)

//--------------------------------------------------------------------------
// General Group Properties Messages
#define WM_NEW_GROUP_CREATED	(WM_USER + 241)
#define WM_GROUP_RENAMED        (WM_USER + 242)

#define WM_SELECT_SPECIFIED_ITEM   (WM_USER + 243)
#define WM_RESET_SPECIFIED_ITEM    (WM_USER + 244)
#define WM_CUSTOM_TREE_REFLECTION  (WM_USER + 245)
#define WM_SELECT_CHANGED_PKGROWID (WM_USER + 246)
#define WM_SELECT_SPECIFIED_PATCH  (WM_USER + 247)
#define WM_UPDATE_PACKAGE          (WM_USER + 248)
#define WM_NEW_APPLICATION_CREATED (WM_USER + 249)
#define WM_APPLICATION_DELETE      (WM_USER + 250)

//--------------------------------------------------------------------------
// Navigation Messages
#define WM_NAVIGATE_PRODUCT_VIEW (WM_USER + 316)
#define WM_VIEW_REFRESH          (WM_USER + 317)
#define WM_CLOSE_CATALOG		 (WM_USER + 318)
#define	WM_UPDATE_UI_STATES		 (WM_USER + 319)
#define WM_UPDATE_AMS_CONN_STATUS (WM_USER+320)
#define WM_CUSTOM_REDRAWPACKAGETREE (WM_USER + 321)

#define WM_LAUNCH_PATCHANALYSISWIZARD  (WM_USER + 322)

//---------------------------------------------------------------------------
#define WM_AS_CS_PROCESS_ASSISTANT_COMM  (WM_USER + 2313)

#define ASSISTANT_OP_IMPORT   1001
#define ASSISTANT_OP_CONFLICT 1002
#define ASSISTANT_OP_RESOLVE  1003

#define WM_FORCE_CHECK_IN                (WM_USER + 2317)
#define CHECK_IN_OVERWRITE    101
#define CHECK_IN_EXISTING     102
#define CHECK_IN			  103
#define CHECK_OUT			  104
#define UNDO_CHECKOUT         105

#define WM_AS_CS_PROCESS_ASSISTANT_CONFLICT (WM_USER + 2333)

typedef struct tagAssistantInfo
{
    DWORD  nOperation;
    DWORD  nPkgRowID_; //or -1 if not needed
    TCHAR  szConnectionString[2048];
    TCHAR  szPackagePath[2048];
} ASSISTANTINFO;

//--------------------------------------------------------------------------
typedef enum eOutputWndTabType
{
	eowttValidation,
	eowttConflict,
	eowttImport,
	eowttResolution,
	eowttImportSnapshot
}
EOutputWndTabType;

#endif //_ISUICONFLICTSERVICES_DEFS_H_