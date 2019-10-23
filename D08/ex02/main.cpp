#include "Mutantstack.hpp"
#include <iostream>

int main()
{
    Mutantstack<int> stack;

    stack.push(5);
    stack.push(17);

    std::cout << stack.top() << std::endl;

    stack.pop();
    std::cout << stack.size() << std::endl;
    stack.pop();
    std::cout << stack.size() << std::endl;

    for (int i=0; i < 15; i++) {
        stack.push(1<<i);
    }

    Mutantstack<int>::iterator it = stack.begin();
    Mutantstack<int>::const_iterator ite = stack.end();

    ++it;
    --it;
    std::cout << "iterate on the stack" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(stack);

    return 0;
}
