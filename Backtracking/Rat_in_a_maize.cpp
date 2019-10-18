#include<bits/stdc++.h>
int maze[100][100];
int ar[100][100];

void explore(int n,int row,int col)
{

    if(row==n-1 and col==n-1)
    {
        //base case
        maze[row][col]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cout<<maze[i][j]<<" ";
        cout<<endl;
        maze[row][col]=0;
        return;
    }

    if(col+1!=n and ar[row][col+1]!=0 and maze[row][col+1]!=1)
    {
        maze[row][col+1]=1;
        explore(n,row,col+1);
        maze[row][col+1]=0;
    }
    if(col-1!=-1 and ar[row][col-1]!=0 and maze[row][col-1]!=1)
    {
        maze[row][col-1]=1;
        explore(n,row,col-1);
        maze[row][col-1]=0;
    }
    if(row+1!=n and ar[row+1][col]!=0 and maze[row+1][col]!=1)
    {
        maze[row+1][col]=1;
        explore(n,row+1,col);
        maze[row+1][col]=0;
    }
       if(row-1!=-1 and ar[row-1][col]!=0 and maze[row-1][col]!=1)
    {
        maze[row-1][col]=1;
        explore(n,row-1,col);
        maze[row-1][col]=0;
    }
}

void findpath(int n)
{
    memset(maze,0,sizeof(maze));
            maze[0][0]=1;
           explore(n,0,0);
}
void ratInAMaze(int arr[][20], int n){

      for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
              ar[i][j]=arr[i][j];
     findpath(n);
}
