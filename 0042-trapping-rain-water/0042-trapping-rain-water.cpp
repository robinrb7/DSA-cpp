class Solution {
private:
    void findSuffixMax(vector<int> &height,vector<int> &suffixMax,int n){
        int maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,height[i]);
            suffixMax[i] = maxi;
        }
    }
public:
    int trap(vector<int>& height) {
        int  n = height.size();
        vector<int> suffixMax(n);
        findSuffixMax(height,suffixMax,n);
        
        int prefixMax = INT_MIN;
        int totalWater = 0;
        for(int i=0;i<n;i++){
            prefixMax = max(prefixMax,height[i]);
            int waterToAdd = min(prefixMax,suffixMax[i]);
            waterToAdd = waterToAdd - height[i];
            totalWater += waterToAdd;
        }

        return totalWater;
    }
};