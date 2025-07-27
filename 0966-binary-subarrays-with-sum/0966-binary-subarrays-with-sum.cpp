class Solution {
    int numSubarrayLooseSum(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n = nums.size();
        int sum =0,cnt=0, l=0,r=0;
        while(r<n){
            sum += nums[r];
            while(l<=r && sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }

        return cnt;
        
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (numSubarrayLooseSum(nums,goal) - numSubarrayLooseSum(nums,goal-1));
    }
};