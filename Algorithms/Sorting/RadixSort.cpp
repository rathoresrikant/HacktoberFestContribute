#include<iostream>
#include<queue>
using namespace std;

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
}

int getMin(int arr[], int n) {
    int min = INT16_MAX;
    for(int i = 0;i < n;i++) {
        if(min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int getMax(int arr[], int n) {
    int max = INT16_MIN;
    for(int i = 0;i < n;i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

void radixSortUsingQueueSTL(int arr[], int n) {
    queue<int> q[10];
    int max = getMax(arr, n);
    int maxDigits = 0;
    while(max > 0) {
        maxDigits++;
        max /= 10;
    }
    int currPow = 1;
    for(int i = 0;i < maxDigits;i++) {
        for(int j = 0;j < n;j++) {
            int currIdx = (arr[j] / currPow) % 10;
            q[currIdx].push(arr[j]);
        }
        int idx = 0;
        for(int j = 0;j < 10;j++) {
            while(!q[j].empty()) {
                arr[idx++] = q[j].front();
                q[j].pop();
            }
        }
        currPow *= 10;
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++) {
        cin>>arr[i];
    }
	radixSortUsingQueueSTL(arr, n);
    printArray(arr, n);
	return 0; 
} 
