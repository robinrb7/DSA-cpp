class Solution {
    int numSubarrayLooseOdd(vector<int>& nums, int k){
        if(k<0) return 0;
        int n =nums.size();
        int oddCnt=0,cnt=0;
        int l=0,r=0;
        while(r<n){
            if(nums[r]&1) oddCnt++;

            while(oddCnt>k){
                if(nums[l]&1) oddCnt--;
                l++;
            }

            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (numSubarrayLooseOdd(nums,k) - numSubarrayLooseOdd(nums,k-1));
    }
};