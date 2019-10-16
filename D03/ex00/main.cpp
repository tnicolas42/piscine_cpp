#include "FragTrap.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    FragTrap frag("name");
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
    return 0;
}