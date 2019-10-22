#include "Array.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

int main()
{
    Array<int> arr(10);

    arr[3] = 12;
    std::cout << arr[3] << std::endl;

    try {
        std::cout << arr[10] << std::endl;  // out of range
    }
    catch (std::out_of_range &e) {
        std::cout << "[ERROR]: " << e.what() << std::endl;
    }

    Array<int> arr2 = arr;
    arr2[3] = 42;
    std::cout << " arr[3]: " << arr[3] << std::endl;
    std::cout << "arr2[3]: " << arr2[3] << std::endl;

    Array<std::string> arr3(40);
    arr3[4] = "test";
    std::cout << "arr3[4]: " << arr3[4] << std::endl;

    return 0;
}
