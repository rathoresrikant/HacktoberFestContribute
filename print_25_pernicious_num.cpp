// program to print the first 25 pernicious numbers
// a pernicious number is a positive integer whose binary representation has a prime number of "ones" in it
// for example: 3 = 11 (in binary) has 2 "ones" making it the first pernicious number

#include<bits/stdc++.h>
using namespace std;

// function to check if a given number is prime.
bool prime(int n)
{
    if(n <= 1)
        return false;
    for(int i = 2; i<n;i++)
    {
        if(n%i == 0)
            return false;
        // a prime number is only divisible by 1 and the number itself
    }
    return true;
}

//driver function

int main() 
{
    int n = 25;
    for (int i=1,count=0; count < n; i++)
    { 
        // "__builtin_popcount(i)" count no of ones in binary representation 
        if (prime(__builtin_popcount(i)))
        // checks if the number of "ones" in binary representation of i is a prime
        { 
            cout << i << endl;       
            count++; 
        } 
    }

return 0;
}
