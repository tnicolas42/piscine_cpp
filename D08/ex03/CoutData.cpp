#include "CoutData.hpp"

CoutData::CoutData(Brainfuck *brfk) :
AInstruction(brfk, '.') {
}

CoutData::CoutData(CoutData const &src) :
AInstruction(src) {
    *this = src;
}

CoutData::~CoutData() {
}

CoutData &CoutData::operator=(CoutData const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void CoutData::exec() {
}
