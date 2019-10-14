#include <iostream>
#include <string>

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    std::string str = "HI THIS IS BRAIN";
    std::string *strPtr = &str;
    std::string &strRef = str;

    std::cout << "using pointer: " << *strPtr << std::endl;
    std::cout << "using reference: " << strRef << std::endl;

    return 0;
}