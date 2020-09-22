//
// Created by a on 7/6/20.
//

#include "dna_sequence.h"
#include <cstring>


bool DnaSequence::isValid(const char* dna) {
    return strlen(dna) == strspn(dna, "ACTG");
}


DnaSequence::dnaNuc* DnaSequence::initDna(const char* dna) {
    m_dna = new Nucleotide[m_len + 1];
    strcpy((char*)m_dna, dna);
    return m_dna;
}


DnaSequence::DnaSequence(const char* dna) : m_len(strlen(dna)) {
    if(isValid(dna)) {
        initDna(dna);
    }

    else {
        throw std::invalid_argument("the DNA need to contain only: A, C, T and G letters\n");
    }
}


DnaSequence::DnaSequence(const std::string& dna) : m_len(strlen(dna.c_str())) {
    if(isValid(dna.c_str())) {
        initDna(dna.c_str());
    }

    else {
        throw std::invalid_argument("the DNA need to contain only: A, C, T and G letters\n");
    }
}


DnaSequence::DnaSequence(const DnaSequence &dna) : m_len(dna.m_len) {
    initDna((char*)dna.m_dna);
}


DnaSequence DnaSequence::operator=(const DnaSequence &dna) {
    if(this != &dna) {
        m_len = dna.m_len;

        delete [] m_dna;
        initDna((char*)dna.m_dna);
    }

    return *this;
}


DnaSequence::~DnaSequence() {
    delete [] m_dna;
}


std::ostream &operator<<(std::ostream &out, DnaSequence dna) {
    for(size_t i = 0 ; i < dna.m_len ; ++i) {
        out << ((char*)dna.m_dna)[i];
    }

    return out;
}


const char *DnaSequence::getDna() const {
    return (char*)m_dna;
}


bool operator==(const DnaSequence &left, const DnaSequence &right) {
    return !strcmp(right.getDna(), left.getDna());
}


bool operator!=(const DnaSequence &left, const DnaSequence &right) {
    return strcmp(right.getDna(), left.getDna());
}


DnaSequence::dnaNuc& DnaSequence::operator[](size_t index){
    if(index >= m_len || index < 0) {
        throw std::out_of_range("the index is out of range\n");
    }

    return m_dna[index];
}



//// phase 2 ////


DnaSequence::DnaSequence(IRead& reader) {
    std::string dna = reader.read();
    m_len = strlen(dna.c_str());

    if(isValid(dna.c_str())) {
        initDna(dna.c_str());
    }

    else {
        throw std::invalid_argument("the DNA need to contain only: A, C, T and G letters\n");
    }
}


DnaSequence DnaSequence::slice(size_t begin/* = 0 */, size_t end/* = 0 */) {
    if (end == 0 || end > m_len)
        end = m_len;

    if (begin >= length()) {
        begin = end + 1;
    }

    DnaSequence newDna(end - begin + 1);
    newDna.m_dna = new Nucleotide[end - begin + 2];
    size_t i;

    for (i = 0; i < end - begin + 1; ++i)
        newDna.m_dna[i] = m_dna[i + begin];

    newDna.m_dna[i] = m_dna[m_len];

    return newDna;
}


DnaSequence::DnaSequence(size_t len) : m_len(len) { }


DnaSequence DnaSequence::pair() {
    DnaSequence newDna(m_len);
    newDna.m_dna = new Nucleotide[m_len + 1];

    for(size_t i = 0 ; i < m_len ; ++i) {
        if(m_dna[i] == 'A')
            newDna.m_dna[m_len - i - 1] = 'T';
        else if(m_dna[i] == 'T')
            newDna.m_dna[m_len - i - 1] = 'A';
        else if(m_dna[i] == 'C')
            newDna.m_dna[m_len - i - 1] = 'G';
        else
            newDna.m_dna[m_len - i - 1] = 'C';
    }

    newDna.m_dna[m_len] = m_dna[m_len];

    return newDna;
}


size_t DnaSequence::myStrstr(Nucleotide* nucleotide, size_t length) {

    for (size_t i = 0; i <= m_len - length ; i++) {
        size_t j;
        for (j = 0; j < length ; j++)
            if (!(this->operator[](i + j) == nucleotide[j]))
                break;

        if (j == length) {
            return i;
        }
    }

    return m_len;
}


bool DnaSequence::find(DnaSequence subsequence) {
    if(myStrstr((Nucleotide*)subsequence.getDna(), subsequence.length()) == m_len)
        return false;
    return true;
}


size_t DnaSequence::count(DnaSequence subsequence) {
    size_t index = -1;
    size_t count = 0;

    while(true) {
        index += 1 + slice(index + 1).myStrstr((Nucleotide*)subsequence.getDna(), subsequence.length());
        if(index < m_len) {
            ++count;
        }

        else {
            break;
        }
    }

    return count;
}


std::list<size_t> DnaSequence::findAll(DnaSequence subsequence) {
    std::list<size_t> foundIndex;
    size_t index = -1;

    while(true) {
        index += 1 + slice(index + 1).myStrstr((Nucleotide*)subsequence.getDna(), subsequence.length());
        if(index < m_len) {
            foundIndex.push_back(index);
        }

        else {
            break;
        }
    }

    return foundIndex;
}

size_t DnaSequence::findCodon(size_t index) {
    const char startCodon[] = "ATG";
    const char endCodon[][4] = {"TAG", "TAA", "TGA"};
    size_t indexes[3];
    indexes[0] = slice(index).myStrstr((Nucleotide *) startCodon, 3);
    indexes[1] = slice(index).myStrstr((Nucleotide *) endCodon[1], 3);
    indexes[2] = slice(index).myStrstr((Nucleotide *) endCodon[1], 3);
    indexes[3] = slice(index).myStrstr((Nucleotide *) endCodon[2], 3);

    for (int i = 0; i < 3 ; ++i) {
        if(indexes[i] != m_len)
            return indexes[i];
    }

    return m_len;
}

std::list<size_t> DnaSequence::findConsensusSequences() {
    std::list<size_t> consensusSeq;
    std::list<size_t> startCodon = findAll("ATG");
    std::list<size_t> endCodon = findAll("TAG");
    std::list<size_t> endCodon2 = findAll("TAA");
    std::list<size_t> endCodon3= findAll("TGA");
    endCodon.merge(endCodon2);
    endCodon.merge(endCodon3);
    endCodon.sort();

    std::list<size_t>::iterator startIter = startCodon.begin();
    std::list<size_t>::iterator endIter = endCodon.begin();

    while(startIter != startCodon.end()) {

        while(endIter != endCodon.end() && *endIter < *startIter) {
            endCodon.erase(endIter);
            endIter = endCodon.begin();
        }

        while(endIter != endCodon.end() && (*endIter - *startIter) % 3 != 0) {
            ++endIter;
        }

        if(endIter != endCodon.end()) {
            consensusSeq.push_back(*startIter);
            endCodon.erase(endIter);
        }

        endIter = endCodon.begin();
        ++startIter;
    }

    return consensusSeq;
}




// Nucleotide

DnaSequence::Nucleotide::Nucleotide(const char letter) : m_letter(letter) {}

bool DnaSequence::Nucleotide::operator==(DnaSequence::Nucleotide& letter) {
    return (m_letter == letter.m_letter);
}

DnaSequence::Nucleotide &DnaSequence::Nucleotide::operator=(char letter) {
    if(letter != 'A' && letter != 'C' && letter != 'G' && letter != 'T')
        throw std::invalid_argument("");
    m_letter = letter;
    return *this;
}