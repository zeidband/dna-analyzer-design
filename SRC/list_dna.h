//
// Created by a on 7/6/20.
//

#ifndef SRC_LIST_DNA_H
#define SRC_LIST_DNA_H

#include "dna_data.h"
#include <map>

class IWrite;

typedef std::map<size_t, DNA*> IdDnaList;
typedef std::map<std::string, DNA*> NameDnaList;

class ListDna {
public:
    static size_t addDna(std::string dna, std::string name);
    static void printDnaById(IWrite* output, size_t id);
private:
    static IdDnaList _allDnaAsId;
    static NameDnaList _allDnaAsName;
};


#endif //SRC_LIST_DNA_H
