#include <et/string_utils.hpp>

namespace et::string_utils {

std::string lower(std::string String)
{
    std::string *loweredWord = new std::string;
    for (std::size_t i = 0; i < String.length(); i++)
    {
        if (i == 0)
        {
            *loweredWord = tolower(String[i]);
            continue;
        }
        *loweredWord += tolower(String[i]);
    };
    return *loweredWord;
    delete loweredWord;
};

std::string upper(std::string String)
{
    std::string *loweredWord = new std::string;
    for (std::size_t i = 0; i < String.length(); i++)
    {
        if (i == 0)
        {
            *loweredWord = toupper(String[i]);
            continue;
        }
        *loweredWord += toupper(String[i]);
    };
    return *loweredWord;
    delete loweredWord;
};

char *dump_char_arr(std::string parseString)
{
    int stringLength = parseString.length();
    char *charString = new char[stringLength];
    
    for (auto i = 0; i < stringLength; i++)
    {
        charString[i] = parseString.at(i);
    }
    return charString;
}

std::string parse_char_arr(char *charArray)
{
    std::string *compiledWord = new std::string;
    for (std::size_t i = 0; i < sizeof(charArray); i++)
    {
        if (i == 0)
        {
            *compiledWord = charArray[i];
            continue;
        }
        else
        {
            *compiledWord += charArray[i];
        };
    };
    return *compiledWord;
    delete compiledWord;
};

std::forward_list<char> *remove_phrase(std::string *inputString, char removeWhat, bool endOfList)
{
    std::forward_list<char> *filteredList = new std::forward_list<char>;
    if (endOfList)
    {
        *inputString += "`";
    };
    filteredList->assign(inputString->begin(), inputString->end());
    filteredList->remove_if([removeWhat](char in)
                            { return in == removeWhat ? true : false; });
    return filteredList;
}

std::list<std::string> *split_string(std::string phrase)
{
    phrase.append(" ");
    std::list<std::string> *splitWords = new std::list<std::string>;
    std::string word;
    for (auto character : phrase)
    {
        if (character != ' ')
        {
            word += character;
        }
        else
        {
            splitWords->push_back(word);
            word.clear();
        }
    }
    return splitWords;
}

template <typename datatype>
datatype *toDS(int argc, char **argv)
{
    datatype *tempPtr = new datatype;
    for (int i = 1; i < argc; i++)
    {
        std::istringstream iss(argv[i]);
        typename datatype::value_type unknownType;
        iss >> unknownType;
        tempPtr->push_back(unknownType);
    }
    return tempPtr;
}
}