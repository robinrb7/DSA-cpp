class Solution {
    private:
    bool isValid(vector<string> &board, int row, int col, int n){
        int dupRow = row, dupCol = col;
        while(dupCol>=0){
            if(board[dupRow][dupCol--]=='Q') return false;
        }
        dupRow = row, dupCol = col;
        while(dupRow>=0 && dupCol>=0){
            if(board[dupRow--][dupCol--]=='Q') return false;
        }
        dupRow = row, dupCol = col;
        while(dupRow<n && dupCol>=0){
            if(board[dupRow++][dupCol--]=='Q') return false;
        }

        return true;
    }
    void solve(int col, vector<vector<string>> &res, int n,vector<string> &board){
        if(col == n){
            res.push_back(board);
            return;
        } 

        for(int row=0;row<n;row++){
            if(isValid(board,row,col,n)){
                board[row][col] = 'Q';
                solve(col+1,res,n,board);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>board(n,string(n,'.'));
        
        solve(0,res,n,board);
        return res;
    }
};