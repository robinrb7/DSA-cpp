class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        int operations=0;
        while(!is_sorted(nums.begin(),nums.end())){
            int minPairSum=INT_MAX, minPairIndex=-1;

            int n = nums.size();
            for(int i=0;i<n-1;i++){
                int pairSum = nums[i]+nums[i+1];
                if(pairSum < minPairSum){
                    minPairSum = pairSum;
                    minPairIndex=i;
                }
            }

            nums[minPairIndex] = minPairSum;
            nums.erase(nums.begin() + minPairIndex+1);
            operations++;
        }

        return operations;
    }
};