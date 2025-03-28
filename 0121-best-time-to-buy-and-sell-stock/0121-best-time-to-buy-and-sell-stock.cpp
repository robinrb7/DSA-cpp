class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int mini = prices[0];
        int profit =0;

        for(int i=1;i<n;i++){
            int diff = prices[i]-mini;
            if(diff > profit){
                profit = diff;
            }
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};