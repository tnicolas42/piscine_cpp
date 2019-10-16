#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    FragTrap frag("fragPlayer");
    frag.rangedAttack("target");
    frag.meleeAttack("target");
    frag.takedamage(30);
    frag.beRepaired(5);
    frag.vaulthunter_dot_exe("target");
    frag.vaulthunter_dot_exe("target");
    frag.vaulthunter_dot_exe("target");
    frag.vaulthunter_dot_exe("target");
    frag.vaulthunter_dot_exe("target");
    frag.vaulthunter_dot_exe("target");
    ScavTrap scav("scavPlayer");
    scav.rangedAttack("target");
    scav.meleeAttack("target");
    scav.takedamage(30);
    scav.beRepaired(5);
    scav.challengeNewcomer();
    scav.challengeNewcomer();
    scav.challengeNewcomer();
    scav.challengeNewcomer();
    scav.challengeNewcomer();
    scav.challengeNewcomer();
    return 0;
}