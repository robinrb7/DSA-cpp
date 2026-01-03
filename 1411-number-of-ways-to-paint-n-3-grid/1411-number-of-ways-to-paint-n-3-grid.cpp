class Solution {
    const int MOD = 1e9 + 7;
private:
    long long solve(vector<string> &ways, int n, int prevStrIndex,vector<vector<long long>> &dp){
        if(n==0) return 1;
        if(dp[n][prevStrIndex]!=-1) return dp[n][prevStrIndex];

        long long ans = 0;
        string prevString = ways[prevStrIndex];
        for(int i=0;i<12;i++){
            if(i==prevStrIndex) continue;

            string currString = ways[i];
            bool conflict = false;
            for(int j=0;j<3;j++){
                if(prevString[j]==currString[j]){
                    conflict = true;
                    break;
                } 
            }

            if(!conflict){
                ans = (ans + solve(ways,n-1,i,dp))  % MOD;
            } 
        }

        return dp[n][prevStrIndex] = ans;
    }
public:
    int numOfWays(int n) {
        vector<string> ways = {"RGY","RGR","RYR","RYG",
                                "GYR","GYG", "GRG","GRY",
                                "YGR","YGY","YRY","YRG"
                                };

        vector<vector<long long>> dp(n+1,vector<long long>(12,-1));
        
        long long ans=0;
        for(int i=0;i<12;i++){
            ans = (ans + solve(ways,n-1,i,dp))  % MOD;
        }

        return (int)ans;
    }
};