#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    ISpaceMarine *bob = new TacticalMarine;
    ISpaceMarine *jim = new AssaultTerminator;

    ISquad *vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i=0; i < vlc->getCount(); ++i) {
        ISpaceMarine *cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete vlc;
    return 0;
}