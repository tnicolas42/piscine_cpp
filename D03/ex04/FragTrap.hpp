#pragma once

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(FragTrap const &src);
        virtual ~FragTrap();

        FragTrap &operator=(FragTrap const &rhs);
        virtual const std::string &getType() const;

        void vaulthunter_dot_exe(std::string const & target);
    protected:
    private:
        std::string _type;
};