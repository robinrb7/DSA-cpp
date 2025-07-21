class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int>st;

        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else{
                if(st.empty()) return false;
                char top = st.top();
                if((top=='(' && ch!=')') || (top=='{' && ch!='}') || (top=='[' && ch!=']')) return false;
                st.pop();
            }
        }

        if(!st.empty()) return false;
        return true;
    }
};