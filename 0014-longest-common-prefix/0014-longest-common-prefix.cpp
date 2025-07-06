class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();

        string prefix = str[0];
        for (int i = 1; i < n; i++) {
            while(str[i].find(prefix) !=0){
                prefix.pop_back();
                if(prefix.empty()){
                    return prefix;
                }
            }
        }

        return prefix;

    }
};