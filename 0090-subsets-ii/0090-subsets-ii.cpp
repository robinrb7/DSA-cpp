class Solution {
    private:
    void solve(vector<int>&nums,int index, int n,vector<vector<int>>&ans,vector<int>&temp){
        if(index>=n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        solve(nums,index+1,n,ans,temp);
        temp.pop_back();

        while(index+1 < n && nums[index] == nums[index+1]) index++;
        solve(nums,index+1,n,ans,temp);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int> >ans;
        vector<int>temp;
        solve(nums,0,nums.size(),ans,temp);

        sort(ans.begin(),ans.end());
        return ans;
    }
};