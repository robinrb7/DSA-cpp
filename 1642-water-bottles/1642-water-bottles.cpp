class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = 0;
        while(numBottles >= numExchange){
            int newBottles = numBottles/numExchange;
            emptyBottles = numBottles%numExchange;
            numBottles = newBottles + emptyBottles;
            ans += newBottles;
        }
        return ans;
    }
};