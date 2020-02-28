#pragma once


struct EventMessage
{
	enum Type { info, warning, error, build, progress };

	EventMessage(UINT nID) : m_type(info), m_nErrCode(0)
	{
		m_msg.LoadString(nID);
	}
	
	EventMessage(Type t, CString msg, DWORD code = 0)
		: m_type(t), m_msg(msg), m_nErrCode(code)
	{
	}

	EventMessage(Type t, UINT nID = 0, DWORD code = 0)
		: m_type(t), m_nErrCode(code)
	{
		if (nID) m_msg.LoadString(nID);
	}

	Type m_type;
	CString m_msg;
	DWORD m_nErrCode;
	UINT m_nProgress;
};


typedef void (CALLBACK *EventCallback)(EventMessage& ev);