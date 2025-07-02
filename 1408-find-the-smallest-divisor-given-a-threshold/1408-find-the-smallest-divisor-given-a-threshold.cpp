class Solution {
    bool poss(vector<int>& nums,int mid, int threshold){
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            sum += (nums[i] +mid-1)/mid;
        }
        return sum <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int  n = nums.size();
        if(threshold < n) return -1;

        int low = 1,high = *max_element(nums.begin(),nums.end());

        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(poss(nums,mid,threshold)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};