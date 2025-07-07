class Solution {
    private:
    void insertVal(unordered_map<char,int> &val){
        val['I']=1;
        val['V']=5;
        val['X']=10;
        val['L']=50;
        val['C']=100;
        val['D']=500;
        val['M']=1000;
    }
public:
    int romanToInt(string s) {
       int n= s.length();

       unordered_map<char,int> val;
       insertVal(val);

       int i=n-2;
       int ans= val[s[n-1]];
       while(i>=0){
            if(val[s[i]]<val[s[i+1]]) ans -= val[s[i]];
            else ans += val[s[i]];
            i--;
       }

       return ans;
    }
};