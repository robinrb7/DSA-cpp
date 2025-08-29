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

    int solveTab(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;

        for(int rowIndex=0;rowIndex<m;rowIndex++){
            for(int colIndex=0;colIndex<n;colIndex++){
                if(rowIndex==0 && colIndex==0) continue;

                int up = 0;
                if(rowIndex > 0) up = dp[rowIndex-1][colIndex];
                int left = 0;
                if(colIndex > 0) left = dp[rowIndex][colIndex-1];

                dp[rowIndex][colIndex]= up + left;
            }
        }
        return dp[m-1][n-1];
    }

public:
    int uniquePaths(int m, int n) {
        return solveTab(m,n);
    }
};