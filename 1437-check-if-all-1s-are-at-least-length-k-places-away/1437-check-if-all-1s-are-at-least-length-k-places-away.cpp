class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0;
        while(l<n && nums[l]!=1)l++;
        r=l+1;
        while(r<n){
            while(r<n && nums[r]!=1) r++;
            if(r==n) break;
            if((r-l-1)<k) return false;
            l=r;
            r++;
        }

        return true;
    }
};