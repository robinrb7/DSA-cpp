class Solution {
    private:
    bool isPalindrome(string &s,int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    int solve(string &s, int i,vector<int> &dp){
        int n = s.length();
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];
        
        int mini=INT_MAX;
        for(int index=i;index<n;index++){

            if(isPalindrome(s,i,index)){
                int cnt = 1 + solve(s,index+1,dp);
                mini = min(mini,cnt);
            }
        }
        return dp[i] = mini;
    }

    int solveTab(string &s){
        int n = s.length();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int index=i;index<n;index++){

                if(isPalindrome(s,i,index)){
                    int cnt = 1 + dp[index+1];
                    mini = min(mini,cnt);
                }
            }
            dp[i] = mini;
        }

        return dp[0];
    }

public:
    int minCut(string s) {
        int n =s.length();

        
        return solveTab(s) -1;
    }
};