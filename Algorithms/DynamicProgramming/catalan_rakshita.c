//nth catalan number

#include<stdio.h>

long long int cat(int n) 
{ 
    int i,j;
    long long int c[n + 1]; 

    c[0]=c[1]=1; 
     
    for (i=2;i<=n;i++)
     { 
        c[i]=0; 
        for (j=0;j<i;j++) 
            c[i]+=c[j]*c[i-j-1]; 
     } 
  
 
    return c[n]; 
} 
  
void main() 
{ 
  int N;
  printf("\nEnter the value of n [nth catalan number]");
  scanf("%d",&N);
  printf("\n\n The nth catalan number is:\n");
  printf("%Ld \n",cat(N));
    
} 
