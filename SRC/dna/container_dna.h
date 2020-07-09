//
// Created by a on 7/6/20.
//

#ifndef SRC_CONTAINER_DNA_H
#define SRC_CONTAINER_DNA_H

#include "dna_data.h"
#include <map>
#include <tr1/memory>

class IWrite;


class ContainerDna {

    typedef std::map<size_t, std::tr1::shared_ptr<DNA> > IdDnaList;
    typedef std::map<std::string, std::tr1::shared_ptr<DNA> > NameDnaList;

public:
    static size_t addDna(std::string dna, std::string name);

    static void printDnaById(IWrite* output, size_t id);

    static bool isNameInContainer(std::string name);

    static bool isIDInContainer(size_t id);

    static std::string getDnaByNameOrId(std::string);

    static std::string getNameById(size_t id);

    static void deleteAll();

private:
    static IdDnaList _allDnaAsId;

    static NameDnaList _allDnaAsName;

    static size_t _idCounter;
};


#endif //SRC_CONTAINER_DNA_H
