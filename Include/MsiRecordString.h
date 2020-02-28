#ifndef __MsiRecordString_h__
#define __MsiRecordString_h__

#include <msiquery.h>

// user-defined namespace for MSI API
#ifndef MSI
#define MSI
#endif

class CMsiRecordString
{
public:
	explicit CMsiRecordString(MSIHANDLE hRecord, UINT iField)
		: m_pAllocBuf(NULL)
	{
		DWORD cchValue = 512;

		m_nRes = MSI::MsiRecordGetString(hRecord, iField, m_szBuf, &cchValue);

		if (m_nRes == ERROR_MORE_DATA)
		{
			UINT iSize = MSI::MsiRecordDataSize(hRecord, iField);

			m_pAllocBuf = new TCHAR[iSize*2 + 1];
			cchValue = iSize*2 + 1;

			m_nRes = MSI::MsiRecordGetString(hRecord, iField, m_pAllocBuf, &cchValue);

			if (m_nRes != ERROR_SUCCESS)
			{
				delete []m_pAllocBuf;
				m_pAllocBuf = NULL;
			}
		}
	}

	~CMsiRecordString()
	{
		delete[]m_pAllocBuf;
	}

	operator LPCTSTR()
	{
		if (ERROR_SUCCESS != m_nRes)
			return NULL;

		return m_pAllocBuf?m_pAllocBuf:m_szBuf;
	}

	UINT Result()
	{
		return m_nRes;
	}

private:
	LPTSTR	m_pAllocBuf;
	TCHAR	m_szBuf[512];
	UINT	m_nRes;
};

#endif