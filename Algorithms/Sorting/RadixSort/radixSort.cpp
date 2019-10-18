#include <bits/stdc++.h>
using namespace std;

int getMaxElement(int arr[], int n){
	int mm;
	mm = arr[0];
	for (int i = 1; i < n; i++){
		mm = max(mm, arr[i]);
	}
	return mm;
}

void countSort(int arr[], int n, int rem){
	int out[n] = {};
	int count[10] = {};
	
	for (int i = 0; i < n; i++) count[ (arr[i]/rem)%10 ]++;

	for (int i = 1; i < 10; i++) count[i] += count[i-1];
	
	for (int i = n - 1; i >= 0; i--){
		out[ count[(arr[i]/rem)%10] - 1 ] = arr[i];
		count[ (arr[i]/rem)%10 ]--;
	}
	
	for (int i = 0; i < n; i++) arr[i] = out[i];
}

void radix_sort(int arr[], int n) {
    int maxElement = getMaxElement(arr, n);

	for (int rem = 1; rem <= maxElement; rem *= 10){
		countSort(arr, n, rem);
	}
	
	return;
}

int main(void) {
    int a[] = { 10, 7, 9, 4, 6, 2, 5, 6, 84, 12};
    int a_size = sizeof(a)/sizeof(a[0]);

    radix_sort(a, a_size);

    for (auto ele : a) {
        cout << ele << " ";
    }
	cout << endl;
	
	return 0;
}
