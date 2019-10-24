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

bool DecrPtr::exec() {
    if (_brfk->getPtr() == 0)
        return false;
    _brfk->getPtr()--;
    return true;
}
