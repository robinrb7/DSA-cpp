class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = INT_MIN;
        int left = 0, right = n-1;

        while(left < right){
            if(height[left] < height[right]){
                maxArea = max(maxArea, height[left] * (right-left));
                left++;
            }
            else{
                maxArea = max(maxArea, height[right] * (right-left));
                right--;
            }
        }

        return maxArea;
    }
};