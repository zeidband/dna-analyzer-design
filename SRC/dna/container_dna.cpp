//
// Created by a on 7/6/20.
//

#include <cstdlib>
#include "container_dna.h"

size_t ContainerDna::_idCounter = 1;
ContainerDna::IdDnaList ContainerDna::_allDnaAsId;
ContainerDna::NameDnaList ContainerDna::_allDnaAsName;

size_t ContainerDna::addDna(std::string dna, std::string name) {
    std::tr1::shared_ptr<DNA> newDna(new DNA(name, dna, _idCounter));
    _allDnaAsId.insert(std::pair<size_t, std::tr1::shared_ptr<DNA> >(_idCounter, newDna));
    _allDnaAsName.insert(std::pair<std::string, std::tr1::shared_ptr<DNA> >(name, newDna));

    return _idCounter++;
}

void ContainerDna::printDnaById(IWrite *output, size_t id, bool all) {
    if ( all ) {
        _allDnaAsId[id]->printAll(output);
    }

    else {
        _allDnaAsId[id]->print(output);
    }
}

void ContainerDna::printDnaByName(IWrite *output, std::string name, bool all) {
    if ( all ) {
        _allDnaAsName[name]->printAll(output);
    }

    else {
        _allDnaAsName[name]->print(output);
    }
}


bool ContainerDna::isNameInContainer(std::string name) {
    return _allDnaAsName.find(name.c_str()) != _allDnaAsName.end();
}

bool ContainerDna::isIDInContainer(size_t dna) {
    return _allDnaAsId.find(dna) != _allDnaAsId.end();
}

std::string ContainerDna::getDnaByNameOrId(std::string NameOrId) {
    if ( NameOrId[0] == '#' ) {
        NameOrId.erase(0, 1);
        return _allDnaAsId[std::atoi(NameOrId.c_str())]->getDnaAsString();
    }

    NameOrId.erase(0, 1);
    return _allDnaAsName[NameOrId]->getDnaAsString();
}

std::string ContainerDna::getNameById(size_t id) {
    return _allDnaAsId[id]->getName();
}

size_t ContainerDna::getIdByName(std::string& name) {
    return _allDnaAsName[name]->getId();
}

void ContainerDna::deleteAll() {
    std::map<size_t, std::tr1::shared_ptr<DNA> >::iterator iter, curr;

    for (iter = _allDnaAsId.begin(); iter != _allDnaAsId.end();) {
        curr = iter;
        ++iter;
        _allDnaAsId.erase(curr);
    }
}

size_t ContainerDna::sliceDna(std::string &name, size_t begin, size_t end, bool inPlace, std::string &dna) {
    size_t id = 0;

    if ( !inPlace ) {
        id = addDna(dna, name);
    }

    else {
        id = getIdByName(name);
    }

    _allDnaAsName[name].get()->slice(begin, end);

    return id;
}



