class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> hashMap;

        int maxLen =0;
        int i=0,j=0;
        while(i<n && j<n){
            if((hashMap.find(s[j]) != hashMap.end()) &&  hashMap[s[j]] >=i){
                i = hashMap[s[j]] + 1;
            }
            int len = j-i+1;
            maxLen = max(maxLen,len);
            hashMap[s[j]] = j;
            j++;
        }

        return maxLen;
    }
};