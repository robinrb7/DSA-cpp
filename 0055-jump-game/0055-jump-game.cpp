class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 1;

        int maxIndex = 0;
        for(int i=0;i<n;i++){
            if(i > maxIndex) return false;
            maxIndex = max(maxIndex,nums[i]+i);
        }

        return true;
    }
};