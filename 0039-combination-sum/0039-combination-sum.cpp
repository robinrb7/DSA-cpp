class Solution {
    private:
    void solve(vector<int>& candidates, int target, int index,vector<int>temp,vector<vector<int>> &res, int n){
        if(target==0) {
            res.push_back(temp);
            return;
        }

        if(index==n || target<0) return;

        for(int i = index;i<n;i++){
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i,temp,res,n);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());

        vector<int>temp;
        vector<vector<int>> res;

        solve(candidates,target,0,temp,res,n);
        return res;
    }
};