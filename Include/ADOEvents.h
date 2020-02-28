#ifndef _ADO_EVENTS_H
#define _ADO_EVENTS_H

template <class T>
class ATL_NO_VTABLE IAdoConnectionEventImpl : public ConnectionEventsVt
{
public:

	STDMETHOD(InfoMessage)(struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection)
	{
		*adStatus = adStatusUnwantedEvent; 
		return S_OK;
	}

	STDMETHOD(BeginTransComplete)(LONG TransactionLevel, struct Error * pError, enum EventStatusEnum * adStatus,
									struct _Connection * pConnection)
	{
		*adStatus = adStatusUnwantedEvent; 
		return S_OK;
	}

	STDMETHOD(CommitTransComplete)(struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection)
	{
	    *adStatus = adStatusUnwantedEvent; 
		return S_OK;
	}
        
    STDMETHOD(RollbackTransComplete)(struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection)
	{
		*adStatus = adStatusUnwantedEvent; 
		return S_OK;
	}

        
    STDMETHOD(WillExecute)(BSTR * Source, enum CursorTypeEnum * CursorType, enum LockTypeEnum * LockType,
							long * Options, enum EventStatusEnum * adStatus, struct _Command * pCommand,
							struct _Recordset * pRecordset, struct _Connection * pConnection)
	{
		*adStatus = adStatusUnwantedEvent; 
		return S_OK;
    }   
        
	STDMETHOD(ExecuteComplete)(LONG RecordsAffected, struct Error * pError, enum EventStatusEnum * adStatus,
								struct _Command * pCommand, struct _Recordset * pRecordset, struct _Connection * pConnection)
	{
		*adStatus = adStatusUnwantedEvent; 
		return S_OK;
	}

        
	STDMETHOD(WillConnect)(BSTR * ConnectionString, BSTR * UserID, BSTR * Password, long * Options,
							enum EventStatusEnum * adStatus, struct _Connection  *pConnection) 
	{
		*adStatus = adStatusUnwantedEvent; 
		return S_OK;
	}

        
	STDMETHOD(ConnectComplete)(struct Error * pError, enum EventStatusEnum * adStatus, struct _Connection * pConnection)
	{
		*adStatus = adStatusUnwantedEvent; 
		return S_OK;
	}

        
    STDMETHOD(Disconnect)(enum EventStatusEnum * adStatus, struct _Connection * pConnection)
	{
		*adStatus = adStatusUnwantedEvent; 
		return S_OK;
	}

	HRESULT GetAdoErrorMessage(struct Error *pError, BSTR *pbstrError)
	{
		if(pError)
		{
			long nCount = 0;
			pError->get_Description(pbstrError);
		}
		return S_OK;
	}
};

#endif //_ADO_EVENTS_H