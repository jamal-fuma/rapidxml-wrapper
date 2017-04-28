#ifndef NODE_TYPE_HPP
#define NODE_TYPE_HPP

#include "rapidxml/rapidxml.hpp"

#include "node/Util.hpp"
#include "node/QualifiedName.hpp"
namespace Node
{
    namespace XML
    {
        template <rapidxml::node_type I>
        struct Type
        {
            typedef rapidxml::xml_node<> value_type;
            typedef value_type & reference_type;
            typedef value_type * pointer_type;

            enum { eValue = I };

            Type()
                : m_node(nullptr)
            {
            }

            ~Type() = default;

            Type(rapidxml::xml_node<> * node)
                : m_node(node)
            {
            }

            Type & operator=(const Type & rhs) = default;
            Type(const Type & rhs) = default;

            bool match_value(const char * value)
            {
                if(!m_node)
                {
                    return false;
                }
                return Node::Util::match_string(
                           m_node->value(), m_node->value_size(),
                           value);
            }

            QualifiedName
            to_qualified_name() const
            {
                if(!m_node)
                {
                    return QualifiedName();
                }
                return QualifiedName(m_node->name(), m_node->name_size());
            }

            std::string value() const
            {
                if(!m_node)
                {
                    return std::string{};
                }
                return std::string{m_node->value(), m_node->value_size()};
            }

            pointer_type m_node;
        };

        //!< A document node. Name and value are empty.
        typedef Type<rapidxml::node_document> DocumentNode;

        //!< An element node. Name contains element name. Value contains text of first data node.
        typedef Type<rapidxml::node_element> ElementNode;

        //!< A data node. Name is empty. Value contains data text.
        typedef Type<rapidxml::node_data> DataNode;

        //!< A CDATA node. Name is empty. Value contains data text.
        typedef Type<rapidxml::node_cdata> CDATA_Node;

        //!< A comment node. Name is empty. Value contains comment text.
        typedef Type<rapidxml::node_comment> CommentNode;

        //!< A declaration node. Name and value are empty. Declaration parameters (version, encoding and standalone) are in node attributes.
        typedef Type<rapidxml::node_declaration> DeclarationNode;

        //!< A DOCTYPE node. Name is empty. Value contains DOCTYPE text.
        typedef Type<rapidxml::node_doctype> DoctypeNode;

        //!< A PI node. Name contains target. Value contains instructions.
        typedef Type<rapidxml::node_pi> ProcessingIntructionNode;
    } // Node::XML
} // Node

#endif /*  ndef NODE_TYPE_HPP */
