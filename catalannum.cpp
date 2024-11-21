#include <iostream>
#include <vector>

using namespace std;

// Function to compute factorial
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to generate the first n Catalan numbers
vector<unsigned long long> generateCatalanNumbers(int n) {
    vector<unsigned long long> catalan(n);
    
    for (int i = 0; i < n; ++i) {
        // C(n) = (2n)! / ((n + 1)! * n!)
        catalan[i] = factorial(2 * i) / (factorial(i + 1) * factorial(i));
    }
    
    return catalan;
}

int main() {
    int n;
    cout << "Enter the number of Catalan numbers to generate: ";
    cin >> n;

    vector<unsigned long long> catalanNumbers = generateCatalanNumbers(n);
    
    cout << "The first " << n << " Catalan numbers are:\n";
    for (int i = 0; i < n; ++i) {
        cout << "C(" << i << ") = " << catalanNumbers[i] << endl;
    }

    return 0;
}
