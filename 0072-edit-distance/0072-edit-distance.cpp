class Solution {
    private:
    int solve(string word1,string word2, int index1, int index2,vector<vector<int>> &dp){
        int n1 = word1.length();
        int n2 = word2.length();
        
        if(index1 <0) return index2+1;
        if(index2 <0) return index1+1;

        if(dp[index1+1][index2+1] != -1) return dp[index1+1][index2+1];

        int ans = 0;
        if(word1[index1]==word2[index2]){
            ans = 0 + solve(word1,word2,index1-1,index2-1,dp);
        }
        else{
            int insertCh = 1 + solve(word1,word2,index1,index2-1,dp);
            int deleteCh = 1 + solve(word1,word2,index1-1,index2,dp);
            int replaceCh = 1 + solve(word1,word2,index1-1,index2-1,dp);

            ans = min(insertCh,min(deleteCh,replaceCh));
        }

        return dp[index1+1][index2+1] = ans;
    }

    int solveTab(string word1,string word2){
        int n1 = word1.length();
        int n2 = word2.length();

        vector<int> prev(n2+1,0);
        vector<int> curr(n2+1,0);
        prev[0]=0;
        for(int j=0;j<=n2;j++) prev[j] = j;

        for(int index1=1;index1<=n1;index1++){
            curr[0]=index1;
            for(int index2=1;index2<=n2;index2++){
                int ans = 0;
                if(word1[index1-1]==word2[index2-1]){
                    ans = 0 + prev[index2-1];
                }
                else{
                    int insertCh = 1 + curr[index2-1];
                    int deleteCh = 1 + prev[index2];
                    int replaceCh = 1 + prev[index2-1];

                    ans = min(insertCh,min(deleteCh,replaceCh));
                }

                curr[index2] = ans;
            }
            prev=curr;
        }

        return prev[n2];
    }


public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        if(n1==0 && n2==0) return 0;
        if(n1==0 && n2!=0) return n2;
        if(n1!=0 && n2==0) return n1;

        return solveTab(word1,word2);
    }
};