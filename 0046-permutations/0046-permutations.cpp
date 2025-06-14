class Solution {
    private:
    void solve(vector<int>& nums,vector<vector<int>> &ans,int index, int n){
        if(index==n){
            ans.push_back(nums);
            return;
        }

        for(int i =index;i<n;i++){
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1,n);
            swap(nums[index],nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        solve(nums,ans,0,nums.size());
        return ans;
    }
};