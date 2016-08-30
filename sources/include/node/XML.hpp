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

        void traverse_with_operation(rapidxml::node<> * parent,
                                     std::function<void(rapidxml::xml_node<> *)> operation);

    } // Node::XML
} // Node

#endif /*  ndef NODE_XML_HPP */


#include <functional> // std
#include <stack>

//#include "node/Visitor.hpp"

void parse_xml(const char * data, size_t len, Visitor & visitor);
{
	try
	{
		DOMTree doc(data,len);
		doc.visit(visitor);
	}
	catch(const std::runtime_error & e)
	{
		std::cout << e.what() << "\n";
	}
}

void visit(Visitor & visitor) const
{
	// visit the node pointers in the proper order of traversal
	for(const auto & xml : m_decendents)
	{
		xml->accept(visitor)
	}
}

std::unique_ptr<VisitableBase>
wrap_node(rapidxml::xml_node<> * node)
{
	switch(node->type())
	{
		case rapidxml::node_document:
			return std::unique_ptr<VisitableBase>(new Document(node));
		case rapidxml::node_element:
			return std::unique_ptr<VisitableBase>(new Element(node));
		case rapidxml::node_data:
			return std::unique_ptr<VisitableBase>(new Data(node));
		case rapidxml::node_cdata:
			return std::unique_ptr<VisitableBase>(new CDATA(node));
		case rapidxml::node_declaration:
			return std::unique_ptr<VisitableBase>(new Declaration(node));
		case rapidxml::node_comment:
			return std::unique_ptr<VisitableBase>(new Comment(node));
		case rapidxml::node_doctype:
			return std::unique_ptr<VisitableBase>(new Doctype(node));
		case rapidxml::node_pi:
			return std::unique_ptr<VisitableBase>(new ProcessingIntruction(node));
		default:
			break;
	}

	return nullptr;
}

