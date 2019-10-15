#include "Fixed.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    Fixed a;
    const Fixed b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
}
