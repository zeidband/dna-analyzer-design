//
// Created by a on 7/6/20.
//

#include <sstream>
#include "dna_data.h"

size_t DNA::_idCounter = 0;

DNA::DNA(std::string &name, std::string dna) : _name(name), _dna(dna) {
    _id = _idCounter++;
}

void DNA::print(IWrite *output) {
    std::stringstream out;
    out << "[" << _id << "] " << _name << ": " << _dna;
    output->write(out.str());

}
