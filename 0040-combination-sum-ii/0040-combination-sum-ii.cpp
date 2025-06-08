class Solution {
    private:
    void solve(vector<int>& cand, int target,vector<vector<int>>&ans,vector<int>&temp,int index, int n){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index>=n || target<0) return;

        for(int i = index;i<n;i++){
            if(i!=index && cand[i]==cand[i-1]) continue;
            
            temp.push_back(cand[i]);
            solve(cand,target-cand[i],ans,temp,i+1,n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n= candidates.size();

        sort(candidates.begin(),candidates.end());
        solve(candidates,target,ans,temp,0,n);
        return ans;
    }
};