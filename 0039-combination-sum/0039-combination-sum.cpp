class Solution {
    private:
    void solve(vector<int>&cand, int target, vector<vector<int>>&ans, vector<int>&temp,int n, int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;

        for(int i = index;i<n;i++){
            temp.push_back(cand[i]);
            solve(cand,target-cand[i],ans,temp,n,i);

            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(candidates,target,ans,temp,candidates.size(),0);
        return ans;
    }
};