// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/long-jump-1-7d02705a/description/
// Medium
// Complexity : O(nLogn) try
// better than O(n^2) but worst than O(nlogn)

#include<bits/stdc++.h>
using namespace std;

int bruteForce(vector<int>& A, int K) {
    vector<int>len(A.size(), 1);
    for(int i = 0; i < A.size(); i++) {
        for(int j = i+1; j < A.size(); j++) {
            if(A[j] - A[i] >= K) { len[j] = max(len[j], len[i]+1); }
        }
    }
    int result = 0;
    for(int x : len) result = max(result, x);
    return result;
}

void binarySearch(int start, int end, vector<int>& maxLen, int X, int K)
{
    for(int i = start; i <= end; i++) {
        if(X - maxLen[i] >= K) {
            if(maxLen[i+1] >= X) {
                maxLen[i+1] = X;
                break;
            }
        }
    }
}

int optimalSolution(vector<int>& arr, int K) {

    vector<int>maxLen(arr.size(), 0);
    int size = -1;

    for(int i = 0; i < arr.size(); i++) {
        // If the value is the first element or valid greater than the last element
        if(size == -1 || arr[i]-maxLen[size] >= K) {
            maxLen[++size] = arr[i];
        }
        // If the value is smaller than the first element
        else if(arr[i] <= maxLen[0]) { maxLen[0] = arr[i]; }
        // Place the value somewhere in between O(logn) try
        // worked with O(n)
        else {
            binarySearch(0, size, maxLen, arr[i], K);
        }
    }
    
    return size+1;
}

int KJump (vector<int>& A, int K) {
    // Returns the length of longest subsequence
    return optimalSolution(A, K);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int K;
    cin >> K;
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++) {
    	cin >> A[i_A];
    }

    int out_;
    out_ = KJump(A, K);
    cout << out_;
}