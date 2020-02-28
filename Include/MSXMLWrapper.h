
#pragma once

//#include "msxml2.h"

// src\inc
#include "stringx.h"
#include "iscomacros.h"
#include "combool.h"

#ifndef EXCLUDE_ISCOCREATE_XML
#undef MXSMLWRAPPER_USE_ISCOCREATE
#endif

#ifdef MXSMLWRAPPER_USE_ISCOCREATE
#include "IsCoCreateInProc.h"
#endif

//------------------------------------------------------------------------------
// Import MSXML 6
//------------------------------------------------------------------------------
//#import <msxml6.dll> rename_namespace("XML") raw_interfaces_only
// If this import statement fails, you need to install the MSXML 6.0
// component from
#include "msxml6.tlh"

enum EnumXmlVersion
{
	eXmlVerNone = 0,
	eXmlVer3 = 3,
	eXmlVer4 = 4,
	eXmlVer6 = 6
};

namespace {
	template <class T>
	inline HRESULT CreateFirst(REFCLSID refclsid, EnumXmlVersion eXmlVersion, HRESULT hr, T** ppUnk, EnumXmlVersion& eXmlVersionUsed)
	{
		if (*ppUnk)
			return hr;
#ifdef CoCreateInstance
#undef CoCreateInstance
		hr = ::CoCreateInstance(refclsid, NULL, CLSCTX_INPROC_SERVER, __uuidof(T), (LPVOID*)ppUnk);
#define CoCreateInstance USE_ISCoCreateInstance_INSTEAD_PLEASE
#else
		hr = ::CoCreateInstance(refclsid, NULL, CLSCTX_INPROC_SERVER, __uuidof(T), (LPVOID*)ppUnk);
#endif
		if (SUCCEEDED(hr))
		{
			eXmlVersionUsed = eXmlVersion;
		}
		return hr;
	}
	template <class T>
	inline HRESULT CreateFirst(LPCWSTR szServer, EnumXmlVersion eXmlVersion, HRESULT hr, T** ppUnk, EnumXmlVersion& eXmlVersionUsed)
	{
#ifdef MXSMLWRAPPER_USE_ISCOCREATE
		if (*ppUnk)
			return hr;
		hr = ISCoCreateInstance(szServer, __uuidof(T), ppUnk);
		if (SUCCEEDED(hr))
		{
			eXmlVersionUsed = eXmlVersion;
		}
#endif
		return hr;
	}
}

class MSXMLWrapper
{

public:

	static bool IsAnyVersionOfXMLInstalled()
	{
		bool bIsXmlInstalled = false;

		try
		{
			CComPtr<XML::IXMLDOMDocument2> spXmlDoc;
			HRESULT hRes = CreateXmlDocObj(&spXmlDoc);
			bIsXmlInstalled = (SUCCEEDED(hRes) && spXmlDoc);
		}
		catch (...)
		{
			bIsXmlInstalled = false;
		}

		return bIsXmlInstalled;
	}

	static HRESULT CreateXmlDocObj(XML::IXMLDOMDocument2** pXmlDoc)
	{
		EnumXmlVersion eXmlVersion;
		return CreateXmlDocObj(pXmlDoc, eXmlVersion);
	}

	static HRESULT CreateXmlDocObj(XML::IXMLDOMDocument2** pXmlDoc, EnumXmlVersion& eXmlVersion)
	{
		// MVM TODO: Add code to allow forcing a particluar version of MSMXL
		HRESULT hres = E_FAIL;
		hres = CreateFirst(__uuidof(XML::DOMDocument60), eXmlVer6, hres, pXmlDoc, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::DOMDocument40), eXmlVer4, hres, pXmlDoc, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::DOMDocument30), eXmlVer3, hres, pXmlDoc, eXmlVersion);
		hres = CreateFirst(L"msxml6.dll", eXmlVer6, hres, pXmlDoc, eXmlVersion);
		hres = CreateFirst(L"msxml4.dll", eXmlVer4, hres, pXmlDoc, eXmlVersion);
		hres = CreateFirst(L"msxml3.dll", eXmlVer3, hres, pXmlDoc, eXmlVersion);
		return hres;
	}

	// Load XML from a file
	inline static HRESULT CreateXmlDocFromFile(const stringx& sXmlFile, XML::IXMLDOMDocument2** pXmlDoc, bool bValidateOnParse = false)
	{
		return CreateXmlDocOrErrorFromFile(sXmlFile, pXmlDoc, NULL, bValidateOnParse);
	}

	// Load XML from a file, returning either pXMLDoc or pParseError if available (check for null returns)
	static HRESULT CreateXmlDocOrErrorFromFile(const stringx& sXmlFile, XML::IXMLDOMDocument2** pXmlDoc, XML::IXMLDOMParseError** pParseError, bool bValidateOnParse = false)
	{
		CComPtr<XML::IXMLDOMDocument2> spXmlDoc;

		CHECK(CreateXmlDocObj(&spXmlDoc));

		spXmlDoc->setProperty(stringx(L"ProhibitDTD"), CComVariant(VARIANT_FALSE));
		CHECK(spXmlDoc->put_validateOnParse(CComBool(bValidateOnParse)));

		CComBool cbResult;
		CHECK(spXmlDoc->load(CComVariant(sXmlFile.c_str()), &cbResult));

		if(!cbResult)
		{
			if (pParseError)
				spXmlDoc->get_parseError(pParseError);

			return E_FAIL;
		}

		return spXmlDoc.CopyTo(pXmlDoc);
	}

	// Load XML directly from text already in memory
	static HRESULT CreateXmlDocFromXml(const stringx& sXml, XML::IXMLDOMDocument2** pXmlDoc, bool bValidateOnParse = false)
	{
		CComPtr<XML::IXMLDOMDocument2> spXmlDoc;

		CHECK(CreateXmlDocObj(&spXmlDoc));

		CHECK(spXmlDoc->put_validateOnParse(CComBool(bValidateOnParse)));

		CComBool cbResult;
		CHECK(spXmlDoc->loadXML(sXml, &cbResult));

		if(!cbResult)
		{
#ifdef _DEBUG
			// Uncomment this code if you want to get more information about what failed
/*			XML::IXMLDOMParseErrorPtr pErr;
			spXmlDoc->get_parseError(&pErr);

			long lLine;
			pErr->get_line(&lLine);

			long lLinePos;
			pErr->get_linepos(&lLinePos);

			stringx sReason;
			pErr->get_reason(&sReason);

			::MessageBox(0, sReason, _T(""), MB_OK);
*/
#endif
			return E_FAIL;
		}

		return spXmlDoc.CopyTo(pXmlDoc);
	}

	inline static HRESULT CreateSaxReader(XML::ISAXXMLReader** pSaxReader)
	{
		EnumXmlVersion eXmlVersion;
		return CreateSaxReader(pSaxReader, eXmlVersion);
	}

	static HRESULT CreateSaxReader(XML::ISAXXMLReader** pSaxReader, EnumXmlVersion& eXmlVersion)
	{
		HRESULT hres = E_FAIL;
		hres = CreateFirst(__uuidof(XML::SAXXMLReader60), eXmlVer6, hres, pSaxReader, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::SAXXMLReader40), eXmlVer4, hres, pSaxReader, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::SAXXMLReader30), eXmlVer3, hres, pSaxReader, eXmlVersion);
		hres = CreateFirst(L"msxml6.dll", eXmlVer6, hres, pSaxReader, eXmlVersion);
		hres = CreateFirst(L"msxml4.dll", eXmlVer4, hres, pSaxReader, eXmlVersion);
		hres = CreateFirst(L"msxml3.dll", eXmlVer3, hres, pSaxReader, eXmlVersion);
		return hres;
	}

	inline static HRESULT CreateNamespaceManager(XML::IMXNamespaceManager **ppNSMgr)
	{
        EnumXmlVersion eXmlVersion;
        return CreateNamespaceManager(ppNSMgr, eXmlVersion);
	}

	static HRESULT CreateNamespaceManager(XML::IMXNamespaceManager **ppNSMgr, EnumXmlVersion& eXmlVersion)
	{
        HRESULT hres = E_FAIL;
        hres = CreateFirst(__uuidof(XML::MXNamespaceManager60), eXmlVer6, hres, ppNSMgr, eXmlVersion);
        hres = CreateFirst(__uuidof(XML::MXNamespaceManager40), eXmlVer4, hres, ppNSMgr, eXmlVersion);
        hres = CreateFirst(L"msxml6.dll", eXmlVer6, hres, ppNSMgr, eXmlVersion);
        hres = CreateFirst(L"msxml4.dll", eXmlVer4, hres, ppNSMgr, eXmlVersion);
        return hres;
	}

	static HRESULT CreateXmlHttpRequest(XML::IServerXMLHTTPRequest **ppXHR)
	{
		EnumXmlVersion eXmlVersion;
		return CreateXmlHttpRequest(ppXHR, eXmlVersion);
	}

	static HRESULT CreateXmlHttpRequest(XML::IServerXMLHTTPRequest **ppXHR, EnumXmlVersion& eXmlVersion)
	{
		HRESULT hres = E_FAIL;
		hres = CreateFirst(__uuidof(XML::ServerXMLHTTP60), eXmlVer6, hres, ppXHR, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::ServerXMLHTTP40), eXmlVer4, hres, ppXHR, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::ServerXMLHTTP30), eXmlVer3, hres, ppXHR, eXmlVersion);
		hres = CreateFirst(L"msxml6.dll", eXmlVer6, hres, ppXHR, eXmlVersion);
		hres = CreateFirst(L"msxml4.dll", eXmlVer4, hres, ppXHR, eXmlVersion);
		hres = CreateFirst(L"msxml3.dll", eXmlVer3, hres, ppXHR, eXmlVersion);
		return hres;
	}

	static HRESULT CreateMxWriter(XML::IMXWriter** pMxWriter)
	{
		EnumXmlVersion eXmlVersion;
		return CreateMxWriter(pMxWriter, eXmlVersion);
	}

	static HRESULT CreateMxWriter(XML::IMXWriter** pMxWriter, EnumXmlVersion& eXmlVersion)
	{
		HRESULT hres = E_FAIL;
		hres = CreateFirst(__uuidof(XML::MXXMLWriter60), eXmlVer6, hres, pMxWriter, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::MXXMLWriter40), eXmlVer4, hres, pMxWriter, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::MXXMLWriter30), eXmlVer3, hres, pMxWriter, eXmlVersion);
		hres = CreateFirst(L"msxml6.dll", eXmlVer6, hres, pMxWriter, eXmlVersion);
		hres = CreateFirst(L"msxml4.dll", eXmlVer4, hres, pMxWriter, eXmlVersion);
		hres = CreateFirst(L"msxml3.dll", eXmlVer3, hres, pMxWriter, eXmlVersion);
		return hres;
	}

	static HRESULT CreateSchemaCollection(XML::IXMLDOMSchemaCollection2 **pSchemaCollection)
	{
		EnumXmlVersion eXmlVersion;
		return CreateSchemaCollection(pSchemaCollection, eXmlVersion);
	}

	static HRESULT CreateSchemaCollection(XML::IXMLDOMSchemaCollection2 **pSchemaCollection, EnumXmlVersion& eXmlVersion)
	{
		HRESULT hres = E_FAIL;
		hres = CreateFirst(__uuidof(XML::XMLSchemaCache60), eXmlVer6, hres, pSchemaCollection, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::XMLSchemaCache40), eXmlVer4, hres, pSchemaCollection, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::XMLSchemaCache30), eXmlVer3, hres, pSchemaCollection, eXmlVersion);
		hres = CreateFirst(L"msxml6.dll", eXmlVer6, hres, pSchemaCollection, eXmlVersion);
		hres = CreateFirst(L"msxml4.dll", eXmlVer4, hres, pSchemaCollection, eXmlVersion);
		hres = CreateFirst(L"msxml3.dll", eXmlVer3, hres, pSchemaCollection, eXmlVersion);
		return hres;
	}

	// Indent the contents of pDoc into the storage described by vOutput.
	// vOutput can hold an IXMLDOMDocument or an IStream (such as those created by SHCreateStreamOnFile)
	static HRESULT IndentXml(XML::IXMLDOMDocument *pDoc, VARIANT vOutput)
	{
		CComPtr<XML::IMXWriter> spWriter;
		CComPtr<XML::ISAXXMLReader> spReader;
		HRESULT hr;
		if (FAILED(hr = MSXMLWrapper::CreateMxWriter(&spWriter))
			|| FAILED(hr = spWriter->put_omitXMLDeclaration(VARIANT_FALSE))
			|| FAILED(hr = spWriter->put_standalone(VARIANT_TRUE))
			|| FAILED(hr = spWriter->put_indent(VARIANT_TRUE))
			|| FAILED(hr = spWriter->put_encoding(L"UTF-8"))
			|| FAILED(hr = MSXMLWrapper::CreateSaxReader(&spReader))
			|| FAILED(hr = spReader->putContentHandler(CComQIPtr<XML::ISAXContentHandler>(spWriter)))
			|| FAILED(hr = spReader->putDTDHandler(CComQIPtr<XML::ISAXDTDHandler>(spWriter)))
			|| FAILED(hr = spReader->putErrorHandler(CComQIPtr<XML::ISAXErrorHandler>(spWriter)))
			|| FAILED(hr = spReader->putProperty((PUSHORT)L"http://xml.org/sax/properties/lexical-handler", CComVariant(spWriter)))
			|| FAILED(hr = spReader->putProperty((PUSHORT)L"http://xml.org/sax/properties/declaration-handler", CComVariant(spWriter)))
			|| FAILED(hr = spWriter->put_output(vOutput))
			|| FAILED(hr = spReader->parse(CComVariant(pDoc))))
		{
			return hr;
		}
		return hr;
	}

	// per http://www.w3.org/TR/xml11/#sec-common-syn but note : is specifically excluded
	static inline bool IsValidNameFirstChar(const wchar_t c)
	{
		return (c >= 'A' && c <= 'Z') || c == '_' || (c >= 'a' && c <= 'z') || (c >= 0xc0 && c <= 0xd6) || (c >= 0xf8 && c <= 0x2ff)
			|| (c >= 0x370 && c <= 0x37d) || (c >= 0x37f && c <= 0x1fff) || (c >= 0x200c && c <= 0x200d) || (c >= 0x2070 && c <= 0x218f)
			|| (c >= 0x2c00 && c <= 0x2fef) || (c >= 0x3001 && c <= 0xd7ff) || (c >= 0xf900 && c <= 0x2fdcf) || (c >= 0xfdf0 && c <= 0xfffd)
			|| (c >= 0x10000 && c <= 0xeffff);
	}

	// per http://www.w3.org/TR/xml11/#sec-common-syn but note : is specifically excluded
	static inline bool IsValidNameChar(const wchar_t c)
	{
		return IsValidNameFirstChar(c) || c == '-' || c == '.'
			|| (c >= '0' && c <= '9') || c == 0xb7 || (c >= 0x0300 && c <= 0x036f) || (c >= 0x203f && c <= 0x2040);
	}

	static bool IsValidAttributeName(const stringx& sName)
	{
		if(sName.empty())
			return false;

		if (!IsValidNameFirstChar(sName[0]))
			return false;

		for (int i = 1; i < (int)sName.size(); ++i)
		{
			if (!IsValidNameChar(sName[i]))
				return false;
		}
		return true;
	}

	template <typename T>
	static _stringx<T> MakeValidAttributeName(const _stringx<T>& sName)
	{
		_stringx<T> sValid(sName);

		if (sValid.empty())
			sValid = L"_";

		if (!IsValidNameFirstChar(sValid[0]))
			sValid[0] = '_';

		for (int i = 1; i < (int)sValid.size(); ++i)
		{
			if (!IsValidNameChar(sValid[i]))
				sValid[i] = L'_';
		}
		return sValid;
	}

	inline static bool IsValidElementName(const stringx& sName)
	{
		return IsValidAttributeName(sName) && !sName.as_stringxi().startswith(L"xml");
	}

	template <typename T>
	inline static _stringx<T> MakeValidElementName(const _stringx<T>& sName)
	{
		return sName.as_stringxi().startswith(L"xml") ? MakeValidAttributeName(L"_" + sName) : MakeValidAttributeName(sName);
	}

	// Helper - set select attribute of <xsl:param name="(sParam)" select="'(sValue)'"/>
	static HRESULT InjectXslParameter(XML::IXMLDOMDocument2* pXsl, const stringx& sParam, const stringx& sValue)
	{
		CComPtr<XML::IXMLDOMNode> spParam;
		CHECK(pXsl->selectSingleNode(L"//*[@name='" + sParam + L"']", &spParam))
		if (spParam)
		{
			CHECK(spParam->put_text(sValue))
		}
		return S_OK;
	}

	static stringx GetParseError(XML::IXMLDOMParseError* pError)
	{
		stringx sMessage;
		if (pError)
		{
			LONG lErrorCode = 0, lLine = 0, lCol = 0;
			stringx sError, sText;
			pError->get_errorCode(&lErrorCode);
			pError->get_line(&lLine);
			pError->get_linepos(&lCol);
			pError->get_reason(&sError);
			pError->get_srcText(&sText);

			if (lErrorCode)
			{
				stringx sParseError;
				sParseError.format(L"Line %d Column %d: Error 0x%08x: %s in: %s", lLine, lCol, lErrorCode, sError.c_str(), sText.c_str());
				sMessage += sParseError;
			}
		}
		return sMessage;
	}

	static stringx GetParseError(XML::IXMLDOMParseError2* pError)
	{
		stringx sMessage;
		if (pError)
		{
			LONG lErrorCode = 0, lLine = 0, lCol = 0;
			stringx sError, sText;
			pError->get_errorCode(&lErrorCode);
			pError->get_line(&lLine);
			pError->get_linepos(&lCol);
			pError->get_reason(&sError);
			pError->get_srcText(&sText);

			stringx sXPath;
			pError->get_errorXPath(&sXPath);

			if (lErrorCode)
			{
				stringx sParseError;
				sParseError.format(L"Line %d Column %d (%s): Error 0x%08x: %s in: %s", lLine, lCol, sXPath.c_str(), lErrorCode, sError.c_str(), sText.c_str());
				sMessage += sParseError;
			}
		}
		return sMessage;
	}

	static HRESULT GetAttributeValue(XML::IXMLDOMNode* pNode, const stringx& sAttrName, stringx& sAttrValue, const stringx& sNamespaceUri = L"")
	{
		if(pNode)
		{
			CComPtr<XML::IXMLDOMNamedNodeMap> spAtrrMap;
			CHECK(pNode->get_attributes(&spAtrrMap))

			CComPtr<XML::IXMLDOMNode> spFoundNode;
			CHECK(spAtrrMap->getQualifiedItem(sAttrName, sNamespaceUri, &spFoundNode))

			if (spFoundNode)
			{
				CComVariant cvValue;
				CHECK(spFoundNode->get_nodeValue(&cvValue))
				sAttrValue = cvValue.bstrVal;
			}
		}
		return S_OK;
	}

	static HRESULT SetAttributeValue(XML::IXMLDOMNode *pNode, const stringx& sAttr, const stringx& sValue, const stringx& sNamespaceUri = L"")
	{
		if (!pNode)
			return E_POINTER;

		CComPtr<XML::IXMLDOMDocument> spDoc;
		CHECK(pNode->get_ownerDocument(&spDoc))

		CComPtr<XML::IXMLDOMNamedNodeMap> spNamedNodeMap;
		CHECK(pNode->get_attributes(&spNamedNodeMap))

		CComPtr<XML::IXMLDOMNode> spAttrNode;
		CHECK(spDoc->createNode(CComVariant(XML::NODE_ATTRIBUTE), sAttr, sNamespaceUri, &spAttrNode))
		CHECK(spAttrNode->put_text(sValue))

		CComPtr<XML::IXMLDOMNode> spNewAttrib;
		return spNamedNodeMap->setNamedItem(spAttrNode, &spNewAttrib);
	}

	static HRESULT AddElement(XML::IXMLDOMNode *pParentNode, const stringx& sName, const stringx& sNameSpaceUri, XML::IXMLDOMNode **ppNode)
	{
		if (!pParentNode)
			return E_INVALIDARG;

		CComPtr<XML::IXMLDOMDocument> spDoc;
		CHECK(pParentNode->get_ownerDocument(&spDoc));

		CComPtr<XML::IXMLDOMNode> spNode;
		CHECK(spDoc->createNode(CComVariant(XML::NODE_ELEMENT), sName, sNameSpaceUri, &spNode));

		return pParentNode->appendChild(spNode, ppNode);
	}

	static HRESULT SetAttribute(XML::IXMLDOMNode *pNode, const stringx& sAttr, const stringx& sValue, const stringx& sNamespaceuri = L"")
	{
		CComPtr<XML::IXMLDOMNode> spNewNode;
		return CreateAttribute(pNode, sAttr, sValue, sNamespaceuri, &spNewNode);
	}

	static HRESULT CreateAttribute(XML::IXMLDOMNode *pNode, const stringx& sAttr, const stringx& sValue, const stringx& sNamespaceUri, XML::IXMLDOMNode** ppNewAttrib)
	{
		CComPtr<XML::IXMLDOMNamedNodeMap> spNamedNodeMap;
		CHECK(pNode->get_attributes(&spNamedNodeMap));

		CComPtr<XML::IXMLDOMDocument> spDoc;
		CHECK(pNode->get_ownerDocument(&spDoc));

		CComPtr<XML::IXMLDOMNode> spAttrNode;
		CHECK(spDoc->createNode(CComVariant(XML::NODE_ATTRIBUTE), sAttr, sNamespaceUri, &spAttrNode));
		CHECK(spAttrNode->put_text(sValue));

		return spNamedNodeMap->setNamedItem(spAttrNode, ppNewAttrib);
	}

	/*static stringx ValidateXML(const stringx& sXml, const stringx& sSchema)
	{
		CComPtr<XML::IXMLDOMSchemaCollection> spXmlSchema;
		XML::IXMLDOMDocument2Ptr pXMLDoc;
		CComPtr<XML::IXMLDOMParseError> spXmlValErr;
		HRESULT hRes = S_OK;
		stringx sOutput;

		hRes = spXmlSchema.CoCreateInstance(__uuidof(XML::XMLSchemaCache60), NULL, CLSCTX_INPROC_SERVER);
		hRes = spXmlSchema->add(L"urn:Test", sSchema);

		pXMLDoc.CreateInstance(__uuidof(XML::DOMDocument60));

		pXMLDoc->schemas  = spXmlSchema->GetInterfacePtr();
		pXMLDoc->async = VARIANT_FALSE;
		pXMLDoc->validateOnParse = VARIANT_TRUE;
		pXMLDoc->resolveExternals = VARIANT_TRUE;

		if (pXMLDoc->load(sXml) != VARIANT_TRUE)
		{
			spXmlValErr = pXMLDoc->parseError;
			sOutput = _L"Validation failed on " + sXml +
			L"\n=====================") +
			L"\nReason: " + stringx(pErr->Getreason()) +
			L"\nSource: " + stringx(pErr->GetsrcText()) +
			L"\nLine: " + stringx(pErr->Getline()) +
			L"\n";

		}
		else
		{
			sOutput = L"Validation succeeded for " + sXml +
			L"\n======================\n" +
			stringx(pXD->xml) + L"\n";
		}

		return sOutput;



	}*/


	static HRESULT CreateXslTemplate(XML::IXSLTemplate** pXslTemplate)
	{
		EnumXmlVersion eXmlVersion;
		return CreateXslTemplate(pXslTemplate, eXmlVersion);
	}

	static HRESULT CreateXslTemplate(XML::IXSLTemplate** pXslTemplate, EnumXmlVersion& eXmlVersion)
	{
		// MVM TODO: Add code to allow forcing a particluar version of MSMXL
		HRESULT hres = E_FAIL;
		hres = CreateFirst(__uuidof(XML::XSLTemplate60), eXmlVer6, hres, pXslTemplate, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::XSLTemplate40), eXmlVer4, hres, pXslTemplate, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::XSLTemplate30), eXmlVer3, hres, pXslTemplate, eXmlVersion);
		return hres;
	}

	static HRESULT CreateFreeThreadedDoc(XML::IXMLDOMDocument2** pDoc)
	{
		HRESULT hres = E_FAIL;
		EnumXmlVersion eXmlVersion;
		hres = CreateFirst(__uuidof(XML::FreeThreadedDOMDocument60), eXmlVer6, hres, pDoc, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::FreeThreadedDOMDocument40), eXmlVer4, hres, pDoc, eXmlVersion);
		hres = CreateFirst(__uuidof(XML::FreeThreadedDOMDocument30), eXmlVer3, hres, pDoc, eXmlVersion);
		return hres;

	}

};
