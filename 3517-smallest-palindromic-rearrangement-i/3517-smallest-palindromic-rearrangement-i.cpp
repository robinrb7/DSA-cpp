class Solution {

public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n==1) return s;
        
        vector<int> count(26,0);
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }

        char oddChar = '$';
        int index=0;

        for(int i=0;i<26;i++){
            if(count[i]==0) continue;
            if(count[i]&1) oddChar = i+'a';

            int limit = count[i]/2;
            char ch = i + 'a';
            for(int j=index; j<(index + limit); j++){
                s[j]= ch;
                s[n-j-1]= ch;
            }

            index += limit;
            if(index==n/2) break;
        }

        if(oddChar != '$') s[n/2] = oddChar;
        return s;
    }
};