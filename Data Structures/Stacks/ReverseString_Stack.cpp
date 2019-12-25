#include<iostream>
#include<stack>

void reverse(char *str)
{
	std::stack<char> s;

	for (int i = 0; i < strlen(str); i++)
	{
		s.push(str[i]);
	}

	for (int i = 0; i<strlen(str); i++)
	{
		str[i] = s.top();
		s.pop();
	}	
}

int main()
{

	char c [] = "Hacktoberfest";
	reverse(c);
	std::cout << c; 

	return 0; 
}