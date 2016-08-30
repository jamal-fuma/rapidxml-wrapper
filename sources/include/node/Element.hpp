#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "visitor/VisitableBase.hpp"

//!< An element node.
// Name contains element name.
//Value contains text of first data node.
struct Element
        : ElementNode
        , VisitableBase
{
    ElementNode() = default;
    virtual ~Element() = default;

    Element(rapidxml::xml_node<> * node);

    // visitor entry point
    virtual void accept(Visitor & v)

    // copyable
    Element & operator=(const Element & rhs) = default;
    Element(const Element & rhs) = default;

    // non copying string matchers
    bool match_xmlns_prefix(const char * xmlns_prefix, size_t len);
    bool match_fullname(const char * name);
    bool match_localname(const char * name);

    // access a qualified name as component
    Node::XML::QualifiedName m_name;
};

#endif /*  ndef ELEMENT_HPP */
