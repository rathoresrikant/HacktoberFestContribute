#include <iostream>
using namespace std;

int countSquareMatrices(int n, int m) {
    int totalSquares = 0;
    int maxSquareSize = min(n, m);
    for (int k = 1; k <= maxSquareSize; k++) {
        totalSquares += (n - k + 1) * (m - k + 1);
    }
    return totalSquares;
}

int main() {
    int n, m;
    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;
    int result = countSquareMatrices(n, m);
    cout << "Number of square submatrices: " << result << endl;
    return 0;
}
