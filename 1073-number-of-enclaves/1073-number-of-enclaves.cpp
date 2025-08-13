class Solution {
    private:
    void dfs(vector<vector<int>>& grid,vector<vector<int>> &visited,int row, int col){
        int n =  grid.size();
        int m = grid[0].size();

        visited[row][col]=1;
        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m
                && grid[nRow][nCol]==1 && visited[nRow][nCol]!=1){
                    dfs(grid,visited,nRow,nCol);
                }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int col=0;col<m;col++){
            if(grid[0][col]==1 && visited[0][col]!=1){
                dfs(grid,visited,0,col);
            }

            if(grid[n-1][col]==1 && visited[n-1][col]!=1){
                dfs(grid,visited,n-1,col);
            }
        }
       
        for(int row=1;row<n-1;row++){
            if(grid[row][0]==1 && visited[row][0]!=1){
                dfs(grid,visited,row,0);
            }

            if(grid[row][m-1]==1 && visited[row][m-1]!=1){
                dfs(grid,visited,row,m-1);
            }
        }

        int countNotEscapes=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=1) countNotEscapes++;
            }
        }

        return countNotEscapes;

    }
};