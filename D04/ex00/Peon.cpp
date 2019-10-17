#include "Peon.hpp"

Peon::Peon() :
Victim("defaultName") {
}

Peon::Peon(std::string const &name) :
Victim(name) {
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) :
Victim(src) {
    *this = src;
}

Peon::~Peon() {
    std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator=(Peon const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}
void Peon::getPolymorphed() const {
    std::cout << _name << " has been turned into a pink pony !" << std::endl;
}