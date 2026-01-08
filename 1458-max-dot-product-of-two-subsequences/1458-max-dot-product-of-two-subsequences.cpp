class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int index1,int index2,vector<vector<int>> &dp){
        if(index1<0 || index2<0) return INT_MIN;
        if(dp[index1][index2]!=-1) return dp[index1][index2];

        int include = (nums1[index1]*nums2[index2]);

        if(index1>=0 && index2>=0) include += max(0,solve(nums1,nums2,index1-1,index2-1,dp));
        int exclude1 = 0 + solve(nums1,nums2,index1-1,index2,dp);
        int exclude2 = 0 + solve(nums1,nums2,index1,index2-1,dp);

        return dp[index1][index2] = max(include,max(exclude1,exclude2));
    }

    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int index1=0;index1<n;index1++){
            for(int index2=0;index2<m;index2++){
                int include = (nums1[index1]*nums2[index2]);

                if(index1>0 && index2>0) include += max(0,solve(nums1,nums2,index1-1,index2-1,dp));
                int exclude1 = 0 + solve(nums1,nums2,index1-1,index2,dp);
                int exclude2 = 0 + solve(nums1,nums2,index1,index2-1,dp);

                dp[index1][index2] = max(include,max(exclude1,exclude2));
            }
        }

        return dp[n-1][m-1];
    }



public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m=nums2.size();
        
        return solveTab(nums1,nums2);
    }
};