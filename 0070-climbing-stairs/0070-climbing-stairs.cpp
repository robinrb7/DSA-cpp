class Solution {
private:
    int solve(int stepNo){
        if(stepNo < 0) return 0;
        if(stepNo==0 || stepNo==1) return 1;

        int cntWays = solve(stepNo - 1) + solve(stepNo -2);
        return cntWays;
    }

    int solveMem(int stepNo,vector<int> &dp){
        if(stepNo < 0) return 0;
        if(stepNo==0 || stepNo==1) return 1;

        if(dp[stepNo] != -1) return dp[stepNo];

        int cntWays = solveMem(stepNo - 1,dp) + solveMem(stepNo - 2,dp);
        return dp[stepNo] = cntWays;
    }

    int solveTab(int n){
        vector<int> dp(n+1,0); 
        dp[0]=dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    int solveSpaceOpt(int n){
        int prev2 =1, prev1=1;
        int curr = -1;

        for(int i=2;i<=n;i++){
            curr = prev2 + prev1;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

public:
    int climbStairs(int n) {
        if(n==0 || n==1) return n;

        return solveSpaceOpt(n);
    }
};