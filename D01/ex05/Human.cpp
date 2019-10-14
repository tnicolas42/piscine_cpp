#include "Human.hpp"

Human::Human() : _brain() {}

Human::~Human() {}

Brain &Human::getBrain() { return _brain; }

std::string Human::identify() const {
    return _brain.identify();
}