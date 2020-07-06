//
// Created by a on 7/5/20.
//

#ifndef SRC_PARSER_H
#define SRC_PARSER_H


#include <string>
#include <vector>

typedef std::vector<std::string> args;


struct Parser {

    Parser(std::string& command);

protected:
    args _argsList;
};


#endif //SRC_PARSER_H
