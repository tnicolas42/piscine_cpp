#pragma once

#include <string>
#include <iostream>

class Victim {
    public:
        Victim(std::string const &name);
        Victim(Victim const &src);
        virtual ~Victim();

        Victim &operator=(Victim const &rhs);
        virtual void getPolymorphed() const;
        const std::string &getName() const;
    protected:
        std::string _name;
    private:
        Victim();
};

std::ostream &operator<<(std::ostream &o, Victim const &other);