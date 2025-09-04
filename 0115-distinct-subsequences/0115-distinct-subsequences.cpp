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

    int solveTab(string str1, string str2){
        int n1 = str1.length();
        int n2 = str2.length();
        vector<vector<long long>> dp(n1+1,vector<long long>(n2+1,0));
        for(int i=0;i<=n1;i++)dp[i][0]=1;

        for(int index1=1;index1<=n1;index1++){
            for(int index2=1;index2<=n2;index2++){

                int ans=0;
                if(str1[index1-1]==str2[index2-1]){
                    ans = dp[index1-1][index2-1]  + dp[index1-1][index2];
                }
                else{
                    ans = dp[index1-1][index2];
                }
                dp[index1][index2] = ans;
            }
        }

       return (int)dp[n1][n2];
    }
public:
    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();

        return solveTab(s,t);
    }
};