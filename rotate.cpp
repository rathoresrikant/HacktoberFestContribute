#include <iostream>
#include <vector>
using namespace std;

// Function to display the matrix
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

// Function to rotate the matrix 90 degrees anticlockwise
void rotate90Anticlockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each column
    for (int j = 0; j < n; ++j) {
        for (int i = 0, k = n - 1; i < k; ++i, --k) {
            swap(matrix[i][j], matrix[k][j]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    displayMatrix(matrix);

    rotate90Anticlockwise(matrix);

    cout << "\nMatrix after 90-degree Anticlockwise Rotation:\n";
    displayMatrix(matrix);

    return 0;
}
