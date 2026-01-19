class Solution {
private:
    bool possible(vector<vector<int>>& rowPrefix,int threshold,int row,int col, int side){
        int colNo = col+side-1;
        int sum = 0;
        for(int i=0;i<side;i++){
            int firstVal = rowPrefix[row+i][colNo];
            int secondVal = (colNo>=side)? rowPrefix[row+i][colNo-side]: 0;
            int finalVal = firstVal - secondVal;

            sum+= finalVal;
            if(sum>threshold) return false;
        }

        return true;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(), m= mat[0].size();
        int maxSide = min(n,m);

        vector<vector<int>> rowPrefix(n,vector<int>(m));
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum += mat[i][j];
                rowPrefix[i][j]=sum;
            }
        }

        for(int side = maxSide;side>=1;side--){

            for(int i=0;i+side-1<n;i++){
                for(int j=0;j+side-1<m;j++){
                    
                    if(possible(rowPrefix,threshold,i,j,side)){
                        return side;
                    }

                }
            }
        }

        return 0;
    }
};