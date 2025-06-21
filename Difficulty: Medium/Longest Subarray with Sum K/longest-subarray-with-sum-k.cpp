class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        
        int n =arr.size();
        map<int,int> preSum;
        int sum = 0, maxLen=0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            
            if(sum==k){
                maxLen = max(maxLen,i+1);
            }
            
            int rem = sum-k;
            if(preSum.find(rem) != preSum.end()){
                maxLen = max(maxLen,i-preSum[rem]);
            }
            
            if(preSum.find(sum)==preSum.end()) preSum[sum] = i;
        }
        
        return maxLen;
    }
};