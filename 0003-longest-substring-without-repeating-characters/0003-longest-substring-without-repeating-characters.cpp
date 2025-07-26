class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n<=1) return n;
        vector<int>hashMap(256,-1);

        int maxLen =0;
        int i=0,j=0;
        while( i<n && j<n){
            if(hashMap[s[j]]!=-1 && hashMap[s[j]] >= i){
                i = hashMap[s[j]] + 1;
            }
            maxLen = max(maxLen, j-i+1);
            hashMap[s[j]] = j;
            j++;
        }

        return maxLen;
    }
};