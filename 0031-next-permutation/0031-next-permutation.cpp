class Solution {
    private:
    int justGreater(vector<int>&nums, int start, int n){
        int pivot = nums[start-1];
        int mini = INT_MAX;
        int minIndx = -1;
        for(int i = start;i<n;i++){
            if(nums[i]>pivot && nums[i]<=mini){
                mini = nums[i];
                minIndx = i;
            }
        }
        return minIndx;
    }

public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot =i;
                break;
            }
        }
        if(pivot==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        int nextPivot = justGreater(nums,pivot+1,n);
        swap(nums[pivot],nums[nextPivot]);

        int i = pivot+1, j=n-1;
        while(i<=j){
            swap(nums[i++],nums[j--]);
        }

        return;
    }
};