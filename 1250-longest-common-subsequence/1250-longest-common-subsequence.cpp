class Solution {
    int solve(string text1,string text2, int index1,int index2,vector<vector<int>> &dp){
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];

        int ans = 0;
        if(text1[index1]==text2[index2]){
            ans = 1 + solve(text1,text2,index1 -1,index2 -1,dp);
        }
        else{
            int moveFirst = solve(text1,text2,index1 -1,index2,dp);
            int moveSecond = solve(text1,text2,index1,index2 -1,dp);
            ans = max(moveFirst,moveSecond);
        }

        return dp[index1][index2] = ans;
    }

    int solveTab(string text1,string text2){
        int n1= text1.length(), n2 = text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int index1=1;index1<=n1;index1++){
            for(int index2=1;index2<=n2;index2++){

                int ans = 0;
                if(text1[index1 -1]==text2[index2 -1]){
                    ans = 1 + dp[index1 -1][index2 -1];
                }
                else{
                    int moveFirst = dp[index1 -1][index2];
                    int moveSecond = dp[index1][index2 -1];
                    ans = max(moveFirst,moveSecond);
                }

                dp[index1][index2] = ans;
            }
        }
        return dp[n1][n2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        return solveTab(text1,text2);
    }
};