class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return nums[0];

        vector<int> freq(51,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            freq[nums[i]]++;
        }

        if(k==n) return maxi;
        if(k==1){
            maxi = -1;
            for(int i=0;i<n;i++){
                if(freq[nums[i]]==1) maxi = max(maxi,nums[i]);
            }
            return (maxi==-1)? -1: maxi;
        }

        if(freq[nums[0]]==1 && (nums[0]>nums[n-1] || freq[nums[n-1]]!=1) ) return nums[0];
        else if(freq[nums[n-1]]==1 && (nums[0]<nums[n-1] || freq[nums[0]]!=1) ) return nums[n-1];

        return -1;

    }
};