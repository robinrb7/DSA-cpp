class Solution {
private:
    int solve(vector<vector<int>>& triangle,int row, int col, int nRow,vector<vector<int>> &dp){
        if(row==nRow-1) return triangle[row][col];
        if(dp[row][col]!=-1) return dp[row][col];

        int choice1 = triangle[row][col] + solve(triangle,row+1,col,nRow,dp);
        int choice2 = triangle[row][col] + solve(triangle,row+1,col+1,nRow,dp);

        return dp[row][col] = min(choice1,choice2);
    }

    int solveTab(vector<vector<int>>& triangle){
        int nRow = triangle.size();
        vector<int> nextRow(triangle[nRow-1].size(),0);
        vector<int> currRow(triangle[nRow-1].size(),0);

        for(int i=0;i<triangle[nRow-1].size();i++){
            nextRow[i] = triangle[nRow-1][i];
        }

        for(int row=nRow-2;row>=0;row--){
            for(int col=0;col<triangle[row].size();col++){
                int choice1 = triangle[row][col] + nextRow[col];
                int choice2 = triangle[row][col] + nextRow[col+1];

                currRow[col] = min(choice1,choice2);
            }
            nextRow=currRow;
        }
        return nextRow[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return solveTab(triangle);
    }
};