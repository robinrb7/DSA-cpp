class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low =0,high=n-1;

        int mini = INT_MAX;

        while(low < high){
            int mid = low + (high-low)/2;

            if(nums[low] <= nums[high]) break;

            if(nums[mid] >= nums[0]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }

        return nums[low];
    }
};