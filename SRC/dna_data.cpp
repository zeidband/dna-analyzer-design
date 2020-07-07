//
// Created by a on 7/6/20.
//

#include <sstream>
#include "dna_data.h"


DNA::DNA(std::string &name, std::string dna, size_t id) : _name(name), _dna(dna) , _id(id) {}

void DNA::print(IWrite *output) {
    std::stringstream out;
    out << "[" << _id << "] " << _name << ": " << _dna;
    output->write(out.str());

}
