//
// Created by a on 7/8/20.
//

#include <cstdlib>
#include <sstream>
#include "dup_command.h"
#include "new_command.h"
#include "../../dna/container_dna.h"
#include "../../exceptions/too_many_parameters.h"
#include "../../exceptions/few_parameters.h"
#include "../../exceptions/wrong_syntax.h"
#include "../../exceptions/no_dna.h"

Load::sequenceName Dup::_sequenceFilesAndCount;


void Dup::isOk(Parser &args) {
    //Correctness check the parser
    isCorrectArgs(args); //throw exception if args not correct

    //the parser is valid!!
    addName(args);
}

bool Dup::run(Parser &input, IWrite *outputPrint) {
    ContainerDna::printDnaById(outputPrint, ContainerDna::addDna(input._args[1], input._args[2]));
    return false;
}

void Dup::isCorrectArgs(Parser &args) {
    size_t size = args._args.size();

    if ( size < 2 ) {
        throw FewParameters("There are not enough arguments to load command");
    }

    if ( size > 3 ) {
        throw TooManyParameters("There are too much arguments to load command");
    }

    if ( args._args[1][0] != '@' && args._args[1][0] != '#' ) {
        throw WrongSyntax("Should be given @ before the DNA name or # before the DNA id");
    }

    if ( !isExistId(args._args[1]) && !isExistName(args._args[1]) ) {
        throw NoDna();
    }

    if ( size == 3 ) {

        if ( args._args[2][0] != '@' ) {
            throw WrongSyntax("Should be given @ before the DNA name");
        }

        else {
            args._args[2].erase(0, 1);

            // TODO: decide if to change the name if exist such name
            if ( ContainerDna::isNameInContainer(args._args[2]) ) {
                throw std::invalid_argument("exist dna with such name in the program");
            }
        }
    }
}

void Dup::addName(Parser &args) {

    if ( args._args.size() == 2 ) {

        // given name to dup
        if ( args._args[1][0] == '#' ) {
            args._args[1].erase(0, 1);
            args._args[1] = ContainerDna::getNameById(std::atoi(args._args[1].c_str()));
        }

        else {
            args._args[1].erase(0, 1);
        }

        // First time we see a file with that name
        if ( _sequenceFilesAndCount.find(args._args[1]) == _sequenceFilesAndCount.end() ) {
            _sequenceFilesAndCount[args._args[1]] = 1;
        }

        std::stringstream name;

        do {
            name.str("");
            name << args._args[1] << "_" << _sequenceFilesAndCount[args._args[1]];
            ++_sequenceFilesAndCount[args._args[1]];
        } while ( ContainerDna::isNameInContainer(name.str()) );

        args._args.push_back(name.str());
        args._args[1] = ContainerDna::getDnaByNameOrId('@' + args._args[1]);
    }

    else {
        args._args[1] = ContainerDna::getDnaByNameOrId(args._args[1]);
    }
}

