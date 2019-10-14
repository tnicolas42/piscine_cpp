#include "ZombieEvent.hpp"
#include <iostream>
#include <ctime>

ZombieEvent::ZombieEvent() : _type("default") {
    std::srand(std::time(nullptr));
}

ZombieEvent::~ZombieEvent() {}

void ZombieEvent::setZombieType(const std::string type) {
    _type = type;
}

Zombie *ZombieEvent::newZombie(const std::string name) const {
    Zombie *newZ = new Zombie(name, _type);
    return newZ;
}

Zombie *ZombieEvent::randomChump() const {
    std::string name = randomNames[std::rand() % (sizeof(randomNames) / sizeof(randomNames[0]))];
    Zombie *newZ = new Zombie(name, _type);
    return newZ;
}