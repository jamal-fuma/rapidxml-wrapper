// C library

// STL
#include <sstream>
#include <iostream>

// Boost
#include <boost/filesystem.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

// RapidXML
#include "rapidxml/rapidxml.hpp"

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

    boost::iostreams::mapped_file region(
        filename,
        boost::iostreams::mapped_file::readonly
    );

    std::cout.write(region.const_data(),region.size());
//   parse_xml(region.const_data(),region.size());

    return EXIT_SUCCESS;
}
