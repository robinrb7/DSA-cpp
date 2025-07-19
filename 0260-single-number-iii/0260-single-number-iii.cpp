class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n= nums.size();

        long xorAll=0;
        for(int i=0;i<n;i++) xorAll = xorAll^nums[i];
        
        int rightmostSetBit = (xorAll & xorAll-1) ^ xorAll;
        int bucket1=0,bucket2=0;

        for(int i=0;i<n;i++){
            if(nums[i] & rightmostSetBit) bucket1 = bucket1^nums[i];
            else bucket2 = bucket2^nums[i];
        }

        return {bucket1,bucket2};

    }
};