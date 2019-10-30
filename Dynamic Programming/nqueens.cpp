#include<stdio.h>
#include<math.h>
 
int board[20],count; 								//board is an array which represents the solution and count tells the no of solutions
 
int main()
{
 int n;												// represents the no of queens
 void queen(int row,int n);							//as the function to be called is defined later
 
 printf(" - N Queens Problem Using Backtracking -");
 printf("\n\nEnter number of Queens:");
 scanf("%d",&n);
 queen(1,n);										//call the function queen
 printf("solutions:%d",count);
 return 0;
}
 
//function for printing the solution
/*void print(int n)
{
 int i,j;											//variables to be used in the loops
 printf("\n\nSolution %d:\n\n",++count);
 
 for(i=1;i<=n;++i)									//this for loop prints the row no.
  printf("\t%d",i);
 
 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);								//prints the column no.
  for(j=1;j<=n;++j) 								//for nxn board
  {
   if(board[i]==j)									//if the solution array board has the same column stored to place the queen then 
    printf("\tQ"); 									//queen at i,j position
   else
    printf("\t-"); 									//empty slot i.e. queen is not placed at i,j
  }
 }
}*/
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)								//checking column and digonal conflicts
 {
  if(board[i]==column)								//column conflict if the column is already occupied by another queen
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))				//diagonal conflict to see if 2 queens lie on the same diagonal
    return 0;
 }
 
 return 1; 											//no conflicts
}
 
//function to check for proper positioning of queen for a given row and all columns
void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column; 								//no conflicts so place queen
   if(row==n) 										//dead end i.ei all queens are placed
	print(n); 										//printing the board configuration
   else 											//otherwise try queen with next position
    queen(row+1,n);
    
  }
 }

}
