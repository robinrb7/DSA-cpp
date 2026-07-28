class Solution {
    private:
    bool static sortReverse(char a , char b){
        return  a > b;
    }
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n==1) return s;
        
        bool hasMiddle = (n&1)? true: false;
        int firstHalfLen = n/2;
        int secondHalfLen = n - firstHalfLen;
        if(hasMiddle) secondHalfLen--;

        string firstHalf = s.substr(0,firstHalfLen);
        string secondHalf = (hasMiddle)? s.substr(firstHalfLen+1,secondHalfLen) : s.substr(firstHalfLen,secondHalfLen);

        sort(firstHalf.begin(),firstHalf.end());
        sort(secondHalf.begin(),secondHalf.end(), sortReverse);

        string ans =  (hasMiddle)? (firstHalf + s[n/2] +  secondHalf) : (firstHalf + secondHalf);
        return ans;
    }
};