class Solution {
private:
    bool possible(vector<vector<int>>& grid,vector<vector<int>> &rowPrefix,
                vector<vector<int>> &colPrefix, int row, int col, int side)
    {
        int rowNo = row + side -1, colNo = col + side -1;

        int sum=-1;
        for(int j=0;j<side;j++){
            int firstVal = colPrefix[rowNo][col+j];
            int secondVal = (rowNo>=side)? colPrefix[rowNo-side][col+j]: 0;
            int finalVal = firstVal-secondVal;

            if(sum==-1) sum = finalVal;
            else{
                if(sum!= finalVal) return 0;
            }
        }

        
        for(int i=0;i<side;i++){
            int firstVal = rowPrefix[row+i][colNo];
            int secondVal = (colNo>=side)? rowPrefix[row+i][colNo-side]: 0;
            int finalVal = firstVal-secondVal;

            if(sum!= finalVal) return 0;
        }

        int diagonal1=0, diagonal2=0;
        for(int i=0;i<side;i++){
            diagonal1 += grid[row+i][col+i];
            diagonal2 += grid[row+side-1-i][col+i];
        }

        if(diagonal1!=diagonal2 || diagonal1!=sum) return 0;

        return 1;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxSide = min(n,m);

        vector<vector<int>> rowPrefix(n,vector<int>(m)), colPrefix(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rowPrefix[i][j] = grid[i][j];
                if(j!=0) rowPrefix[i][j] += rowPrefix[i][j-1];
            }
        }

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                colPrefix[i][j] = grid[i][j];
                if(i!=0) colPrefix[i][j] += colPrefix[i-1][j];
            }
        }

        for(int side=maxSide; side>=2;side--){

            for(int i=0;i+side-1<n;i++){
                for(int j=0;j+side-1<m;j++){
                    if(possible(grid,rowPrefix,colPrefix,i,j,side)){
                        return side;
                    }
                }
            }
        }

        return 1;
    }
};