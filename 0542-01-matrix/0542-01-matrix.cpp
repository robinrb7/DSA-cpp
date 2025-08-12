class Solution {
    private:

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};
        while(!q.empty()){
            auto p = q.front();
            int row = p.first.first;
            int col = p.first.second;
            int step = p.second;
            q.pop();

            mat[row][col] = step;

            for(int i=0;i<4;i++){
                int nRow = row+dRow[i];
                int nCol = col+dCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && visited[nRow][nCol]==0){
                    q.push({{nRow,nCol},step+1});
                    visited[nRow][nCol]=1;
                }
            }

        }

        return mat;
    }
};