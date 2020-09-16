//
// Created by a on 7/5/20.
//

#include "file_reader.h"


std::string& FileReader::read(std::string& inputFrom, size_t readSomeLines/* = 0*/) {
    std::string line;
    std::ifstream myFile(inputFrom.c_str());

    if (myFile.is_open()) {

        //read a line in the middle of the file
        if(readSomeLines) {
            for(size_t i = 0 ; i < readSomeLines ; ++i) {

                if (getline(myFile, line)) {
                    _input = line;
                }
            }
        }

        //read one line from the file
        else {
            getline(myFile, line);
            _input = line;
        }

        myFile.close();
        return _input;
    }

    throw std::fstream::failure("unable to open file");
}

