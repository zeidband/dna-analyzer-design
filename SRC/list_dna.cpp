//
// Created by a on 7/6/20.
//

#include "list_dna.h"

void ListDna::addDna(std::string dna, std::string name) {
    DNA *newDna = new DNA(name, dna);
    _allDnaAsId.insert(std::pair<size_t, DNA*>(newDna->getId(), newDna));
    _allDnaAsName.insert(std::pair<std::string, DNA*>(name, newDna));
}

void ListDna::printDnaById(size_t id) {
    
}
