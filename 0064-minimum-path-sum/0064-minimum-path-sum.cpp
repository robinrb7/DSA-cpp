class Solution {
private:
    int solve(vector<vector<int>>& grid){
        int n=grid.size(), m=grid[0].size();
        vector<int> prevRow(m,INT_MAX);

        for(int row=0;row<n;row++){
            vector<int> currRow(m,0);
            for(int col=0;col<m;col++){
                if(row==0 && col==0){
                    currRow[col]=grid[0][0];
                    continue;
                } 

                int up = INT_MAX, left = INT_MAX;
                if(row>0) up = prevRow[col];
                if(col>0) left = currRow[col-1];

                currRow[col] = grid[row][col] + min(up,left);
            }
            prevRow=currRow;
        }
        return prevRow[m-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        return solve(grid);
    }
};