class Solution {
  private:
    int solve(vector<int>& heights, int index,vector<int> &dp){
        if(index==0) return 0;
        if(index==1) return abs(heights[1] - heights[0]);
        
        if(dp[index]!=-1) return dp[index];
        
        int step1 = solve(heights,index-1,dp) + abs(heights[index] - heights[index-1]);
        int step2 = solve(heights,index-2,dp) + abs(heights[index] - heights[index-2]);
        dp[index] =  min(step1,step2);
        
        return dp[index];
    }
  public:
    int minCost(vector<int>& height) {
        
        int n = height.size();
        vector<int>dp(n+1,-1);
        return solve(height,n-1,dp);
    }
};