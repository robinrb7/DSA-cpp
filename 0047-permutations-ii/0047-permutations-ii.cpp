class Solution {
    private:
    void solve(vector<int>& nums,vector<vector<int>> &ans,int index, int n){
        if(index==n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        
        for(int i =index;i<n;i++){
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1,n);
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(nums,ans,0,nums.size());
        return ans;
    }
};