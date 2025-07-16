class Solution {
    private:
    bool isValid(int row, int col,vector<int> &leftRow,vector<int> &lowerDiagonal,vector<int> &upperDiagonal, int n){
        if(leftRow[row]==1 || lowerDiagonal[row+col]==1 || upperDiagonal[col-row + (n-1)]==1) return 0;
        return 1;
    }
    void solve(int col, vector<vector<string>> &res, int n,vector<string> &board,vector<int> &leftRow,vector<int> &lowerDiagonal,vector<int> &upperDiagonal){
        if(col == n){
            res.push_back(board);
            return;
        } 

        for(int row=0;row<n;row++){
            if(isValid(row,col,leftRow,lowerDiagonal,upperDiagonal,n)){
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[col-row + (n-1)] = 1;

                board[row][col] = 'Q';
                solve(col+1,res,n,board,leftRow,lowerDiagonal,upperDiagonal);
                board[row][col] = '.';

                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[col-row + (n-1)] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>board(n,string(n,'.'));

        vector<int>leftRow(n,0);
        vector<int>lowerDiagonal(2*n -1,0);
        vector<int>upperDiagonal(2*n-1,0);
        
        solve(0,res,n,board,leftRow,lowerDiagonal,upperDiagonal);
        return res;
    }
};