#ifndef NODE_XML_HPP
#define NODE_XML_HPP

#include <functional>

#include "rapidxml/rapidxml.hpp"
namespace Node
{
    namespace XML
    {
        using attribute_ptr_t = rapidxml::xml_attribute<> * ;
        bool match_attribute(attribute_ptr_t attr, const char * name);
        bool match_attribute_prefix(rapidxml::xml_attribute<> * attr, const char * name);

        void traverse_with_operation(rapidxml::xml_node<> * parent,
                                     std::function<void(rapidxml::xml_node<> *)> operation);

    } // Node::XML
} // Node

#endif /*  ndef NODE_XML_HPP */
