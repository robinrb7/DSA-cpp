class Solution {
    private:
    void solve(int k, int target, vector<int>temp, vector<vector<int>>&res, int len, int startIndx){
        if(len==k){
            if(target==0) res.push_back(temp);
            return;
        }

        for(int i = startIndx;i<=9;i++){
            temp.push_back(i);
            solve(k,target-i,temp,res,len+1,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(k<1 || k>9) return res;

        vector<int> temp;
        solve(k,n, temp,res,0,1);
        return res;
    }
};