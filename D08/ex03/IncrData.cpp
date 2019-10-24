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

bool IncrData::exec() {
    if (_brfk->getData()[_brfk->getPtr()] == std::numeric_limits<char>::max())
        return false;
    _brfk->getData()[_brfk->getPtr()]++;
    return true;
}
