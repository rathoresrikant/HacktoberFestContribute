#include<bits/stdc++.h>

using namespace std;

void maxHeapify(int a[],int n,int index){
    int l,r,largest;
    l=(index+1)*2-1;
    r=(index+1)*2;

    if(l<n && a[l]>a[index]){
        largest=l;
    }
    else{
        largest=index;
    }

    if(r<n && a[r]>a[largest]){
        largest=r;
    }

    if(largest!=index){
        int temp=a[index];
        a[index]=a[largest];
        a[largest]=temp;

        maxHeapify(a,n,largest);
    }
}

void buildHeap(int a[],int n){
    for(int i=n/2;i>=0;i--){
        maxHeapify(a,n,i);
    }
}

int main(){
    int a[]={65,3,22,25,27,17,20,8,4};

    int n=sizeof(a)/sizeof(int);
    buildHeap(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
   return 0; 
}
