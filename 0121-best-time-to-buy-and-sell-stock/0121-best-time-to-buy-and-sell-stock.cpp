class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int buyIndex=0, profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]-prices[buyIndex] > profit){
                profit = prices[i]-prices[buyIndex];
            }
            if(prices[i]<prices[buyIndex]) buyIndex=i;
        }

        return profit;
    }
};