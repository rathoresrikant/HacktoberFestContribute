#include<stdio.h>

void array_rev(int a[], int n){
    int b[n];
    for(int i=0;i<n;i++){
        b[n-1-i] = a[i];        	
    }
    for(int i=0;i<n;i++){
        a[i] = b[i];        	
    }
}

void main(){
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);    
    array_rev(a, n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
