class Solution {
    private:
    bool solve(vector<int> &nums, int index, int n,vector<int>&dp){
        if(index==n-1) return 1;

        if(dp[index] != -1) return dp[index];
        for(int i =1; i<=nums[index];i++){
            if(solve(nums,index+i,n,dp)) return dp[index] = true;
        }

        return dp[index] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 1;

        vector<int>dp(n,-1);

        return solve(nums,0,n,dp);
    }
};