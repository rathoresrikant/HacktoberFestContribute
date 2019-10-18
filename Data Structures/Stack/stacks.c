#include <stdio.h>
#include <stdlib.h>
struct stack{
	int stk[5];
	int top;
};
typedef struct stack STACK;
STACK s;
void push(void);
void pop(void);
void disp(void);
int main()
{
	int choice , opt=1;
	s.top=-1;
	while (opt==1)
	{
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				disp();
				break;
			default:
				printf("invalid input\n");
		}
		printf("press 1 to continue\n");
		scanf("%d",&opt);
	}	
}
void push(void)
{
	if (s.top==4)
	{
		printf("stack is full\n");
	}
	else
	{
		int a;
		printf("enter number\n");
		scanf("%d",&a);
		s.top+=1;
		s.stk[s.top]=a;
	}
}
void pop (void)
{
	if (s.top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("element popped %d\n",s.stk[s.top]);
		s.top-=1;
	}
}
void disp (void)
{
	if (s.top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		int i;
		for (i=0;i<=s.top;i++)
		{
			printf("%d\n",s.stk[i]);
		}
	}
}
