// One Solution is to first sort the array and find the longest subarray with consecutive elements. Time complexity of this solution is O(nLogn)
// We can solve this problem in O(n) time using an Efficient Solution. The idea is to use Hashing. We first insert all elements in a Set. Then check all the possible starts of consecutive subsequences
#include<unordered_map>

vector<int> longestSubsequence(int *arr, int n){

    unordered_map<int,bool> mapp;
    
    for (int i=0;i<n;i++)
    {
        mapp[arr[i]]=true;
    }
    
    int maxLen=0;
    int sE;
    
    for(int i=0;i<n;i++)
    {
        int len=0;
        int key=arr[i];
        int temp=arr[i];
        while(mapp[temp]==true){
            len++;
            temp++;
        }
        
        
        if(len>maxLen){
            maxLen=len;
            sE=key;
        }
        
    }
    
    
    vector<int> v;
    for(int i=0;i<maxLen;i++){
        v.push_back(sE++);
    }
    
    return v;
}