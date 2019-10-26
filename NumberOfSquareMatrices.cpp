#include<iostream> 
using namespace std; 

// Returns count of all squares 
// in a rectangle of size m x n 
int countSquares(int m, int n) 
{ 
// If n is smaller, swap m and n 
if (n < m) 
	swap(m, n); 

// Now n is greater dimension, 
// apply formula 
return m * (m + 1) * (2 * m + 1) / 
	6 + (n - m) * m *(m + 1) / 2; 
} 

// Driver Code 
int main() 
{ 
int m,n;
cin>>m>>n;
cout << "Count of squares is "<< countSquares(m, n); 
return 0;
} 
