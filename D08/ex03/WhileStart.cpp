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

void WhileStart::exec() {
}
