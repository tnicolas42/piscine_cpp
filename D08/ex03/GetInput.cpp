#include "GetInput.hpp"
#include <iostream>

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

bool GetInput::exec() {
    int ci = std::getchar();
    if ((ci >= 32 && ci <= 126)) {
        _brfk->getData()[_brfk->getPtr()] = static_cast<char>(ci);
        return true;
    }
    if (ci == -1) {  // ^D -> save 0
        _brfk->getData()[_brfk->getPtr()] = 0;
        return true;
    }
    if (ci == '\n') {  // \n -> retry instruction
        _brfk->getProgPtr()--;
        return true;
    }
    return false;
}
