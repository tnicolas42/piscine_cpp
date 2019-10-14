#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(uint32_t n) : _hordeSize(n), _horde(new Zombie[n]) {}

ZombieHorde::~ZombieHorde() {
    delete [] _horde;
}