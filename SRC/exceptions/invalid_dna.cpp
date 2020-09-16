//
// Created by a on 9/16/20.
//

#include "invalid_dna.h"

const char* InvalidDna::what() const throw() {
    return "InvalidDna:: dna contain only A, G, T, C";
}
