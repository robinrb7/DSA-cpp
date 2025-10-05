class Solution {
private:
    void dfs(vector<vector<int>>& heights,vector<vector<int>>& visited,int row, int col,int n, int m){

        visited[row][col] = 1;
        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1}; 

        for(int i =0;i<4;i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m 
                && (heights[nRow][nCol] >= heights[row][col]) && !visited[nRow][nCol]){
                dfs(heights,visited,nRow,nCol,n,m);
            }

        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> visitedPacific(n,vector<int>(m,0));
        vector<vector<int>> visitedAtlantic(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(!visitedPacific[i][0]) dfs(heights,visitedPacific,i,0,n,m);
            if(!visitedAtlantic[i][m-1]) dfs(heights,visitedAtlantic,i,m-1,n,m);
        }
        for(int j=0;j<m;j++){
            if(!visitedPacific[0][j]) dfs(heights,visitedPacific,0,j,n,m);
            if(!visitedAtlantic[n-1][j]) dfs(heights,visitedAtlantic,n-1,j,n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visitedPacific[i][j]==1 && visitedAtlantic[i][j]==1) res.push_back({i,j});
            }
        }

        return res;


    }
};