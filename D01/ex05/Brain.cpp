#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain() {}

Brain::~Brain() {}

std::string Brain::identify() const {
    std::stringstream hexStr;
    hexStr << std::hex << this;
    return hexStr.str();
}