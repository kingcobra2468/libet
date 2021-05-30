#include <et/utils/string_utils.hpp>
#include <catch.hpp>
#include <string>
#include <cstring>
#include <list>

TEST_CASE("Upper string", "[upper]")
{
    SECTION("1")
    {
        const std::string expected_output{"TEST"};
        const std::string actual_output = et::utils::string::upper("test");

        REQUIRE_THAT(actual_output, Catch::Matchers::Equals(expected_output));
    }
    SECTION("2")
    {
        const std::string expected_output{"TE124%^*$E"};
        const std::string actual_output = et::utils::string::upper("te124%^*$E");

        REQUIRE_THAT(actual_output, Catch::Matchers::Equals(expected_output));
    }
}

TEST_CASE("Lower string", "[lower]")
{
    SECTION("1")
    {
        const std::string expected_output{"test"};
        const std::string actual_output = et::utils::string::lower("TEST");

        REQUIRE_THAT(actual_output, Catch::Matchers::Equals(expected_output));
    }
    SECTION("2")
    {
        const std::string expected_output{"!@$$"};
        const std::string actual_output = et::utils::string::lower("!@$$");

        REQUIRE_THAT(actual_output, Catch::Matchers::Equals(expected_output));
    }
}

TEST_CASE("Dump char array", "[dump_char_arr]")
{
    SECTION("1")
    {
        const char experted_output[] = "testing";
        const char *actual_output = et::utils::string::dump_char_arr("testing");

        REQUIRE(!strcmp((char *)&experted_output, actual_output));

        delete actual_output;
    }
    SECTION("2")
    {
        const char experted_output[] = "Testinga";
        const char *actual_output = et::utils::string::dump_char_arr("testing");

        REQUIRE_FALSE(!strcmp((char *)&experted_output, actual_output));
        delete actual_output;
    }
}

TEST_CASE("Parse char array", "[parse_char_arr]")
{
    SECTION("1")
    {
        const char input[] = "testing";
        const std::string expected_output = std::string{input};
        const std::string actual_output = et::utils::string::parse_char_arr((char *)&input);

        REQUIRE_THAT(actual_output, Catch::Matchers::Equals(expected_output));
    }
}

TEST_CASE("Remove Symbol", "[remove_symbol]")
{
    SECTION("1")
    {
        std::string input{"testing"};
        std::forward_list<char> expected_output = {'e', 's', 'i', 'n', 'g'};
        std::forward_list<char> *actual_output = et::utils::string::remove_symbol(input, 't', false);

        auto actual_output_it = actual_output->cbegin();
        auto expected_output_it = expected_output.cbegin();

        while (expected_output_it != expected_output.end())
        {
            REQUIRE(*actual_output_it == *expected_output_it);
            ++expected_output_it;
            ++actual_output_it;
        }

        delete actual_output;
    }
    SECTION("2")
    {
        std::string input{"testing"};
        std::forward_list<char> expected_output = {'t', 'e', 's', 't', 'i', 'n', 'g'};
        std::forward_list<char> *actual_output = et::utils::string::remove_symbol(input, '$', false);

        auto actual_output_it = actual_output->cbegin();
        auto expected_output_it = expected_output.cbegin();

        while (expected_output_it != expected_output.end())
        {
            REQUIRE(*actual_output_it == *expected_output_it);
            ++expected_output_it;
            ++actual_output_it;
        }

        delete actual_output;
    }
    SECTION("3")
    {
        std::string input{"testing"};
        std::forward_list<char> expected_output = {'t', 's', 't', 'i', 'n', 'g'};
        std::forward_list<char> *actual_output = et::utils::string::remove_symbol(input, 'e', true);

        REQUIRE_THAT(input, Catch::Matchers::Equals("testing$"));

        auto actual_output_it = actual_output->cbegin();
        auto expected_output_it = expected_output.cbegin();

        while (expected_output_it != expected_output.end())
        {
            REQUIRE(*actual_output_it == *expected_output_it);
            ++expected_output_it;
            ++actual_output_it;
        }

        delete actual_output;
    }
    SECTION("4")
    {
        std::string input{"testing"};
        std::forward_list<char> expected_output = {'t', 's', 't', 'i', 'n', 'g'};
        std::forward_list<char> *actual_output = et::utils::string::remove_symbol(input, 'e', true, '`');

        REQUIRE_THAT(input, Catch::Matchers::Equals("testing`"));

        delete actual_output;
    }
}

TEST_CASE("Split string", "[split_string]")
{
    SECTION("1")
    {
        std::string input{"this is a test"};
        const std::list<std::string> expected_output = {"this", "is", "a", "test"};
        const std::list<std::string> *actual_output = et::utils::string::split_string(input);

        auto actual_output_it = actual_output->cbegin();
        auto expected_output_it = expected_output.cbegin();

        while (expected_output_it != expected_output.end())
        {
            REQUIRE_THAT(*actual_output_it, Catch::Matchers::Equals(*expected_output_it));
            ++expected_output_it;
            ++actual_output_it;
        }
    }
    SECTION("2")
    {
        std::string input{"this"};
        const std::list<std::string> expected_output = {"this"};
        const std::list<std::string> *actual_output = et::utils::string::split_string(input);

        auto actual_output_it = actual_output->cbegin();
        auto expected_output_it = expected_output.cbegin();

        while (expected_output_it != expected_output.end())
        {
            REQUIRE_THAT(*actual_output_it, Catch::Matchers::Equals(*expected_output_it));
            ++expected_output_it;
            ++actual_output_it;
        }
    }
    SECTION("3")
    {
        std::string input{""};
        const std::list<std::string> *actual_output = et::utils::string::split_string(input);

        REQUIRE(actual_output->size() == 0);
    }
}