class Solution {
    private:
    pair<int,int> expand(string &s, int left, int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--, right++;
        }
        return {left+1,right-1};
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1) return s;
        
        int maxLen = 0, startIndx = -1;
        string res ="";
        for(int i =0;i<n;i++){
            pair<int,int> odd = expand(s,i,i);
            pair<int,int> even = expand(s,i,i+1);
            
            int oddLen = odd.second - odd.first +1;
            int evenLen = even.second - even.first +1;
            
            if(oddLen > evenLen && oddLen>maxLen){
                maxLen = oddLen;
                startIndx = odd.first;
            }
            else{
                if(evenLen > maxLen){
                    maxLen = evenLen;
                    startIndx = even.first;
                }
            }
        }
        
        return s.substr(startIndx, maxLen);
    }
};