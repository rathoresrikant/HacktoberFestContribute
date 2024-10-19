#include <bits/stdc++.h>
using namespace std;

int binarySearch(int start, int end, vector<int>& maxLen, int value, int K) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (value - maxLen[mid] >= K) {
            if (mid + 1 <= end && maxLen[mid + 1] >= value) {
                maxLen[mid + 1] = value;
                return mid + 1;
            }
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start;
}

int optimalSolution(vector<int>& arr, int K) {
    vector<int> maxLen(arr.size(), INT_MAX);
    int size = 0;

    for (int value : arr) {
        if (size == 0 || value - maxLen[size - 1] >= K) {
            maxLen[size++] = value;
        } else {
            int pos = binarySearch(0, size - 1, maxLen, value, K);
            maxLen[pos] = value;
        }
    }
    
    return size;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, N;
    cin >> K >> N;
    vector<int> A(N);
    for (int& a : A) {
        cin >> a;
    }

    cout << optimalSolution(A, K) << '\n';
    return 0;
}
