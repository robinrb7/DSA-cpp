class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) return nums[i];
            if(i>1 && nums[i]==nums[i-2]) return nums[i];
        }

        return nums[0];
    }
};