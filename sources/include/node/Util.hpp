#ifndef NODE_UTIL_HPP
#define NODE_UTIL_HPP

#include <bitset>
#include <cstddef>

namespace Node
{
    namespace Util
    {
        bool match_string(const char * rhs, std::size_t rhs_len, const char * name);
        bool match_string(const char * rhs, std::size_t rhs_len, const char * name, std::size_t name_len);

        bool match_string_prefix(const char * rhs, std::size_t rhs_len, const char * name, std::size_t name_len);
        const char * find_character(const char * ptr, std::size_t len, int ch);

        template < std::size_t N>
        struct RequiredFields
        {
            std::bitset< N > m_fieldset;

            void clear()
            {
                m_fieldset.reset();
            }

            bool valid()
            {
                return m_fieldset.all();
            }

            void set(int n)
            {
                m_fieldset.set(n);
            }
        };
    } // Node::Util
} // Node

#endif /*  ndef NODE_UTIL_HPP */
