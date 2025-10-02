class Solution {
private:
    pair<int,int> getBottlesCount(int numBottles, int &numExchange){
        int newBottles=0;
        while(numBottles >= numExchange){
            newBottles++;
            numBottles -= numExchange;
            numExchange++;
        }
        return {newBottles,numBottles};
    }
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;

        while(numBottles >= numExchange){
            auto[newBottles , emptyBottles] = getBottlesCount(numBottles,numExchange);
            ans += newBottles;
            numBottles = newBottles + emptyBottles;
        }

        return ans;
    }
};