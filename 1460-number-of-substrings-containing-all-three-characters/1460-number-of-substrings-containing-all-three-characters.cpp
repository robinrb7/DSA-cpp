class Solution {
public:
    int numberOfSubstrings(string s) {
        int n =s.length();
        vector<int> charLastSeenIndex(3,-1);
        int cnt=0;
        
        for(int i =0;i<n;i++){
            charLastSeenIndex[s[i]-'a'] = i;

            if(charLastSeenIndex[0]!=-1 && charLastSeenIndex[1]!=-1 && charLastSeenIndex[2]!=-1){
                cnt += 1 + min(min(charLastSeenIndex[0],charLastSeenIndex[1]),charLastSeenIndex[2]);
            }
        }
        return cnt;
    }
};