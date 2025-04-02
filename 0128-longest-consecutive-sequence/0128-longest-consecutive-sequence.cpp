class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());  
        int longest = 0;

        for (int num : st) {
            // Only process if it's the start of a sequence
            if (st.find(num - 1) == st.end()) {  
                int x = num;
                int count = 1;

                while (st.find(x+1) != st.end()) {
                    x++;
                    count++;
                }

                longest = max(longest, count);
            }
        }
        return longest;
    }
};
