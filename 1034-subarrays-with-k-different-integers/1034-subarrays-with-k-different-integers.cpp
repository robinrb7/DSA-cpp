class Solution {
    int numSubarrayLooseDistinct(vector<int>& nums, int k){
        if(k<1) return 0;
        int n = nums.size();
        int cnt=0,l=0,r=0;
        unordered_map<int,int> freq;

        while(r<n){
            freq[nums[r]]++;

            while(l<=r && freq.size()>k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0) freq.erase(nums[l]);
                l++;
            }

            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (numSubarrayLooseDistinct(nums,k) - numSubarrayLooseDistinct(nums,k-1));
    }
};