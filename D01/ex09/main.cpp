#include "Logger.hpp"
#include <iostream>

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    Logger log("test.log");
    log.log("file", "this is an info logging message in a file");
    log.log("console", "this is an info logging message in the console");
    log.log("both", "this is an info logging message in the console and in a file");

    return 0;
}