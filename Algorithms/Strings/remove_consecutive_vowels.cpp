#include <iostream>

bool is_vowel(char c) {
    return c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i';
}

int main() {
    std::string input, output;
    
    std::cout << "Enter a string: ";
    std::cin >> input;

    int i = 0;
    while (i < input.size()) {
        if (i < input.size() - 1 &&
            is_vowel(input[i]) && 
            is_vowel(input[i + 1])) {
            while (i < input.size() && is_vowel(input[i])) i++;
        }
            
        output += input[i];
        i++;
    }

    std::cout << "New string, which is deleted consecutive vowels: " << output << std::endl;
    return 0;
}
