#include "Span.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(static_cast<uint32_t>(time(NULL)));
    Span sp(1000);

    for (std::vector<int>::iterator it=sp.getArray().begin(); it != sp.getArray().end(); it++) {
        sp.addNumber(rand());
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}
