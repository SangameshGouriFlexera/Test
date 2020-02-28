#if !defined(PARSE_UTIL_H)
#define PARSE_UTIL_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <VECTOR>
using namespace std;

class CParseUtil
{
public:
    typedef vector<CString> VEC_SUBSTRINGS;

	// Split sString into substrings using delimiter character ch
    static void Parse(TCHAR ch, const CString& sString, VEC_SUBSTRINGS &vecSubs)
    {
        if (!sString.GetLength())
            return;
        int iStart = 0;
        int iEnd = 0;
        iEnd = sString.Find(ch, iStart);
        while (iEnd != -1)
        {
            vecSubs.push_back(sString.Mid(iStart, iEnd - iStart));
            iStart = iEnd + 1;
            iEnd = sString.Find(ch, iStart);
        }
        vecSubs.push_back(sString.Mid(iStart, sString.GetLength() - iStart));
    }

	// Split sString into substrings using delimiter string sDelim
    static bool Split(TCHAR ch, const CString& sString, CString& sName, CString& sValue)
    {
        int iPos = sString.Find(ch);
        if (iPos != -1)
        {
            sName = sString.Left(iPos);
            sValue = sString.Right(sString.GetLength() - iPos - 1);
            return true;
        }
        return false;
    }

	// Split sString into substrings using delimiter character ch
    static void Parse(const CString& sDelim, const CString& sString, VEC_SUBSTRINGS &vecSubs)
    {
        if (!sString.GetLength())
            return;
        int iStart = 0;
        int iEnd = 0;
        iEnd = sString.Find(sDelim, iStart);
        while (iEnd != -1)
        {
            vecSubs.push_back(sString.Mid(iStart, iEnd - iStart));
            iStart = iEnd + sDelim.GetLength();
            iEnd = sString.Find(sDelim, iStart);
        }
        vecSubs.push_back(sString.Mid(iStart, sString.GetLength() - iStart));
    }
};

#endif // !defined(PARSE_UTIL_H)