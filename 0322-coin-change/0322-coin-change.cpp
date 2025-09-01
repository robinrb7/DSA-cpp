class Solution {
private:
    int solve(vector<int>& coins,int index, int amount,vector<vector<int>> &dp){
        if(amount==0) return 0;
        if(index==0){
            if(amount%coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        
        int notTake = 0 + solve(coins,index-1,amount,dp);
        int take = INT_MAX;
        if(amount >= coins[index]) take = 1 + solve(coins,index,amount-coins[index],dp);
        

        return dp[index][amount] = min(take,notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans =  solve(coins,n-1,amount,dp);
        return (ans>=1e9)? -1: ans;
    }
};