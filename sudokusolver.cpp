#include <iostream>
#include<cmath>
using namespace std;

bool canPlace(int sudoku[][25],int i,int j,int n,int number){
    for(int x=0;x<n;x++){
        if(sudoku[x][j]==number||sudoku[i][x]==number)
            return false;          
        }
    
	int sx = (i/3)*3;
    int sy = (j/(n/3))*(n/3);

    for(int x=sx;x<sx+3;x++){
        for(int y=sy;y<sy+(n/3);y++){
            if(sudoku[x][y]==number){
                return false;
            }
        }
    }
     
     return true;
}

bool solveSudoku(int sudoku[][25],int i,int j,int n){
    //base case
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
     
     return true;
    }
    //recursive case
    if(j==n){
        return solveSudoku(sudoku,i+1,0,n);
    }
    if(sudoku[i][j]!=0){
        return solveSudoku(sudoku,i,j+1,n);
    }
   else {for(int number=1;number<=n;number++){
        if(canPlace(sudoku,i,j,n,number)){
            sudoku[i][j]=number;

            if(solveSudoku(sudoku,i,j+1,n)){
                return true;
            }
        }
    }
    sudoku[i][j]=0;
    return false;
   }
    
}

int main() {
    int n;
    cin>>n;
    int sudoku[25][25]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>sudoku[i][j];
        }
    }
    solveSudoku(sudoku,0,0,n);

    return 0;
}
