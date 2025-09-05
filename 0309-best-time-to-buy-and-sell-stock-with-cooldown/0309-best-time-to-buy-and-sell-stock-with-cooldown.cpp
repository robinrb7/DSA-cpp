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

int solveTab(vector<int>& prices){
    int n=prices.size();
    vector<int>front1(2,0),front2(2,0) , curr(2,0); 

    for(int index=n-1;index>=0;index--){
        curr[1] = max(-prices[index] + front1[0] , front1[1]);
        curr[0] = max(prices[index] + front2[1] , front1[0]);

        front2=front1;
        front1=curr;
    }

    return front1[1];
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return solveTab(prices);
    }
};