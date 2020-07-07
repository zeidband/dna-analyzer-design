//
// Created by a on 7/6/20.
//

#include "list_dna.h"

IdDnaList ListDna::_allDnaAsId;
NameDnaList ListDna::_allDnaAsName;

size_t ListDna::addDna(std::string dna, std::string name) {
    DNA *newDna = new DNA(name, dna);
    _allDnaAsId.insert(std::pair<size_t, DNA*>(newDna->getId(), newDna));
    _allDnaAsName.insert(std::pair<std::string, DNA*>(name, newDna));

    return newDna->getId();
}

void ListDna::printDnaById(IWrite *output, size_t id) {
    _allDnaAsId[id]->print(output);
}

