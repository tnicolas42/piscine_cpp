#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    ZombieEvent type1 = ZombieEvent();
    ZombieEvent type2 = ZombieEvent();

    type1.setZombieType("type01");
    Zombie *new1 = type1.randomChump();
    type2.setZombieType("type02");
    Zombie *new2 = type2.randomChump();
    Zombie *new3 = type1.randomChump();
    type1.setZombieType("type03");
    Zombie *new4 = type1.newZombie("my name");

    delete new1;
    delete new2;
    delete new3;
    delete new4;
    return 0;
}