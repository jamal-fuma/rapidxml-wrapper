#if defined(HAVE_CONFIG_H)
    #include "config.h"
#endif

#include "node/QualifiedName.hpp"

#include "node/Util.hpp"
namespace Node
{
    namespace XML
    {


        QualifiedName::QualifiedName()
            : m_ptr(0)
            , m_full_len(0)
            , m_prefix_len(0)
        {
        }

        QualifiedName::QualifiedName(const char * ptr, size_t len)
            : m_ptr(ptr)
            , m_full_len(len)
            , m_prefix_len(0)
        {
            if(m_ptr)
            {
                const char * cptr = Node::Util::find_character(m_ptr,m_full_len,':');
                if(cptr)
                {
                    m_prefix_len =  static_cast<size_t>(cptr - m_ptr);
                }
            }
        }

        const char *
        QualifiedName::prefix() const
        {
            return m_ptr;
        }

        const char *
        QualifiedName::local() const
        {
            if(!m_ptr)
            {
                return m_ptr;
            }
            return m_ptr + (prefix_size()+1);
        }

        size_t QualifiedName::prefix_size() const
        {
            return m_prefix_len;
        }

        size_t QualifiedName::local_size() const
        {
            if(!m_prefix_len)
            {
                return m_full_len;
            }
            return m_full_len - (m_prefix_len+1);
        }

        size_t QualifiedName::full_size() const
        {
            return m_full_len;
        }

        bool QualifiedName::match_prefix(const char * name,size_t len) const
        {
            if(!m_ptr)
            {
                return false;
            }
            return Node::Util::match_string(prefix(),prefix_size(),name,len);
        }

        bool QualifiedName::match_fullname(const char * name) const
        {
            if(!m_ptr)
            {
                return false;
            }
            return Node::Util::match_string(prefix(),full_size(),name);
        }

        bool QualifiedName::match_localname(const char * name) const
        {
            if(!m_ptr)
            {
                return false;
            }
            return Node::Util::match_string(local(),local_size(), name);
        }

        bool QualifiedName::empty() const
        {
            return (!m_ptr || !m_full_len);
        }
    } // Node::XML
} // Node
