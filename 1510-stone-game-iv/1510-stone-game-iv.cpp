class Solution {
    private:

    //player0 -> Alice
    //player1 -> bob
    bool solve(int n,vector<int> &dp){
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];

        for(int i=1;i*i<=n;i++){
            if(!solve(n-(i*i),dp)) return dp[n] = 1;  
            //this call made by bob, so if it is false which means bob does not wins, so automatically Alice wins, so we return true here
        }

        return dp[n] = 0;
    }

    bool solveTab(int n){
        vector<int> dp(n+1,0);

        for(int index=1;index<=n;index++){
            for(int i=1;i*i<=index;i++){

                if(!dp[index-(i*i)]){
                    dp[index] = 1;
                    break;  
                }
            }
        }

        return dp[n];
    }


public:
    bool winnerSquareGame(int n) {
        if(n==1) return true;

        
        return solveTab(n);
    }
};