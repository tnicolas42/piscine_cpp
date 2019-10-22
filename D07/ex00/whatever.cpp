#include <iostream>

template<typename T>
void swap(T &swap1, T &swap2) {
    T tmp = swap1;
    swap1 = swap2;
    swap2 = tmp;
}

template<typename T>
T const &min(T const &n1, T const &n2) {
    return (n1 < n2) ? n1 : n2;
}

template<typename T>
T const &max(T const &n1, T const &n2) {
    return (n1 > n2) ? n1 : n2;
}

int main()
{
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}
