#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int ans=INT_MIN,temp=0;
        
    for(int i=0 ; i<nums.size() ; i++){
        temp+=nums[i];
                        
        if(temp>ans)
           ans=temp;
            
        if(temp<0)
           temp=0;
        }
        return ans;
    }
    
    int main(){
    vecvtor<int> arr;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++) cin>>arr[i];
    
    cout<<maxSubArray(arr)<<endl;
    
    return 9;
    }
