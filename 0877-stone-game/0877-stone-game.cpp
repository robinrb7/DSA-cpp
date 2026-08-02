class Solution {
    private:
    int solve(vector<int>& piles, int start, int end){
        if(start>end) return 0;

        int takeStart = piles[start] + min(solve(piles,start+2,end), solve(piles,start+1,end-1));
        int takeEnd = piles[end] + min(solve(piles,start+1,end-1),solve(piles,start,end-2));

        return max(takeStart,takeEnd);
    }

    int solveMem(vector<int>& piles, int start, int end,vector<vector<int>> &dp){
        if(start>end) return 0;
        if(dp[start][end] != -1) return dp[start][end];

        int takeStart = piles[start] + min(solveMem(piles,start+2,end,dp), solveMem(piles,start+1,end-1,dp));
        int takeEnd = piles[end] + min(solveMem(piles,start+1,end-1,dp),solveMem(piles,start,end-2,dp));

        return dp[start][end] = max(takeStart,takeEnd);
    }

    int solveTab(vector<int>& piles){
        int n=piles.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int i=0;i<n;i++) dp[i][i+2] = piles[i];

        for(int start=n-1;start>=0;start--){
            for(int end=start;end<n;end++){
             //shift made in 'end' for handling indexing acc. to logic

                int takeStart = piles[start] + min(dp[start+2][end+2], dp[start+1][end+1]);
                int takeEnd = piles[end] + min(dp[start+1][end+1],dp[start][end]);

                dp[start][end+2] = max(takeStart,takeEnd);
            }
        }

        return dp[0][n-1];
    }



    
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        
        int playerFirstMaxScore = solveTab(piles);
        return playerFirstMaxScore > 0;
    }
};