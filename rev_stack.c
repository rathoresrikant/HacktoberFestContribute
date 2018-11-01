#include<stdio.h>
#include<string.h>

//define maximum up to 20
#define MAX 20

int top = -1;
char stack[MAX];

/*Begin of push*/
char push(char item)
{
	if(top == (MAX-1))
		printf("Stack Overflow\n");
	else
		stack[++top] =item;
}
/*End of push*/

/*Begin of pop*/
char pop()
{
	if(top == -1)
		printf("Stack Underflow\n");
	else
		return stack[top--];
}
/*End of pop*/

/*Begin of main*/
int main()
{
	char str[20];
	int i;
	printf("Enter the string : " );
	gets(str);
	for(i=0;i<strlen(str);i++)
		push(str[i]);
	for(i=0;i<strlen(str);i++)
		str[i]=pop();
	printf("Reversed string is : ");
	puts(str);
	return 0;

}
