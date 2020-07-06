//
// Created by a on 7/5/20.
//

#include "file_writer.h"
#include <fstream>

void FileWriter::write(std::string input) {
    std::ofstream myfile("output.txt", std::ios::ate);

    if (myfile.is_open()) {
        myfile << input << std::endl;
        myfile.close();
    }

    else {
        throw std::fstream::failure("unable to open file");
    }
}
