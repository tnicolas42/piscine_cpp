#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer() :
_name("defaultName"),
_title("defaultTitle") {
    std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(std::string const &name, std::string const &title) :
_name(name),
_title(title) {
    std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src) {
    *this = src;
}

Sorcerer::~Sorcerer() {
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &rhs) {
    if (this != &rhs) {
        _name = rhs.getName();
        _title = rhs.getTitle();
    }
    return *this;
}

void Sorcerer::polymorph(Victim const &victim) const {
    victim.getPolymorphed();
}

const std::string &Sorcerer::getName() const { return _name; }
const std::string &Sorcerer::getTitle() const { return _title; }

std::ostream &operator<<(std::ostream &o, Sorcerer const &other) {
    o << "I am " << other.getName() << ", " << other.getTitle() << ", and I like ponies !" << std::endl;
    return o;
}