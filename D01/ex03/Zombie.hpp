#pragma once

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

class Zombie {
    public:
        Zombie();
        Zombie(const std::string name, const std::string type);
        ~Zombie();

        void announce() const;
        void setName(const std::string name);
    protected:
    private:
        std::string _name;
        std::string _type;
};