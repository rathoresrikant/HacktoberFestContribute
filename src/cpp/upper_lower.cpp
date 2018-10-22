#include <iostream>

int main() {
    std::string input, lower, upper;

    std::cout << "Enter a string: ";
    std::cin >> input;

    for (auto c : input) {
        lower += tolower(c);
        upper += toupper(c);
    }

    std::cout << "\nLower string: " << lower << std::endl;
    std::cout << "Upper string: " << upper << std::endl;
    return 0;
}