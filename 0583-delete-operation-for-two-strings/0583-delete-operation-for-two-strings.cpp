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
public:
    int minDistance(string word1, string word2) {
        int n1=word1.length(), n2=word2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));

        return solve(word1,word2,n1-1,n2-1,dp);
    }
};