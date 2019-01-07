#include <iostream>
#include <string>
#include <forward_list>
#include <list>
#include <string>
#include <sstream>
#include <typeinfo>

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

        template <typename datatype> datatype * toDS(int argc, char ** argv){
            datatype * tempPtr = new datatype;
            for(int i = 1; i < argc; i++){
                std::istringstream iss(argv[i]);
                typename datatype::value_type unknownType;
                iss >> unknownType;
                tempPtr->push_back(unknownType);
            }
        return tempPtr;
        }
};