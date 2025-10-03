class Solution {
private:
    void findPrefixMax(vector<int> &height,vector<int> &prefixMax, int n){
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);
            prefixMax[i] = maxi;
        }

    }
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
        vector<int> prefixMax(n), suffixMax(n);
        findPrefixMax(height,prefixMax,n);
        findSuffixMax(height,suffixMax,n);

        int totalWater = 0;
        for(int i=0;i<n;i++){
            int waterToAdd = min(prefixMax[i],suffixMax[i]);
            waterToAdd = waterToAdd - height[i];
            totalWater += waterToAdd;
        }

        return totalWater;
    }
};