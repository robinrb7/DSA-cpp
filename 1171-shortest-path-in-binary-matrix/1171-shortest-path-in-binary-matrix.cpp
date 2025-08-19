class Solution {
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int  n= grid.size();
        int m = grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;

        vector<vector<int>> visited(n,vector<int>(m,0));
        int minLen=-1;

        queue<pair<pair<int,int>,int> > q;
        q.push({{0,0},1});
        visited[0][0]=1;

        while(!q.empty()){
            auto[cord, len] = q.front();
            auto[row , col] = cord;
            q.pop();

            if(row==n-1 && col==m-1){
                minLen = len;
                break;
            } 

            int dRow[8] = {-1,1,0,0,-1,-1,1,1};
            int dCol[8] = {0,0,-1,1,-1,1,-1,1};

            for(int i=0;i<8;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&
                    grid[nRow][nCol]==0 && visited[nRow][nCol]==0){
                    q.push({{nRow,nCol},len+1});
                    visited[nRow][nCol]=1;
                }
            }
        }

        return minLen;
    }
};