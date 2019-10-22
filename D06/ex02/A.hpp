#pragma once

#include "Base.hpp"

class A : public Base {
    public:
        A();
        A(A const &src);
        virtual ~A();

        A &operator=(A const &rhs);
    protected:
    private:
};
