//
// Created by a on 7/6/20.
//

#ifndef SRC_LIST_DNA_H
#define SRC_LIST_DNA_H

#include "dna_data.h"
#include <map>

class ListDna {
public:
    void addDna(std::string dna, std::string name);
    void printDnaById(size_t id);
private:
    static std::map<size_t, DNA*> _allDnaAsId;
    static std::map<std::string, DNA*> _allDnaAsName;
};


#endif //SRC_LIST_DNA_H
