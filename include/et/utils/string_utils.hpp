#ifndef __STRING_UTILS__
#define __STRING_UTILS__

#include <string>
#include <forward_list>
#include <list>

namespace et::utils::string
{

    std::string lower(const std::string);
    std::string upper(const std::string);
    char *dump_char_arr(const std::string);
    std::string parse_char_arr(const char *);
    std::forward_list<char> *remove_symbol(std::string &, const char,
                                           bool, const char = '$');
    std::list<std::string> *split_string(const std::string);
};

#endif