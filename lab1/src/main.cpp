#include <iostream>
#include "remove_vowels.h"

int main() {
    std::string line;
    std::getline(std::cin, line); // читаем строку
    std::cout << remove_vowels(line) << std::endl;
    return 0;
}
