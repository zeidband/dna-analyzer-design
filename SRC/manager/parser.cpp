//
// Created by a on 7/5/20.
//

#include <iostream>
#include <sstream>
#include "parser.h"


Parser& Parser::operator=(std::string &command) {
    if(!_args.empty()) {
        _args.clear();
    }

    std::stringstream lineInput(command);
    std::string arg;
    while(std::getline(lineInput, arg, ' ')) {
        _args.push_back(arg);
    }
    return *this;
}
