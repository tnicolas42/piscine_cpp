#pragma once

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(ScavTrap const &src);
        virtual ~ScavTrap();

        ScavTrap &operator=(ScavTrap const &rhs);

        void challengeNewcomer();
    protected:
    private:
};