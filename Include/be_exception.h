// be_exception.h: interface for the be_exception class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BE_EXCEPTION_H__8BB8A2E9_FFE8_40DC_AECB_6ACDF3A4415B__INCLUDED_)
#define AFX_BE_EXCEPTION_H__8BB8A2E9_FFE8_40DC_AECB_6ACDF3A4415B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stringx.h"

class be_exception : public exception  
{             
public:
    be_exception();
    virtual ~be_exception();
	// Attn: inheriting classes: Override so that it throws your type instead be_exception.
	virtual void type_specific_throw();

    void clear();
	void throw_error();

    // not using stringx to prevent stringx's automatic ctor that 
    // takes an integer
    void prepare_error(const wchar_t* sError);
	
	// only use if you have are getting the error from a source that has
	// arleady loaded the string from the string table
	void prepare_preloaded_error(long lErrNum, const stringx& sError);
    
    void throw_error(long lErrNum, UINT nStrId);
    void prepare_error(long lErrNum, UINT nStrId);
    void throw_error(long lErrNum, UINT nStrId, const stringx& sParam1);
    void prepare_error(long lErrNum, UINT nStrId, const stringx& sParam1);
    void throw_error(long lErrNum, UINT nStrId, const stringx& sParam1,
        const stringx& sParam2);
    void prepare_error(long lErrNum, UINT nStrId, const stringx& sParam1,
        const stringx& sParam2);
    void throw_error(long lErrNum, UINT nStrId, const stringx& sParam1,
        const stringx& sParam2, const stringx& sParam3);
    void prepare_error(long lErrNum, UINT nStrId, const stringx& sParam1,
        const stringx& sParam2, const stringx& sParam3);
    void throw_error(long lErrNum, UINT nStrId, const stringx& sParam1,
        const stringx& sParam2, const stringx& sParam3, const stringx& sParam4);
    void prepare_error(long lErrNum, UINT nStrId, const stringx& sParam1,
        const stringx& sParam2, const stringx& sParam3, const stringx& sParam4);
    void throw_error(long lErrNum, UINT nStrId, long lParam1, long lParam2);
    void prepare_error(long lErrNum, UINT nStrId, long lParam1, long lParam2);
    void throw_win32_error(long lErrNum, UINT nStrId);
    void prepare_win32_error(long lErrNum, UINT nStrId);
    void throw_win32_error(long lErrNum, UINT nStrId, const stringx& sParam1);
    void prepare_win32_error(long lErrNum, UINT nStrId, const stringx& sParam1);
    void throw_win32_error(long lErrNum, UINT nStrId, const stringx& sParam1,
        const stringx& sParam2);
    void prepare_win32_error(long lErrNum, UINT nStrId, const stringx& sParam1,
        const stringx& sParam2);

    void add_info(exception& e);
    void add_win32_error();
    void unhandled();
    bool is_prepared()
    {
        return m_bPrepared;
    }

	UINT get_str_id(){return m_nStrId;};
	stringx get_sParam1(){return m_sParam1;};
    stringx get_sParam2(){return m_sParam2;};

	long get_error_number() const
	{
		return m_lErrNum;
	}
    stringx get_message(bool bIncludeErrorNumber = true) const;
    stringx get_verbose() const
    {
        return m_sVerbose;
    }
    void put_verbose(const stringx& sVerbose)
    {
        ATLASSERT(m_sVerbose.empty());
        m_sVerbose = sVerbose;;
    }

protected:
    stringx m_sVerbose;

private:
    enum 
    {
        preloaded,
        noParam,
        oneStrParam,
        twoStrParams,
        threeStrParams,
		fourStrParams,
        oneLongParam,
        twoLongParams
    } m_type;
    mutable stringx m_sMsg;
    stringx m_sParam1;
    stringx m_sParam2;
    stringx m_sParam3;
    stringx m_sParam4;
    long m_lParam1;
    long m_lParam2;
    long m_lErrNum;
    long m_lWin32ErrNum;
    UINT m_nStrId;
    bool m_bPrepared;
    mutable bool m_bMsgReady;
};
#endif // !defined(AFX_BE_EXCEPTION_H__8BB8A2E9_FFE8_40DC_AECB_6ACDF3A4415B__INCLUDED_)
