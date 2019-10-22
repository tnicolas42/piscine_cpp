#include "Convert.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "usage: ./convert <convert>" << std::endl;
        return 1;
    }

    Convert conv = Convert(av[1]);

    std::cout << "char: ";
    try {
        char c = conv.toChar();
        std::cout << c << std::endl;
    }
    catch (Convert::ConvertError &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "int: ";
    try {
        int i = conv.toInt();
        std::cout << i << std::endl;
    }
    catch (Convert::ConvertError &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "float: ";
    try {
        float f = conv.toFloat();
        std::cout << f << "f" << std::endl;
    }
    catch (Convert::ConvertError &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "double: ";
    try {
        double d = conv.toDouble();
        std::cout << d << std::endl;
    }
    catch (Convert::ConvertError &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}