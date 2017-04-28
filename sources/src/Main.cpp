#include "node/xml_s3.hpp"

// STL
#include <sstream>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/algorithm/string/predicate.hpp>


int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        std::cout << "File not specified\n";
        return EXIT_FAILURE;
    }
    const char * filename = argv[1];
    if(!boost::filesystem::exists(filename))
    {
        std::ostringstream ss;
        ss << "File not found: " << filename << "\n";
        throw std::logic_error(ss.str());
    }
    std::ostringstream ss;
    {
        boost::iostreams::mapped_file region(
            filename,
            boost::iostreams::mapped_file::readonly
        );
        ss.write(region.const_data(),region.size());
    }
    Node::XML::ListBucketResult obj{ss.str()};
    auto count = obj.m_objects;
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
    count = obj.m_errors;
    while(count)
    {
        --count;
        if(boost::starts_with(obj.m_auth_failures.m_message.at(count),"The authorization header is malformed; the region '"))
        {
            std::cout << "Wrong Region - retry with " << obj.m_auth_failures.m_region.at(count) << "\n";
        }
        else
        {
            std::cout << obj.m_auth_failures.m_host_id.at(count) << " ";
            std::cout << obj.m_auth_failures.m_request_id.at(count) << " ";
            std::cout << obj.m_auth_failures.m_code.at(count) << " ";
            std::cout << obj.m_auth_failures.m_message.at(count) << " ";
            std::cout << obj.m_auth_failures.m_region.at(count) << "\n";
        }
    }
    return EXIT_SUCCESS;
}
