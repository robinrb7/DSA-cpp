class Solution {
    private:
    int rowInd(vector<vector<int>>& mat,int col, int n){
        int maxRow=-1, maxi=INT_MIN;
            for(int i=0;i<n;i++){
                if(mat[i][col]>maxi){
                    maxi = mat[i][col];
                    maxRow = i;
                }
            }
        return maxRow;
    }
    
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n= mat.size();
        int m = mat[0].size();

        int low =0,high =m-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int maxRow = rowInd(mat,mid,n);

            int left = mid>0? mat[maxRow][mid-1]:-1;
            int right= mid<m-1? mat[maxRow][mid+1]:-1;

            if(mat[maxRow][mid]> left && mat[maxRow][mid]> right) return {maxRow,mid};
            else if(left > mat[maxRow][mid]) high = mid-1;
            else low = mid+1;
        }
        return {-1,-1};
    }
};