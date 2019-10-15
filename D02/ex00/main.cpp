#include "Fixed.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
