class Solution {
private:
    bool possible(vector<vector<int>>& prefix,int threshold,int side, int n,int m){

        for(int row=0;row+side-1<n;row++){
            for(int col=0;col+side-1<m;col++){
                int rowNo = row+side-1, colNo = col+side-1;

                int sum = prefix[rowNo][colNo];
                if(row>0) sum-= prefix[row-1][colNo];
                if(col>0)   sum-= prefix[rowNo][col-1];
                if(row>0 && col>0)   sum+= prefix[row-1][col-1];

                if(sum<=threshold) return true;
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(), m= mat[0].size();

        vector<vector<int>> prefix(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j] = mat[i][j];
                if(i>0) prefix[i][j] += prefix[i-1][j];
                if(j>0) prefix[i][j] += prefix[i][j-1];
                if(i>0 && j>0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }

        int low=1,high=min(n,m);
        while(low<=high){
            int mid = low + (high-low)/2;

            if(possible(prefix,threshold,mid,n,m)){
                low=mid+1;
            }
            else 
                high = mid-1;
        }

        return high;
    }
};