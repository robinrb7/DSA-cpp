class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n =s.length();
        
        int maxLen = -1,l=0,r=0;
        unordered_map<char,int> charFreq;
        
        while(r<n){
            charFreq[s[r]]++;
            if(charFreq.size()>k){
                charFreq[s[l]]--;
                if(charFreq[s[l]]==0) charFreq.erase(s[l]);
                l++;
            }
            if(charFreq.size()==k) maxLen = max(maxLen,r-l+1);
            r++;
        }
        
        return maxLen;
    }
};