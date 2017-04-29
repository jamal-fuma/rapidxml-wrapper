#include "node/xml_s3.hpp"
// STL
#include <iostream>

int main(int argc, char * argv[])
{
    std::string xml;
    if(argc < 2)
    {
        std::cout << "File not specified\n";
        return EXIT_FAILURE;
    }
    else
    {
        std::string filename{argv[1]};
        if(!Node::XML::load_file(xml,filename))
        {
            std::cout << "File not found: " << filename << "\n";
            return EXIT_FAILURE;
        }
    }
    Node::XML::ListBucketResult obj{&xml[0]};
    auto count = obj.m_nobjects;
    while(count)
    {
        --count;
        std::cout << obj.m_owner_name.at(count) << " ";
        std::cout << obj.m_owner_id.at(count) << " ";
        std::cout << "https://" << obj.m_bucket_name.at(count) << ".s3.amazonaws.com/" << obj.m_key.at(count) << " ";
        std::cout << obj.m_last_modified_at.at(count) << " ";
        std::cout << obj.m_size.at(count) << " ";
        std::cout << obj.m_etag.at(count) << "\n";
    }
    count = obj.m_nerrors;
    const auto & auth_failures = obj.m_auth_failures;
    while(count)
    {
        --count;
        const auto & msg = auth_failures.m_message.at(count);
        if(Node::XML::starts_with_wrong_region(msg))
        {
            std::cout << "Wrong Region - retry with " << auth_failures.m_region.at(count) << "\n";
            continue;
        }
        std::cout << auth_failures.m_host_id.at(count) << " ";
        std::cout << auth_failures.m_request_id.at(count) << " ";
        std::cout << auth_failures.m_code.at(count) << " ";
        std::cout << msg << " ";
        std::cout << auth_failures.m_region.at(count) << "\n";
    }
    count = obj.m_nbuckets;
    const auto & buckets = obj.m_buckets;
    while(count)
    {
        --count;
        std::cout << buckets.m_owner_name.at(count) << " ";
        std::cout << buckets.m_owner_id.at(count) << " ";
        std::cout << "https://" << buckets.m_bucket_name.at(count) << ".s3.amazonaws.com/" << " ";
        std::cout << buckets.m_created_at.at(count) << "\n";
    }
    return EXIT_SUCCESS;
}
