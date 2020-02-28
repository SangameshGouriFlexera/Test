
 /*=======================================================================*/
 /*                 The Stirling Group  (c) 1990, 1991                    */
 /*                 Roselle, Illinois 60172  USA                          */
 /*                 All rights Reserved.                                  */
 /*                 MemSHIELD (tm) v1.2                                   */
 /*                 InVisible declares for MemSHIELD                      */
 /*=======================================================================*/

 //
 //
 //   File :    MemHook.h
 //
 //   Purpose : This file supports MemSHIELD.
 //             It contains constants used to rename all entries.
 //             This file will be enabled by TSG utility library only.
 //
 //

/************************************************************************/
/*                    Macro definition for Stirling Products            */
/*----------------------------------------------------------------------*/
/*             Used to rename those private/invisible entries           */
/************************************************************************/

/*----------------------------------------------------------------------*/
/*                        Public/Visible entries                        */
/*----------------------------------------------------------------------*/
#define MemHeapCreate                    TSGM0M1
#define MemHeapFree                      TSGM0M2
#define MemHeapAlloc                     TSGM0M3
#define MemHeapDestroy                   TSGM0M4
#define MemHeapStatus                    TSGM0M5
#define MemHeapConfigure                 TSGM0M6
#define MemHeapQuery                     TSGM0M7
#define MemHeapHandle                    TSGM0M8
#define MemHeapReAlloc                   TSGM0M9

#define MemHeapVersion                   TSGM0M10
#define MemHeapTraverse                  TSGM0M11
#define MemHeapQuerySubHeap              TSGM0M12
#define MemHeapLockSubHeap               TSGM0M13
#define MemHeapUnLockSubHeap             TSGM0M14
#define MemHeapLockCount                 TSGM0M15
#define MemHeapResetSubHeap              TSGM0M16

#define MemHeapRemoveMemBlock            TSGM0M17

/*----------------------------------------------------------------------*/
/*                       Private/Invisible variables                    */
/*----------------------------------------------------------------------*/
#define mmhMemMainTable                  TSGV0V1
#define mmeErr                           TSGV0V2
#define mmcConfig                        TSGV0V3
#define iMemHeapNum                      TSGV0V4

#define ulMem_Times_Alloc                TSGV1V1
#define ulMem_Times_Free                 TSGV1V2
#define ulMem_Times_Create               TSGV1V3
#define ulMem_Times_Alloc_Int            TSGV1V4
#define ulMem_Times_Free_Int             TSGV1V5
#define ulMem_Times_Destroy              TSGV1V6
#define ulMem_Times_GC                   TSGV1V7

#define ulMem_Time_Alloc                 TSGV2V1
#define ulMem_Time_Free                  TSGV2V2
#define ulMem_Time_Alloc_Int             TSGV2V3
#define ulMem_Time_Free_Int              TSGV2V4
#define ulMem_Time_Create                TSGV2V5
#define ulMem_Time_Destroy               TSGV2V6
#define ulMem_Time_GC                    TSGV2V7
#define ulMemCurTime                     TSGV2V8

#define iMhMgrStart                      TSGV3V1
#define iMhTableEntryFactor              TSGV3V2
#define iFreeListTblEntry                TSGV3V3

#define bMem_bMemDebug                   TSGV4V1
#define bMem_bMemAlloc                   TSGV4V2
#define bMem_bMemStat                    TSGV4V3

#define timeMembuffer                    TSGV5V1
#define tmMemptr                         TSGV5V2


/*----------------------------------------------------------------------*/
/*                       Private/Invisible entries                      */
/*----------------------------------------------------------------------*/
#define MHSetupVariables                 TSGI00R1
#define MHStart                          TSGI00R2

#define MHCreate                         TSGI01R1
#define MemHeapCreateInt                 TSGI01R2
#define MemHeapAllocInt                  TSGI01R3
#define MemHeapDestroyInt                TSGI01R4
#define MHExpandHeap                     TSGI01R5
#define MHUserHeapTableSize              TSGI01R6

#define MHFillHeapFreeListTable          TSGI02R1
#define MHBinarySearchOnFreeListTable    TSGI02R2

#define MH_IsHead                        TSGI03R1
#define MH_IsFree                        TSGI03R2
#define MH_IsOverWritten                 TSGI03R3
#define MH_IsEvenParity                  TSGI03R4

#define MHChecksumSetup                  TSGI04R1
#define MHHandleCheck                    TSGI04R2
#define MH_NodeAllocated                 TSGI04R3
#define MH_HeapExtensible                TSGI04R4
#define MH_HeapExpansible                TSGI04R5
#define MH_NoRelease                     TSGI04R6
//#define MH_HeapZeroInit                  TSGI04R7
#define MH_SetHeapAttribute              TSGI04R8

#define MHAllocateIt                     TSGI05R1
#define MHNodeSplit                      TSGI05R2
#define MHMakeHeapToNode                 TSGI05R3
#define MHNodeInsert                     TSGI05R4
#define MHPtrToHeap                      TSGI05R5

#define MHGCPartial                      TSGI06R1
#define MHGCFull                         TSGI06R2
#define MHGCAlloc                        TSGI06R3

#define MHUserHeapTableEntry             TSGI07R1
#define MHAssignBytes                    TSGI07R2
#define MHAllocMemForHeap                TSGI07R3
#define MHMemExpand                      TSGI07R4
#define MHFreeMemHeap                    TSGI07R5

#define MHErrorMsg                       TSGI08R1
#define MHMessageBox                     TSGI08R2
#define MH_CurTime                       TSGI08R3
#define MH_XGetTime                      TSGI08R4

#define MHLocalAlloc                     TSGI09R1
#define MHLocalFree                      TSGI09R2
#define MHLocalReAlloc                   TSGI09R3

#define MHSizeCvt                        TSGI10R1
#define MH_PageToByte                    TSGI10R2

#define MHLargeAlloc                     TSGI11R1
#define MHLargeFree                      TSGI11R2
#define MHLargeReAlloc                   TSGI11R3

#define MHHeapFreeDebug                  TSGI12R1
#define MHHeapAllocDebug                 TSGI12R2
#define MHHeapReAllocDebug               TSGI12R3

#define MH_Init_Stat                     TSGI13R1
#define MH_Reset_Global_Stat             TSGI13R2
#define MH_SubObjectTypeCt               TSGI13R3
#define MH_LastFree                      TSGI13R4

#define MHDDEAlloc                       TSGI14R1
#define MHDDEFree                        TSGI14R2
#define MHDDEReAlloc                     TSGI14R3

#define MHAllocLargeMemForHeap           TSGI15R1
#define MHReAllocLargeMemBlock           TSGI15R2
#define MHReAllocMemBlock                TSGI15R3

#define MHDefHeapHandle                  TSGI16R1
#define MHGetHandle                      TSGI16R2
#define MHGetLocalHandle                 TSGI16R3

#define MH_HeapVirtual                   TSGV1R1
#define MH_LockCount                     TSGV1R2
#define MH_LockHeap                      TSGV1R3
#define MH_UnLockHeap                    TSGV1R4
#define MH_ResetSubHeap                  TSGV1R5
#define MH_GetNodeSize                   TSGV1R6
#define MH_GetSubHeap                    TSGV1R7

#ifdef _WINPROG

#define Mem_lstrcpy                      lstrcpy
#define Mem_lstrcmp                      lstrcmp
#define Mem_lstrlen                      lstrlen
#define Mem_lstrcat                      lstrcat

#else

#define Mem_lstrcpy                      TSGI17R1
#define Mem_lstrcmp                      TSGI17R2
#define Mem_lstrlen                      TSGI17R3
#define Mem_lstrcat                      TSGI17R4

#endif

