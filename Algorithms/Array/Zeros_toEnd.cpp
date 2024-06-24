#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]!=0){
            b[j] = a[i];
            j++;
        }
    }
    int i = 0;
    while(i<j){
        a[i] = b[i];
        i++;
    }
    while(i<n){
        a[i] = 0;
        i++;
    }
    i = 0;
    while (i < n)
    {
        cout<<a[i] <<" ";
        i++;
    }
    return 0;
}