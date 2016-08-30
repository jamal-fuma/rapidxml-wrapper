#ifndef NODE_TEST_HELPER_HPP
#define NODE_TEST_HELPER_HPP

// C library
#include <assert.h>

// STL
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>

// Boost
#include <boost/test/unit_test.hpp>
#include <boost/test/mock_object.hpp>

#include <boost/filesystem.hpp>
#include <boost/iostreams/device/mapped_file.hpp>
#include <boost/lexical_cast.hpp>

namespace Node
{
    namespace Test
    {
        struct Fixture
        {
            public:
                // setup
                Fixture()
                {
                    // setup fixture data members
                }

                // teardown
                ~Fixture() {}

                std::string
                fixture_datafile(const std::string & filename)
                {
                    if(!boost::filesystem::exists(filename.c_str()))
                    {
                        std::ostringstream ss;
                        ss << "File not found: " << filename << "\n";
                        throw std::logic_error(ss.str());
                    }

                    boost::iostreams::mapped_file region(
                        filename,
                        boost::iostreams::mapped_file::readonly
                    );

                    return std::string(region.const_data(),region.size());
                }

                // public data the testcases can use
        };
    } // Node::Test namespace
} // Node namespace

#endif /* ndef NODE_TEST_HELPER_HPP */
