#include<iostream>
using namespace std;
int n=9;
void printsudoku(int mat[][9])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
            if((j+1)%3==0)
            {
                cout<<'\t';
            }
        }
        if((i+1)%3==0)
        {
            cout<<endl;
        }
        cout<<endl;
    }
}
bool possible(int mat[][9],int i,int j,int no)
{
    int x,y;
    for(x=0;x<n;x++)
    {
        if(mat[x][j]==no || mat[i][x]==no)
        {
            return false;
        }
    }
    int m=(i/3)*3;
    int p=(j/3)*3;
    for(x=m;x<m+3;x++)
    {
        for(y=p;y<p+3;y++)
        {
            if(mat[x][y]==no)
            {
                return false;
            }
        }
    }
    return true;
}
bool solvesudoku(int mat[][9],int i,int j)
{
    if(i==9)
    {
        printsudoku(mat);
        return true;
    }

    if (j==9)
    {
        return solvesudoku(mat,i+1,0);
    }

    if(mat[i][j]!=0)
    {
        return solvesudoku(mat,i,j+1);
    }

    for(int no=1;no<=9;no++)
    {
       if(possible(mat,i,j,no))
       {
           mat[i][j]=no;
           bool aagekisolvehui=solvesudoku(mat,i,j+1);
           if(aagekisolvehui)
           {
               return true;
           }
       }
    }
    mat[i][j]=0;
    return false;
}
int main()
{
    int mat[][9]={
                    {5,3,0,0,7,0,0,0,0},
                    {6,0,0,1,9,5,0,0,0},
                    {0,9,8,0,0,0,0,6,0},
                    {8,0,0,0,6,0,0,0,3},
                    {4,0,0,8,0,3,0,0,1},
                    {7,0,0,0,2,0,0,0,6},
                    {0,6,0,0,0,0,2,8,0},
                    {0,0,0,4,1,9,0,0,5},
                    {0,0,0,0,8,0,0,7,9}
                 };

    printsudoku(mat);
    solvesudoku(mat,0,0);
}
