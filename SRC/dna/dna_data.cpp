//
// Created by a on 7/6/20.
//

#include <sstream>
#include "dna_data.h"


DNA::DNA(std::string &name, std::string dna, size_t id) : _name(name), _dna(dna) , _id(id) {}

void DNA::print(IWrite *output) {
    std::stringstream out;
    out << "[" << _id << "] " << _name << ": ";


    if(_dna.length() <= 40) {
        out << _dna;
    }

    else {
        out << _dna.slice(0, 31) << "...";
        out << _dna[_dna.length() - 3] << _dna[_dna.length() - 2] << _dna[_dna.length() - 1];
    }

    output->write(out.str());
}
