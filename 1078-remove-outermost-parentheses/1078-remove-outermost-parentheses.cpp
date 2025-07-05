class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        int cnt=0;
        
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt!=0) ans+= s[i];
                cnt++;
            }
            else{
                cnt--;
                if(cnt!=0) ans+= s[i];
            }
        }
        
        return ans;
    }
};