class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n) return "";

        unordered_map<char,int> charFreq;
        for(int i=0;i<m;i++) charFreq[t[i]]++;

        int minLen = INT_MAX, cnt = 0, startIndx = -1;
        int l =0,r=0;
        while(r<n){
            if(charFreq[s[r]]>0) cnt++;
            charFreq[s[r]]--;

            while(cnt==m){
                if(r-l+1 < minLen){
                    minLen = min(minLen,r-l+1);
                    startIndx = l;
                }

                charFreq[s[l]]++;
                if(charFreq[s[l]]>0) cnt--;
                l++;
            }

            r++;
        }
        
        return (startIndx==-1)? "" : s.substr(startIndx,minLen);
    }
};