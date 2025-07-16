class Solution {
    bool solve(vector<vector<char>>& board, string word,int stringIndex, int rowIndex,int colIndex, int row , int col){
        if(stringIndex==word.length()) return true;
        if(rowIndex<0 || rowIndex==row || colIndex==col || colIndex<0 || board[rowIndex][colIndex]!=word[stringIndex] || board[rowIndex][colIndex] =='$'){
            return false;
        } 
        
        char temp = board[rowIndex][colIndex];
        board[rowIndex][colIndex]='$';

        bool right = solve(board,word,stringIndex+1,rowIndex,colIndex+1,row,col);
        bool left = solve(board,word,stringIndex+1,rowIndex,colIndex-1,row,col);
        bool down = solve(board,word,stringIndex+1,rowIndex+1,colIndex,row,col);
        bool up =   solve(board,word,stringIndex+1,rowIndex-1,colIndex,row,col);

        board[rowIndex][colIndex]= temp;
        return (right || left || down || up);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int nRow = board.size();
        int nCol = board[0].size();

        for(int i =0;i<nRow;i++){
            for(int j=0;j<nCol;j++){
                if(solve(board,word,0,i,j,nRow,nCol)) return 1;
            }
        }
       return 0; 
    }
};