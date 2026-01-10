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
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(),m=s2.length();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s1,s2,n-1,m-1,dp);
    }
};