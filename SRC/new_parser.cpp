//
// Created by a on 7/6/20.
//

#include "new_parser.h"
#include <iostream>

NewParser::NewParser(std::string& command) : Parser(command) {
    if(_argsList.size() > 3) {
        std::invalid_argument("Too many arguments to new");
    }

    if(_argsList.size() < 2) {
        std::invalid_argument("Not enough arguments to new");
    }
}
