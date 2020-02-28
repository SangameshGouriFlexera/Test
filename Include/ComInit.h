#ifndef __COMINIT_H__
#define __COMINIT_H__

// Usage:
/*
	Used in a program block where you need to call CoInitialize(0).

	for example,

	void main( )
	{
		ComInit initcom;
		if (S_OK != initcom)
			MessageBox(0, "Initialization fails", "Stop", MB_OK);

		//rest of the code.
	}
*/

struct ComInit
{
	ComInit()
		:hRes(::CoInitialize(0))
	{}

	~ComInit()
	{
		if (ERROR_SUCCESS == hRes)
			::CoUninitialize();
	}

	operator HRESULT()
	{
		return hRes;
	}

private:
	long hRes;
};

#endif