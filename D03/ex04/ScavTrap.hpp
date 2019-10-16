#pragma once

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(ScavTrap const &src);
        virtual ~ScavTrap();

        ScavTrap &operator=(ScavTrap const &rhs);
        virtual const std::string &getType() const;

        void challengeNewcomer();
    protected:
    private:
        std::string _type;
};