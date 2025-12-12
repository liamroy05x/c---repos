#include <iostream>
#include <string>
#include <algorithm>

std::string parse_input(const std::string& user_input) {
    std::string s = user_input;

    s.erase(0, s.find_first_not_of(" \t\n\r"));
    if (!s.empty()) s.erase(s.find_last_not_of(" \t\n\r") + 1);

    if (s.empty()) return "unknown";

    if (s.size() >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        return "hex";

    for (char c : s) {
        if (std::string("abcdefABCDEF").find(c) != std::string::npos)
            return "hex";
    }

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

std::string convert_to_binary(const std::string& value, const std::string& value_type) {
    try {
        unsigned long long number = 0;

        if (value_type == "decimal") {
            number = std::stoull(value, nullptr, 10);
        } else if (value_type == "hex") {
            std::string s = value;
            if (s.size() >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
                s = s.substr(2);
            number = std::stoull(s, nullptr, 16);
        } else {
            return "";
        }

        if (number == 0) return "0";

        std::string binary;
        while (number > 0) {
            binary.push_back((number % 2) ? '1' : '0');
            number /= 2;
        }
        std::reverse(binary.begin(), binary.end());
        return binary;
    } catch (...) {
        return "";
    }
}

int main() {
    std::cout << "converter.cpp is running\n";
    std::cout << "Enter a decimal or hexadecimal number: ";

    std::string user_input;
    std::getline(std::cin, user_input);

    std::string input_type = parse_input(user_input);
    std::string binary = convert_to_binary(user_input, input_type);

    if (binary.empty()) {
        std::cout << "Invalid input. Please enter a valid decimal or hexadecimal number.\n";
    } else {
        std::cout << "Binary: " << binary << "\n";
    }

    return 0;
}
