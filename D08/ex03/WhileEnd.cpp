#include "WhileEnd.hpp"

WhileEnd::WhileEnd(Brainfuck *brfk) :
AInstruction(brfk, ']') {
}

WhileEnd::WhileEnd(WhileEnd const &src) :
AInstruction(src) {
    *this = src;
}

WhileEnd::~WhileEnd() {
}

WhileEnd &WhileEnd::operator=(WhileEnd const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

bool WhileEnd::exec() {
    int count = 0;
    _brfk->getProgPtr()--;
    while (_brfk->getProgPtr() > 0) {
        if (_brfk->getProg()[_brfk->getProgPtr()]->getInstr() == ']')
            count++;
        else if (_brfk->getProg()[_brfk->getProgPtr()]->getInstr() == '[') {
            if (count == 0) {
                _brfk->getProgPtr()--;  // the next instrcution in while loop is ++
                return true;
            }
            count--;
        }
        _brfk->getProgPtr()--;
    }
    return false;
}
