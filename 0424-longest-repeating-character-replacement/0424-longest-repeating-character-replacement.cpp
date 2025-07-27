class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =s.length();

        int l =0;
        int maxLen = 0;
        unordered_map<char,int> freqCnt;
        int maxFreq = 0;

        for(int r=0;r<n;r++){
            freqCnt[s[r]]++;
            if(freqCnt[s[r]] > maxFreq) maxFreq = freqCnt[s[r]];

            int len = r-l+1;
            int replacements = len - maxFreq;
            while(replacements > k){
                freqCnt[s[l]]--;
                l++;
                maxFreq = 0;
                for(auto it : freqCnt){
                    if(it.second> maxFreq) maxFreq = it.second;
                }
                len = r-l+1;
                replacements = len - maxFreq;
            }
            maxLen = max(maxLen,len);
        }

        return maxLen;
    }
};