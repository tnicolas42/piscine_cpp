#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    Sorcerer robert("Robert", "the Magnificent");

    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << robert << jim << joe;

    robert.polymorph(jim);
    robert.polymorph(joe);

    return 0;
}