#ifndef __ASLOCALIZEHELPER_H
#define __ASLOCALIZEHELPER_H


/*
*
* ASLocalizeHelper contains string formatting functions to format strings using
* %1, %2, etc. instead of using %s, %d. These are used to allow for arbitrary ordering
* of format specifiers in a string such that the format specifier orders can 
* be reordered during translation of strings without causing any issues based on the 
* original function call parameters.
*
* These functions are taken from stringx.h and modified to work with CString.
*
*/
namespace ASLocalizeHelper {
	CString static load_helper(UINT uiId)
	{
		CString strResult;
		strResult.LoadString(uiId);
		return strResult;
	}

	CString static format_strings(const TCHAR* fmtstr, const TCHAR** rglpsz, int nString)
    {
        // determine length of destination string
        int nTotalLen = 0;
        const TCHAR* pchSrc = fmtstr;
        while (*pchSrc != _T('\0'))
        {
            if (pchSrc[0] == _T('%') &&
                 ( (pchSrc[1] >= _T('0') && pchSrc[1] <= _T('9')) ||
                    (pchSrc[1] >= _T('A') && pchSrc[1] <= _T('Z'))) )
            {
                // %A comes after %9 -- we'll need it someday
                int i;
                if (pchSrc[1] > _T('9'))
                    i = 9 + (pchSrc[1] - _T('A'));
                else
                    i = pchSrc[1] - _T('1');
                pchSrc += 2;
                if (i >= nString)
                    ++nTotalLen;
                else if (rglpsz[i] != NULL)
                    nTotalLen += _tcslen(rglpsz[i]);
            }
            else
            {
                if (_istlead(*pchSrc))
                    ++nTotalLen, ++pchSrc;
                ++pchSrc;
                ++nTotalLen;
            }
        }

        pchSrc = fmtstr;

		CString strDest;

		TCHAR* pchDest = strDest.GetBuffer(nTotalLen);

        while (*pchSrc != _T('\0'))
        {
            if (pchSrc[0] == _T('%') &&
                 ( (pchSrc[1] >= _T('0') && pchSrc[1] <= _T('9')) ||
                    (pchSrc[1] >= _T('A') && pchSrc[1] <= _T('Z'))) )
            {
                // %A comes after %9 -- we'll need it someday
                int i;
                if (pchSrc[1] > _T('9'))
                    i = 9 + (pchSrc[1] - _T('A'));
                else
                    i = pchSrc[1] - _T('1');
                pchSrc += 2;
                if (i >= nString)
                {
                    *pchDest++ = _T('?');
                }
                else if (rglpsz[i] != NULL)
                {
                    _tcscpy(pchDest, rglpsz[i]);
                    pchDest += _tcslen(pchDest);
                }
            }
            else
            {
                if (_istlead(*pchSrc))
                    *pchDest++ = *pchSrc++; // copy first of 2 bytes
                *pchDest++ = *pchSrc++;
            }
        }
        *pchDest = _T('\0');

		strDest.ReleaseBuffer();

		return strDest;
    }

	//
	// Format a string with nString number of format specifiers. rglpsz is an 
	// array of pointers to the strings to be inserted in the format string.
	//
    CString static format_strings(UINT nIDS, const TCHAR** rglpsz, int nString)
    {
		CString strFormat;
		strFormat.LoadString(nIDS);
		if(strFormat.IsEmpty())
			return CString("");

        return format_strings(strFormat, rglpsz, nString);
    }

	//
	// Format a string with one format specifier.
	//
    CString static format_strings(UINT nIDS, const TCHAR* lpsz1)
    {
        return format_strings(nIDS, &lpsz1, 1);
    }

	//
	// Format a string with two format specifiers.
	//
    CString static format_strings(UINT nIDS, const TCHAR* lpsz1,
        const TCHAR* lpsz2)
    {
        const TCHAR* rglpsz[2];
        rglpsz[0] = lpsz1;
        rglpsz[1] = lpsz2;
        return format_strings(nIDS, rglpsz, 2);
    }

	//
	// Format a string with three format specifiers.
	//
    CString static format_strings(UINT nIDS, const TCHAR* lpsz1,
        const TCHAR* lpsz2, const TCHAR* lpsz3)
    {
        const TCHAR* rglpsz[3];
        rglpsz[0] = lpsz1;
        rglpsz[1] = lpsz2;
        rglpsz[2] = lpsz3;
        return format_strings(nIDS, rglpsz, 3);
    }

	//
	// Format a string with four format specifiers.
	//
    CString static format_strings(UINT nIDS, const TCHAR* lpsz1,
        const TCHAR* lpsz2, const TCHAR* lpsz3, const TCHAR* lpsz4)
    {
        const TCHAR* rglpsz[4];
        rglpsz[0] = lpsz1;
        rglpsz[1] = lpsz2;
        rglpsz[2] = lpsz3;
        rglpsz[3] = lpsz4;
        return format_strings(nIDS, rglpsz, 4);
    }

	CString static format_strings(UINT nIDS, const TCHAR* lpsz1,
		const TCHAR* lpsz2, const TCHAR* lpsz3, const TCHAR* lpsz4,
		const TCHAR* lpsz5)
	{
		const TCHAR *rglpsz[5];
		rglpsz[0] = lpsz1;
		rglpsz[1] = lpsz2;
		rglpsz[2] = lpsz3;
		rglpsz[3] = lpsz4;
		rglpsz[4] = lpsz5;
		return format_strings(nIDS, rglpsz, 5);
	}

	CString static format_strings(UINT nIDS, const TCHAR* lpsz1,
		const TCHAR* lpsz2, const TCHAR* lpsz3, const TCHAR* lpsz4,
		const TCHAR* lpsz5, const TCHAR* lpsz6)
	{
		const TCHAR *rglpsz[6];
		rglpsz[0] = lpsz1;
		rglpsz[1] = lpsz2;
		rglpsz[2] = lpsz3;
		rglpsz[3] = lpsz4;
		rglpsz[4] = lpsz5;
		rglpsz[5] = lpsz6;
		return format_strings(nIDS, rglpsz, 6);
	}


	CString static format_strings(UINT nIDS, const TCHAR* lpsz1,
		const TCHAR* lpsz2, const TCHAR* lpsz3, const TCHAR* lpsz4,
		const TCHAR* lpsz5, const TCHAR* lpsz6, const TCHAR* lpsz7)
	{
		const TCHAR *rglpsz[7];
		rglpsz[0] = lpsz1;
		rglpsz[1] = lpsz2;
		rglpsz[2] = lpsz3;
		rglpsz[3] = lpsz4;
		rglpsz[4] = lpsz5;
		rglpsz[5] = lpsz6;
		rglpsz[6] = lpsz7;
		return format_strings(nIDS, rglpsz, 7);
	}

	CString static format_strings(UINT nIDS, const TCHAR* lpsz1,
		const TCHAR* lpsz2, const TCHAR* lpsz3, const TCHAR* lpsz4,
		const TCHAR* lpsz5, const TCHAR* lpsz6, const TCHAR* lpsz7,
		const TCHAR* lpsz8)
	{
		const TCHAR *rglpsz[8];
		rglpsz[0] = lpsz1;
		rglpsz[1] = lpsz2;
		rglpsz[2] = lpsz3;
		rglpsz[3] = lpsz4;
		rglpsz[4] = lpsz5;
		rglpsz[5] = lpsz6;
		rglpsz[6] = lpsz7;
		rglpsz[7] = lpsz8;
		return format_strings(nIDS, rglpsz, 8);
	}

	CString static format_strings(const TCHAR* fmtstr, const TCHAR* lpsz1)
	{
		return format_strings(fmtstr, &lpsz1, 1);
	}

	CString static format_strings(const TCHAR* fmtstr, const TCHAR* lpsz1, const TCHAR* lpsz2)
	{
		const TCHAR* rglpsz[2];
		rglpsz[0] = lpsz1;
		rglpsz[1] = lpsz2;
		return format_strings(fmtstr, rglpsz, 2);
	}

	CString static format_strings(const TCHAR* fmtstr, const TCHAR* lpsz1, const TCHAR* lpsz2,
		const TCHAR* lpsz3)
	{
		const TCHAR* rglpsz[3];
		rglpsz[0] = lpsz1;
		rglpsz[1] = lpsz2;
		rglpsz[2] = lpsz3;
		return format_strings(fmtstr, rglpsz, 3);
	}

	CString static format_strings(const TCHAR* fmtstr, const TCHAR* lpsz1, const TCHAR* lpsz2,
		const TCHAR* lpsz3, const TCHAR* lpsz4)
	{
		const TCHAR* rglpsz[4];
		rglpsz[0] = lpsz1;
		rglpsz[1] = lpsz2;
		rglpsz[2] = lpsz3;
		rglpsz[3] = lpsz4;
		return format_strings(fmtstr, rglpsz, 4);
	}

	CString static format_strings(const TCHAR* fmtstr, const TCHAR* lpsz1, const TCHAR* lpsz2,
		const TCHAR* lpsz3, const TCHAR* lpsz4, const TCHAR* lpsz5)
	{
		const TCHAR* rglpsz[5];
		rglpsz[0] = lpsz1;
		rglpsz[1] = lpsz2;
		rglpsz[2] = lpsz3;
		rglpsz[3] = lpsz4;
		rglpsz[4] = lpsz5;
		return format_strings(fmtstr, rglpsz, 5);
	}

	//
	// Return a CString string of the number 'Value'.
	//
	CString static IntToCString(const int Value, int radix = 10)
	{
		TCHAR buffer[32];

		_itot(Value, buffer, radix);

		CString retstr(buffer);

		return retstr;
	}

}

#endif // __ASLOCALIZEHELPER_H