#pragma once

#include "Victim.hpp"
#include <string>
#include <iostream>

class Sorcerer {
    public:
        Sorcerer(std::string const &name, std::string const &title);
        Sorcerer(Sorcerer const &src);
        ~Sorcerer();

        Sorcerer &operator=(Sorcerer const &rhs);
        void polymorph(Victim const &victim) const;
        const std::string &getName() const;
        const std::string &getTitle() const;
    protected:
    private:
        Sorcerer();

        std::string _name;
        std::string _title;
};

std::ostream &operator<<(std::ostream &o, Sorcerer const &other);