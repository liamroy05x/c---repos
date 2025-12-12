#include <iostream>
#include <string>

std::string parse_input(const std::string& user_input) {
    std::string s = user_input;

    // trim whitespace
    s.erase(0, s.find_first_not_of(" \t\n\r"));
    if (!s.empty()) s.erase(s.find_last_not_of(" \t\n\r") + 1);

    if (s.empty()) return "unknown";

    // detect hex prefix
    if (s.size() >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        return "hex";

    // detect hex characters
    for (char c : s) {
        if (std::string("abcdefABCDEF").find(c) != std::string::npos)
            return "hex";
    }

    // try decimal, then hex
    try {
        std::stoll(s, nullptr, 10);
        return "decimal";
    } catch (...) {
        try {
            std::stoll(s, nullptr, 16);
            return "hex";
        } catch (...) {
            return "unknown";
        }
    }
}

// stub for now
std::string convert_to_binary(const std::string& value, const std::string& value_type) {
    return "";
}

int main() {
    std::cout << "converter.cpp is running\n";
    std::cout << "Enter a decimal or hexadecimal number: ";

    std::string user_input;
    std::getline(std::cin, user_input);

    return 0;
}
