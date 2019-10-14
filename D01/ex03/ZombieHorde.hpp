#pragma once

#include "Zombie.hpp"

class ZombieHorde {
    public:
        ZombieHorde(uint32_t n);
        ~ZombieHorde();

        void announce() const;
    protected:
    private:
        uint32_t _hordeSize;
        Zombie *_horde;
};