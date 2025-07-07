class Solution {
  public:
    string reverseWords(string &s) {
        int n = s.length();
        if(n<=1) return s;
        
        int i=0;
        string res ="";
        while(i<n){
            while(i<n && s[i]==' ') i++;
            if(i>=n) break;
            
            int j = i;
            while(i<n && s[i]!=' ')i++;
            string ans = s.substr(j,i-j);
            reverse(ans.begin(),ans.end());
            res += ans + " ";
        }
        
        res.resize(res.length()-1);
        return res;
        
    }
};