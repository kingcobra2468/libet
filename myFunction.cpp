#include <iostream>
#include <string>
#include "myFunction.h"
#include <ctype.h>

std::string methods::lower(std::string String){
    std::string * loweredWord = new std::string; 
    for(int i = 0; i < String.length(); i++){
        if(i == 0){
            *loweredWord = tolower(String[i]);
            continue;
            }
        *loweredWord+=tolower(String[i]);
    };
    return *loweredWord;
    delete loweredWord;
};

std::string methods::upper(std::string String){
    std::string * loweredWord = new std::string; 
    for(int i = 0; i < String.length(); i++){
        if(i == 0){
            *loweredWord = toupper(String[i]);
            continue;
            }
        *loweredWord+=toupper(String[i]);
    };
    return *loweredWord;
    delete loweredWord;
};

char* methods::stringToChar(std::string parseString){
    int stringLength = parseString.length();
    char* charString = new char[stringLength];
    for(auto i = 0; i < stringLength; i++){
        charString[i]=parseString.at(i);
    }
    return charString;
}
std::string methods::charToString(char *charArray){
    std::string * compiledWord = new std::string;
    for(int i = 0; i < sizeof(charArray)/sizeof(char); i++){
        if(i == 0){
            *compiledWord=charArray[i];
            continue;
            }
        else{
            *compiledWord+=charArray[i];
            }; 
    };
    return *compiledWord;
    delete compiledWord;
};


