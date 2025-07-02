class Solution {
    private:
    long long func(vector<int>&piles, int mid){
        long long totalH = 0;

        for(int i =0;i<piles.size();i++){
            totalH += (piles[i] + mid-1)/mid;
        }
        return totalH;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            if(piles[i] > maxi) maxi = piles[i];
        }

        int ans = -1;
        int low = 1, high = maxi;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long req = func(piles,mid);

            if(req <= h){
                ans = mid;
                high= mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};