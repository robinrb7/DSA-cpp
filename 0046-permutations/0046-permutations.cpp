class Solution {
    private:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &temp, int index, int n,vector<int> & visited){
        if(index==n){
            ans.push_back(temp);
            return;
        }

        for(int i =0;i<n;i++){
            if(!visited[i]){
                temp.push_back(nums[i]);
                visited[i]=1;
                solve(nums,ans,temp,index+1,n,visited);
                temp.pop_back();
                visited[i]=0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        vector<int> temp;
        vector<int>visited(nums.size(),0);
        solve(nums,ans,temp,0,nums.size(),visited);
        return ans;
    }
};