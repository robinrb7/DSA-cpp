class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>umap;
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(umap.find(target-nums[i])!=umap.end()){
                ans.push_back(umap[target-nums[i]]);
                ans.push_back(i);
            }
            else{
                umap[nums[i]] = i;
            }
        }

        return ans; 
    }
};