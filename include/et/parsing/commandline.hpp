#ifndef __COMMANDLINE_UTILS__
#define __COMMANDLINE_UTILS__

#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <ctype.h>

namespace et::parsing::commandline
{
    template <typename datatype>
    datatype *to_type(int argc, char **argv);
};

#endif