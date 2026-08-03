class Solution {
    private:

    //TC -> O(3^n)
    int solve(vector<int>& stoneValue, int index, int n){
        if(index>=n) return 0;

        int takeOne=INT_MIN, takeTwo=INT_MIN,takeThree=INT_MIN;

        takeOne = stoneValue[index] - solve(stoneValue,index+1,n);
        if(index+1<n) takeTwo = stoneValue[index] + stoneValue[index+1]  - solve(stoneValue,index+2,n);
        if(index+2<n) takeThree = stoneValue[index] + stoneValue[index+1] + stoneValue[index+2] - solve(stoneValue,index+3,n);

        return max(takeOne,max(takeTwo,takeThree));
    }

    //TC -> O(n)  SC-> O(n) dp array + O(n) recusrion stack memory
    int solveMem(vector<int>& stoneValue, int index, int n, vector<int> &dp){
        if(index>=n) return 0;
        if(dp[index]!= INT_MIN) return dp[index];

        int takeOne=INT_MIN, takeTwo=INT_MIN,takeThree=INT_MIN;

        takeOne = stoneValue[index] - solveMem(stoneValue,index+1,n,dp);
        if(index+1<n) takeTwo = stoneValue[index] + stoneValue[index+1]  - solveMem(stoneValue,index+2,n,dp);
        if(index+2<n) takeThree = stoneValue[index] + stoneValue[index+1] + stoneValue[index+2] - solveMem(stoneValue,index+3,n,dp);

        return dp[index] = max(takeOne,max(takeTwo,takeThree));
    }


    //TC -> O(n)  SC-> O(n) dp array (only)
    int solveTab(vector<int>& stoneValue){
        int n =stoneValue.size();
        vector<int> dp(n+1,0);

        for(int index=n-1;index>=0;index--){
            int takeOne=INT_MIN, takeTwo=INT_MIN,takeThree=INT_MIN;

            takeOne = stoneValue[index] - dp[index+1];
            if(index+1<n) takeTwo = stoneValue[index] + stoneValue[index+1]  - dp[index+2];
            if(index+2<n) takeThree = stoneValue[index] + stoneValue[index+1] + stoneValue[index+2] - dp[index+3];

            dp[index] = max(takeOne,max(takeTwo,takeThree));
        }

        return dp[0];
    }

    int solveOptm(vector<int>& stoneValue){
        int n =stoneValue.size();
        int dp1=0,dp2=0,dp3=0;

        for(int index=n-1;index>=0;index--){
            int takeOne=INT_MIN, takeTwo=INT_MIN,takeThree=INT_MIN;

            takeOne = stoneValue[index] - dp1;
            if(index+1<n) takeTwo = stoneValue[index] + stoneValue[index+1]  - dp2;
            if(index+2<n) takeThree = stoneValue[index] + stoneValue[index+1] + stoneValue[index+2] - dp3;

            dp3=dp2;
            dp2=dp1;
            dp1 = max(takeOne,max(takeTwo,takeThree));
        }

        return dp1;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        //vector<int> dp(n,INT_MIN);
        int aliceMaxScore = solveOptm(stoneValue);

        if(aliceMaxScore==0) return "Tie";
        else if(aliceMaxScore>0) return "Alice";
        else return "Bob";
    }
};