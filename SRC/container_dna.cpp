//
// Created by a on 7/6/20.
//

#include "container_dna.h"

size_t ContainerDna::_idCounter = 1;
ContainerDna::IdDnaList ContainerDna::_allDnaAsId;
ContainerDna::NameDnaList ContainerDna::_allDnaAsName;

size_t ContainerDna::addDna(std::string dna, std::string name) {
    DNA *newDna = new DNA(name, dna, _idCounter);
    _allDnaAsId.insert(std::pair<size_t, DNA*>(_idCounter, newDna));
    _allDnaAsName.insert(std::pair<std::string, DNA*>(name, newDna));

    return _idCounter++;
}

void ContainerDna::printDnaById(IWrite *output, size_t id) {
    _allDnaAsId[id]->print(output);
}

