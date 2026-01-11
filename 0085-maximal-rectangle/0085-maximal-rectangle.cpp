class Solution {
private:
    int solve(vector<int> &arr){
        int maxArea = 0;
        stack<int> st;
        int m = arr.size();

        for(int i=0;i<m;i++){

            while(!st.empty() && arr[i]<arr[st.top()]){
                int currElement = st.top();
                st.pop();

                int nse = i;
                int pse = (st.empty())? -1: st.top();
                
                int height = arr[currElement];
                int width = nse - pse - 1;
                int area = height * width;

                maxArea = max(maxArea,area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = m;
            int currElement = st.top();
                st.pop();

                int pse = (st.empty())? -1: st.top();
                
                int height = arr[currElement];
                int width = nse - pse - 1;
                int area = height * width;

                maxArea = max(maxArea,area);
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int maxi = 0;
        vector<int> arr(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') arr[j] += 1;
                else arr[j] = 0;
            }

            maxi = max(maxi,solve(arr));
        }

        return maxi;
    }

};