class Solution {
    bool solveTab(vector<int>&nums, int sum){
        int n=nums.size();
        vector<bool>prev(sum+1,0);
        vector<bool>curr(sum+1,0);
        if(nums[0]<=sum) prev[nums[0]]=1;
        
        for(int index=1;index<n;index++){
            prev[0] = curr[0] = 1;
            for(int target=1;target<=sum;target++){
                bool include=0;
                if(target-nums[index]>=0) 
                    include = prev[target-nums[index]];
                bool exclude = prev[target];
        
                curr[target] = include||exclude;
            }
            prev=curr;
        }

        return prev[sum];
    }
public:
    bool canPartition(vector<int>& nums){
        int n= nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++) totalSum += nums[i];
        if(totalSum%2==1) return false;

        int sum = totalSum/2;
        return solveTab(nums,sum);
    }
};