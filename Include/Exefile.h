//==========================================
// Matt Pietrek
// Microsoft Systems Journal, Feb 1997
// FILE: EXEFILE.H
//==========================================
#ifndef __EXEFILE_H__
#define __EXEFILE_H__

#ifndef __MEMMAPFL_H__
#include "memorymappedfile.h"
#endif

// MakePtr is a macro that allows you to easily add to values (including
// pointers) together without dealing with C's pointer arithmetic.  It
// essentially treats the last two parameters as DWORDs.  The first
// parameter is used to typecast the result to the appropriate pointer type.
#define MakePtr( cast, ptr, addValue ) (cast)( (DWORD)(ptr) + (DWORD)(addValue))


class CExeFile : public CMemoryMappedFile
{
public:

	enum eType { exeType_Invalid, exeType_DOS, exeType_NE, exeType_VXD, exeType_LX, exeType_PE, exeType_PE64, exeType_PEIA64, exeType_PEARM, exeType_PE_NET_MSIL, exeType_PE_NET_X86, exeType_PE_NET_X64, exeType_PE_NET_IA64, exeType_PE_NET_ARM };

	enum errEXE_FILE {  errEXE_FILE_NO_ERROR, errEXE_FILE_FILE_NOT_FOUND,  errEXE_FILE_INVALID_FORMAT };
      
    CExeFile( BSTR bstrFileName );
    ~CExeFile( ){ ; }
    
    bool IsValid() const { return errMMF_NoError == m_errorType; }
    
    errEXE_FILE GetErrorType() const { return m_errorType; }

    DWORD   GetSecondaryHeaderOffset() const { return m_secondaryHeaderOffset; }

    eType GetExeType() { return m_exeType; }

    PSTR    GetFileTypeDescription( void );

    protected:

    errEXE_FILE m_errorType;
            
    private:

    LONG        m_secondaryHeaderOffset;
    eType    m_exeType;

};

#endif
