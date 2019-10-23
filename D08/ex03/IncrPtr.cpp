#include "IncrPtr.hpp"

IncrPtr::IncrPtr(Brainfuck *brfk) :
AInstruction(brfk, '>') {
}

IncrPtr::IncrPtr(IncrPtr const &src) :
AInstruction(src) {
    *this = src;
}

IncrPtr::~IncrPtr() {
}

IncrPtr &IncrPtr::operator=(IncrPtr const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void IncrPtr::exec() {
}
