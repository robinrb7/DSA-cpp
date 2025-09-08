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
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0), cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int N = cuts.size();

        vector<vector<int>> dp(N,vector<int>(N,-1));
        return solve(cuts,1,N-2,dp);
    }
};