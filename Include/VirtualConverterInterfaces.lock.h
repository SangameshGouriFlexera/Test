#pragma once

class IVirtualConvertEvent
{
public:
	virtual void StatusMessage (BSTR bstrMessage, bool bIsVerbose)=0;
	virtual void LogError(long lErrorNum, BSTR bstrErrorMsg)=0;
	virtual void LogWarning(long lWarningNum, BSTR bstrWarningMsg)=0;	
	virtual void ProgressIncrement (long lIncrement, bool *pbCancel)=0;
	virtual void ProgressMax (long lMax, bool *pbCancel)=0;
	virtual void TestCancel (bool *pbCancel)=0;
};


int WINAPI BuildVirtual(LPCWSTR lpszSourceFile, LPCWSTR lpszTargetFile, IVirtualConvertEvent* pEvent);