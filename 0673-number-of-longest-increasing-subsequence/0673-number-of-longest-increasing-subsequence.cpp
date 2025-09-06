class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> dp(n,{1,1}); 
        int maxi = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(nums[i] > nums[j]){
                    if(1 + dp[j].first > dp[i].first){
                        dp[i].first = 1 + dp[j].first;
                        dp[i].second = dp[j].second;
                    }
                    else if (1 + dp[j].first == dp[i].first){
                        dp[i].second += dp[j].second;
                    }
                }
            }
            maxi = max(maxi,dp[i].first);
        }

        int numSeq=0;
        for(int i=0;i<n;i++){
            if(dp[i].first == maxi) numSeq += dp[i].second;
        }

        return numSeq; 
    }
};