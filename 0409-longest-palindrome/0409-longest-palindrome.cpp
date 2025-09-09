class Solution {
private:

public:
    int longestPalindrome(string s) {
        int n =s.length();
        int res =0;

        unordered_map<char,int> Freq;
        for(int i=0;i<n;i++){
            Freq[s[i]]++;
            if(Freq[s[i]]%2==0) res +=2;
        }

        for(auto it:Freq){
            if(it.second & 1) return res+1;
        }

        return res;


    }
};