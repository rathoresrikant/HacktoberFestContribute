#include<iostream>
using namespace std;

int count=0;
int par(int A[ ],int p,int r)
{
    int x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        count++;
        if(A[j]<x)
        {
            i++;
            int temp=A[j];
            A[j]=A[i];
            A[i]=temp;
        }
    }
    int temp=A[r];
    A[r]=A[i+1];
    A[i+1]=temp;
    return i+1;
}

void quickSort(int A[ ],int p,int r)
{
    if(p<r)
    {
        int q=par(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}

int main()
{
    int n;
    cout<<"\tQuick-Sort:";
    do{
    cout<<"\n   Enter the number of element : ";
    cin>>n;
    int A[n];
    cout<<"Enter the element : ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    quickSort(A,0,n-1);
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<"\nCount : "<<count;
    }while(1);
}
