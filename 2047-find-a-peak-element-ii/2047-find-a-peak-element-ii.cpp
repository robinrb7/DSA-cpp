class Solution {
    private:
    bool poss(vector<vector<int>>& mat,int row,int col,int n,int m){
        if((row >0 && mat[row][col] < mat[row-1][col]) || (row<n-1 && mat[row][col] < mat[row+1][col]) 
            || (col >0 && mat[row][col] < mat[row][col-1]) || (col<m-1 && mat[row][col] < mat[row][col+1])){
            return 0;
           }

           return 1;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n= mat.size();
        int m = mat[0].size();

        int low =0,high =m-1;
        while(low<=high){
            int mid = low + (high-low)/2;

            int maxRow=-1, maxi=INT_MIN;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi){
                    maxi = mat[i][mid];
                    maxRow = i;
                }
            }

            if(poss(mat,maxRow,mid,n,m)) return {maxRow,mid};
            else if(mid >0 && mat[maxRow][mid-1] > mat[maxRow][mid]) high = mid-1;
            else low = mid+1;
        }
        return {-1,-1};
    }
};