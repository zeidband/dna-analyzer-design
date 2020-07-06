//
// Created by a on 7/6/20.
//

#ifndef SRC_DNA_DATA_H
#define SRC_DNA_DATA_H

#include "dna_sequence.h"

class DNA {
private:
    Name *_name;
    size_t _id;
    DnaSequence _dna;
    Status _status;

    static size_t _id_counter;
};


#endif //SRC_DNA_DATA_H
