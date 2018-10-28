#include<iostream>
#include<string.h>
#include<stack>			//Use Standard template library to create Stack data structure 
using namespace std;
 
void Reverse(char *p);
 
int main()
{
	char string[] = "www.firmcodes.com";
	
	Reverse(string);
	
	printf(" %s",string);	
	
	return 0;
}
 
void Reverse(char *p)
{
	stack<char> S;
	
	/* Pushing to stack */
	for(int i=0; i<strlen(p); i++)		
				S.push(p[i]);
	
	/* Poping from stack */			
	for(int i=0; i<strlen(p); i++)
	{
		p[i] = S.top();
		S.pop();
	}
}