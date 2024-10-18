#include <iostream>
using namespace std;

int countSquareMatrices(int rows, int cols) {
    int count = 0;

    // Iterate through all possible sizes of square matrices
    for (int size = 1; size <= min(rows, cols); size++) {
        // Calculate the number of positions for this size
        int positions = (rows - size + 1) * (cols - size + 1);
        count += positions;
    }

    return count;
}

int main() {
    int rows, cols;

    // Input the dimensions of the rectangular matrix
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int result = countSquareMatrices(rows, cols);
    cout << "The number of square matrices in the rectangular matrix is: " << result << endl;

    return 0;
}
