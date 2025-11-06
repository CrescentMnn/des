#include "logger.h"
#include <iostream>
#include <string>

bool Logger::verbose = false;

void Logger::setVerbose(bool v){
    verbose = v;
}

void Logger::log(const std::string& msg){
    if(verbose){ std::cout << "[LOG] " << msg << std::endl; }
}
