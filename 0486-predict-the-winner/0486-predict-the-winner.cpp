class Solution {
    private:

    //Tc -> O(2^n) SC -> O(n) recursion stack memory only
    int solve(vector<int>& nums, int start, int end){
        if(start==end){
            return nums[start]; // or nums[end] -> both same as index is same, but we are taking it
                                //because this value has not been included yet in any player's score.
        }

        int takeStart = nums[start] - solve(nums,start+1,end);
        int takeEnd = nums[end] - solve(nums,start,end-1);

        return max(takeStart, takeEnd);
    }

    //TC -> O(n^2)  SC -> O(n^2) dp array + o(n) recursion stack memory
    int solveMem(vector<int>& nums, int start, int end,vector<vector<int>> &dp){
        if(start==end) return nums[start];
        
        if(dp[start][end]!=-1) return dp[start][end];

        int takeStart = nums[start] - solveMem(nums,start+1,end,dp);
        int takeEnd = nums[end] - solveMem(nums,start,end-1,dp);

        dp[start][end] = max(takeStart, takeEnd);
        return dp[start][end];
    }

    //TC -> O()
    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<n;i++) dp[i][i+1] = nums[i];

        for(int start=n-1;start>=0;start--){
            for(int end=start+1;end<n;end++){
                
                int takeStart = nums[start] - dp[start+1][end+1];
                int takeEnd = nums[end] - dp[start][end];
                dp[start][end+1] = max(takeStart, takeEnd);
            }
        }
        
        return dp[0][n];
    }


public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;

        int playerFirstMaxScore = solveTab(nums);
        return (playerFirstMaxScore>=0) ;
    }
};