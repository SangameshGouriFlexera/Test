#include "StdAfx.h"
#include "ISXmlDom.h"

#include "hrx_new.h"

#include "MSXMLWrapper.h"

namespace is {
namespace xml {
IS_INLINE_NAMESPACE dom {

namespace detail {

template <typename DomType> struct InterfaceOf { typedef XML::IXMLDOMNode type; };
template <> struct InterfaceOf<DomText> { typedef XML::IXMLDOMText type; };
template <> struct InterfaceOf<DomComment> { typedef XML::IXMLDOMComment type; };
template <> struct InterfaceOf<DomAttribute> { typedef XML::IXMLDOMAttribute type; };
template <> struct InterfaceOf<DomElement> { typedef XML::IXMLDOMElement type; };
template <> struct InterfaceOf<DomDocument> { typedef XML::IXMLDOMDocument2 type; };
template <> struct InterfaceOf<DomProcessingInstruction> { typedef XML::IXMLDOMProcessingInstruction type; };

template <typename DomType> struct NodeTypeOf { static const XML::DOMNodeType value = (XML::DOMNodeType)XML::NODE_INVALID; };
template <> struct NodeTypeOf<DomText> { static const XML::DOMNodeType value = (XML::DOMNodeType)XML::NODE_TEXT; };
template <> struct NodeTypeOf<DomComment> { static const XML::DOMNodeType value = (XML::DOMNodeType)XML::NODE_COMMENT; };
template <> struct NodeTypeOf<DomAttribute> { static const XML::DOMNodeType value = (XML::DOMNodeType)XML::NODE_ATTRIBUTE; };
template <> struct NodeTypeOf<DomElement> { static const XML::DOMNodeType value = (XML::DOMNodeType)XML::NODE_ELEMENT; };
template <> struct NodeTypeOf<DomDocument> { static const XML::DOMNodeType value = (XML::DOMNodeType)XML::NODE_DOCUMENT; };
template <> struct NodeTypeOf<DomProcessingInstruction> { static const XML::DOMNodeType value = (XML::DOMNodeType)XML::NODE_PROCESSING_INSTRUCTION; };

template <typename DomType>
struct DomTraits
{
	typedef typename std::decay<DomType>::type type;
	typedef typename InterfaceOf<type>::type Interface;
	typedef typename InterfaceOf<type>::type * RawPtr;
	typedef CComPtr<typename InterfaceOf<type>::type> SafePtr;
	typedef CComQIPtr<typename InterfaceOf<type>::type> QI;
	static const XML::DOMNodeType NodeType = NodeTypeOf<type>::value;
};

class impl
{
public:
	template <typename DomType>
	static DomType FromXmlNode(XML::IXMLDOMNode *pNode)
	{
		XML::DOMNodeType type;
		if (pNode)
		{
			hrx hr = pNode->get_nodeType(&type);
			ATLASSERT(DomTraits<DomType>::NodeType == type);
		}
		return DomType(DomTraits<DomType>::QI(pNode));
	}

	static CComPtr<XML::IXMLDOMDocument2> Compat_ToXmlNode(const DomDocument& doc)
	{
		CComPtr<XML::IXMLDOMDocument2> spDoc;
		doc.m_pNode.QueryInterface(&spDoc);
		return spDoc;
	}

	static CComPtr<XML::IXMLDOMElement> Compat_ToXmlNode(const DomElement& elt)
	{
		CComPtr<XML::IXMLDOMElement> spElt;
		elt.m_pNode.QueryInterface(&spElt);
		return spElt;
	}

	static DomParseError FromParseError(XML::IXMLDOMParseError *pError)
	{
		return DomParseError(pError);
	}

	static DomParseErrorList FromParseErrorList(XML::IXMLDOMParseError *pParseError)
	{
		CComQIPtr<XML::IXMLDOMParseError2> spParseError2(pParseError);
		if (spParseError2)
		{
			CComPtr<XML::IXMLDOMParseErrorCollection> spAllErrors;
			hrx hr = spParseError2->get_allErrors(&spAllErrors);
			if (spAllErrors)
				return impl::FromParseErrorList(spAllErrors);
		}
		return DomParseErrorList(pParseError);
	}

	static DomParseErrorList FromParseErrorList(XML::IXMLDOMParseErrorCollection *pErrors)
	{
		return DomParseErrorList(pErrors);
	}

	static DomTraits<DomDocument>::SafePtr CreateNewDocument()
	{
		DomTraits<DomDocument>::SafePtr spDoc;
		MSXMLWrapper::CreateXmlDocObj(&spDoc);
		InitializeDoc(spDoc);
		return spDoc;
	}

	static DomTraits<DomDocument>::RawPtr InitializeDoc(DomTraits<DomDocument>::RawPtr pDoc)
	{
		hrx hr = pDoc->put_validateOnParse(VARIANT_FALSE);
		hr = pDoc->setProperty(stringxi(L"SelectionLanguage"), CComVariant(L"XPath"));
		hr = pDoc->setProperty(stringxi(L"MultipleErrorMessages"), CComVariant(VARIANT_TRUE));
		hr = pDoc->setProperty(stringxi(L"NewParser"), CComVariant(VARIANT_TRUE));
		return pDoc;
	}

	template <typename DomType>
	static DomTraits<DomDocument>::SafePtr GetDocument(DomType *pThis)
	{
		DomTraits<DomDocument>::SafePtr spDoc2;
		ATLASSERT(pThis->m_pNode != nullptr);
		if (FAILED(pThis->m_pNode.QueryInterface(&spDoc2)))
		{
			// in practice Dom* won't let spDoc1 be null, so skip the check
			CComPtr<XML::IXMLDOMDocument> spDoc1;
			hrx hr = pThis->m_pNode->get_ownerDocument(&spDoc1);
			hr = spDoc1.QueryInterface(&spDoc2);
		}
		return spDoc2;
	}

	template <typename RetType, typename DomType, typename Method>
	static RetType Get(DomType *pThis, Method&& method)
	{
		RetType retval;
		hrx hr = Call(pThis, method, &retval);
		return retval;
	}

	template <typename RetType, typename DomType, typename Method, typename Arg>
	static RetType Get(DomType *pThis, Method&& method, Arg&& arg)
	{
		RetType retval;
		hrx hr = Call(pThis, method, std::forward<Arg>(arg), &retval);
		return retval;
	}

	template <typename DomType, typename Method, typename Arg>
	static HRESULT Call(DomType *pThis, Method&& method, Arg&& arg)
	{
		auto pIface = static_cast<typename DomTraits<DomType>::Interface*>(pThis->m_pNode.p);
		ATLASSERT(pIface != nullptr);
		return (pIface->*method)(std::forward<Arg>(arg));
	}

	template <typename DomType, typename Method, typename Arg1, typename Arg2>
	static HRESULT Call(DomType *pThis, Method&& method, Arg1&& arg1, Arg2&& arg2)
	{
		auto pIface = static_cast<typename DomTraits<DomType>::Interface*>(pThis->m_pNode.p);
		ATLASSERT(pIface != nullptr);
		return (pIface->*method)(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2));
	}

	template <typename AppendType>
	static AppendType Append(DomNode *pThis, XML::IXMLDOMNode *pNode)
	{
		CComPtr<XML::IXMLDOMNode> spAppended;
		hrx hr = Call(pThis, &XML::IXMLDOMNode::appendChild, pNode, &spAppended);
		return impl::FromXmlNode<AppendType>(spAppended);
	}

	template <typename ReplaceType>
	static ReplaceType Replace(DomNode *pThis, XML::IXMLDOMNode *pNode)
	{
		auto& spThis = pThis->m_pNode;
		CComPtr<XML::IXMLDOMNode> spParent, spReplacement, spReplaced;
		hrx hr = spThis->get_parentNode(&spParent);
		hr = spParent->insertBefore(pNode, CComVariant(spThis), &spReplacement);
		hr = spParent->removeChild(spThis, &spReplaced);
		spThis.Release();
		return impl::FromXmlNode<ReplaceType>(spReplacement);
	}

	static void Remove(DomNode *pThis)
	{
		auto& spThis = pThis->m_pNode;
		CComPtr<XML::IXMLDOMNode> spParent, spRemoved;
		hrx hr = spThis->get_parentNode(&spParent);
		hr = spParent->removeChild(spThis, &spRemoved);
		spThis.Release();
	}
};

struct TemporarySelectionNamespace
{
	TemporarySelectionNamespace(const DomContainer* pContainer, const stringxi& sSelectionNamespace)
		: m_Document(impl::FromXmlNode<DomDocument>(impl::GetDocument(pContainer)))
	{
		m_sOriginalNamespace = m_Document.GetSelectionNamespaces();
		m_Document.SetSelectionNamespaces(sSelectionNamespace);
	}

	~TemporarySelectionNamespace()
	{
		m_Document.SetSelectionNamespaces(m_sOriginalNamespace);
	}

	DomDocument m_Document;
	stringxi m_sOriginalNamespace;
};

} // detail

using namespace detail;

DomNode::DomNode(XML::IXMLDOMNode *pNode) : m_pNode(pNode) {}
DomNode::~DomNode() {} // ensure CComPtr<IXMLDOMNode> fully defined

DomName DomNode::GetName() const
{
	ATLASSERT(m_pNode != nullptr);
	stringxi sName, sUri, sPrefix;
	hrx hr = m_pNode->get_nodeName(&sName);
	hr = m_pNode->get_namespaceURI(&sUri);
	hr = m_pNode->get_prefix(&sPrefix);

	return DomName(sName, sUri, sPrefix);
}

DomComment DomNode::ChangeToComment()
{
	auto sXml = impl::Get<stringxi>(this, &XML::IXMLDOMNode::get_xml);

	DomTraits<DomComment>::SafePtr spCommentNode;
	hrx hr = impl::GetDocument(this)->createComment(sXml, &spCommentNode);

	return impl::Replace<DomComment>(this, spCommentNode);
}

//////////////////////////////////////////////////////////////////////////

DomAttribute::DomAttribute(XML::IXMLDOMAttribute *pNode)
	: DomNode(pNode)
{
}

DomAttribute DomAttribute::Empty()
{
	return DomAttribute(nullptr);
}

stringxi DomAttribute::GetValue() const
{
	auto cvValue = impl::Get<CComVariant>(this, &XML::IXMLDOMAttribute::get_value);
	return stringxi(cvValue);
}

void DomAttribute::GetValue(VARIANT *pValue)
{
	hrx hr = impl::Call(this, &XML::IXMLDOMAttribute::get_value, pValue);
}

void DomAttribute::SetValue(const stringxi& sValue)
{
	hrx hr = impl::Call(this, &XML::IXMLDOMAttribute::put_value, sValue);
}

//////////////////////////////////////////////////////////////////////////

DomContainer::DomContainer(XML::IXMLDOMNode *pNode) : DomNode(pNode) {}

DomElement DomContainer::AddElement(const DomName& name)
{
	CComPtr<XML::IXMLDOMNode> spEltNode;
	impl::GetDocument(this)->createNode(CComVariant(XML::NODE_ELEMENT), name.m_sQualifiedName, name.m_sNamespaceUri, &spEltNode);

	return impl::Append<DomElement>(this, spEltNode);
}

DomElement DomContainer::AddElement(const stringxi& sQualifiedName, const stringxi& sNamespaceUri)
{
	return AddElement(DomName(sQualifiedName, sNamespaceUri));
}

DomText DomContainer::AddText(const stringx& sText)
{
	CComPtr<XML::IXMLDOMText> spText;
	impl::GetDocument(this)->createTextNode(sText, &spText);
	return impl::Append<DomText>(this, spText);
}

DomText DomContainer::AddText(const stringxi& sText)
{
	CComPtr<XML::IXMLDOMText> spText;
	impl::GetDocument(this)->createTextNode(sText, &spText);
	return impl::Append<DomText>(this, spText);
}

DomComment DomContainer::AddComment(const stringxi& sComment)
{
	CComPtr<XML::IXMLDOMComment> spComment;
	impl::GetDocument(this)->createComment(sComment, &spComment);
	return impl::Append<DomComment>(this, spComment);
}

DomComment DomContainer::AddComment(const stringx& sComment)
{
	CComPtr<XML::IXMLDOMComment> spComment;
	impl::GetDocument(this)->createComment(sComment, &spComment);
	return impl::Append<DomComment>(this, spComment);
}

DomElement DomContainer::AddElementWithText(const DomName& name, const stringxi& sText)
{
	CComPtr<XML::IXMLDOMNode> spEltNode;
	impl::GetDocument(this)->createNode(CComVariant(XML::NODE_ELEMENT), name.m_sQualifiedName, name.m_sNamespaceUri, &spEltNode);
	hrx hr = spEltNode->put_text(sText);
	return impl::Append<DomElement>(this, spEltNode);
}

DomElement DomContainer::AddElementWithText(const DomName& name, const stringx& sText)
{
	CComPtr<XML::IXMLDOMNode> spEltNode;
	impl::GetDocument(this)->createNode(CComVariant(XML::NODE_ELEMENT), name.m_sQualifiedName, name.m_sNamespaceUri, &spEltNode);
	hrx hr = spEltNode->put_text(sText);
	return impl::Append<DomElement>(this, spEltNode);
}

DomElement DomContainer::AddElementWithText(const stringxi& sQualifiedName, const stringxi& sNamespaceUri, const stringxi& sText)
{
	return AddElementWithText(DomName(sQualifiedName, sNamespaceUri), sText);
}

DomElement DomContainer::AddElementWithText(const stringxi& sQualifiedName, const stringxi& sNamespaceUri, const stringx& sText)
{
	return AddElementWithText(DomName(sQualifiedName, sNamespaceUri), sText);
}

DomElement DomContainer::AddElementWithTextIfText(const DomName& name, const stringxi& sText)
{
	return sText.empty() ? DomElement::Empty() : AddElementWithText(name, sText);
}

DomElement DomContainer::AddElementWithTextIfText(const DomName& name, const stringx& sText)
{
	return sText.empty() ? DomElement::Empty() : AddElementWithText(name, sText);
}

DomElement DomContainer::AddElementWithTextIfText(const stringxi& sQualifiedName, const stringxi& sNamespaceUri, const stringxi& sText)
{
	return sText.empty() ? DomElement::Empty() : AddElementWithText(sQualifiedName, sNamespaceUri, sText);
}

DomElement DomContainer::AddElementWithTextIfText(const stringxi& sQualifiedName, const stringxi& sNamespaceUri, const stringx& sText)
{
	return sText.empty() ? DomElement::Empty() : AddElementWithText(sQualifiedName, sNamespaceUri, sText);
}

DomProcessingInstruction DomContainer::AddPI(const stringxi& sTarget, const stringxi& sData)
{
	CComPtr<XML::IXMLDOMProcessingInstruction> spPI;
	impl::GetDocument(this)->createProcessingInstruction(sTarget, sData, &spPI);
	return impl::Append<DomProcessingInstruction>(this, spPI);
}

DomElement DomContainer::EnsureElement(const stringxi& sSearchName, const DomName& name)
{
	auto elt = SelectSingleElement(sSearchName);
	if (!elt)
		elt = AddElement(name);
	return elt;
}

DomElement DomContainer::EnsureElement(const stringxi& sSearchName, const stringxi& sCreateName, const stringxi& sNamespaceUri)
{
	return EnsureElement(sSearchName, DomName(sCreateName, sNamespaceUri));
}

DomElement DomContainer::EnsureElementWithAttribute(const stringxi& sSearchElt, const DomName& nameElt, const DomName& nameAttr, const stringxi& sAttrValue)
{
	auto elt = SelectSingleElement(sSearchElt + L"[@" + nameAttr.m_sQualifiedName + L"='" + sAttrValue + L"']");
	if (!elt)
	{
		elt = AddElement(nameElt);
		elt.SetAttribute(nameAttr, sAttrValue);
	}
	return elt;
}

DomElementList DomContainer::GetElements() const
{
	return DomElementList(impl::Get<CComPtr<XML::IXMLDOMNodeList>>(this, &XML::IXMLDOMNode::selectNodes, stringx(L"*")));
}

DomElementList DomContainer::SelectElements(const stringxi& sXPathQuery) const
{
	return DomElementList(impl::Get<CComPtr<XML::IXMLDOMNodeList>>(this, &XML::IXMLDOMNode::selectNodes, sXPathQuery));
}

is::xml::dom::DomElementList DomContainer::SelectElements(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const
{
	detail::TemporarySelectionNamespace restore(this, sSelectionNamespaces);
	return SelectElements(sXPathQuery);
}

DomElement DomContainer::SelectSingleElement(const stringxi& sXPathQuery) const
{
	auto spNode = impl::Get<CComPtr<XML::IXMLDOMNode>>(this, &XML::IXMLDOMNode::selectSingleNode, sXPathQuery);
	return impl::FromXmlNode<DomElement>(DomTraits<DomElement>::QI(spNode));
}

is::xml::dom::DomElement DomContainer::SelectSingleElement(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const
{
	detail::TemporarySelectionNamespace restore(this, sSelectionNamespaces);
	return SelectSingleElement(sXPathQuery);
}

DomAttributeList DomContainer::SelectAttributes(const stringxi& sXPathQuery) const
{
	return DomAttributeList(impl::Get<CComPtr<XML::IXMLDOMNodeList>>(this, &XML::IXMLDOMNode::selectNodes, sXPathQuery));
}

DomAttributeList DomContainer::SelectAttributes(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const
{
	detail::TemporarySelectionNamespace restore(this, sSelectionNamespaces);
	return SelectAttributes(sXPathQuery);
}

DomAttribute DomContainer::SelectSingleAttribute(const stringxi& sXPathQuery) const
{
	auto spNode = impl::Get<CComPtr<XML::IXMLDOMNode>>(this, &XML::IXMLDOMNode::selectSingleNode, sXPathQuery);
	return impl::FromXmlNode<DomAttribute>(DomTraits<DomAttribute>::QI(spNode));
}

is::xml::dom::DomAttribute DomContainer::SelectSingleAttribute(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const
{
	detail::TemporarySelectionNamespace restore(this, sSelectionNamespaces);
	return SelectSingleAttribute(sXPathQuery);
}

DomCommentList DomContainer::SelectComments(const stringxi& sXPathQuery) const
{
	return DomCommentList(impl::Get<CComPtr<XML::IXMLDOMNodeList>>(this, &XML::IXMLDOMNode::selectNodes, sXPathQuery));
}

is::xml::dom::DomCommentList DomContainer::SelectComments(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const
{
	detail::TemporarySelectionNamespace restore(this, sSelectionNamespaces);
	return SelectComments(sXPathQuery);
}

DomComment DomContainer::SelectSingleComment(const stringxi& sXPathQuery) const
{
	auto spNode = impl::Get<CComPtr<XML::IXMLDOMNode>>(this, &XML::IXMLDOMNode::selectSingleNode, sXPathQuery);
	return impl::FromXmlNode<DomComment>(DomTraits<DomComment>::QI(spNode));
}

is::xml::dom::DomComment DomContainer::SelectSingleComment(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const
{
	detail::TemporarySelectionNamespace restore(this, sSelectionNamespaces);
	return SelectSingleComment(sXPathQuery);
}

DomElement DomContainer::GetParentElement() const
{
	auto spNode = impl::Get<CComPtr<XML::IXMLDOMNode>>(this, &XML::IXMLDOMNode::get_parentNode);
	return impl::FromXmlNode<DomElement>(DomTraits<DomElement>::QI(spNode));
}

long DomContainer::SelectCount(const stringxi& sXPathQuery) const
{
	auto spNodes = impl::Get<CComPtr<XML::IXMLDOMNodeList>>(this, &XML::IXMLDOMNode::selectNodes, sXPathQuery);
	long cNodes = 0;
	if (spNodes)
		spNodes->get_length(&cNodes);
	return cNodes;
}

stringxi DomContainer::GetChildText(const stringxi& sXPathQuery) const
{
	stringxi sText;
	auto spNode = impl::Get<CComPtr<XML::IXMLDOMNode>>(this, &XML::IXMLDOMNode::selectSingleNode, sXPathQuery);
	hrx hr = spNode ? spNode->get_text(&sText) : ERROR_NO_MORE_ITEMS;
	return sText;
}

stringxi DomContainer::GetChildText(const stringxi& sXPathQuery, const stringxi& sDefault) const
{
	stringxi sText;
	auto spNode = impl::Get<CComPtr<XML::IXMLDOMNode>>(this, &XML::IXMLDOMNode::selectSingleNode, sXPathQuery);
	if (spNode)
		hrx hr = spNode->get_text(&sText);
	else
		sText = sDefault;
	return sText;
}

bool DomContainer::SetChildText(const stringxi& sXPathQuery, const stringxi& sText)
{
	auto spNode = impl::Get<CComPtr<XML::IXMLDOMNode>>(this, &XML::IXMLDOMNode::selectSingleNode, sXPathQuery);
	if (spNode)
		spNode->put_text(sText);
	return spNode != nullptr;
}

//////////////////////////////////////////////////////////////////////////

DomProcessingInstruction::DomProcessingInstruction(XML::IXMLDOMProcessingInstruction *pNode) : DomNode(pNode) {}

stringxi DomProcessingInstruction::GetTarget() const
{
	return impl::Get<stringxi>(this, &XML::IXMLDOMProcessingInstruction::get_target);
}

stringxi DomProcessingInstruction::GetData() const
{
	return impl::Get<stringxi>(this, &XML::IXMLDOMProcessingInstruction::get_data);
}

void DomProcessingInstruction::SetData(const stringxi& sData)
{
	hrx hr = impl::Call(this, &XML::IXMLDOMProcessingInstruction::put_data, sData);
}

//////////////////////////////////////////////////////////////////////////

DomText::DomText(XML::IXMLDOMText *pNode) : DomNode(pNode) {}

stringxi DomText::GetText() const
{
	return impl::Get<stringxi>(this, &XML::IXMLDOMText::get_text);
}

void DomText::SetText(const stringxi& sText)
{
	hrx hr = impl::Call(this, &XML::IXMLDOMText::put_text, sText);
}

//////////////////////////////////////////////////////////////////////////

DomComment::DomComment(XML::IXMLDOMComment *pComment) : DomNode(pComment) {}

stringxi DomComment::GetComment() const
{
	return impl::Get<stringxi>(this, &XML::IXMLDOMComment::get_text);
}

void DomComment::SetComment(const stringxi& sComment)
{
	hrx hr = impl::Call(this, &XML::IXMLDOMComment::put_text, sComment);
}

//////////////////////////////////////////////////////////////////////////

DomDocument::DomDocument(XML::IXMLDOMDocument2 *pDoc) : DomContainer(pDoc) {}

DomDocument::DomDocument(const stringxi& sSelectionNamespaces)
	: DomContainer(impl::CreateNewDocument())
{
	hrx hr = impl::Call(this, &XML::IXMLDOMDocument2::put_validateOnParse, VARIANT_FALSE);
	hr = impl::Call(this, &XML::IXMLDOMDocument2::setProperty, stringxi(L"SelectionLanguage"), CComVariant(L"XPath"));
	hr = impl::Call(this, &XML::IXMLDOMDocument2::setProperty, stringxi(L"MultipleErrorMessages"), CComVariant(VARIANT_TRUE));
	hr = impl::Call(this, &XML::IXMLDOMDocument2::setProperty, stringxi(L"NewParser"), CComVariant(VARIANT_TRUE));
	SetSelectionNamespaces(sSelectionNamespaces);
}

bool DomDocument::LoadFile(LPCWSTR szFile)
{
	return VARIANT_FALSE != impl::Get<VARIANT_BOOL>(this, &XML::IXMLDOMDocument2::load, CComVariant(szFile));
}

bool DomDocument::LoadText(const stringxi& sText)
{
	return VARIANT_FALSE != impl::Get<VARIANT_BOOL>(this, &XML::IXMLDOMDocument2::loadXML, sText);
}

bool DomDocument::LoadStream(IStream* pStream)
{
	return VARIANT_FALSE != impl::Get<VARIANT_BOOL>(this, &XML::IXMLDOMDocument2::load, CComVariant(pStream));
}

bool DomDocument::LoadPEResource(const stringxi& sPE, LPCWSTR szName, LPCWSTR szType)
{
	HMODULE hPE = ::LoadLibraryEx(sPE, NULL, LOAD_LIBRARY_AS_DATAFILE);
	bool fLoaded = hPE ? LoadPEResource(hPE, szName, szType) : false;
	if (hPE)
		::FreeLibrary(hPE);
	return fLoaded;
}

bool DomDocument::LoadPEResource(HMODULE hPE, LPCWSTR szName, LPCWSTR szType)
{
	HRSRC hRsrc = ::FindResource(hPE, szName, szType);
	if (!hRsrc)
		return false;

	DWORD cbRsrc = ::SizeofResource(hPE, hRsrc);
	HGLOBAL hgRsrc = ::LoadResource(hPE, hRsrc);
	LPVOID pvRsrc = ::LockResource(hgRsrc);

	CComPtr<IStream> spRsrc;
	spRsrc.Attach(SHCreateMemStream((LPBYTE)pvRsrc, cbRsrc));
	return spRsrc && LoadStream(spRsrc);
}

bool DomDocument::LoadPEManifest(const stringxi& sPE, DomPEFlags flags)
{
	bool fLoaded = false;
	const DWORD dwFlags = (DWORD)flags;
	if (!fLoaded && !(dwFlags & (DWORD)DomPEFlags::ExternalOnly))
	{
		HMODULE hPE = ::LoadLibraryEx(sPE, NULL, LOAD_LIBRARY_AS_DATAFILE);
		if (!(dwFlags & (DWORD)DomPEFlags::ResourceMask))
			flags = static_cast<DomPEFlags>(dwFlags | static_cast<DWORD>(sPE.endswith(L".exe")
				? DomPEFlags::CreateProcessResource : DomPEFlags::IsolationAwareResource));
		fLoaded = LoadPEManifest(hPE, flags);
		if (hPE)
			::FreeLibrary(hPE);
	}
	if (!fLoaded && !(dwFlags & (DWORD)DomPEFlags::EmbeddedOnly))
	{
		fLoaded = LoadFile(sPE + L".manifest");
	}
	return fLoaded;
}

bool DomDocument::LoadPEManifest(HMODULE hPE, DomPEFlags flags)
{
	bool fLoaded = false;
	const DWORD dwFlags = (DWORD)flags;
	const DWORD dwResource = dwFlags & (DWORD)DomPEFlags::ResourceMask;

	HRSRC hMan = nullptr;
	if (!dwResource || dwResource == (DWORD)DomPEFlags::CreateProcessResource)
		hMan = (hPE && !hMan) ? ::FindResource(hPE, CREATEPROCESS_MANIFEST_RESOURCE_ID, MAKEINTRESOURCE(RT_MANIFEST)) : hMan;
	if (!dwResource || dwResource == (DWORD)DomPEFlags::IsolationAwareResource)
		hMan = (hPE && !hMan) ? ::FindResource(hPE, ISOLATIONAWARE_MANIFEST_RESOURCE_ID, MAKEINTRESOURCE(RT_MANIFEST)) : hMan;

	if (!fLoaded && hMan)
	{
		DWORD cbConfig = ::SizeofResource(hPE, hMan);
		HGLOBAL hgConfig = ::LoadResource(hPE, hMan);
		LPVOID pvConfig = ::LockResource(hgConfig);

		CComPtr<IStream> spConfig;
		spConfig.Attach(SHCreateMemStream((LPBYTE)pvConfig, cbConfig));
		if (spConfig)
			fLoaded = LoadStream(spConfig);
	}
	return fLoaded;
}

bool DomDocument::SaveToFile(const stringxi& sFile, DomSaveFlags flags)
{
	if (DomSaveFlags::Indent == flags)
	{
		CComPtr<IStream> spStream;
		hrx hr = SHCreateStreamOnFile(sFile, STGM_CREATE | STGM_WRITE, &spStream);
		CComVariant cvOutput(spStream);
		return SUCCEEDED(MSXMLWrapper::IndentXml(impl::GetDocument(this), cvOutput));
	}
	return SUCCEEDED(impl::Call(this, &XML::IXMLDOMDocument2::save, sFile));
}

DomDocument DomDocument::FromFile(LPCWSTR szFile, const stringxi& sSelectionNamespaces)
{
	DomDocument doc(sSelectionNamespaces);
	ATLVERIFY(doc.LoadFile(szFile));
	return doc;
}

DomDocument DomDocument::FromText(const stringxi& sText, const stringxi& sSelectionNamespaces)
{
	DomDocument doc(sSelectionNamespaces);
	ATLVERIFY(doc.LoadText(sText));
	return doc;
}

DomDocument DomDocument::FromStream(IStream* pStream, const stringxi& sSelectionNamespaces)
{
	DomDocument doc(sSelectionNamespaces);
	ATLVERIFY(doc.LoadStream(pStream));
	return doc;
}

DomDocument DomDocument::FromPEResource(const stringxi& sPE, LPCWSTR szName, LPCWSTR szType, const stringxi& sSelectionNamespaces)
{
	DomDocument doc(sSelectionNamespaces);
	ATLVERIFY(doc.LoadPEResource(sPE, szName, szType));
	return doc;
}

DomDocument DomDocument::FromPEResource(HMODULE hPE, LPCWSTR szName, LPCWSTR szType, const stringxi& sSelectionNamespaces)
{
	DomDocument doc(sSelectionNamespaces);
	ATLVERIFY(doc.LoadPEResource(hPE, szName, szType));
	return doc;
}

DomDocument DomDocument::FromPEManifest(const stringxi& sPE, DomPEFlags flags, const stringxi& sSelectionNamespaces)
{
	DomDocument doc(sSelectionNamespaces);
	ATLVERIFY(doc.LoadPEManifest(sPE, flags));
	return doc;
}

DomDocument DomDocument::FromPEManifest(HMODULE hPE, DomPEFlags flags, const stringxi& sSelectionNamespaces)
{
	DomDocument doc(sSelectionNamespaces);
	ATLVERIFY(doc.LoadPEManifest(hPE, flags));
	return doc;
}

void DomDocument::SetSelectionNamespaces(const stringxi& sSelectionNamespaces)
{
	hrx hr = impl::Call(this, &XML::IXMLDOMDocument2::setProperty, stringxi(L"SelectionNamespaces"), sSelectionNamespaces);
}

stringxi DomDocument::GetSelectionNamespaces() const
{
	return stringxi(impl::Get<CComVariant>(this, &XML::IXMLDOMDocument2::getProperty, stringxi(L"SelectionNamespaces")));
}

stringxi DomDocument::QualifyXPathName(const DomName& name) const
{
	if (name.m_sNamespaceUri.empty())
		return name.m_sQualifiedName;

	auto sNamespaces = GetSelectionNamespaces();
	sNamespaces.replace_all(L"\"", L"\'");
	auto ns = sNamespaces.find(L"'" + name.m_sNamespaceUri + L"'");
	if (ns == stringxi::npos)
		throw std::invalid_argument("Namespace unavailable for querying");
	auto p = sNamespaces.rfind(':', ns);
	auto prefix = sNamespaces.substr(p + 1, ns - 2 - p);
	return prefix + L":" + name.m_sQualifiedName.right_back_char(':');
}

stringxi DomDocument::QualifyXPathName(const stringxi& sQualifiedName, const stringxi& sNamespaceURI) const
{
	return QualifyXPathName(DomName(sQualifiedName, sNamespaceURI));
}

DomElement DomDocument::GetDocumentElement() const
{
	auto spElt = impl::Get<CComPtr<XML::IXMLDOMElement>>(this, &XML::IXMLDOMDocument2::get_documentElement);
	return impl::FromXmlNode<DomElement>(spElt);
}

DomParseErrorList DomDocument::GetParseErrors() const
{
	auto spParseError = impl::Get<CComPtr<XML::IXMLDOMParseError>>(this, &XML::IXMLDOMDocument2::get_parseError);

	return impl::FromParseErrorList(spParseError);
}

DomParseErrorList DomDocument::Validate(DomSchemaCollection schemaCollection)
{
	impl::Call(this, &XML::IXMLDOMDocument2::putref_schemas, CComVariant(schemaCollection.m_spSchemas));
	auto spParseError = impl::Get<CComPtr<XML::IXMLDOMParseError>>(this, &XML::IXMLDOMDocument2::validate);

	return impl::FromParseErrorList(spParseError);
}

void DomDocument::Erase(DomElementList& elts)
{
	for (auto& elt : elts)
	{
		elt.Remove();
	}
}

#if _MSC_VER >= 1900
DomDocument::operator bool() const noexcept
{
	return bool(GetDocumentElement());
}
#else
DomDocument::operator DomDocument::_Bool_type() const _NOEXCEPT
{	// test for non-null pointer
	return (GetDocumentElement() ? (&_STD _Bool_struct<DomNode>::_Member) : 0);
}

#endif

//////////////////////////////////////////////////////////////////////////

DomElement::DomElement(XML::IXMLDOMElement *pNode) : DomContainer(pNode) {}

DomElement DomElement::Empty()
{
	return DomElement(nullptr);
}

DomAttributeList DomElement::GetAttributes() const
{
	return SelectAttributes(L"@*");
}

DomAttribute DomElement::GetDomAttribute(const DomName& name) const
{
	auto spAttribute = impl::Get<CComPtr<XML::IXMLDOMAttribute>>(this, &XML::IXMLDOMElement::getAttributeNode, name.m_sQualifiedName);
	return impl::FromXmlNode<DomAttribute>(spAttribute);
}

stringxi DomElement::GetAttribute(const DomName& name) const
{
	auto cvValue = impl::Get<CComVariant>(this, &XML::IXMLDOMElement::getAttribute, name.m_sQualifiedName);
	return stringxi(cvValue);
}

stringxi DomElement::GetAttributeOrDefault(const DomName& name, const stringxi& sDefault) const
{
	auto cvValue = impl::Get<CComVariant>(this, &XML::IXMLDOMElement::getAttribute, name.m_sQualifiedName);
	return VT_NULL < cvValue.vt ? stringxi(cvValue) : sDefault;
}

DomAttribute DomElement::SetAttribute(const DomName& name, LPCWSTR szValue)
{
	return SetAttribute(name, CComVariant(szValue));
}

DomAttribute DomElement::SetAttribute(const DomName& name, const CComVariant& cvValue)
{
	CComPtr<XML::IXMLDOMAttribute> spAttribute;
	if (name.m_sNamespaceUri.empty())
	{
		impl::GetDocument(this)->createAttribute(name.m_sQualifiedName, &spAttribute);
	}
	else
	{
		CComPtr<XML::IXMLDOMNode> spAttributeNode;
		impl::GetDocument(this)->createNode(CComVariant(NODE_ATTRIBUTE), name.m_sQualifiedName, name.m_sNamespaceUri, &spAttributeNode);
		hrx hr = spAttributeNode.QueryInterface(&spAttribute);
	}

	CComPtr<XML::IXMLDOMAttribute> spOut;
	hrx hr = spAttribute->put_value(cvValue);
	impl::Call(this, &XML::IXMLDOMElement::setAttributeNode, spAttribute, &spOut);
	return impl::FromXmlNode<DomAttribute>(spAttribute);
}

DomAttribute DomElement::SetAttribute(const DomName& name, const FILETIME& ft, DomTimeFlags flags)
{
	const DWORD dwFlags = (DWORD)flags;
	SYSTEMTIME st, stSave;
	LPSYSTEMTIME pstUse = &stSave;
	BOOL fSuccess = FileTimeToSystemTime(&ft, &st);
	if (fSuccess && dwFlags & (DWORD)DomTimeFlags::ConvertToUTC)
		fSuccess = TzSpecificLocalTimeToSystemTime(nullptr, &st, &stSave);
	else if (fSuccess && dwFlags & (DWORD)DomTimeFlags::ConvertToLocal)
		fSuccess = SystemTimeToTzSpecificLocalTime(nullptr, &stSave, &st);
	else
		pstUse = &st;

	stringxi sLocalTime;
	const LCID lcid = (dwFlags & (DWORD)DomTimeFlags::FormatLocal) ? LOCALE_USER_DEFAULT : LOCALE_INVARIANT;
	DWORD cchTime = GetTimeFormatW(lcid, 0, pstUse, nullptr, nullptr, 0);
	if (fSuccess && cchTime++)
	{
		GetTimeFormatW(lcid, 0, pstUse, nullptr, sLocalTime.get_buffer(cchTime), cchTime);
		return SetAttribute(name, sLocalTime);
	}
	return DomAttribute::Empty();
}

void DomElement::EraseAttribute(const DomName& name)
{
	hrx hr = impl::Call(this, &XML::IXMLDOMElement::removeAttribute, name.m_sQualifiedName);
}

stringxi DomElement::GetElementText() const
{
	return impl::Get<stringxi>(this, &XML::IXMLDOMElement::get_text);
}

void DomElement::Remove()
{
	impl::Remove(this);
}

//////////////////////////////////////////////////////////////////////////

DomParseError::DomParseError(XML::IXMLDOMParseError* pParseError) : m_spParseError(pParseError) {}

long DomParseError::GetLine()
{
	long lLine;
	hrx hr = m_spParseError->get_line(&lLine);
	return lLine;
}

long DomParseError::GetColumn()
{
	long lColumn;
	hrx hr = m_spParseError->get_linepos(&lColumn);
	return lColumn;
}

stringxi DomParseError::GetReason()
{
	stringxi sReason;
	hrx hr = m_spParseError->get_reason(&sReason);
	return sReason;
}

stringxi DomParseError::GetSourceText()
{
	stringxi sText;
	hrx hr = m_spParseError->get_srcText(&sText);
	return sText;
}

//////////////////////////////////////////////////////////////////////////

template <typename DomType>
detail::DomList<DomType>::DomList(XML::IXMLDOMNodeList *pList)
{
	LONG cItems = 0;
	if (pList)
		pList->get_length(&cItems);
	reserve(cItems);

	for (LONG lItem = 0; lItem < cItems; ++lItem)
	{
		CComPtr<XML::IXMLDOMNode> spNode;
		hrx hr = pList->get_item(lItem, &spNode);
		emplace_back(impl::FromXmlNode<DomType>(spNode));
	}
}

detail::DomList<DomParseError>::DomList(XML::IXMLDOMParseErrorCollection *pAllErrors)
{
	LONG cItems = 0;
	if (pAllErrors)
		pAllErrors->get_length(&cItems);
	reserve(cItems);

	for (LONG lItem = 0; lItem < cItems; ++lItem)
	{
		CComPtr<XML::IXMLDOMParseError2> spNode;
		hrx hr = pAllErrors->get_item(lItem, &spNode);
		emplace_back(impl::FromParseError(spNode));
	}
}

detail::DomList<DomParseError>::DomList(XML::IXMLDOMParseError *pError)
{
	emplace_back(impl::FromParseError(pError));
}


//////////////////////////////////////////////////////////////////////////

DomSchemaCollection::DomSchemaCollection()
{
	MSXMLWrapper::CreateSchemaCollection(&m_spSchemas);
	m_spSchemas->put_validateOnLoad(VARIANT_FALSE);
}

bool DomSchemaCollection::AddSchema(const stringxi& sNamespace, const stringxi& sXsd)
{
	return SUCCEEDED(m_spSchemas->add(sNamespace, sXsd));
}

bool DomSchemaCollection::AddSchema(const stringxi& sNamespace, IStream *pXsd)
{
	return SUCCEEDED(m_spSchemas->add(sNamespace, CComVariant(pXsd)));
}

bool DomSchemaCollection::AddSchema(const stringxi& sNamespace, const DomDocument& doc)
{
	return SUCCEEDED(m_spSchemas->add(sNamespace, CComVariant(impl::GetDocument(&doc))));
}

bool DomSchemaCollection::AddSchema(const DomDocument& doc)
{
	return AddSchema(doc.GetChildText(L"xs:schema/@targetNamespace"), doc);
}

bool DomSchemaCollection::Validate()
{
	return SUCCEEDED(m_spSchemas->validate());
}

//////////////////////////////////////////////////////////////////////////

} // dom

namespace compat {
	DomDocument FromDom(XML::IXMLDOMDocument2 *pDoc) { return detail::impl::FromXmlNode<DomDocument>(detail::impl::InitializeDoc(pDoc)); }
	DomElement FromDom(XML::IXMLDOMElement *pElt) { return detail::impl::FromXmlNode<DomElement>(pElt); }
	CComPtr<XML::IXMLDOMDocument2> ToDomDoc(const DomNode& node) { return detail::impl::GetDocument(&node); }
	CComPtr<XML::IXMLDOMDocument2> ToDom(const DomDocument& doc) { return detail::impl::Compat_ToXmlNode(doc); }
	CComPtr<XML::IXMLDOMElement> ToDom(const DomElement& elt) { return detail::impl::Compat_ToXmlNode(elt); }
}

} // xml
} // is