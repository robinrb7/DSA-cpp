class Solution {
    private:
    int countArr(vector<int>&nums, int k, int maxi){
        int n = nums.size();
        int sum=0, cnt=1;
        for(int i =0;i<n;i++){
            if(nums[i]>maxi) return 1e9;
            if(sum + nums[i] > maxi){
                cnt++;
                sum=0;
            }
            sum += nums[i];
        }
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        int mini= INT_MAX, sum=0;
        for(int i =0;i<n;i++){
            if(nums[i]<mini) mini=nums[i];
            sum += nums[i];
        }

        int low = mini, high = sum;
        while(low<=high){
            int mid = low + (high-low)/2;

            int val = countArr(nums,k,mid);
            if(val <= k){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};