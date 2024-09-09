class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        int totalSum=0;
        int leftSum=0,rightSum=0;
        for(auto num:nums){
            totalSum+=num;
        }

        for(int i =0;i<nums.size();i++){
            rightSum = totalSum -leftSum -nums[i];

            if(rightSum == leftSum){
            return i;
            }
            leftSum += nums[i];
        }
         
        return -1;
    }
};