class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ele = -1;
        int i = 0;
        int j = nums.size()-1;
        while(i < j){
            ele = max(ele,nums[i]+nums[j]);
            i++;
            j--;
        }
        return ele;
    }
};