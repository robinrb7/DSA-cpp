class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        int i =0;
        while(i<n){
            int j = i+1,k=n-1;
            while(j<k){
                int element  = nums[i]+nums[j]+nums[k];
                if(element==0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);

                    int y =nums[j],x=nums[k];
                    while(j<k && nums[j]==y) j++;
                    while(j<k && nums[k]==x) k--;
                }
                else if(element<0) j++;
                else k--;
            }
            int z = nums[i];
            while(i<n && nums[i]==z)i++;
        }

        return ans;
    }
};