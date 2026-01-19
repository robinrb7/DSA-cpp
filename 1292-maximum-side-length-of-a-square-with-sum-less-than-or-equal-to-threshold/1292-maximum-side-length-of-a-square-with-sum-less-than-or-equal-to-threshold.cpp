class Solution {
private:
    bool possible(vector<vector<int>>& prefix,int threshold,int row,int col, int side){
        int rowNo=row+side-1 , colNo = col+side-1;
        int sum = prefix[rowNo][colNo];
        if(row>0) sum-= prefix[row-1][colNo];
        if(col>0)   sum-= prefix[rowNo][col-1];
        if(row>0 && col>0)   sum+= prefix[row-1][col-1];

        return sum<=threshold;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(), m= mat[0].size();
        int maxSide = min(n,m);

        vector<vector<int>> prefix(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j] = mat[i][j];
                if(i>0) prefix[i][j] += prefix[i-1][j];
                if(j>0) prefix[i][j] += prefix[i][j-1];
                if(i>0 && j>0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }

        for(int side = maxSide;side>=1;side--){

            for(int i=0;i+side-1<n;i++){
                for(int j=0;j+side-1<m;j++){
                    
                    if(possible(prefix,threshold,i,j,side)){
                        return side;
                    }

                }
            }
        }

        return 0;
    }
};