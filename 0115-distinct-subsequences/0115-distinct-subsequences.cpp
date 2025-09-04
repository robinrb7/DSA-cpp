class Solution {
private:
    int solve(string str1, string str2, int index1,int index2,vector<vector<int>> &dp){
        if(index2 < 0) return 1;
        if(index1<0 && index2>=0) return 0;

        if(dp[index1][index2]!=-1) return dp[index1][index2];
        int ans=0;
        if(str1[index1]==str2[index2]){
            ans = solve(str1,str2,index1-1,index2-1,dp)  + solve(str1,str2,index1-1,index2,dp);
        }
        else{
            ans = solve(str1,str2,index1-1,index2,dp);
        }
        return dp[index1][index2] = ans;
    }
public:
    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();

        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(s,t,n1-1,n2-1,dp);
    }
};