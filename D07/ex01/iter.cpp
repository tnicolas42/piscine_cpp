#include <iostream>

void square(int &i);

template<typename Arr, typename Func>
void iter(Arr *arr, size_t size, Func func) {
    for (size_t i=0; i < size; i++) {
        func(arr[i]);
    }
}

void square(int &i) {
    i = i * i;
}

template<typename T>
void print(T const &toPrint) {
    std::cout << toPrint << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t sz = sizeof(arr) / sizeof(arr[0]);

    std::cout << "print" << std::endl;
    iter(arr, sz, &print<int>);
    std::cout << "square" << std::endl;
    iter(arr, sz, &square);
    std::cout << "print" << std::endl;
    iter(arr, sz, &print<int>);

    return 0;
}
