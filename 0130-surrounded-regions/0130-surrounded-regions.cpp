class Solution {
    private:
    void dfs(vector<vector<char>>& board,vector<vector<int>> &visited, int row, int col){
        int n = board.size();
        int m = board[0].size();

        visited[row][col]=1;
        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m 
                && board[nRow][nCol]=='O' &&  visited[nRow][nCol]!=1){
                    dfs(board,visited,nRow,nCol);
            }
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int col=0;col<m;col++){
            if(board[0][col]=='O' && visited[0][col]!=1){
                dfs(board,visited,0,col);
            }
        }
        for(int col=0;col<m;col++){
            if(board[n-1][col]=='O' && visited[n-1][col]!=1){
                dfs(board,visited,n-1,col);
            }
        }
        for(int row=1;row<n-1;row++){
            if(board[row][0]=='O' && visited[row][0]!=1){
                dfs(board,visited,row,0);
            }
        }
        for(int row=1;row<n-1;row++){
            if(board[row][m-1]=='O' && visited[row][m-1]!=1){
                dfs(board,visited,row,m-1);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==0) board[i][j]='X';
            }
        }
    }
};