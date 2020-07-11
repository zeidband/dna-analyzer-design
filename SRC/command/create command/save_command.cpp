//
// Created by a on 7/10/20.
//

#include <cstdlib>
#include "../../dna/container_dna.h"
#include "save_command.h"
#include <cstring>
#include "../../write/file_writer.h"

Save::Save(Parser &args) {
    //Correctness check the parser
    isCorrectArgs(args); //throw exception if args not correct

    //the parser is valid!!
    addName(args);
}


bool Save::run(Parser *input, IWrite *outputPrint) {
    FileWriter writer(input->_args[2]);
    writer.write(ContainerDna::getDnaByNameOrId(input->_args[1]));
    return false;
}

void Save::isCorrectArgs(Parser &args) {
    size_t size = args._args.size();

    if(size < 2)
        throw std::invalid_argument("There are not enough arguments to load command");

    if(size > 3)
        throw std::invalid_argument("There are too much arguments to load command");

    if(!isId(args._args[1]) && !isName(args._args[1]) && !isDna(args._args[1]))
        throw std::invalid_argument("Invalid seq");

    if(size == 3)
        if(args._args[2][0] != '@')
            throw std::invalid_argument("Should be given @ before the DNA name");
}


void Save::addName(Parser &args) {
    if(args._args.size() == 2) {
        if(args._args[1][0] == '#') {
            args._args[1].erase(0, 1);
            args._args.push_back(ContainerDna::getNameById(std::atoi(args._args[1].c_str())) + ".rawdna");
            args._args[1].insert(0, 1, '#');
        }

        else if(args._args[1][0] == '@') {
            args._args.push_back(args._args[1] + ".rawdna");
            args._args[2].erase(0, 1);
        }

        else {
            throw std::invalid_argument("there is no file name to insert this dna");
        }
    }
}

bool Save::isDna(std::string &dna) {
    return strlen(dna.c_str()) == strspn(dna.c_str(), "ACTG");
}

bool Save::isId(std::string &id) {
    bool flag = false;

    if(id[0] == '#') {
        id.erase(0, 1);
        flag = ContainerDna::isIDInContainer(std::atoi(id.c_str()));
        id.insert(0, 1, '#');
    }

    return flag;
}

bool Save::isName(std::string &name) {
    bool flag = false;

    if(name[0] == '@') {
        name.erase(0, 1);
        flag = ContainerDna::isNameInContainer(name);
        name.insert(0, 1, '@');
    }

    return flag;
}

