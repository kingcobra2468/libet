#include <sqlite3.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include "sqlite3Lib.h"
#include <sstream> //std::stringstream

int sqlite3Lib::callback( //CREATE FRIEND
    void *NotUsed, 
    int recordsNum, 
    char **recordFieldData, 
    char **recordFieldName
    ){
    sqlite3Lib* obj = (sqlite3Lib*) NotUsed;
	int i;
    std::vector<std::string> temp;// = new std::vector<std::string>; 
	for(i=0; i<recordsNum; i++)
	{
		//std::cout<<recordFieldName[i]<<" = " << (recordFieldData[i] ? recordFieldData[i] : "NULL")<<"\n";
        temp.push_back(recordFieldData[i]);   
	}
    obj->tempReturn.push_back(temp);
    temp.clear();
	return 0; 
};

std::deque<std::vector<std::string>> sqlite3Lib::returnRecords(
    sqlite3 * sqlite3Obj,
    std::string table, 
    std::initializer_list<std::string> pullFields
    ){
        std::string fields;
        int * tempInt = new int(1);
        for(auto x: pullFields){
            (*tempInt != pullFields.size()) ? fields.append(x.append(",")) : fields.append(x);
            *tempInt +=1;
        };
    char str[100];
    sprintf(str, "SELECT %s FROM %s", fields.c_str(), table.c_str());
    int rc;
    rc = sqlite3_exec(sqlite3Obj, str, callback, (void*) this, NULL);
    if( rc )
	{
		std::cout<<"Can't open database: "<<sqlite3_errmsg(sqlite3Obj)<<"\n";
	} 
	else
	{
		std::cout<<"Open database successfully\n\n";
    }
    return tempReturn;
};

std::deque<std::vector<std::string>> sqlite3Lib::rawSQLReturn(sqlite3 * sqlite3Obj,std::string command){
    sqlite3_exec(sqlite3Obj, command.c_str(), callback, (void*) this, NULL);
    return tempReturn;
}

void sqlite3Lib::rawSQL(
    sqlite3 * sqlite3Obj,
    std::string command
    ){
    sqlite3_exec(sqlite3Obj, command.c_str(), callback, NULL, NULL);
}

