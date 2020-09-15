//
// Created by a on 7/7/20.
//

#include "load_command.h"
#include "../../dna/container_dna.h"
#include "../../reader/file_reader.h"
#include "new_command.h"
#include <cstring>
#include <sstream>


Load::sequenceName Load::_sequenceFilesAndCount;

void Load::isOk(Parser &args) {
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

void Load::isCorrectArgs(Parser &args) {
    size_t size = args._args.size();

    if(size < 2) {
        throw std::invalid_argument("There are not enough arguments to load command");
    }

    if(size > 3) {
        throw std::invalid_argument("There are too much arguments to load command");
    }

    FileReader file;
    args._args.push_back(args._args[1]);
    args._args[1] = file.read(args._args[1]);

    if(!isDna(args._args[1])) {
        throw std::invalid_argument("Invalid DNA");
    }

    if(size == 3) {

        if(args._args[2][0] != '@') {
            throw std::invalid_argument("Should be given @ before the DNA name");
        }

        else {
            args._args[2].erase(0, 1);

            if(ContainerDna::isNameInContainer(args._args[2])) {
                throw std::invalid_argument("exist dna with such name in the program");
            }

            args._args[2].insert(0, 1, '@');
        }
    }
}

void Load::addName(Parser &args) {
    if(args._args.size() == 3) {
        size_t type = args._args[2].find(".");
        args._args[2].erase(type, args._args[2].size() - 1);

        // First time we see a file with that name
        if(!ContainerDna::isNameInContainer(args._args[2])) {
            _sequenceFilesAndCount[args._args[2]] = 1;
        }

        else {
            std::stringstream name;
            name << args._args[2] << _sequenceFilesAndCount[args._args[2]];
            _sequenceFilesAndCount[args._args[2]] += 1;
            args._args.pop_back();
            args._args.push_back(name.str());
        }

    }

    else {
        args._args[2].erase(0,1);
        args._args.pop_back();
    }
}

