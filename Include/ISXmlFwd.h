#pragma once

// ISXmlFwd.h:
//  - Forward delcarations for ISXmlDom.h, ISXmlDom.cpp
//
// Note - would add declarations for a theoretical ISXmlSax here as well

// This block, which defines IS_INLINE_NAMESPACE and IS_USING_INLINE_NAMESPACE should probably be
// extracted to a theoretical <ISVsCompat.h>
#if !defined(IS_INLINE_NAMESPACE)
# if _MSC_VER >= 1900 // VS >= VS2015
#  define IS_INLINE_NAMESPACE inline namespace
#  define IS_USING_INLINE_NAMESPACE(ns)
# else // VS < VS2015
#  define IS_INLINE_NAMESPACE namespace
#  define IS_USING_INLINE_NAMESPACE(ns) using namespace ns; // simulate inline namespace. roughly.
# endif // VS2015
#endif //

// Forward declarations of namespace and members
namespace is {
namespace xml {
IS_INLINE_NAMESPACE dom {

enum class DomSaveFlags;
enum class DomPEFlags;
enum class DomTimeFlags;

struct DomName;

class DomNode;
class DomText;
class DomComment;
class DomProcessingInstruction;
class DomAttribute;
class DomContainer;
class DomDocument;
class DomElement;
class DomParseError;
class DomSchemaCollection;

} // namespace dom
IS_USING_INLINE_NAMESPACE(dom)
} // namespace xml
} // namespace is
