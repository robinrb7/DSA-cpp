class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;

        int maxLen=0;
        int i=0,j=0;
        while(j<n){
            if(freq[nums[j]]+1 <=k) {
                freq[nums[j]]++;
                j++;
                maxLen = max(maxLen,j-i);
            }
            else{
                while(i<j){
                    freq[nums[i]]--;
                    i++;
                    if(freq[nums[j]]<=k) break;
                }
            }
        }

        return maxLen;
    }
};