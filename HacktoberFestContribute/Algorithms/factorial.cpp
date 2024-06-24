#include <iostream>
using namespace std;

int factorial1(int n) {
    if(n<0) {
        return -1;
    }
    
    if(n==0 || n==1) {
        return 1;
    }
    else {
        return factorial1(n-1)*n;
    }
}

int factorial2(int n) {
    int f = 1;
    for(int i=1;i<=n;i++) {
        f*=i;
    }
    return f;
}

int main() {
    int n;
    cin>>n;
    cout<<factorial1(n)<<endl;
    cout<<factorial2(n);
    return 0;
}
