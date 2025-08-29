class Solution {
    int solve(int rowIndex,int colIndex,vector<vector<int>> &dp){
        if(rowIndex<0 || colIndex<0) return 0;
        if(rowIndex==0 && colIndex==0) return 1;

        if(dp[rowIndex][colIndex]!= -1) return dp[rowIndex][colIndex];

        int up = solve(rowIndex-1,colIndex,dp);
        int left = solve(rowIndex,colIndex-1,dp);

        dp[rowIndex][colIndex]= up + left;
        return dp[rowIndex][colIndex];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};