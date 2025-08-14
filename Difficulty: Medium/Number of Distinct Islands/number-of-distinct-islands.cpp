// User function Template for C++

class Solution {
    private:
        void dfs(vector<vector<int>>& grid,vector<vector<int>> &visited,int row, int col,vector<pair<int,int>> &vec, int baseRow, int baseCol){
            visited[row][col]=1;
            vec.push_back({row-baseRow,col-baseCol});
            
            int n = grid.size();
            int m = grid[0].size();
            
            int dRow[4] = {-1,1,0,0};
            int dCol[4] = {0,0,-1,1};
            
            for(int i =0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m
                    && grid[nRow][nCol]==1 && visited[nRow][nCol]!=1){
                        dfs(grid,visited,nRow,nCol,vec,baseRow,baseCol);
                }
            }
        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=1){
                    vector<pair<int,int>> vec;
                    dfs(grid,visited,i,j,vec,i,j);
                    s.insert(vec);
                }
            }
        }
        
        return s.size();
        
        
    }
};
