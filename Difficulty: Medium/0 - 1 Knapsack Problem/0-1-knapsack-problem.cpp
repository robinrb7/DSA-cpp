class Solution {
    private:
    int solve(vector<int> &val, vector<int> &wt,int index, int weight,vector<vector<int>> &dp){
        if(weight==0) return 0;
        if(index==0){
            if(weight>=wt[index]) return val[index];
            else return 0;
        }
        
        if(dp[index][weight] != -1) return dp[index][weight];
        
        int take = INT_MIN;
        if(weight>=wt[index]) take = val[index] + solve(val,wt,index-1,weight-wt[index],dp);
        int notTake = 0 + solve(val,wt,index-1,weight,dp);
        
        return dp[index][weight] = max(take,notTake);
    }
    
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return solve(val,wt,n-1,W,dp);
    }
};