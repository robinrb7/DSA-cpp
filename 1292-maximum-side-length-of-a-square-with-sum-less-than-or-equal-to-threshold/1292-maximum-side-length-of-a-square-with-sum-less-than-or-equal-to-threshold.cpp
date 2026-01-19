class Solution {
private:
    bool possible(vector<vector<int>>& prefix,int threshold,int row,int col, int rowNo,int colNo){
        
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
        
        

        
        int ans = 0;
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    
                    int low=1,high=maxSide;
                    while(low<=high){
                        int mid = low + (high-low)/2;

                        int nRow = i + mid -1, nCol = j+mid-1;
                        if(nRow<n && nCol<m && possible(prefix,threshold,i,j,nRow,nCol)){
                            ans = max(ans,mid);
                            low=mid+1;
                        }
                        else 
                            high = mid-1;
                        
                    }

                }
            }

        return ans;
    }
};