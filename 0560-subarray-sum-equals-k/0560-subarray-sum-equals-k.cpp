class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int>hash;
        int count=0,sum=0;
        for(int i =0;i<n;i++){
            sum += nums[i];
            if(sum==k){
                count++;
            }
            if(hash.find(sum-k)!=hash.end()){
                count = count + hash[sum-k];
            }
            
            if(hash.find(sum)!=hash.end()) hash[sum]++;
            else hash[sum]=1;
        }
        
        return count;
    }
};