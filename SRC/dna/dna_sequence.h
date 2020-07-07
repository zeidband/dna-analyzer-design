//
// Created by a on 7/6/20.
//

#ifndef SRC_DNA_SEQUENCE_H
#define SRC_DNA_SEQUENCE_H

#include <list>
#include "../read/i_read.h"

class DnaSequence {
private:
    class Nucleotide {
    public:
        Nucleotide(const char letter);
        Nucleotide() {}
        bool operator==(Nucleotide& letter);
        Nucleotide &operator=(char letter);
        Nucleotide(Nucleotide*);
        operator char() { return m_letter; }

    private:
        char m_letter;
    };

    typedef Nucleotide dnaNuc;


public:
    DnaSequence(const char* dna);
    DnaSequence(const std::string& dna);
    DnaSequence(const DnaSequence& dna);
    DnaSequence(IRead& reader);
    DnaSequence operator=(const DnaSequence& dna);
    ~DnaSequence();

    friend std::ostream& operator<<(std::ostream& out, DnaSequence dna);
    dnaNuc& operator[](size_t index);
    size_t length() const { return m_len; }
    const char *getDna() const;

    DnaSequence slice(size_t begin = 0, size_t end = 0);
    DnaSequence pair();
    bool find(DnaSequence dnaSequence);
    size_t count(DnaSequence subsequence);
    std::list<size_t> findAll(DnaSequence subsequence);
    std::list<size_t> findConsensusSequences();

protected:
    size_t findCodon(size_t index);
    size_t myStrstr(Nucleotide* nucleotide, size_t length);
    bool isValid(const char* dna);
    DnaSequence(size_t len);

private:
    Nucleotide* initDna(const char* dna);

    Nucleotide* m_dna;
    size_t m_len;

};

bool operator==(const DnaSequence &left, const DnaSequence &right);

bool operator!=(const DnaSequence &left, const DnaSequence &right);



#endif //SRC_DNA_SEQUENCE_H
