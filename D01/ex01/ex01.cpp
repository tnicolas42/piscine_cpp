#include <iostream>
#include <string>

void memoryLeak() {
    std::string *panthere = new std::string("String panthere");

    std::cout << *panthere << std::endl;

    delete panthere;  // comment / uncomment this line to test
}

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    memoryLeak();
    // while (1);  // uncommetn this line and run `leaks ex01` to test
    return 0;
}