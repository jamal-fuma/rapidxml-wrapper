#ifndef NODE_QUALIFIED_NAME_HPP
#define NODE_QUALIFIED_NAME_HPP

#include <cstddef>

namespace Node
{
    namespace XML
    {
        struct QualifiedName
        {
            QualifiedName();
            QualifiedName(const char * ptr, std::size_t len);

            const char * prefix() const;
            const char * local() const;

            std::size_t prefix_size() const;
            std::size_t local_size() const;
            std::size_t full_size() const;

            bool match_prefix(const char * name,std::size_t len) const;
            bool match_fullname(const char * name) const;
            bool match_localname(const char * name) const;
            bool empty() const;

            const char * m_ptr;
            std::size_t m_full_len;
            std::size_t m_prefix_len;
        };
    } // Node::XML
} // Node

#endif /*  ndef NODE_QUALIFIED_NAME_HPP */
