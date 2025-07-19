class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];

        int res=0;
        for(int bit=0;bit<32;bit++){
            int count1 = 0;
            for(int i=0;i<n;i++){
                if(nums[i] & (1<<bit)) count1++;
            }
            if(count1%3==1){
                res = res |(1<<bit);
            }
        }

        return res;
    }
};