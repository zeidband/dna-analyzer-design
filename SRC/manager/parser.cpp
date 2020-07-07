//
// Created by a on 7/5/20.
//

#include <iostream>
#include <sstream>
#include "parser.h"


Parser& Parser::operator=(std::string &command) {
    if(!_argsList.empty()) {
        _argsList.clear();
    }

    std::stringstream ss(command);
    std::string arg;
    while(std::getline(ss, arg, ' ')) {
        _argsList.push_back(arg);
    }
    return *this;
}