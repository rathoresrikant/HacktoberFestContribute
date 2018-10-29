//JAI MATA DI
//LETS ROCK 

#include<bits/stdc++.h>
using namespace std;


#define ll long long int

// to sort on the basis of second value in descending order
/*bool cmp(const pair<ll,pair<int,int>> &a, const pair<int,pair<int,int>> &b){


       if(a.second!=b.second)
          return a.second<b.second;

       else 
          return a.first<b.first;

}*/

#define watch(x) cout << (#x) << " is " << (x) << endl

   int main()
{
    cin.tie(0);
    cout.tie(0);
    
     int n;
     cin>>n;
     
     int arr[n];
     
     for(int i=0;i<n;i++)
        cin>>arr[i];
     
     
     sort(arr,arr+n);
     
     cout<<arr[n-1]<<" "<<arr[n-2]<<"\n";
     
     
     
}
