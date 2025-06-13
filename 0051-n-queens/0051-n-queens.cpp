class Solution {
    private:
    bool isSafe(vector<string> &board, int row, int col, int n){
        int i = row, j= col;
        while(j>=0){
            if(board[i][j]=='Q') return false;
            j--;
        }

        i = row, j= col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }

        i = row, j= col;
        while(i<n && j>=0){
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }

        return true;
    }
    
    void solve(int n,vector<string> &board, vector<vector<string>> &ans,int col){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row =0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col] = 'Q';
                solve(n,board,ans,col+1);
                board[row][col] = '.';
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;

        solve(n,board,ans,0);
        return ans;
    }
};