#pragma once

#include "Base.hpp"

class C : public Base {
    public:
        C();
        C(C const &src);
        virtual ~C();

        C &operator=(C const &rhs);
    protected:
    private:
};
