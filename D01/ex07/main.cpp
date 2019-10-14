#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av) {
    if (ac != 4) {
        std::cout << "Usage: ./ex07 file search replace" << std::endl;
        return 1;
    }
    std::ifstream fileIn(av[1]);
    if (fileIn.fail()) {
        std::cout << "Error: " << strerror(errno) << std::endl;
        return 1;
    }
    std::ofstream fileOut(std::string(av[1]) + ".replace");
    if (fileOut.fail()) {
        std::cout << "Error: " << strerror(errno) << std::endl;
        return 1;
    }
    std::string searchStr(av[2]);
    if (searchStr.size() == 0) {
        std::cout << "Error: search string is null" << std::endl;
        return 1;
    }
    std::string replaceStr(av[3]);

    for (std::string line; std::getline(fileIn, line);) {
        size_t index = 0;
        while (true) {
            index = line.find(searchStr, index);
            if (fileOut.fail()) {
                std::cout << "Error: " << strerror(errno) << std::endl;
                return 1;
            }
            if (index == std::string::npos) break;

            /* Make the replacement. */
            line.replace(index, searchStr.size(), replaceStr);

            /* Advance index forward so the next iteration doesn't pick it up as well. */
            index += replaceStr.size();
        }
        fileOut << line << std::endl;
    }
    fileIn.close();
    fileOut.close();
    return 0;
}