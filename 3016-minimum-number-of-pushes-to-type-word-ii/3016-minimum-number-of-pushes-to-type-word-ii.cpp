class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n<=8) return n;

        vector<int> charFreq(26,0);
        for(int i=0;i<n;i++) charFreq[word[i]-'a']++;

        sort(charFreq.begin(),charFreq.end(), greater<int>());

        int minPushes=0;
        for(int i=0;i<26;i++){
            minPushes += charFreq[i] * (i/8 +1);
        }

        return minPushes;
    }
};


// time coomplexity -> n + (26 * log(26)) + 26