#if defined(HAVE_CONFIG_H)
    #include "config.h"
#endif

#include "TestHelper.hpp"
#include "node/QualifiedName.hpp"

struct FixtureData
    : Fuma::Test::Fixture
{

};

BOOST_FIXTURE_TEST_SUITE(QualifiedName, FixtureData)

BOOST_AUTO_TEST_CASE(should_default_construct)
{
    try
    {
        Node::XML::QualifiedName name;
        BOOST_REQUIRE(name.empty());
        BOOST_REQUIRE(!name.prefix());
        BOOST_REQUIRE(!name.local());
        BOOST_REQUIRE_EQUAL(0,name.prefix_size());
        BOOST_REQUIRE_EQUAL(0,name.local_size());
        BOOST_REQUIRE_EQUAL(0,name.full_size());
    }
    catch(const std::runtime_error & err)
    {
        BOOST_FAIL("should_default_construct_successfully");
    }
    catch(const std::logic_error & err)
    {
        BOOST_FAIL("should_default_construct_successfully");
    }
}

BOOST_AUTO_TEST_CASE(should_split_qualified_names)
{
    try
    {
        char buffer[] = "pfx:test";
        Node::XML::QualifiedName name(&buffer[0],std::strlen(buffer));
        BOOST_REQUIRE(!name.empty());
        BOOST_REQUIRE_EQUAL(8,name.full_size());
        BOOST_REQUIRE_EQUAL("pfx",std::string(name.prefix(), name.prefix_size()));
        BOOST_REQUIRE_EQUAL(3,name.prefix_size());
        BOOST_REQUIRE_EQUAL("test",std::string(name.local()));
        BOOST_REQUIRE_EQUAL(4,name.local_size());
    }
    catch(const std::runtime_error & err)
    {
        BOOST_FAIL("should_default_construct_successfully");
    }
    catch(const std::logic_error & err)
    {
        BOOST_FAIL("should_default_construct_successfully");
    }
}

BOOST_AUTO_TEST_SUITE_END()
