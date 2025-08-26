class Solution {
private:
    
    int solve(vector<int>& coins, int amount){
        vector<int> dp(amount+1,0);
        dp[0]=0;

        for(int price=1;price<amount+1;price++){
            int minCoins = INT_MAX;
            for(int i=0;i<coins.size();i++){
                int coinsReq = INT_MAX;
                if(price-coins[i] >=0){
                    if(dp[price-coins[i]] !=-1){
                        coinsReq = 1 + dp[price-coins[i]];
                        minCoins = min(minCoins,coinsReq);
                    } 
                }   
            }
            dp[price] = (minCoins==INT_MAX)? -1: minCoins;
        }

        return dp[amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        
        return  solve(coins,amount);
    }
};