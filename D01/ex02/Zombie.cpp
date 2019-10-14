#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() :
  _name("NoName"),
  _type("default") {
    std::cout << "<" << _name << " (" << _type << ")> born" << std::endl;
}

Zombie::Zombie(const std::string name, const std::string type) :
  _name(name),
  _type(type) {
    std::cout << "<" << _name << " (" << _type << ")> born" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "<" << _name << " (" << _type << ")> die" << std::endl;
}

void Zombie::announce() const {
    std::cout << "<" << _name << " (" << _type << ")> Braiiiiiiinnnssss..." << std::endl;
}