#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    while(n>0){
        v.push_back(n % 2);
        n /= 2;
    }
    int i = v.size() - 1;
    while(i>=0){
        cout << v[i];
        i--;
    }
    return 0;
}