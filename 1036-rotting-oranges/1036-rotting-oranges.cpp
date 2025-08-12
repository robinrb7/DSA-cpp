class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int> >q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                if(grid[i][j]==1) visited[i][j]=1;
            }
        }

        int maxTime = 0;
        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            maxTime = max(maxTime,time);

            for(int k=0;k<4;k++){
                int nRow = row + dRow[k];
                int nCol = col + dCol[k];

                if(nRow<n && nRow>=0 && nCol<m && nCol>=0 
                    && grid[nRow][nCol]==1 && visited[nRow][nCol]!=2 ){
                    q.push({{nRow,nCol},time+1});
                    visited[nRow][nCol]=2; 
                  }
            }
        }

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1 && visited[i][j]!=2) return -1;
                }
            }

            return maxTime;
        }
};