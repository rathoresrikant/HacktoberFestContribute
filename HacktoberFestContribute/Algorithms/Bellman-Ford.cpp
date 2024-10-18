#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    cout << "Insert numbers (-999 to close the input)" << endl;
    int x;
    cin >> x;
    
    // Input loop to take numbers until -999 is entered
    while (x != -999) {
        v.push_back(x);
        cin >> x;
    }

    // Separate numbers and zeroes into two vectors
    vector<int> zeroes;
    vector<int> numbers;
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0)
            zeroes.push_back(v[i]);  // Collect zeroes
        else
            numbers.push_back(v[i]); // Collect non-zero numbers
    }

    // Clear the original vector v
    v.clear();
    
    // Push all non-zero numbers first
    for (int i = 0; i < numbers.size(); i++) {
        v.push_back(numbers[i]);
    }

    // Then push all zeroes
    for (int i = 0; i < zeroes.size(); i++) {
        v.push_back(zeroes[i]);
    }

    // Output the modified vector
    cout << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}
