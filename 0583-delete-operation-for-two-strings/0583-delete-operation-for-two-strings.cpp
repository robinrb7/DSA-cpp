class Solution {
    int solve(string word1,string word2,int index1,int index2,vector<vector<int>> &dp){
        if(index1<0) return index2+1;
        if(index2<0) return index1+1;

        if(dp[index1][index2]!=-1) return dp[index1][index2];

        int ans=0;
        if(word1[index1]==word2[index2]){
            ans = 0 + solve(word1,word2,index1-1,index2-1,dp);
        }
        else{
            ans = 1 + min(solve(word1,word2,index1-1,index2,dp),solve(word1,word2,index1,index2-1,dp));
        }
        return dp[index1][index2] = ans;
    }

    int solveTab(string word1,string word2){
        int n1=word1.length(), n2=word2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int j=0;j<=n2;j++) dp[0][j] = j;
        for(int i=0;i<=n1;i++) dp[i][0] = i;

        for(int index1=1;index1<=n1;index1++){
            for(int index2=1;index2<=n2;index2++){
                int ans=0;
                if(word1[index1-1]==word2[index2-1]){
                    ans = dp[index1-1][index2-1];
                }
                else{
                    ans = 1 + min(dp[index1-1][index2],dp[index1][index2-1]);
                }
                dp[index1][index2] = ans;
            }
        }
        return dp[n1][n2];        
    }
public:
    int minDistance(string word1, string word2) {
        int n1=word1.length(), n2=word2.length();

        return solveTab(word1,word2);
    }
};