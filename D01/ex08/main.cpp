#include "Human.hpp"

int main(int ac, char **av) {
    (void)ac;
    (void)av;

    Human human;
    human.action("meleeAttack", "otherHuman");
    return 0;
}