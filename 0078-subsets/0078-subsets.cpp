class Solution {
    void solve(vector<int>& nums,vector<int> &temp,vector<vector<int>> &res, int index, int n){
        if(index==n) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        solve(nums,temp,res,index+1,n);
        temp.pop_back();

        solve(nums,temp,res,index+1,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n==0) return res;

        vector<int>temp;
        solve(nums,temp,res,0,n);
        return res;
    }
};