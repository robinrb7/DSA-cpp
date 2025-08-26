class Solution {
private:
    int solveMemOpt(vector<int>& nums){
        int n =nums.size();
        int prev1=nums[0];
        int prev2=0;
        int curr = -1;

        for(int index=1;index<n;index++){
            int pick = nums[index];
            if(index>=2) pick += prev2;
            int notPick = 0 + prev1;

           curr =  max(pick,notPick);
           prev2=prev1;
           prev1=curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=n-1) temp1.push_back(nums[i]);
            if(i!=0) temp2.push_back(nums[i]);
        }

        return max(solveMemOpt(temp1),solveMemOpt(temp2));
    }
};