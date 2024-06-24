#include<stdio.h>
double fact(int n);
void main()
{
	int n;
	printf("Enter number");
	scanf("%d",&n);
	printf("Factorial= %.2li",fact(n));
	
}
double fact(int n)
{
	int f=1,i;
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
	return f;
}
