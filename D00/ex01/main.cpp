#include "PhoneContact.hpp"
#include <iostream>
#include <string>

#define C_ADD "ADD"
#define C_SEARCH "SEARCH"
#define C_EXIT "EXIT"

#define MAX_CONTACT 8

void add(PhoneContact (&contacts)[MAX_CONTACT]) {
    bool err = true;
    for(int i=0; i < MAX_CONTACT; i++) {
        if (!contacts[i].isInit()) {
            contacts[i].init();
            err = false;
            break;
        }
    }
    if (err) {
        std::cout << "Can't add contacts (already " << MAX_CONTACT << ")" << std::endl;
    }
}

void search(PhoneContact (&contacts)[MAX_CONTACT]) {
    if (!contacts[0].isInit()) {
        std::cout << "No contacts" <<std::endl;
        return;
    }
    std::cout << "*----------*----------*----------*----------*" << std::endl;
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "*----------*----------*----------*----------*" << std::endl;
    for(int i=0; i < MAX_CONTACT; i++) {
        if (contacts[i].isInit()) {
            contacts[i].displayCompact();
        }
    }
    std::cout << "*----------*----------*----------*----------*" << std::endl;

    std::string indexStr;
    std::cout << "Show index: ";
    std::cin >> indexStr;
    bool err = false;
    for (uint32_t i=0; i < indexStr.size(); i++) {
        if (!isnumber(indexStr[i]) || i > 3) {
            err = true;
            break;
        }
    }
    if (err) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    int index = std::stoi(indexStr);
    if (index < 0 || index >= MAX_CONTACT || !contacts[index].isInit()) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    contacts[index].display();
}

bool run(PhoneContact (&contacts)[MAX_CONTACT]) {
    std::string command;
    std::cout << "command (" << C_ADD << "|" << C_SEARCH << "|" << C_EXIT << "): ";
    std::cin >> command;
    if (command == C_ADD) {
        add(contacts);
    }
    else if (command == C_SEARCH) {
        search(contacts);
    }
    else if (command == C_EXIT) {
        return false;
    }
    else {
        std::cout << "Invalid command: " << command << std::endl;
    }
    return true;
}

void loop() {
    PhoneContact contacts[MAX_CONTACT];
    while (run(contacts));
}

int main(int ac, char **av) {
    (void)ac;
    (void)av;

    loop();
    return 0;
}