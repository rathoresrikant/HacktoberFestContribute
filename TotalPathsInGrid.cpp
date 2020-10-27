/*
suppose you are at (1,1) in a grid of size (m*n) and you wish to go to (m,n) ...
At one time you can either move down or right from a point (x,y)
now , you want to find in how many ways you can reach there..

There are two easy approaches :
1. Dynamic Programming
2. Mathematical Formula

*/

// Dynamic Programming Approach

int TotalPathUsingDp(int m , int n){
int dp[m][n];   // making a duplicate grid

for(int i   = 0; i < m; i++){
for(int j = 0; j<n; j++){
dp[i][j] = 0; // initializing array to 0
}
}

for(int i =0 ; i<n; i++){
dp[0][i] = 1;   // initialize array's first row = 1
}

for(int i =0 ; i<n; i++){
dp[i][0] = 1;   // initialize array's first col = 1
}

for(int i = 1; i<m; i++){
for(int j =1; j<n; j++){
dp[i][j] = dp[i-1][j] + dp[i][j-1]; // adding values of upper and left grid block
}
}
return dp[m-1][n-1];
}

// Mathematical Approach

int TotalPathsUsingMaths(int m, int n){
return (m! * n!)/(m! + n!);   // here [m!] means [factorial of m]
}
