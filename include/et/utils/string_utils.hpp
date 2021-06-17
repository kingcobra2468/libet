#ifndef __STRING_UTILS__
#define __STRING_UTILS__

#include <string>
#include <forward_list>
#include <list>

/**
 * @brief Various helper methods for working with strings.
 * 
 * This class contains various string related helper methods that
 * make it easier to work with both C and C++ strings and supplement
 * some basic string operations that are not present with STL strings.
 * 
 */
namespace et::utils::string
{
    /**
     * @brief Transforms a string into lowercase.
     * 
     * @param input_str Input string to be made lowercase.
     * @return std::string the resulting lowercase string. 
     */
    std::string lower(const std::string input_str);

    /**
     * @brief Transforms a string into uppercase.
     * 
     * @param input_str Input string to be made uppercase.
     * @return std::string the resulting uppercase string.
     */
    std::string upper(const std::string input_str);

    /**
     * @brief Casts a STL string into a C-style char* string.
     * 
     * @param input_str STL string to be casted.
     * @return char* the resulting char* C-string.
     */
    char *dump_char_arr(const std::string input_str);

    /**
     * @brief Casts a C-style char* string into a STL string.
     * 
     * @param input_str C-style string to be casted into an STL string.
     * @return std::string the resulting STL string.
     */
    std::string parse_char_arr(const char *input_str);

    /**
     * @brief Removes a token from a string.
     *  
     * Removes a symbol from a string and creates a singly linked char list of 
     * the resulting string.
     * 
     * @param input_str Input string to be parsed.
     * @param symbol Symbol to be removed in the string.
     * @param mark_end Flag on whether to add a token to the end of the string
     * once the string has been parsed. 
     * @param mark_symbol The token to be added to the end of the string if mark_end is set to true.
     * By defualt the the token is '$'.
     * @return std::forward_list<char>* the singly linked char list of the resulting string.
     */
    std::forward_list<char> *remove_symbol(std::string &input_str, const char symbol,
                                           bool mark_end, const char mark_symbol = '$');

    /**
     * @brief Splits a string by the space delimiter.
     * 
     * @param input_str Input string to be split.
     * @return std::list<std::string>* a pointer to a list containing the words that resulted
     * from the split.
     */
    std::list<std::string> *split_string(const std::string input_str);
};

#endif