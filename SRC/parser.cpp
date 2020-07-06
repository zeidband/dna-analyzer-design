//
// Created by a on 7/5/20.
//

#include <iostream>
#include <sstream>
#include "parser.h"

Parser::Parser(std::string& command) {
    std::stringstream ss(command);
    std::string arg;
    while(std::getline(ss, arg, ' ')) {
        _argsList.push_back(arg);
    }
}
