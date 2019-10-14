#include <iostream>
#include <string>

int main(int ac, char **av) {
    // get string
    std::string s = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    if (ac > 1) {
        s = "";
        for (int i=1; i < ac; i++){
            s += av[i];
        }
    }

    // uppercase
    for (uint32_t i=0; i < s.length(); i++) {
        if (isalpha(s[i]) && islower(s[i])) {
            s[i] = s[i]  + 'A' - 'a';
        }
    }

    // print output
    std::cout << s << std::endl;

    return (0);
}