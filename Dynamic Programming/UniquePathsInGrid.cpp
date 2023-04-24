/*Unique Paths in a Grid
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n).
At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.*/

/**
*The solution is in CPP
*Time Complexity O(n^2)
*Space Complexity: O(n)
*/

int Test::uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A.size()==0){
        return 0;
    }
    vector<int> first(A[0].size()+1, 0), second(A[0].size()+1, 0);

    for(int j = 1; j<=A[0].size(); j++){
        if(A[0][j-1]==1){
            break;
        }else{
            first[j]=1;
        }
    }

    for(int i = 2; i<=A.size(); i++){
        for(int j = 1; j<=A[0].size(); j++){
            if(A[i-1][j-1]==1){
                second[j]=0;
            }else{
                second[j]=first[j] + second[j-1];
            }
        }
        first = second;
    }
    return first[A[0].size()];
}
