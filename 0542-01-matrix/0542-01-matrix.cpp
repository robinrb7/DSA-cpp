class Solution {

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        queue< pair<pair<int,int>,int> > q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                } 
                
            }
        }

        int dRow[4] = {0,0,-1,1};
        int dCol[4] = {-1,1,0,0};

        while(!q.empty()){
            auto[cord, dist] = q.front();
            q.pop();
            auto[row,col] = cord;

            for(int i=0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m 
                    && mat[nRow][nCol]==1 && !visited[nRow][nCol]){

                        visited[nRow][nCol]=1;
                        mat[nRow][nCol] = dist+1;
                        q.push({{nRow,nCol}, dist + 1});
                }
            }

        }

        return mat;
    }
};