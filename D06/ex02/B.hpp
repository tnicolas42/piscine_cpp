#pragma once

#include "Base.hpp"

class B : public Base {
    public:
        B();
        B(B const &src);
        virtual ~B();

        B &operator=(B const &rhs);
    protected:
    private:
};
