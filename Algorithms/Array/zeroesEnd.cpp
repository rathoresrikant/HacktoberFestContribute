#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    cout << "Insert numbers (-999 close number)" << endl;
    int x;
    cin >> x;
    
    // Input loop
    while (x != -999) {
        v.push_back(x);
        cin >> x;
    }

    vector<int> result;

    // First, add non-zero elements
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            result.push_back(v[i]);
        }
    }

    // Then, add all the zero elements
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            result.push_back(v[i]);
        }
    }

    // Print the result vector
    cout << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
