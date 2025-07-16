class Solution {
    private:
    bool isPossible(vector<vector<char>>& board,int row,int col,char ch){
        //for row
        for(int i =0;i<9;i++){
            if(board[row][i]==ch) return false;
        }
        //for col
        for(int i =0;i<9;i++){
            if(board[i][col]==ch) return false;
        }
        //for 3X3 box
        for(int i=0;i<9;i++){
            int rowIndex = (3 * (row/3)) + i/3;
            int colIndex = (3 * (col/3)) + i%3;
            if(board[rowIndex][colIndex]==ch) return false;
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){

                    for(char ch ='1';ch<='9';ch++){
                        if(isPossible(board,i,j,ch)){
                            board[i][j]=ch;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};