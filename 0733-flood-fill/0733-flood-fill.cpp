class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int startColor = image[sr][sc];
        if(color == startColor) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;

        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};

        while(!q.empty()){
            auto[row,col] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==startColor){
                    image[nRow][nCol] = color;
                    q.push({nRow,nCol});
                }

            }
        }

        return image;
    }
};