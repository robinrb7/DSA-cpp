class Solution {
    private:
    void transpose(vector<vector<int>>& matrix){
        for(int i = 0;i<matrix.size()-1;i++){
            for(int j=i+1;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);

        for(auto &row:matrix){
            reverse(row.begin(),row.end());
        }
    }
};