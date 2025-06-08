class Solution {
    private:
    bool solve(vector<int>& arr, int sum, int index, int n,vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(index>=n || sum <0 ) return 0;
        
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        bool include = solve(arr,sum-arr[index], index+1,n,dp);
        bool exclude = solve(arr,sum,index+1,n,dp);
        
        dp[index][sum] = (include|| exclude);
        return dp[index][sum];
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        return solve(arr,sum,0,n,dp);
    }
};