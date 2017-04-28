#include "node/xml_s3.hpp"

#if defined(HAVE_CONFIG_H)
    #include "config.h"
#endif


// RapidXML
#include "rapidxml/rapidxml.hpp"

// Boost


namespace Node
{
    namespace XML
    {
        std::string make_value(const rapidxml::xml_node<> * v)
        {
            struct value
            {
                std::string m_value;
                value(const rapidxml::xml_node<> * v)
                    : m_value{v->value(),v->value_size()}
                {}
                value()
                    : m_value{}
                {}
            };
            value val{v};
            return val.m_value;
        }

        ListBucketResult::
        ListBucketResult()
            : m_objects{0}
            , m_errors{0}
            , m_bucket_name{}
            , m_key{}
            ,m_last_modified_at{}
            ,m_etag{}
            ,m_size{}
            ,m_owner_name{}
            ,m_owner_id{}
            ,m_auth_failures{}
        {}
        ListBucketResult::ListBucketResult(std::string xml)
            :ListBucketResult{}
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
                >(&xml[0]);
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
                                                        m_bucket_name.emplace_back(make_value(bucket_name));
                                                        m_key.emplace_back(make_value(key));
                                                        m_last_modified_at.emplace_back(make_value(last_modified_at));
                                                        m_etag.emplace_back(make_value(etag));
                                                        m_size.emplace_back(make_value(size));
                                                        m_owner_name.emplace_back(make_value(owner_name));
                                                        m_owner_id.emplace_back(make_value(owner_id));
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
                m_objects = count;
                count = 0;
                for(auto root = doc.first_node("Error"); root; root = root->next_sibling())
                {
                    if(auto code = root->first_node("Code"))
                    {
                        if(make_value(code) == "AuthorizationHeaderMalformed")
                        {
                            if(auto message = root->first_node("Message"))
                            {
                                if(auto region = root->first_node("Region"))
                                {
                                    if(auto request_id= root->first_node("RequestId"))
                                    {
                                        if(auto host_id= root->first_node("HostId"))
                                        {
                                            m_auth_failures.m_code.emplace_back(make_value(code));
                                            m_auth_failures.m_message.emplace_back(make_value(message));
                                            m_auth_failures.m_request_id.emplace_back(make_value(request_id));
                                            m_auth_failures.m_host_id.emplace_back(make_value(host_id));
                                            m_auth_failures.m_region.emplace_back(make_value(region));
                                            ++count;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                m_errors = count;
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
