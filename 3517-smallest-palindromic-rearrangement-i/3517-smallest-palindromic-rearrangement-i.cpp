class Solution {

public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n==1) return s;
        
        bool hasMiddle = (n&1)? true: false;
        int firstHalfLen = n/2;

        string firstHalf = s.substr(0,firstHalfLen);
        sort(firstHalf.begin(),firstHalf.end());
        string ans = firstHalf;
        
        reverse(firstHalf.begin(),firstHalf.end());
    
        ans =  (hasMiddle)? (ans + s[n/2] +  firstHalf) : (ans + firstHalf);
        return ans;
    }
};