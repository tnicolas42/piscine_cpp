#include "Brainfuck.hpp"
#include "AInstruction.hpp"
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Usage: ./ex03 <file>" << std::endl;
        return 1;
    }

    std::ifstream f(av[1]);
    if (f.fail()) {
        std::cout << "Error: " << strerror(errno) << std::endl;
        return 1;
    }
    std::string data((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    if (f.fail()) {
        std::cout << "Error: " << strerror(errno) << std::endl;
        return 1;
    }
    if (data.size() == 0) {
        std::cout << "Error: empty file" << std::endl;
        return 0;
    }
    data.erase(std::remove(data.begin(), data.end(), '\n'), data.end());
    data.erase(std::remove(data.begin(), data.end(), '\t'), data.end());
    data.erase(std::remove(data.begin(), data.end(), ' '), data.end());
    f.close();

    Brainfuck brfk;

    if (brfk.compile(data) == false) {
        return (1);
    }
    if (brfk.decodePrgm() == false) {
        return (1);
    }

    return 0;
}
