#include "GetInput.hpp"

GetInput::GetInput(Brainfuck *brfk) :
AInstruction(brfk, ',') {
}

GetInput::GetInput(GetInput const &src) :
AInstruction(src) {
    *this = src;
}

GetInput::~GetInput() {
}

GetInput &GetInput::operator=(GetInput const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void GetInput::exec() {
}
