class Solution {
public:
    string removeKdigits(string num, int k) {
        int n= num.length();
        if(k>=n) return "0";

        stack<char>st;
        int i=0;
        while(i<n){
            while(!st.empty() && k>0 && (num[i]-'0' < st.top()-'0')){
                k--;
                st.pop();
            }
            if(k==0) break;
            st.push(num[i]);
            i++;
        }

        while(k==0 && i<n) st.push(num[i++]);
        while(i==n && k>0) {
            st.pop();
            k--;
        }

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        while(!res.empty() && res.back()=='0') res.pop_back();
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";
        return res;
    }
};