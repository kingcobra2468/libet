#include <et/parsing/commandline.hpp>
#include <catch.hpp>
#include <string>
#include <cstring>
#include <list>

TEST_CASE("Cast raw cmd input", "[to_type]")
{
    SECTION("1")
    {
        char *input[] = {(char *)"a.out", (char *)"this", (char *)"is", (char *)"a", (char *)"test"};
        const std::list<std::string> expected_output = {"this", "is", "a", "test"};
        const std::list<std::string> *actual_output =
            et::parsing::commandline::to_type<std::list<std::string>>(5, input);

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
        char *input[] = {(char *)"name", (char *)"2", (char *)"3", (char *)"4", (char *)"5"};
        const std::list<int> expected_output = {2, 3, 4, 5};
        const std::list<int> *actual_output =
            et::parsing::commandline::to_type<std::list<int>>(5, input);

        auto actual_output_it = actual_output->cbegin();
        auto expected_output_it = expected_output.cbegin();

        while (expected_output_it != expected_output.end())
        {
            REQUIRE((*actual_output_it) == (*expected_output_it));
            ++expected_output_it;
            ++actual_output_it;
        }
    }
    SECTION("3")
    {
        char *input[] = {(char *)"name"};
        const std::list<int> expected_output = {};
        const std::list<int> *actual_output =
            et::parsing::commandline::to_type<std::list<int>>(1, input);

        REQUIRE(expected_output.size() == actual_output->size());
    }
}