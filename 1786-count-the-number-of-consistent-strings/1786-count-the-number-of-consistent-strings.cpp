class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size();
        int m = allowed.length();
        vector<bool> charFreq(26,0);
        for(int i=0;i<m;i++){
            charFreq[allowed[i]-'a'] =1;
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            bool found = 1;
            for(int j=0;j<words[i].length();j++){
                char ch = words[i][j];
                if(!charFreq[ch-'a']){
                    found=0;
                    break;
                } 
            }
            if(found)cnt += 1;
        }

        return cnt;
    }
};