#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    FragTrap frag("fragPlayer");
    ScavTrap scav("scavPlayer");
    frag.rangedAttack("target");
    scav.rangedAttack("target");
    frag.meleeAttack("target");
    scav.meleeAttack("target");
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
    return 0;
}