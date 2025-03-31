class Solution {
    private:
    int solve(int n,int m, int i, int j,vector<vector<int>>&dp){
        if(i==n-1 && j==m-1) return 1;
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int down = solve(n,m,i+1,j,dp);
        int right = solve(n,m,i,j+1,dp);

        dp[i][j] = down+right;
        return dp[i][j];
    }
    int solveTab(int n,int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[n-1][m-1]=1;

        for(int i = n-1;i>=0;i--){
            for(int j =m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                int down = dp[i+1][j];
                int right = dp[i][j+1];

                dp[i][j] = down+right;
            }
        }
        return dp[0][0];
        
    }

    int solveOptm(int n,int m){
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);
        curr[m-1]=1;

        for(int i = n-1;i>=0;i--){
            for(int j =m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                int down = next[j];
                int right = curr[j+1];

                curr[j] = down+right;
            }
            next =curr;
        }
        return curr[0];
        
    }
public:
    int uniquePaths(int m, int n) {
        
        return solveOptm(m,n);
    }
};