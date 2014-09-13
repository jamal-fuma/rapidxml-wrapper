#ifndef NODE_UTIL_HPP
#define NODE_UTIL_HPP

#include <cstddef>

namespace Node
{
	namespace Util
	{
		bool match_string(const char *rhs, std::size_t rhs_len, const char * name);
		bool match_string(const char *rhs, std::size_t rhs_len, const char * name, std::size_t name_len);

		bool match_string_prefix(const char *rhs, std::size_t rhs_len, const char * name, std::size_t name_len);
		const char * find_character(const char *ptr, std::size_t len, int ch);
	} // Node::Util
} // Node

#endif /*  ndef NODE_UTIL_HPP */
