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

bool DecrData::exec() {
    if (_brfk->getData()[_brfk->getPtr()] == 0)
        return false;
    _brfk->getData()[_brfk->getPtr()]--;
    return true;
}
