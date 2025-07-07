class Solution {
    private:
    int val(char ch){
        switch(ch){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        
        return 0;
    }
public:
    int romanToInt(string s) {
       int n= s.length();

       int i=n-2;
       int ans = val(s[n-1]);
       while(i>=0){
            if(val(s[i])<val(s[i+1])) ans -= val(s[i]);
            else ans += val(s[i]);
            i--;
       }

       return ans;
    }
};