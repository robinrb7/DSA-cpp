class Solution {
private:
    int solveTab(vector<int>& nums){
        int n =nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];

        for(int index=1;index<n;index++){
            int pick = nums[index];
            if(index>=2) pick += dp[index-2];
            int notPick = 0 + dp[index-1];

            dp[index] =  max(pick,notPick);
        }
        
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        return solveTab(nums);
    }
};