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

    int solveTab(vector<int>& coins, int cost){
        int n =coins.size();
        vector<vector<int>> dp(n,vector<int>(cost+1,0));
        for(int i=0;i<=cost;i++){
            if(i%coins[0]==0) dp[0][i]= i/coins[0];
            else dp[0][i] = 1e9;
        }

        for(int index=1;index<n;index++){
            for(int amount=1;amount<=cost;amount++){

                int notTake = 0 + dp[index-1][amount];
                int take = INT_MAX;
                if(amount >= coins[index]) take = 1 + dp[index][amount-coins[index]];
                
                dp[index][amount] = min(take,notTake);
            }
        }
        
        return dp[n-1][cost];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        
        int ans =  solveTab(coins,amount);
        return (ans>=1e9)? -1: ans;
    }
};