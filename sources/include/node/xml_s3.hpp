#ifndef NODE_XML_S3_HPP
#define NODE_XML_S3_HPP

#include <vector>
#include <iosfwd>
#include <string>

#include <boost/core/noncopyable.hpp>

// RapidXML
#include "rapidxml/rapidxml.hpp"


namespace Node
{
    namespace XML
    {
        struct block
        {
            const char * m_ptr;
            size_t m_len;
            block(const char * ptr=nullptr,size_t len=0UL);
            block(const rapidxml::xml_node<> * v);
        };

        std::ostream & operator <<(std::ostream & out, const block & rhs);
        bool starts_with_auth_header_malformed(const block & rhs);
        bool starts_with_wrong_region(const block & rhs);
        bool starts_with(const block & rhs, const block & lhs);
        bool load_file(std::string & dest, const std::string & filename);

        struct AuthorizationHeaderMalformed
            : private boost::noncopyable
        {
            std::vector<block> m_code;
            std::vector<block> m_message;
            std::vector<block> m_request_id;
            std::vector<block> m_host_id;
            std::vector<block> m_region;

            AuthorizationHeaderMalformed() = default;
        };

        struct ListBucketResult
            : private boost::noncopyable
        {
            size_t m_objects;
            size_t m_errors;
            std::vector<block> m_bucket_name;
            std::vector<block> m_key;
            std::vector<block> m_last_modified_at;
            std::vector<block> m_etag;
            std::vector<block> m_size;
            std::vector<block> m_owner_name;
            std::vector<block> m_owner_id;
            AuthorizationHeaderMalformed m_auth_failures;

            ListBucketResult();
            explicit ListBucketResult(char * xml);
        };

    } // Node::XML
} // Node

#endif /*  ndef NODE_XML_S3_HPP */
