#include<stdio.h>
#include<string.h>
 
int top=-1,stack[33];
 
void push(int item,int len)
{
	top=top+1;
	stack[top]=item;
}
 
void pop()
{
	printf("%c",stack[top]);
	top--;
}
 
 
void main()
{
 
	char s[22];
	int len,i;
	printf("Enter string\n");
	scanf("%s",s);
	
	len=strlen(s);
	for(i=0;i<len;i++)
	{
	push(s[i],len);
	}
	printf("the reverse of string is\n");
	for(i=0;i<len;i++)
	{
	pop();
	}
	printf("\n");
}
