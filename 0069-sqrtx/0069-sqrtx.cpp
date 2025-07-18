class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int low = 1,high = x;
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;
            long long num  = 1ll*mid*mid;

            if(num <= x){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return ans;
    }
};