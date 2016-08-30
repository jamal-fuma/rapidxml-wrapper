#ifndef NODE_DOM_TREE_HPP
#define NODE_DOM_TREE_HPP

#include "rapidxml/rapidxml.hpp"

#include <memory>
#include <queue>
#include <cstddef>

namespace Node
{
    namespace XML
    {
        struct Visitor;

        struct DOMTree
        {
            // an owning pointer to a value
            typedef std::unique_ptr<VisitableBase>    value_type;

            // a queue of values
            typedef std::queue<value_type>        container_type;

            // a rapidxml parser for utf-8 text
            typedef char                  char_type
            typedef std::vector<char_type>        buffer_type;
            typedef rapidxml::xml_document<char_type> document_type;

            DOMTree();
            DOMTree(const char * data, std::size_t len);

            void visit(Node::XML::Visitor & visitor) const;

            // the backing store for the attribute data - element names etc
            buffer_type m_buf;

            // the memory pool underlying the node structures
            document_type m_doc;

            // the decendants of the root in traversal order
            // wrapped to support the visitor interface
            container_type m_decendants;
        };

    } // Node::XML
} // Node

#endif /*  ndef NODE_DOM_TREE_HPP */
