// Sorting using rank sort algorithm
#include <bits/stdc++.h> 

using namespace std; 
  
// Function to find the rank of each element
void rankify(int* A , int n) { 

    // Rank Vector 
    float R[n] = {0}; 
      
    // Checking every element to calculate their rank
    for (int i = 0; i < n; i++){
        int r = 1, s = 1;
        
        for (int j = 0; j < n; j++){
            if(j != i && A[j] < A[i])
                r += 1;
            if(j != i && A[j] == A[i])
                s += 1;
        }
         
        // Calculation of Rank
        R[i] = r+(float)(s-1)/(float)2;
    
    }
      
    for (int i = 0; i < n; i++)
    {
        cout << R[i] << ' ';
    }
    }
    
// Main function to check the sorting algorithm
int main() { 
    int arr[] = {10, 23, 11, 24, 0, 5, 19};

    int len = sizeof(arr) / sizeof(arr[0]); 
    int i = 0;

    for (i; i < len; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
      
    rankify(arr, len);
    
    return 0; 
} 
