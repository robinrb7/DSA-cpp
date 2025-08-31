class Solution {
    bool solve(vector<int>arr, int target, int index,vector<vector<int>> &dp){
        if(target==0) return 1;
        if(target<0) return 0;
        if(index==0){
            if(arr[0]==target) return 1;
            else return 0;
        };
        if(dp[index][target] != -1) return dp[index][target];

        bool include = solve(arr,target-arr[index],index-1,dp);
        bool exclude = solve(arr,target,index-1,dp);

        return dp[index][target] = include||exclude;
    }
    
    bool solveTab(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        dp[0][arr[0]]=1;
        
        for(int index=1;index<n;index++){
            for(int target=1;target<=sum;target++){
                bool include=0;
                if(target-arr[index]>=0) 
                    include = dp[index-1][target-arr[index]];
                bool exclude = dp[index-1][target];
        
                dp[index][target] = include||exclude;
            }
        }

        return dp[n-1][sum];
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
         return solveTab(arr,sum);
    }
};