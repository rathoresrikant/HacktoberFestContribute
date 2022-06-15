#include<stdio.h>
#include<stdlib.h>
int catalan(int n)
{
if(n<=1)
    return 1;
int res=0;
for(int i=0;i<n;i++)
{
res+=catalan(i)*catalan(n-i-1);
}
return res;
}
int main()
{
int p;
printf("enter the number of times u want");
scanf("%d",&p);
for(int i=0;i<10;i++)
{
cout=catalan(i);
printf("%d",cout);
printf(" ");
}
}
