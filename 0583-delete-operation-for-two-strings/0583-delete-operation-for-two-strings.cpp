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
        vector<int> prev(n2+1,0);

        for(int j=0;j<=n2;j++) prev[j] = j;

        for(int index1=1;index1<=n1;index1++){
            int prevDiagonal = prev[0];
            prev[0]=index1;
            for(int index2=1;index2<=n2;index2++){
                int ans=0;
                if(word1[index1-1]==word2[index2-1]){
                    ans = prevDiagonal;
                }
                else{
                    ans = 1 + min(prev[index2],prev[index2-1]);
                }
                prevDiagonal = prev[index2];
                prev[index2] = ans;
            }
        }
        return prev[n2];        
    }
public:
    int minDistance(string word1, string word2) {
        int n1=word1.length(), n2=word2.length();

        return solveTab(word1,word2);
    }
};