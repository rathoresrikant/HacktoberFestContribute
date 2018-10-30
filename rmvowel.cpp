#include <bits/stdc++.h> 
using namespace std; 
bool is_vow(char c) 
{ 
	return (c == 'a') || (c == 'e') || 
		(c == 'i') || (c == 'o') || 
		(c == 'u'); 
} 

void removeVowels(string str) 
{ 
	printf("%c", str[0]); 

	for (int i = 1; str[i]; i++) 

		if ((!is_vow(str[i - 1])) || 
			(!is_vow(str[i]))) 
			printf("%c", str[i]); 
} 

int main() 
{ 
	char str[] = " boom is boom"; 
	removeVowels(str); 
} 

