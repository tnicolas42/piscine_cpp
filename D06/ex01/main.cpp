#include <iostream>
#include <string>
#include <time.h>

struct Data {
    std::string s1;
    int         n;
    int         _;  // used for padding (-Wpadded)
    std::string s2;
};

void *serialize();
Data *deserialize(void *raw);

void *serialize() {
    Data *data = new Data();

    char randChars[9];
    randChars[8] = '\0';

    for (uint8_t i=0; i < 8; i++) {
        randChars[i] = rand() % 26 + 'a';
    }
    data->s1 = std::string(randChars);

    data->n = rand();

    for (uint8_t i=0; i < 8; i++) {
        randChars[i] = rand() % 26 + 'a';
    }
    data->s2 = std::string(randChars);

    std::cout << "Create struct:" << std::endl;
    std::cout << "\ts1: " << data->s1 << std::endl;
    std::cout << "\t n: " << data->n << std::endl;
    std::cout << "\ts2: " << data->s2 << std::endl;

    return reinterpret_cast<void*>(data);
}

Data *deserialize(void *raw) {
    Data *data = reinterpret_cast<Data*>(raw);
    return data;
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    srand(static_cast<uint32_t>(time(NULL)));

    void *rawData = serialize();
    Data *data = deserialize(rawData);

    std::cout << "Deserialized struct:" << std::endl;
    std::cout << "\ts1: " << data->s1 << std::endl;
    std::cout << "\t n: " << data->n << std::endl;
    std::cout << "\ts2: " << data->s2 << std::endl;

    std::cout << "pointer comparison:" << std::endl;
    std::cout << "\tvoid * " << rawData << std::endl;
    std::cout << "\tData * " << data << std::endl;
    return 0;
}
