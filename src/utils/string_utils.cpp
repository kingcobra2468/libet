#include <et/utils/string_utils.hpp>

namespace et::utils::string
{

    std::string lower(const std::string input_str)
    {
        std::string lowered_string{""};

        for (std::size_t i = 0; i < input_str.length(); i++)
            lowered_string += tolower(input_str[i]);

        return lowered_string;
    };

    std::string upper(const std::string input_str)
    {
        std::string uppered_string{""};

        for (std::size_t i = 0; i < input_str.length(); i++)
            uppered_string += toupper(input_str[i]);

        return uppered_string;
    };

    char *dump_char_arr(const std::string input_str)
    {
        int str_length = input_str.length();
        char *char_arr = new char[str_length + 1];
        char_arr[str_length] = '\0'; // set the terminator for the cstring

        for (auto i = 0; i < str_length; i++)
            char_arr[i] = input_str.at(i);

        return char_arr;
    }

    std::string parse_char_arr(const char *input_str)
    {
        std::string compiled_str{""};

        for (std::size_t i = 0; i < sizeof(input_str) - 1; i++)
            compiled_str += input_str[i];

        return compiled_str;
    };

    std::forward_list<char> *remove_symbol(std::string &input_str, const char symbol,
                                           bool mark_end, const char mark_symbol)
    {
        std::forward_list<char> *filtered_list = new std::forward_list<char>{};

        if (mark_end)
            input_str += mark_symbol;

        filtered_list->assign(input_str.begin(), input_str.end());
        filtered_list->remove_if([symbol](char in)
                                 { return in == symbol; });

        return filtered_list;
    }

    std::list<std::string> *split_string(const std::string input_str)
    {
        std::list<std::string> *word_list = new std::list<std::string>;
        std::string word;

        for (auto character : input_str)
        {
            if (character != ' ')
                word += character;
            else
            {
                word_list->push_back(word);
                word.clear();
            }
        }

        if (word.length()) // only push a word if one exists
        {
            word_list->push_back(word);
            word.clear();
        }

        return word_list;
    }
}