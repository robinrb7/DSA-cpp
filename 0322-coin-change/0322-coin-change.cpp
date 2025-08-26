class Solution {
private:
    int solve(vector<int>& coins, int amount,vector<int> &dp){
        if(amount==0) return 0;
        if(dp[amount]!=-2) return dp[amount];

        int minCoins = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int coinsReq = INT_MAX;
            if(amount-coins[i] >=0){
                int subPrblm = solve(coins,amount-coins[i],dp);
                if(subPrblm !=-1){
                    coinsReq = 1 + subPrblm;
                    minCoins = min(minCoins,coinsReq);
                } 
            }   
        }

        dp[amount] =  (minCoins==INT_MAX)? -1: minCoins;
        return dp[amount];

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-2);
        return  solve(coins,amount,dp);
    }
};