#include "node/xml_s3.hpp"

#if defined(HAVE_CONFIG_H)
    #include "config.h"
#endif

// Boost
#include <boost/filesystem.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

namespace Node
{
    namespace XML
    {
        static constexpr const char * wrong_region = "The authorization header is malformed; the region '";
        static constexpr const size_t wrong_region_sz = std::strlen(wrong_region);

        static constexpr const char * auth_header_malformed = "AuthorizationHeaderMalformed";
        static constexpr const size_t auth_header_malformed_sz = std::strlen(auth_header_malformed);

        block::block(const rapidxml::xml_node<> * v)
            : m_ptr{v->value()}
            , m_len{v->value_size()}
        {}
        block::block(const char * ptr, size_t len)
            : m_ptr{ptr}
            , m_len{len}
        {}

        std::ostream & operator <<(std::ostream & out, const block & rhs)
        {
            out.write(rhs.m_ptr,rhs.m_len);
            return out;
        }

        bool starts_with_wrong_region(const block & rhs)
        {
            static const block wrong_region_block{wrong_region,wrong_region_sz};
            return starts_with(rhs,wrong_region_block);
        }

        bool starts_with_auth_header_malformed(const block & rhs)
        {
            static const block auth_header_malformed_block{auth_header_malformed,auth_header_malformed_sz};
            return starts_with(rhs,auth_header_malformed_block);
        }

        bool starts_with(const block & rhs, const block & lhs)
        {
            size_t prefix_sz = (rhs.m_len > lhs.m_len) ? lhs.m_len : rhs.m_len;
            return (0== memcmp(rhs.m_ptr,lhs.m_ptr,prefix_sz));
        }

        bool load_file(std::string & dest, const std::string & filename)
        {
            if(!boost::filesystem::exists(filename))
            {
                return false;
            }
            boost::iostreams::mapped_file region(
                filename,
                boost::iostreams::mapped_file::readonly
            );
            dest.assign(region.const_data(),region.size());
            return true;
        }

        ListAllMyBucketsResult::ListAllMyBucketsResult()
            : m_bucket_name{}
            ,m_created_at{}
            ,m_owner_name{}
            ,m_owner_id{}
        {}

        ListBucketResult::ListBucketResult()
            : m_bucket_name{}
            , m_key{}
            ,m_last_modified_at{}
            ,m_etag{}
            ,m_size{}
            ,m_owner_name{}
            ,m_owner_id{}
            ,m_auth_failures{}
            ,m_buckets{}
            ,m_nobjects{0}
            ,m_nerrors{0}
            ,m_nbuckets{0}
        {}

        ListBucketResult::ListBucketResult(char * xml)
            : ListBucketResult{}
        {
            try
            {
                // the backing store for the attribute data - element names etc
                rapidxml::xml_document<char> doc;
                doc.parse<
                rapidxml::parse_no_string_terminators
                | rapidxml::parse_trim_whitespace
                | rapidxml::parse_comment_nodes
                | rapidxml::parse_xhtml_entity_translation
                | rapidxml::parse_validate_closing_tags
                >(xml);
                size_t count = 0;
                for(auto root = doc.first_node("ListBucketResult"); root; root = root->next_sibling())
                {
                    if(auto bucket_name = root->first_node("Name"))
                    {
                        for(auto contents = root->first_node("Contents"); contents; contents = contents->next_sibling())
                        {
                            if(auto key = contents->first_node("Key"))
                            {
                                if(auto last_modified_at = contents->first_node("LastModified"))
                                {
                                    if(auto etag = contents->first_node("ETag"))
                                    {
                                        if(auto size = contents->first_node("Size"))
                                        {
                                            if(auto owner = contents->first_node("Owner"))
                                            {
                                                if(auto owner_id = owner->first_node("ID"))
                                                {
                                                    if(auto owner_name = owner->first_node("DisplayName"))
                                                    {
                                                        m_bucket_name.emplace_back(bucket_name);
                                                        m_key.emplace_back(key);
                                                        m_last_modified_at.emplace_back(last_modified_at);
                                                        m_etag.emplace_back(etag);
                                                        m_size.emplace_back(size);
                                                        m_owner_name.emplace_back(owner_name);
                                                        m_owner_id.emplace_back(owner_id);
                                                        ++count;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                m_nobjects = count;
                count = 0;
                for(auto root = doc.first_node("Error"); root; root = root->next_sibling())
                {
                    if(const auto code = root->first_node("Code"))
                    {
                        auto code_block = code;
                        if(starts_with_auth_header_malformed(code_block))
                        {
                            if(const auto message = root->first_node("Message"))
                            {
                                if(const auto region = root->first_node("Region"))
                                {
                                    if(const auto request_id= root->first_node("RequestId"))
                                    {
                                        if(const auto host_id= root->first_node("HostId"))
                                        {
                                            m_auth_failures.m_code.emplace_back(code_block);
                                            m_auth_failures.m_message.emplace_back(message);
                                            m_auth_failures.m_request_id.emplace_back(request_id);
                                            m_auth_failures.m_host_id.emplace_back(host_id);
                                            m_auth_failures.m_region.emplace_back(region);
                                            ++count;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                m_nerrors = count;
                count = 0;
                for(auto root = doc.first_node("ListAllMyBucketsResult"); root; root = root->next_sibling())
                {
                    if(auto owner = root->first_node("Owner"))
                    {
                        if(auto owner_id = owner->first_node("ID"))
                        {
                            if(auto owner_name = owner->first_node("DisplayName"))
                            {
                                if(auto buckets = root->first_node("Buckets"))
                                {
                                    for(auto bucket = buckets->first_node("Bucket"); bucket; bucket = bucket->next_sibling())
                                    {
                                        if(auto bucket_name = bucket->first_node("Name"))
                                        {
                                            if(auto created_at = bucket->first_node("CreationDate"))
                                            {
                                                m_buckets.m_bucket_name.emplace_back(bucket_name);
                                                m_buckets.m_created_at.emplace_back(created_at);
                                                m_buckets.m_owner_name.emplace_back(owner_name);
                                                m_buckets.m_owner_id.emplace_back(owner_id);
                                                ++count;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                m_nbuckets = count;
                count = 0;
            }
            catch(const rapidxml::parse_error & e)
            {
                std::ostringstream ss;
                ss << "Error parsing XML : at character " << (int)(e.where<char>() - &xml[0])
                   << ": " << e.what();
                throw std::runtime_error(ss.str());
            }
        }
    } // Node::XML
} // Node
