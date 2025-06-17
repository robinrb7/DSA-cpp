class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0,h = n-1;
        vector<int>res;
        int ans = -1;

        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]==target){
                ans = mid;
                h = mid-1;
            }
            else if(nums[mid]<target) l =mid+1;
            else h=mid-1;
        }
        res.push_back(ans);

        ans = -1;
        l =0,h = n-1;

        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]==target){
                ans = mid;
                l = mid+1;
            }
            else if(nums[mid]<target) l =mid+1;
            else h=mid-1;
        }
        res.push_back(ans);

        return res;
    }
    
};