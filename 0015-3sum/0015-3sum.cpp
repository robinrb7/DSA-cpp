class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i=0;

        while(i<n){
            int j=i+1,k=n-1;
            while(j<k){
                int element = nums[i]+nums[j]+nums[k];
                if(element==0){
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);

                    int y=nums[j],z=nums[k];
                    while(j<k && nums[j]==y)j++;
                    while(j<k && nums[k]==z)k--;
                }
                else if(element<0) j++;
                else k--;
            }
            int x =nums[i];
            while(i<n && nums[i]==x)i++;
        }

        return ans;
    }
};