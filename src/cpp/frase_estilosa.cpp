#include <iostream>
using namespace std;

int whoWins (string string1, string string2) {
    if (string1.length() < string2.length())
        return 1;
    else if (string1.length() > string2.length())
        return -1;
    else {
        int r = string2.compare(string1);
        if (r < 0)
            return -1;
        else if (r > 0)
            return 1;
        else 
            return 0;
    }
}

int main () {
    int n;
    cin >> n;

    string p1 [n];
    string p2 [n];
    for (int c = 0; c < n; c++)
        cin >> p1[c];
    for (int c = 0; c < n; c++)
        cin >> p2[c];

    int result = 0;
    for (int c = 0; c < n; c++){
        result += whoWins(p1[c], p2[c]);
    }

    if (result > 0)
        cout << "1" << endl;
    else if (result < 0) 
        cout << "2" << endl;
    else
        cout << "empate" << endl;
    
    return 0;
}
