#include "Pony.hpp"
#include <iostream>

Pony::Pony() : _name("NoName") {
    std::cout << "new pony: " << _name << std::endl;
}
Pony::Pony(std::string name) : _name(name) {
    std::cout << "new pony: " << _name << std::endl;
}
Pony::~Pony() {
    std::cout << _name << " died" << std::endl;
}

std::string &Pony::getName() { return _name; }
const std::string &Pony::getName() const { return _name; }