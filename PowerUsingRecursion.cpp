#include <iostream>
using namespace std;

int calculatePower(int base, int powerRaised);

int main() {
    int base, powerRaised, result;

    cout << "Enter base number: ";
    cin >> base;

    cout << "Enter power number (positive integer): ";
    cin >> powerRaised;

    // Input validation for positive integers
    if (powerRaised < 0) {
        cout << "Power raised should be a non-negative integer." << endl;
        return 1; // Exit the program with an error code
    }

    result = calculatePower(base, powerRaised);
    cout << base << "^" << powerRaised << " = " << result << endl;

    return 0;
}

int calculatePower(int base, int powerRaised) {
    if (powerRaised != 0)
        return (base * calculatePower(base, powerRaised - 1));
    else
        return 1; // Base case: any number to the power of 0 is 1
}
