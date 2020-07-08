//
// Created by a on 7/5/20.
//

#include "file_reader.h"


std::string& FileReader::read(std::string& inputFrom, bool readSomeLines/* = false*/) {
    std::string line;
    std::ifstream myFile(inputFrom.c_str());

    if (myFile.is_open()) {

        if(readSomeLines) {
            static size_t count = 0;
            count++;

            for(size_t i = 0 ; i < count ; ++i) {

                if (getline(myFile, line)) {
                    _input = line;
                }
            }
        }

        else {
            getline(myFile, line);
            _input = line;
        }

        myFile.close();
        return _input;
    }

    throw std::fstream::failure("unable to open file");
}

