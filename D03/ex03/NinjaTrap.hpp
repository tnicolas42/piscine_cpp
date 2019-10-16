#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class NinjaTrap : public ClapTrap {
    public:
        NinjaTrap();
        NinjaTrap(const std::string &name);
        NinjaTrap(NinjaTrap const &src);
        virtual ~NinjaTrap();

        NinjaTrap &operator=(NinjaTrap const &rhs);

        void ninjaShoebox(ClapTrap &trap);
        void ninjaShoebox(FragTrap &trap);
        void ninjaShoebox(ScavTrap &trap);
        void ninjaShoebox(NinjaTrap &trap);
    protected:
    private:
};