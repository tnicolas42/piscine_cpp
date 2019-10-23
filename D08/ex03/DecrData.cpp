#include "DecrData.hpp"

DecrData::DecrData(Brainfuck *brfk) :
AInstruction(brfk, '-') {
}

DecrData::DecrData(DecrData const &src) :
AInstruction(src) {
    *this = src;
}

DecrData::~DecrData() {
}

DecrData &DecrData::operator=(DecrData const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void DecrData::exec() {
}
