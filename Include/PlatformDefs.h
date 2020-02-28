/**************************************************************************************************
* NOTICE OF COPYRIGHT AND OWNERSHIP OF SOFTWARE:
*
* Copyright (c) 1993-2005, Macrovision Corporation.  All Rights Reserved.
*
* This computer program is the property of Macrovision Europe Ltd. of Maidenhead, Berkshire, 
* England and Macrovision Corporation of Santa Clara, California, U.S.A. 
* Any use, copy, publication, distribution, display, modification, or transmission of this 
* computer program in whole or in part in any form or by any means without the prior express 
* written permission of Macrovision Europe Ltd. or Macrovision Corporation is strictly prohibited.
* 
* Except when expressly provided by Macrovision Europe Ltd. or Macrovision Corporation in writing,
* possession of this computer program shall not be construed to confer any license or rights under 
* any of Macrovision Europe Ltd.'s or Macrovision Corporation's intellectual property rights, 
* whether by estoppel, implication, or otherwise.  
* 
* ALL COPIES OF THIS PROGRAM MUST DISPLAY THIS NOTICE OF COPYRIGHT AND OWNERSHIP IN FULL.
**************************************************************************************************/
#pragma once

// PVOID PPLATFORMMAIN ------------------------------------------------------
typedef PVOID PPLATFORMMAIN;
#pragma pack(1)
    // 64 bit os value storage
    typedef struct platform_info {
        ULONG           ulUpperOS;              // Upper 32bit of the os value
        ULONG           ulLowerOS;              // Lower 32bit of the os value
    } PLATFORM_INFO, FAR *pPLATFORM_INFO;
#pragma pack()