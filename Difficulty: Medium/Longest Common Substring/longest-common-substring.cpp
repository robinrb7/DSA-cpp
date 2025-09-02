class Solution {
private:
    int solveTab(string text1,string text2){
        int n1= text1.length(), n2 = text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int maxi=0;

        for(int index1=1;index1<=n1;index1++){
            for(int index2=1;index2<=n2;index2++){

                int ans = 0;
                if(text1[index1 -1]==text2[index2 -1]){
                    ans = 1 + dp[index1 -1][index2 -1];
                }

                dp[index1][index2] = ans;
                maxi = max(maxi,ans);
            }
        }
        return maxi;
    }
  public:
    int longestCommonSubstr(string& s1, string& s2) {
       return solveTab(s1,s2);
        
    }
};