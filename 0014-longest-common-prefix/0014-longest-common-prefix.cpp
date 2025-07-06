class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();

        int minLen = str[0].size();
        for (int i = 1; i < n; i++) {
            if (str[i].length() < minLen) minLen = str[i].length();
        }

        for (int i = 0; i < minLen; i++) {
            char ch = str[0][i];
            for (int j = 1; j < n; j++) {
                if (str[j][i] != ch) {
                    minLen = i;
                    break;
                }
            }
        }

        string ans = str[0].substr(0, minLen);
        return ans;
    }
};