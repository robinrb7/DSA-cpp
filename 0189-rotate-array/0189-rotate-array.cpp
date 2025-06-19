class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k%n==0) return;
        k = k%n;

        vector<int>temp;
        for(int i =n-k;i<n;i++){
            temp.push_back(nums[i]);
        }

        for(int i =n-1-k;i>=0;i--){
            nums[i+k] = nums[i];
        }

        int i=0;
        while(k--){
            nums[i] = temp[i];
            i++;
        }
    
    }
};