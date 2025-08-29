class Solution {
private:
    int solve(vector<vector<int>> &matrix,int row,int col, int n,vector<vector<int>> &dp){
        if(row==n-1) return matrix[row][col];
        if(dp[row][col]!=-1) return dp[row][col];

        int leftDg = INT_MAX, rightDg=INT_MAX;
        if(col>0) leftDg = solve(matrix,row+1,col-1,n,dp);
        int down = solve(matrix,row+1,col,n,dp);
        if(col<n-1) rightDg = solve(matrix,row+1,col+1,n,dp);

        return dp[row][col] = matrix[row][col] + min(leftDg,min(down,rightDg));
    }

    int solveTab(vector<vector<int>> &matrix){
        int n =  matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int row=n-2;row>=0;row--){
            for(int col=0;col<n;col++){
                int leftDg = INT_MAX, rightDg=INT_MAX;
                if(col>0) leftDg = dp[row+1][col-1];
                int down = dp[row+1][col];
                if(col<n-1) rightDg = dp[row+1][col+1];

                dp[row][col] = matrix[row][col] + min(leftDg,min(down,rightDg));
            }
        }

        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,dp[0][i]);
        }

        return mini;;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return solveTab(matrix);
    }
};