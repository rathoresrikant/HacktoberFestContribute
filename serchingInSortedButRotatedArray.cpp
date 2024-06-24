// given an array which is sorted and rotated you needs
// find out particular elements
// eg. a[]={4,5,1,2,3} searching of k=2;

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int searchInRotatedArray(int arr[],int start,int end,int key){

    if(start>end){
        return -1;
    }

    int mid=start+(end-start)/2;

    if(arr[mid]==key){
        return mid;
    }

    // mid lie in first part
    if(arr[start]<=arr[mid]){
        if(key>arr[start] && key<arr[mid]){
            return searchInRotatedArray(arr,start,mid-1,key);
        }
        else{
            return searchInRotatedArray(arr,mid+1,end,key);
        }
    }

    if(key>=arr[mid] && key<=arr[end]){
        return searchInRotatedArray(arr,mid+1,end,key);
    }

    return searchInRotatedArray(arr,start,mid-1,key);

}

int main(){

  int arr[]={5,6,7,8,9,1,2,2,2,3,4,4,4};
  int n=13;
  int key;
  cin>>key;

  cout<<searchInRotatedArray(arr,0,n-1,key);


}
