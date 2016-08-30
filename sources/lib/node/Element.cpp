#include "visitor/node/Element.hpp"

Node::XML::Element::Element(rapidxml::xml_node<> * node)
    : Node::XML::ElementNode(node)
//  , VisitableBase()
    , m_name(to_qualified_name())
{
}

// non copying string matchers
bool
Node::XML::Element::match_xmlns_prefix(const char * xmlns_prefix,size_t len)
{
    return m_name.match_prefix(xmlns_prefix,len);
}

bool
Node::XML::Element::match_fullname(const char * name)
{
    return m_name.match_fullname(name);
}

bool
Node::XML::Element::match_localname(const char * name)
{
    return m_name.match_localname(name);
}

std::string
Node::XML::Element::xmlns_prefix()
{
    return std::string(m_name.prefix(), m_name.prefix_size());
}

//void Node::XML::Element::accept(Visitor & v);
//{
//  v.visit(this);
//}
