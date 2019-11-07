class Solution {
public:
    
     int helper(vector<vector<vector<int>>>& dp, vector<vector<int>>& grid, int n, int r1, int c1, int c2)
  {
      int r2 = r1 + c1 - c2;
      if(r1==n-1 && c1==n-1)
      {
          return grid[r1][c1];
      }
      else if(r1==n || c1==n || r2==n || c2==n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
      {
          return INT_MIN;
      }
      else if(dp[r1][c1][c2] != INT_MIN)
      {
          return dp[r1][c1][c2];
      }
      else
      {
          dp[r1][c1][c2] = grid[r1][c1];
          if(r1!=r2 && c1!=c2)
          {
              dp[r1][c1][c2] += grid[r2][c2];
          }
          dp[r1][c1][c2] += max(
              max(helper(dp, grid, n, r1+1, c1, c2+1), 
              helper(dp, grid, n, r1, c1+1, c2)), 
              max(helper(dp, grid, n, r1, c1+1, c2+1), 
              helper(dp, grid, n, r1+1, c1, c2))
              );
      }
      return dp[r1][c1][c2];
  }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
      vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int>(n, INT_MIN)));
      
      return max(0, helper(dp, grid, n, 0, 0, 0));
    }
};
