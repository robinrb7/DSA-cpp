class Solution {
private:
    int solve(vector<int> &cuts,int i, int j,vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j] !=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int index=i;index<=j;index++){
            int cost = cuts[j+1]-cuts[i-1] + solve(cuts,i,index-1,dp) + solve(cuts,index+1,j,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }

    int solveTab(vector<int> &cuts){
        int N = cuts.size();
        vector<vector<int>> dp(N,vector<int>(N,0));

        for(int i =N-2;i>=1;i--){
            for(int j=i;j<=N-2;j++){

                int mini=INT_MAX;
                for(int index=i;index<=j;index++){
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][index-1] + dp[index+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][N-2];
    }


public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0), cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int N = cuts.size();

        
        return solveTab(cuts);
    }
};