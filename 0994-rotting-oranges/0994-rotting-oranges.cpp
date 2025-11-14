class Solution {
private:
    bool isValid(int n,int m,int nRow,int nCol){
        if(nRow>=0 && nRow<n && nCol>=0 && nCol<m) return 1;
        return 0;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    visited[i][j]=2;
                }
            }
        }

        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};
        int minTime=0;

        while(!q.empty()){
            auto[time, cord] = q.front();
            auto[row,col] = cord;
            q.pop();
            
            minTime = max(minTime,time);

            for(int i=0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(isValid(n,m,nRow,nCol) && grid[nRow][nCol]==1 && !visited[nRow][nCol]){
                    visited[nRow][nCol]=2;
                    q.push({time+1,{nRow,nCol}});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=2) return -1;
            }
        }

        return minTime;
    }
};