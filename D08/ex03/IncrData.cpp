#include "IncrData.hpp"

IncrData::IncrData(Brainfuck *brfk) :
AInstruction(brfk, '+') {
}

IncrData::IncrData(IncrData const &src) :
AInstruction(src) {
    *this = src;
}

IncrData::~IncrData() {
}

IncrData &IncrData::operator=(IncrData const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void IncrData::exec() {
}
