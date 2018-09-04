#include <iostream>
#include <string>
#include "myFunction.h"

int main(){
    int test[2]={1,2};
    methods * instance;
    instance = new methods();
    std::cout << instance->lower("THIS IS A TEST") << std::endl;
    std::cout << instance->upper("THIS IS A TEST") << std::endl;
    char * x=instance->stringToChar("THIS IS A TEST");
    std::cout << x[1] << std::endl;
    //std::cout << instance->charToString("THIS IS A TEST") << std::endl;
    for (auto vtest: x){
        std::cout << vtest << std::endl;
    }
    return 0;

}

