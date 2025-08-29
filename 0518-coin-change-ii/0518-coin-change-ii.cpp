class Solution {
    int solve(vector<int> &coins,int amount,int index,vector<vector<int>> &dp){
        if(index==coins.size() || amount<0) return 0;
        if(amount==0) return 1;
        if(dp[index][amount] != -1) return dp[index][amount];

        int include = solve(coins,amount-coins[index],index,dp);
        int exclude = solve(coins,amount,index+1,dp);

        return dp[index][amount] = include + exclude;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(coins,amount,0,dp);
    }
};