class Solution {\
private:
    int solve(vector<vector<int>>& triangle, int i,int j,int n,vector<vector<int>> &dp){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(solve(triangle,i+1,j,n,dp) , solve(triangle,i+1,j+1,n,dp));
    }

    int solveTab(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<int> front(n,0);

        for(int j=0;j<n;j++) front[j] = triangle[n-1][j];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                front[j] = triangle[i][j] + min(front[j] , front[j+1]);
            }
        }
        
        return front[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        return solveTab(triangle);
    }
};