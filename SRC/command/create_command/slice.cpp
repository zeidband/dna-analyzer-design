//
// Created by a on 9/16/20.
//

#include <cstdlib>
#include <cstring>
#include <sstream>
#include "slice.h"
#include "../../exceptions/too_many_parameters.h"
#include "../../exceptions/few_parameters.h"
#include "../../exceptions/wrong_syntax.h"
#include "../../exceptions/no_dna.h"
#include "../../dna/container_dna.h"


Slice::sequenceName Slice::_sequenceFilesAndCount;

void Slice::isOk(Parser &args) {
    //Correctness check the parser
    _inPlace = (args._args.size() == 4);

    isCorrectArgs(args); //throw exception if args not correct

    //the parser is valid!!
    addName(args);
}

bool Slice::run(Parser &input, IWrite *outputPrint) {
    if ( _inPlace ) {
        ContainerDna::printDnaById(outputPrint, ContainerDna::sliceDna(input._args[1], std::atoi(input._args[2].c_str()), std::atoi(input._args[3].c_str())));
    }

    else {
        ContainerDna::printDnaById(outputPrint, ContainerDna::sliceDna(input._args[5], std::atoi(input._args[2].c_str()), std::atoi(input._args[3].c_str()),false, input._args[1]));
    }
//    TODO: this terminate called!!! : slice #2 3 4 : @@
//    for ( size_t i = 0 ; i < input._args.size() ; ++i ) {
//        std::cout << "args[" << i << "] = " << input._args[i] << std::endl;
//    }
    return false;
}

void Slice::isCorrectArgs(Parser &args) {
    size_t size = args._args.size();

    if ( size < 4 ) {
        throw FewParameters("There are not enough arguments to slice command");
    }

    if ( size > 6 ) {
        throw TooManyParameters("There are too much arguments to slice command");
    }

    if ( !isExistId(args._args[1]) && !isExistName(args._args[1]) && !isDna(args._args[1]) ) {
        throw NoDna();
    }

    if ( size == 5 ) {
        throw WrongSyntax("need a name to save in new sequence or type @@ to generate random name");
    }

    if ( _inPlace && args._args[1][0] != '@' && args._args[1][0] != '#' ) {
        // TODO: decide if to do the slice and to print just attention
        throw WrongSyntax("there is no name to save the new Dna");
    }

    if ( !_inPlace ) {
        if ( args._args[4].size() > 1 || args._args[4][0] != ':' ) {
            throw WrongSyntax("the fifth element is only :");
        }
    }

    isNumbers(args);
}

void Slice::addName(Parser &args) {
    if ( !_inPlace ) {
        if (args._args[5][0] != '@') {
            throw WrongSyntax("Should be given @ before the DNA name");
        }

        if ( !strcmp(args._args[5].c_str(), "@@") ) {
            if ( args._args[1][0] == '#' ) {
                args._args[1].erase(0, 1);
                args._args[1] = ContainerDna::getNameById(std::atoi(args._args[1].c_str()));
            }

            else if ( args._args[1][0] == '@' ){
                args._args[1].erase(0, 1);
            }

            else {
                throw WrongSyntax("there is no name to generate the sequence name");
            }

            if ( _sequenceFilesAndCount.find(args._args[2].c_str()) == _sequenceFilesAndCount.end() ) {
                _sequenceFilesAndCount[args._args[2]] = 1;
            }

            std::stringstream name;

            do {
                name.str("");
                name << args._args[1] << "_s" << _sequenceFilesAndCount[args._args[2]];
                ++_sequenceFilesAndCount[args._args[2]];
            } while ( ContainerDna::isNameInContainer(name.str()) );

            args._args.pop_back();
            args._args.push_back(name.str());
        }

        else {
            if ( args._args[1][0] == '@' || args._args[1][0] == '#' ) {
                args._args[1].erase(0, 1);
            }

            args._args[5].erase(0, 1);
            if ( ContainerDna::isNameInContainer(args._args[5]) ) {
                throw std::invalid_argument("exist dna with such name in the program");
            }
        }
    }

    else {
        if ( args._args[1][0] == '#' ) {
            args._args[1].erase(0, 1);
            args._args[1] = ContainerDna::getNameById(std::atoi(args._args[1].c_str()));
        }

        else {
            args._args[1].erase(0, 1);
        }
    }
}

static bool isNumber(const char* str, size_t n) {
    for ( size_t i = 0 ; i < n ; ++i ) {
        if ( str[i] < '0' || str[i] > '9')
            return false;
    }

    return true;
}

void Slice::isNumbers(Parser &args) {
    if ( !isNumber(args._args[2].c_str(), args._args[2].size()) ||
         !isNumber(args._args[3].c_str(), args._args[3].size())) {
        throw WrongSyntax("the from_ind and to_ind should be real numbers!!");
    }

    if ( std::atoi(args._args[2].c_str()) > std::atoi(args._args[3].c_str()) ) {
        throw WrongSyntax("the from_ind should be small then to_ind!!");
    }
}
