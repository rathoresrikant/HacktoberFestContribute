#include <iostream>
#include<math.h>


//RECURSIVE
int allWays(int x, int n, int z=1) {
   
  if(x==0)
    return 1;
  
  if(pow(z,n)>x)
    return 0;
  int count=0;
  for(int i=z;pow(i,n)<=x;i++)
  {
    count+=allWays(x-pow(i,n),n,i+1);
  }
  return count;
}

//DP
int allWays_DP(int x, int n, int z=1) {

	
}
