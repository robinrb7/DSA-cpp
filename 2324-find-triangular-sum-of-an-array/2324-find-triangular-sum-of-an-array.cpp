class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n),curr(n);
        for(int i=0;i<n;i++) prev[i]=nums[i];

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<i;j++){
                nums[j] = (nums[j] + nums[j+1]) %10;
            }
        }
        return nums[0];
    }
};