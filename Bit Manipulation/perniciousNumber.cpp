// CPP program to print first n pernicious numbers 
#include <bits/stdc++.h> 
using namespace std; 
  
// function to check prime number 
bool isPrime(int x) 
{ 
    if (x < 2) 
        return false; 
    for (int i = 2; i < x; i++) { 
        if (x % i == 0) 
            return false; 
    } 
    return true; 
} 
  
// Prints first n Pernicious numbers 
void printPernicious(int n) 
{ 
    for (int i=1,count=0; count<n; i++) { 
  
        // "__builtin_popcount(i)" count no 
        // of ones in binary representation 
        if (isPrime(__builtin_popcount(i))) { 
            cout << i << " "; 
              
            count++; 
        } 
    } 
} 
  
int main() 
{ 
   int n = 25; 
   printPernicious(n); 
   return 0; 
} 
