#ifndef _CCOUNTSTREAM_H_
#define _CCOUNTSTREAM_H_

/* This is a dummy class which will be used in calculating how much is the
Stream size required for a particular save operation, using Actual IStream*/


class CCountStream : public IStream
{
private:
	ULONG m_nTotalSize;

public:
	CCountStream():m_nTotalSize(0){}
	
	STDMETHODIMP_(HRESULT) QueryInterface(REFIID iid, void** ppvObject)
	{
		return E_NOTIMPL;
	}
	STDMETHODIMP_(ULONG)  AddRef(){return 0;}
	STDMETHODIMP_(ULONG)  Release(){return 0;}

	STDMETHODIMP_(HRESULT) Seek(LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER* plibNewPosition)
	{
		return E_NOTIMPL;
	}

	STDMETHODIMP_(HRESULT) SetSize(ULARGE_INTEGER libNewSize)
	{
		return E_NOTIMPL;
	}

	STDMETHODIMP_(HRESULT) CopyTo(IStream* pstm, ULARGE_INTEGER cb, ULARGE_INTEGER* pcbRead, ULARGE_INTEGER* pcbWritten)
	{
		return E_NOTIMPL;
	}

	STDMETHODIMP_(HRESULT) Commit(DWORD grfCommitFlags)
	{
		return E_NOTIMPL;
	}

	STDMETHODIMP_(HRESULT) Revert( void) 
	{
		return E_NOTIMPL;
	}

	STDMETHODIMP_(HRESULT) LockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType)
	{
		return E_NOTIMPL;
	}

	STDMETHODIMP_(HRESULT) UnlockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType)
	{
		return E_NOTIMPL;
	}

	STDMETHODIMP_(HRESULT) Stat(STATSTG* pstatstg, DWORD grfStatFlag)
	{
		return E_NOTIMPL;
	}

	STDMETHODIMP_(HRESULT) Clone(IStream** ppstm)
	{
		return E_NOTIMPL;
	}


	STDMETHODIMP_(HRESULT) Write(void const* pv,  ULONG cb, ULONG* pcbWritten)
	{
		m_nTotalSize += cb;
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE Read(void* pv, ULONG cb, ULONG* pcbRead)
	{
		return E_NOTIMPL;
	}


	ULONG GetSize() {return m_nTotalSize;}
};

#endif//_CCOUNTSTREAM_H_