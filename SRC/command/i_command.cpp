//
// Created by a on 7/5/20.
//

#include "i_command.h"
#include <cstring>
#include <cstdlib>
#include "../dna/container_dna.h"


bool ICommand::isDna(std::string &dna) {
    return strlen(dna.c_str()) == strspn(dna.c_str(), "ACTG");
}

bool ICommand::isExistId(std::string &id) {
    bool flag = false;

    if(id[0] == '#') {
        id.erase(0, 1);
        // TODO: check if id is a number
        flag = ContainerDna::isIDInContainer(std::atoi(id.c_str()));
        id.insert(0, 1, '#');
    }

    return flag;
}

bool ICommand::isExistName(std::string &name) {
    bool flag = false;

    if(name[0] == '@') {
        name.erase(0, 1);
        flag = ContainerDna::isNameInContainer(name);
        name.insert(0, 1, '@');
    }

    return flag;
}
