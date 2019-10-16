#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

#define NINJASHOEBOX_ENERGY 20
#define NINJASHOEBOX_DAMAGE 30

class SuperTrap;

class NinjaTrap : virtual public ClapTrap {
    public:
        NinjaTrap();
        NinjaTrap(const std::string &name);
        NinjaTrap(NinjaTrap const &src);
        virtual ~NinjaTrap();

        NinjaTrap &operator=(NinjaTrap const &rhs);
        virtual const std::string &getType() const;

        void ninjaShoebox(ClapTrap &trap);
        void ninjaShoebox(FragTrap &trap);
        void ninjaShoebox(ScavTrap &trap);
        void ninjaShoebox(NinjaTrap &trap);
        void ninjaShoebox(SuperTrap &trap);
    protected:
    private:
        std::string _type;
};