//
// Created by a on 7/5/20.
//

#include "file_reader.h"

std::string FileReader::read() {
    std::string line;
    std::ifstream myfile("example.txt");

    if (myfile.is_open()) {
        if(getline(myfile, line)) {
            _input = line;
        }
        myfile.close();
        return _input;
    }
    throw std::fstream::failure("unable to open file");
}
