class Solution {
private:
    int solve(string &s1, string &s2, int index1,int index2,vector<vector<int>> &dp){
        if(index1<0 && index2<0) return 0;
        if(index1<0){
            int sum=0;
            for(int i=0;i<=index2;i++) sum += (int)s2[i];
            return sum;
        }
        if(index2<0){
            int sum=0;
            for(int i=0;i<=index1;i++) sum += (int)s1[i];
            return sum;
        }

        if(dp[index1][index2]!=-1) return dp[index1][index2];

        int include = INT_MAX, exclude1=INT_MAX, exclude2=INT_MAX;
        if(s1[index1]==s2[index2]){
            include = solve(s1,s2,index1-1,index2-1,dp);
        }
        else{
            exclude1 = (int)s1[index1] + solve(s1,s2,index1-1,index2,dp);
            exclude2 = (int)s2[index2] + solve(s1,s2,index1,index2-1,dp);
        }

        return dp[index1][index2] = min(include,min(exclude1,exclude2));
    }

    int solveTab(string &s1, string &s2){
        int n = s1.length(),m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        int sum=0;
        for(int i=1;i<=m;i++){
            sum += s2[i-1];
            dp[0][i] = sum;
        }
        sum=0;
        for(int i=1;i<=n;i++){
            sum += s1[i-1];
            dp[i][0] = sum;
        }

        for(int index1=1;index1<=n;index1++){
            for(int index2=1;index2<=m;index2++){

                int include = INT_MAX, exclude1=INT_MAX, exclude2=INT_MAX;
                if(s1[index1-1]==s2[index2-1]){
                    include = dp[index1-1][index2-1];
                }
                else{
                    exclude1 = (int)s1[index1-1] + dp[index1-1][index2];
                    exclude2 = (int)s2[index2-1] + dp[index1][index2-1];
                }

                dp[index1][index2] = min(include,min(exclude1,exclude2));
            }
        }

        return dp[n][m];
    }

    int solveOptm(string &s1, string &s2){
        int n = s1.length(),m=s2.length();
        vector<int> prev(m+1,0) , curr(m+1,0);

        int sum=0;
        for(int i=1;i<=m;i++){
            sum += s2[i-1];
            prev[i] = sum;
        }
        

        for(int index1=1;index1<=n;index1++){
            curr[0] = prev[0] + s1[index1-1];
            for(int index2=1;index2<=m;index2++){

                int include = INT_MAX, exclude1=INT_MAX, exclude2=INT_MAX;
                if(s1[index1-1]==s2[index2-1]){
                    include = prev[index2-1];
                }
                else{
                    exclude1 = (int)s1[index1-1] + prev[index2];
                    exclude2 = (int)s2[index2-1] + curr[index2-1];
                }

                curr[index2] = min(include,min(exclude1,exclude2));
            }
            prev = curr;
        }

        return prev[m];
    }


public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(),m=s2.length();

        return solveOptm(s1,s2);
    }
};