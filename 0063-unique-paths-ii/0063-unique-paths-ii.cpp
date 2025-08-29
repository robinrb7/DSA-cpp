class Solution {
private:
    int solve( int rowIndex, int colIndex,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(rowIndex<0|| colIndex<0 || obstacleGrid[rowIndex][colIndex]==1) return 0;
        if(rowIndex==0 && colIndex==0) return 1;

        if(dp[rowIndex][colIndex] != -1) return dp[rowIndex][colIndex];

        int up = solve(rowIndex-1,colIndex,obstacleGrid,dp);
        int left = solve(rowIndex,colIndex-1,obstacleGrid,dp);

        dp[rowIndex][colIndex] =  up + left;
        return dp[rowIndex][colIndex];
    }

    int solveTab( int n, int m,vector<vector<int>>& obstacleGrid){
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=1;

        for(int rowIndex=0;rowIndex<n;rowIndex++){
            for(int colIndex=0;colIndex<m;colIndex++){
                if(rowIndex==0 && colIndex==0) continue;
                if(obstacleGrid[rowIndex][colIndex]==1) dp[rowIndex][colIndex]=0;
                else{
                    int up=0,left=0;
                    if(rowIndex>0) up = dp[rowIndex-1][colIndex];
                    if(colIndex>0) left = dp[rowIndex][colIndex-1];
                    dp[rowIndex][colIndex] =  up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int n=obstacleGrid.size(), m = obstacleGrid[0].size();
        return solveTab(n,m,obstacleGrid);
    }
};