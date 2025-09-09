class Solution {
private:
    int solve(vector<int> &arr,int k, int i,vector<int> &dp){
        int n = arr.size();
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];

        int maxi =INT_MIN;
        int len=0, maxElement=INT_MIN;
        for(int index=i;index<min(n,i+k);index++){
            len++;
            maxElement = max(maxElement,arr[index]);
            int sum = (len*maxElement) + solve(arr,k,index+1,dp);
            maxi = max(maxi,sum);
        }

        return dp[i] = maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k){
        int n =arr.size();

        vector<int> dp(n,-1);
        return solve(arr,k,0,dp);
    }
};