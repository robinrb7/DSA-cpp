class Solution {
    private:
    void solve(string s, int index, int n, long long &ans,bool negSign){
        if(index==n || (s[index]<'0' || s[index] > '9')) return;

        if(!negSign && ans >= INT_MAX) return;
        if(negSign && -ans <= INT_MIN) return;

        ans = ans*10 + (s[index]-'0');
        solve(s, index+1,n,ans,negSign);
    }
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
        solve(s,i,n,ans,negSign);

        if(!negSign && ans >= INT_MAX) return INT_MAX;
        if(negSign && -ans <= INT_MIN) return INT_MIN;

        if(negSign) ans = -ans;
        return ans;
    }
};