class Solution {
    int maxRowArea(vector<int>&heights){
        int n = heights.size();
        stack<int>st;
        int maxArea = INT_MIN;
        for(int i =0;i<n;i++){

            while(!st.empty() && heights[i] < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = (st.empty())? i : i - st.top() -1;
                maxArea = max(maxArea,height*width);
            }
            st.push(i);
        }

        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            int width = (st.empty())? n : n - st.top() -1;
            maxArea = max(maxArea,height*width);
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>prefixSum(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum =0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1') sum +=1;
                else sum = 0;
                prefixSum[i][j] = sum;
            }
        }

        int maxMatrixArea = 0;
        for(int i=0;i<n;i++){
            int area = maxRowArea(prefixSum[i]);
            maxMatrixArea = max(maxMatrixArea,area);
        }

        return maxMatrixArea;
    }
};