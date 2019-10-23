#include "DecrPtr.hpp"

DecrPtr::DecrPtr(Brainfuck *brfk) :
AInstruction(brfk, '<') {
}

DecrPtr::DecrPtr(DecrPtr const &src) :
AInstruction(src) {
    *this = src;
}

DecrPtr::~DecrPtr() {
}

DecrPtr &DecrPtr::operator=(DecrPtr const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void DecrPtr::exec() {
}
