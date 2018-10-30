// A simple C++ program to find max product pair in 
// an array of integers 
#include<bits/stdc++.h> 
using namespace std; 

// Function to find maximum product pair in arr[0..n-1] 
void maxProduct(int arr[], int n) 
{ 
	if (n < 2) 
	{ 
		cout << "No pairs exists\n"; 
		return; 
	} 

	// Initialize max product pair 
	int a = arr[0], b = arr[1]; 

	// Traverse through every possible pair 
	// and keep track of max product 
	for (int i=0; i<n; i++) 
	for (int j=i+1; j<n; j++) 
		if (arr[i]*arr[j] > a*b) 
			a = arr[i], b = arr[j]; 

	cout << "Max product pair is {" << a << ", "
		<< b << "}"; 
} 

// Driver program to test 
int main() 
{ 
	int arr[] = {1, 4, 3, 6, 7, 0}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	maxProduct(arr, n); 
	return 0; 
} 

