#include "Base.hpp"
#include <stdlib.h>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
}

Base *Base::generate() const {
    int type = rand() % 3;

    if (type == 0) {
        return static_cast<Base*>(new A());
    }
    if (type == 1) {
        return static_cast<Base*>(new B());
    }
    return static_cast<Base*>(new C());
}
