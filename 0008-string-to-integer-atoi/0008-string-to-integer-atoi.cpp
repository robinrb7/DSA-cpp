class Solution {
public:
    int myAtoi(string s) {
        int n= s.length();
        int i=0; bool negSign=0;
        while(i<n && s[i]==' ' ) i++;
        if(s[i]=='-' || s[i]=='+'){
            negSign = (s[i]=='-');
            i++;
        }
    
        while(i<n && s[i]=='0') i++; 

        long long res = 0;
        for(i;i<n;i++){
            if(s[i]<'0' || s[i]>'9') break;
            int num = s[i]-'0';
            res = res*10 + num;

            if(!negSign && res > INT_MAX) return INT_MAX;
            if(negSign && -res < INT_MIN) return INT_MIN;
        }
        if(negSign) res = -res;
        return res;
        
        return res;
    }
};