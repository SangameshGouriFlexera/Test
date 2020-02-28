#pragma once

#include "ISXmlFwd.h"

#include "stringx.h"
// Wrapper around MSXML that, in theory, would let us swap any other DOM implementation in

namespace XML {
	struct IXMLDOMNode;
	struct IXMLDOMText;
	struct IXMLDOMComment;
	struct IXMLDOMAttribute;
	struct IXMLDOMElement;
	struct IXMLDOMDocument2;
	struct IXMLDOMParseError;
	struct IXMLDOMParseErrorCollection;
	struct IXMLDOMProcessingInstruction;
	struct IXMLDOMSchemaCollection2;
	struct IXMLDOMNodeList;
}

namespace is {
namespace xml {
IS_INLINE_NAMESPACE dom {

	namespace detail
	{
		class impl;

		template <typename DomType>
		class DomList : public std::vector<DomType>
		{
		public:
			using std::vector<DomType>::begin;
			using std::vector<DomType>::cbegin;
			using std::vector<DomType>::rbegin;
			using std::vector<DomType>::crbegin;

			using std::vector<DomType>::end;
			using std::vector<DomType>::cend;
			using std::vector<DomType>::rend;
			using std::vector<DomType>::crend;

			using std::vector<DomType>::empty;
			using std::vector<DomType>::size;

		private:
			friend DomContainer;
			DomList(XML::IXMLDOMNodeList *pList);
		};

		template <>
		class DomList<DomParseError> : public std::vector<DomParseError>
		{
		public:
			using std::vector<DomParseError>::begin;
			using std::vector<DomParseError>::cbegin;
			using std::vector<DomParseError>::rbegin;
			using std::vector<DomParseError>::crbegin;

			using std::vector<DomParseError>::end;
			using std::vector<DomParseError>::cend;
			using std::vector<DomParseError>::rend;
			using std::vector<DomParseError>::crend;

			using std::vector<DomParseError>::empty;
			using std::vector<DomParseError>::size;

		private:
			friend detail::impl;
			DomList(XML::IXMLDOMParseErrorCollection *pAllErrors);
			DomList(XML::IXMLDOMParseError *pError);
		};
	}

	typedef detail::DomList<DomAttribute> DomAttributeList;
	typedef detail::DomList<DomComment> DomCommentList;
	typedef detail::DomList<DomElement> DomElementList;
	typedef detail::DomList<DomParseError> DomParseErrorList;

	struct DomName
	{
		DomName(LPCWSTR szQualifedName, LPCWSTR szNamespaceURI = L"")
			: m_sQualifiedName(szQualifedName)
			, m_sNamespaceUri(szNamespaceURI)
		{}

		DomName(const stringxi& sQualifiedName, const stringxi& sNamespaceUri = L"")
			: m_sQualifiedName(sQualifiedName)
			, m_sNamespaceUri(sNamespaceUri)
		{}

		DomName(stringxi&& sQualifiedName, stringxi&& sNamespaceUri = L"")
			: m_sQualifiedName(std::move(sQualifiedName))
			, m_sNamespaceUri(std::move(sNamespaceUri))
		{}

		DomName(const stringxi& sLocalName, const stringxi& sNamespaceUri, const stringxi& sPrefix)
			: m_sQualifiedName(!sPrefix.empty() ? sPrefix + L":" + sLocalName : sLocalName)
			, m_sNamespaceUri(sNamespaceUri)
		{}

		DomName(stringxi&& sLocalName, stringxi&& sNamespaceUri, stringxi&& sPrefix)
			: m_sQualifiedName(!sPrefix.empty() ? std::move(sPrefix) + L":" + std::move(sLocalName) : std::move(sLocalName))
			, m_sNamespaceUri(std::move(sNamespaceUri))
		{}

		const stringxi m_sQualifiedName;
		const stringxi m_sNamespaceUri;

		friend bool operator==(const DomName& a, const DomName& b)
		{
			return a.m_sNamespaceUri == b.m_sNamespaceUri
				&& a.m_sQualifiedName == b.m_sQualifiedName;
		}

		friend bool operator<(const DomName& a, const DomName& b)
		{
			return a.m_sNamespaceUri < b.m_sNamespaceUri
				|| (a.m_sNamespaceUri == b.m_sNamespaceUri
					&& a.m_sQualifiedName < b.m_sQualifiedName);
		}

	};

	// DomNode: base class of most DomTypes, stores a single lightweight pointer
	// While this could feasibly be used as the base of a class hierarchy, these classes are intended for use
	// as value types. However since they will refcount a CComPtr, it's advantageous to pass by reference when possible.
	class DomNode
	{
	public:
		DomName GetName() const;

#if _MSC_VER >= 1900
		explicit operator bool() const noexcept { return m_pNode != nullptr;  }
#else
		typedef int _STD _Bool_struct<DomNode>::* _Bool_type;
		operator _Bool_type() const _NOEXCEPT
		{	// test for non-null pointer
			return (this->m_pNode != nullptr ? (&_STD _Bool_struct<DomNode>::_Member) : 0);
		}
#endif

		DomComment ChangeToComment();

	protected:
		DomNode(XML::IXMLDOMNode *pNode);
		~DomNode();

	private:
		friend detail::impl;
		CComPtr<XML::IXMLDOMNode> m_pNode;
	};

	// DomText: represent a text node, such as the text content of an element.
	class DomText : public DomNode
	{
	public:
		stringxi GetText() const;
		void SetText(const stringxi& sText);

	private:
		friend detail::impl;
		DomText(XML::IXMLDOMText *pNode);
	};

	// DomComment: represent a comment node. <!--comment-->
	class DomComment : public DomNode
	{
	public:
		stringxi GetComment() const;
		void SetComment(const stringxi& sComment);

	private:
		friend detail::impl;
		DomComment(XML::IXMLDOMComment *pComment);
	};

	// DomProcessingInstruction: represent a processing instruction. <?target data...?>
	class DomProcessingInstruction : public DomNode
	{
	public:
		stringxi GetTarget() const;
		stringxi GetData() const;

		void SetData(const stringxi& sData);

	private:
		friend detail::impl;
		DomProcessingInstruction(XML::IXMLDOMProcessingInstruction *pNode);
	};

	// DomAttribute: represent an attribute on an element. <element attribute="value"/>
	class DomAttribute : public DomNode
	{
	public:
		static DomAttribute Empty();

		stringxi GetValue() const;
		void GetValue(VARIANT *pValue);

		void SetValue(const stringxi& sValue);

	private:
		friend detail::impl;
		DomAttribute(XML::IXMLDOMAttribute *pNode);
	};

	// DomContainer: synthetic intermediate class, has operations shared between documents and elements:
	//  - Ability to add child nodes (elements, text, comments, processing instructions)
	//  - Ability to query child nodes (elements, attributes, etc.)
	//  - Helper to query or set child text, typically on an existing attribute-value or element-text.
	class DomContainer : public DomNode
	{
	public:
		// AddElement: Create and append an Element. Return it.
		DomElement AddElement(const DomName& name);
		DomElement AddElement(const stringxi& sQualifiedName, const stringxi& sNamespaceUri);

		// AddText: Create and append a Text Node. Return it.
		DomText AddText(const stringxi& sText);
		DomText AddText(const stringx& sText);

		// AddComment: Create and append a comment. Return it.
		DomComment AddComment(const stringxi& sComment);
		DomComment AddComment(const stringx& sComment);

		// AddPI: Create and append a ProcessingInstruction. Return it.
		DomProcessingInstruction AddPI(const stringxi& sTarget, const stringxi& sData = stringxi());

		// AddElementWithText: Create and append a child element with specified text. Return the element.
		DomElement AddElementWithText(const DomName& name, const stringxi& sText);
		DomElement AddElementWithText(const DomName& name, const stringx& sText);
		DomElement AddElementWithText(const stringxi& sQualifiedName, const stringxi& sNamespaceUri, const stringxi& sText);
		DomElement AddElementWithText(const stringxi& sQualifiedName, const stringxi& sNamespaceUri, const stringx& sText);

		// AddElementWithTextIfText: Like AddElementWithText, but if sText is empty, adds nothing and returns an empty DomElement.
		DomElement AddElementWithTextIfText(const DomName& name, const stringxi& sText);
		DomElement AddElementWithTextIfText(const DomName& name, const stringx& sText);
		DomElement AddElementWithTextIfText(const stringxi& sQualifiedName, const stringxi& sNamespaceUri, const stringxi& sText);
		DomElement AddElementWithTextIfText(const stringxi& sQualifiedName, const stringxi& sNamespaceUri, const stringx& sText);

		// EnsureElement: Get existing child element, or create and return new one.
		DomElement EnsureElement(const stringxi& sSearchName, const DomName& name);
		DomElement EnsureElement(const stringxi& sSearchName, const stringxi& sCreateName, const stringxi& sNamespaceUri);

		// EnsureElement: Get existing child element with specified attribute value, or create and return new one.
		DomElement EnsureElementWithAttribute(const stringxi& sSearchElt, const DomName& nameElt, const DomName& nameAttr, const stringxi& sAttrValue);

		// GetElements: Return a list of children elements
		DomElementList GetElements() const;

		// SelectElements: Return a list of elements selected by sXPathQuery.
		DomElementList SelectElements(const stringxi& sXPathQuery) const;
		// SelectElements: Return a list of elements selected by sXPathQuery, temporarily using sSelectionNamespaces instead.
		DomElementList SelectElements(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const;
		// SelectSingleElement: Return the first matching element selected by sXPathQuery.
		DomElement SelectSingleElement(const stringxi& sXPathQuery) const;
		// SelectSingleElement: Return the first matching element selected by sXPathQuery, temporarily using sSelectionNamespaces instead.
		DomElement SelectSingleElement(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const;

		// SelectAttributes: Return a list of attributes selected by sXPathQuery.
		DomAttributeList SelectAttributes(const stringxi& sXPathQuery) const;
		// SelectAttributes: Return a list of attributes selected by sXPathQuery, temporarily using sSelectionNamespaces instead.
		DomAttributeList SelectAttributes(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const;
		// SelectSingleAttribute: Return the first matching attribute selected by sXPathQuery.
		DomAttribute SelectSingleAttribute(const stringxi& sXPathQuery) const;
		// SelectSingleAttribute: Return the first matching attribute selected by sXPathQuery, temporarily using sSelectionNamespaces instead.
		DomAttribute SelectSingleAttribute(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const;

		// SelectComments: Return a list of comments selected by sXPathQuery.
		DomCommentList SelectComments(const stringxi& sXPathQuery) const;
		// SelectComments: Return a list of comments selected by sXPathQuery, temporarily using sSelectionNamespaces instead.
		DomCommentList SelectComments(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const;
		// SelectSingleComment: Return the first matching comment selected by sXPathQuery.
		DomComment SelectSingleComment(const stringxi& sXPathQuery) const;
		// SelectSingleComment: Return the first matching comment selected by sXPathQuery, temporarily using sSelectionNamespaces instead.
		DomComment SelectSingleComment(const stringxi& sXPathQuery, const stringxi& sSelectionNamespaces) const;

		DomElement GetParentElement() const;

		long SelectCount(const stringxi& sXPathQuery) const;

		// GetChildText: Return text of single-node XPath query. Throws if child is not found.
		stringxi GetChildText(const stringxi& sXPathQuery) const;

		// GetChildText: Return text of single-node XPath query. Return sDefault if child is not found.
		stringxi GetChildText(const stringxi& sXPathQuery, const stringxi& sDefault) const;

		// SetChildText: Set the text of the node returned from a single-node XPath query. Return false if child is not found.
		bool SetChildText(const stringxi& sXPathQuery, const stringxi& sText);

	protected:
		DomContainer(XML::IXMLDOMNode *pNode);
	};

	enum class DomSaveFlags
	{
		None = 0x0,	// Save as is
		Indent = 0x1,	// Indent the content while saving it
	};

	enum class DomPEFlags
	{
		None = 0x0,

		// Location flags: Set one to select a preferred source. Otherwise will load from resources, then external.
		//      Will fail if both are set. Ignored in methods taking HMODULE.
		EmbeddedOnly = 0x1,	// only load from PE resources
		ExternalOnly = 0x2,	// only load from external file

		// Embedded Resource Name flags: Specify which sources to examine.
		//		If none are specified in a method taking a filename, the extension determines the resource examined.
		//		If none are specified in a method taking HMODULE, all resources are examined.
		CreateProcessResource = 0x10,	// only load an Exe's resource name
		IsolationAwareResource = 0x20,	// only load a Dll's resource name

		ResourceMask = CreateProcessResource | IsolationAwareResource,
	};

	// DomDocument: represents an XML document. Adds abilities to load and save documents, specify selection namespaces, and validate.
	class DomDocument : public DomContainer
	{
	public:
		// DomDocument: Instantiate a new DomDocument with specified selection namespaces, and useful defaults.
		explicit DomDocument(const stringxi& sSelectionNamespaces = L"");

		// LoadFile: load an xml document from a file path name
		bool LoadFile(LPCWSTR szFile);

		// LoadText: load an xml document from XML text
		bool LoadText(const stringxi& sText);

		// LoadStream: load an xml document from an IStream
		bool LoadStream(IStream* pStream);

		// LoadPEResource: load an xml document that's stored as a PE resource, either identified by path or by already-loaded HMODULE.
		bool LoadPEResource(const stringxi& sPE, LPCWSTR szName, LPCWSTR szType);
		bool LoadPEResource(HMODULE hPE, LPCWSTR szName, LPCWSTR szType);

		// LoadPEManifest: load the xml configuration manifest stored as a PE resource (or possibly an external file), either identified
		//		by path or by already-loaded HMODULE. LoadPEManifest will search multiple locations per the value of flags. If a manifest
		//		is embedded but is not valid, it will prevent looking for an external manifest unless DomPEFlags::ExternalOnly is specified.
		bool LoadPEManifest(const stringxi& sPE, DomPEFlags flags);
		bool LoadPEManifest(HMODULE hPE, DomPEFlags flags);

		// SaveToFile: save an xml document to a file, with options specified in flags
		bool SaveToFile(const stringxi& sFile, DomSaveFlags flags);

		// FromXYZ: The static FromXYZ methods create a DomDocument, attempt to load its contents, and return it.
		//		If the load fails, it will return an empty document. However any XML document that lacks a root element will also be empty.
		//		So if you need to know 100% if the load succeeded, use the LoadXYZ methods. See LoadXYZ methods for further descriptions.
		static DomDocument FromFile(LPCWSTR szFile, const stringxi& sSelectionNamespaces = L"");
		static DomDocument FromText(const stringxi& sText, const stringxi& sSelectionNamespaces = L"");
		static DomDocument FromStream(IStream* pStream, const stringxi& sSelectionNamespaces = L"");
		static DomDocument FromPEResource(const stringxi& sPE, LPCWSTR szName, LPCWSTR szType, const stringxi& sSelectionNamespaces = L"");
		static DomDocument FromPEResource(HMODULE hPE, LPCWSTR szName, LPCWSTR szType, const stringxi& sSelectionNamespaces = L"");
		static DomDocument FromPEManifest(const stringxi& sPE, DomPEFlags flags, const stringxi& sSelectionNamespaces = L"");
		static DomDocument FromPEManifest(HMODULE hPE, DomPEFlags flags, const stringxi& sSelectionNamespaces = L"");

		void SetSelectionNamespaces(const stringxi& sSelectionNamespaces);
		stringxi GetSelectionNamespaces() const;

		// Qualify a name for use with the current SelectionNamespaces. Throws invalid_argument if a namespace is required but not present.
		stringxi QualifyXPathName(const DomName& name) const;
		stringxi QualifyXPathName(const stringxi& sQualifiedName, const stringxi& sNamespaceURI) const;

		DomElement GetDocumentElement() const;

		DomParseErrorList GetParseErrors() const;

		DomParseErrorList Validate(DomSchemaCollection schemaCollection);

		// Erase: Remove elements from the document. Note that removing them will empty the DomElements within the DomElementList.
		void Erase(DomElementList& elts);

#if _MSC_VER >= 1900
		explicit operator bool() const noexcept;
#else
		operator _Bool_type() const _NOEXCEPT;
#endif


	private:
		friend detail::impl;
		DomDocument(XML::IXMLDOMDocument2 *pNode);
	};

	enum class DomTimeFlags
	{
		None = 0,

		// Format flags control the appearance of the time as a string
		FormatInvariant = 0,	// use invariant format
		FormatLocal = 1,		// Use local default

		// Conversion flags change the time zone on read or write. If neither are passed, the timezone is unchanged.
		ConvertToUTC = 0x10,	// Pass Local and store UTC (or read Local and return UTC)
		ConvertToLocal = 0x20,	// Read UTC and return Local (or pass UTC and store Local)
	};

	// DomElement: represents and element. Adds abilities to set, query, or remove attributes, and element text.
	class DomElement : public DomContainer
	{
	public:
		static DomElement Empty();

		// GetAttributes: return a list of attributes
		DomAttributeList GetAttributes() const;

		// GetDomAttribute: return attribute or DomAttribute::Empty() if it doesn't exist
		DomAttribute GetDomAttribute(const DomName& name) const;

		// GetAttribute: return value of named attribute, or empty string if it doesn't exist
		stringxi GetAttribute(const DomName& name) const;

		// GetAttributeOrDefault: Return value of named attribute, or sDefault if it doesn't exist
		stringxi GetAttributeOrDefault(const DomName& name, const stringxi& sDefault) const;

		// SetAttribute: Set or add and set attribute to given value.
		DomAttribute SetAttribute(const DomName& name, LPCWSTR szValue);
		DomAttribute SetAttribute(const DomName& name, const CComVariant& cvValue);
		DomAttribute SetAttribute(const DomName& name, const FILETIME& ft, DomTimeFlags flags);

		// EraseAttribute: Remove an attribute from the specified element.
		void EraseAttribute(const DomName& name);

		// GetElementText: Return text of this element. Semantically identical to DomNode::GetText, but more clearly named.
		stringxi GetElementText() const;

		// Remove: Remove this element from the document.
		void Remove();

	private:
		friend detail::impl;
		DomElement(XML::IXMLDOMElement *pNode);
	};

	// DomParseError: represent a validation or parsing error. If loading or validating a document fails, these can specify why.
	class DomParseError
	{
	public:
		long GetLine();
		long GetColumn();
		stringxi GetReason();
		stringxi GetSourceText();

	private:
		friend detail::impl;
		DomParseError(XML::IXMLDOMParseError* pParseError);
		CComPtr<XML::IXMLDOMParseError> m_spParseError;
	};

	// DomSchemaCollection: represent a collection of schema files used to validate a document.
	class DomSchemaCollection
	{
		friend DomDocument;
	public:
		DomSchemaCollection();

		// AddSchema: load schema with specified namespace by path
		bool AddSchema(const stringxi& sNamespace, const stringxi& sXsd);
		// AddSchema: load schema with specified namespace from stream
		bool AddSchema(const stringxi& sNamespace, IStream *pXsd);
		// AddSchema: load schema with specified namespace from DomDocument
		bool AddSchema(const stringxi& sNamespace, const DomDocument& doc);
		// AddSchema: load schema from DomDocument, looking up namespace.
		// Requires document's SelectionNamespaces includes: xmlns:xs='http://www.w3.org/2001/XMLSchema'
		bool AddSchema(const DomDocument& doc);

		bool Validate();

	private:
		CComPtr<XML::IXMLDOMSchemaCollection2> m_spSchemas;
	};

} // namespace dom
IS_USING_INLINE_NAMESPACE(dom)

/// compat
// Note that the compat functions aren't particularly safe. Among other things, they cast away const.
namespace compat {
	DomDocument FromDom(XML::IXMLDOMDocument2 *pDoc);
	DomElement FromDom(XML::IXMLDOMElement *pElt);
	CComPtr<XML::IXMLDOMDocument2> ToDomDoc(const DomNode& node);
	CComPtr<XML::IXMLDOMDocument2> ToDom(const DomDocument& doc);
	CComPtr<XML::IXMLDOMElement> ToDom(const DomElement& elt);
}

} // namespace xml
} // namespace is