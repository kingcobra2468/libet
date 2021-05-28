#ifndef __STRING_UTILS__
#define __STRING_UTILS__

#include <iostream>
#include <string>
#include <forward_list>
#include <list>
#include <string>
#include <sstream>
#include <typeinfo>
#include <ctype.h>

namespace et::string_utils
{

std::string lower(std::string);
std::string upper(std::string);
char* dump_char_arr(std::string);
std::string parse_char_arr(char*);
std::forward_list<char>* remove_phrase(std::string*, char, bool);
std::list<std::string>* split_string(std::string phrase);

template <typename datatype>
datatype *toDS(int argc, char **argv);
};

#endif