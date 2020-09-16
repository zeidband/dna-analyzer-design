//
// Created by a on 7/10/20.
//

#include <cstdlib>
#include "../../dna/container_dna.h"
#include "save_command.h"
#include "../../writer/file_writer.h"
#include "../../exceptions/too_many_parameters.h"
#include "../../exceptions/few_parameters.h"
#include "../../exceptions/wrong_syntax.h"


void Save::isOk(Parser &args) {
    //Correctness check the parser
    isCorrectArgs(args); //throw exception if args not correct

    //the parser is valid!!
    addName(args);
}

bool Save::run(Parser &input, IWrite *outputPrint) {
    FileWriter writer(input._args[2]);

    if ( input._args[1][0] != '@' && input._args[1][0] != '#' ) {
        writer.write(input._args[1]);
    }

    else {
        writer.write(ContainerDna::getDnaByNameOrId(input._args[1]));
    }

    outputPrint->write("done!");

    return false;
}

void Save::isCorrectArgs(Parser &args) {
    size_t size = args._args.size();

    if ( size < 2 ) {
        throw FewParameters("There are not enough arguments to load command");
    }

    if ( size > 3 ) {
        throw TooManyParameters("There are too much arguments to load command");
    }

    if ( !isExistId(args._args[1]) && !isExistName(args._args[1]) && !isDna(args._args[1]) ) {
        throw WrongSyntax("Invalid seq");
    }

    if ( size == 3 ) {
        if ( invalidFile(args._args[2]) ) {
            throw WrongSyntax("The filename should be suffixed by .rawdna");
        }
    }
}

void Save::addName(Parser &args) {
    if ( args._args.size() == 2 ) {
        if ( args._args[1][0] == '#' ) {
            args._args[1].erase(0, 1);
            args._args.push_back(ContainerDna::getNameById(std::atoi(args._args[1].c_str())) + ".rawdna");
            args._args[1].insert(0, 1, '#');
        }

        else if ( args._args[1][0] == '@' ) {
            args._args.push_back(args._args[1] + ".rawdna");
            args._args[2].erase(0, 1);
        }

        else {
            throw WrongSyntax("there is no file name to insert this dna");
        }
    }
}

bool Save::invalidFile(std::string &name_file) {
    const char* suffixed = ".rawdna";
    size_t size = name_file.size();

    if ( size < 7 ) {
        return true;
    }

    for ( int i = 1 ; i <= 7 ; ++i ) {
        if ( name_file[size - i] != suffixed[7 - i] ) {
            return true;
        }
    }

    return false;
}

