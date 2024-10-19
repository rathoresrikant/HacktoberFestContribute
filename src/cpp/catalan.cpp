#include <iostream>
#include <vector>
using namespace std;

// Function to find the nth Catalan number using dynamic programming
unsigned long int catalan(unsigned int n) {
    // Create a table to store results of subproblems
    vector<unsigned long int> catalanTable(n + 1, 0);
    
    // Base case
    catalanTable[0] = 1;
    catalanTable[1] = 1;

    // Fill the catalanTable using previously calculated values
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalanTable[i] += catalanTable[j] * catalanTable[i - j - 1];
        }
    }

    return catalanTable[n];
}

// Driver program to test above function
int main() {
    unsigned int n;
    cout << "Enter the value of n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << catalan(i) << " ";
    }
    cout << endl;

    return 0;
}
