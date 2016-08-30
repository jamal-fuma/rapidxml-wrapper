#if defined(HAVE_CONFIG_H)
#include "config.h"
#endif

#include <stdexcept>
#include <sstream>

#include "node/DOMTree.hpp"

Node::XML::DOMTree::DOMTree()
    : m_buf('\0',1)
{
    m_buf.push_back('\0');
}

Node::XML::DOMTree::DOMTree(const char * ptr, size_t len)
    : m_buf(data,data+len)
{
    try
    {
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
            [&](rapidxml::xml_node<> * node)
        {
 //           std::cout << "Node PTR: " << static_cast<std::uintptr_t>(node) << "\n";
            // std::unique_ptr wrapped_node = DOMTree::wrap_node(node);
            // if(wrapped_node)
            // m_decendants->push_back(std::move(wrapped_node));
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

// void
// Node::XML::DOMTree::visit(Node::XML::Visitor & visitor) const
// {
//    // visit the node pointers in the proper order of traversal
//    for(const auto & xml : m_decendents)
//    {
//        xml->accept(visitor)
//    }
// }
