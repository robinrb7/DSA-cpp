class Solution {
private:
    int solve( int rowIndex, int colIndex,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(rowIndex<0|| colIndex<0 || obstacleGrid[rowIndex][colIndex]==1) return 0;
        if(rowIndex==0 && colIndex==0) return 1;

        if(dp[rowIndex][colIndex] != -1) return dp[rowIndex][colIndex];
        
        int up = solve(rowIndex-1,colIndex,obstacleGrid,dp);
        int down = solve(rowIndex,colIndex-1,obstacleGrid,dp);

        dp[rowIndex][colIndex] =  up + down;
        return dp[rowIndex][colIndex];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m = obstacleGrid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,obstacleGrid,dp);
    }
};