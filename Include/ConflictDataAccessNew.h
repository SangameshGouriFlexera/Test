#if !defined(CONFLIC_DATA_ACCESS_INCLUDED_)
#define CONFLIC_DATA_ACCESS_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "atldbcli.h"
/////////////////////////////////////////////////////////////////////////////
// CSchemaInfo class
class CsysSchemaInfoAccessor
{
public:
	long m_UniqueID;

BEGIN_COLUMN_MAP(CsysSchemaInfoAccessor)
	COLUMN_ENTRY(1, m_UniqueID)
END_COLUMN_MAP()

DEFINE_COMMAND(CsysSchemaInfoAccessor, _T("SELECT UniqueID FROM cssysSchemaInfo"))


	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

/////////////////////////////////////////////////////////////////////////////
// CSchemaInfo class
class CSchemaInfoAccessor35
{
public:
	TCHAR m_SchemaVersion[21];
	LONG m_UniqueID;
	TCHAR m_LastUser[129];
	DATE  m_LastUsed;

BEGIN_COLUMN_MAP(CSchemaInfoAccessor35)
	COLUMN_ENTRY(1, m_SchemaVersion)
	COLUMN_ENTRY(2, m_UniqueID)
	COLUMN_ENTRY(3, m_LastUser)
	COLUMN_ENTRY_TYPE(4, DBTYPE_DATE, m_LastUsed)
END_COLUMN_MAP()

DEFINE_COMMAND(CSchemaInfoAccessor35, _T("SELECT Version, UnqiueIdentifier, LastUser, LastUsed FROM SummaryInformation"))


	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

/////////////////////////////////////////////////////////////////////////////
// CWFSchemaInfoAccessor35 class
class CWFSchemaInfoAccessor35
{
public:
	LONG m_Version;
	LONG m_UniqueID;

BEGIN_COLUMN_MAP(CWFSchemaInfoAccessor35)
	COLUMN_ENTRY(1, m_Version)
	COLUMN_ENTRY(2, m_UniqueID)
END_COLUMN_MAP()

DEFINE_COMMAND(CWFSchemaInfoAccessor35, _T("SELECT Version, UniqueId FROM SummaryInformation"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

/////////////////////////////////////////////////////////////////////////////
// CWorkflowSchemaInfoAccessor class
class CWorkflowSchemaInfoAccessor
{
public:
	LONG m_RowID;
	TCHAR m_SchemaVersion[21];

BEGIN_COLUMN_MAP(CWorkflowSchemaInfoAccessor)
	COLUMN_ENTRY(1, m_RowID)
	COLUMN_ENTRY(2, m_SchemaVersion)
END_COLUMN_MAP()

DEFINE_COMMAND(CWorkflowSchemaInfoAccessor, _T("SELECT RowID, SchemaVersion FROM AMS_SchemaInfo"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

#endif // !defined(CONFLIC_DATA_ACCESS_INCLUDED_)
