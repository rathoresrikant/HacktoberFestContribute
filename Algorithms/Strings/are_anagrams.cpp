#include <iostream>
#include <algorithm>
#include <cctype>

bool is_anagram(std::string& first, std::string& second) {
    if (first.size() != second.size())
        return false;

    std::transform(first.begin(), first.end(), first.begin(), tolower);
    std::transform(second.begin(), second.end(), second.begin(), tolower);

    int count[255] = { 0 };
    for (auto c : first)
        count[static_cast<int>(c)]++;

    for (auto c : second) {
        if (!count[static_cast<int>(c)]) {
            return false;
        } else {
            count[static_cast<int>(c)]--;
        }
    }

    for (auto i : count) 
        if (i != 0) return false;

    return true;
}

int main() {
    std::string first, second;
    
    std::cout << "Enter the first string: ";
    std::cin >> first;
    std::cout << "Enter the second string: ";
    std::cin >> second;

    std::cout << "Result: " << is_anagram(first, second) << std::endl;
    return 0;
}

