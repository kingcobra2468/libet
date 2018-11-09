#include <sqlite3.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <deque>
#include <vector>

class sqlite3Lib{
    private:
        std::deque<std::vector<std::string>> tempReturn;
    public:
        
        static int callback(
            void *NotUsed, 
            int recordsNum, 
            char **recordFieldData, 
            char **recordFieldName
            );
        std::deque<std::vector<std::string>> returnRecords(
            sqlite3 * sqlite3Obj,
            std::string table, 
            std::initializer_list<std::string> pullFields
            );
        std::deque<std::vector<std::string>> rawSQLReturn(
            sqlite3 * sqlite3Obj,
            std::string command
            );
        void rawSQL(
            sqlite3 * sqlite3Obj,
            std::string command
            );
        
};