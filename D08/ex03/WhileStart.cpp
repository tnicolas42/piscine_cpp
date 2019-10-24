#include "WhileStart.hpp"

WhileStart::WhileStart(Brainfuck *brfk) :
AInstruction(brfk, '[') {
}

WhileStart::WhileStart(WhileStart const &src) :
AInstruction(src) {
    *this = src;
}

WhileStart::~WhileStart() {
}

WhileStart &WhileStart::operator=(WhileStart const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

bool WhileStart::exec() {
    if (_brfk->getData()[_brfk->getPtr()] > 0)
        return true;

    // go to the end of the loop
    int count = 0;
    _brfk->getProgPtr()++;
    while (_brfk->getProgPtr() < _brfk->getProg().size()) {
        if (_brfk->getProg()[_brfk->getProgPtr()]->getInstr() == '[')
            count++;
        else if (_brfk->getProg()[_brfk->getProgPtr()]->getInstr() == ']') {
            if (count == 0)
                return true;
            count--;
        }
        _brfk->getProgPtr()++;
    }
    return false;
}
