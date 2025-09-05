class Solution {
private:
int solve(vector<int>& prices, int index,int buyAllowed,vector<vector<int>> &dp){
    int n=prices.size();
    if(index==n) return 0;

    if(dp[index][buyAllowed]!=-1) return dp[index][buyAllowed];
    int ans = 0;
    if(buyAllowed){
        ans = max(-prices[index] + solve(prices,index+1,0,dp) , 0 + solve(prices,index+1,1,dp));
    }
    else{
        ans = max(prices[index] + solve(prices,index+1,1,dp) , 0 + solve(prices,index+1,0,dp));
    }

    return dp[index][buyAllowed] = ans;
}

int solveTab(vector<int>& prices){
    int n=prices.size();
    int frontBuy=0, frontSell=0;

    for(int index=n-1;index>=0;index--){
        int currBuy=0, currSell=0;

        currBuy = max(-prices[index] + frontSell , frontBuy);
        currSell = max(prices[index] + frontBuy , frontSell);

        frontBuy = currBuy;
        frontSell = currSell;
    }
    
    return frontBuy;
}
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();

        return solveTab(prices);
    }
};