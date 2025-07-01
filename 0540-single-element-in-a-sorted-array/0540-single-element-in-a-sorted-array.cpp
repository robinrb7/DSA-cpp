class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[n-1];

        for(int i =0;i<n;i=i+2){
            if(i!=n-1 && nums[i+1]!=nums[i]){
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};