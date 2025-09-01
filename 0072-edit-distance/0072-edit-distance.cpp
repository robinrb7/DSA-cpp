class Solution {
    private:
    int solve(string word1,string word2, int index1, int index2,vector<vector<int>> &dp){
        int n1 = word1.length();
        int n2 = word2.length();
        
        if(index1 <0) return index2+1;
        if(index2 <0) return index1+1;

        if(dp[index1+1][index2+1] != -1) return dp[index1+1][index2+1];

        int ans = 0;
        if(word1[index1]==word2[index2]){
            ans = 0 + solve(word1,word2,index1-1,index2-1,dp);
        }
        else{
            int insertCh = 1 + solve(word1,word2,index1,index2-1,dp);
            int deleteCh = 1 + solve(word1,word2,index1-1,index2,dp);
            int replaceCh = 1 + solve(word1,word2,index1-1,index2-1,dp);

            ans = min(insertCh,min(deleteCh,replaceCh));
        }

        return dp[index1+1][index2+1] = ans;
    }


public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        if(n1==0 && n2==0) return 0;
        if(n1==0 && n2!=0) return n2;
        if(n1!=0 && n2==0) return n1;

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(word1,word2,n1-1,n2-1,dp);
    }
};