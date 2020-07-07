//
// Created by a on 7/6/20.
//

#include "new_command_class.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include "list_dna.h"

NewCommandClass::NewCommandClass(Parser *args) {
    //Correctness check the parser
    size_t size = args->_argsList.size();

    if(size < 2)
        throw std::invalid_argument("There are not enough arguments to new command");

    if(size > 3)
        throw std::invalid_argument("There are too much arguments to new command");

    if(!isDna(args->_argsList[1]))
        throw std::invalid_argument("Invalid DNA");

    if(size == 3)
        if(args->_argsList[2][0] != '@')
            throw std::invalid_argument("Should be given @ before the DNA name");

    //the parser is valid!!

    if(size == 2) {
        static size_t numOfSeq = 1;
        std::stringstream name;
        name << "seq" << numOfSeq;
        args->_argsList.push_back(name.str());
    }

    else {
        args->_argsList[2].erase(0,1);
    }
}

bool NewCommandClass::isDna(std::string &dna) {
    return strlen(dna.c_str()) == strspn(dna.c_str(), "ACTG");
}


bool NewCommandClass::run(Parser* input, IWrite* outputPrint) {
    ListDna::printDnaById(outputPrint,ListDna::addDna(input->_argsList[1], input->_argsList[2]));
    return false;
}

