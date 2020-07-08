//
// Created by a on 7/6/20.
//

#include "new_command.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include "../../dna/container_dna.h"

New::New(Parser& args) {
    //Correctness check the parser
    isCorrectArgs(args);

    addName(args);
}


bool New::isDna(std::string &dna) {
    return strlen(dna.c_str()) == strspn(dna.c_str(), "ACTG");
}


bool New::run(Parser* input, IWrite* outputPrint) {
    ContainerDna::printDnaById(outputPrint, ContainerDna::addDna(input->_args[1], input->_args[2]));
    return false;
}

void New::isCorrectArgs(Parser &args) {
    size_t size = args._args.size();

    if(size < 2)
        throw std::invalid_argument("There are not enough arguments to new command");

    if(size > 3)
        throw std::invalid_argument("There are too much arguments to new command");

    if(!isDna(args._args[1]))
        throw std::invalid_argument("Invalid DNA");

    if(size == 3)
        if(args._args[2][0] != '@')
            throw std::invalid_argument("Should be given @ before the DNA name");
}

void New::addName(Parser &args) {
    if(args._args.size() == 2) {
        static size_t numOfSeq = 1;
        std::stringstream name;
        name << "seq" << numOfSeq++;
        args._args.push_back(name.str());
    }

    else {
        args._args[2].erase(0,1);
    }
}
