#ifndef __COMMANDLINE_UTILS__
#define __COMMANDLINE_UTILS__

#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <ctype.h>
#include <list>

/**
 * @brief Helper methods for dealing with raw input from command line.
 * 
 * This class contains various utilities that make it easier to work with
 * the command line. Given that the command line is of type char**, these
 * utilities make way for working with this structure.
 * 
 */
namespace et::parsing::commandline
{
    /**
     * @brief Casts the char** command line input array into a new STL datatype.
     * 
     * This method parses the raw char array recieved from the command line and
     * transforms it into a STL container (any that supports push_back operation). This
     * makes it easier to work with the input args.
     * 
     * @tparam datatype The datatype (that supports push_back), in which all
     * the commandline args should be cast to.
     * @param argc Number of command line args.
     * @param argv List of command line args.
     * @return datatype* a pointer to the datatype created which holds the command line
     * args in the new datatype.
     */
    template <typename datatype>
    datatype *to_type(int argc, char **argv)
    {
        datatype *parsed_list = new datatype{};

        for (int i = 1; i < argc; i++)
        {
            std::istringstream iss(argv[i]);
            typename datatype::value_type raw_word;
            iss >> raw_word;
            parsed_list->push_back(raw_word);
        }

        return parsed_list;
    }
};

#endif