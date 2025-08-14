class Solution {
    private:
        void dfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int row, int col){
            visited[row][col]=1;
            int n = grid.size();
            int m = grid[0].size();
            
            int dRow[4] = {-1,1,0,0};
            int dCol[4] = {0,0,-1,1};
            
            for(int i =0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m
                    && grid[nRow][nCol]=='1' && visited[nRow][nCol]!=1){
                        dfs(grid,visited,nRow,nCol);
                    }
            }
        }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cntIsland = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]!=1){
                    cntIsland++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        
        return cntIsland;
    }
};