#include <iostream>
#include <string>

std::string parse_input(const std::string& user_input) {
    std::string s = user_input;

    // trim whitespace
    s.erase(0, s.find_first_not_of(" \t\n\r"));
    if (!s.empty()) {
        s.erase(s.find_last_not_of(" \t\n\r") + 1);
    }

    if (s.empty()) {
        return "unknown";
    }

    return "unknown";
}

int main() {
    std::cout << "converter.cpp is running\n";
    std::cout << "Enter a decimal or hexadecimal number: ";

    std::string user_input;
    std::getline(std::cin, user_input);

    return 0;
}
