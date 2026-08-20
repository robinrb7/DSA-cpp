class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return {nums[0]};

        vector<int> arr1,arr2;
        arr1.push_back(nums[0]), arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(arr1.back()>arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }


        int i=0;
        int n2= arr2.size();
        while(i<n2){
            arr1.push_back(arr2[i]);
            i++;
        }

        return arr1;
    }
};