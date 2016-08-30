#if defined(HAVE_CONFIG_H)
#include "config.h"
#endif

#include <stack>

#include "node/XML.hpp"
#include "node/Util.hpp"

bool
Node::XML::match_attribute_prefix(rapidxml::xml_attribute<> * attr, const char * name)
{
    return Node::Util::match_string_prefix(
               attr->name(), attr->name_size(),
               name, strlen(name));
}

bool
Node::XML::match_attribute(rapidxml::xml_attribute<> * attr, const char * name)
{
    return Node::Util::match_string(
               attr->name(),attr->name_size(),
               name);
}

void
Node::XML::traverse_with_operation(rapidxml::node<> * parent,
                                   std::function<void(rapidxml::xml_node<> *)> operation)
{
    // iterative equivilant of
    // traverse(parent,operation)
    // {
    //      if(!parent)
    //           return;
    //
    //      operation(parent);
    //      traverse(parent->first_node());
    //      traverse(parent->next_sibling());
    //   }
    if(!parent)
        return;

    for(std::stack<rapidxml::xml_node<> *> order({parent}); !order.empty();)
    {
        rapidxml::xml_node<> * node = order.top();
        order.pop();

        // wrap current node for later usage
        operation(node);

        // leafs end the recursion
        if(!node->first_node())
        {
            // climb until we have a sibling or run out of ancestors
            while(!node->next_sibling() && node != parent)
                node = node->parent();

            // visit sibling
            if(node->next_sibling())
                order.emplace(node->next_sibling());

            continue;
        }

        // internal nodes extend the recursion
        // as we need to visit decendents of current sibling
        order.emplace(node->first_node());
    }
}

