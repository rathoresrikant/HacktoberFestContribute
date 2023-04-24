#include <iostream> 

using namespace std;

bool sameDiagonal(int c1, int c2, int c3, int c4) {
    return ((c1-c3)==(c2-c4)) or (c1+c2 == c3+c4);
}

bool sameLine(int c1, int c2, int c3, int c4) {
    return (c1==c3 and c2!=c4) or (c1!=c3 and c2==c4);
}

int main () {

    int c1,c2,c3,c4;

    cin >> c1 >> c2 >> c3 >> c4;

    if(c1 == c3 and c2 == c4) {
        cout << 0;
    } else if (sameLine(c1,c2,c3,c4) or sameDiagonal(c1,c2,c3,c4)) {
        cout << 1;
    } else {
        cout << 2;
    }
}
