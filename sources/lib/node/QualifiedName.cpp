#if defined(HAVE_CONFIG_H)
#include "config.h"
#endif

#include "node/QualifiedName.hpp"

#include "node/Util.hpp"

Node::XML::QualifiedName::QualifiedName()
	: m_ptr(0)
	, m_full_len(0)
	, m_prefix_len(0) 
{
}

Node::XML::QualifiedName::QualifiedName(const char *ptr, size_t len)
	: m_ptr(ptr)
	, m_full_len(len)
	, m_prefix_len(0)
{
	const char *cptr = Node::Util::find_character(ptr,m_full_len,':');
	if(cptr)
	{
		++cptr;
		m_prefix_len =  static_cast<size_t>(cptr - m_ptr);
	}
}

const char *
Node::XML::QualifiedName::prefix() const
{
	return m_ptr;
}

const char *
Node::XML::QualifiedName::local() const
{
	return m_ptr + prefix_size();
}

size_t Node::XML::QualifiedName::prefix_size() const
{
	return m_prefix_len;
}

size_t Node::XML::QualifiedName::local_size() const
{
	return m_full_len - m_prefix_len;
}

size_t Node::XML::QualifiedName::full_size() const
{
	return m_full_len;
}

bool Node::XML::QualifiedName::match_prefix(const char * name,size_t len) const
{
	return Node::Util::match_string(prefix(),prefix_size(),name,len);
}

bool Node::XML::QualifiedName::match_fullname(const char * name) const
{
	return Node::Util::match_string(prefix(),full_size(),name);
}

bool Node::XML::QualifiedName::match_localname(const char * name) const
{
	return Node::Util::match_string(local(),local_size(), name);
}
