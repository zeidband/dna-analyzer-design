//
// Created by a on 7/5/20.
//

#ifndef SRC_PARSER_H
#define SRC_PARSER_H


#include <string>
#include <vector>

typedef std::vector<std::string> args;


struct Parser {
    Parser& operator=(std::string& command);
    args _args;
};


#endif //SRC_PARSER_H
