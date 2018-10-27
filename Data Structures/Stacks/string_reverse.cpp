#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100

char *stack;
int top;

void push (char c){
	
	top++;
	stack[top]=c;
	}

char pop(){
	
	top--;
	return stack[top];
	}
	

int main(){

	char *s;
	s=(char *)malloc(MAX_LEN*sizeof(char)); 
	int n;
	printf("Enter a string\n");
	scanf("%s",s);
	n =strlen(s)+1;
	stack= (char *)malloc(n*sizeof(char));
	for(int i=0;i<n;i++)
		push(s[i]);
	for(int i=0;i<n;i++)
		printf("%c",pop());	
	return 0;
	}
