class Solution {
    private:
    bool poss(vector<int>&nums, int k, int maxi){
        int n = nums.size();
        int sum=0, cnt=1;
        for(int i =0;i<n;i++){
            if(nums[i]>maxi) return 0;
            if(sum + nums[i] > maxi){
                cnt++;
                sum=0;
            }
            sum += nums[i];
            if(cnt>k) return 0;
        }
        return 1;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        if(k>n) return -1;
        int mini= INT_MAX, sum=0;
        for(int i =0;i<n;i++){
            if(nums[i]<mini) mini=nums[i];
            sum += nums[i];
        }

        int low = mini, high = sum;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(poss(nums,k,mid)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};