class Solution {
private:
    string solveTab(string text1,string text2){
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
        dp[n1][n2];

        string ans="";
        int len = n1+n2 - dp[n1][n2];
        for(int i=0;i<len;i++) ans += "$";
        int index = len-1;

        int i=n1,j=n2;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans[index]= text1[i-1];
                index--;
                i--,j--; 
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    ans[index] = text2[j-1];
                    index--;
                    j--;
                }
                else{
                    ans[index] = text1[i-1];
                    index--;
                    i--;
                }
            }
        }
        
        while(i!=0){
            ans[index--] = text1[i-1];
            i--;
        } 
        while(j!=0){
            ans[index--] = text2[j-1];
            j--;
        } 

        return ans;

    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        return solveTab(str1,str2);
    }
};