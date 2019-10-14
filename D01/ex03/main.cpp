#include "ZombieHorde.hpp"
#include <iostream>

int main(int ac, char **av) {
    (void)ac;
    (void)av;

    // create the horde
    ZombieHorde horde(5);

    std::cout << "---" << std::endl;

    return 0;  // all the zombies are destroyed on the horde destructor
}