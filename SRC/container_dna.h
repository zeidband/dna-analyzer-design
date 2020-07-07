//
// Created by a on 7/6/20.
//

#ifndef SRC_CONTAINER_DNA_H
#define SRC_CONTAINER_DNA_H

#include "dna_data.h"
#include <map>

class IWrite;


class ContainerDna {

    typedef std::map<size_t, DNA*> IdDnaList;
    typedef std::map<std::string, DNA*> NameDnaList;

public:
    static size_t addDna(std::string dna, std::string name);

    static void printDnaById(IWrite* output, size_t id);

private:
    static IdDnaList _allDnaAsId;

    static NameDnaList _allDnaAsName;

    static size_t _idCounter;
};


#endif //SRC_CONTAINER_DNA_H
