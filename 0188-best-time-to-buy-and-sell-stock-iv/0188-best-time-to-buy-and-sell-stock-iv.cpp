class Solution {
private:
    int solve(vector<int>& prices, int index, int transLimit,vector<vector<int>> &dp){
        int n=prices.size();
        if(index==n || transLimit==0) return 0;
        if(dp[index][transLimit]!=-1) return dp[index][transLimit];

        int ans = 0;
        if(transLimit %2==0){
            ans = max(-prices[index] + solve(prices,index+1,transLimit-1,dp) , 0 + solve(prices,index+1,transLimit,dp));
        }
        else{
            ans = max(prices[index] + solve(prices,index+1,transLimit-1,dp) , 0 + solve(prices,index+1,transLimit,dp));
        }

        return dp[index][transLimit] = ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2*k+1,-1));
        return solve(prices,0,2*k,dp);
    }
};