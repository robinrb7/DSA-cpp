class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            dp[i][0] = matrix[i][0];
            cnt += dp[i][0];
        } 
        for(int j=1;j<m;j++){
            dp[0][j] = matrix[0][j];
            cnt += dp[0][j];
        } 

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){

                if(matrix[i][j]==0) dp[i][j]=0;
                else{
                    int up = dp[i-1][j];
                    int left = dp[i][j-1];
                    int diagonal = dp[i-1][j-1];

                    dp[i][j] = 1 + min(up,min(left,diagonal));
                }
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};