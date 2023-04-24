#include <stdio.h>
#include <stdlib.h>
void findsum(int ele, int array[])
{int i;
float sum=0.0, average;

}
int main()
{
 int n;
 int num[100];

 printf("enter numbers of elements  ");
 scanf("%d", &n);

 while (n>100|| n<= 0)
 {
     printf("error! number should be in range 1 - 100.  \n ");
     printf("enter the number again:");
     scanf("%d",&n);
 }
 findsum (n,num);
}
