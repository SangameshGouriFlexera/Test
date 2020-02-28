#ifndef _WORKFLOW_DATA_ACCESSORS_H_
#define _WORKFLOW_DATA_ACCESSORS_H_

//-------------------------------------------------------------------------
#include <atldbcli.h>

//-------------------------------------------------------------------------
class CTemplatesAccessor
{
public:
	LONG m_TemplateID;
	DBSTATUS m_TemplateID_Status;
	TCHAR m_Name[256];
	TCHAR m_Description[256];
	LONG m_DateCreated;
	TCHAR m_Owner[256];
	TCHAR m_Children[256];

BEGIN_COLUMN_MAP(CTemplatesAccessor)
	COLUMN_ENTRY_STATUS(1, m_TemplateID, m_TemplateID_Status)
	COLUMN_ENTRY(2, m_Name)
	COLUMN_ENTRY(3, m_Description)
	COLUMN_ENTRY(4, m_DateCreated)
	COLUMN_ENTRY(5, m_Owner)
	COLUMN_ENTRY(6, m_Children)
END_COLUMN_MAP()

DEFINE_COMMAND(CTemplatesAccessor, _T(" \
	SELECT \
		TemplateID, \
		Name, \
		Description, \
		DateCreated, \
		Owner, \
		Children  \
		FROM wftblTemplates"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CToolAccessor30
{
public:
	LONG m_ToolID;
	DBSTATUS m_ToolID_Status;
	TCHAR m_Location[256];
	TCHAR m_Description[256];
	TCHAR m_HelpFile[256];
	TCHAR m_Arguments[256];
	TCHAR m_Comments[256];
	LONG m_ToolType;

BEGIN_COLUMN_MAP(CToolAccessor30)
	COLUMN_ENTRY_STATUS(1, m_ToolID, m_ToolID_Status)
	COLUMN_ENTRY(2, m_Location)
	COLUMN_ENTRY(3, m_Description)
	COLUMN_ENTRY(4, m_HelpFile)
	COLUMN_ENTRY(5, m_Arguments)
	COLUMN_ENTRY(6, m_Comments)
	COLUMN_ENTRY(7, m_ToolType)
END_COLUMN_MAP()

DEFINE_COMMAND(CToolAccessor30, _T(" \
	SELECT \
		ToolID, \
		Location, \
		Description, \
		HelpFile, \
		Arguments, \
		Comments, \
		ToolType \
		FROM Tools"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CToolAccessor35
{
public:
	LONG m_ToolID;
	DBSTATUS m_ToolID_Status;
	TCHAR m_Location[256];
	TCHAR m_Description[256];
	TCHAR m_HelpFile[256];
	TCHAR m_Arguments[256];
	TCHAR m_Comments[256];
	LONG m_ToolType;
	TCHAR m_WorkingDir[256];
	LONG m_ShowTool;

BEGIN_COLUMN_MAP(CToolAccessor35)
	COLUMN_ENTRY_STATUS(1, m_ToolID, m_ToolID_Status)
	COLUMN_ENTRY(2, m_Location)
	COLUMN_ENTRY(3, m_Description)
	COLUMN_ENTRY(4, m_HelpFile)
	COLUMN_ENTRY(5, m_Arguments)
	COLUMN_ENTRY(6, m_Comments)
	COLUMN_ENTRY(7, m_ToolType)
	COLUMN_ENTRY(8, m_WorkingDir)
	COLUMN_ENTRY(9, m_ShowTool)
END_COLUMN_MAP()

DEFINE_COMMAND(CToolAccessor35, _T(" \
	SELECT \
		ToolID, \
		Location, \
		Description, \
		HelpFile, \
		Arguments, \
		Comments, \
		ToolType, \
		WorkingDir, \
		ShowTool  \
		FROM Tools"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CToolAccessor
{
public:
	LONG m_ToolID;
	DBSTATUS m_ToolID_Status;
	TCHAR m_Location[256];
	TCHAR m_Description[256];
	TCHAR m_HelpFile[256];
	TCHAR m_Arguments[256];
	TCHAR m_Comments[256];
	LONG m_ToolType;
	TCHAR m_WorkingDir[256];
	LONG m_ShowTool;
	TCHAR m_ToolsIcon[256];
	LONG m_DisplayOrder;
	DBSTATUS m_DisplayOrder_Status;

BEGIN_COLUMN_MAP(CToolAccessor)
	COLUMN_ENTRY_STATUS(1, m_ToolID, m_ToolID_Status)
	COLUMN_ENTRY(2, m_Location)
	COLUMN_ENTRY(3, m_Description)
	COLUMN_ENTRY(4, m_HelpFile)
	COLUMN_ENTRY(5, m_Arguments)
	COLUMN_ENTRY(6, m_Comments)
	COLUMN_ENTRY(7, m_ToolType)
	COLUMN_ENTRY(8, m_WorkingDir)
	COLUMN_ENTRY(9, m_ShowTool)
	COLUMN_ENTRY(10, m_ToolsIcon)
	COLUMN_ENTRY_STATUS(11, m_DisplayOrder, m_DisplayOrder_Status)
END_COLUMN_MAP()

DEFINE_COMMAND(CToolAccessor, _T(" \
	SELECT \
		ToolID, \
		Location, \
		Description, \
		HelpFile, \
		Arguments, \
		Comments, \
		ToolType, \
		WorkingDir, \
		ShowTool,  \
		ToolsIcon, \
		DisplayOrder \
		FROM wftblTools"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CUserWorkflowAccessor30
{
public:
	LONG m_WorkflowID;
	DBSTATUS m_WorkflowID_Status;
	LONG m_UserID;
	TCHAR m_Name[256];
	TCHAR m_Description[256];
	LONG m_DateCreated;
	TCHAR m_Children[256];

BEGIN_COLUMN_MAP(CUserWorkflowAccessor30)
	COLUMN_ENTRY_STATUS(1, m_WorkflowID, m_WorkflowID_Status)
	COLUMN_ENTRY(2, m_UserID)
	COLUMN_ENTRY(3, m_Name)
	COLUMN_ENTRY(4, m_Description)
	COLUMN_ENTRY(5, m_DateCreated)
	COLUMN_ENTRY(6, m_Children)
END_COLUMN_MAP()

DEFINE_COMMAND(CUserWorkflowAccessor30, _T(" \
	SELECT \
		WorkflowID, \
		UserID, \
		Name, \
		Description, \
		DateCreated, \
		Children \
		FROM UserWorkflows"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CUserWorkflowAccessor35
{
public:
	LONG m_WorkflowID;
	DBSTATUS m_WorkflowID_Status;
	LONG m_UserID;
	TCHAR m_Name[256];
	TCHAR m_Description[256];
	LONG m_DateCreated;
	TCHAR m_Children[256];
	TCHAR m_SourcePackage[256];
	TCHAR m_OutputDir[256];
	TCHAR m_OutputFileName[256];

BEGIN_COLUMN_MAP(CUserWorkflowAccessor35)
	COLUMN_ENTRY_STATUS(1, m_WorkflowID, m_WorkflowID_Status)
	COLUMN_ENTRY(2, m_UserID)
	COLUMN_ENTRY(3, m_Name)
	COLUMN_ENTRY(4, m_Description)
	COLUMN_ENTRY(5, m_DateCreated)
	COLUMN_ENTRY(6, m_Children)
	COLUMN_ENTRY(7, m_SourcePackage)
	COLUMN_ENTRY(8, m_OutputDir)
	COLUMN_ENTRY(9, m_OutputFileName)
END_COLUMN_MAP()

DEFINE_COMMAND(CUserWorkflowAccessor35, _T(" \
	SELECT \
		WorkflowID, \
		UserID, \
		Name, \
		Description, \
		DateCreated, \
		Children, \
		SourcePackage, \
		OutputDir, \
		OutputFileName \
		FROM UserWorkflows"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CUserWorkflowAccessor
{
public:
	LONG m_WorkflowID;
	DBSTATUS m_WorkflowID_Status;
	LONG m_UserID;
	TCHAR m_Name[256];
	TCHAR m_Description[256];
	LONG m_DateCreated;
	TCHAR m_Children[256];
	TCHAR m_SourcePackage[256];
	TCHAR m_OutputDir[256];
	TCHAR m_OutputFileName[256];
	TCHAR m_UserName[256];

BEGIN_COLUMN_MAP(CUserWorkflowAccessor)
	COLUMN_ENTRY_STATUS(1, m_WorkflowID, m_WorkflowID_Status)
	COLUMN_ENTRY(2, m_UserID)
	COLUMN_ENTRY(3, m_Name)
	COLUMN_ENTRY(4, m_Description)
	COLUMN_ENTRY(5, m_DateCreated)
	COLUMN_ENTRY(6, m_Children)
	COLUMN_ENTRY(7, m_SourcePackage)
	COLUMN_ENTRY(8, m_OutputDir)
	COLUMN_ENTRY(9, m_OutputFileName)
	COLUMN_ENTRY(10, m_UserName)
END_COLUMN_MAP()

DEFINE_COMMAND(CUserWorkflowAccessor, _T(" \
	SELECT \
		WorkflowID, \
		UserID, \
		Name, \
		Description, \
		DateCreated, \
		Children, \
		SourcePackage, \
		OutputDir, \
		OutputFileName, \
		UserName  \
		FROM wftblUserWorkflows"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};


class CAMSAppAndWorkflow
{
public:
	TCHAR m_szAMSAppGUID[256];
	TCHAR m_szAMSAMSMjrItemGUID[256];

BEGIN_COLUMN_MAP(CAMSAppAndWorkflow)
	COLUMN_ENTRY(1, m_szAMSAppGUID)
	COLUMN_ENTRY(2, m_szAMSAMSMjrItemGUID)
END_COLUMN_MAP()

DEFINE_COMMAND(CAMSAppAndWorkflow, _T(" \
	SELECT [a].[AMSAppGUID_], [a].[AMSWFMjrItemGUID_] FROM [asAMSWorkflowProjects] AS [a] WHERE [ASProjectID_] = %ld AND 0 = (SELECT COUNT([WorkflowID]) FROM [wftblWorkflowTasks] WHERE [Status] = 0 AND [WorkflowID]=%ld)"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

class CASWorkflow
{
public:
	TCHAR m_szWorkflowID[256];
	TCHAR m_szAMSAMSMjrItemGUID[256];

BEGIN_COLUMN_MAP(CAMSAppAndWorkflow)
	COLUMN_ENTRY(1, m_szAMSAppGUID)
	COLUMN_ENTRY(2, m_szAMSAMSMjrItemGUID)
END_COLUMN_MAP()

DEFINE_COMMAND(CAMSAppAndWorkflow, _T(" \
	SELECT [a].[AMSAppGUID_], [a].[AMSWFMjrItemGUID_] FROM [asAMSWorkflowProjects] AS [a] WHERE [ASProjectID_] = %ld AND 0 = (SELECT COUNT([WorkflowID]) FROM [wftblWorkflowTasks] WHERE [Status] = 0 AND [WorkflowID]=%ld)"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CTemplateWorkflowAccessor
{
public:
	LONG m_TemplateID;
	LONG m_WorkflowID;
	LONG m_ModifiedFlag;

BEGIN_COLUMN_MAP(CTemplateWorkflowAccessor)
	COLUMN_ENTRY(1, m_TemplateID)
	COLUMN_ENTRY(2, m_WorkflowID)
	COLUMN_ENTRY(3, m_ModifiedFlag)
END_COLUMN_MAP()

DEFINE_COMMAND(CTemplateWorkflowAccessor, _T(" \
	SELECT \
		TemplateID, \
		WorkflowID, \
		ModifiedFlag  \
		FROM wftblTemplateWorkflow"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CCommandLinesAccessor
{
public:
	LONG m_CommandLineID;
	DBSTATUS m_CommandLineID_Status;
	LONG m_ToolID;
	TCHAR m_Description[256];
	TCHAR m_CommandLine[256];

BEGIN_COLUMN_MAP(CCommandLinesAccessor)
	COLUMN_ENTRY_STATUS(1, m_CommandLineID, m_CommandLineID_Status)
	COLUMN_ENTRY(2, m_ToolID)
	COLUMN_ENTRY(3, m_Description)
	COLUMN_ENTRY(4, m_CommandLine)
END_COLUMN_MAP()

DEFINE_COMMAND(CCommandLinesAccessor, _T(" \
	SELECT \
		CommandLineID, \
		ToolID, \
		Description, \
		CommandLine  \
		FROM wftblCommandLines"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CWorkflowTasksAccessor30
{
public:
	LONG m_WorkflowID;
	LONG m_TaskID;
	TCHAR m_Description[256];
	LONG m_ParentTaskID;
	LONG m_TaskType;
	LONG m_ToolID;
	TCHAR m_HelpFile[256];
	TCHAR m_Arguments[256];
	TCHAR m_Notes[256];
	LONG m_Status;
	LONG m_DateCompleted;
	LONG m_TemplateTaskID;
	TCHAR m_Children[256];

BEGIN_COLUMN_MAP(CWorkflowTasksAccessor30)
	COLUMN_ENTRY(1, m_WorkflowID)
	COLUMN_ENTRY(2, m_TaskID)
	COLUMN_ENTRY(3, m_Description)
	COLUMN_ENTRY(4, m_ParentTaskID)
	COLUMN_ENTRY(5, m_TaskType)
	COLUMN_ENTRY(6, m_ToolID)
	COLUMN_ENTRY(7, m_HelpFile)
	COLUMN_ENTRY(8, m_Arguments)
	COLUMN_ENTRY(9, m_Notes)
	COLUMN_ENTRY(10, m_Status)
	COLUMN_ENTRY(11, m_DateCompleted)
	COLUMN_ENTRY(12, m_TemplateTaskID)
	COLUMN_ENTRY(13, m_Children)
END_COLUMN_MAP()

DEFINE_COMMAND(CWorkflowTasksAccessor30, _T(" \
	SELECT \
		WorkflowID, \
		TaskID, \
		Description, \
		ParentTaskID, \
		TaskType, \
		ToolID, \
		HelpFile, \
		Arguments, \
		Notes, \
		Status, \
		DateCompleted, \
		TemplateTaskID, \
		Children \
		FROM wftblWorkflowTasks"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CWorkflowTasksAccessor
{
public:
	LONG m_WorkflowID;
	LONG m_TaskID;
	TCHAR m_Description[256];
	LONG m_ParentTaskID;
	LONG m_TaskType;
	LONG m_ToolID;
	TCHAR m_HelpFile[256];
	TCHAR m_Arguments[256];
	TCHAR m_Notes[256];
	LONG m_Status;
	LONG m_DateCompleted;
	LONG m_TemplateTaskID;
	TCHAR m_Children[256];
	LONG m_CommandLineID;

BEGIN_COLUMN_MAP(CWorkflowTasksAccessor)
	COLUMN_ENTRY(1, m_WorkflowID)
	COLUMN_ENTRY(2, m_TaskID)
	COLUMN_ENTRY(3, m_Description)
	COLUMN_ENTRY(4, m_ParentTaskID)
	COLUMN_ENTRY(5, m_TaskType)
	COLUMN_ENTRY(6, m_ToolID)
	COLUMN_ENTRY(7, m_HelpFile)
	COLUMN_ENTRY(8, m_Arguments)
	COLUMN_ENTRY(9, m_Notes)
	COLUMN_ENTRY(10, m_Status)
	COLUMN_ENTRY(11, m_DateCompleted)
	COLUMN_ENTRY(12, m_TemplateTaskID)
	COLUMN_ENTRY(13, m_Children)
	COLUMN_ENTRY(14, m_CommandLineID)
END_COLUMN_MAP()

DEFINE_COMMAND(CWorkflowTasksAccessor, _T(" \
	SELECT \
		WorkflowID, \
		TaskID, \
		Description, \
		ParentTaskID, \
		TaskType, \
		ToolID, \
		HelpFile, \
		Arguments, \
		Notes, \
		Status, \
		DateCompleted, \
		TemplateTaskID, \
		Children, \
		CommandLineID  \
		FROM wftblWorkflowTasks"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CTemplateTasksAccessor30
{
public:
	LONG m_TemplateID;
	LONG m_TaskID;
	DBSTATUS m_TaskID_Status;
	TCHAR m_Description[256];
	LONG m_ParentTaskID;
	LONG m_TaskType;
	LONG m_ToolID;
	TCHAR m_HelpFile[256];
	TCHAR m_Arguments[256];
	TCHAR m_Notes[256];
	TCHAR m_Children[256];

BEGIN_COLUMN_MAP(CTemplateTasksAccessor30)
	COLUMN_ENTRY(1, m_TemplateID)
	COLUMN_ENTRY_STATUS(2, m_TaskID, m_TaskID_Status)
	COLUMN_ENTRY(3, m_Description)
	COLUMN_ENTRY(4, m_ParentTaskID)
	COLUMN_ENTRY(5, m_TaskType)
	COLUMN_ENTRY(6, m_ToolID)
	COLUMN_ENTRY(7, m_HelpFile)
	COLUMN_ENTRY(8, m_Arguments)
	COLUMN_ENTRY(9, m_Notes)
	COLUMN_ENTRY(10, m_Children)
END_COLUMN_MAP()

DEFINE_COMMAND(CTemplateTasksAccessor30, _T(" \
	SELECT \
		TemplateID, \
		TaskID, \
		Description, \
		ParentTaskID, \
		TaskType, \
		ToolID, \
		HelpFile, \
		Arguments, \
		Notes, \
		Children \
		FROM TemplateTasks"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

//-------------------------------------------------------------------------
class CTemplateTasksAccessor
{
public:
	LONG m_TemplateID;
	LONG m_TaskID;
	DBSTATUS m_TaskID_Status;
	TCHAR m_Description[256];
	LONG m_ParentTaskID;
	LONG m_TaskType;
	LONG m_ToolID;
	TCHAR m_HelpFile[256];
	TCHAR m_Arguments[256];
	TCHAR m_Notes[256];
	TCHAR m_Children[256];
	LONG m_CommandLineID;

BEGIN_COLUMN_MAP(CTemplateTasksAccessor)
	COLUMN_ENTRY(1, m_TemplateID)
	COLUMN_ENTRY_STATUS(2, m_TaskID, m_TaskID_Status)
	COLUMN_ENTRY(3, m_Description)
	COLUMN_ENTRY(4, m_ParentTaskID)
	COLUMN_ENTRY(5, m_TaskType)
	COLUMN_ENTRY(6, m_ToolID)
	COLUMN_ENTRY(7, m_HelpFile)
	COLUMN_ENTRY(8, m_Arguments)
	COLUMN_ENTRY(9, m_Notes)
	COLUMN_ENTRY(10, m_Children)
	COLUMN_ENTRY(11, m_CommandLineID)
END_COLUMN_MAP()

DEFINE_COMMAND(CTemplateTasksAccessor, _T(" \
	SELECT \
		TemplateID, \
		TaskID, \
		Description, \
		ParentTaskID, \
		TaskType, \
		ToolID, \
		HelpFile, \
		Arguments, \
		Notes, \
		Children, \
		CommandLineID  \
		FROM wftblTemplateTasks"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};


#endif // _WORKFLOW_DATA_ACCESSORS_H_