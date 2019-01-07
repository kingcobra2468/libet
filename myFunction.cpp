#include <iostream>
#include <string>
#include "/home/erik/Documents/Programming/CPP/Library/myFunction.h"
#include <ctype.h>
#include <forward_list>
#include <list>
#include <string>

std::string methods::lower(std::string String){
    std::string * loweredWord = new std::string; 
    for(int i = 0; i < String.length(); i++){
        if(i == 0){*loweredWord = tolower(String[i]);continue;}
        *loweredWord+=tolower(String[i]);
    };
    return *loweredWord;
    delete loweredWord;
};
std::string methods::upper(std::string String){
    std::string * loweredWord = new std::string; 
    for(int i = 0; i < String.length(); i++){
        if(i == 0){*loweredWord = toupper(String[i]);continue;}
        *loweredWord+=toupper(String[i]);
    };
    return *loweredWord;
    delete loweredWord;
};
char* methods::stringToChar(std::string parseString){ //c_chr()
    int stringLength = parseString.length();
    char* charString = new char[stringLength];
    for(auto i = 0; i < stringLength; i++){
        charString[i]=parseString.at(i);
    }
    return charString;
}
std::string methods::charToString(char * charArray){
    std::string * compiledWord = new std::string;
    for(int i = 0; i < sizeof(charArray); i++){
        if(i == 0){*compiledWord=charArray[i];continue;}
        else{*compiledWord+=charArray[i];}; 
    };
    return *compiledWord;
    delete compiledWord;
};
std::forward_list<char> * methods::removeInString(std::string * inputString, char removeWhat, bool endOfList){
    std::forward_list<char> * filteredList = new std::forward_list<char>;
    if(endOfList){*inputString+="`";};
    filteredList->assign(inputString->begin(), inputString->end());
    filteredList->remove_if([removeWhat](char in){return in == removeWhat ? true : false; });
    return filteredList;
}
std::list<std::string> * methods::splitString(std::string phrase){
    phrase.append(" ");
    std::list<std::string> * splitWords = new std::list<std::string>;
    std::string word;
    for (auto character : phrase){
        if(character != ' '){
            word+=character;
        }
        else{
            splitWords->push_back(word);
            word.clear();
        }
    }
    return splitWords;
}


//template std::list<std::string> * methods::toDS(int argc, char ** argv);