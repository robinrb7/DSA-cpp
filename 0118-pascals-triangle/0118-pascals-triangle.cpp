class Solution {
    private:
    vector<int> findRow(int n){
        vector<int> res;
        res.push_back(1);
        
        int ans=1;
        for(int col=1;col<n;col++){
            ans = ans * (n-col)/col;
            res.push_back(ans);
        }
        
        return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i=0;i<numRows;i++){
            ans.push_back(findRow(i+1));
        }

        return ans;
    }
};