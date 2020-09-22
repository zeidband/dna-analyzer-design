//
// Created by a on 9/22/20.
//

#include <cstring>
#include <sys/stat.h>
#include <sstream>
#include "load.h"
#include "../../../reader/file_reader.h"
#include "../../../dna/container_dna.h"


LoadParams::sequenceName LoadParams::_sequenceFilesAndCount;


LoadParams &LoadParams::operator=(Parser &args) {
    _ok = E_OK;

    numOfParameters(args._args.size());

    if ( _ok == E_OK ) {
        isFileExist(args._args[1]);
    }

    if ( _ok == E_OK ) {
        isDna(_sequence);
    }

    if ( args._args.size() == 3 && _ok == E_OK ) {
        isCorrectName(args._args[2]);
    }

    else if ( _ok == E_OK ){
        newName(args._args[1]);
    }

    return *this;
}


void LoadParams::numOfParameters(size_t size) {
    if ( size < 2 || size > 3 ) {
        _ok = E_WRONG;
        _message = "There are not enough or too much arguments to new command";
    }
}


void LoadParams::isFileExist(std::string &fileName) {
    struct stat buffer = {};
    if ( !stat(fileName.c_str(), &buffer) ) {
        FileReader file;
        _sequence = file.read(fileName);
    }

    else {
        _ok = E_WRONG;
        _message = "unable to open file - file isn't exist";
    }
}


void LoadParams::isDna(std::string &dna) {
    if ( strlen(dna.c_str()) != strspn(dna.c_str(), "ACTG") ) {
        _ok = E_WRONG;
        _message = "Invalid dna - dna contain only A, G, T, C";
    }
}


void LoadParams::isCorrectName(std::string &name) {
    if (name[0] != '@') {
        _ok = E_WRONG;
        _message = "Should be given @ before the DNA name";
    }

    else {
        name.erase(0, 1);

        // TODO: decide if to change the name if exist such name
        if ( ContainerDna::isNameInContainer(name) ) {
            _ok = E_WRONG;
            _message = "exist dna with such name in the data";
        }

        else {
            _name = name;
        }
    }
}


void LoadParams::newName(std::string& fileName) {
    size_t type = fileName.find('.');
    fileName.erase(type, fileName.size() - 1);

    // First time we see a file with that name
    if ( _sequenceFilesAndCount.find(fileName) == _sequenceFilesAndCount.end() ) {
        _sequenceFilesAndCount[fileName] = 1;
    }

    if ( ContainerDna::isNameInContainer(fileName) ) {
        std::stringstream name;

        do {
            name.str("");
            name << fileName << _sequenceFilesAndCount[fileName]++;
        } while ( ContainerDna::isNameInContainer(name.str()) );

        _name = name.str();
    }

    else {
        _name = fileName;
    }
}


