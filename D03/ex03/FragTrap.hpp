#pragma once

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(FragTrap const &src);
        virtual ~FragTrap();

        FragTrap &operator=(FragTrap const &rhs);

        void vaulthunter_dot_exe(std::string const & target);
    protected:
    private:
};