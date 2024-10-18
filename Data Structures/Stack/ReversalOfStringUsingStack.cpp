#include <iostream>
#include <stack> // including stack library
using namespace std;

int main() {
    string a; // initialize a string a
    cout << "Enter a string: ";
    getline(cin, a); // read the entire line including spaces

    stack<char> b; // initialize a stack named b

    // Push every character of the string into the stack
    for (long long int i = 0; i < a.length(); i++) {
        b.push(a[i]);
    }

    // Pop characters from the stack to print them in reverse order
    while (!b.empty()) { // ensure the stack is not empty
        cout << b.top(); // print the top character
        b.pop(); // pop the top character
    }
    
    cout << endl; // print a newline at the end
    return 0; // return 0 to indicate successful execution
}
