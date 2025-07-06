class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();

        int maxi=INT_MIN;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++;
            if(s[i]==')') cnt--;
            
            if(cnt > maxi) maxi = cnt;
        }

        return maxi;
    }
};