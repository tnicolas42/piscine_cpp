#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T &container, int search) {
    return std::find(container.begin(), container.end(), search);
}

template<typename T>
void easyFindPrint(T &container, int search) {
    typename T::iterator it = easyfind<T>(container, search);

    if (it != container.end()) {
        std::cout << "found: " << *it << std::endl;
    }
    else {
        std::cout << "value " << search << " not found" << std::endl;
    }
}
