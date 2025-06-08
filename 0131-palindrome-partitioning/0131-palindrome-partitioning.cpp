class Solution {
    private:
    bool palin(string s, int i, int j,vector<vector<int>>&dp){

        if(dp[i][j] != -1) return dp[i][j];

        int left = i, right =j;
        while(left<right){
            if(s[left++]!=s[right--]){
                dp[i][j]=0;
                return dp[i][j];
            }
        }
        dp[i][j] = 1;
        return dp[i][j];
    }
    void solve(string s, vector<vector<string>>&ans, vector<string> &temp, int partIndx, int n,vector<vector<int>>&dp){
        if(partIndx == n){
            ans.push_back(temp);
            return;
        } 

        for(int i=partIndx;i<n;i++){
            if(palin(s,partIndx,i,dp)){
                temp.push_back(s.substr(partIndx,i - partIndx +1));
                solve(s,ans,temp,i+1,n,dp);
                temp.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> temp;
        int n= s.length();

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        solve(s,ans,temp,0,n,dp);
        return ans;
    }
};