//
// Created by a on 7/6/20.
//

#ifndef SRC_DNA_DATA_H
#define SRC_DNA_DATA_H

#include "dna_sequence.h"
#include "../writer/i_write.h"


class DNA {
public:
    DNA(std::string &name, std::string dna, size_t id);

    void print(IWrite* output);

    std::string getDnaAsString();

    size_t getId() { return _id; }

    std::string getName() { return _name; }

private:
    std::string _name;
    size_t _id;
    DnaSequence _dna;
    // _status;
};


#endif //SRC_DNA_DATA_H
