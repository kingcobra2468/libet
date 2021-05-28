#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <string>
#include <et/string_utils.hpp>

TEST_CASE("Uppercase: 1", "[upper]")
{
    REQUIRE_THAT(et::string_utils::upper("test"), Catch::Matchers::Equals("TEST"));
}