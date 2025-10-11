class Solution {

public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        bool sorted = 1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                sorted = false;
                break;
            }
        }
        if(sorted) return 0;

        int k = -1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                if(k==-1) k=nums[i];
                else k = k & nums[i];
            }
        }
        return k;
    }
};