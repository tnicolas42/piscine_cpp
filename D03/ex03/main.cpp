#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::cout << "// init" << std::endl;
    FragTrap frag("fragPlayer");
    ScavTrap scav("scavPlayer");
    NinjaTrap ninja("ninjaPlayer");
    std::cout << "// attack" << std::endl;
    frag.rangedAttack("target");
    scav.rangedAttack("target");
    ninja.rangedAttack("target");
    frag.meleeAttack("target");
    scav.meleeAttack("target");
    ninja.meleeAttack("target");
    frag.takedamage(30);
    scav.takedamage(30);
    frag.beRepaired(5);
    scav.beRepaired(5);
    frag.vaulthunter_dot_exe("target");
    scav.challengeNewcomer();
    frag.vaulthunter_dot_exe("target");
    scav.challengeNewcomer();
    frag.vaulthunter_dot_exe("target");
    scav.challengeNewcomer();
    frag.vaulthunter_dot_exe("target");
    scav.challengeNewcomer();
    frag.vaulthunter_dot_exe("target");
    scav.challengeNewcomer();
    frag.vaulthunter_dot_exe("target");
    scav.challengeNewcomer();
    std::cout << "// ninja attack frag" << std::endl;
    ninja.ninjaShoebox(frag);
    std::cout << "// ninja attack scav" << std::endl;
    ninja.ninjaShoebox(scav);
    std::cout << "// delete" << std::endl;
    return 0;
}