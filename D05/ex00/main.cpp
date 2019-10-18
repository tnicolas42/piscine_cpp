#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    Bureaucrat b("bob", 150);

    try {
        while (1) {
            for(int i=0; i < 10; i++) {
                b.upGrade();
            }
            std::cout << b << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "[ERROR]: " << e.what() << std::endl;
        std::cout << b << std::endl;
    }

    return 0;
}