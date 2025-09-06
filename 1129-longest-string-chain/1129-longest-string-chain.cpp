class Solution {
    private:
    static bool cmp(string s1, string s2){
        return s1.length() < s2.length();
    }

    bool compare(string &str1,string &str2){
        int n1 = str1.length(), n2 =str2.length();
        if(n2 +1 != n1) return 0;

        int i=0,j=0;
        while(i<n1){
            if(str1[i]==str2[j]){
                i++,j++;
            }
            else i++;
        }
        if(i==n1 && j==n2) return 1;
        return 0;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),cmp);
        
        vector<int> dp(n,1);
        int maxi=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(compare(words[i],words[j]) && 1 + dp[j]>dp[i]){
                    dp[i] = 1 + dp[j];
                }
            }
            maxi= max(maxi,dp[i]);
        }

        return maxi;
    }
};