class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n =  nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(nums[i]==2){
                ans.push_back(-1);
                continue;
            }

            int num = nums[i];
            for(int j=1;j<num;j++){
                if((j|j+1)==num){
                    ans.push_back(j);
                    break;
                }
            }
        }

        return ans;
    }
};