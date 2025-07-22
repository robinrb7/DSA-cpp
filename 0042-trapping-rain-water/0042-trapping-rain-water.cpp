class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int width=1;
        int leftMax=0, rightMax=0;
        int totalWater = 0;
        
        int left=0,right=n-1;
        while(left<right){
            if(height[left]<=height[right]){
                if(height[left]<leftMax){
                    totalWater += (leftMax-height[left]) *width;
                }
                leftMax = max(leftMax,height[left]);
                left++;
            }
            else{
                if(height[right]<rightMax){
                    totalWater += (rightMax-height[right]) *width;
                }
                rightMax = max(rightMax,height[right]);
                right--;
            }
        }

        return totalWater;
    }
};