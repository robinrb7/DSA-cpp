class Solution {
    int solve(vector<int>&nums,int index, int prevIndex,vector<vector<int>> &dp){
        int n =nums.size();
        if(index==n) return 0;
        if(dp[index][prevIndex+1]!=-1) return dp[index][prevIndex+1];

        int take = 0;
        if(prevIndex == -1 || nums[index]>nums[prevIndex])
            take = 1 + solve(nums,index+1,index,dp);
        int notTake = 0 + solve(nums,index+1,prevIndex,dp);

        return dp[index][prevIndex+1] = max(take,notTake);
    }

    int solveTab(vector<int>&nums){
        int n =nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int index=n-1;index>=0;index--){
            for(int prevIndex=index-1;prevIndex>=-1;prevIndex--){
                int take = 0;
                if(prevIndex == -1 || nums[index]>nums[prevIndex])
                    take = 1 + dp[index+1][index+1];
                int notTake = dp[index+1][prevIndex+1];

                dp[index][prevIndex+1] = max(take,notTake);
            }
        }

        return dp[0][0];        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        if(n==0 || n==1) return n;

        return solveTab(nums);
    }
};