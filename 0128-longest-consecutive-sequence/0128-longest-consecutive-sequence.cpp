class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;

        unordered_set<int> st;
        for(int i =0;i<n;i++){
            st.insert(nums[i]);
        }

        int maxLen=1;

        for(auto it : st){
            int len =1;
            if(st.find(it-1) == st.end()){
                int el = it;
                while(st.find(el+1) != st.end()){
                    len++;
                    el++;
                }
            } 

            maxLen = max(maxLen,len);
        }

        return maxLen;
    }
};