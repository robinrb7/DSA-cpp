class Solution {
private:
    bool isPossible(int num1,int num2,int num3){
        if(num1+num2>num3 && num2+num3>num1 && num1+num3>num2) return 1;
        return 0;
    }
    
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int k=n-1;k>=2;k--){
            if(isPossible(nums[k],nums[k-1],nums[k-2])) return nums[k] + nums[k-1] + nums[k-2];
        }

        return 0;
    }
};