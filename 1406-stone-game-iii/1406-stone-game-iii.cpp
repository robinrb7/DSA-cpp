class Solution {
    private:
    int solve(vector<int>& stoneValue, int index, int n){
        if(index>=n) return 0;

        int takeOne=INT_MIN, takeTwo=INT_MIN,takeThree=INT_MIN;

        takeOne = stoneValue[index] - solve(stoneValue,index+1,n);
        if(index+1<n) takeTwo = stoneValue[index] + stoneValue[index+1]  - solve(stoneValue,index+2,n);
        if(index+2<n) takeThree = stoneValue[index] + stoneValue[index+1] + stoneValue[index+2] - solve(stoneValue,index+3,n);

        return max(takeOne,max(takeTwo,takeThree));
    }

    int solveMem(vector<int>& stoneValue, int index, int n, vector<int> &dp){
        if(index>=n) return 0;
        if(dp[index]!= INT_MIN) return dp[index];

        int takeOne=INT_MIN, takeTwo=INT_MIN,takeThree=INT_MIN;

        takeOne = stoneValue[index] - solveMem(stoneValue,index+1,n,dp);
        if(index+1<n) takeTwo = stoneValue[index] + stoneValue[index+1]  - solveMem(stoneValue,index+2,n,dp);
        if(index+2<n) takeThree = stoneValue[index] + stoneValue[index+1] + stoneValue[index+2] - solveMem(stoneValue,index+3,n,dp);

        return dp[index] = max(takeOne,max(takeTwo,takeThree));
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n,INT_MIN);
        int aliceMaxScore = solveMem(stoneValue,0,n,dp);

        if(aliceMaxScore==0) return "Tie";
        else if(aliceMaxScore>0) return "Alice";
        else return "Bob";
    }
};