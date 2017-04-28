#if defined(HAVE_CONFIG_H)
    #include "config.h"
#endif

#include <cstring>
#include <algorithm>

#include "node/Util.hpp"

bool
Node::Util::match_string(const char * rhs, std::size_t rhs_len, const char * name)
{
    return Node::Util::match_string(rhs,rhs_len, name,strlen(name));
}

bool
Node::Util::match_string(const char * rhs, std::size_t rhs_len, const char * name, std::size_t name_len)
{
    if(rhs_len != name_len)
    {
        return false;
    }
    return Node::Util::match_string_prefix(rhs,rhs_len,name,name_len);
}

bool
Node::Util::match_string_prefix(const char * rhs, std::size_t rhs_len, const char * name, std::size_t name_len)
{
    return (0 == std::strncmp(name,rhs, std::min(rhs_len,name_len)));
}

const char *
Node::Util::find_character(const char * ptr, std::size_t len, int ch)
{
    return static_cast<const char *>(std::memchr(ptr,ch, len));
}
