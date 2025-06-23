class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> preSum;
        int count=0,sum=0;
        preSum[0]=1;

        for(int i =0;i<n;i++){
            sum += nums[i];

            if(preSum.find(sum-k) != preSum.end()){
                count = count + preSum[sum-k];
            }

            preSum[sum]++;
        }

        return count;
    }
};