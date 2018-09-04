#include <iostream>
#include <string>
#include <forward_list>
#include <list>

class methods {
    private:
    protected:

    public:
        std::string lower(std::string String);
        std::string upper(std::string String);
        char* stringToChar(std::string parseString);
        std::string charToString(char* charArray);
        std::forward_list<char> *removeInString(std::string * inputString, char removeWhat, bool endOfList);
        std::list<std::string> * splitString(std::string phrase);
};