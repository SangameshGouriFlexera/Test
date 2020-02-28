// be_exception.cpp: implementation of the be_exception class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "be_exception.h"

#ifdef USE_ATL7_MODULES
#define _Module _AtlBaseModule
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

be_exception::be_exception() :
    m_type(noParam),
    m_lParam1(0),
    m_lParam2(0),
    m_lErrNum(0),
    m_lWin32ErrNum(0),
    m_nStrId(0),
    m_bPrepared(false),
    m_bMsgReady(false)
{
}

be_exception::~be_exception()
{
}

stringx be_exception::get_message(bool bIncludeErrorNumber) const
{
    if (!m_bMsgReady)
    {
        m_bMsgReady = true;
        stringx sText;

        switch (m_type)
        {
		case preloaded:
			sText = m_sMsg;
			break;
        case noParam:
            sText.load_string(_Module.GetResourceInstance(), m_nStrId);
            break;            
        case oneStrParam:
            sText.format_string1(_Module.GetResourceInstance(), m_nStrId, m_sParam1);
            break;            
        case twoStrParams:
            sText.format_string2(_Module.GetResourceInstance(), m_nStrId, m_sParam1,
                m_sParam2);
            break;            
        case threeStrParams:
            sText.format_string3(_Module.GetResourceInstance(), m_nStrId, m_sParam1,
                m_sParam2, m_sParam3);
            break;            
        case fourStrParams:
            sText.format_string4(_Module.GetResourceInstance(), m_nStrId, m_sParam1,
                m_sParam2, m_sParam3, m_sParam4);
            break;            
        case oneLongParam:
            sText.load_string(_Module.GetResourceInstance(), m_nStrId);
            sText.format(sText, m_lParam1);
            break;            
        case twoLongParams:
            sText.load_string(_Module.GetResourceInstance(), m_nStrId);
            sText.format(sText, m_lParam1, m_lParam2);
            break;            
        }

		if(bIncludeErrorNumber)
		{
			m_sMsg.format(L"%d: %s", m_lErrNum, sText.c_str());
		}
		else
		{
			m_sMsg = sText;
		}

    }
    return m_sMsg;
}    

void be_exception::type_specific_throw() 
{
	throw *this;
}

void be_exception::throw_error()
{
	ATLASSERT (m_bPrepared);
	type_specific_throw();
}

void be_exception::prepare_error(const wchar_t* sError)
{
    clear();
    m_type = noParam;
    m_sMsg = sError;
    m_bMsgReady = true;
    m_bPrepared = true;
}

void be_exception::prepare_preloaded_error(long lErrNum, const stringx& sError)
{
    clear();
    m_type = preloaded;
    m_lErrNum = lErrNum;
    m_sMsg = sError;
    m_bPrepared = true;
}	

void be_exception::throw_error(long lErrNum, UINT nStrId)
{
    prepare_error(lErrNum, nStrId);
    type_specific_throw();
}    

void be_exception::prepare_error(long lErrNum, UINT nStrId)
{
    clear();
    m_type = noParam;
    m_lErrNum = lErrNum;
    m_nStrId = nStrId;
    m_bPrepared = true;
}    

void be_exception::throw_error(long lErrNum, UINT nStrId, const stringx& sParam1)
{
    prepare_error(lErrNum, nStrId, sParam1);
    type_specific_throw();
}

void be_exception::prepare_error(long lErrNum, UINT nStrId, const stringx& sParam1)
{
    clear();
    m_type = oneStrParam;
    m_lErrNum = lErrNum;
    m_nStrId = nStrId;
    m_sParam1 = sParam1;
    m_bPrepared = true;
}    

void be_exception::throw_error(long lErrNum, UINT nStrId, const stringx& sParam1,
    const stringx& sParam2)
{
    prepare_error(lErrNum, nStrId, sParam1, sParam2);
    type_specific_throw();
}

void be_exception::prepare_error(long lErrNum, UINT nStrId, const stringx& sParam1,
    const stringx& sParam2)
{
    clear();
    m_type = twoStrParams;
    m_lErrNum = lErrNum;
    m_nStrId = nStrId;
    m_sParam1 = sParam1;
    m_sParam2 = sParam2;
    m_bPrepared = true;
}    

void be_exception::throw_error(long lErrNum, UINT nStrId, const stringx& sParam1,
    const stringx& sParam2, const stringx& sParam3)
{
    prepare_error(lErrNum, nStrId, sParam1, sParam2, sParam3);
    type_specific_throw();
}

void be_exception::prepare_error(long lErrNum, UINT nStrId, const stringx& sParam1,
    const stringx& sParam2, const stringx& sParam3)
{
    clear();
    m_type = threeStrParams;
    m_lErrNum = lErrNum;
    m_nStrId = nStrId;
    m_sParam1 = sParam1;
    m_sParam2 = sParam2;
    m_sParam3 = sParam3;
    m_bPrepared = true;
}    

void be_exception::throw_error(long lErrNum, UINT nStrId, const stringx& sParam1,
    const stringx& sParam2, const stringx& sParam3, const stringx& sParam4)
{
    prepare_error(lErrNum, nStrId, sParam1, sParam2, sParam3, sParam4);
    type_specific_throw();
}

void be_exception::prepare_error(long lErrNum, UINT nStrId, const stringx& sParam1,
    const stringx& sParam2, const stringx& sParam3, const stringx& sParam4)
{
    clear();
    m_type = fourStrParams;
    m_lErrNum = lErrNum;
    m_nStrId = nStrId;
    m_sParam1 = sParam1;
    m_sParam2 = sParam2;
    m_sParam3 = sParam3;
    m_sParam4 = sParam4;
    m_bPrepared = true;
}    
void be_exception::throw_error(long lErrNum, UINT nStrId, long lParam1,
    long lParam2)
{
    prepare_error(lErrNum, nStrId, lParam1, lParam2);
    type_specific_throw();
}

void be_exception::prepare_error(long lErrNum, UINT nStrId, long lParam1,
    long lParam2)
{
    clear();
    m_type = twoLongParams;
    m_lErrNum = lErrNum;
    m_nStrId = nStrId;
    m_lParam1 = lParam1;
    m_lParam2 = lParam2;
    m_bPrepared = true;
}    

void be_exception::throw_win32_error(long lErrNum, UINT nStrId)
{
    prepare_win32_error(lErrNum, nStrId);
    type_specific_throw();
}    

void be_exception::prepare_win32_error(long lErrNum, UINT nStrId)
{
    add_win32_error();
    m_type = oneStrParam;
    m_lErrNum = lErrNum;
    m_nStrId = nStrId;
    m_bPrepared = true;
}    

void be_exception::throw_win32_error(long lErrNum, UINT nStrId, const stringx& sParam1)
{
    prepare_win32_error(lErrNum, nStrId, sParam1);
    type_specific_throw();
}    

void be_exception::prepare_win32_error(long lErrNum, UINT nStrId, const stringx& sParam1)
{
    add_win32_error();
    m_type = oneStrParam;
    m_lErrNum = lErrNum;
    m_nStrId = nStrId;
    m_sParam1 = sParam1;
    m_bPrepared = true;
}    

void be_exception::throw_win32_error(long lErrNum, UINT nStrId, const stringx& sParam1,
    const stringx& sParam2)
{
    prepare_win32_error(lErrNum, nStrId, sParam1, sParam2);
    type_specific_throw();
}    

void be_exception::prepare_win32_error(long lErrNum, UINT nStrId,
    const stringx& sParam1, const stringx& sParam2)
{
    add_win32_error();
    m_type = twoStrParams;
    m_lErrNum = lErrNum;
    m_nStrId = nStrId;
    m_sParam1 = sParam1;
    m_sParam2 = sParam2;
    m_bPrepared = true;
}

void be_exception::clear()
{
    m_type = noParam;
    m_sMsg.erase();
	m_sVerbose.erase();
    m_sParam1.erase();
    m_sParam2.erase();
    m_sParam3.erase();
	m_lParam1 = 0;
    m_lParam2 = 0;
    m_lErrNum = 0;
    m_lWin32ErrNum = 0;
    m_nStrId = 0;
    m_bPrepared = false;
    m_bMsgReady = false;
}    

void be_exception::add_info(exception& e)
{
    m_sVerbose = e.what();
}    

void be_exception::add_win32_error()
{
    long lWin32ErrNum = ::GetLastError();
    LPVOID lpMsgBuf;
    int nLen = ::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER  |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, lWin32ErrNum, 0, (LPTSTR)&lpMsgBuf, 0, NULL);
    clear();
    m_lWin32ErrNum = lWin32ErrNum;
    if (nLen)
    {
        m_sVerbose = (LPTSTR)lpMsgBuf;
        LocalFree(lpMsgBuf);
    }
}    

void be_exception::unhandled()
{
    m_sVerbose = L"Unknown Exception"; //@string
}    
