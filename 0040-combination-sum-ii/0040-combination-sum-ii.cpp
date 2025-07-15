class Solution {
    private:
    void solve(vector<int>& candidates, int target,vector<vector<int>> &res,vector<int> temp, int n, int index){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(index==n || target<0) return;


        for(int i =index;i<n;i++){
            if(i!= index && candidates[i]== candidates[i-1]) continue;
            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],res,temp,n,i+1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n= candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> temp;

        solve(candidates,target,res,temp,n,0);

        return res;
    }
};