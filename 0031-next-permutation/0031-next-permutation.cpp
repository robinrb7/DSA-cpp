class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;

        int index=-1;
        for(int i = n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i= n-1;i>index;i--){
            if(nums[i] > nums[index]){
                swap(nums[index],nums[i]);
                break;
            }
        }
        reverse(nums.begin() + index+1,nums.end());

        return;
    }
};