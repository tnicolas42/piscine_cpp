#include "Human.hpp"
#include <iostream>

Human::Human() {}

Human::~Human() {}

void Human::action(std::string const & action_name, std::string const & target) {
    static struct Action actions[] = {
        {"meleeAttack", &Human::meleeAttack},
        {"rangedAttack", &Human::rangedAttack},
        {"intimidatingShout", &Human::intimidatingShout}
    };
    static uint32_t sz = sizeof(actions) / sizeof(actions[0]);

    for (uint32_t i=0; i < sz; i++) {
        if (action_name == actions[i].name) {
            ((*this).*(actions[i].f))(target);
            return;
        }
    }
    std::cout << "invalid action for human" << std::endl;
}

void Human::meleeAttack(std::string const & target) {
    std::cout << "meleeAttack on " << target << std::endl;
}
void Human::rangedAttack(std::string const & target) {
    std::cout << "rangedAttack on " << target << std::endl;
}
void Human::intimidatingShout(std::string const & target) {
    std::cout << "rangedAttack on " << target << std::endl;
}