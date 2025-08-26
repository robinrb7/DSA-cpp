class Solution {
private:
    int solve(vector<int>& nums, int index,vector<int>&dp){
        if(index==0) return nums[0];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];

        int pick = nums[index] + solve(nums,index-2,dp);
        int notPick = 0 + solve(nums,index-1,dp);

        dp[index] =  max(pick,notPick);
        return dp[index];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,n-1,dp);
    }
};