class Solution {
    int solve(vector<vector<char>>& matrix,int n,int m, int i, int j,int &maxi,vector<vector<int>>&dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;

        int diagonal = solve(matrix,n,m,i+1,j+1,maxi,dp);
        int right = solve(matrix,n,m,i,j+1,maxi,dp);
        int down = solve(matrix,n,m,i+1,j,maxi,dp);

        if(matrix[i][j]== '1'){
            ans = 1 + min(diagonal,min(right,down));
        }
        maxi = max(maxi,ans);
        dp[i][j] = ans;
        return dp[i][j];

    }

    int solveTab(vector<vector<char>>& matrix,int n,int m,int &maxi){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i =n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = 0;

                int diagonal = dp[i+1][j+1];
                int right = dp[i][j+1];
                int down = dp[i+1][j];

                if(matrix[i][j]== '1'){
                    ans = 1 + min(diagonal,min(right,down));
                }
                maxi = max(maxi,ans);
                dp[i][j] = ans;                
            }
        }

        return dp[0][0];

    }

    int solveOptm(vector<vector<char>>& matrix,int n,int m,int &maxi){
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);

        for(int i =n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = 0;

                int diagonal = next[j+1];
                int right = curr[j+1];
                int down = next[j];

                if(matrix[i][j]== '1'){
                    ans = 1 + min(diagonal,min(right,down));
                }
                maxi = max(maxi,ans);
                curr[j] = ans;                
            }
            next=curr;
        }

        return curr[0];

    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n==1 && m==1) return (matrix[0][0]=='1') ? 1 :0;

        int maxi = 0;
        solveOptm(matrix,n,m,maxi);
        return maxi*maxi;
    }
};