#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>

void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

void identify_from_pointer(Base *p) {
    A *a = dynamic_cast<A*>(p);
    if (a) {
        std::cout << "A" << std::endl;
        return;
    }
    B *b = dynamic_cast<B*>(p);
    if (b) {
        std::cout << "B" << std::endl;
        return;
    }
    C *c = dynamic_cast<C*>(p);
    if (c) {
        std::cout << "C" << std::endl;
        return;
    }
    std::cout << "not A, B or C" << std::endl;
}

void identify_from_reference(Base &p) {
    try {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    }
    catch (std::bad_cast) {}
    try {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
        return;
    }
    catch (std::bad_cast) {}
    try {
        C &c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return;
    }
    catch (std::bad_cast) {}
    std::cout << "not A, B or C" << std::endl;
}

int main(int ac, char **av)
{
    srand(static_cast<uint32_t>(time(NULL)));
    (void)ac;
    (void)av;
    Base base;
    Base *randomClass = base.generate();
    std::cout << "from pointer" << std::endl;
    identify_from_pointer(randomClass);
    std::cout << "from reference" << std::endl;
    identify_from_reference(*randomClass);
    return 0;
}
