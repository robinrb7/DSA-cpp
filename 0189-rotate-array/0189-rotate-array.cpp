class Solution {
    private:
    void rev(vector<int> &nums, int s, int e){
        while(s<e){
            swap(nums[s++],nums[e--]);
        }
        return;
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k%n==0) return;
        k = k%n;

        rev(nums,0,n-1-k);
        rev(nums,n-k,n-1);
        rev(nums,0,n-1);
    
    }
};