class Solution {

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> dp(n,1);
        vector<int> parent(n,-1);

        for(int i=0;i<n;i++){
            for(int prevIndex=0;prevIndex<i;prevIndex++){

                if(nums[i]%nums[prevIndex]==0){
                    if(1 + dp[prevIndex] > dp[i]){
                        dp[i] = 1 + dp[prevIndex];
                        parent[i] = prevIndex;
                    }
                }
            }
        }

        int len=0, startIndex=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>len){
                len = dp[i];
                startIndex=i;
            }
        }

        vector<int> res(len);
        int index=len-1;
        while(startIndex!= -1){
            res[index--] = nums[startIndex];
            startIndex = parent[startIndex];
        }

        return res;
    }
}; 