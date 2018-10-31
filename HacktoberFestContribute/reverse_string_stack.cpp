#include <bits/stdc++.h>

using namespace std;

int main(){
    int length;
    char aux;
    stack <char> reversed;
    string s;
  
    printf("Insert your string:\n");
    cin >> s;
    length = s.length();
    for(int i = 0; i < length; i++){
        reversed.push(s[i]);  
    }
    printf("Your reversed string is:\n");
    while(!reversed.empty()){
        aux = reversed.top();
        printf("%c", aux);
        reversed.pop();
    }
    printf("\n");
    return 0;
}
