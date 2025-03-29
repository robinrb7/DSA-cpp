class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;

        int n= matrix.size();
        int m =  matrix[0].size();
        int totalCnt = n*m;

        int stRow = 0, stCol =0, endRow =n-1,endCol =m-1;

        while(totalCnt>0){
            for(int j = stCol;j<=endCol && totalCnt>0;j++){
                ans.push_back(matrix[stRow][j]);
                totalCnt--;
            }
            stRow++;

            for(int i = stRow;i<=endRow && totalCnt>0;i++){
                ans.push_back(matrix[i][endCol]);
                totalCnt--;
            }
            endCol--;

            for(int j = endCol;j>=stCol && totalCnt>0;j--){
                ans.push_back(matrix[endRow][j]);
                totalCnt--;
            }
            endRow--;

            for(int i = endRow;i>=stRow && totalCnt>0;i--){
                ans.push_back(matrix[i][stCol]);
                totalCnt--;
            }
            stCol++;
        }

        return ans;
    }
};