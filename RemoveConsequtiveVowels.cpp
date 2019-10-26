#include <bits/stdc++.h> 
using namespace std; 

// function which returns True or False 
// for occurrence of a vowel 
bool is_vow(char c) 
{ 
	// this compares vowel with 
	// character 'c' 
	return (c == 'a') || (c == 'e') || 
		(c == 'i') || (c == 'o') || 
		(c == 'u'); 
} 

// function to print resultant string 
void removeVowels(string str) 
{ 
	// print 1st character 
	printf("%c", str[0]); 

	// loop to check for each character 
	for (int i = 1; str[i]; i++) 

		// comparison of consecutive characters 
		if ((!is_vow(str[i - 1])) || 
			(!is_vow(str[i]))) 
			printf("%c", str[i]); 
} 

// Driver Code 
int main() 
{ 
	char str[] = "Chaaaaangeeeeee Meeeeee!!"; 
	removeVowels(str); 
} 
