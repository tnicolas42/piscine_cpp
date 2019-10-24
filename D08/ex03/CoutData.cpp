#include "CoutData.hpp"
#include <iostream>

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

bool CoutData::exec() {
    std::cout << _brfk->getData()[_brfk->getPtr()];
    return true;
}
