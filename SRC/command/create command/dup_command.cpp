//
// Created by a on 7/8/20.
//

#include <cstdlib>
#include <sstream>
#include "dup_command.h"
#include "new_command.h"
#include "../../dna/container_dna.h"

Load::sequenceName Dup::_sequenceFilesAndCount;


Dup::Dup(Parser &args) {
    //Correctness check the parser
    isCorrectArgs(args); //throw exception if args not correct

    //the parser is valid!!
    addName(args);
}

void Dup::isCorrectArgs(Parser &args) {
    size_t size = args._args.size();

    if(size < 2)
        throw std::invalid_argument("There are not enough arguments to load command");

    if(size > 3)
        throw std::invalid_argument("There are too much arguments to load command");

    if(args._args[1][0] == '#') {
        args._args[1].erase(0, 1);
        if(!ContainerDna::isIDInContainer(std::atoi(args._args[1].c_str())))
            throw std::invalid_argument("There is no such DNA");
        args._args[1].insert(args._args[1].begin(), '#');
    }

    else {
        if(!ContainerDna::isNameInContainer(args._args[1]))
            throw std::invalid_argument("There is no such DNA");
    }

    if(size == 3)
        if(args._args[2][0] != '@')
            throw std::invalid_argument("Should be given @ before the DNA name");
}

void Dup::addName(Parser &args) {

    if(args._args.size() == 3) {

        // given name to dup
        if (args._args[1][0] == '#') {
            args._args[1].erase(0, 1);
            args._args[1] = ContainerDna::getNameById(std::atoi(args._args[1].c_str()));
        }

        // First time we see a file with that name
        if (!ContainerDna::isNameInContainer(args._args[2])) {
            _sequenceFilesAndCount[args._args[2]] = 1;
            args._args.push_back(args._args[1]);
        }

        else {
            std::stringstream name;
            name << args._args[2] << "_" << _sequenceFilesAndCount[args._args[2]];
            _sequenceFilesAndCount[args._args[2]] += 1;
            args._args.pop_back();
            args._args.push_back(name.str());
        }

    }

    args._args[1] = ContainerDna::getDnaByNameOrId(args._args[1]);
}

bool Dup::run(Parser *input, IWrite *outputPrint) {
    New myNew;
    myNew.run(input, outputPrint);
    return false;
}


