class Solution {
private:
    int solve(vector<int>& prices, int index,int buyAllowed,int limit,vector<vector<vector<int>> > &dp){
        int n=prices.size();
        if(index==n || limit==0) return 0;
        if(dp[index][buyAllowed][limit]!=-1) return dp[index][buyAllowed][limit];

        int ans = 0;
        if(buyAllowed){
            ans = max(-prices[index] + solve(prices,index+1,0,limit,dp) , 0 + solve(prices,index+1,1,limit,dp));
        }
        else{
            ans = max(prices[index] + solve(prices,index+1,1,limit-1,dp) , 0 + solve(prices,index+1,0,limit,dp));
        }

        return dp[index][buyAllowed][limit] = ans;
    }

    int solveTab(vector<int>& prices){
        int n=prices.size();
       vector<vector<vector<int>> > dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

       for(int index=n-1;index>=0;index--){
            for(int buyAllowed=0;buyAllowed<=1;buyAllowed++){
                for(int limit=1;limit<=2;limit++){
                    int ans = 0;
                    if(buyAllowed){
                        ans = max(-prices[index] + dp[index+1][0][limit] , dp[index+1][1][limit]);
                    }
                    else{
                        ans = max(prices[index] + dp[index+1][1][limit-1], dp[index+1][0][limit]);
                    }

                    dp[index][buyAllowed][limit] = ans;
                }
            }
       }

       return dp[0][1][2];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<vector<int>> > dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solveTab(prices);
    }
};