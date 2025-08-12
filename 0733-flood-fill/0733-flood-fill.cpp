class Solution {
    void dfs(vector<vector<int>>& image, int i, int j, int color,int startColor,int n, int m){

        image[i][j]= color;
        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};

        for(int k=0;k<4;k++){
            int row = i + dRow[k];
            int col = j + dCol[k];

            if(row>=0 && row<n && col>=0 && col<m && image[row][col]==startColor){
                dfs(image,row,col,color,startColor,n,m);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if(sr <0 || sr>=n || sc<0 || sc>=m) return image;
        if(image[sr][sc]==color) return image;

        int startColor = image[sr][sc];
        dfs(image,sr,sc,color,startColor,n,m);

        return image;
    }
};