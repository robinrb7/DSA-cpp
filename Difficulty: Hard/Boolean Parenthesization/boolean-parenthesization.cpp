// User function Template for C++
class Solution {
    private:
    int solve(string &s, int i, int j, bool isTrue,vector<vector<vector<int>> >&dp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue) return s[i]=='T';
            else return s[i]=='F';
        }
        
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        
        int ways = 0;
        for(int index=i+1;index<=j-1;index=index+2){
            int cnt = 0;
            int lt = solve(s,i,index-1,1,dp), rt =  solve(s,index+1,j,1,dp);
            int lf = solve(s,i,index-1,0,dp), rf  = solve(s,index+1,j,0,dp);
            if(s[index]=='&'){
                if(isTrue) cnt  = lt * rt;
                else cnt = lf * rf +  lf * rt + lt * rf;
            }
            else if(s[index]=='|'){
               if(isTrue) cnt = lt * rt +  lt * rf + lf * rt;
               else cnt = lf * rf;
            }
            else{
                if(isTrue) cnt = lf * rt + lt * rf;
                else cnt = lt * rt + lf * rf;
            }
            
            ways += cnt;
        }
        
        return dp[i][j][isTrue] = ways;
    }
  public:
    int countWays(string &s) {
        int n = s.length();
        
        vector<vector<vector<int>> >dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(s,0,n-1,1,dp);
        
    }
};