class Solution {
public:
    string reverseWords(string s) {
        int n =s.length();
        stack<string>st;

        int i=0;
        while(i<n){
            string str="";
            while(i<n && s[i] != ' '){
                str += s[i];
                i++;
            }

            if(!str.empty()) st.push(str);
            i++;
        }

        string ans="";
        while(!st.empty()){
            string top = st.top();
            st.pop();
            if(!st.empty()) ans += top + " ";
            else ans += top;
        }

        return ans;
    }
};