//===========================================================================
//
//  IIIIIII SSSSSS
//    II    SS                          InstallShield (R
//    II    SSSSSS      (c) 1996-2003, InstallShield Software Corporation
//    II        SS      (c) 1990-1996, InstallShield Corporation
//  IIIIIII SSSSSS                     All Rights Reserved.
//
//
//    File Name:  SetupTraceDefsPriv.h
//	
//  Description:  Setup Tracing defintions
//
//===========================================================================

#ifndef _SETUPTRACEDEFSPRIV_H_
#define _SETUPTRACEDEFSPRIV_H_

//
// !!!IMPORTANT NOTE!!!
// 
// Don't use #pragma or _T() notation nor the \ line continuation character
// in this file, since it needs to be compilable with the InstallScript compiler.
//

// Registry
#define TRACE_REGKEY_ROOT                           HKEY_CURRENT_USER
#define TRACE_REGKEY_ENABLE_TRACE                   "ISlogit"
#define TRACE_REGVALUE_ENABLE_TRACE_STD             "TraceStd"
#define TRACE_REGVALUE_FILENAMEPATH					"FileNamePath"

#define TRACE_FILENAME_TRACE_LOG				    L"setuptrace"
#define TRACE_FILEEXT_TRACE_BIN						L"bin"
#define TRACE_FILEEXT_TRACE_LOG						L"log"

// General
#define TRACE_FMT_HEXVALUE							"0x%08lx"
#define TRACE_FMT_DECVALUE							"%ld"
#define TRACE_FMT_STRVALUE							"%s"
#define TRACE_FMT_STRWVALUE							"%S"
#define TRACE_FMT_TAB								"\t"
#define TRACE_FMT_EMPTY								""
#define TRACE_FMT_DELIM_COL							"|"

#define TRACE_ENCRYPTION_KEY						33
#define TRACE_MAX_LINE_LEN							16384 // 16K Buffer
// Note: The 64K buffer causes some problems with DoInstall (and possibly other
// functionality so for now switch back to 16K buffer.
//#define TRACE_MAX_LINE_LEN						65536 //64K Buffer
#define TRACE_TXT_FMT_VERSION						"FormatVersion=00000005\r\n\r\n"
#define TRACE_TXT_COPYRIGHT1						"(c) Copyright 2003 InstallShield Software Corporation (All Rights Reserved)\r\n\r\n"
#define TRACE_FMT_TIMEDATE							"TraceStarted: %.2ld/%.2ld/%.2ld %.2ld:%.2ld:%.2ld\r\n"
#define TRACE_FMT_SETUPEXE							"SetupExe: %s\r\n"
#define TRACE_FMT_SETUPEXEVERSION					"SetupExeVersion: %ld.%ld.%ld.%ld\r\n"
#define TRACE_FMT_COLUMN_HEADERS					"Category" TRACE_FMT_DELIM_COL "SubCategory" TRACE_FMT_DELIM_COL "Details\r\n"
#define TRACE_CAT_COMMENT							"Comment"
#define TRACE_FMT_SUB								TRACE_FMT_STRVALUE TRACE_FMT_DELIM_COL TRACE_FMT_STRVALUE TRACE_FMT_DELIM_COL
#define TRACE_TXT_TRACE_DATA						"\r\nTraceData:\r\n"

#endif