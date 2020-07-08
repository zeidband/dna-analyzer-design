//
// Created by a on 7/7/20.
//

#include "load_command.h"
#include "../../dna/container_dna.h"
#include "../../read/file_reader.h"
#include "new_command.h"
#include <cstring>
#include <sstream>


Load::Load(Parser &args) {
    //Correctness check the parser
    isCorrectArgs(args); //throw exception if args not correct

    //the parser is valid!!
    addName(args);
}

bool Load::run(Parser *input, IWrite *outputPrint) {
    New myNew;
    myNew.run(input, outputPrint);
    return false;
}

bool Load::isDna(std::string &dna) {
    return strlen(dna.c_str()) == strspn(dna.c_str(), "ACTG");
}

void Load::isCorrectArgs(Parser &args) {
    size_t size = args._args.size();

    if(size < 2)
        throw std::invalid_argument("There are not enough arguments to load command");

    if(size > 3)
        throw std::invalid_argument("There are too much arguments to load command");

    FileReader file;
    args._args.push_back(args._args[1]);
    args._args[1] = file.read(args._args[1]);

    if(!isDna(args._args[1]))
        throw std::invalid_argument("Invalid DNA");

    if(size == 3)
        if(args._args[2][0] != '@')
            throw std::invalid_argument("Should be given @ before the DNA name");
}

void Load::addName(Parser &args) {
    if(args._args.size() == 3) {
        size_t type = args._args[3].find(".");
        args._args[3].erase(type, args._args.size() - 1);
        if(!ContainerDna::isNameInContainer(args._args[3])) {
            _sequenceFilesAndCount[args._args[3]] = 1;
        }

        std::stringstream name;
        name << args._args[3] << _sequenceFilesAndCount[args._args[3]];
        _sequenceFilesAndCount[args._args[3]] += 1;

        args._args.pop_back();
        args._args.push_back(name.str());
    }

    else {
        args._args[2].erase(0,1);
        args._args.pop_back();
    }
}

