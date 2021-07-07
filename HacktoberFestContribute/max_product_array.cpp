//This is the source code two find the two elements in an array that have the maximum product
#include <bits/stdc++.h>

using namespace std;

int main(){
    int tam, aux;
    vector <int> v;
    printf("Select your array size: ");
    scanf("%d", &tam);
    printf("Now insert the elements of your array:\n");
    for(int i = 1; i <= tam; i++){
        scanf("%d", &aux);
        v.push_back(aux);
    }
    //sorting the array
    sort(v.begin(), v.end());
    printf("The two elements of your array with maximum product are %d and %d\n", v[v.size()-2], v[v.size()-1]);
    return 0;
}
