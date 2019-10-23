#include "Brainfuck.hpp"

Brainfuck::Brainfuck() : _data(new std::string()), _ptr(_data) {
    _data->reserve(MAX_STR_SIZE);
}

Brainfuck::Brainfuck(Brainfuck const &src) {
    *this = src;
}

Brainfuck::~Brainfuck() {
    delete _data;
}

Brainfuck &Brainfuck::operator=(Brainfuck const &rhs) {
    if (this != &rhs) {
        _data = new std::string(rhs.getData());
        _ptr = _data;
    }
    return *this;
}

std::string const  &Brainfuck::getData() const { return *_data; }
std::string        &Brainfuck::getData() { return *_data; }
std::string const  *Brainfuck::getPtr() const { return _ptr; }
std::string        *Brainfuck::getPtr() { return _ptr; }
