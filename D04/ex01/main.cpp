#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    Character *zaz = new Character("zaz");
    std::cout << *zaz;

    Enemy *b = new RadScorpion();

    AWeapon *pr = new PlasmaRifle();
    AWeapon *pf = new PowerFist();

    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);

    zaz->attack(b);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    zaz->attack(b);
    zaz->attack(b);
    zaz->attack(b);
    zaz->attack(b);
    zaz->attack(b);
    std::cout << *zaz;

    return 0;
}