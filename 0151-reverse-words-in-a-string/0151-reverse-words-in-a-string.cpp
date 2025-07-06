class Solution {
public:
    string reverseWords(string s) {
        int n =s.length();

        string ans= "";
        int i=n-1;
        while(i>=0){
            while(i>=0 && s[i]==' ')i--;
            if(i<0) break;

            int j=i;
            while(i>=0 && s[i]!=' ')i--;
            ans += s.substr(i+1,j-i) + " ";

            i--;
        }

        ans.resize(ans.length()-1);
        return ans;
    }
};