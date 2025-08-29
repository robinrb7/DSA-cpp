class Solution {
private:
    int solve(vector<vector<int>>& grid, int row, int col,vector<vector<int>> &dp){
        if(row<0 || col<0) return INT_MAX;
        if(row==0 && col==0) return grid[0][0];
        if(dp[row][col]!=-1) return dp[row][col];

        int up = solve(grid,row-1,col,dp);
        int left = solve(grid,row,col-1,dp);

        return  dp[row][col] = grid[row][col] + min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(grid,n-1,m-1,dp);
    }
};