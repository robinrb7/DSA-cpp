class Solution {
public:
    string reverseWords(string s) {
        int n =s.length();

        int i=0,j=0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            while(i<n && s[i] !=' ') s[j++]=s[i++];
            while(i<n && s[i]==' ')i++;
            if(i<n) s[j++]=' ';
        }
        s.resize(j);

        reverse(s.begin(),s.end());
        int start=0;
        for(int end=0;end<=s.size();end++){
            if(s[end]==' ' || end == s.size()){
                reverse(s.begin()+start,s.begin()+end);
                start = end+1;
            }
        }

        return s;
    }
};