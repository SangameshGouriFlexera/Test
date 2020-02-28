#ifndef _PERFORMANCE_H_
#define _PERFORMANCE_H_

#ifdef _DEBUG
	#define START_TIMER(n)				\
		CPerformance oPerform##n;		\
		oPerform##n.StartPerformanceMeasurement();

	#define END_TIMER(n)	oPerform##n.EndPerformanceMeasurement();
	#define TIME_TAKEN(n)	oPerform##n.GetPerformanceTimingsInMilliSecs();
#else
	#define START_TIMER(n)
	#define END_TIMER(n)
	#define TIME_TAKEN(n)
#endif


class CPerformance
{
public:
	CPerformance()
	{
		::QueryPerformanceFrequency(&nPerformanceFreq);
	};

	~CPerformance()
	{
	};

	void StartPerformanceMeasurement()
	{
		::QueryPerformanceCounter(&nStartTime);
	}

	void EndPerformanceMeasurement()
	{
		::QueryPerformanceCounter(&nEndTime);
	}

	float GetPerformanceTimings()
	{
		float fTimings = 0.0;

		__int64 nPerfFreq = nPerformanceFreq.QuadPart;

		if(nPerfFreq)
		{
			fTimings = nEndTime.QuadPart - nStartTime.QuadPart;
			fTimings = fTimings / nPerfFreq;
		}
		return fTimings;
	}

	float GetPerformanceTimingsInMilliSecs()
	{
		float fTimings = 0.0;

		__int64 nPerfFreq = nPerformanceFreq.QuadPart;

		if(nPerfFreq)
		{
			fTimings = nEndTime.QuadPart - nStartTime.QuadPart;
			fTimings = (fTimings * 1000)/ nPerfFreq;
		}
		return fTimings;
	}

private:

	// Initial Performance counter value before peformance measure starts
	LARGE_INTEGER nStartTime; 

	// Final Performance counter value
	LARGE_INTEGER nEndTime; 

	// Value which indicates how often the performance counter occurs.
	LARGE_INTEGER nPerformanceFreq; 
};

#endif //_PERFORMANCE_H_
