class Solution {
    private:
    vector<int> prefixMax(vector<int>& height){
        int n= height.size();
        vector<int> ans(n);
        ans[0]=height[0];
        int maxi = ans[0];
        for(int i =1;i<n;i++){
            maxi = max(maxi,height[i]);
            ans[i]=maxi;
        }
        return ans;
    }
    vector<int> suffixMax(vector<int>& height){
        int n= height.size();
        vector<int> ans(n);
        ans[n-1]=height[n-1];
        int maxi = ans[n-1];
        for(int i =n-2;i>=0;i--){
            maxi = max(maxi,height[i]);
            ans[i]=maxi;
        }
        return ans;
    }
public:
    int trap(vector<int>& height) {
        vector<int>prefix = prefixMax(height);
        vector<int>suffix = suffixMax(height);

        int total = 0;
        for(int i =0;i<height.size();i++){
            if(height[i]<prefix[i] && height[i]<suffix[i]){
                total += min(prefix[i],suffix[i])-height[i]; 
            }
        }

        return total;
    }
};