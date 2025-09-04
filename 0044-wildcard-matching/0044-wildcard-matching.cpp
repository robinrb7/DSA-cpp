class Solution {
private:
    bool solve(string str1,string str2, int index1,int index2,vector<vector<int>> &dp){
        if(index1<0 && index2<0) return 1;
        if(index2<0) return 0;
        if(index1<0){
            for(int i=index2;i>=0;i--){
                if(str2[i]!='*') return 0;
            }
            return 1;
        }

        if(dp[index1][index2]!=-1) return dp[index1][index2];

        bool ans=0;
        if(str1[index1]==str2[index2] || str2[index2]=='?'){
            ans = solve(str1,str2,index1-1,index2-1,dp);
        }
        else if(str2[index2]=='*'){
            ans = solve(str1,str2,index1-1,index2,dp) || solve(str1,str2,index1,index2-1,dp);
        }
        else ans = 0;

        return dp[index1][index2] = ans;
    }

    bool solveTab(string str1,string str2){
        int n1=str1.length(), n2=str2.length();
        vector<bool> prev(n2+1,0) , curr(n2+1,0);
        prev[0]=1;
      
        int firstChIndex=-1;
        for(int i=0;i<n2;i++){
            if(str2[i]!='*'){
                firstChIndex=i;
                break;
            }
        }
        if(firstChIndex==-1){
            for(int j=1;j<=n2;j++) prev[j]=1;
        }
        else{
            for(int j=1;j<=firstChIndex;j++) prev[j]=1;
        }

        for(int index1=1;index1<=n1;index1++){
            curr[0]=0;
            for(int index2=1;index2<=n2;index2++){
                bool ans=0;
                if(str1[index1-1]==str2[index2-1] || str2[index2-1]=='?'){
                    ans = prev[index2-1];
                }
                else if(str2[index2-1]=='*'){
                    ans = prev[index2] || curr[index2-1];
                }

                curr[index2] = ans;
            }
            prev=curr;
        }

        return prev[n2];
    }
public:
    bool isMatch(string s, string p) {
        int n1=s.length(), n2=p.length();

        if(n1==0 && n2==0) return 1;
        if(n1!=0 && n2==0) return 0;
        if(n1==0 && n2!=0){
            for(int i=0;i<n2;i++){
                if(p[i]!='*') return 0;
            }
            return 1;
        }
        

        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solveTab(s,p);
    }
};