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

void WhileEnd::exec() {
}
