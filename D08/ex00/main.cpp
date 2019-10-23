#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    int i1 = 42;
    int i2 = 30;
    std::vector<int> vec(10, 12);  // 10 elements at value 12
    vec[3] = 42;

    easyFindPrint< std::vector<int> >(vec, i1);
    easyFindPrint< std::vector<int> >(vec, i2);

    return 0;
}
