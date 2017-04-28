#if defined(HAVE_CONFIG_H)
    #include "config.h"
#endif

#include "TestHelper.hpp"
#include "node/Util.hpp"

struct FixtureData
    : Fuma::Test::Fixture
{

};

BOOST_FIXTURE_TEST_SUITE(RequiredFields, FixtureData)

BOOST_AUTO_TEST_CASE(should_default_construct)
{
    try
    {
        Node::Util::RequiredFields<1> fields;
        BOOST_REQUIRE(!fields.valid());
        fields.set(0);
        BOOST_REQUIRE(fields.valid());
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
