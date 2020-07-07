//
// Created by a on 7/6/20.
//

#ifndef SRC_DNA_DATA_H
#define SRC_DNA_DATA_H

#include "dna_sequence.h"
#include "i_write.h"


class DNA {
public:
    DNA(std::string &name, std::string dna, size_t id);

    void print(IWrite* output);

    size_t getId() { return _id; }

private:
    std::string _name;
    size_t _id;
    DnaSequence _dna;
    // _status;
};


#endif //SRC_DNA_DATA_H
