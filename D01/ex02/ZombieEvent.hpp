#pragma once

#include "Zombie.hpp"
#include <string>

static std::string randomNames[] = {
    "Zombie01",
    "Zombie02",
    "Zombie03",
    "Zombie04",
    "Zombie05",
    "Zombie06",
    "Zombie07",
    "Zombie08",
    "Zombie09"
};

class ZombieEvent {
    public:
        ZombieEvent();
        ~ZombieEvent();

        void setZombieType(const std::string type);
        Zombie *newZombie(const std::string name) const;
        Zombie *randomChump() const;
    protected:
    private:
        std::string _type;
};