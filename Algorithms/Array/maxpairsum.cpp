#include<bits/stdc++.h>
using namespace std;

int main(){

	int A[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,3,27,9,81,243,729,8,7};
	int n = sizeof(A)/sizeof(int);
	int sum = 0, index1 = 0, index2 = 1;
	int max = A[0] + A[1];

	for(int i=1; i<n; i++){
		for(int j=i+1; j<n; j++){
			sum = A[i]	+ A[j];
			if(sum>max){
				max = sum;
				index1 = i;
				index2 = j;
			}
		}
	}

	cout<<"The maximum pair sum is "<<max<<" at index "<<i<<" and "<<j<<endl;
	return 0;
}
