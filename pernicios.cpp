#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if(n<2) return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0) return false;
    }
    return true; 
}
 
void printPernicious(int n) 
{ 
    int count = 0;
    int i = 2;
    while(count < n){
        if(isprime(__builtin_popcount(i))){
            cout << i << " ";
            count++;
        }
        i++;
    }
} 

int main(){
    int n;
    cout << "Enter n: " ;
    cin >> n;
    printPernicious(n);
}