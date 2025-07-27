class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =s.length();

        int l =0, maxLen =0, maxFreq = 0;
        vector<int> charFreq(26,0);

        for(int r=0;r<n;r++){
            charFreq[s[r]-'A']++;
            if(charFreq[s[r]-'A'] > maxFreq) maxFreq = charFreq[s[r]-'A'];

            int len = r-l+1;
            int replacements = len - maxFreq;
            if(replacements > k){
                charFreq[s[l]-'A']--;
                l++;
            }
            if(replacements<=k) maxLen = max(maxLen,len);
        }

        return maxLen;
    }
};