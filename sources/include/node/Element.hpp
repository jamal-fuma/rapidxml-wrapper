#ifndef NODE_ELEMENT_HPP
#define NODE_ELEMENT_HPP

#include "node/VisitableBase.hpp"

namespace Node
{
    namespace XML
    {
        //!< An element node.
        // Name contains element name.
        //Value contains text of first data node.
        struct Element
            : public VisitableBase
        {
            // access a qualified name as component
            ElementNode m_node;
            QualifiedName m_name;

            Element(rapidxml::xml_node<> * node=nullptr);
            virtual ~Element() = default;

            // visitor entry point
            virtual void accept(Visitor & v) const override
            {
                v.visit(*this);
            }

            // non copying string matchers
            bool match_xmlns_prefix(const char * xmlns_prefix,size_t len) const;
            bool match_fullname(const char * name) const;
            bool match_localname(const char * name) const;
            std::string xmlns_prefix() const;
        };
    } // Node::XML
} // Node

#endif /*  ndef NODE_ELEMENT_HPP */
