class Solution {
private:
    int solve(vector<int>& nums, int i,int j,vector<vector<int>> &dp){
        int n = nums.size();
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = INT_MIN;
        for(int index=i;index<=j;index++){
            int coins =  nums[i-1] * nums[index] * nums[j+1] + solve(nums,i,index-1,dp) + solve(nums,index+1,j,dp);
            maxi = max(maxi,coins);
        }

        return dp[i][j] = maxi;
    }

    int solveTab(vector<int>& nums){
        int n = nums.size();
         vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=n-2;i>=1;i--){
            for(int j =i;j<=n-2;j++){

                int maxi = INT_MIN;
                for(int index=i;index<=j;index++){
                    int coins =  nums[i-1] * nums[index] * nums[j+1] + dp[i][index-1] + dp[index+1][j];
                    maxi = max(maxi,coins);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n-2];
    }
public:
    int maxCoins(vector<int>& nums){
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();

       
        return solveTab(nums);
    }
};