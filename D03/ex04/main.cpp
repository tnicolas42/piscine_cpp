#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    // create NinjaTrap
    std::cout << "/* init */" << std::endl;
    std::cout << "// create FragTrap (parent = ClapTrap)" << std::endl;
    FragTrap frag2("frag player");
    std::cout << "// create ScavTrap (parent = ClapTrap)" << std::endl;
    ScavTrap scav("scav player");
    std::cout << "// create NinjaTrap (parent = ClapTrap)" << std::endl;
    NinjaTrap ninja("ninja player");
    std::cout << "// create SuperTrap (parents = NinjaTrap & FragTrap)" << std::endl;
    SuperTrap super("super player");

    std::cout << std::endl;
    FragTrap frag = frag2;

    std::cout << std::endl;
    std::cout << "/* attack */" << std::endl;
    std::cout << "// attack on real target" << std::endl;
    super.ninjaShoebox(scav);
    ninja.ninjaShoebox(scav);
    super.ninjaShoebox(ninja);
    super.ninjaShoebox(super);
    super.ninjaShoebox(frag);
    super.ninjaShoebox(ninja);
    super.ninjaShoebox(ninja);
    super.ninjaShoebox(scav);
    scav.beRepaired(30);
    std::cout << "// useless attacks" << std::endl;
    scav.rangedAttack("target");
    frag.meleeAttack("target");
    super.vaulthunter_dot_exe("target");
    frag.vaulthunter_dot_exe("target");
    scav.challengeNewcomer();

    std::cout << std::endl;
    std::cout << "/* delete */" << std::endl;
    std::cout << "// auto delete of all objects" << std::endl;
    return 0;
}