class Solution {
    private:
    bool isEqual(vector<int> &freq, vector<int> &freqW){
        for(int i =0;i<freq.size();i++){
            if(freq[i]!=freqW[i]) return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int>freq(26,0);
        for(int i =0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }

        int windSize = s1.length();
        vector<int>freqW(26,0);

        for(int i =0;i<windSize;i++){
            freqW[s2[i]-'a']++;
        }
        if (isEqual(freq,freqW)) return true;

        for(int i =windSize;i<s2.length();i++){
            freqW[s2[i]-'a']++;
            freqW[s2[i-windSize]-'a']--;

            if (isEqual(freq,freqW)) return true;

        }

        return false;
    }
};