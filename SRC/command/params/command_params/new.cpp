//
// Created by Sara a on 9/22/20.
//

#include <cstring>
#include <sstream>
#include "new.h"
#include "../../../dna/container_dna.h"


NewParams &NewParams::operator=(Parser &args) {
    _ok = E_OK;

    numOfParameters(args._args.size());

    if ( _ok == E_OK ) {
        isDna(args._args[1]);
        _sequence = args._args[1];
    }

    if ( args._args.size() == 3 && _ok == E_OK ) {
        isCorrectName(args._args[2]);
    }

    else if ( _ok == E_OK ) {
        newName();
    }

    return *this;
}


void NewParams::numOfParameters(size_t size) {
    if ( size < 2 || size > 3 ) {
        _ok = E_WRONG;
        _message = "There are not enough or too much arguments to new command";
    }
}


void NewParams::isDna(std::string &dna) {
    if ( strlen(dna.c_str()) != strspn(dna.c_str(), "ACTG") ) {
        _ok = E_WRONG;
        _message = "Invalid dna - dna contain only A, G, T, C";
    }

    else {
        _sequence = dna;
    }
}


void NewParams::isCorrectName(std::string &name) {
    if (name[0] != '@') {
        _ok = E_WRONG;
        _message = "Should be given @ before the DNA name";
    }

    else {
        name.erase(0, 1);

        // TODO: decide if to change the name if exist such name
        if(ContainerDna::isNameInContainer(name)) {
            _ok = E_WRONG;
            _message = "exist dna with such name in the data";
        }

        _name = name;
    }
}


void NewParams::newName() {
    static size_t numOfSeq = 1;
    std::stringstream name;

    do {
        name.str("");
        name << "seq" << numOfSeq++;
    } while (ContainerDna::isNameInContainer(name.str()));

    _name = name.str();
}

