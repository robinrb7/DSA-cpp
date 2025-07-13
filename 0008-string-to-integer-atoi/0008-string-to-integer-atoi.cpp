class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        while(i<n && s[i]==' ')i++;
        bool negSign = 0;
        if(s[i]=='+'||s[i]=='-'){
            negSign = s[i]=='-';
            i++;
        }

        while(i<n && s[i]=='0')i++;
        long long ans = 0;
        while(s[i] >='0' && s[i]<='9'){
            int num = s[i]-'0';
            ans = ans*10 + num;
            if(!negSign && ans >= INT_MAX) return INT_MAX;
            if(negSign && -ans <= INT_MIN) return INT_MIN;

            i++;
        }

        if(negSign) ans = -ans;
        return ans;
    }
};