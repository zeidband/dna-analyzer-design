//
// Created by a on 7/6/20.
//

#include <sstream>
#include "dna_data.h"


DNA::DNA(std::string &name, std::string dna, size_t id) : _name(name) , _id(id), _dna(dna) {}

void DNA::print(IWrite *output) {
    std::stringstream out;
    out << "[" << _id << "] " << _name << ": ";

    size_t len = _dna.length();

    if(len <= 40) {
        out << _dna;
    }

    else {
        out << _dna.slice(0, 31) << "...";
        out << _dna[len - 3] << _dna[len - 2] << _dna[len - 1];
    }

    output->write(out.str());
}


void DNA::printAll(IWrite *output) {
    std::stringstream out;
    out << "[" << _id << "] " << _name << ": " << _dna.getDna();

    output->write(out.str());
}


std::string DNA::getDnaAsString() {
    return _dna.getDna();
}

