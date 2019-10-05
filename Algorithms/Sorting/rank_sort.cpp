#include<iostream>
using namespace std;


void rankSort(int A[], int low, int high)
{
	float R[high] = {0}; 
	int B[high];
	for (int i = low; i < high; i++)
    { 
	    int r = 0; 
	      
	    for (int j = low; j < i; j++) 
	    { 
	        if (A[j] <= A[i]) 
	            r += 1;     
	    } 
        for (int j =i+1; j<high; j++)
        {
            if(A[j] < A[i])
                r +=1;
        }
	   	B[r] = A[i];
	   	
	}  


    cout<<"Sorted Array in increasing order is : \n";  
    for(int l = 0; l<high; l++)
    {
    	cout<<B[l]<<" ";
    }
    cout<<endl;
	
}


int main()  
{  
    int A[] = {6, 17, 45, 6,-9, 0};
    int n = sizeof(A) / sizeof(A[0]);
    rankSort(A,0, n);   
    return 0;  
}  
