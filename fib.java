#include <iostream>
#include <vector>

using namespace std;

void fibonacciBottomUp(int n) {
    // Create a vector to store Fibonacci numbers
    vector<int> fib(n + 1);

    // Base cases
    fib[0] = 0; // F(0)
    fib[1] = 1; // F(1)

    // Fill the vector using the bottom-up approach
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print the Fibonacci series
    cout << "Fibonacci series up to " << n << ": ";
    for (int i = 0; i <= n; ++i) {
        cout << fib[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    fibonacciBottomUp(n);

    return 0;
}
