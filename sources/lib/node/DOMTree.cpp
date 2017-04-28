#include "node/DOMTree.hpp"

#if defined(HAVE_CONFIG_H)
    #include "config.h"
#endif

#include <stdexcept>
#include <sstream>
#include <iostream>
#include <node/XML.hpp>
#include <node/Element.hpp>
namespace Node
{
    namespace XML
    {

        DOMTree::DOMTree()
            : m_buf{{'\0'}}
        , m_doc{}
        , m_decendants{}
        {
        }

        DOMTree::DOMTree(const char * ptr, size_t len)
            : DOMTree{}
        {
            try
            {
                m_buf.resize(len+1);
                std::copy(ptr,ptr+len,&m_buf[0]);
                // the backing store for the attribute data - element names etc
                m_buf.push_back('\0');
                // build the DOM tree
                m_doc.parse<
                rapidxml::parse_no_string_terminators
                | rapidxml::parse_trim_whitespace
                | rapidxml::parse_comment_nodes
                | rapidxml::parse_xhtml_entity_translation
                | rapidxml::parse_validate_closing_tags
                >(&m_buf[0]);
                // traverse DOM tree populating container of decendants
                Node::XML::traverse_with_operation(
                    m_doc.first_node(),
                    [this](rapidxml::xml_node<> * node)
                {
                    m_decendants.emplace_back(this->wrap_node(node));
                });
            }
            catch(const rapidxml::parse_error & e)
            {
                std::ostringstream ss;
                ss << "Error parsing XML : at character " << (int)(e.where<char>() - &m_buf[0])
                   << ": " << e.what();
                throw std::runtime_error(ss.str());
            }
        }

        void
        DOMTree::visit(Visitor & visitor) const
        {
            // visit the node pointers in the proper order of traversal
            for(const auto & xml : m_decendants)
            {
                xml->accept(visitor);
            }
        }

        std::unique_ptr<VisitableBase>
        DOMTree::wrap_node(rapidxml::xml_node<> * node)
        {
            switch(node->type())
            {
            case rapidxml::node_document:
                return std::make_unique<Document>(node);
                break;
            case rapidxml::node_element:
                return std::make_unique<Element>(node);
                break;
            case rapidxml::node_data:
                return std::make_unique<Data>(node);
                break;
            case rapidxml::node_cdata:
                return std::make_unique<CDATA>(node);
                break;
            case rapidxml::node_declaration:
                return std::make_unique<Declaration>(node);
                break;
            case rapidxml::node_comment:
                return std::make_unique<Comment>(node);
                break;
            case rapidxml::node_doctype:
                return std::make_unique<Doctype>(node);
                break;
            case rapidxml::node_pi:
                return std::make_unique<ProcessingIntruction>(node);
                break;
            default:
                break;
            }
            return std::make_unique<Element>(nullptr);
        }
    } // Node::XML
} // Node
