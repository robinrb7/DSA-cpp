class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int low = 0, high = nums.size() - 2;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == nums[mid ^ 1]) // clever trick
                low = mid + 1;
            else
                high = mid - 1;
        }

        return nums[low];
    }
};