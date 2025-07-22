class Solution {
    private:
    void prevGreaterElement(vector<int>& height,vector<int>&prefixMax,int n){
        prefixMax[0]=height[0];
        int maxi = prefixMax[0];
        for(int i=1;i<n;i++){
            prefixMax[i] = max(height[i],maxi);
            maxi = prefixMax[i];
        }
    }

    void nextGreaterElement(vector<int>& height,vector<int>&suffixMax,int n){
        suffixMax[n-1] = height[n-1];
        int maxi = suffixMax[n-1];

        for(int i=n-2;i>=0;i--){
            suffixMax[i] = max(height[i],maxi);
            maxi = suffixMax[i];
        }
    }
    
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefixMax(n,-1);
        vector<int>suffixMax(n,-1);

        prevGreaterElement(height,prefixMax,n);
        nextGreaterElement(height,suffixMax,n);

        int width=1;
        int totalWater = 0;
        for(int i=0;i<n;i++){
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];

            if(height[i]< leftMax && height[i]<rightMax){
                totalWater +=(min(leftMax,rightMax) - height[i]) * width;
            }
            
        }

        return totalWater;
    }
};