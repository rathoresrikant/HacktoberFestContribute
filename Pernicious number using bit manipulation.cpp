#include <iostream>
using namespace std;

bool isPernicious(int num) {
    int count = 0;
    while (num > 0) {
        count += (num & 1);
        num >>= 1;
    }
    return (count % 2 == 0);
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;
    if (number <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }
    if (isPernicious(number)) {
        cout << number << " is a pernicious number." << endl;
    } else {
        cout << number << " is not a pernicious number." << endl;
    }
    return 0;
}
