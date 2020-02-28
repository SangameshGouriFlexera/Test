#if !defined(AFX_ISIXMOUTPUT__50ABE7F5_DA9D_43C6_855A_620DB1BB5A7D__INCLUDED_)
#define AFX_ISIXMOUTPUT__50ABE7F5_DA9D_43C6_855A_620DB1BB5A7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Stringx.h"
#include "msxml2.h"
#include "cominit.h"

#ifdef RTRUNNER
#include "file.h"
#endif

#define LOG_FILE_DIR _T("m:\\Codebases\\isdev\\Build\\logfiles\\")
#define LOG_FILE_NAME _T("UnitTests.xml")
#define XML_HEADER L"<?xml version=\"1.0\" encoding=\"utf-8\" ?><?xml-stylesheet href=\"http://schbuild10/Builds/Styles/UnitTests.xsl\" type=\"text/xsl\"?><UnitTests></UnitTests>"
#define XML_HEADER_95 L"<?xml version=\"1.0\" encoding=\"utf-8\" ?><?xml-stylesheet href=\"http://schbuild10/Builds/Styles/UnitTests.xsl\" type=\"text/xsl\"?><UnitTests>"
#define XML_FOOTER_95 L"</UnitTests>"
#define TEST_STATUS L"Status"
#define TEST_FILE_NAME L"FileName"
#define TEST_PASS L"Pass"
#define TEST_FAIL L"Fail"
#define TEST_TEST L"Test"
#define TEST_TIME L"Time"
#define TEST_NAME L"Name"
#define TEST_COUNT L"Count"
#define TEST_SKIP L"Skip"
#define TEST_DISABLED L"Disabled"
#define TEST_TRUE L"True"
#define TEST_FALSE L"False"

// Note: Copied temporarily from 'TestSharedConstants.h' due to dependency problems.
#define RTTEST_RESULT_TEST_PASSED				0x000000001
#define RTTEST_RESULT_TEST_SKIPPED				0x000000002
#define RTTEST_RESULT_TEST_DISABLED				0x000000004
#define RTTEST_RESULT_TEST_UNEXPECTED			0x000000008

class CISXmlOutput : public ComInit
{
	private:
		bool m_bWriteOutput;
		CComPtr<IXMLDOMDocument2> m_spDoc;
		CComPtr<IXMLDOMElement> m_spRoot;
		stringxi m_sFileName;
        bool m_bNoXMLSupport;

        #ifdef RTRUNNER
        std::vector<stringxi> m_vLines;
        #endif

	public:
		CISXmlOutput (stringxi sDefaultFileName = LOG_FILE_NAME, stringxi sLogFileDir = LOG_FILE_DIR) : m_bWriteOutput (false), m_bNoXMLSupport( false )
		{
			m_sFileName = sLogFileDir ^ sDefaultFileName;

			DWORD dwAttrib = GetFileAttributes(sLogFileDir);
			if  ((0xFFFFFFFF != dwAttrib) && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY))
			{
#ifdef STANDALONE
				#undef CoCreateInstance	
#endif
				HRESULT hr = ::CoCreateInstance(__uuidof(DOMDocument30), NULL, CLSCTX_INPROC_SERVER, __uuidof(IXMLDOMDocument2), (void**)&m_spDoc);
#ifdef STANDALONE
				#define CoCreateInstance USE_ISCoCreateInstance_INSTEAD_PLEASE
#endif


				if (m_spDoc && (ERROR_SUCCESS == hr))
				{
					VARIANT_BOOL vbSuccess;
					dwAttrib = GetFileAttributes(m_sFileName);
					if ((0xFFFFFFFF != dwAttrib) && !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY))
						hr = m_spDoc->load(CComVariant(m_sFileName.c_str()),&vbSuccess);
					else
						hr = m_spDoc->loadXML(CComBSTR(XML_HEADER),&vbSuccess);

					if ((ERROR_SUCCESS == hr) && (vbSuccess == VARIANT_TRUE))
					{
						if (ERROR_SUCCESS == m_spDoc->get_documentElement(&m_spRoot))
							m_bWriteOutput = true;
					}
				}
                else
                    // On failure, assume no XML support
                    m_bNoXMLSupport = true;
			}

			//if (!m_bWriteOutput)
			//	::MessageBox(0,"test","test",0);

		}

		void AddTestResults(const stringx& sFileName, const stringx& sTestName, int nResult, int nCount = 1 )
		{
            #ifdef RTRUNNER
            // Win95 support
            if( m_bNoXMLSupport )
            {
                // Build the count
    			stringx sCount;
				sCount.format( L"%ld", nCount );

                // Build the line
                stringxi sLine;
                sLine = L"<Test Name=\"" + sTestName + L"\" "
                      + L"Status=\"" + ( nResult & RTTEST_RESULT_TEST_PASSED ? TEST_PASS : TEST_FAIL ) + L"\" "
                      + L"Skip=\"" + ( nResult & RTTEST_RESULT_TEST_SKIPPED ? TEST_TRUE : TEST_FALSE ) + L"\" "
                      + L"Disabled=\"" + ( nResult & RTTEST_RESULT_TEST_DISABLED ? TEST_TRUE : TEST_FALSE ) + L"\" "
                      + L"Count=\"" + sCount + L"\" "
                      + L"FileName=\"" + sFileName + L"\" "
                      + L"Time=\"" + GetDateTime() + L"\""
                      + L"/>";

                // Add the line
                m_vLines.push_back( sLine );

                // Done
                return;
            }
            #endif

			if (m_bWriteOutput && m_spDoc)
			{
				CComPtr<IXMLDOMNode> spNode;
				if (ERROR_SUCCESS == AddElement(TEST_TEST, &spNode))
				{
					if (spNode)
					{
						CComPtr<IXMLDOMNode> spNodeName;
						AddAttribute(TEST_NAME, sTestName, spNode, &spNodeName);

						CComPtr<IXMLDOMNode> spNodeResult;
						AddAttribute(TEST_STATUS, ( nResult & RTTEST_RESULT_TEST_PASSED ) ? TEST_PASS : TEST_FAIL, spNode, &spNodeResult);

						CComPtr<IXMLDOMNode> spNodeSkip;
						AddAttribute(TEST_SKIP, ( nResult & RTTEST_RESULT_TEST_SKIPPED ) ? TEST_TRUE : TEST_FALSE, spNode, &spNodeSkip);

						CComPtr<IXMLDOMNode> spNodeDisabled;
						AddAttribute(TEST_DISABLED, ( nResult & RTTEST_RESULT_TEST_DISABLED ) ? TEST_TRUE : TEST_FALSE, spNode, &spNodeDisabled);

						CComPtr<IXMLDOMNode> spNodeCount;
						stringx sCount;
						sCount.format( L"%ld", nCount );
						AddAttribute(TEST_COUNT, sCount, spNode, &spNodeCount);

						CComPtr<IXMLDOMNode> spNodeFile;
						AddAttribute(TEST_FILE_NAME, sFileName, spNode, &spNodeFile);

						CComPtr<IXMLDOMNode> spNodeTime;				
						AddAttribute(TEST_TIME, GetDateTime(), spNode, &spNodeTime);
					}
				}
			}
		}

		~CISXmlOutput ()
		{
            #ifdef RTRUNNER
            // Win95 support
            if( m_bNoXMLSupport )
            {
                // Open file
                is::file f;
                if( f.open_write( m_sFileName ) == ERROR_SUCCESS )
                {
                    // Write header
                    f.write_string( XML_HEADER_95 );

                    // Write contents
                    for( std::vector<stringxi>::iterator it = m_vLines.begin(); it != m_vLines.end(); it++ )
                        f.write_string( is::stringw( it->c_str() ) );

                    // Write footer
                    f.write_string( XML_FOOTER_95 );
                }
                return;
            }
            #endif

			if (m_bWriteOutput && m_spDoc)
			{
				HRESULT hr = m_spDoc->save(CComVariant(m_sFileName.c_str()));
			}
		};

		stringx GetDateTime()
		{	
			TCHAR lpBuffer[MAX_PATH];
			::GetDateFormat(LOCALE_USER_DEFAULT, DATE_SHORTDATE, NULL, NULL, lpBuffer, MAX_PATH);
			stringx sDateTime = lpBuffer;

			::GetTimeFormat(LOCALE_SYSTEM_DEFAULT, NULL,  NULL, NULL, lpBuffer, MAX_PATH);
			sDateTime = sDateTime + L' ' + stringx(lpBuffer);
			return sDateTime;
		}

		HRESULT AddElement(const stringx& sNode, IXMLDOMNode** ppNode) 
		{
			if (m_bWriteOutput && m_spDoc && sNode.length())
			{
				CComPtr<IXMLDOMElement> spElement;
				if (ERROR_SUCCESS == m_spDoc->createElement(sNode, &spElement))
				{
					CComPtr<IXMLDOMNode> spNode;
					if (ERROR_SUCCESS == spElement.QueryInterface(&spNode))
					{
						if (ERROR_SUCCESS == m_spRoot->appendChild(spNode, ppNode))
							return S_OK;
					}
				}
			}
			return E_INVALIDARG;
		}

		HRESULT AddAttribute(const stringx& sNode, const stringx& sValue, IXMLDOMNode* pElement, IXMLDOMNode** ppNode) 
		{
			if (m_bWriteOutput && m_spDoc && pElement && sNode.length())
			{
				CComPtr<IXMLDOMAttribute> spAttribute;
				if (ERROR_SUCCESS == m_spDoc->createAttribute(sNode, &spAttribute))
				{
					CComPtr<IXMLDOMNode> spNode;
					if (ERROR_SUCCESS == spAttribute.QueryInterface(&spNode))
					{
						CComPtr<IXMLDOMNamedNodeMap> spNodeMap;
						if (ERROR_SUCCESS == pElement->get_attributes(&spNodeMap))
						{
							CComPtr<IXMLDOMNode> spCreatedNode;
							if (ERROR_SUCCESS == spNodeMap->setNamedItem(spNode, &spCreatedNode))
							{
								if (ERROR_SUCCESS == spCreatedNode->put_text(sValue))
								{
									if (ERROR_SUCCESS == spCreatedNode.QueryInterface(ppNode))
									{
										return S_OK;
									}
								}
							}
						}

					}	
				}
				
			}
			return E_INVALIDARG;
		}

};


#endif