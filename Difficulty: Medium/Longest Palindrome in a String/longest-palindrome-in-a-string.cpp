class Solution {
    private:
    bool checkPalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
  public:
    string longestPalindrome(string &s) {
        int n =s.length();
        
        string ans ="";
        int maxLen=1;
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(checkPalindrome(s,i,j)){
                    if((j-i+1) > maxLen){
                        maxLen = j-i+1;
                        ans = s.substr(i,maxLen);
                    }
                }
            }
        }
        
        return ans;
        
    }
};