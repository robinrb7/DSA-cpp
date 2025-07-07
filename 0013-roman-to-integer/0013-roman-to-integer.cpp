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

       int i=0;
       int ans=0;
       while(i<n){
            if(i+1<n && (s[i]=='I'||s[i]=='X' || s[i]=='C') && val[s[i]]<val[s[i+1]]){
                ans += val[s[i+1]]-val[s[i]];
                i=i+2;
            }
            else {
                ans += val[s[i]];
                i++;
            }
       }

       return ans;
    }
};