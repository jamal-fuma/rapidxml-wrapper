#if defined(HAVE_CONFIG_H)
    #include "config.h"
#endif

#include "TestHelper.hpp"
#include "node/Type.hpp"

struct FixtureData
    : Fuma::Test::Fixture
{

};

BOOST_FIXTURE_TEST_SUITE(Type, FixtureData)

BOOST_AUTO_TEST_CASE(should_provide_an_empty_qualifed_name)
{
    try
    {
        Node::XML::ElementNode element;
        Node::XML::QualifiedName name(element.to_qualified_name());
        BOOST_REQUIRE(name.empty());
        BOOST_REQUIRE(!name.prefix());
        BOOST_REQUIRE(!name.local());
        BOOST_REQUIRE_EQUAL(0,name.prefix_size());
        BOOST_REQUIRE_EQUAL(0,name.local_size());
        BOOST_REQUIRE_EQUAL(0,name.full_size());
    }
    catch(const std::runtime_error & err)
    {
        BOOST_FAIL("should_provide_an_empty_qualifed_name_successfully");
    }
    catch(const std::logic_error & err)
    {
        BOOST_FAIL("should_provide_an_empty_qualifed_name_successfully");
    }
}

BOOST_AUTO_TEST_SUITE_END()
