
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> res;
        res.push_back(1);
        
        int ans=1;
        for(int col=1;col<n;col++){
            ans = ans * (n-col)/col;
            res.push_back(ans);
        }
        
        return res;
    }
};
