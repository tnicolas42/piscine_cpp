#pragma once

#include "Victim.hpp"
#include <string>

class Peon : public Victim {
    public:
        Peon(std::string const &name);
        Peon(Peon const &src);
        virtual ~Peon();

        Peon &operator=(Peon const &rhs);
        virtual void getPolymorphed() const;
    protected:
    private:
        Peon();
};