class Solution {
private:
    int solve(vector<int>& prices, int index,int buyAllowed,vector<vector<int>> &dp){
    int n=prices.size();
    if(index>=n) return 0;

    if(dp[index][buyAllowed]!=-1) return dp[index][buyAllowed];
    int ans = 0;
    if(buyAllowed){
        ans = max(-prices[index] + solve(prices,index+1,0,dp) , 0 + solve(prices,index+1,1,dp));
    }
    else{
        ans = max(prices[index] + solve(prices,index+2,1,dp) , 0 + solve(prices,index+1,0,dp));
    }

    return dp[index][buyAllowed] = ans;
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};