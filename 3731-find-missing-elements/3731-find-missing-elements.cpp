class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            int cntMissingNum= nums[i]-nums[i-1]-1;

            for(int j=1;j<=cntMissingNum;j++) ans.push_back(nums[i-1]+j);   
        }

        return ans;
    }
};