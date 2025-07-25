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

        stack<int>st;

        int maxArea= INT_MIN;
        for(int i=0;i<n;i++){

            while(!st.empty() && heights[i] < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width=0;
                if(!st.empty()) width = i - st.top() - 1;
                else width = i - (-1) - 1;
                int area = height * width;
                maxArea = max(maxArea,area);
            }

            st.push(i);
        }

        while(!st.empty()){
            int height = heights[st.top()];
                st.pop();
                int width=0;
                if(!st.empty()) width = n - st.top() - 1;
                else width = n - (-1) - 1;
                int area = height * width;
                maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};