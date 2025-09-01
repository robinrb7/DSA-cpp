class Solution {
    private:
    int solve(vector<int> &arr, int index,int target,vector<vector<int>> &dp){
        if(index==0){
            if(arr[0]==0 && target==0) return 2;
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        
        if(dp[index][target] !=-1) return dp[index][target];

        int notTake = solve(arr,index-1,target,dp);
        int take = 0;
        if(target>= arr[index])take = solve(arr,index-1,target-arr[index],dp);

        return dp[index][target] = take + notTake;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(arr,n-1,target,dp);
    }
};