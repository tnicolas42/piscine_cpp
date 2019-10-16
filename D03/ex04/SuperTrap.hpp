#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>

class SuperTrap : virtual public FragTrap, virtual public NinjaTrap {
    public:
        SuperTrap();
        SuperTrap(const std::string &name);
        SuperTrap(SuperTrap const &src);
        virtual ~SuperTrap();

        SuperTrap &operator=(SuperTrap const &rhs);
        virtual const std::string &getType() const;
    protected:
    private:
        std::string _type;
};