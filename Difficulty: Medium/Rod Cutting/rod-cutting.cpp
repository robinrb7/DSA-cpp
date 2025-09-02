// User function Template for C++

class Solution {
    private:
    int solve(vector<int> &price, int index, int length,vector<vector<int>> &dp){
        if(length==0) return 0;
        if(index==0){
            return length* price[0];
        }
        if(dp[index][length] != -1) return dp[index][length];
        
        int notTake = 0 + solve(price,index-1,length,dp);
        int take = INT_MIN;
        if(length>=(index+1))
            take = price[index] + solve(price,index,length-(index+1),dp);
            
        return dp[index][length] = max(take,notTake);
    }
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(price,n-1,n,dp);
    }
};