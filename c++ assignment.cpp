#include <iostream>
#include <string>

int main() {
    std::cout << "converter.cpp is running\n";
    std::cout << "Enter a decimal or hexadecimal number: ";

    std::string user_input;
    std::getline(std::cin, user_input);

    return 0;
}
