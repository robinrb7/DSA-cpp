class Solution {
    private:
    int solve(string s1,string s2, int index1,int index2,vector<vector<int>> &dp){
        if(index1<0 || index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];

        int ans=0;
        if(s1[index1]==s2[index2]){
            ans = 1 + solve(s1,s2,index1-1,index2-1,dp);
        }
        else{
            ans = max(solve(s1,s2,index1,index2-1,dp),solve(s1,s2,index1-1,index2,dp));
        }

        return dp[index1][index2] = ans;
    }

    int solveTab(string s1,string s2){
        int n = s1.length();
        vector<int>prev(n+1,0);

        for(int index1=1;index1<=n;index1++){
            int prevDg=0;
            for(int index2=1;index2<=n;index2++){
                int ans=0;
                if(s1[index1-1]==s2[index2-1]){
                    ans = 1 + prevDg;
                }
                else{
                    ans = max(prev[index2-1],prev[index2]);
                }
                prevDg = prev[index2];
                prev[index2] = ans;
            }
        }

        return prev[n];
    }

public:
    int longestPalindromeSubseq(string s) {
        string s1 = s, s2 = s; 
        reverse(s2.begin(),s2.end());
        int n = s.length();

        
        return solveTab(s1,s2);
    }
};