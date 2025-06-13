class Solution {
    private:
    void solve(int n,vector<string> &board, vector<vector<string>> &ans,int col,vector<int>&leftRow,vector<int>&upDiagonal,vector<int>&lowDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row =0;row<n;row++){
            if(leftRow[row] ==0 && upDiagonal[n-1+row-col]==0 && lowDiagonal[row+col]==0){
                board[row][col] = 'Q';

                leftRow[row] = 1;
                upDiagonal[n-1+row-col]=1;
                lowDiagonal[row+col]=1;

                solve(n,board,ans,col+1,leftRow,upDiagonal,lowDiagonal);
                board[row][col] = '.';

                leftRow[row] = 0;
                upDiagonal[n-1+row-col]=0;
                lowDiagonal[row+col]=0;
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;

        vector<int>leftRow(n,0);
        vector<int>upDiagonal(2*n-1,0);
        vector<int>lowDiagonal(2*n-1,0);

        solve(n,board,ans,0,leftRow,upDiagonal,lowDiagonal);
        return ans;
    }
};