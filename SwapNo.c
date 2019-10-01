
#include <stdio.h> 
int main() 
{ 
  int x , y; 
  printf("Enter the value of x and y:"); //Taking the value of the numbers.
  scanf("%d%d",&x,&y);//Reading value
s
  // Code to swap 'x' and 'y' 
  x = x + y;   
  y = x - y;   
  x = x - y;   
  
  printf("After Swapping: x = %d, y = %d", x, y); 
  
  return 0; 
} 
