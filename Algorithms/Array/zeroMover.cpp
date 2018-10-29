// Program to move zeroes in the end
#include <iostream>
using namespace std;

// Function to move zero to end
void zeroMover(int a[], int n){
    int count = 0;  // Count of non-zero elements 
  
    for (int i = 0; i < n; i++) 
        if (arr[i] != 0) 
            arr[count++] = arr[i]; 

    while (count < n) 
        arr[count++] = 0;
}

//Driver Program
int main() {
	int arr[] = {11,0,0,3,4,0,56,23};
	int n = sizeof(arr)/sizeof(arr[0]);
	zeroMover(arr, n);
	
	for(int i = 0; i<n; i++)
	    cout<<arr{i]<<" ";
    return 0;
}
