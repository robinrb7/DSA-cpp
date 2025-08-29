class Solution {
    int solve(vector<int> &coins,int amount,int index,vector<vector<int>> &dp){
        if(amount<0) return 0;
        if(amount==0) return 1;

        if(dp[index][amount]!=-1) return dp[index][amount];
        int sum=0;
        for(int i=index;i<coins.size();i++){
            sum += solve(coins,amount-coins[i],i,dp);
        }
        return dp[index][amount] = sum;
    }
public:
    int change(int amount, vector<int>& coins){
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(coins,amount,0,dp);
    }
};