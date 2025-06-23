class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        int rowS=0,rowE=n-1,colS=0,colE=m-1;
        vector<int> ans;

        while(rowS<=rowE && colS<=colE){
            for(int i =colS;i<=colE;i++){
                ans.push_back(matrix[rowS][i]);
            }
            rowS++;

            for(int i =rowS;i<=rowE;i++){
                ans.push_back(matrix[i][colE]);
            }
            colE--;

            if(rowS<=rowE){
                for(int i =colE;i>=colS;i--){
                    ans.push_back(matrix[rowE][i]);
                }
                rowE--;
            }
            
            if(colS<=colE){
                for(int i =rowE;i>=rowS;i--){
                    ans.push_back(matrix[i][colS]);
                }
                colS++;
                }
            
        }

        return ans;
    }
};