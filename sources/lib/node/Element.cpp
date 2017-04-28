#include "node/Element.hpp"

namespace Node
{
    namespace XML
    {
        Element::Element(rapidxml::xml_node<> * node)
            : VisitableBase{}
            , m_node{node}
            , m_name{m_node.to_qualified_name()}
        {
        }

        // non copying string matchers
        bool
        Element::match_xmlns_prefix(const char * xmlns_prefix,size_t len) const
        {
            return m_name.match_prefix(xmlns_prefix,len);
        }

        bool
        Element::match_fullname(const char * name) const
        {
            return m_name.match_fullname(name);
        }

        bool
        Element::match_localname(const char * name) const
        {
            return m_name.match_localname(name);
        }

        std::string
        Element::xmlns_prefix() const
        {
            return std::string(m_name.prefix(), m_name.prefix_size());
        }

        NopVisitor::NopVisitor()
            : VisitorHelper{}
            , m_print_next_value{false}
        {}

        void NopVisitor::visit(const Element  & node)
        {
            if(node.match_fullname("Key"))
            {
                m_print_next_value = true;
            }
            else if(node.match_fullname("LastModified"))
            {
                m_print_next_value = true;
            }
            else
            {
                m_print_next_value = false;
            }
        }

        void NopVisitor::visit(const Data  & node)
        {
            if(m_print_next_value)
            {
                auto v = node.m_node.m_node ;
                m_print_next_value = false;
            }
        }
    } // Node::XML
} // Node
