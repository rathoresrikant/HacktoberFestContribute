#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int main(){
	int n;
	vector<int> array;
	vector<int> exit;
	
	cin >> n;
	
	
	for(int i = 0; i < n; i++) {
		int c;
		cin >> c;
		array.push_back(c);
		}
	
	int i,j; 
	
	i = 0;
	j = n-1;
	
	while(i < j) {
		exit.push_back(array[i] * array[j]);
		i++;
		j--;
	}
	
	sort(exit.begin(), exit.end());
		
	for(int x: exit)
		cout << x << " ";
	return 0;
}    
