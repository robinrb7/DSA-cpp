class Solution {
private:
    int solve(vector<vector<int>>& grid){
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = grid[0][0];

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0 && col==0) continue;

                int up = INT_MAX, left = INT_MAX;
                if(row>0) up = dp[row-1][col];
                if(col>0) left = dp[row][col-1];

                dp[row][col] = grid[row][col] + min(up,left);
            }
        }
        return dp[n-1][m-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        return solve(grid);
    }
};