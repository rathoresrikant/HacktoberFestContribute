
#include<bits/stdc++.h>

int board[11][11];

bool ispossible(int n,int row,int col)
{
    for(int j=row-1;j>=0;j--)
    {
        if(board[j][col]==1)
            return false;
    }
    for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }
    for(int i=row-1,j=col+1;i>=0 and j<n;i--,j++)
    {
        if(board[i][j]==1)
            return false;
    }
    return true;
}

void qhelper(int n,int row)
{
    if(row==n)
    {
        //board filled
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }

    for(int j=0;j<n;j++)
    {
        if(ispossible(n,row,j))
        {
            board[row][j]=1;
            qhelper(n,row+1);
            board[row][j]=0;
        }
    }
}


void placeNQueens(int n){

 memset(board,0,sizeof(board));
    qhelper(n,0);

}
