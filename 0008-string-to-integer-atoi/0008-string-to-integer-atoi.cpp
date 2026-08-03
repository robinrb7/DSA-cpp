class Solution {
    private:
    void solve(string &s,int index, int n, long long &num, bool neg){
        if(index==n) return;
        if(s[index]<'0' || s[index]>'9') return;

        if(!neg && num>=INT_MAX) return;
        if(neg && -num<=INT_MIN) return;

        num = num*10 + (s[index]-'0');
        solve(s,index+1,n,num,neg);
    }
public:
    int myAtoi(string s) {
        int n = s.length();
        
        bool neg=0;
        int i=0;
        while(i<n && s[i]==' ') i++;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            neg = (s[i]=='-')? 1:0;
            i++;
        }

        long long num=0;
        solve(s,i,n,num,neg);

        if(!neg && num>=INT_MAX) return INT_MAX;
        if(neg && -num<=INT_MIN) return INT_MIN;

        return (neg)? -num: num;
    }
};