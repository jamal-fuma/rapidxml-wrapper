#ifndef NODE_XML_S3_HPP
#define NODE_XML_S3_HPP

#include <string>
#include <vector>

namespace Node
{
    namespace XML
    {
        struct AuthorizationHeaderMalformed
        {
            std::vector<std::string> m_code;
            std::vector<std::string> m_message;
            std::vector<std::string> m_request_id;
            std::vector<std::string> m_host_id;
            std::vector<std::string> m_region;

            AuthorizationHeaderMalformed() = default;
        };

        struct ListBucketResult
        {
            size_t m_objects;
            size_t m_errors;
            std::vector<std::string> m_bucket_name;
            std::vector<std::string> m_key;
            std::vector<std::string> m_last_modified_at;
            std::vector<std::string> m_etag;
            std::vector<std::string> m_size;
            std::vector<std::string> m_owner_name;
            std::vector<std::string> m_owner_id;
            AuthorizationHeaderMalformed m_auth_failures;

            ListBucketResult();
            explicit ListBucketResult(std::string xml);
        };

    } // Node::XML
} // Node

#endif /*  ndef NODE_XML_S3_HPP */
