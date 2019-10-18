#include<stdio.h>
int stack[15];
int top=-1;
void creation(int item)
{
	top=top+1;
	stack[top]=item;
}
void display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
}
void push()
{
	int a;
	printf("Enter new element : ");
	scanf("%d",&a);
	if(top==14)
	{
		printf("Overflow");
	}
	else
	{
		top=top+1;
		stack[top]=a;
		
	}
}
void pop()
{
	int old;
	stack[top]=old;
	top=top-1;
	printf("Deleted element= %d",old);
}
int main()
{
	int item,i,n,selection;
	label:
		printf("Enter 1 to create");
		printf("\nEnter 2 to display");
		printf("\nEnter 3 to insert an element");
		printf("\nEnter 4 to delete an element");
		printf("\nyour selection");
		scanf("%d",&selection);
		if(selection==1)
		{
			printf("Enter elements\n");
			for(i=0;i<5;i++)
			{
				scanf("%d",&item);
				creation(item);
			}
			goto label;
		}
		if(selection==2)
		{
			display();
			goto label;
		}
		if(selection==3)
		{
			push();
			goto label;
		}
		if(selection==4)
		{
			pop();
			goto label;
		}
}
