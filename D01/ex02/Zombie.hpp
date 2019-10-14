#pragma once

#include <string>

class Zombie {
    public:
        Zombie();
        Zombie(const std::string name, const std::string type);
        ~Zombie();

        void announce() const;
    protected:
    private:
        std::string _name;
        std::string _type;
};