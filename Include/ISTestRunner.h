#if !defined(AFX_ISTESTRUNNER__50ABE7F5_DA9D_43C6_855A_620DB1BB5A7D__INCLUDED_)
#define AFX_ISTESTRUNNER__50ABE7F5_DA9D_43C6_855A_620DB1BB5A7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "iscppunit.h"
#include "ISTestXMLOutput.h"
#include "..\cppunit\include\cppunit\UI\text\testrunner.h"
#include "..\cppunit\include\cppunit\TestResultCollector.h"
#include "..\cppunit\include\cppunit\TestSuite.h"
#include "..\cppunit\include\cppunit\Test.h" 
#include "..\cppunit\include\cppunit\TestFailure.h" 
#include "map"

class ISTestRunner : public CppUnit::TextUi::TestRunner , public CISXmlOutput
{
	public:
		ISTestRunner ()
		{
		}	

		bool run( std::string testName ="",
            bool doWait = false,
            bool doPrintResult = true,
            bool doPrintProgress = true )
		{
			bool bReturn = TestRunner::run(testName, true, doPrintResult,doPrintProgress);
			stringx sTests;
			std::map<stringx, bool> listTestList;

			
			for ( std::vector<CppUnit::Test *>::const_iterator it = m_suite->getTests().begin(); 
					it != m_suite->getTests().end();++it )
			{
				CppUnit::TestSuite* pTestSuite = dynamic_cast<CppUnit::TestSuite*>(*it);

				for ( std::vector<CppUnit::Test *>::const_iterator itInner = pTestSuite->getTests().begin(); 
					itInner != pTestSuite->getTests().end();++itInner )
				{
					CppUnit::Test* pTestInner = *itInner;
					listTestList[stringx(pTestInner->getName())] = true;
				}
			}


			CppUnit::TestResultCollector::TestFailures::const_iterator itFailure = m_result->failures().begin();
			int failureNumber = 1;
			while ( itFailure != m_result->failures().end() ) 
			{
				CppUnit::TestFailure* pfailure = *itFailure++;
				std::map<stringx, bool>::iterator iterItem =  listTestList.find(pfailure->failedTestName());
				if (iterItem != listTestList.end())
                {
					iterItem->second = false;
				}
			}

			for (std::map<stringx, bool>::const_iterator itTest = listTestList.begin(); itTest != listTestList.end(); ++itTest)
			{
				/*if (itTest->second)
					sTests += L"Pass:";
				else
					sTests += L"Fail:";
				sTests += itTest->first;
				sTests += L"\n";*/

				//TCHAR szFile[MAX_PATH];
				//GetModuleFileName(GetModuleHandle(NULL), szFile, MAX_PATH);
				AddTestResults("", itTest->first, itTest->second);
			}


			//::MessageBox(0,sTests,_T("test"),0);
			return bReturn;
		}
};

#endif
