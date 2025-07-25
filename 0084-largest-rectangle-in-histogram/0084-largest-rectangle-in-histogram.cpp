class Solution {
    private:
    void previousSmaller(vector<int>&heights,vector<int>&pse,int n){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i] = st.top();

            st.push(i);
        }
    }
    void nextSmaller(vector<int>&heights,vector<int>&nse,int n){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]) st.pop();
            if(st.empty()) nse[i]=n;
            else nse[i] = st.top();

            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();

        vector<int>pse(n,-1);
        vector<int>nse(n,-1);
        previousSmaller(heights,pse,n);
        nextSmaller(heights,nse,n);

        int maxArea= INT_MIN;
        for(int i=0;i<n;i++){
            int height = heights[i];
            int width = nse[i]-pse[i]-1;
            int area = height * width;

            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};