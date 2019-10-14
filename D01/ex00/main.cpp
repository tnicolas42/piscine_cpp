#include "Pony.hpp"
#include <iostream>

Pony *ponyOnTheHeap(std::string name) {
    Pony *pony = new Pony(name);
    return pony;
}

Pony ponyOnTheStack(std::string name) {
    Pony pony = Pony(name);
    return pony;
}

int main(int ac, char**av) {
    (void)ac;
    (void)av;

    /* create pony */
    Pony p1 = ponyOnTheStack("stack");  // new pony: stack
    Pony *p2 = ponyOnTheHeap("heap");  // new pony: heap
    std::cout << std::endl;

    /* use pony */
    std::cout << "Hello " << p1.getName() << std::endl;
    std::cout << "Hello " << p2->getName() << std::endl;
    std::cout << std::endl;

    /* delete pony  */
    delete p2;  // heap died
    // stack pony is auto deleted at the end of the function
    return 0;  // stack died
}